#!/usr/bin/env perl
#
# Convert check-parsing.sh's log to diff format.
#

if(-t STDIN && $#ARGV == -1) {
	print STDERR "Usage: check-parsing-log2diff.pl < check-parsing.sh.log > diff.patch\n";
	exit(1);
}

$state = 0;
while(<>) {
	if ($state == 0) {
		if (/^Checking\s*(.+?)\s*against\s*(.+?)$/) {
			$source = $1;
			$target = $2;
		} elsif (/^\-\-\-\s(.+?)\s.*/) {
			print "--- a/dev/null " . "\n";
		} elsif (/^\+\+\+\s(.+?)\s.*/) {
			print "+++ b" . $target . "\n";
			$state = 1;
		}
	} else {
		if (/^Checking\s*(.+?)\s*against\s*(.+?)$/) {
			$source = $1;
			$target = $2;
			$state = 0;
		} else {
			print $_;
		}
	}
}
