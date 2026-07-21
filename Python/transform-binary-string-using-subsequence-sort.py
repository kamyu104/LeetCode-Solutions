# Time:  O(n * m)
# Space: O(n)

# prefix sum
class Solution(object):
    def transformStr(self, s, strs):
        """
        :type s: str
        :type strs: List[str]
        :rtype: List[bool]
        """
        prefix = [0]*(len(s)+1)
        for i in xrange(len(s)):
            prefix[i+1] = prefix[i]+(1 if s[i] == '1' else 0)
        result = [False]*len(strs)
        for i, t in enumerate(strs):
            left = right = 0
            for j in xrange(len(t)):
                left += (1 if t[j] == '1' else 0)
                right = min(right+(1 if t[j] != '0' else 0), prefix[j+1])
                if left > right:
                    break
            result[i] = left <= prefix[-1] <= right
        return result
