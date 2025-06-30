# Time:  O(n * l)
# Space: O(n)

# prefix sum
class Solution(object):
    def longestCommonPrefix(self, words):
        """
        :type words: List[str]
        :rtype: List[int]
        """
        def lcp(i, j):
            if i < 0 or j >= len(words):
                return 0
            s1, s2 = words[i], words[j]
            for k in xrange(min(len(s1), len(s2))):
                if s1[k] != s2[k]:
                    return k
            return k+1
    
        lcps = [lcp(i, i+1) for i in xrange(len(words)-1)]
        right = [0]*(len(lcps)+2)
        for i in reversed(xrange(len(lcps))):
            right[i] = max(right[i+1], lcps[i])
        result = [0]*len(words)
        left = 0
        for i in xrange(len(words)):
            if i-2 >= 0:
                left = max(left, lcps[i-2])
            result[i] = max(left, right[i+1], lcp(i-1, i+1))
        return result
