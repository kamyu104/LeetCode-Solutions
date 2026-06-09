# Time:  O(n * 2^n)
# Space: O(n)

# backtracking
class Solution(object):
    def generateValidStrings(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[str]
        """
        def backtracking(total):
            if len(curr) == n:
                result.append("".join(curr))
                return
            curr.append('0')
            backtracking(total)
            curr.pop()
            if (not curr or curr[-1] == '0') and total+len(curr) <= k:
                curr.append('1')
                backtracking(total+(len(curr)-1))
                curr.pop()

        result, curr = [], []
        backtracking(0)
        return result


# Time:  O(n * 2^n)
# Space: O(n)
# bitmasks
class Solution2(object):
    def generateValidStrings(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[str]
        """
        return ["".join('1' if mask&(1<<i) else '0' for i in xrange(n)) for mask in xrange(1<<n) if mask&(mask>>1) == 0 and sum(i for i in xrange(n) if mask&(1<<i)) <= k]
