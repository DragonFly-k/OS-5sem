#! /bin/bash
if [ "$1" == "" ]
then 
echo "parametrs not found"
exit
else if ! [[ "$1" =~ [[:digit:]]+$ ]]
then 
echo "pid=$1 not int"
exit
else if ps -p $1 > /dev/null
then
echo "Name: " $(basename $(readlink -f /proc/$1/exe))
echo "Pid: " $1
echo "PPid: " $(ps -o ppid= -p $1)
else 
echo "pid=$1 process not found"
exit
fi
fi
fi

if [ "$2" == "fd" ]
then
for x in $(ls -l /proc/$1/fd | awk '{print $9}')
do 
echo "fd= "$x
done
fi 
