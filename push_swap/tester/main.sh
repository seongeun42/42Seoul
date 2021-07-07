ARG=`jot -r 100 -2147483648 2147483647 | tr "\n" " "`

#echo `../push_swap $ARG`
echo `../push_swap $ARG | wc -l`
#echo `../push_swap $ARG | cat -e`
echo `../push_swap $ARG | ../checker_Mac $ARG`
echo `../push_swap $ARG | ../checker $ARG`
