#!/bin/bash
echo "enter the value of N to find the prime numbers from 1 to N"
read N

flag=0
echo "the prime numbers from 1 to $N are:"
echo

for((j=2;j<=N;j++))
do
   for((i=2 ;i<= $((j/2));i++))
    do

    if [ $((j%i))==0 ]
    then 
      flag=1
      break
    fi
    done
if [ $flag==0 ]
then echo -ne "$j"
fi
 flag=0
done