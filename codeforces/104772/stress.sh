P=e
make ${P} ${P}2 gen || exit 1
for ((i = 1; ; i++)) do
	./gen $i > in_
	./${P} < in_ > out
	./${P}2 < in_ > out2
	if (! cmp -s out out2) then
		echo "--> entrada:"
		cat in_
		echo "--> saida1:"
		cat out
		echo "--> saida2:"
		cat out2
		break;
	fi
	echo $i
done
