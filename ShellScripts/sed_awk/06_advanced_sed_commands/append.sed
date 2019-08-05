# in 1 line
# when there is no line after the pattern
s/Owner and Operator Guide/Installation Guide/
# with \n
# firt find begin word , then read next line
# replace \n with blank
# and substitute
/Owner/{
$!N
s/ *\n/ /
s/Owner and Operator Guide */Installation Guide\
/
}
