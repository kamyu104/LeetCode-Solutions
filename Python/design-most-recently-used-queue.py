# Time:  ctor:  O(nlogn)
# Space: fetch: O(logn)

from sortedcontainers import SortedList


# balanced bst solution
class MRUQueue(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.__sl = SortedList((i-1, i) for i in xrange(1, n+1))  

    def fetch(self, k):
        """
        :type k: int
        :rtype: int
        """
        last, _ = self.__sl[-1]
        _, val = self.__sl.pop(k-1)
        self.__sl.add((last+1, val))
        return val


# Time:  ctor:  O(n + m), m is the max number of calls
# Space: fetch: O(log(n + m))
class BIT(object):  # 0-indexed.
    def __init__(self, n):
        MAX_CALLS = 2000
        self.__bit = [0]*(n+MAX_CALLS+1)  # Extra one for dummy node.
        for i in xrange(1, len(self.__bit)):
            self.__bit[i] = (1 if i-1 < n else 0) + self.__bit[i-1]
        for i in reversed(xrange(1, len(self.__bit))):
            last_i = i - (i & -i)
            self.__bit[i] -= self.__bit[last_i]

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

    def binary_lift(self, k):
        floor_log2_n = (len(self.__bit)-1).bit_length()-1
        pow_i = 2**floor_log2_n
        total = pos = 0  # 1-indexed
        for i in reversed(xrange(floor_log2_n+1)):  # O(logN)
            if pos+pow_i < len(self.__bit) and not (total+self.__bit[pos+pow_i] >= k):
                total += self.__bit[pos+pow_i]
                pos += pow_i
            pow_i >>= 1
        return (pos+1)-1  # 0-indexed


# fenwick / bit solution
class MRUQueue2(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.__bit = BIT(n)
        self.__lookup = {i:i+1 for i in xrange(n)}
        self.__curr = n
        
    def fetch(self, k):
        """
        :type k: int
        :rtype: int
        """
        pos = self.__bit.binary_lift(k)  
        val = self.__lookup.pop(pos)
        self.__bit.add(pos, -1)
        self.__bit.add(self.__curr, 1)
        self.__lookup[self.__curr] = val     
        self.__curr += 1
        return val


# Time:  ctor:  O(n)
# Space: fetch: O(sqrt(n))
import collections
import math


# sqrt decomposition solution
class MRUQueue3(object):

    def __init__(self, n):
        """
        :type n: int
        """
        self.__buckets = [collections.deque() for _ in xrange(int(math.ceil(n**0.5)))]
        for i in xrange(n):
            self.__buckets[i//len(self.__buckets)].append(i+1)

    def fetch(self, k):
        """
        :type k: int
        :rtype: int
        """
        k -= 1
        left, idx = divmod(k, len(self.__buckets))
        val = self.__buckets[left][idx]
        del self.__buckets[left][idx]
        self.__buckets[-1].append(val)
        for i in reversed(xrange(left, len(self.__buckets)-1)):
            x = self.__buckets[i+1].popleft()
            self.__buckets[i].append(x)
        return val
