# Time:  O(nlogn)
# Space: O(n)

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

    def __init__(self, end=[float("inf"), float("inf"), float("inf")], can_duplicated=True):
        seed(0)
        self.__head = SkipNode()
        self.__len = 0
        self.__can_duplicated = can_duplicated
        self.add(end)
        self.__end = self.find(end)

    def begin(self):
        return self.__head.nexts[0]
    
    def end(self):
        return self.__end

    def lower_bound(self, target, cmp=lambda x, y: x < y):
        return self.__lower_bound(target, self.__find_prev_nodes(target, cmp))

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

    def __find_prev_nodes(self, val, cmp=lambda x, y: x < y):
        prevs = [None]*len(self.__head.nexts)
        curr = self.__head
        for i in reversed(xrange(len(self.__head.nexts))):
            while curr.nexts[i] and cmp(curr.nexts[i].val, val):
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

# Template translated from:
# https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h
class LineContainer(object):
    def __init__(self):
        self.__skiplist = SkipList()

    def add(self, k, m):
        self.__skiplist.add([k, m, 0])
        z = self.__skiplist.find([k, m, 0])
        x = y = z
        z = z.nexts[0]
        while self.__intersect(y, z):
            z = self.__skiplist.remove(z)
        if x != self.__skiplist.begin():
            x = x.prevs[0]
            if self.__intersect(x, y):
                y = self.__skiplist.remove(y)
                self.__intersect(x, y)
        y = x
        while y != self.__skiplist.begin():
            x = x.prevs[0]
            if x.val[2] < y.val[2]:
                break
            y = self.__skiplist.remove(y)
            self.__intersect(x, y)
            y = x
    
    def query(self, x):
        it = self.__skiplist.lower_bound(x, cmp=lambda x, y: x[2] < y)
        return it.val[0]*x + it.val[1]

    def __intersect(self, x, y):
        if y == self.__skiplist.end():
            x.val[2] = float("inf")
            return False
        if x.val[0] == y.val[0]:
            x.val[2] = float("inf") if x.val[1] > y.val[1] else float("-inf")
        else:
            x.val[2] = (y.val[1]-x.val[1])//(x.val[0]-y.val[0])
        return x.val[2] >= y.val[2]

    def __iter__(self):
        return iter(self.__skiplist)

    def __len__(self):
        return len(self.__skiplist)

    def __str__(self):
        return str(self.__skiplist)


# prefix sum, dp, convex hull trick
class Solution(object):
    def minimumCost(self, nums, cost, k):
        """
        :type nums: List[int]
        :type cost: List[int]
        :type k: int
        :rtype: int
        """
        prefix1 = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix1[i+1] = prefix1[i]+nums[i]
        prefix2 = [0]*(len(cost)+1)
        for i in xrange(len(nums)):
            prefix2[i+1] = prefix2[i]+cost[i]
        dp = 0
        lc = LineContainer()
        for i in reversed(xrange(len(nums))):
            lc.add(prefix1[i+1], -(dp+prefix1[i+1]*prefix2[i+1]))
            dp = (-lc.query(prefix2[i]))+(k*(prefix2[-1]-prefix2[i]))
        return dp


# Time:  O(n^2)
# Space: O(n)
# dp
class Solution2(object):
    def minimumCost(self, nums, cost, k):
        """
        :type nums: List[int]
        :type cost: List[int]
        :type k: int
        :rtype: int
        """
        prefix1 = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix1[i+1] = prefix1[i]+nums[i]
        prefix2 = [0]*(len(cost)+1)
        for i in xrange(len(nums)):
            prefix2[i+1] = prefix2[i]+cost[i]
        dp = [float("inf")]*(len(nums)+1)
        dp[-1] = 0
        for i in reversed(xrange(len(nums))):
            for j in xrange(i, len(nums)):
                dp[i] = min(dp[i], prefix1[j+1]*(prefix2[j+1]-prefix2[i])+dp[j+1]+(k*(prefix2[-1]-prefix2[i])))
        return dp[0]
