# process the command page
# delete the row of asterisks
/^\*\**\*$/d
# delete tabs at the begining of lines and following a colon
/^	/s///
/:	/s//:/
# add head macro
/NAME:/{
s//.Rh 0 "/
s/ - /" "/
s/$/"/
}
# change the SYNTAX part
/SYNTAX:/,/^$/{
/SYNTAX:/c\
.Rh Syntax\
.in +5n\
.ft B\
.nf\
.na
/^$/c\
.in -5n\
.ft R\
.fi\
.ab b
}
# change the USAGE part
/USAGE:/,/^$/{
/USAGE:/c\
.Rh Usage
/\(.*\)	- \(.*\)/s//.IP "\\fI\1\\fR" 15n\
\2./
}
# change the DESC part
/DESC:/,/RETURNS:/{
/DESC:/i\
.LP
s/DESC: *$/.Rh Description/
s/^$/.LP/
}
# change the RETURNS part
/RETURNS:/,/^$/{
/RETURNS:/c\
.Rh Return Value
s/There is no return value\.*/None./
}
# delete remaining blank lines, at the very last
/^$/d
