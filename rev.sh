#!/bin/bash
echo "enter a string to reverse"
echo 
read str1
echo "The reverse of the string using inbuilt function is:"
echo $srt1|rev
echo
length=${#str1}

echo ${length}