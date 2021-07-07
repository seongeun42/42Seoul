ARG=`jot -r 11 -2147488 2147487 | tr "\n" " "`

#echo `../push_swap $ARG`
echo `../push_swap $ARG | wc -l`
#echo `../push_swap $ARG | cat -e`
#echo `../push_swap $ARG | ../checker_linux $ARG`
echo `../push_swap $ARG | ../checker $ARG`
