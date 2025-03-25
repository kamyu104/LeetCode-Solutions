# Time:  O(qlogr)
# Space: O(1)

# greedy
class Solution(object):
    def minOperations(self, queries):
        """
        :type queries: List[List[int]]
        :rtype: int
        """
        result = 0
        for l, r in queries:
            total = 0
            base = i = 1
            while base <= r:
                nl, nr = max(l, base), min(r, 4*base-1)
                if nl <= nr:
                    total += i*(nr-nl+1)
                i += 1
                base *= 4
            result += (total+1)//2
        return result
