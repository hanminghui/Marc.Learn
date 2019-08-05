# change the <para> tag and empty line after
/<para/{
$!N
c\
.LP
}
# extract the bitmap figure to a file
/<Figure Begin>/,/<Figure End>/{
/^$/d
w interleaf.fig
/<Figure End>/i\
.FG\
<insert figure here>\
.FE
d
}
/^$/d
