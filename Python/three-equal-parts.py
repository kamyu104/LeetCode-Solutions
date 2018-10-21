# Time:  O(n)
# Space: O(1)

class Solution(object):
    def threeEqualParts(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        total = sum(A)
        if total % 3 != 0:
            return [-1, -1]
        if total == 0:
            return [0, len(A)-1]

        count = total//3
        nums = [0]*3
        c = 0
        for i in xrange(len(A)):
            if A[i] == 1:
                if c % count == 0:
                    nums[c//count] = i
                c += 1

        while nums[2] != len(A):
            if not A[nums[0]] == A[nums[1]] == A[nums[2]]:
                return [-1, -1]
            nums[0] += 1
            nums[1] += 1
            nums[2] += 1
        return [nums[0]-1, nums[1]]
