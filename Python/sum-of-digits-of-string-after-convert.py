# Time:  O(n + logn + log(logn) + ...) = O(n)
# Space: O(1)

class Solution(object):
    def getLucky(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        total = reduce(lambda total, x: total+sum(divmod((ord(x)-ord('a')+1), 10)), s, 0)
        while k > 1 and total > 9:
            new_total = 0
            while total:
                total, x = divmod(total, 10)
                new_total += x
            total = new_total
            k -= 1
        return total
