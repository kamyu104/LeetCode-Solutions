# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        def isDividingNumber(num):
            n = num
            while n > 0:
                if (n%10) == 0 or (num%(n%10)) != 0:
                    return False
                n /= 10
            return True
        
        result = []
        for num in xrange(left, right+1):
            if isDividingNumber(num):
                result.append(num)
        return result
