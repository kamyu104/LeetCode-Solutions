# Time:  O(n + 26)
# Space: O(26)

# freq table, math
class Solution(object):
    def score(self, cards, x):
        cnt1 = [0]*26
        cnt2 = [0]*26
        cnt3 = 0
        for s in cards:
            if x not in s:
                continue
            if s[0] == x == s[1]:
                cnt3 += 1
            elif s[0] == x:
                cnt1[ord(s[1])-ord('a')] += 1
            elif s[1] == x:
                cnt2[ord(s[0])-ord('a')] += 1
        total1, total2 = sum(cnt1), sum(cnt2)
        mx1, mx2 = max(cnt1), max(cnt2)
        pair1, pair2 = min(total1-mx1, total1//2), min(total2-mx2, total2//2)
        pair3 = min((total1-2*pair1)+(total2-2*pair2), cnt3)
        return (pair1+pair2)+pair3+min(pair1+pair2, (cnt3-pair3)//2)
