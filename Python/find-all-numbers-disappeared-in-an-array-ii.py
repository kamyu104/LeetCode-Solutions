# Time:  O(r)
# Space: O(r)

# hash table
class Solution(object):
    def findDisappearedNumbers(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[List[int]]
        """
        lookup = [False]*(upper-lower+1)
        for x in nums:
            if not lower <= x <= upper:
                continue
            lookup[x-lower] = True
        result = []
        l = 0
        for i in xrange(len(lookup)):
            l += 1
            if i+1 == len(lookup) or lookup[i+1] != lookup[i]:
                if not lookup[i]:
                    result.append([lower+(i-l+1), lower+i])
                l = 0
        return result


# Time:  O(nlogn)
# Space: O(1)
# sort
class Solution2(object):
    def findDisappearedNumbers(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        for x in nums:
            if x > upper:
                break
            if x < lower:
                continue
            if lower <= x-1:
                result.append([lower, x-1])
            lower = x+1
        if lower <= upper:
            result.append([lower, upper])
        return result
