COUNT=500
MAX=2147483647
MIN=-2147483648

ARG="`jot -r -s " " ${COUNT} ${MIN} ${MAX}`"

echo "${ARG}"
./push_swap ${ARG}
./push_swap ${ARG} | ./checker ${ARG}
