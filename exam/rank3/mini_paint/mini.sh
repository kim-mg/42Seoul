gcc -Wall -Wextra -Werror mini_paint.c -lm -o _mini_paint
# g++ -Wall -Wextra -Werror generate_example.cpp -lm -o _gen

# ./_gen

counter=1
max=2

while [ $counter -le $max ]
do
	printf "\n\n=====================================$counter=======================================\n\n"
	./_mini_paint examples/$counter
	counter=$((counter + 1))
done

# cat output

# rm -rf _gen* _micro_paint* example_* output
rm -rf _micro_paint*