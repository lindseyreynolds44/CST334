#! /bin/bash

# ECHO COMMAND
echo Hello World!

# VARIABLES 
NAME="Brad"
#echo "my name is ${NAME}"

# USER INPUT
#read -p "Enter your name: " NAME
#echo "Hello $NAME, nice to meet you!"


# IF-ELSE 
if [ "$NAME" == "Lindsey" ]
then 
    echo "Your name is Lindsey"
elif [ "$NAME" == "Jack" ]
then 
    echo "Your name is Jack"
else 
    echo "Your name is not Lindsey or Jack"
fi

# COMPARISONS 
NUM1=30
NUM2=5
if [ "$NUM1" -gt "$NUM2" ]
then 
    echo "$NUM1 is greater than $NUM2"
else 
    echo "$NUM1 is less than $NUM2"
fi

# FILE CONDITIONS 
FILE="test.txt"
if [ -e "$FILE" ]
then 
    echo "$FILE exists"
else 
    echo "$FILE does not exist"
fi 

# CASE STATEMENTS
read -p "Are you 21 or over? Y/N " ANSWER
case "$ANSWER" in
    [yY] | [yY][eE][sS])
        echo "You can have a beer :)"
        ;;
    [nN] | [nN][oO])
        echo "Sorry, no drinking"
        ;;
    *)
        echo "Please enter y/yes or n/no"
        ;;
    esac


# SIMPLE FOR LOOP
NAMES="Brad Kevin Alice Mark"

for NAME in $NAMES
    do 
        echo "Hello $NAME"
done

# FOR LOOP TO RENAME FILES
FILES=$(ls *.txt)
NEW="new"
for FILE in $FILES 
    do 
        echo "Renaming $FILE to new-$FILE"
        mv $FILE $NEW-$FILE
done

# WHILE LOOP - READ THROUGH A FILE
LINE=1
while read -r CURRENT_LINE
    do
        echo "$LINE: $CURRENT_LINE"
        ((LINE++))
done < "./new-1.txt"


# FUNCTION WITH PARAMS
function greet() {
    echo "Hello, I am $1 and I am $2"
}

greet "Brad" "36"