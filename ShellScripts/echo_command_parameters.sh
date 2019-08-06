#! /bin/bash
echo \$\#, number of arguments: $#
echo \$*, all arguments: $*
echo \$0, command name: $0
declare -i i=1
while [ $i -le $# ]
do
	echo \$$i: ${!i}
	i=$((i+1))
done
