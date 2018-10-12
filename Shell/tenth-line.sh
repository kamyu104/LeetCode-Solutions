# Time:  O(n)
# Space: O(1)

awk '{if(NR==10) print $0}' file.txt
awk 'NR == 10' file.txt

sed -n 10p file.txt

tail -n+10 file.txt | head -1

