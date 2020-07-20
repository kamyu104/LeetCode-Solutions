# Time:  O(nlogm), m is the max value of arr
# Space: O(logm)

class BitCount(object):
    def __init__(self, n):
        self.__l = 0
        self.__n = n
        self.__count = [0]*n
    
    def __iadd__(self, num):
        self.__l += 1
        base = 1
        for i in xrange(self.__n):
            if num&base:
                self.__count[i] += 1
            base <<= 1
        return self

    def __isub__(self, num):
        self.__l -= 1
        base = 1
        for i in xrange(self.__n):
            if num&base:
                self.__count[i] -= 1
            base <<= 1
        return self
            
    def bit_and(self):
        num, base = 0, 1
        for i in xrange(self.__n):
            if self.__count[i] == self.__l:
                num |= base
            base <<= 1
        return num


class Solution(object):
    def closestToTarget(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        count = BitCount(max(arr).bit_length())
        result, left = float("inf"), 0
        for right in xrange(len(arr)):
            count += arr[right]
            while left <= right:
                f = count.bit_and()
                result = min(result, abs(f-target))
                if f >= target:
                    break
                count -= arr[left]
                left += 1
        return result
                    
  
# Time:  O(nlogm), m is the max value of arr
# Space: O(logm)
class Solution2(object):
    def closestToTarget(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        result, dp = float("inf"), set()  # at most O(logm) dp states
        for x in arr:
            dp = {x}|{f&x for f in dp}
            for f in dp:
                result = min(result, abs(f-target))
        return result
