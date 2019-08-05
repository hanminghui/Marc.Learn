# reduce multiple blank lines to one; version using d command
# if a blank line matched, and a blank line after
# delete the two blank line
/^$/{
	N
	/^\n$/d
}
# then read a new line to pattern space
