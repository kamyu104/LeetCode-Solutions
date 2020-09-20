# Time:  O(n * 2^(n - 1))
# Space: O(n)

class Solution(object):
    def maxUniqueSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        def popcount(n):
            count = 0
            while n:
                n &= n-1
                count += 1
            return count
    
        result = 1
        total = 2**(len(s)-1)
        for mask in xrange(total):
            if popcount(mask) < result:
                continue
            lookup, curr, base = set(), [], 1
            for i in xrange(len(s)):
                curr.append(s[i])
                if (mask&base) or base == total:
                    if "".join(curr) in lookup:
                        break
                    lookup.add("".join(curr))
                    curr = []
                base <<= 1
            else:
                result = max(result, len(lookup))
        return result
