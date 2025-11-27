valgrind \
 --leak-check=full \
 --track-origins=yes \
 --show-leak-kinds=all \
 --track-fds=yes \
 --suppressions=mlx.supp \
  ./cub3D maps/test_map.cub
