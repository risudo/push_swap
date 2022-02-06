#!/bin/bash

GREEN="\033[32m"
RESET="\033[39m"

execute() {
	echo -e "$GREEN" "[[" ${1} ${2} "]]" "$RESET"
	./push_swap $1 $2
	echo
}

execute aa
execute 1a
execute 1 1
execute 2147483648 1
execute -2147483649 1
execute ""

