#!/usr/bin/perl

#
# $Id$
# $Author$
#
# Simple tool that extracts known ASN.1 modules from the stream of LyX data.
#

if($#ARGV == -1) {
	print STDERR "Extract known modules from LyX data\n";
	print STDERR "Usage: cat *.lyx | $0 <ASN-Module-Name> ...\n";
	exit 64;
}

# Convert arguments into a hash for quicker search.
for(my $i; $i <= $#ARGV; $i++) {
	$modules{$ARGV[$i]} = $ARGV[$i].".asn1";
}

# Process incoming stream in search for ASN.1 modules.
while(<STDIN>) {
	chop;
	if($inmodule) {
		next if(/^$/);
		if(/^\\layout /) {
			print O "\n";
			next;
		}
		if(/^\\begin_inset Quotes/) {
			print O '"';
			next;
		}
		next if(/^\\/);
		print O;
		if(/^END$/) {
			$inmodule = 0;
			print O "\n";
		}
	} else {
		next unless $modules{$_};
		open(O, '> '.$modules{$_});
		print O;
		$inmodule = 1;
		delete $modules{$_};
	}
}

# Make sure noone's missing.
die "Modules not found: " . join(", ", keys %modules) . "\n" if keys %modules;
