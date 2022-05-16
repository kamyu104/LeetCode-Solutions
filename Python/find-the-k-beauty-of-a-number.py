# Time:  O(logn)
# Space: O(logn)

# sliding window
class Solution(object):
    def divisorSubstrings(self, num, k):
        """
        :type num: int
        :type k: int
        :rtype: int
        """
        result = curr = 0
        s = map(int, str(num))
        base = 10**(k-1)
        for i, x in enumerate(s):
            if i-k >= 0:
                curr -= s[i-k]*base
            curr = curr*10+x
            if i+1 >= k:
                result += int(curr and num%curr == 0)
        return result
