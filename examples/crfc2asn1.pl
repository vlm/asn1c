#!/usr/bin/perl

#
# $Id$
# $Author$
#
# Simple tool that fetches the ASN.1 specifications from the
# given set of RFC files.
#


my $inasn = 0;	# Are we inside ASN.1 grammar?
my $found = 0;
my $currentFname = '';

if(-t STDIN && $#ARGV == -1) {
	print STDERR "Rip ASN.1 specification from RFC file\n";
	print STDERR "Usage: $0 <rfc-file.txt> ...\n";
	print STDERR "Usage: <someprog> | $0\n";
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
		# definition.
		#
		if(/^[ \t]*END[ \t]*$/) {
			print STDERR
			"Missed an ASN.1 grammar before line ". $. ."?\n";
			unlink($currentFile) or die "Can't remove $!";
			print STDERR "Removed $currentFile";
			exit(1);
		}

		my $rfcid = '';
		$rfcid = $1 . '-' if($ARGV =~ /([a-z0-9]+)/i);

		if(/^[ \t]+([A-Za-z0-9-]+).*DEFINITIONS.*::=/) {
			$currentFname = $rfcid . $1 . ".asn1";
			$inasn = 1;
		} elsif(/^[ \t]*([A-Za-z0-9-]+).*{.*iso/) {
			$currentFname = $rfcid . $1 . ".asn1";
			my @a = ($_);
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
		} else {
			next;
		}

		print STDERR "Found $1 at line $. => $currentFname\n";
		open(O, "> $currentFname") or die "Can't open $currentFname";
		select(O);

		$found++;
		print "\n";
		print "-- \n";
		print "-- ASN.1 module found by $0 in $ARGV at line " . $. . "\n";
		print "-- \n";
		print "\n";
	}

	if(/^[ \t]*END[ \t]*$/) {
		print;
		select(STDOUT);
		close(O);
		$inasn = 0;
		next;
	}

	#
	# The following clauses are primarily designed to make
	# asn1c command-line easier (i.e., to avoid "-ftypes88").
	# You may want to get rid of them if you're doing generic
	# ASN.1 extraction and do not want to alter the ASN.1 specs.
	#
	if(
/^(.*)((UniversalString|BMPString|UTF8String)\s+::=\s+\[[A-Z]+\s\d+\]\sIMPLICIT\sOCTET\sSTRING)(.*)$/ms
	) {
		print "\n-- Legacy redefinition of $3 removed by $0:\n";
		print "$1-- $2 -- $4";
		next;
	} elsif(/delete following line if \"new\" types are supported/) {
		print;
		print "/* Legacy stuff deleted by $0:\n";
		$_ = <>;
		print;
		print " */\n";
		next;
	}
 

	print;	# Dump the ASN.1 module line out.
}

die "No ASN.1 modules found\n" unless $found;
