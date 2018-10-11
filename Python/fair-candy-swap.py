# Time:  O(m + n)
# Space: O(m + n)

class Solution(object):
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        diff = (sum(A)-sum(B))//2
        setA = set(A)
        for b in set(B):
            if diff+b in setA:
                return [diff+b, b]
        return []

