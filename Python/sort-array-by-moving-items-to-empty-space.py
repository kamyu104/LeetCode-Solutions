# Time:  O(n)
# Space: O(n)

# greedy, sort
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def min_moves(d):
            def index(x):
                return d*(len(nums)-1) if x == 0 else x-d

            lookup = [False]*len(nums)
            result = len(nums)
            for i in xrange(len(nums)):
                if lookup[nums[i]]:
                    continue
                l = 0
                while not lookup[nums[i]]:
                    lookup[nums[i]] = True
                    l += 1
                    i = index(nums[i])
                result -= 1
                if l >= 2:
                    result += 2
            return result-2*int(nums[d*(len(nums)-1)] != 0)

        return min(min_moves(0), min_moves(1))


# Time:  O(n)
# Space: O(n)
# greedy, sort
class Solution2(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def min_moves(d):
            def index(x):
                return d*(len(nums)-1) if x == 0 else x-d

            a = nums[:]
            result = 0
            for i in xrange(len(a)):
                l, has_zero = 1, (a[i] == 0)
                while index(a[i]) != i:
                    j = index(a[i])
                    a[i], a[j] = a[j], a[i]
                    l += 1
                    has_zero |= (a[i] == 0)
                if l >= 2:
                    result += l-1 if has_zero else l+1
            return result

        return min(min_moves(0), min_moves(1))
