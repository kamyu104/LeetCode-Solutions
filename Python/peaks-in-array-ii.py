# Time:  O(nlogn + qlogn)
# Space: O(n)

# fenwick tree
class BIT(object):  # 0-indexed.
    def __init__(self, n):
        self.__bit = [0]*(n+1)  # Extra one for dummy node.

    def add(self, i, val):
        i += 1  # Extra one for dummy node.
        while i < len(self.__bit):
            self.__bit[i] += val
            i += (i&-i)

    def query(self, i):
        i += 1  # Extra one for dummy node.
        ret = 0
        while i > 0:
            ret += self.__bit[i]
            i -= (i&-i)
        return ret

    def kth_element(self, k):
        if k <= 0:
            return -1
        floor_log2_n = (len(self.__bit)-1).bit_length()-1
        pow_i = 2**floor_log2_n
        total = pos = 0  # 1-indexed
        for _ in reversed(xrange(floor_log2_n+1)):  # O(logN)
            if pos+pow_i < len(self.__bit) and not total+self.__bit[pos+pow_i] >= k:
                total += self.__bit[pos+pow_i]
                pos += pow_i
            pow_i >>= 1
        return (pos+1)-1


class Solution(object):
    def countOfPeaks(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def count(n):
            return n*(n-1)//2

        def update(i):
            if not 0 < i < len(nums)-1:
                return
            x = 1 if nums[i-1] < nums[i] > nums[i+1] else 0
            if lookup[i] == x:
                return
            d = x-lookup[i]
            lookup[i] = x
            bit.add(i, d)
            j = bit.kth_element(bit.query(i-1))
            if j >= 0:
                bit2.add(j, d*count(i-j))
            k = bit.kth_element(bit.query(i)+1)
            if k < len(nums):
                bit2.add(i, d*count(k-i))
            if j >= 0 and k < len(nums):
                bit2.add(j, -d*count(k-j))

        bit = BIT(len(nums))
        bit2 = BIT(len(nums))
        lookup = [0]*len(nums)
        prev = -1
        for i in xrange(1, len(nums)-1):
            if not nums[i-1] < nums[i] > nums[i+1]:
                continue
            lookup[i] = 1
            bit.add(i, 1)
            if prev >= 0:
                bit2.add(prev, count(i-prev))
            prev = i
        result = []
        for q in queries:
            if q[0] == 1:
                l, r = q[1], q[2]
                base = bit.query(l)
                cnt = bit.query(r-1)-base
                if cnt == 0:
                    result.append(0)
                    continue
                left = bit.kth_element(base+1)
                right = bit.kth_element(base+cnt)
                result.append(count(r-l)-(count(left-l)+(bit2.query(right-1)-bit2.query(left-1))+count(r-right)))
            else:
                nums[q[1]] = q[2]
                for i in xrange(q[1]-1, (q[1]+1)+1):
                    update(i)
        return result
