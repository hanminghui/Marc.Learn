{
	total = $2 + $3 + $4 + $5 + $6
	print NR ".", $1, "total: " total, "average: "  total / 5
}
END {print "students number: " NR }
