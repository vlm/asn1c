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
			exit(1);
		}

		my $rfcid = '';
		$rfcid = $1 . '-' if($ARGV =~ /([a-z0-9]+)/i);

		if(/^[ \t]+([A-Za-z0-9-]+).*DEFINITIONS.*::=/) {
			my $fname = $rfcid . $1 . ".asn1";
			open(O, "> $fname") or die "Can't open $fname";
			select(O);
			$inasn = 1;
		} elsif(/^[ \t]*([A-Za-z0-9-]+).*{.*iso/) {
			my $fname = $rfcid . $1 . ".asn1";
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
			open(O, "> $fname") or die "Can't open $fname";
			select(O);
		} else {
			next;
		}

		$found++;
		print "\n";
		print "-- \n";
		print "-- ASN.1 module found in $ARGV by $0 at " . $. . "\n";
		print "-- \n";
		print "\n";
	}

	print;

	if(/^[ \t]*END[ \t]*$/) {
		select(STDOUT);
		close(O);
		$inasn = 0;
	}
}

die "No ASN.1 specifications found\n" unless $found;
