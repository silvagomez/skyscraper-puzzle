printf "Test no input\n"
./a.out | cat -e

printf "\nTest empty string\n"
./a.out " " | cat -e

printf "\nTest extra space start\n"
./a.out " 3 2 2 1 2 1 3 2 3 2 1 2 1 2 3 2" | cat -e

printf "\nTest extra space mid sentence\n"
./a.out "3 2 2 1 2 1 3 2 3  2 1 2 1 2 3 2" | cat -e

printf "\nTest extra space end sentence\n"
./a.out "3 2 2 1 2 1 3 2 3 2 1 2 1 2 3 2 " | cat -e

printf "\nTest bigger than acceptable number\n"
./a.out "5 2 2 1 2 1 3 2 3 2 1 2 1 2 3 2" | cat -e

printf "\nTest nadditional parameter\n"
./a.out "5 2 2 1 2 1 3 2 3 2 1 2 1 2 3 2" "hola" | cat -e

printf "\nTest Unsolvable puzzle\n"
./a.out "1 1 1 1 2 1 3 2 3 1 3 2 2 3 1 3" | cat -e

printf "\nTest 1 should be OK\n"
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e

printf "\nTest 2 should be OK\n"
./a.out "2 3 1 2 2 1 3 2 3 1 3 2 2 3 1 3" | cat -e

printf "\nTest 3 should be OK\n"
./a.out "2 3 1 2 1 2 3 2 2 3 2 1 2 1 3 2" | cat -e

printf "\nTest 4 should be OK\n"
./a.out "3 2 2 1 2 1 3 2 3 2 1 2 1 2 3 2" | cat -e

printf "\nTest 5 should be OK\n"
./a.out "1 2 2 3 2 3 1 2 1 2 3 2 3 2 1 2" | cat -e

printf "\nTest 6 should be OK\n"
./a.out "2 2 3 1 3 1 2 2 3 1 2 2 1 3 2 2" | cat -e

printf "\nTest 7 should be OK\n"
./a.out "3 1 2 2 2 2 3 1 2 2 1 3 2 2 3 1" | cat -e

printf "\nTest 8 should be OK\n"
./a.out "1 3 2 2 3 1 2 2 1 3 2 2 2 2 1 3" | cat -e

printf "\nTest 9 should be OK:\n"
./a.out "3 2 2 1 2 1 2 3 3 2 1 2 1 2 2 3" | cat -e

printf "\nTest 10 should be OK:\n"
./a.out "2 2 1 3 3 1 2 2 3 1 2 2 2 2 1 3" | cat -e