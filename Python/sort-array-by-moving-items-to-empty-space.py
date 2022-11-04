# Time:  O(n)
# Space: O(n)

# greedy
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def min_moves(d):
            lookup = [0]*len(nums)
            for i, x in enumerate(nums):
                lookup[x] = i
            result, i = 0, 1
            while i < len(nums):
                if lookup[0] != d*(len(nums)-1): 
                    ni = lookup[0]+d
                else:
                    for i in xrange(i, len(nums)):
                        if lookup[i]+d != i:
                            break
                    else:
                        i = len(nums)
                        continue
                    ni = i
                lookup[0], lookup[ni] = lookup[ni], lookup[0]
                result += 1
            return result

        return min(min_moves(0), min_moves(1))
