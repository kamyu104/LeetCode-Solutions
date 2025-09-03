# Time:  O(n)
# Space: O(1)

# math
class Solution(object):
    def minOperations(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        zero = s.count('0')
        if len(s) == k:
            return 0 if zero == 0 else 1 if zero == len(s) else -1
        result = float("inf")
        if (k&1) == (zero&1):
            i = max(ceil_divide(zero, k), ceil_divide(len(s)-zero, len(s)-k))
            if (i&1) == 0:
                i += 1
            result = min(result, i)
        if (zero&1) == 0:
            i = max(ceil_divide(zero, k), ceil_divide(zero, len(s)-k))
            if (i&1) == 1:
                i += 1
            result = min(result, i)
        return result if result != float("inf") else -1


# Time:  O(n)
# Space: O(1)
# math
class Solution2(object):
    def minOperations(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        zero = s.count('0')
        if len(s) == k:
            return 0 if zero == 0 else 1 if zero == len(s) else -1
        result = float("inf")
        i = max(ceil_divide(zero, k), ceil_divide(len(s)-zero, len(s)-k))
        if (i&1) == 0:
            i += 1
        if ((i*k-zero)&1) == 0:  # (k&1) == (zero&1)
            result = min(result, i)
        i = max(ceil_divide(zero, k), ceil_divide(zero, len(s)-k))
        if (i&1) == 1:
            i += 1
        if ((i*k-zero)&1) == 0:  # (zero&1) == 0
            result = min(result, i)
        return result if result != float("inf") else -1


# Time:  O(n)
# Space: O(1)
# math
class Solution3(object):
    def minOperations(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        zero = s.count('0')
        for i in xrange(len(s)+1):
            if (i*k-zero)&1:
                continue
            if i&1:
                if zero <= i*k <= zero*i+(len(s)-zero)*(i-1):
                    return i
            else:
                if zero <= i*k <= zero*(i-1)+(len(s)-zero)*i:
                    return i
        return -1
