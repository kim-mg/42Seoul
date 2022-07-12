gcc -Wall -Werror -Wextra get_next_line.c main.c -o get_next_line
./get_next_line < main.c > yours_.res
cat -e yours_.res > yours.res
cat -e < main.c > origin.res
diff -y --suppress-common-line origin.res yours.res
rm -rf origin.res yours_.res yours.res get_next_line