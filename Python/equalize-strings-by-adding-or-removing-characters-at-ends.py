# Time:  O((n + m) * log(min(n, m)))
# Space: O(min(n, m))

# binary search, rolling hash
class Solution(object):
    def minOperations(self, initial, target):
        """
        :type initial: str
        :type target: str
        :rtype: int
        """
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check( mid):
                    right = mid-1
                else:
                    left = mid+1
            return right
        
        def rolling_hash(s, l, lookup, check):
            MOD, P = 10**9+7, 113
            h = 0
            pw = pow(P, l-1, MOD)
            for i in xrange(len(s)):
                h = (h*P+(ord(s[i])-ord('a')))%MOD
                if i < l-1:
                    continue
                if not check:
                    lookup.add(h)
                elif h in lookup:
                    return True
                h = (h-(ord(s[i-(l-1)])-ord('a'))*pw)%MOD
            return False
                    
        def check(l):
            lookup = set()
            rolling_hash(target, l, lookup, False)
            return rolling_hash(initial, l, lookup, True)

        if len(initial) < len(target):
            initial, target = target, initial
        return len(initial)+len(target)-2*binary_search_right(1, min(len(initial), min(target)), check)


# Time:  O(n * m)
# Space: O(1)
# dp
class Solution2(object):
    def minOperations(self, initial, target):
        """
        :type initial: str
        :type target: str
        :rtype: int
        """
        result = 0
        for k in xrange(2):
            for i in xrange(k, len(initial)):
                curr = 0
                for j in xrange(min(len(initial)-i, len(target))):
                    curr = curr+1 if initial[i+j] == target[j] else 0
                    result = max(result, curr)
            initial, target = target, initial
        return len(initial)+len(target)-2*result


# Time:  O(n * m)
# Space: O(min(n, m))
# dp
class Solution3(object):
    def minOperations(self, initial, target):
        """
        :type initial: str
        :type target: str
        :rtype: int
        """
        if len(initial) < len(target):
            initial, target = target, initial
        result = 0
        dp = [0]*(len(target)+1)
        for i in xrange(len(initial)):
            for j in reversed(xrange(len(target))):
                dp[j+1] = dp[j]+1 if initial[i] == target[j] else 0
            result = max(result, max(dp))
        return len(initial)+len(target)-2*result
