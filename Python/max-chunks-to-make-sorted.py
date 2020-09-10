# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        result, max_i = 0, 0
        for i, v in enumerate(arr):
            max_i = max(max_i, v)
            if max_i == i:
                result += 1
        return result

    
# Time:  O(n)
# Space: O(n)
# mono stack solution
class Solution2(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        result, increasing_stk = 0, []
        for num in arr:
            max_num = num if not increasing_stk else max(increasing_stk[-1], num)
            while increasing_stk and increasing_stk[-1] > num:
                increasing_stk.pop()
            increasing_stk.append(max_num)
        return len(increasing_stk)
