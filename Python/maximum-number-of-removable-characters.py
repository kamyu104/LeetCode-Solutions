# Time:  O(rlogn)
# Space: O(r)

# if r = O(1), this is better
class Solution(object):
    def maximumRemovals(self, s, p, removable):
        """
        :type s: str
        :type p: str
        :type removable: List[int]
        :rtype: int
        """
        def check(s, p, removable, x):
            lookup = set(removable[i] for i in xrange(x))
            j = 0
            for i in xrange(len(s)):
                if i in lookup or s[i] != p[j]:
                    continue
                j += 1
                if j == len(p):
                    return True
            return False

        left, right = 0, len(removable)
        while left <= right:
            mid = left + (right-left)//2
            if not check(s, p, removable, mid):
                right = mid-1
            else:
                left = mid+1
        return right


# Time:  O(rlogn)
# Space: O(n)
# if r = O(n), this is better
class Solution2(object):
    def maximumRemovals(self, s, p, removable):
        """
        :type s: str
        :type p: str
        :type removable: List[int]
        :rtype: int
        """
        def check(s, p, lookup, x):
            j = 0
            for i in xrange(len(s)):
                if lookup[i] <= x or s[i] != p[j]:
                    continue
                j += 1
                if j == len(p):
                    return True
            return False

        lookup = [float("inf")]*len(s)
        for i, r in enumerate(removable):
            lookup[r] = i+1
        left, right = 0, len(removable)
        while left <= right:
            mid = left + (right-left)//2
            if not check(s, p, lookup, mid):
                right = mid-1
            else:
                left = mid+1
        return right
