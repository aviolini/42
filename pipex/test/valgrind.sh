#! /bin/bash

# --show-reachable=yes
# --log-file="valgrind"
# --track-fds=yes
#COMPLETO
#valgrind -s -q --track-fds=yes --leak-check=full --track-origins=yes --trace-children=yes --show-leak-kinds=all ./pipex . "lsi" "wc -l" outfile #2>>my_error
# --log-file=$1


make -C .. re && make -C .. clean
clear
valgrind -s -q --leak-check=full --track-fds=yes --trace-children=yes --show-leak-kinds=all ../pipex infile "cat" "wc -l" outfile
valgrind -s -q --leak-check=full --track-fds=yes --trace-children=yes --show-leak-kinds=all ../pipex infile "cati" "wc -l" outfile
valgrind -s -q --leak-check=full --track-fds=yes --trace-children=yes --show-leak-kinds=all ../pipex infile "cat" "wcx -l" outfile
valgrind -s -q --leak-check=full --track-fds=yes --trace-children=yes --show-leak-kinds=all ../pipex infile "cat -a" "wc -k" outfile