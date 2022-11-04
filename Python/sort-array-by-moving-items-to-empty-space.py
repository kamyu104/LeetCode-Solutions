# Time:  O(n)
# Space: O(n)

# greedy
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def index(x, d):
            return d*(len(nums)-1) if x == 0 else x-d
    
        def min_moves(d):
            a = nums[:]
            result = 0
            for i in xrange(len(a)):
                l, found = 1, (a[i] == 0)
                while index(a[i], d) != i:
                    j = index(a[i], d)
                    a[i], a[j] = a[j], a[i]
                    l += 1
                    found |= (a[i] == 0)
                if l >= 2:
                    result += l-1 if found else l+1
            return result

        return min(min_moves(0), min_moves(1))


# Time:  O(n)
# Space: O(n)
# greedy
class Solution2(object):
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
