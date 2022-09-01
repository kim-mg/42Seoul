make fclean
make debug

valgrind --leak-check=full --error-limit=no ./cub3D map/map1.cub
