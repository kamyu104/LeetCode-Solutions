# Time:  O(n)
# Space: O(k), k is number of words

awk '{for(i=1;i<=NF;i++) a[$i]++} END {for(k in a) print k,a[k]}' words.txt | sort -k2 -nr

