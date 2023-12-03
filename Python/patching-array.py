# Time:  O(s + logn), s is the number of elements in the array
# Space: O(1)

class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        result = reachable = 0
        for x in nums:
            if x > n:
                break
            while not reachable >= x-1:
                result += 1
                reachable += reachable+1
            reachable += x
        while not reachable >= n:
            result += 1
            reachable += reachable+1
        return result


# Time:  O(s + logn), s is the number of elements in the array
# Space: O(1)
class Solution2(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        result = reachable = 0
        for x in nums:
            while not reachable >= x-1:
                result += 1
                reachable += reachable+1
                if reachable >= n:
                    return result
            reachable += x
            if reachable >= n:
                return result
        while not reachable >= n:
            result += 1
            reachable += reachable+1
        return result


# Time:  O(s + logn), s is the number of elements in the array
# Space: O(1)
class Solution3(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        patch, miss, i = 0, 1, 0
        while miss <= n:
            if i < len(nums) and nums[i] <= miss:
                miss += nums[i]
                i += 1
            else:
                miss += miss
                patch += 1

        return patch

