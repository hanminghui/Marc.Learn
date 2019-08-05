# extract outline from latex files
sed -n '
s/[{}]//g
s/\\section/	A. /p
s/\\subsection/		B. /p' $*
