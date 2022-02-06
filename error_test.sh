#!/bin/bash

GREEN="\033[32m"
RESET="\033[39m"

execute () {
	echo -e ${GREEN}${1}${RESET}
	eval $1
	echo ""
}

execute './push_swap aa'
execute './push_swap 1a'
execute './push_swap 2147483648 1'
execute './push_swap -2147483649 1'
execute './push_swap 4294967300 1'
execute './push_swap 1 1'
execute './push_swap +0 -0'
execute './push_swap'
