s/@f1(\([^)]*\))/\\fB\1\\fR/g
/@f1(\([^)]*\))/!n
/@f1([^)]*$/!{
	n
}
/@f1([^)]*$/{
	H
	d
}
/[^(]*)/!{
	H
	d
}
/[^(]*)/{
	x
	G
	s/^\n//
	s/@f1(\([^)]*\))/\\fB\1\\fR/
}
