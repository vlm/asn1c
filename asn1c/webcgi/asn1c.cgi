#!/usr/bin/perl -w
#
# $Id$
#

############################################################################
# The following preferences may be modified to match the local environment #
############################################################################

# Directory with the users data.
$TMPDIR = '/tmp/asn1c-cgi-jail/';
$SUIDHelper = './asn1c-suid-helper';
$SkeletonsDir = '/usr/local/share/asn1c';	# Will be needed only once
$CompilerLocation = '/usr/local/bin/asn1c';	# asn1c binary location
$HelpDBFile = $TMPDIR . '/var/db/Help-DB';	# Help requests database
$HashProgramPath = 'md5';			# Program to hash the input
$DM = 0750;					# Directory mode for all mkdirs
$MaxHistoryItems = 5;				# Number of items in History
$DynamicHistory = 'yes';			# Full/Short history
$safeFilename = '^[a-z0-9_-]+[.a-z0-9_-]*$';	# Safe filename
$ASN1C_Page = 'http://lionet.info/asn1c';
$HelpEmail = 'asn1c@lionet.info';
$defaultUserEmail = 'your@email';

$warn = '<CENTER><FONT SIZE=+1><B>';
$unwarn = '</B></FONT></CENTER>';

$OpEnvFailed = 'Failed to create the operations\' environment:';
$RandFailed = 'No source of randomness';
$SandBoxInitFailed = 'User playground initialization failed';

$myName = $ENV{SCRIPT_NAME};	# URL of this particular script (without args)

$homePath = "<FONT FACE=Courier SIZE=-1>"
	. "<A HREF=http://lionet.info>Home</A>"
	. " &gt;&gt; <A HREF=$ASN1C_Page>asn1c</A>"
	. " &gt;&gt; <A HREF=$ASN1C_Page/asn1c.cgi>Free Online ASN.1 Compiler</A>"
	. "</FONT><P>";

###################################################
# The code below rarely requires any modification #
###################################################

use CGI qw/param cookie header upload escapeHTML/;

$|=1;	# Enable AutoFlush (for older versions of Perl)

my $redirect = '';	# No redirection by default
my $redirect_bottom = '';	# No redirection text by default
my $content = '';	# Default content is empty

sub IssueRedirect() {
	$redirect = "<META HTTP-EQUIV=\"Refresh\" "
		. "CONTENT=\"5; URL=$myName\">";
	$redirect_bottom = "<P><CENTER>This page will <A HREF=$ASN1C_Page/asn1c.cgi>disappear</A> in 5 seconds.</CENTER>"
}

# If something goes wrong, this function is invoked to display the error message
sub bark($@) {
	local $_ = join("<BR>\n", @_);
	$content = $warn . $_ . $unwarn;
	goto PRINTOUT;
}

# Make the directory name containing session files for the given Session ID
sub makeSessionDirName($$) {
	local $pfx = shift;	# Prefix is the name of the top-level directory
	local $sid = shift;	# Session identifier (md5)
	$pfx . '/sessions/' . $sid . '/';
}

# Create ISO 8601 time string: "YYYY-MM-DDThh:mm:ss"
my $cachedTime;
sub isoTime() {
	return $cachedTime if $cachedTime;
	local @tm = localtime(time);

	$tm[5] += 1900;
	$tm[4] += 1;

	# Insert leading zeros
	for(my $i = 0; $i < 5; $i++) {
		$tm[$i] =~ s/^(.)$/0$1/;
	}

	$cachedTime = "$tm[5]-$tm[4]-$tm[3]T$tm[2]:$tm[1]:$tm[0]";
}

# Create the necessary environment for chrooting into.
sub prepareChrootEnvironment() {
	return 1 if(-d $TMPDIR);	# Envuronment already exists
	mkdir $TMPDIR, $DM, or bark($OpEnvFailed, $!);	# Global directory
	mkdir $TMPDIR . 'sessions', $DM or bark($OpEnvFailed, $!); # sessions
	mkdir $TMPDIR . 'bin', $DM or bark($OpEnvFailed, $!);	# asn1c location
	mkdir $TMPDIR . 'skeletons', $DM or bark($OpEnvFailed, $!); # asn1c data
	mkdir $TMPDIR . 'var', $DM or bark($OpEnvFailed, $!);
	mkdir $TMPDIR . 'var/db', $DM or bark($OpEnvFailed, $!);
	if(-d '/lib') {
		# Merge in dynamic libc
		mkdir $TMPDIR . 'lib', $DM or bark($OpEnvFailed, $!);
		system("cd $TMPDIR/lib && "
			. "for i in"
				. " /lib/ld-linux.*"	# Linux ELF loader
				. " /lib/libc.*"	# Standard C library
				. " /lib/libm.*"	# Math library
			. '; do ln $i; done');
	} elsif(-d '/usr/lib') {
		# There's no /lib on MacOS
		mkdir $TMPDIR . 'usr', $DM or bark($OpEnvFailed, $!);
		mkdir $TMPDIR . 'usr/lib', $DM or bark($OpEnvFailed, $!);
		mkdir $TMPDIR . 'usr/lib/system', $DM or bark($OpEnvFailed, $!);
		system("cd $TMPDIR/usr/lib && "
			. "for i in"
				. " /usr/lib/libc.*"
				. " /usr/lib/libSystem.*"
				. " /usr/lib/system/libmath*"
				. " /usr/lib/dy*"
			. '; do ln $i; done');
	}
	if(-d '/usr/libexec') {
		# FreeBSD ELF loader
		mkdir $TMPDIR . 'usr', $DM;
		mkdir $TMPDIR . 'usr/libexec',$DM or bark($OpEnvFailed, $!);
		system("cd $TMPDIR/usr/libexec && "
			. 'for i in /usr/libexec/ld-elf.*; do ln $i; done');
	}
	system("cp $CompilerLocation $TMPDIR/bin 2>/dev/null") == 0
		or bark($OpEnvFailed, $!);
	system("cp -r $SkeletonsDir/* $TMPDIR/skeletons >/dev/null 2>&1") == 0
			or bark($OpEnvFailed, $!);
	return 1;
}

sub makeArchive($$) {
	local $TMPDIR = shift;
	local $sandbox = shift;
	local $archName = $sandbox . '/+Archive.tgz';

	if(! -f $archName) {
		system("cd $sandbox && "
			. "for i in ./*.[ch]; do if [ -L \$i ]; then"
			. " cp $TMPDIR/skeletons/\$i \$i.-;"
			. " mv \$i.- \$i;"
			. " fi done && tar --dereference --ignore-failed-read --owner nobody --group nobody -zcf +tmp." . $$ . " *.[ch] Makefile* +Compiler.Log *.asn *.asn1"
			. " && rm -f ./*.[ch] ./Makefile*"
			. " && mv ./+tmp." . $$ . " $archName"
			. " || rm -f ./+tmp." . $$);
		undef unless -f $archName;
	}

	$archName;
}

my $EnvironmentSetOK = prepareChrootEnvironment();

#
# Record user's email.
#
$userEmail = cookie('userEmail');
$userEmail = $defaultUserEmail unless defined($userEmail);
$tmpEmail = param('email');
if(defined($tmpEmail)) {
	unless($tmpEmail =~ /^\s*([a-z0-9._+-]+@[a-z0-9.+-]+)\s*$/i) {
		bark("Invalid email address: "
			. "<B><FONT COLOR=darkred>$tmpEmail</FONT></B>");
	}
	my $previousEmail = $userEmail;
	$userEmail = $1;
	if($userEmail eq $defaultUserEmail) {
		IssueRedirect();
		bark("Please enter <FONT COLOR=red>your own</FONT> "
			. "email address, "
			. "instead of default \"<FONT COLOR=darkred>$defaultUserEmail</FONT>\"");
	}
	if($userEmail ne $previousEmail) {
		# Refresh cookie contents.
		local $ck = cookie(-name=>'userEmail',
			-value=>$userEmail,
			-path=>'/', -expires=>'+1d');
		print "Set-Cookie: " . $ck . "\n";
	}
}

#
# Check if full history requested.
#
$HistoryShow = cookie('HistoryShow');
$HistoryShow = '' unless $HistoryShow;
$tmpHSParam = param('history');	# Control cookie setting
if (defined($tmpHSParam)
 && $tmpHSParam ne $HistoryShow
 && $tmpHSParam =~ /^(full|short)$/) {
	$HistoryShow = $tmpHSParam;
	local $ck = cookie(-name=>'HistoryShow',
		-value=>$HistoryShow,
		-path=>'/', -expires=>'+1h');
	print "Set-Cookie: " . $ck . "\n";
}

#
# Prepare the session and create the session directory.
# If session exists, perfom arguments checking and execute historic views.
#
$session = cookie('SessionID');
unless($session) {
	$session = '';
	open(R, '/dev/urandom')
		or open(R, '/dev/random')
			or bark($RandFailed);
	read(R, $session, 16) == 16 or bark("Not enough randomness");
	if($ENV{HTTP_USER_AGENT}) {
		$session .= $ENV{HTTP_USER_AGENT};	# Add randomness
	}
	my $pid = open(R, "-|");
	if($pid == 0) {	# Child
		open(W, "| $HashProgramPath") or die;
		print W $session;
		exit(0);
	}
	$session = <R>;
	$session =~ s/[^a-f0-9]//ig;
	bark("md5 program is rotten here") if(length($session) != 32);
	$sessionDir = makeSessionDirName($TMPDIR, $session);
	mkdir($sessionDir, $DM) or bark($SandBoxInitFailed);
	my $ck = cookie(-name=>'SessionID', -value=>$session,
			-path=>'/', -expires=>'+1y');
	print header(-expires=>'-1y', -cookie=>$ck);
	$HTTPHeaderGenerated = 1;
} else {
	$session =~ s/[^a-f0-9]//ig;
	bark("Nope, try again") if(length($session) != 32);	# cool hacker?

	# Make sure the session directory exists
	$sessionDir = makeSessionDirName($TMPDIR, $session);
	mkdir($sessionDir, $DM) or bark($SandBoxInitFailed)
		unless(-d $sessionDir);

	local $t = param('time');
	local $file = param('file');
	local $fetch = param('fetch');
	local $show = param('show');
	unless(defined($t) && defined($file)
		&& $t =~ /^[0-9TZ:+-]{14,}$/
		&& $file =~ /$safeFilename/i) {
		$fetch = '';
		$show = '';
	}
	if($fetch =~ /$safeFilename/i || $show =~ /^(log|tgz)$/) {
		local $sandbox = $sessionDir . '/' . $t . '--' . $file;

		if($show eq 'tgz') {
			local $tarball = makeArchive($TMPDIR, $sandbox);
			defined $tarball
				or bark("Cannot create archive [$sandbox]");

			printf("Content-Type: application/x-tar\n");
			printf("Content-Encoding: gzip\n\n");
			exec("cat $tarball");
			exit(0);
		}

		if($show eq 'log') {
			$sandbox .= '/+Compiler.Log';
		} else {
			$sandbox .= '/' . $fetch;
		}
		open(I, "< " . $sandbox)
			or bark("Invalid or outdated request: [$sandbox] [$show] $!");
		printf "Content-Type: text/plain\n\n";
		while(<I>) {
			print;
		}
		exit(0);
	}
}

#
# Check if transaction help is requested.
#
$transHelp = param('transHelp');
if(defined($transHelp)
&& $transHelp =~ /^([0-9]+)--([0-9TZ:+-]{14,})--([_.a-zA-Z0-9-]+)$/) {
	open(S, "| sendmail -it")
		or bark("Cannot perform help request, "
			. "please email to the address below");
	print S "From: $userEmail\n";
	print S "To: $HelpEmail\n";
	print S "Subject: asn1c help requested for $3 ($1) by $userEmail\n";
	print S "\n";
	print S "\n-- \n";
	print S "User $userEmail requested help with\n";
	print S "$session/$2--$3 ($1)\n";
	close(S);

	open(S, '>> ' . $sessionDir . '/' . $2 . '--' . $3 . '/+HelpReq')
		or bark("Cannot perform help request, "
			. "please email to the address below");
	print S "$userEmail\n";
	close(S);

	open(S, '>> ' . $HelpDBFile);	# Susceptible to race condition.
	print S "$session/$2--$1--$3\n";
	close(S);

	$content = '<CENTER>Transaction '
		. "$1 ($3) is marked for manual processing.<BR>"
		. "Results will be mailed to "
		. "<FONT COLOR=darkgreen>$userEmail</FONT> shortly."
		. "</CONTENT>";
	IssueRedirect();
	goto PRINTOUT;
}

open(LOG, ">> $sessionDir/+logfile") or bark("Sandbox error: $!");
print LOG isoTime() . "\tIP=$ENV{REMOTE_ADDR}";
print LOG "\tEMAIL=$userEmail" if($userEmail ne $defaultUserEmail);

@gotSafeNames = ();
@gotNames = param('file');
if($#gotNames != -1 && $gotNames[0] ne "") {
	$gotFile = param('file');
	@gotFiles = upload('file');
} else {
	@gotNames = ();
	@gotFiles = ();
	$gotFile = undef;
}

if($#gotNames == -1) {
	my $text = param('text');
	if($text) {
		push(@gotNames, 'module.asn1');
	}
}

# Make safe filenames
foreach my $fname (@gotNames) {
	local $_ = $fname;
	s/.*\///g;	# Strip directory components
	s/.*\\//g;	# Strip directory components (DOS version)
	s/^[.-]/_/g;	# Don't allow filenames starting with a dot or a dash
	s/[^._a-z0-9-]/_/gi;
	if(!length($_)) {
		print LOG "\n";
		bark("Too strange filename: \"$fname\"");
	}
	$_ .= '.asn1' unless(/asn[1]{0,1}$/i);
	@gotSafeNames = (@gotSafeNames, $_);
	print LOG "\t" . $_;
}

#
# Save the files and start compilation process.
#
if($#gotSafeNames >= 0) {
	$transactionDir = isoTime() . '--' . join("-", @gotSafeNames);
	print LOG "\tDST=$transactionDir";

	my $sandbox = $sessionDir . '/' . $transactionDir;
	mkdir($sandbox, $DM) or bark($SandBoxInitFailed);

	open(O, '> ' . $sandbox . '/+Names');
	print O join("\n", @gotNames);
	open(O, '> ' . $sandbox . '/+safeNames');
	print O join("\n", @gotSafeNames);
	for(my $i = 0; $i <= $#gotSafeNames; $i++) {
		local $name = $gotSafeNames[$i];
		open(O, '> ' . $sandbox . '/'. $name);
		if($#gotFiles == -1) {
			print O scalar(param('text'));
		} else {
			while(<$gotFile>) {
				print O;
			}
		}
	}
	close(O);

	my $inChDir = makeSessionDirName("/", $session) . $transactionDir;
	my $options = '';
	my $optDebugL = param('optDebugL');
	my $optE = param('optE');
	my $optEF = param('optEF');
	my $optNT = param('optNT');
	my $optCN = param('optCN');
	$options .= " -Wdebug-lexer"
		if(defined($optDebugL) && $optDebugL eq "on");
	$options .= " -E" if(defined($optE) && $optE eq "on");
	$options .= " -EF" if(defined($optEF) && $optEF eq "on");
	$options .= " -fnative-types" if(defined($optNT) && $optNT eq "on");
	$options .= " -fcompound-names" if(defined($optCN) && $optNT eq "on");
	my $CompileASN = "$TMPDIR/bin/asn1c -v | sed -e 's/^/-- /'"
			. " > $sandbox/+Compiler.Log 2>&1"
		. "; $SUIDHelper $TMPDIR $inChDir $options @gotSafeNames "
			. " >> $sandbox/+Compiler.Log 2>&1"
		. "; echo \$? > $sandbox/+ExitCode";
	system($CompileASN);
	bark("Failed to initiate compilation process: $!")
		if(!-r $sandbox . '/+ExitCode');
	makeArchive($TMPDIR, $sandbox);
}

#print join("<BR>\n", `env`);

$form =
  "<FORM METHOD=POST ACTION=$myName ENCTYPE=\"multipart/form-data\">"
. "Pick the ASN.1 module file:<BR>\n"
. "<INPUT TYPE=file NAME=file SIZE=35><BR clear=all>\n"
. "Alternatively, enter the ASN.1 specification into the area below:<BR>\n"
. "<TEXTAREA NAME=text ROWS=15 COLS=60>\n"
. "/*\n"
. " * This ASN.1 specification is given for illustrative purposes\n"
. " */\n"
. "TestModule  { iso org(3) dod(6) internet(1) private(4)\n"
. "        1 spelio(9363) software(1) asn1c(5) webcgi(2) 1 }\n"
. "DEFINITIONS ::= BEGIN\n"
. "\n"
. "  TestType ::= SEQUENCE {\n"
. "      num [PRIVATE 1] INTEGER,\n"
. "      str UTF8String (SIZE(1..20)) OPTIONAL\n"
. "  }\n"
. "\n"
. "END\n"
. "</TEXTAREA><BR>\n"
. "<P>"
. "<FONT SIZE=-1>"
. "These options may be enabled to control the compiler's behavior:<BR>\n"
. "<INPUT TYPE=checkbox NAME=optDebugL> Debug lexer (<I>-Wdebug-lexer</I>)<BR>\n"
. "<INPUT TYPE=checkbox NAME=optE> Just parse and dump (do not compile) (<I>-E</I>)<BR>\n"
. "<INPUT TYPE=checkbox NAME=optEF> Parse, perform semantic checks, and dump (<I>-E -F</I>)<BR>\n"
. "<INPUT TYPE=checkbox NAME=optNT CHECKED=on> Employ native machine types (e.g. <b>double</b> instead of <b>REAL_t</b>) (<I>-fnative-types</I>)<BR>\n"
. "<INPUT TYPE=checkbox NAME=optCN> Prevent name clashes in compiled output (<I>-fcompound-names</I>)<BR>\n"
. "</FONT>"
. "<P>\n"
. "<INPUT TYPE=submit VALUE=\"Proceed with ASN.1 compilation\">"
. " (<A HREF=$ASN1C_Page>What is ASN.1?</A>)"
. "</FORM>";

#
# Gather previous transactions to generate the history page.
# The history page contains a list of several last ASN.1 files
# which were uploaded for compilation into the system
# by this particular browser (cookie-tracked).
#
opendir(SD, $sessionDir) or bark("Cannot open sandbox: $!");
my @transactions = sort { $b cmp $a }
		(grep {/^[0-9TZ:+-]{14,}--[_.a-zA-Z0-9-]+$/}
			readdir(SD));
my $CountHistoryItems = 0;
my $fullresp = param("fullresp");
foreach my $trans (sort { $b cmp $a } @transactions) {
	next unless($trans =~ /^([0-9TZ:+-]{14,})--([_.a-zA-Z0-9-]+)$/);

	local ($t, $f) = ($1, $2);
	local $origTime = $t;
	$t =~ s/T/ /;	# "1999-01-02T13:53:12" => "1999-01-02 13:53:12"

	# Global transaction number
	local $tNum = 1 + $#transactions - $CountHistoryItems;

	# Open the list of file names under which these files are known
	# at the remote system.
	open(I, '< ' . $sessionDir . '/' . $trans . '/+Names');
	local @Names = <I>;

	# Open the list of "safe" file names under which these files
	# are known to our file system.
	open(I, '< ' . $sessionDir . '/' . $trans . '/+safeNames');
	local @safeNames = <I>;

	# Create a list of real file names whith appropriate links to the
	# "safe" file names for subsequent file fetching.
	local @markedNames = ();
	for(my $i = 0; $i <= $#Names; $i++) {
		local $_ = "<A HREF=\"$myName?time="
			. escapeHTML($origTime)
			. "&file=$f"
			. "&fetch=$safeNames[$i]\">$Names[$i]</A>";
		@markedNames = (@markedNames, $_);
	}

	local $ec = '';
	open(I, '< ' . $sessionDir . '/' . $trans . '/+ExitCode')
		and chop($ec = <I>);

	if($ec eq "0") {
		$results = "<FONT COLOR=darkgreen><B>"
			. "Compiled OK</B></FONT><BR>\n";
	} else {
		$results = "<FONT COLOR=darkred>"
			. "Error during compilation: $ec</FONT><BR>\n";
	}

	$allowFetchResults = $ec eq "0"
		&& (-f $sessionDir . '/' . $trans . '/+Archive.tgz'
		|| -f $sessionDir . '/' . $trans . '/Makefile.am.sample');

	$results .= "<NOBR>"
		. ($allowFetchResults ? '1. ' : '')
		. "<A HREF=\"$myName/$f-$tNum.Log?time="
		. escapeHTML($origTime)
		. "&file=$f"
		. "&show=log\">"
		. "Show compiler log</A></NOBR>";
	$results .= "<BR>\n<NOBR>"
		. "2. <A HREF=\"$myName/$f-$tNum.tgz?time="
		. escapeHTML($origTime)
		. "&file=$f"
		. "&show=tgz\">"
		. "Fetch results (.tgz)</A></NOBR>"
		if $allowFetchResults;
	if($ec ne "0") {
		local $eml, @resp;
		open(H, '< ' . $sessionDir . '/' . $trans . '/+HelpResp')
			and @resp = <H>;
		open(H, '< ' . $sessionDir . '/' . $trans . '/+HelpReq')
			and chomp($eml = <H>);
		if($#resp >= 0) {
			shift(@resp) while($resp[0] =~ /^$/);
			if($fullresp eq $tNum) {
				$results .= "<P><B>Analysis:</B><BLOCKQUOTE>";
				$results .= join("<BR>", @resp);
				$results .= "</BLOCKQUOTE>";
				$results .= "(<A HREF=\"$myName\">Hide full text</A>)";
			} else {
				$results .= "<P><B>Analysis:</B> $resp[0]<BR>";
				$results .= "(<A HREF=\"$myName?fullresp=$tNum\">Show full text</A>)";
			}
		} elsif($eml) {
			$results .= "<P><FONT COLOR=darkred Family=Serif><B>"
				. "Status: manual help requested<BR>"
				. " by <FONT COLOR=black>$eml</FONT>,<BR>"
				. "expect results in a few hours.<B></FONT>";
		} else {
			$results .= '<P>'
			. "<INPUT TYPE=text NAME=email VALUE=\"$userEmail\"><BR>"
			. "<INPUT TYPE=hidden NAME=transHelp VALUE=\"$tNum--$trans\">"
			. '<INPUT TYPE=Submit VALUE="Help me fix it!">'
			. '<!-- <A HREF="mailto:asn1c@lionet.info?Subject=asn1c compiler help: '
			. "transaction $tNum ("
			. join(', ', @safeNames)
			. ") failed with code $ec"
			. '&body=leave body empty or add more comments">Help me fix it!</A> (See bottom line) -->'
			;
			$atLeastOneError = 1;
		}
	}

	$trColor = ' BGCOLOR=#f8f8f8';
	$trColor = ' BGCOLOR=#d0ffe0' unless($CountHistoryItems);
	$tNum = '<I>' . $tNum . '</I>' unless($CountHistoryItems);

	$history .= "<TR $trColor>"
		. "<TH ALIGN=center><FONT FACE=Helvetica SIZE=-2>$tNum</FONT></TH>"
		. "<TD ALIGN=center><FONT SIZE=-1 FACE=Helvetica>"
		. join(", ", @markedNames)
		. "</FONT></TD>"
		. "<FORM METHOD=POST ACTION=$myName><TD><FONT SIZE=-2 FACE=Helvetica>"
			. $results
			. "</TD></FORM>"
		. "</TR>\n";
	
	last if(++$CountHistoryItems >= $MaxHistoryItems
		&& $HistoryShow ne 'full');
}

if($DynamicHistory eq 'yes') {
	# [Un-]limit number of history items
	$HistoryItemsHidden = 1 + $#transactions - $CountHistoryItems;
	if($HistoryItemsHidden > 0) {
		# Propose to expand the list.
		local $item = 'item';
		$HistoryItemsHidden == 1 or $item = 'items';
		$history .= "<TR BGCOLOR=white><TD COLSPAN=3 ALIGN=center>"
			. "<FONT SIZE=-1><A HREF=\"$myName?history=full\">"
			. "Show full history</A> "
			. "($HistoryItemsHidden hidden $item)"
			. "</FONT></TD></TR>\n";
	} elsif($HistoryShow eq "full" && $#transactions >= $MaxHistoryItems) {
		# Propose to shorten the list.
		local $item = 'item';
		$MaxHistoryItems == 1 or $item = 'items';
		$history .= "<TR BGCOLOR=white><TD COLSPAN=3 ALIGN=center>"
			. "<FONT SIZE=-1><A HREF=\"$myName?history=short\">"
			. "Short history</A> ($MaxHistoryItems $item)"
			. "</FONT></TD></TR>\n";
	}
}

if($history) {
	$history = "<H3>History</H3>"
	. "<TABLE CELLPADDING=0 CELLSPACING=0 BGCOLOR=#404040 WIDTH=100%><TR><TD>"
	. "<TABLE BORDER=0 CELLPADDING=5 CELLSPACING=1 WIDTH=100%>\n"
	. "<TR BGCOLOR=#e0f0d0>"
	. "<TH WIDTH=1%><FONT COLOR=#404040 FACE=Courier>N</FONT></TH>"
	. "<TH><FONT COLOR=#404040 FACE=Courier>Files processed</FONT></TH>"
	. "<TH><FONT COLOR=#404040 FACE=Courier>Result</FONT></TH>"
	. "</TR>\n"
	. $history . "</TABLE></TD></TR></TABLE><BR>\n";

	if($atLeastOneError) {
		$history .= "<FONT SIZE=-1 COLOR=#404040>"
			. "<FONT COLOR=darkred><B>Bottom line:</B> ASN.1 compiler was unable to process some of the input files.</FONT><BR>"
			. "This is typically caused by syntax errors in the input files.\n"
			. "Such errors are normally fixed by removing or adding a couple of characters in the ASN.1 module.<BR>\n"
			. "<BR><B><FONT COLOR=darkred>Please consider clicking on an appropriate &quot;<I>Help me fix it!</I>&quot; link above.</FONT></B><BR>\n"
			. "An email will be sent to a person who will gladly fix the ASN.1 module for you. (The typical turn-around time is less than 24 hours.)\n"
			. "<BR>This is <B>free</B>, and highly advisable.\n"
			. "Your request will help us make a better compiler!\n"
			. "<BR>Thank you."
			. "</FONT>";
	}
}

unless($history) {
	$history = "<FONT SIZE=+2 COLOR=#a0a0a0>"
		. "[compiled results will appear here]</FONT>";
	$histValign = 'center';
} else {
	$histValign = 'top';
}

$content .=
  "<TABLE WIDTH=100% BORDER=0 CELLSPACING=5 CELLPADDING=5><TR><TD ID=inputbox VALIGN=top ROWSPAN=2 WIDTH=40%>\n"
. "<H3 ALIGN=center>ASN.1 Input</H3>\n"
. "$form"
. "</TD><TD WIDTH=60% HEIGHT=50% ALIGN=center VALIGN=$histValign>$history \n"
. "</TD></TR><TR><TD HEIGHT=50% VALIGN=bottom>"
	. "<FONT SIZE=-1><B>Privacy Note:</B> this page is tailored "
	. "to your browser using a cryprographically strong cookie. "
	. "<I>Other users will see their own (different) data.</I> "
	. "(<A HREF=asn1c-privacy.html>Read more...</A>)"
	. "</FONT>"
. "</TD></TR></TABLE>";

$ua = $ENV{HTTP_USER_AGENT};
$ua =~ s/\\/\\\\/;
$ua =~ s/"/\\"/;
print LOG "\tUA=\"$ua\"";
print LOG "\n";	# Finalize logging record

PRINTOUT:

print header(-expires=>'-1y') unless($HTTPHeaderGenerated);

# If environment has never been set up completely, remove it.
if($EnvironmentSetOK != 1 && $TMPDIR ne "/") {
	system("rm -rf $TMPDIR/ >/dev/null 2>&1");
}

print<<EOM;
<HTML>
<HEAD>
<TITLE>Free Online ASN.1 Compiler</TITLE>
<META NAME="Description" CONTENT="Free Online ASN.1 Compiler">
$redirect
<STYLE TYPE="text/css">
	TD#inputbox {
		border-right: dashed 1px rgb(200, 200, 200);
	}
</STYLE>
</HEAD>
<BODY BGCOLOR=white>

$homePath

$content

$redirect_bottom

<HR WIDTH=70%>
<CENTER><ADDRESS><FONT SIZE=-1 FACE=Courier COLOR=#404040>
<A HREF=$ASN1C_Page>The ASN.1 Compiler</A>
	Copyright &copy; 2003, 2004, 2005
Lev Walkin &lt;<A HREF=mailto:vlm&#64;lionet.info?Subject=asn1c>vlm&#64;lionet.info</A>&gt;
</FONT></ADDRESS></CENTER>
</BODY>
</HTML>
EOM
