# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def rearrangeArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        pos, neg = 0, 1
        result = [0]*len(nums)
        for x in nums:
            if x > 0:
                result[pos] = x
                pos += 2
            else:
                result[neg] = x
                neg += 2
        return result


# Time:  O(n)
# Space: O(1)
# generator
class Solution2(object):
    def rearrangeArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def pos():
            for x in nums:
                if x > 0:
                    yield x
        
        def neg():
            for x in nums:
                if x < 0:
                    yield x
        
        gen_pos = pos()
        gen_neg = neg()
        return [next(gen_pos) if i%2 == 0 else next(gen_neg)  for i in xrange(len(nums))]


# Time:  O(n)
# Space: O(n)
# array, implementation
class Solution3(object):
    def rearrangeArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        pos, neg = [], []
        for i in reversed(xrange(len(nums))):
            if nums[i] > 0:
                pos.append(nums[i])
            else:
                neg.append(nums[i])
        result = []
        for i in xrange(len(nums)):
            if i%2 == 0:
                result.append(pos.pop())
            else:
                result.append(neg.pop())
        return result
