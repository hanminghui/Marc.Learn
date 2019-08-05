# replace blank line, even line contains spaces
s/^ *$/.LP/
/^+  */d
# replace spaces at begin of the line
s/^  *//
# replace spaces at end of the line
s/ *$//
# replace spaces more than one to just one space
s/  */ /g
s/\.  */.  /g
