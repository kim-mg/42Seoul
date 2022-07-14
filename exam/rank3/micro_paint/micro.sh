gcc -Wall -Wextra -Werror micro_paint.c -lm -o _micro_paint
# g++ -Wall -Wextra -Werror generate_example.cpp -lm -o _gen

# ./_gen

counter=0
max=8

while [ $counter -le $max ]
do
	printf "\n\n=====================================$counter=======================================\n\n"
	./_micro_paint examples/$counter
	counter=$((counter + 1))
done

# cat output

# rm -rf _gen* _micro_paint* example_* output
rm -rf _micro_paint*