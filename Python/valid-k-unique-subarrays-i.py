# Time:  O(n + q)
# Space: O(n)

import collections
import random


# two pointers, hash table, prefix sum
class Solution(object):
    def validSubarrays(self, nums, k, queries):
        """
        :type nums: List[int]
        :type k: int
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        def min_left(k):
            result = [len(nums)]*len(nums)
            cnt = collections.defaultdict(int)
            left = 0
            for right in xrange(len(nums)):
                cnt[nums[right]] += 1
                while len(cnt) == k+1:
                    cnt[nums[left]] -= 1
                    if not cnt[nums[left]]:
                        del cnt[nums[left]]
                    left += 1
                if len(cnt) == k:
                    result[right] = left
            return result

        left = min_left(k)
        right = min_left(k-1)
        h = {}
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            if nums[i] not in h:
                h[nums[i]] = random.getrandbits(64)
            prefix[i+1] = prefix[i]^h[nums[i]]
        return [(r-l+1)%2 == 0 and prefix[r+1]^prefix[l] == 0 and left[r] <= l < right[r] for l, r in queries]


# Time:  O((n + q) * logn)
# Space: O(n + q)
import collections
import random


# hash table, prefix sum, fenwick tree
class Solution2(object):
    def validSubarrays(self, nums, k, queries):
        """
        :type nums: List[int]
        :type k: int
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        class BIT(object):  # 0-indexed.
            def __init__(self, n):
                self.__bit = [0]*(n+1)  # Extra one for dummy node.

            def add(self, i, val):
                i += 1  # Extra one for dummy node.
                while i < len(self.__bit):
                    self.__bit[i] += val
                    i += (i & -i)

            def query(self, i):
                i += 1  # Extra one for dummy node.
                ret = 0
                while i > 0:
                    ret += self.__bit[i]
                    i -= (i & -i)
                return ret

        h = {}
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            if nums[i] not in h:
                h[nums[i]] = random.getrandbits(64)
            prefix[i+1] = prefix[i]^h[nums[i]]
        groups = [[] for _ in xrange(len(nums))]
        for i, (l, r) in enumerate(queries):
            groups[r].append((i, l))
        result = [False]*len(queries)
        bit = BIT(len(nums))
        lookup = {}
        for r in xrange(len(nums)):
            if nums[r] in lookup:
                bit.add(lookup[nums[r]], -1)
            lookup[nums[r]] = r
            bit.add(lookup[nums[r]], 1)
            for i, l in groups[r]:
                result[i] = (r-l+1)%2 == 0 and prefix[r+1]^prefix[l] == 0 and (bit.query(r)-bit.query(l-1)) == k
        return result


# Time:  O(qlogq + (n + q) * sqrt(n))
# Space: O(n + q)
import collections


# sort, coordinate compression, mo's algorithm
class Solution3(object):
    def validSubarrays(self, nums, k, queries):
        """
        :type nums: List[int]
        :type k: int
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        # reference: https://cp-algorithms.com/data_structures/sqrt_decomposition.html
        def mo_s_algorithm():  # Time: O(QlogQ + (N + Q) * sqrt(N))
            def add(i):  # Time: O(F) = O(1)
                cnt[nums[i]] += 1
                odd[0] += 1 if cnt[nums[i]]&1 else -1        # odd count

            def remove(i):  # Time: O(F) = O(1)
                cnt[nums[i]] -= 1
                odd[0] += 1 if cnt[nums[i]]&1 else -1        # odd count
                if not cnt[nums[i]]:
                    del cnt[nums[i]]

            def get_ans():  # Time: O(A) = O(1)
                return (len(cnt) == k and odd[0] == 0)

            cnt = collections.defaultdict(int)
            odd = [0]
            result = [False]*len(queries)
            block_size = int(len(nums)**0.5)+1  # O(S) = O(sqrt(N))
            idxs = range(len(queries))
            idxs.sort(key=lambda x: (queries[x][0]//block_size, queries[x][1] if (queries[x][0]//block_size)&1 else -queries[x][1]))  # Time: O(QlogQ)
            left, right = 0, -1
            for i in idxs:  # Time: O((N / S) * N * F + S * Q * F + Q * A) = O((N + Q) * sqrt(N)), O(S) = O(sqrt(N)), O(F) = O(1), O(A) = 1
                l, r = queries[i]
                while left > l:
                    left -= 1
                    add(left)
                while right < r:
                    right += 1
                    add(right)
                while left < l:
                    remove(left)
                    left += 1
                while right > r:
                    remove(right)
                    right -= 1
                result[i] = get_ans()
            return result

        return mo_s_algorithm()
