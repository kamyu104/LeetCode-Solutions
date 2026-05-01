# Time:  O(n)
# Space: O(1)

# freq table, sort
class Solution(object):
    def sortVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        VOWELS = "aeiou"
        cnt = {}
        for i, x in enumerate(s):
            if x not in VOWELS:
                continue 
            if x not in cnt:
                cnt[x] = [0, i]
            cnt[x][0] += 1
        sorted_cnt = sorted(([k, v, i] for k, (v, i) in cnt.iteritems()), key=lambda x: (-x[1], x[2]), reverse=True)
        result = list(s)
        for i in xrange(len(result)):
            if result[i] not in VOWELS:
                continue
            result[i] = sorted_cnt[-1][0]
            sorted_cnt[-1][1] -= 1
            if not sorted_cnt[-1][1]:
                sorted_cnt.pop()
        return "".join(result)
