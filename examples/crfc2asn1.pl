#!/usr/bin/env perl
#
# Extract the ASN.1 module text from the given set of RFC files.
#


my $inasn = 0;	# Are we inside ASN.1 grammar?
my $found = 0;
my $currentFname = '';

if(-t STDIN && $#ARGV == -1) {
	print STDERR "Extract the ASN.1 specification from the RFC file(s).\n";
	print STDERR "Usage 1: $0 <rfc-file.txt> ...\n";
	print STDERR "Usage 2: <someprog> | $0\n";
	exit(1);
}

while(<>) {
	#
	# Strip RFC page delimiters.
	#
	next if /^[A-Z].*\[Page [0-9]+\]$/;
	next if /^$/;
	next if /^RFC [0-9].*[0-9]+$/;

	if($inasn == 0) {
		#
		# The least correct way to find the start of ASN
		# definition. That is, to ask a user.
		#
		if(/^[ \t]*END[ \t]*(--.*)?$/) {
			print STDERR
			"Missed an ASN.1 grammar before line ". $. ."?\n";
			exit(1);
		}

		my $modName = '';	# ASN.1 module name
		my $rfcid = '';
		$rfcid = $1 . '-' if($ARGV =~ /([a-z0-9]+)\.[^.]+$/i);

		if(/^[ \t]*([A-Z][A-Za-z0-9-]*).*DEFINITIONS.*::=/) {
			$modName = $1;
			$currentFname = $rfcid . $modName . ".asn1";
			$inasn = 1;
		} elsif(/^[ \t]*([A-Z][A-Za-z0-9-]*).*{[ \t]*(?:joint-)?iso/
		|| /^[ \t]*{[ \t]*(?:joint-)?iso/) {
			my @a = ($_);
			$modName = $1;
			unless(length($modName)) {
				next unless $prevLine =~
					/^[ \t]*([A-Z][A-Za-z0-9-]*)[ \t]*$/;
				$modName = $1;
				unshift(@a, $prevLine);
			}
			$currentFname = $rfcid . $modName . ".asn1";
			my $i;
			for($i = 0; $i < 8; $i++) {
				$_ = <>;
				push(@a, $_);
				if(/DEFINITIONS/) {
					$_ = join('', @a);
					$inasn = 1;
					last;
				}
			}
			next unless $inasn;
		} elsif(/^\s*DEFINITIONS\s*$/
		&& $prevLine =~ /^\s*([A-Z][A-Za-z0-9-]*)\s*{[0-9a-z)( -]+}\s*$/) {
			$_ = $prevLine . $prevComments . $_;
			$modName = $1;
			$currentFname = $rfcid . $modName. ".asn1";
			$inasn = 1;
		} else {
			if(/^[ \t]*--/) {
				$prevComments .= $_;
			} else {
				$prevComments = '';
				$prevLine = $_;
			}
			next;
		}

		print STDERR "Found $modName at line $.\n=> Saving as $currentFname\n";
		open(O, "> $currentFname") or die "Can't open $currentFname";
		select(O);

		$found++;
		print "\n";
		print "-- \n";
		print "-- ASN.1 module found by $0 in $ARGV at line " . $. . "\n";
		print "-- \n";
		print "\n";
	}

	if(/^[ \t]*END[ \t]*(--.*)?$/) {
		print;
		select(STDOUT);
		close(O);
		$inasn = 0;
		next;
	}

	#
	# The following clauses are primarily designed to simplify
	# asn1c tool behavior.
	# You may want to get rid of them if you're doing generic
	# ASN.1 extraction and do not want to alter the ASN.1 specs at all.
	#
	if(
/^([ \t]*)((UniversalString|BMPString|UTF8String)\s+::=\s+\[[A-Z]+\s\d+\]\sIMPLICIT\sOCTET\sSTRING)(.*)$/ms
	) {
		print "\n-- Legacy redefinition of $3 removed by $0:\n";
		print "$1-- $2 -- $4";
		next;
	} elsif(/delete following line if \"new\" types are supported/) {
		print;
		print "/* Legacy constructs deleted by $0:\n";
		$_ = <>;
		print;
		print " */\n";
		next;
	}
 

	print;	# Dump the ASN.1 module line out.
}

die "No ASN.1 modules found\n" unless $found;
