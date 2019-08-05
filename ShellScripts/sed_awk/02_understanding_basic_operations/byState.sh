#! /bin/bash
# Usage: sed -f nameState.sed maillist | ./byState.sh
# first, add state to front of each line
awk -F, '{print $4 ", " $0}' |
# then, sort by the state
sort |
# last, output by the state
awk -F, '
$1 == LastState{
	print "\t" $2
}
$1 != LastState{
	LastState = $1
	print $1
	print "\t" $2
}'
