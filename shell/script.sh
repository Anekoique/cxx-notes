echo This is my first shell script
touch testfile
ls
echo End of mt shell script

echo $USER

variable_name="Geeksforgeeks"
echo $variable_name

x=10
y=11
if [ $x -ne $y ]
then
echo "not equal"
fi

x=2
while [ $x -lt 6 ]
do
echo $x
x=`expr $x + 1`
done

echo "No of arguments is $#"
echo "Name of the script is $0"
echo "FIrst argument is $1"
echo "Second argument is $2"

b=$(pwd)
c=`pwd`
echo $b
echo $c
d=$(ls /bin | grep bash)
echo $d

messages=$(cat << EOF
hello there!
this is multi-line message created using a here document.
EOF
)
echo "$messages"
echo $messages


messages=$(cat <<- EOF
	hello there!
	this is multi-line message created using a here document.
EOF
)
echo "$messages"
echo $messages

command << delimiter




