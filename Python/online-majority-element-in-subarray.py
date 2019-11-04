# Time:  ctor:  O(n)
#        query: O(klogn), k = log2(Q/ERROR_RATE)
# Space: O(n)

import collections
import random
import bisect


class MajorityChecker(object):

    def __init__(self, arr):
        """
        :type arr: List[int]
        """
        Q, ERROR_RATE = 10000, 0.001
        self.__K = int(Q/ERROR_RATE).bit_length()  # floor(log2(Q/ERROR_RATE))+1 = 24
        self.__arr = arr
        self.__inv_idx = collections.defaultdict(list)
        for i, x in enumerate(self.__arr):
            self.__inv_idx[x].append(i)

    def query(self, left, right, threshold):
        """
        :type left: int
        :type right: int
        :type threshold: int
        :rtype: int
        """
        def count(inv_idx, m, left, right):
            return bisect.bisect_right(inv_idx[m], right) - \
                   bisect.bisect_left(inv_idx[m], left)

        for _ in xrange(self.__K):
            m = self.__arr[random.randint(left, right)]
            if count(self.__inv_idx, m, left, right) >= threshold:
                return m
        return -1


# Time:  ctor:  O(n)
#        query: O(sqrt(n)*logn)
# Space: O(n)
import collections
import bisect


class MajorityChecker2(object):

    def __init__(self, arr):
        """
        :type arr: List[int]
        """
        self.__arr = arr
        self.__inv_idx = collections.defaultdict(list)
        for i, x in enumerate(self.__arr):
            self.__inv_idx[x].append(i)
        self.__bound = int(round((len(arr)**0.5)))
        self.__majorities = [i for i, group in self.__inv_idx.iteritems() if len(group) >= self.__bound]

    def query(self, left, right, threshold):
        """
        :type left: int
        :type right: int
        :type threshold: int
        :rtype: int
        """
        def count(inv_idx, m, left, right):
            return bisect.bisect_right(inv_idx[m], right) - \
                   bisect.bisect_left(inv_idx[m], left)

        def boyer_moore_majority_vote(nums, left, right):
            m, cnt = nums[left], 1
            for i in xrange(left+1, right+1):
                if m == nums[i]:
                    cnt += 1
                else:
                    cnt -= 1
                    if cnt == 0:
                        m = nums[i]
                        cnt = 1
            return m

        if right-left+1 < self.__bound:
            m = boyer_moore_majority_vote(self.__arr, left, right)
            if count(self.__inv_idx, m, left, right) >= threshold:
                return m
        else:
            for m in self.__majorities:
                if count(self.__inv_idx, m, left, right) >= threshold:
                    return m
        return -1


# Time:  ctor:  O(nlogn)
#        query: O((logn)^2)
# Space: O(n)
import functools


class SegmentTreeRecu(object):  # 0-based index
    def __init__(self, nums, count):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        N = len(nums)
        self.__original_length = N
        self.__tree_length = 2**(N.bit_length() + (N&(N-1) != 0))-1
        self.__tree = [-1 for _ in range(self.__tree_length)]
        self.__count = count
        self.__constructTree(nums, 0, self.__original_length-1, 0)

    def query(self, i, j):
        return self.__queryRange(i, j, 0, self.__original_length-1, 0)

    def __constructTree(self, nums, left, right, idx):
        if left > right:
             return
        if left == right:
            self.__tree[idx] = nums[left]
            return 
        mid = left + (right-left)//2
        self.__constructTree(nums, left, mid, idx*2 + 1)
        self.__constructTree(nums, mid+1, right, idx*2 + 2)
        if self.__tree[idx*2 + 1] != -1 and \
           self.__count(self.__tree[idx*2 + 1], left, right)*2 > right-left+1:
            self.__tree[idx] = self.__tree[idx*2 + 1] 
        elif self.__tree[idx*2 + 2] != -1 and \
             self.__count(self.__tree[idx*2 + 2], left, right)*2 > right-left+1:
            self.__tree[idx] = self.__tree[idx*2 + 2] 

    def __queryRange(self, range_left, range_right, left, right, idx):
        if left > right:
            return (-1, -1)
        if right < range_left or left > range_right:
            return (-1, -1)
        if range_left <= left and right <= range_right:
            if self.__tree[idx] != -1:
                c = self.__count(self.__tree[idx], range_left, range_right)
                if c*2 > range_right-range_left+1:
                    return (self.__tree[idx], c)
        else:
            mid = left + (right-left)//2
            result = self.__queryRange(range_left, range_right, left, mid, idx*2 + 1)
            if result[0] != -1:
                return result
            result = self.__queryRange(range_left, range_right, mid + 1, right, idx*2 + 2)
            if result[0] != -1:
                return result
        return (-1, -1)


class MajorityChecker3(object):

    def __init__(self, arr):
        """
        :type arr: List[int]
        """
        def count(inv_idx, m, left, right):
            return bisect.bisect_right(inv_idx[m], right) - \
                   bisect.bisect_left(inv_idx[m], left)

        self.__arr = arr
        self.__inv_idx = collections.defaultdict(list)
        for i, x in enumerate(self.__arr):
            self.__inv_idx[x].append(i)
        self.__segment_tree = SegmentTreeRecu(arr, functools.partial(count, self.__inv_idx))

    def query(self, left, right, threshold):
        """
        :type left: int
        :type right: int
        :type threshold: int
        :rtype: int
        """
        result = self.__segment_tree.query(left, right)
        if result[1] >= threshold:
            return result[0]
        return -1


# Time:  ctor:  O(n)
#        query: O(sqrt(n)*logn)
# Space: O(n)
import collections
import bisect


class MajorityChecker4(object):

    def __init__(self, arr):
        """
        :type arr: List[int]
        """
        self.__arr = arr
        self.__inv_idx = collections.defaultdict(list)
        for i, x in enumerate(self.__arr):
            self.__inv_idx[x].append(i)
        self.__bucket_size = int(round((len(arr)**0.5)))
        self.__bucket_majorities = []
        for left in xrange(0, len(self.__arr), self.__bucket_size):
            right = min(left+self.__bucket_size-1, len(self.__arr)-1)
            self.__bucket_majorities.append(self.__boyer_moore_majority_vote(self.__arr, left, right))

    def query(self, left, right, threshold):
        """
        :type left: int
        :type right: int
        :type threshold: int
        :rtype: int
        """
        def count(inv_idx, m, left, right):
            return bisect.bisect_right(inv_idx[m], right) - \
                   bisect.bisect_left(inv_idx[m], left)

        l, r = left//self.__bucket_size, right//self.__bucket_size;
        if l == r:
            m = self.__boyer_moore_majority_vote(self.__arr, left, right)
            if count(self.__inv_idx, m, left, right) >= threshold:
                return m
            return -1
        else:
            m = self.__boyer_moore_majority_vote(self.__arr, left, (l+1)*self.__bucket_size-1)
            if count(self.__inv_idx, m, left, right) >= threshold:
                return m
            m = self.__boyer_moore_majority_vote(self.__arr, r*self.__bucket_size, right)
            if count(self.__inv_idx, m, left, right) >= threshold:
                return m;
            for i in xrange(l+1, r):
                if count(self.__inv_idx, self.__bucket_majorities[i], left, right) >= threshold:
                    return self.__bucket_majorities[i]
            return -1
    
    def __boyer_moore_majority_vote(self, nums, left, right):
            m, cnt = nums[left], 1
            for i in xrange(left+1, right+1):
                if m == nums[i]:
                    cnt += 1
                else:
                    cnt -= 1
                    if cnt == 0:
                        m = nums[i]
                        cnt = 1
            return m
