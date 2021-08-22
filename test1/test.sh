cd ./out

files=`find ../text -name '*.txt'`

for cur in $files;
do
	./test $cur > test.txt
	diff $cur test.txt >> result.txt 2>&1
	if [ $? -eq 0 ]; then
		echo "${cur##*/} : OK"
	elif [ $? -eq 1 ]; then
		echo "${cur##*/} : KO"
	fi
done
