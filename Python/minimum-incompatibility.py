# Time:  O(sum(i*d * nCr(i*d, d) * nCr(n, i*d) for i in xrange(1, k+1))) < O(sum(n * 2^m * nCr(n, m) for m in xrange(n+1))) = O(n * 3^n)
# Space: O(n * k)

import itertools


class Solution(object):
    def minimumIncompatibility(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        inf = (len(nums)-1)*(len(nums)//k)+1
        def backtracking(nums, d, lookup):
            if not nums:
                return 0
            if nums not in lookup:
                ret = inf
                for new_nums in itertools.combinations(nums, d):
                    new_nums_set = set(new_nums)
                    if len(new_nums_set) < d:
                        continue
                    left = []
                    for num in nums:
                        if num in new_nums_set:
                            new_nums_set.remove(num)
                            continue
                        left.append(num)
                    ret = min(ret, max(new_nums)-min(new_nums) + backtracking(tuple(left), d, lookup))
                lookup[nums] = ret
            return lookup[nums]
        
        result = backtracking(tuple(nums), len(nums)//k, {})
        return result if result != inf else -1


# Time:  O(max(n * 2^n, 3^n))
# Space: O(2^n)
class Solution_TLE(object):
    def minimumIncompatibility(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        inf = (len(nums)-1)*(len(nums)//k)+1
        POW = [1]
        for i in xrange(len(nums)):
            POW.append(POW[-1]<<1)
        
        def popcount(n):
            result = 0
            while n:
                n &= n - 1
                result += 1
            return result
    
        def find_candidates(nums, k):
            total = POW[len(nums)]-1
            m = len(nums)//k
            result = [inf]*(total+1)
            for mask in xrange(total+1):
                if popcount(mask) != m:
                    continue
                lookup = 0
                mx, mn = 0, inf
                for i in xrange(len(nums)):
                    if mask&POW[i] == 0:
                        continue
                    if lookup&POW[nums[i]]:
                        break
                    lookup |= POW[nums[i]]
                    mx = max(mx, nums[i])
                    mn = min(mn, nums[i])
                else:
                    result[mask] = mx-mn
            return result
        
        candidates = find_candidates(nums, k)
        m = len(nums)//k
        total = POW[len(nums)]-1
        dp = [inf]*(total+1)
        dp[0] = 0
        for mask in xrange(total+1):
            if popcount(mask) % m != 0:
                continue
            # submask enumeration:
            # => sum(nCr(n, k) * 2^k for k in xrange(n+1)) = (1 + 2)^n = 3^n
            # => Time: O(3^n), see https://cp-algorithms.com/algebra/all-submasks.html
            submask = mask
            while submask:
                dp[mask] = min(dp[mask], dp[mask-submask] + candidates[submask])
                submask = (submask-1)&mask
        return dp[-1] if dp[-1] != inf else -1


# Time:  O(nlogn)
# Space: O(n)
import collections
import sortedcontainers
# wrong with greedy solution
# nums = [15, 9, 7, 10, 15, 14, 12, 2, 10, 8, 10, 13, 4, 11, 2]
# k = 5
# greedy  => [[2, 4, 7], [2, 8, 9], [10, 11, 12], [10, 13, 15], [10, 14, 15]] => 24
# correct => [[2, 4, 7], [2, 8, 10], [9, 10, 11], [10, 12, 15], [13, 14, 15]] => 22
# optimized from Solution_Greedy, using SortedList (which is not supported in GoogleCodeJam / GoogleKickStart)
class Solution_Wrong_Greedy_SortedList(object):
    def minimumIncompatibility(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def greedy(nums, k, is_reversed):
            count = collections.Counter(nums)
            if max(count.itervalues()) > k:
                return -1
            ordered_set = sortedcontainers.SortedList(count.iterkeys())
            freq_to_nodes = collections.defaultdict(collections.OrderedDict)
            for x in ordered_set:
                freq_to_nodes[count[x]][x] = count[x]
            stks = [[] for _ in xrange(k)] 
            curr = 0
            while ordered_set:  # the while loop runs O(k) times
                if len(stks)-curr in freq_to_nodes:  # fill the deterministic elements into the remaining subsets
                    for x in freq_to_nodes[len(stks)-curr].iterkeys():  # total time = O(n)
                        for i in xrange(curr, len(stks)):
                            stks[i].append(x)
                        count.pop(x)
                        ordered_set.remove(x)
                    freq_to_nodes.pop(len(stks)-curr)
                # greedily fill the contiguous ordered elements into the first vacant subset until it is full,
                # otherwise, the result sum would get larger => in fact, this is wrong
                to_remove = []
                direction = (lambda x:x) if not is_reversed else reversed
                for x in direction(ordered_set):
                    stks[curr].append(x)
                    freq_to_nodes[count[x]].pop(x)
                    if not freq_to_nodes[count[x]]:
                        freq_to_nodes.pop(count[x])
                    count[x] -= 1  # total time = O(n)
                    if not count[x]:
                        count.pop(x)
                        to_remove.append(x)
                    else:
                        freq_to_nodes[count[x]][x] = count[x]
                    if len(stks[curr]) == len(nums)//k:
                        curr += 1
                        break
                for x in to_remove:
                    ordered_set.remove(x)  # total time = O(nlogn)
            return sum([max(stk)-min(stk) for stk in stks])

        return min(greedy(nums, k, False), greedy(nums, k, True))  # two possible minimas


# Time:  O(nlogn)
# Space: O(n)
import collections
from random import randint, seed


# Template modified from:
# https://github.com/kamyu104/LeetCode-Solutions/blob/master/Python/design-skiplist.py
class SkipNode(object):
    def __init__(self, level=0, val=None):
        self.val = val
        self.nexts = [None]*level
        self.prevs = [None]*level

class SkipList(object):
    P_NUMERATOR, P_DENOMINATOR = 1, 2  # P = 1/4 in redis implementation
    MAX_LEVEL = 32  # enough for 2^32 elements

    def __init__(self, end=float("inf"), can_duplicated=False, cmp=lambda x, y: x < y):
        seed(0)
        self.__head = SkipNode()
        self.__len = 0
        self.__can_duplicated = can_duplicated
        self.__cmp = cmp
        self.add(end)
        self.__end = self.find(end)

    def begin(self):
        return self.__head.nexts[0]
    
    def end(self):
        return self.__end

    def lower_bound(self, target):
        return self.__lower_bound(target, self.__find_prev_nodes(target))

    def find(self, target):
        return self.__find(target, self.__find_prev_nodes(target))
        
    def add(self, val):
        if not self.__can_duplicated and self.find(val):
            return self.find(val), False
        node = SkipNode(self.__random_level(), val)
        if len(self.__head.nexts) < len(node.nexts): 
            self.__head.nexts.extend([None]*(len(node.nexts)-len(self.__head.nexts)))
        prevs = self.__find_prev_nodes(val)
        for i in xrange(len(node.nexts)):
            node.nexts[i] = prevs[i].nexts[i]
            if prevs[i].nexts[i]:
                prevs[i].nexts[i].prevs[i] = node
            prevs[i].nexts[i] = node
            node.prevs[i] = prevs[i]
        self.__len += 1
        return node if self.__can_duplicated else (node, True)

    def remove(self, it):
        prevs = it.prevs
        curr = self.__find(it.val, prevs)
        if not curr:
            return self.__end
        self.__len -= 1   
        for i in reversed(xrange(len(curr.nexts))):
            prevs[i].nexts[i] = curr.nexts[i]
            if curr.nexts[i]:
                curr.nexts[i].prevs[i] = prevs[i]
            if not self.__head.nexts[i]:
                self.__head.nexts.pop()
        return curr.nexts[0]
    
    def __lower_bound(self, val, prevs):
        if prevs:
            candidate = prevs[0].nexts[0]
            if candidate:
                return candidate
        return None

    def __find(self, val, prevs):
        candidate = self.__lower_bound(val, prevs)
        if candidate and candidate.val == val:
            return candidate
        return None

    def __find_prev_nodes(self, val):
        prevs = [None]*len(self.__head.nexts)
        curr = self.__head
        for i in reversed(xrange(len(self.__head.nexts))):
            while curr.nexts[i] and self.__cmp(curr.nexts[i].val, val):
                curr = curr.nexts[i]
            prevs[i] = curr
        return prevs

    def __random_level(self):
        level = 1
        while randint(1, SkipList.P_DENOMINATOR) <= SkipList.P_NUMERATOR and \
              level < SkipList.MAX_LEVEL:
            level += 1
        return level
    
    def __iter__(self):
        it = self.begin()
        while it != self.end():
            yield it.val
            it = it.nexts[0]

    def __len__(self):
        return self.__len-1  # excluding end node

    def __str__(self):
        result = []
        for i in reversed(xrange(len(self.__head.nexts))):
            result.append([])
            curr = self.__head.nexts[i]
            while curr:
                result[-1].append(str(curr.val))
                curr = curr.nexts[i]
        return "\n".join(map(lambda x: "->".join(x), result))

# wrong with greedy solution
# nums = [15, 9, 7, 10, 15, 14, 12, 2, 10, 8, 10, 13, 4, 11, 2]
# k = 5
# greedy  => [[2, 4, 7], [2, 8, 9], [10, 11, 12], [10, 13, 15], [10, 14, 15]] => 24
# correct => [[2, 4, 7], [2, 8, 10], [9, 10, 11], [10, 12, 15], [13, 14, 15]] => 22
# optimized from Solution_Wrong_Greedy, using SkipList
class Solution_Wrong_Greedy_SkipList(object):
    def minimumIncompatibility(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def greedy(nums, k, is_reversed):
            count = collections.Counter(nums)
            if max(count.itervalues()) > k:
                return -1
            ordered_set = SkipList() if not is_reversed else SkipList(end=float("-inf"), cmp=lambda x, y: x > y)
            freq_to_nodes = collections.defaultdict(collections.OrderedDict)
            for x in sorted(count.keys(), reverse=is_reversed):
                ordered_set.add(x)
                freq_to_nodes[count[x]][x] = count[x]
            stks = [[] for _ in xrange(k)] 
            curr = 0
            while ordered_set:  # the while loop runs O(k) times
                if len(stks)-curr in freq_to_nodes:  # fill the deterministic elements into the remaining subsets
                    for x in freq_to_nodes[len(stks)-curr].iterkeys():  # total time = O(n)
                        for i in xrange(curr, len(stks)):
                            stks[i].append(x)
                        count.pop(x)
                        ordered_set.remove(ordered_set.find(x))
                    freq_to_nodes.pop(len(stks)-curr)
                # greedily fill the contiguous ordered elements into the first vacant subset until it is full,
                # otherwise, the result sum would get larger => in fact, this is wrong
                it = ordered_set.begin()
                while it != ordered_set.end():
                    x = it.val
                    stks[curr].append(x)
                    freq_to_nodes[count[x]].pop(x)
                    if not freq_to_nodes[count[x]]:
                        freq_to_nodes.pop(count[x])
                    count[x] -= 1  # total time = O(n)
                    if not count[x]:
                        count.pop(x)
                        it = ordered_set.remove(it)  # total time = O(nlogn)
                    else:
                        freq_to_nodes[count[x]][x] = count[x]
                        it = it.nexts[0]
                    if len(stks[curr]) == len(nums)//k:
                        curr += 1
                        break
            return sum([max(stk)-min(stk) for stk in stks])

        return min(greedy(nums, k, False), greedy(nums, k, True))  # two possible minimas


# Time:  O(nlogn + k * n), could be improved to O(nlogn) by skiplist or orderedlist
# Space: O(n)
import collections
# wrong with greedy solution
# nums = [15, 9, 7, 10, 15, 14, 12, 2, 10, 8, 10, 13, 4, 11, 2]
# k = 5
# greedy  => [[2, 4, 7], [2, 8, 9], [10, 11, 12], [10, 13, 15], [10, 14, 15]] => 24
# correct => [[2, 4, 7], [2, 8, 10], [9, 10, 11], [10, 12, 15], [13, 14, 15]] => 22
class Solution_Wrong_Greedy(object):
    def minimumIncompatibility(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def greedy(nums, k, is_reversed):
            count = collections.Counter(nums)
            if max(count.itervalues()) > k:
                return -1
            sorted_keys = sorted(count.keys(), reverse=is_reversed)
            stks = [[] for _ in xrange(k)] 
            curr, remain = 0, len(nums)
            while remain:  # the while loop runs O(k) times, and the inner loops runs O(n) times
                for x in sorted_keys:  # fill the deterministic elements into the remaining subsets
                    if count[x] != len(stks)-curr:
                        continue
                    for i in xrange(curr, len(stks)):
                        stks[i].append(x)
                    remain -= count[x]
                    count[x] = 0
                # greedily fill the contiguous ordered elements into the first vacant subset until it is full,
                # otherwise, the result sum would get larger => in fact, this is wrong
                for x in sorted_keys:
                    if not count[x]:
                        continue
                    stks[curr].append(x)
                    remain -= 1
                    count[x] -= 1
                    if len(stks[curr]) == len(nums)//k:
                        curr += 1
                        break
            return sum([max(stk)-min(stk) for stk in stks])

        return min(greedy(nums, k, False), greedy(nums, k, True))  # two possible minimas

