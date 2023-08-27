for((i = 1; i<=100 ; ++i));do
	echo $i
	#./gen $i > gin
	#./file < gin > out1
	#./brute < gin > out2
	#diff -w out1 out2 || break
	diff -w <(./file < gin) <(./brute < gin) || break  	
done  
# -w --> Command which commands not to check whitespaces
# Removing i<=100 puts it in  an infinite loop
