# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxAbsValExpr(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        # 1. max(|arr1[i]-arr1[j]| + |arr2[i]-arr2[j]| + |i-j| for i > j)
        #    = max(|arr1[i]-arr1[j]| + |arr2[i]-arr2[j]| + |i-j| for j > i)
        # 2. for i > j:
        #        (|arr1[i]-arr1[j]| + |arr2[i]-arr2[j]| + |i-j|)
        #        >= c1*(arr1[i]-arr1[j]) + c2*(arr2[i]-arr2[j]) + i-j for c1 in (1, -1), c2 in (1, -1)
        #        = (c1*arr1[i]+c2*arr2[i]+i) - (c1*arr1[j]+c2*arr2[j]+j) for c1 in (1, -1), c2 in (1, -1)
        # 1 + 2 => max(|arr1[i]-arr1[j]| + |arr2[i]-arr2[j]| + |i-j| for i != j)
        #          = max((c1*arr1[i]+c2*arr2[i]+i) - (c1*arr1[j]+c2*arr2[j]+j)
        #                for c1 in (1, -1), c2 in (1, -1) for i > j)
        result = 0
        for c1 in [1, -1]:
            for c2 in [1, -1]:
                min_prev = float("inf")
                for i in xrange(len(arr1)):
                    curr = c1*arr1[i] + c2*arr2[i] + i
                    result = max(result, curr-min_prev)
                    min_prev = min(min_prev, curr)
        return result

    
# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def maxAbsValExpr(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        return max(max(c1*arr1[i] + c2*arr2[i] + i for i in xrange(len(arr1))) -
                   min(c1*arr1[i] + c2*arr2[i] + i for i in xrange(len(arr1)))
                   for c1 in [1, -1] for c2 in [1, -1])
