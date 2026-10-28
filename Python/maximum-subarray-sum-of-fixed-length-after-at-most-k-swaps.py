# Time:  O(nlogn)
# Space: O(n)

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


# sort, coordinate compression, fenwick tree, greedy, sliding window
class Solution(object):
    def maxSum(self, nums, length, k):
        """
        :type nums: List[int]
        :type length: int
        :type k: int
        :rtype: int
        """
        def update(i, side, d):
            cnt[side].add(rank[i], d)
            total[side].add(rank[i], d*nums[i])

        def top_total(side, i):
            return total[side].query(len(nums)-1)-total[side].query(cnt[side].kth_element((length if side == IN else len(nums)-length)-i))

        IN, OUT = range(2)
        k = min(k, length, len(nums)-length)
        if k == 0:
            result = curr = sum(nums[i] for i in xrange(length))
            for i in xrange(length, len(nums)):
                curr += nums[i]-nums[i-length]
                result = max(result, curr)
            return result
        rank = [0]*len(nums)
        for i, x in enumerate(sorted(xrange(len(nums)), key=lambda i: nums[i])):
            rank[x] = i
        cnt = [BIT(len(nums)), BIT(len(nums))]
        total = [BIT(len(nums)), BIT(len(nums))]
        for i in xrange(length):
            update(i, IN, +1)
        for i in xrange(length, len(nums)):
            update(i, OUT, +1)
        result = total[IN].query(len(nums)-1)
        curr = sum(rank[i] >= len(nums)-length for i in xrange(length))
        for left in xrange(len(nums)-length+1):
            if curr >= length-k:
                return sum(x for i, x in enumerate(nums) if rank[i] >= len(nums)-length)
            result = max(result, top_total(IN, length-k)+top_total(OUT, k))
            right = left+length
            if right >= len(nums):
                continue
            update(left, IN, -1)
            update(left, OUT, +1)
            update(right, OUT, -1)
            update(right, IN, +1)
            curr += (rank[right] >= len(nums)-length)-(rank[left] >= len(nums)-length)
        return result


# Time:  O(n * (logn)^2)
# Space: O(n)
# sort, coordinate compression, fenwick tree, binary search, greedy, sliding window
class Solution2(object):
    def maxSum(self, nums, length, k):
        """
        :type nums: List[int]
        :type length: int
        :type k: int
        :rtype: int
        """
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        def update(i, side, d):
            cnt[side].add(rank[i], d)
            total[side].add(rank[i], d*nums[i])

        def kth_element(side, i):
            return nums[order[cnt[side].kth_element(i)]]

        def top_total(side, i):
            return total[side].query(len(nums)-1)-total[side].query(cnt[side].kth_element((length if side == IN else len(nums)-length)-i))

        IN, OUT = range(2)
        k = min(k, length, len(nums)-length)
        if k == 0:
            result = curr = sum(nums[i] for i in xrange(length))
            for i in xrange(length, len(nums)):
                curr += nums[i]-nums[i-length]
                result = max(result, curr)
            return result
        order = sorted(xrange(len(nums)), key=lambda i: nums[i])
        rank = [0]*len(nums)
        for i, x in enumerate(order):
            rank[x] = i
        cnt = [BIT(len(nums)), BIT(len(nums))]
        total = [BIT(len(nums)), BIT(len(nums))]
        for i in xrange(length):
            update(i, IN, +1)
        for i in xrange(length, len(nums)):
            update(i, OUT, +1)
        result = total[IN].query(len(nums)-1)
        for left in xrange(len(nums)-length+1):
            i = binary_search_right(1, k, lambda i: kth_element(OUT, (len(nums)-length)-i+1)-kth_element(IN, i) > 0)
            result = max(result, top_total(IN, length-i)+top_total(OUT, i))
            right = left+length
            if right >= len(nums):
                continue
            update(left, IN, -1)
            update(left, OUT, +1)
            update(right, OUT, -1)
            update(right, IN, +1)
        return result


# Time:  O(n^2)
# Space: O(n)
# sort, two pointers, greedy, sliding window
class Solution3(object):
    def maxSum(self, nums, length, k):
        """
        :type nums: List[int]
        :type length: int
        :type k: int
        :rtype: int
        """
        k = min(k, length, len(nums)-length)
        result = curr = sum(nums[i] for i in xrange(length))
        if k == 0:
            for i in xrange(length, len(nums)):
                curr += nums[i]-nums[i-length]
                result = max(result, curr)
            return result
        order = sorted(xrange(len(nums)), key=lambda i: nums[i])
        for left in xrange(len(nums)-length+1):
            right = left+length
            total, i, j = curr, 0, len(nums)-1
            for _ in xrange(k):
                while not (left <= order[i] < right):
                    i += 1
                while left <= order[j] < right:
                    j -= 1
                if nums[order[j]]-nums[order[i]] <= 0:
                    break
                total += nums[order[j]]-nums[order[i]]
                i += 1
                j -= 1
            result = max(result, total)
            if right >= len(nums):
                continue
            curr += nums[right]-nums[left]
        return result
