#!/bin/bash
echo "Enter a string" 
read str1
length=${#str1}
for((i=$length-1;i>=0;i--))
do 
REV=$REV${str1:$i:1}
done
echo "the reverse of the string using looping is"
echo $REV
echo "to check whether the input string is palindrome or not"
if [ $str1 = $REV ]
then
  echo "$str1 is a palindrome"

else
  echo "$str1 is not a palindrome"
fi