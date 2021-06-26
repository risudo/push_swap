gen_permutation() {
  echo -e "from itertools import permutations\nfor p in permutations(range(1, 1+$1)):\n    print(' '.join(str(i) for i in p))" | python3
}

# 5の順列をファイルに出力
gen_permutation 5 > permutation.txt
# ファイルの行ごとにテストして "行の内容: count: push_swapの行数 checker: checkerの結果" を出力
# while read line; do
#   count=$(./push_swap ${line} | wc -l | tr -d ' ')
#   checker_result=$(./push_swap ${line} | ./checker ${line})
#   printf "${line}: count: ${count} checker: ${checker_result}\n"
# done < permutation.txt