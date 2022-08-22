c++ -Wall -Wextra -Werror -g test.cpp
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./a.out
rm -rf a.out