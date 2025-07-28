# Time:  O(nlogr * 2^n)
# Space: O(2^n)

# bitmasks, greedy
class Solution(object):
    def maximizeXorAndXor(self, nums):
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
        n = len(nums)
        and_arr = [0]*(1<<n)
        xor_arr = [0]*(1<<n)
        for mask in xrange(1, 1<<n):
            lb = mask&-mask
            i = lb.bit_length()-1
            and_arr[mask] = and_arr[mask^lb]&nums[i] if mask^lb else nums[i]
            xor_arr[mask] = xor_arr[mask^lb]^nums[i]
        result = 0
        full_mask = (1<<n)-1
        for mask in xrange(1, 1<<n):
            total_and = and_arr[mask]
            total_xor = xor_arr[full_mask^mask]
            max_xor = max_xor_subset(((nums[i]&~total_xor) for i in xrange(n) if not (mask&(1<<i))))
            result = max(result, total_and+total_xor+2*max_xor)
        return result


# Time:  O(nlogr * 2^n)
# Space: O(1)
# bitmasks, greedy
class Solution2(object):
    def maximizeXorAndXor(self, nums):
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
        n = len(nums)
        result = 0
        for mask in xrange(1, 1<<n):
            and_arr = -1
            xor_arr = 0
            for i in xrange(n):
                if mask&(1<<i):
                    and_arr = and_arr&nums[i] if and_arr != -1 else nums[i]
                else:
                    xor_arr ^= nums[i]
            max_xor = max_xor_subset(((nums[i]&~xor_arr) for i in xrange(n) if not (mask&(1<<i))))
            result = max(result, and_arr+xor_arr+2*max_xor)
        return result
