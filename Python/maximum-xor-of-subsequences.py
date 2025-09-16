# Time:  O(nlogr), r = max(nums)
# Space: O(r)

# bitmasks, greedy
class Solution(object):
    def maxXorSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def max_xor_subset(nums):  # Time: O(nlogr)
            base = [0]*l 
            for x in nums:  # gaussian elimination over GF(2)
                for b in base:
                    if x^b < x:
                        x ^= b
                if x:
                    base.append(x)
            max_xor = 0
            for b in base:  # greedy
                if (max_xor^b) > max_xor:
                    max_xor ^= b
            return max_xor

        l = max(nums).bit_length()
        return max_xor_subset(nums)


# Time:  O(nlogr), r = max(nums)
# Space: O(r)
# bitmasks, greedy
class Solution2(object):
    def maxXorSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def max_xor_subset(nums):  # Time: O(nlogr)
            base = [0]*l 
            for x in nums:  # gaussian elimination over GF(2)
                for i in reversed(xrange(len(base))):
                    if not x&(1<<i):
                        continue
                    if base[i] == 0:
                        base[i] = x
                        break
                    x ^= base[i]
            max_xor = 0
            for b in reversed(base):  # greedy
                if (max_xor^b) > max_xor:
                    max_xor ^= b
            return max_xor

        l = max(nums).bit_length()
        return max_xor_subset(nums)
