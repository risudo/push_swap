COUNT=12
MAX=1000
MIN=1

ARG="`jot -r -s " " ${COUNT} ${MIN} ${MAX}`"

echo "${ARG}"
./push_swap ${ARG}
