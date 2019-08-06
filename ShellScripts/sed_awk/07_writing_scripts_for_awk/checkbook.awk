# checkbook.awk
BEGIN { FS = "\t" }

#1 Expect the first record to have the starting balance
NR == 1 {
	print "Begining Balance: \t" $1
	balance = $1
	next      # get next record and start over
}

#2 Apply to each check record, adding amount from balance
{
	print $1, $2, $3
	print balance += $3
}
