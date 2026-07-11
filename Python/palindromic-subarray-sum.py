# Time:  O(n)
# Space: O(n)

# prefix sum, manacher's algorithm
class Solution(object):
    def getSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def manacher(s):
            ret = [-1]
            for x in s:
                ret.append(-2)
                ret.append(x)
            ret.append(-2)
            ret.append(-3)
            P = [0]*len(ret)
            C, R = 0, 0
            for i in xrange(1, len(ret)-1):
                i_mirror = 2*C-i
                if R > i:
                    P[i] = min(R-i, P[i_mirror])
                while ret[i+1+P[i]] == ret[i-1-P[i]]:
                    P[i] += 1
                if i+P[i] > R:
                    C, R = i, i+P[i]
            return P

        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        p = manacher(nums)
        return max(prefix[(i+p[i])//2]-prefix[(i-p[i])//2] for i in xrange(1, len(p)-1))
