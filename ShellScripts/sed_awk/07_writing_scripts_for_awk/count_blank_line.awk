#/^$/ { print x += 1 }
# or
/^$/ { x++ }
END { print "blank line number: " x }
