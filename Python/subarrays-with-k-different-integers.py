# Time:  O(n)
# Space: O(k)

import collections


class Solution(object):
    def subarraysWithKDistinct(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        def atMostK(A, K):
            count = collections.defaultdict(int)
            result, left = 0, 0
            for right in xrange(len(A)):
                count[A[right]] += 1
                while len(count) > K:
                    count[A[left]] -= 1
                    if count[A[left]] == 0:
                        count.pop(A[left])
                    left += 1
                result += right-left+1
            return result
        
        return atMostK(A, K) - atMostK(A, K-1)


# Time:  O(n)
# Space: O(k)
class Window(object):
    def __init__(self):
        self.__count = collections.defaultdict(int)

    def add(self, x):
        self.__count[x] += 1

    def remove(self, x):
        self.__count[x] -= 1
        if self.__count[x] == 0:
            self.__count.pop(x)
            
    def size(self):
        return len(self.__count)


class Solution2(object):
    def subarraysWithKDistinct(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        window1, window2 = Window(), Window()
        result, left1, left2 = 0, 0, 0
        for i in A:
            window1.add(i)
            while window1.size() > K:
                window1.remove(A[left1])
                left1 += 1
            window2.add(i)
            while window2.size() >= K:
                window2.remove(A[left2])
                left2 += 1
            result += left2-left1
        return result
