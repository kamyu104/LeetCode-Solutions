# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def numberOfChild(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        q, r = divmod(k, n-1)
        return r if q&1 == 0 else (n-1)-r


# Time:  O(1)
# Space: O(1)
# math
class Solution2(object):
    def numberOfChild(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        r = k%(2*(n-1))
        return r if r <= n-1 else (n-1)-(r-(n-1))
