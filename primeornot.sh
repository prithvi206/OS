#!/bin/bash
echo "enter a number"
read n
flag=0
for((i=2 ;i<= $(($n/2));i++))
do
if [ $(($n%$i))==0 ]
then flag=1
fi
done
if [ $flag==0 ]
then echo "$n is a prime number"
else
echo "$n is not a prime number"
fi