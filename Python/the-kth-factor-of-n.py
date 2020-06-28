# Time:  O(sqrt(n))
# Space: O(1)

class Solution(object):
    def kthFactor(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        def kth_factor(n, k=0):
            mid = None
            i = 1
            while i*i <= n:
                if not n%i:
                    mid = i
                    k -= 1
                    if not k:
                        break
                i += 1
            return mid, -k
    
        mid, count = kth_factor(n)
        total = 2*count-(mid*mid == n)
        if k > total:
            return -1
        result = kth_factor(n, k if k <= count else total-(k-1))[0]
        return result if k <= count else n//result


# Time:  O(sqrt(n))
# Space: O(sqrt(n))
class Solution2(object):
    def kthFactor(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        result = []
        i = 1
        while i*i <= n:
            if not n%i:
                if i*i != n:
                    result.append(i)
                k -= 1
                if not k:
                    return i
            i += 1
        return -1 if k > len(result) else n//result[-k]
