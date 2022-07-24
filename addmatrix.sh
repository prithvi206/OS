#!/bin/bash
m=3
n=3
declare -A X
declare -A Y
#declare : built-in command used to declare shell variables and functions, set their attributes and display the values
declare -A Z
echo "enter the first 3*3 matrix:"
for((i=0;i<3;i++))
do
    for((j=0;j<3;j++))
    do
        read X[$i,$j]
    done
done

echo "enter the second 3*3 matrix:"
for((i=0;i<3;i++))
do
    for((j=0;j<3;j++))
    do
        read Y[$i,$j]
    done
done

echo "The first matrix:"
for((i=0;i<3;i++))
do
    for((j=0;j<3;j++))
    do
        echo -ne "${X[$i,$j]} "
        #-ne or -en will not append new line in echo
    done
echo -e "\n"
done


echo "The second matrix:"
for((i=0;i<3;i++))
do
    for((j=0;j<3;j++))
    do
        echo "${Y[$i,$j]}"
    done
echo -e "\n"
done

echo "The resultant matrix is :"
for((i=0;i<3;i++))
do
    for((j=0;j<3;j++))
    do
        Z[$i,$j]=$((X[$i,$j]+Y[$i,$j]))
        echo -ne "${Z[$i,$j]}"
    done
    echo -e "\n"
done


     