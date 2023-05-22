#!/bin/bash

make && clear

EXE="./megaphone"

echo "Test 1:"
$EXE "shhhhh... I think the students are asleep..."
echo "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
echo

echo "Test 2:"
$EXE "Damnit" " ! " "Sorry students, I thought this thing was off."
echo "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
echo

echo "Test 3:"
$EXE
echo "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

make fclean &>/dev/null


echo
: <<'END'

The first line is called a "shebang" and specifies the interpreter to be used for executing the script. 
In this case, it is set to /bin/bash, indicating that the script should be interpreted by the Bash shell.

EXE="./megaphone" -> This line sets the value of the variable EXE to the string "./megaphone". 
It likely represents the path or name of an executable file that will be invoked later.

It prints "Test 1:" to the console. Then it executes the command stored in the variable EXE 
with the argument "shhhhh... I think the students are asleep...". 
The output is then printed using echo. The expected output is "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...".

The make fclean command, likely to clean up any generated files or artifacts created during the build process. 
The &>/dev/null portion redirects both standard output and standard error to /dev/null, 
discarding any output that might be generated.

END
echo