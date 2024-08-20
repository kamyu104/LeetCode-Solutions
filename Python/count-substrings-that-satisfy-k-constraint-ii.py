# Time:  O(n)
# Space: O(n)

# two pointers, sliding window, prefix sum, hash table
class Solution(object):
    def countKConstraintSubstrings(self, s, k, queries):
        """
        :type s: str
        :type k: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def count(l):
            return (l+1)*l//2

        result = cnt = left = 0
        prefix = [0]*(len(s)+1)
        lookup = [-1]*len(s)
        for right in xrange(len(s)):
            cnt += int(s[right] == '1')
            while not (cnt <= k or (right-left+1)-cnt <= k):
                cnt -= int(s[left] == '1')
                left += 1
            result += right-left+1
            prefix[right+1] = prefix[right]+(right-left+1)
            lookup[left] = right
        assert(lookup[0] != -1)
        for i in xrange(len(s)-1):
            if lookup[i+1] == -1:
                lookup[i+1] = lookup[i]
        return [count(min(lookup[left], right)-left+1)+(prefix[right+1]-prefix[min(lookup[left], right)+1]) for left, right in queries]
