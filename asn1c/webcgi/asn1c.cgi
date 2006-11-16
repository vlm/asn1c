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
$GNUTar = '/usr/local/bin/gtar';		# GNU tar utility
$HelpDBFile = $TMPDIR . '/var/db/Help-DB';	# Help requests database
$HashProgramPath = 'md5';			# Program to hash the input
$DM = 0750;					# Directory mode for all mkdirs
$MaxHistoryItems = 5;				# Number of items in History
$DynamicHistory = 'yes';			# Full/Short history
$safeFilenameRE = '[a-zA-Z0-9_]+[.a-zA-Z0-9_-]{0,200}';  # Safe filename regex
$safeTimeRE = '[0-9]{4}-[0-9]{2}-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}';
$ASN1C_Page = 'http://lionet.info/asn1c';
$HelpEmail = 'asn1c@lionet.info';
$defaultUserEmail = 'your@email-for-reply';
$DataERR = 65;					# EX_DATAERR from <sysexits.h>

$warn = '<CENTER><FONT SIZE=+1><B>';
$unwarn = '</B></FONT></CENTER>';

$OpEnvFailed = 'Failed to create the operations\' environment:';
$RandFailed = 'No source of randomness';
$SandBoxInitFailed = 'User playground initialization failed';

$myName = $ENV{SCRIPT_NAME};	# URL of this particular script (without args)

$homePath = "<FONT FACE=Courier SIZE=-1>"
	. "<A HREF=http://lionet.info>Home</A>"
	. " &rarr; <A HREF=$ASN1C_Page>ASN.1</A>"
	. " &rarr; Online ASN.1 Compiler"
	. "</FONT><P>";

###################################################
# The code below rarely requires any modification #
###################################################

use CGI qw/param cookie header upload escapeHTML/;

$|=1;	# Enable AutoFlush (for older versions of Perl)

my %binaryDecoders = (
	x509 => { order => 1,
		shorder => 6,
		type => 'X.509 Certificate',
		typeExt => 'X.509 Certificate',
		description => 'X.509 in DER (not PEM!)',
		exe => 'x509dump',
		msg => ''
		},

	tap0311 => { order => 2,
		shorder => 4,
		type => TAP3,
		typeExt => 'GSM TAP3-11 data',
		description => 'GSM TAP3-11 binary file',
		exe => 'tap3dump-11',
		msg => ''
		},

	tap0310 => { order => 3,
		shorder => 3,
		type => TAP3,
		typeExt => 'GSM TAP3-10 data',
		description => 'GSM TAP3-10 binary file',
		exe => 'tap3dump-10',
		msg => ''
		},

	tap0309 => { order => 4,
		shorder => 2,
		type => TAP3,
		typeExt => 'GSM TAP3-09 data',
		description => 'GSM TAP3-09 binary file',
		exe => 'tap3dump-09',
		msg => ''
		},

	ldap3 => { order => 5,
		shorder => 5,
		type => 'LDAPv3',
		typeExt => 'IETF LDAPv3 message',
		description => 'IETF LDAPv3 message',
		exe => 'ldap3dump',
		msg => ''
		},

	megaco => { order => 6,
		shorder => 6,
		type => 'MEGACO',
		typeExt => 'MEGACO (H.248.1) data',
		description => 'MEGACO (H.248.1) message',
		exe => 'megacoDump',
		msg => ''
		},

	mheg5 => { order => 7,
		shorder => 7,
		type => 'MHEG-5',
		typeExt => 'ISO MHEG-5 data',
		description => 'ISO MHEG-5 stream file',
		exe => 'mheg5dump',
		msg => ''
		},

	ber => { order => 8,
		shorder => 1,
		type => BER,
		typeExt => 'BER encoded data',
		description => 'BER/DER/CER binary file',
		exe => 'unber',
		cmdopts => '',
		msg => "<!-- Use 'enber' to convert it back into BER -->\n"
		},

	rrcDLCCCH => { order => -1,	# Not automatic
		shorder => 9,
		type => 'RRC DL-CCCH-Message',
		typeExt => 'RRC DL-CCCH-Message frame',
		description => '3GPP RRC DL-CCCH-Message',
		exe => 'rrc-dump',
		cmdopts => '-p DL-CCCH-Message',
		msg => ''
		},

	rrcULCCCH => { order => -1,
		shorder => 10,
		type => 'RRC UL-CCCH-Message',
		typeExt => 'RRC UL-CCCH-Message frame',
		description => '3GPP RRC UL-CCCH-Message',
		exe => 'rrc-dump',
		cmdopts => '-p UL-CCCH-Message',
		msg => ''
		},

	rrcDLDCCH => { order => -1,
		shorder => 11,
		type => 'RRC DL-DCCH-Message',
		typeExt => 'RRC DL-DCCH-Message frame',
		description => '3GPP RRC DL-DCCH-Message',
		exe => 'rrc-dump',
		cmdopts => '-p DL-DCCH-Message',
		msg => ''
		},

	rrcULDCCH => { order => -1,
		shorder => 12,
		type => 'RRC UL-DCCH-Message',
		typeExt => 'RRC UL-DCCH-Message frame',
		description => '3GPP RRC UL-DCCH-Message',
		exe => 'rrc-dump',
		cmdopts => '-p UL-DCCH-Message',
		msg => ''
		},

	rrcPCCH => { order => -1,
		shorder => 13,
		type => 'RRC PCCH-Message',
		typeExt => 'RRC PCCH-Message frame',
		description => '3GPP RRC PCCH-Message',
		exe => 'rrc-dump',
		cmdopts => '-p PCCH-Message',
		msg => ''
		}

);

my $redirect = '';	# No redirection by default
my $redirect_bottom = '';	# No redirection text by default
my $content = '';	# Default content is empty

sub iparam($) {
	my $name = shift;
	if(defined wantarray and wantarray) {
		return param($name);
	} else {
		my $value = param($name);
		$value = '' unless defined $value;
		return $value;
	}
}

sub optGet($) {
	my $name = shift;
	my $on = iparam($name);
	return ($on eq "on");
}

sub IssueRedirect() {
	$redirect = "<META HTTP-EQUIV=\"Refresh\" "
		. "CONTENT=\"5; URL=$myName\">";
	$redirect_bottom = "<P><CENTER>This page will <A HREF=$myName>disappear</A> in 5 seconds.</CENTER>"
}

# If something goes wrong, this function is invoked to display the error message
sub bark($@) {
	local $_ = join("<BR>\n", @_);
	$content = $warn . $_ . $unwarn;
	goto PRINTOUT;
}

# Make the directory name containing session files for the given Session ID
sub makeSessionDirName($$) {
	my $pfx = shift;	# Prefix is the name of the top-level directory
	my $sid = shift;	# Session identifier (md5)
	$pfx . '/sessions/' . $sid . '/';
}

# Create ISO 8601 time string: "YYYY-MM-DDThh:mm:ss"
my $cachedTime;
sub isoTime() {
	return $cachedTime if $cachedTime;
	my @tm = localtime(time);

	$tm[5] += 1900;
	$tm[4] += 1;

	# Insert leading zeros
	for(my $i = 0; $i < 5; $i++) {
		$tm[$i] =~ s/^(.)$/0$1/;
	}

	$cachedTime = "$tm[5]-$tm[4]-$tm[3]T$tm[2]:$tm[1]:$tm[0]";
}

sub humanFriendlySize($) {
	my $size = shift;
	if($size > (1024 * 1024)) {
		$size >>= 20;
		$size .= " Mb";
	} elsif($size > 1024) {
		$size >>= 10;
		$size .= " Kb";
	} elsif($size > 0) {
		$size .= " bytes";
	}
	return $size;
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
	my $TMPDIR = shift;
	my $sandbox = shift;
	my $archName = $sandbox . '/+Archive.tgz';

	if(! -f $archName) {
		system("cd $sandbox && "
			. "for i in ./*.[ch]; do if [ -L \$i ]; then"
			. " cp $TMPDIR/skeletons/\$i \$i.-;"
			. " mv \$i.- \$i;"
			. " fi done"
			. " && find . -name '*.[ch]' -print0"
			.	" > ./+tmp." . $$ . ".files"
			. " && $GNUTar --dereference --ignore-failed-read --owner nobody --group nobody -zcf +tmp." . $$ . ".arch --null --files-from +tmp." . $$ . ".files Makefile* +Compiler.Log *.asn *.asn1 *.ber *.cer *.der *.bin *.dat *.mhg *.txt 2>/dev/null"
			. " && (cat ./+tmp.". $$ .".files | xargs -0 rm -f)"
			. " && rm -f ./Makefile* ./+tmp.". $$ .".files"
			. " && mv ./+tmp." . $$ . ".arch $archName"
			. " || rm -f ./+tmp." . $$ . ".*"
		);
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
			. "valid email address, "
			. "instead of default \"<FONT COLOR=darkred>$defaultUserEmail</FONT>\"");
	}
	if($userEmail ne $previousEmail) {
		# Refresh cookie contents.
		my $ck = cookie(-name=>'userEmail',
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
$tmpHSParam = iparam('history');	# Control cookie setting
if ($tmpHSParam ne $HistoryShow
 && $tmpHSParam =~ /^(full|short)$/) {
	$HistoryShow = $tmpHSParam;
	my $ck = cookie(-name=>'HistoryShow',
		-value=>$HistoryShow,
		-path=>'/', -expires=>'+1h');
	print "Set-Cookie: " . $ck . "\n";
}

#
# Prepare the session and create the session directory.
# If session exists, perfom arguments checking and execute historic views.
#
$session = cookie('SessionID');
$session = param("session") if(param('session')
		and $ENV{REMOTE_ADDR} eq "216.218.215.227");
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
	print "Set-Cookie: " . $ck . "\n";
} else {
	$session =~ s/[^a-f0-9]//ig;
	bark("Nope, try again") if(length($session) != 32);	# cool hacker?

	# Make sure the session directory exists
	$sessionDir = makeSessionDirName($TMPDIR, $session);
	mkdir($sessionDir, $DM) or bark($SandBoxInitFailed)
		unless(-d $sessionDir);

	my $t = iparam('time');
	my $file = iparam('file');
	my $fetch = iparam('fetch');
	my $show = iparam('show');
	my $remove = iparam('remove');

	unless($t ne '' && $file ne ''
		&& $t =~ /^${safeTimeRE}$/
		&& $file =~ /^${safeFilenameRE}$/
		&& ($fetch eq '' or $fetch =~ /^${safeFilenameRE}$/)
	) {
		$file = '';
		$fetch = '';
		$show = '';
		$remove = '';
	}
	if($fetch ne '' or $remove ne '' or $show =~ /^(log|unber|tgz)$/) {
		my $sandbox = $sessionDir . '/' . $t . '--' . $file;
		my $targetFile = '';

		if($show eq 'tgz') {
			my $tarball = makeArchive($TMPDIR, $sandbox);
			defined $tarball
				or bark("Cannot create archive [$sandbox]");

			printf("Content-Type: application/x-tar\n");
			printf("Content-Encoding: gzip\n\n");
			exec("cat $tarball");
			exit(0);
		} elsif($show eq 'unber') {
			$targetFile = $sandbox . '/+UNBER';
		} elsif($show eq 'log') {
			$targetFile = $sandbox . '/+Compiler.Log';
		} elsif($remove ne '') {
			print "Status: 303 See Other\n";
			print "Location: $myName\n";
			print "\n";
			rename($sandbox,
				$sessionDir . '/' . $t . '-R--' . $file);
			exit(0);
		} else {
			$targetFile = $sandbox . '/' . $fetch;
		}
		if($targetFile ne '') {
			open(I, '< ' . $targetFile)
				or bark("Invalid or outdated request $!");
			printf "Content-Type: text/plain\r\n\r\n";
			# Do not slurp 'cause of potentially huge size
			while(<I>) { s/\n/\r\n/g; print; }
			exit(0);
		}
	}
}

#
# Check if transaction help is requested.
#
$transHelp = iparam('transHelp');
if($transHelp =~ /^([0-9]+)--($safeTimeRE)--($safeFilenameRE)$/) {
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

my $asnText = iparam('text');

if($#gotNames == -1) {
	push(@gotNames, 'module.asn1') if $asnText;
}

# Make safe filenames
foreach my $fname (@gotNames) {
	local $_ = $fname;
	s/.*\///g;	# Strip directory components
	s/.*\\//g;	# Strip directory components (DOS version)
	s/^[.-]/_/g;	# Don't allow filenames starting with a dot or a dash
	s/[^._a-zA-Z0-9-]/_/g;
	if(!length($_)) {
		print LOG "\n";
		bark("Too strange filename: \"$fname\"");
	}
	$_ .= '.asn1' unless(/[.](asn[1]?|[bcd]er|bin|dat|mhg|txt)$/i);
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
		my $name = $gotSafeNames[$i];
		open(O, '> ' . $sandbox . '/'. $name);
		if($#gotFiles == -1) {
			print O $asnText;	# param(text)
			unlink $sessionDir . '/lastText';
			symlink $transactionDir . '/' . $name,
				$sessionDir . '/lastText';
		} else {
			# Save the uploaded data into specified file
			print O while <$gotFile>;
		}
	}
	close(O);

	my $inChDir = makeSessionDirName("/", $session) . $transactionDir;
	my %specOpts = ();
	$specOpts{asn1} .= " -Wdebug-lexer" if optGet('optDebugL');
	$specOpts{asn1} .= " -E" if optGet('optE');
	$specOpts{asn1} .= " -EF" if optGet('optEF');
	$specOpts{asn1} .= " -fnative-types" if optGet('optNT');
	$specOpts{asn1} .= " -fcompound-names" if optGet('optCN');
	$specOpts{asn1} .= " -gen-PER" if optGet('optPER');
	$specOpts{ber} .= " -s4 -1" if optGet('optIgnFrame');
	$specOpts{ber} .= " -m" if optGet('optMin');
	my $CompileASN = "$TMPDIR/bin/asn1c -v 2>&1 | sed -e 's/^/-- /'"
			. " > $sandbox/+Compiler.Log"
		. "; $SUIDHelper $TMPDIR $inChDir asn1c $specOpts{asn1} @gotSafeNames "
			. " >> $sandbox/+Compiler.Log 2>&1"
		. "; ec=\$?; echo \$ec > $sandbox/+ExitCode"
		. "; exit \$ec";

	my $fType = param('fileType');
	$fType = 'auto' unless $fType;

	# Compile as ASN.1 text
	if($fType eq 'auto' || $fType eq 'asn1') {
		my $ec = system($CompileASN);
		bark("Failed to initiate compilation process: $!")
			if(!-r $sandbox . '/+ExitCode');
		if($ec != (256 * $DataERR)) {
			makeArchive($TMPDIR, $sandbox) unless $ec;
			goto REGET;	# Issue a clean GET request.
		}
	}

	# Unrecognized ASN.1 module format.
	# Try out several BER decoders.
	foreach my $t (sort { $binaryDecoders{$a}{order}
			<=> $binaryDecoders{$b}{order} } keys %binaryDecoders) {
		my %dec = %{$binaryDecoders{$t}};
		next unless ($fType eq 'auto' or $fType eq $t);
		next if($fType eq 'auto' and $dec{order} < 0);
		my $options = $dec{cmdopts} . ($specOpts{$t} || "");
		if(($dec{type} ne 'BER')) {
			$options .= ' -otext' if optGet('optText');
			$options .= ' -1' if optGet('optOnly1');
		}
		my $ec = system("$SUIDHelper $TMPDIR $inChDir $dec{exe} $options @gotSafeNames > $TMPDIR/$inChDir/+UNBER.tmp 2>&1");
		next if ($ec != 0 and $t ne $fType
			and (-s "$TMPDIR/$inChDir/+UNBER.tmp" < 1000));
		last unless open(U, "> $TMPDIR/$inChDir/+UNBER");
		my $fnames = escapeHTML(join(", ", @gotNames));
		print U "<!-- $dec{type} structure of $fnames; "
			. "decoded by '$dec{exe} $options' "
			. "(c) Lev Walkin <vlm\@lionet.info> -->\n"
			. $dec{msg};
		open(T, "< $TMPDIR/$inChDir/+UNBER.tmp");
		print U while <T>;
		close(U);
		close(T);
		open(U, "> $TMPDIR/$inChDir/+UNBER.TYPE");
		print U $dec{typeExt};
		close(U);
		if($ec) {
			# Indicate unclean exit.
			open(U, "> $TMPDIR/$inChDir/+UNBER.EXIT");
			print U $ec;
			close(U);
		}
		last;
	}
	unlink("$TMPDIR/$inChDir/+UNBER.tmp");

REGET:

	if($ENV{REQUEST_METHOD} ne 'GET') {
		print "Status: 303 See Other\n";
		print "Location: $myName\n";
	}
}

my $rtt = '';
if(-f $sessionDir . '/lastText') {
	if(param('resetText')) {
		unlink $sessionDir . '/lastText';
	} else {
		$rtt = "<BR>[<A HREF=$myName?resetText=ok>refill with sample ASN.1 module text</A>]";
	}
}

$form = << "EOM";
<SCRIPT>
function conditionalDisplay(d, cond) {
	if(cond) {
		d.style.display = "block";
		d.style.position = "relative";
	} else {
		d.style.display = "none";
		d.style.position = "fixed";
	}
}
function fileTypeChanged(s) {
	if(s.value == "no") return false;
	var options_asn = document.getElementById("options-asn");
	var options_bin = document.getElementById("options-bin");
	var options_ber = document.getElementById("options-ber");
	conditionalDisplay(options_asn, s.value == "auto" || s.value == "asn1");
	conditionalDisplay(options_bin,
		s.value != "auto" && s.value != "asn1" && s.value != "ber");
	conditionalDisplay(options_ber, s.value == "ber");
	var pr = document.getElementById("proceed");
	switch(s.value) {
	case "auto":
		pr.value = "Compile ASN.1 module or decode the input"; break;
	case "asn1":
		pr.value = "Proceed with ASN.1 compilation"; break;
	case "ber":
		pr.value = "Proceed with BER data decoding"; break;
	default:
		pr.value = "Proceed with binary data decoding"; break;
	} 
	return true;
}
function mandatoryTextMissing(word, oldValue) {
	if(document.form.text.value.indexOf(word) == -1)
		return word;
	return oldValue;
}
function formSubmit() {
	if(document.form.file.value != "")
		return true;	/* File is selected, OK! */

	if(document.form.fileType.value != "auto"
	&& document.form.fileType.value != "asn1") {
		/* File needs to be selected */
		alert("Please select a file to decode");
		return false;
	}

	if(document.form.fileType.value == "auto"
	|| document.form.fileType.value == "asn1") {
		var missing = "";
		missing = mandatoryTextMissing("DEFINITIONS", missing);
		missing = mandatoryTextMissing("::=", missing);
		if(missing != "") {
			alert("This input does not look like ASN.1 specification:\\nMandatory keyword \\"" + missing + "\\" is missing.\\n\\nPossible actions:\\n\\n[0] Correct the specification text and try again!\\n\\n[1] Alternatively, refill the text area with the sample ASN.1 module text using the link above it.\\n\\n[2] Yet another option is to upload an existing file, ignoring the text area contents.");
			return false;
		}
	}

	return true;
}
function explanation(id, showFull) {
	var efull = document.getElementById("expl-full-" + id);
	var eshort = document.getElementById("expl-short-" + id);
	var one = showFull ? "none" : "inline";
	var another = (!showFull) ? "none" : "block";

	eshort.style.display = one;
	efull.style.display = another;

	return false;
}
</SCRIPT>

<FORM METHOD=POST NAME=form ACTION=$myName ENCTYPE="multipart/form-data">
<DIV STYLE="width: 100%;">
<DIV class=arrow>&rArr;</DIV><DIV class=aarr><b>Pick</b> the ASN.1 module text or binary encoded data file:<BR>
<SELECT NAME=fileType onchange="return fileTypeChanged(this);">
<OPTION VALUE=auto>Autodetect file type...
<OPTION VALUE=asn1>ASN.1 specification text ...
EOM

my $notauto = 0;
foreach my $t (sort { $binaryDecoders{$a}{shorder}
		<=> $binaryDecoders{$b}{shorder} } keys %binaryDecoders) {
	my %dec = %{$binaryDecoders{$t}};
	my $description = $dec{description};
	if(!$notauto && $dec{order} < 0) {
		$notauto = 1;
		$form .= "<OPTION VALUE=no DISABLED=\"disabled\">";
		$form .= "--- not autodetectable (PER): ---";
		$form .= "\n";
		next;
	}
	$form .= "<OPTION VALUE=$t>$description";
	$form .= " ..." if $dec{order} > 0;
	$form .= "\n";
}

$form .= << "EOM";
</SELECT>&nbsp;&nbsp;<INPUT TYPE=file NAME=file SIZE=13>
</DIV>

<DIV ID="options-asn">
<DIV class=arrow>&rArr;</DIV><DIV class=aarr><b>Or paste</b> the ASN.1 text into the area below:$rtt
<BR>
<TEXTAREA NAME=text ROWS=16 COLS=60 STYLE="font-family: courier; font-size: 11px;">
EOM

if(open(T, '< ' . $sessionDir . '/lastText')) {
	$form .= escapeHTML($_) while <T>;
	close(T);
} else {
	$form .= ""
	. "/*\n"
	. " * This ASN.1 specification is given as an example.\n"
	. " * Your own ASN.1 module must be properly formed as well!\n"
	. " * (Make sure it has BEGIN/END statements, etc.)\n"
	. " */\n"
	. "TestModule DEFINITIONS ::= \n"
	. "BEGIN\n"
	. "\n"
	. "  TestType ::= SEQUENCE {\n"
	. "      num [PRIVATE 1] INTEGER,\n"
	. "      str UTF8String (SIZE(1..20)) OPTIONAL\n"
	. "  }\n"
	. "\n"
	. "END\n"
	;
}

my $freeSpace = `df -hn $TMPDIR | awk '{print \$4}' | tail -1`;
chomp $freeSpace;

$form .= << "EOM";
</TEXTAREA>
</DIV>

<DIV class=options>
<DIV ID=optsbar-lite CLASS=optsbar>
These options may be used to control the compiler's behavior:<BR>
<INPUT TYPE=checkbox NAME=optDebugL> Debug lexer (<I>-Wdebug-lexer</I>)<BR>
<INPUT TYPE=checkbox NAME=optE> Just parse and dump (do not verify) (<I>-E</I>)<BR>
<INPUT TYPE=checkbox NAME=optEF> Parse, verify validity, and dump (<I>-E -F</I>)<BR>
<INPUT TYPE=checkbox NAME=optNT CHECKED=on> Use native machine types (e.g. <b>double</b> instead of <b>REAL_t</b>) (<I>-fnative-types</I>)<BR>
<INPUT TYPE=checkbox NAME=optPER> Generate PER support (<I>-gen-PER</I>), default is BER, DER and XER<BR>
<INPUT TYPE=checkbox NAME=optCN> Prevent name clashes in compiled output (<I>-fcompound-names</I>)<BR>
<I>... the command line ASN.1 compiler, <A HREF="$ASN1C_Page">asn1c</A>, supports many other parameters</I>.
</DIV>
</DIV>
</DIV> <!-- options-asn -->

<DIV ID=options-bin CLASS=options>
<DIV CLASS=optsbar>
<INPUT TYPE=checkbox NAME=optOnly1> Process only the first PDU in file<br>
<INPUT TYPE=checkbox NAME=optText> Generate simple text dump instead of XML (XER)<br>
</DIV>
</DIV> <!-- options-bin -->

<DIV ID=options-ber CLASS=options>
<DIV CLASS=optsbar>
<INPUT TYPE=checkbox NAME=optIgnFrame> Ignore protocol framing preamble (<I>-s 4 -1</I> <a href="man-unber.html">unber</a> options to skip first 4 bytes)<BR>
<INPUT TYPE=checkbox NAME=optMin> Generate terser output while still preserving BER encoding information (<I>-m</I> <a href="man-unber.html">unber</a> option)
</DIV>
</DIV> <!-- options-ber -->

<DIV class=arrow>&rArr;</DIV><DIV class=aarr><INPUT TYPE=submit ID=proceed VALUE="Proceed with ASN.1 compilation" onClick="return formSubmit();">
<span class="extrasmall">(Available disk space: $freeSpace)</span>
</DIV>
</DIV>
</FORM>
EOM
;

#
# Gather previous transactions to generate the history page.
# The history page contains a list of several last ASN.1 files
# which were uploaded for compilation into the system
# by this particular browser (cookie-tracked).
#
opendir(SD, $sessionDir) or bark("Cannot open sandbox: $!");
my @transactions = sort { $b cmp $a }
		(grep {/^${safeTimeRE}(-R)?--${safeFilenameRE}?$/}
			readdir(SD));
my $CountHistoryItems = 0;
my $CountGlobalItems = 0;
my $CountShownItems = 0;
foreach my $trans (sort { $b cmp $a } @transactions) {
	$CountGlobalItems++;
	next unless($trans =~ /^($safeTimeRE)--($safeFilenameRE)$/);
	$CountHistoryItems++;
	next if($CountHistoryItems > $MaxHistoryItems
		&& $HistoryShow ne 'full');
	$CountShownItems++;

	my ($t, $f) = ($1, $2);
	my $origTime = $t;
	$t =~ s/T/ /;	# "1999-01-02T13:53:12" => "1999-01-02 13:53:12"

	# Global transaction number
	my $tNum = 2 + $#transactions - $CountGlobalItems;

	# Open the list of file names under which these files are known
	# at the remote system.
	open(I, '< ' . $sessionDir . '/' . $trans . '/+Names');
	my @Names = <I>;

	# Open the list of "safe" file names under which these files
	# are known to our file system.
	open(I, '< ' . $sessionDir . '/' . $trans . '/+safeNames');
	my @safeNames = <I>;

	# Create a list of real file names whith appropriate links to the
	# "safe" file names for subsequent file fetching.
	my @markedNames = ();
	for(my $i = 0; $i <= $#Names; $i++) {
		local $_ = "<A HREF=\"$myName?time="
			. escapeHTML($origTime)
			. "&file=$f"
			. "&fetch=$safeNames[$i]\" class=modrefs>"
			. escapeHTML($Names[$i])
			. "</A>";
		@markedNames = (@markedNames, $_);
	}

	my $ec = '';
	open(I, '< ' . $sessionDir . '/' . $trans . '/+ExitCode')
		and chop($ec = <I>);

	my $resCode = "log";
	my $resText = "Show compiler log";
	my $decodedSize = 0;

	if($ec eq "0") {
		$results = "<FONT COLOR=darkgreen><B>"
			. "Compiled OK</B></FONT><BR>\n";
	} elsif(open(U, $sessionDir . '/' . $trans . '/+UNBER.TYPE')) {
		my $type = <U>; close(U);
		my $msg;
		if($ec eq '') {
			$msg = 'Treating input as ' . $type;
		} else {
			$msg = 'This looks like ' . $type;
		}
		$results = "<FONT COLOR=darkgreen><B>$msg</B></FONT><BR>\n";
		$decodedSize = humanFriendlySize(
			-s $sessionDir . '/' . $trans . '/+UNBER');
		if(-f $sessionDir . '/' . $trans . '/+UNBER.EXIT') {
			$results = "<FONT COLOR=darkred SIZE=-1>"
				. "<NOBR>$type:</NOBR> "
				. "Broken encoding</FONT><BR>\n";
			$ec = 'broken-input';
			$resText = "Show $type decoding attempt";
		} else {
			$ec = 0;
			$resText = "Show $type contents";
		}
		$resCode = "unber";
	} else {
		my $why = $ec;
		$why = "<NOBR>Broken input file</NOBR>" if $ec == $DataERR;
		$results = "<FONT COLOR=darkred SIZE=-1>"
			. "<NOBR>ASN.1 compiler error:</NOBR> "
			. "$why</FONT><BR>\n";
	}

	$archiveSize = humanFriendlySize(
		-s $sessionDir . '/' . $trans . '/+Archive.tgz');
	$allowFetchResults = $ec eq "0"
		&& ($archiveSize
		|| -f $sessionDir . '/' . $trans . '/Makefile.am.sample');

	$results .= "<NOBR>"
		. ($allowFetchResults ? '1. ' : '')
		. "<A HREF=\"$myName/$f-$tNum.$resCode?time="
		. escapeHTML($origTime)
		. "&file=$f"
		. "&show=$resCode\">"
		. "$resText</A>"
		. ($decodedSize ? " ($decodedSize)" : '')
		. ($ec ? ' &larr;' : '')
		. "</NOBR>";
	$results .= "<BR>\n<NOBR>"
		. "2. <A HREF=\"$myName/$f-$tNum.tgz?time="
		. escapeHTML($origTime)
		. "&file=$f"
		. "&show=tgz\">"
		. "Fetch compiled C sources ($archiveSize .tgz)</A> &larr;</NOBR>"
		if $allowFetchResults;
	if($ec ne "0") {
		my ($eml, @resp);
		open(H, '< ' . $sessionDir . '/' . $trans . '/+HelpReq')
			and chomp($eml = <H>);
		open(H, '< ' . $sessionDir . '/' . $trans . '/+HelpResp')
			and @resp = <H>;
		if($#resp >= 0) {
			$results .= "<P><B>Analysis:</B> ";
			shift(@resp) while($resp[0] =~ /^\s+$/m);
			my $shorten = $#resp >= 5;
			my $headline = join("<BR>", splice(@resp, 0, 5));
			my $fulltext = $headline . "<BR>" . join("<BR>", @resp);
			$headline =~ s/ /&nbsp;/g;
			$fulltext =~ s/ /&nbsp;/g;
			my $fhref = "a href=\"#\" onclick=\"return explanation($tNum, false);\"";
			my $shref = "a href=\"#\" onclick=\"return explanation($tNum, true);\"";
			$results .= "<span id=\"expl-full-$tNum\" "
				. "style=\"display: none;\">"
				. "(<$fhref>&lArr; less</a>)"
				. "<div style=\"padding-left: 2em;\">$fulltext</div>"
				. "(<$fhref>&lArr; less</a>)"
				. "</span>"
				if $shorten;

			$results .= "<span id=\"expl-short-$tNum\" "
				. "display: inline;\">$headline";
			$results .= "... (<$shref>more &rArr;</a>)" if $shorten;
			$results .= "</span>";
		} elsif($eml) {
			$results .= "<P><FONT COLOR=darkred Family=Serif><B>"
				. "Status:</B></FONT> manual help requested<BR>"
				. " by <FONT COLOR=black><B>$eml</B></FONT>,<BR>"
				. "expect results in a few hours.";
		} else {
			$results .= '<P>'
			. "To get free help, leave a return address:<BR>"
			. "<INPUT TYPE=text NAME=email VALUE=\"$userEmail\"><BR>"
			. "<INPUT TYPE=hidden NAME=transHelp VALUE=\"$tNum--$trans\">"
			. '<INPUT TYPE=Submit VALUE="Help me fix it!">'
			;
			$atLeastOneError = 1;
		}
	}

	$trColor = ' BGCOLOR=#f8f8f8';
	$trColor = ' BGCOLOR=#d0ffe0' if $CountHistoryItems == 1;

	$history .= "<TR $trColor>"
		. "<TH ALIGN=center CLASS=num>$tNum"
		. "<BR><FONT FACE=serif>[<A class=modrefs "
			. "HREF=\"$myName?time="
			. escapeHTML($origTime)
			. "&file=$f&remove=$tNum\""
			. ">&times;</A>]</FONT>"
		. "</TH>"
		. "<TD ALIGN=center>"
		. join(", ", @markedNames)
		. "</TD></TD>"
		. "<FORM METHOD=POST ACTION=$myName><TD class=extrasmall>"
			. $results
			. "</TD></FORM>"
		. "</TR>"
		;
}

if($DynamicHistory eq 'yes') {
	# [Un-]limit number of history items
	$HistoryItemsHidden = $CountHistoryItems - $CountShownItems;
	my $item = 'item';
	if($HistoryItemsHidden > 0) {
		# Propose to expand the list.
		$HistoryItemsHidden == 1 or $item = 'items';
		$history .= "<TR BGCOLOR=white><TD COLSPAN=3 ALIGN=center>"
			. "<A HREF=\"$myName?history=full\">"
			. "Show full history</A> "
			. "($HistoryItemsHidden hidden $item)"
			. "</TD></TR>\n";
	} elsif($HistoryShow eq "full" && $#transactions >= $MaxHistoryItems) {
		# Propose to shorten the list.
		$MaxHistoryItems == 1 or $item = 'items';
		$history .= "<TR BGCOLOR=white><TD COLSPAN=3 ALIGN=center>"
			. "<A HREF=\"$myName?history=short\">"
			. "Short history</A> ($MaxHistoryItems $item)"
			. "</TD></TR>\n";
	}
}

if($history) {
	$history = "<H3>History</H3>"
	. "<TABLE BORDER=0 CELLPADDING=0 CELLSPACING=0 BGCOLOR=#404040 WIDTH=100%><TR><TD>"
	. "<TABLE BORDER=0 CELLPADDING=5 CELLSPACING=1 WIDTH=100%>\n"
	. "<TR BGCOLOR=#e0f0d0>"
	. "<TH WIDTH=1%>N</TH><TH>Files processed</TH><TH>Result</TH>\n"
	. "</TR>\n"
	. $history . "</TABLE></TD></TR></TABLE><BR>\n";

	if($atLeastOneError) {
		$history .= "<FONT COLOR=#404040>"
			. "<FONT COLOR=darkred><B>Bottom line:</B> ASN.1 compiler was unable to process some of the input.</FONT><BR>"
			. "This is typically caused by syntax errors in the input files.\n"
			. "Such errors are normally fixed by removing or adding a couple of characters in the ASN.1 module.<BR>\n"
			. "<BR><B><FONT COLOR=darkred>&rArr; Please consider clicking on the appropriate &quot;<I>Help me fix it!</I>&quot; button above.</FONT></B><BR>\n"
			. "An email will be sent to a live person who will fix the ASN.1 module for you. (The typical turn-around time is less than 24 hours.)\n"
			. "<BR>This is <B>free</B>, and highly advisable.\n"
			. "<BR>Your request will help us make a better compiler!\n"
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
  "<TABLE WIDTH=100% BORDER=0 CELLSPACING=5 CELLPADDING=5><TR><TD class=inputbox VALIGN=top ROWSPAN=2 WIDTH=40%>\n"
. "<H3 ALIGN=center>ASN.1 Input</H3>\n"
. "$form"
. "</TD><TD WIDTH=60% HEIGHT=50% ALIGN=center VALIGN=$histValign>$history \n"
. "</TD></TR><TR><TD HEIGHT=50% VALIGN=bottom>"
	. "<B>Privacy Note:</B> this page is tailored "
	. "to your browser. "
	. "<I>Other users will see their own (different) data.</I> "
	. "(<A HREF=asn1c-privacy.html>Read more...</A>)"
. "</TD></TR></TABLE>";

$ua = $ENV{HTTP_USER_AGENT};
$ua =~ s/\\/\\\\/;
$ua =~ s/"/\\"/;
print LOG "\tUA=\"$ua\"";
print LOG "\n";	# Finalize logging record

PRINTOUT:

print header(-expires=>'-1y');

# If environment has never been set up completely, remove it.
if($EnvironmentSetOK != 1 && $TMPDIR ne "/") {
	system("rm -rf $TMPDIR/ >/dev/null 2>&1");
}

print<<"EOM";
<HTML>
<HEAD>
<TITLE>Free Online ASN.1 Compiler</TITLE>
<META NAME="Description" CONTENT="Free Online ASN.1 Compiler">
$redirect
<STYLE TYPE="text/css">
	TH {
		font-size: 11pt;
		color: #404040;
		font-family: monospace;
	}
	TH.num {
		font-size: 8pt;
		font-family: sans-serif;
	}
        TD {
                font-size: 10pt;
                font-family: sans-serif;
	}
	TD.inputbox {
		border-right: dashed 1px rgb(200, 200, 200);
	}
	DIV {
		font-size: 10pt;
                font-family: sans-serif;
	}
	.extrasmall {
                font-size: 7pt;
                font-family: sans-serif;
	}
	DIV.options {
                font-size: 7pt;
                font-family: sans-serif;
		padding-left: 1em;
		padding-bottom: 5px;
		margin-left: 1em;
	}
	DIV.options#options-bin {
		display: none;
		position: fixed;
	}
	DIV.options#options-ber {
		display: none;
		position: fixed;
	}
	DIV.optsbar#optsbar-lite { font-size: 7pt; }
	DIV.optsbar#optsbar-lite { font-size: 7pt; }
	DIV.optsbar {
                font-size: 8pt;
                font-family: sans-serif;
		padding: 4pt;
		border-left: dashed 1px rgb(200, 200, 200);
	}

	DIV.arrow {
		float: left;
		color: rgb(160,160,160);
	}

	DIV.aarr {
		display: block;
		margin-left: 1em;
		padding-bottom: 5px;
		padding-left: 2pt;
	}

	A.modrefs {
		color: #606060;
		text-decoration: none;
	}
	A:hover.modrefs {
		text-decoration: underline;
	}
	A:visited.modrefs {
		color: #b06060;
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
	Copyright &copy; 2003, 2004, 2005, 2006
Lev Walkin &lt;<A HREF=mailto:vlm&#64;lionet.info?Subject=asn1c>vlm&#64;lionet.info</A>&gt;
</FONT></ADDRESS></CENTER>
</BODY>
</HTML>
EOM
