# Name: Lindsey Reynolds
# Date: 03/10/20
# Title: Lab1 - Step 3
# Description: This program computes the area of a circle 

#!/bin/bash

echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$

user=`whoami`
numusers=`who | wc -l`
pi=3.1416

echo "Hi $user! There are $numusers users logged on."
if [ $user = "lindseyreynolds" ]
then
 echo "Now you can proceed!"
else
 echo "Check who logged in!"
 exit 1
fi

response="Yes"
while [ $response != "No" ]
do
 echo "Enter radius of a circle: "
 read radius
 area=`expr "$pi * $radius * $radius" | bc`
 echo "The area of the circle is $area"
 echo "Would you like to repeat for another circle [Yes/No]?"
 read response
done