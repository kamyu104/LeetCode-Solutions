# Time:  O(n)
# Space: O(1)

class Solution(object):
    # @param A, a list of integers
    # @return an integer
    def maxProduct(self, A):
        global_max, local_max, local_min = float("-inf"), 1, 1
        for x in A:
            local_max, local_min = max(x, local_max * x, local_min * x), min(x, local_max * x, local_min * x)
            global_max = max(global_max, local_max)
        return global_max

class Solution2(object):
    # @param A, a list of integers
    # @return an integer
    def maxProduct(self, A):
        global_max, local_max, local_min = float("-inf"), 1, 1
        for x in A:
            local_max = max(1, local_max)
            if x > 0:
                local_max, local_min = local_max * x, local_min * x
            else:
                local_max, local_min = local_min * x, local_max * x
            global_max = max(global_max, local_max)
        return global_max

