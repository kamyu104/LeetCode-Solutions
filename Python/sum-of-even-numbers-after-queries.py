# Time:  O(n + q)
# Space: O(1)

class Solution(object):
    def sumEvenAfterQueries(self, A, queries):
        """
        :type A: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        total = sum(v for v in A if v % 2 == 0)
        
        result = []
        for v, i in queries:
            if A[i] % 2 == 0:
                total -= A[i]
            A[i] += v
            if A[i] % 2 == 0:
                total += A[i]
            result.append(total)
        return result
