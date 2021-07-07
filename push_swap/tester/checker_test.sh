# push_swap 경로 설정해주세요
# CNT : 원소 개수
# LIMIT : 최대 operation 개수

CNT=100
LIMIT=700
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`../push_swap $ARG | wc -l`
A=`../push_swap $ARG | ../checker_Mac $ARG`
B=`../push_swap $ARG | ../checker $ARG`

while [ $NUM -lt $LIMIT -a $A == $B ]
do
	echo $NUM
	echo "Mac:$A, My:$B"
	ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
	NUM=`../push_swap $ARG | wc -l`
	A=`../push_swap $ARG | ../checker_Mac $ARG`
	B=`../push_swap $ARG | ../checker $ARG`
done
