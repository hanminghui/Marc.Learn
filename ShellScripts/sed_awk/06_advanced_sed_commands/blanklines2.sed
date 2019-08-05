# reduce multiple blank lines to one; version using D command
# if a blank line matched, and a blank line after
# Delete the first blank line
/^$/{
	N
	/^\n$/D
}
# then go to the next line in pattern space
