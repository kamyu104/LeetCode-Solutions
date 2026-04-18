# Time:  O(r + nlogn)
# Space: O(r + n)

# greedy
def precompute(r):
    pow2 = [1]*(r+1)
    for i in xrange(len(pow2)-1):
        pow2[i+1] = (pow2[i]*2)%MOD
    return pow2


MOD = 10**9+7
MAX_TOTAL = 2*10**5
POW2 = precompute(MAX_TOTAL)
class Solution(object):
    def maxValue(self, nums1, nums0):
        """
        :type nums1: List[int]
        :type nums0: List[int]
        :rtype: int
        """
        segments = [(nums1[i], nums0[i]) for i in xrange(len(nums1)) if nums0[i]]
        segments.sort(key=lambda x: (-x[0], x[1]))
        result = (POW2[sum(nums1[i] for i in xrange(len(nums0)) if nums0[i] == 0)]-1)%MOD
        for cnt1, cnt0 in segments:
            result = (result*POW2[cnt1+cnt0]%MOD+(((POW2[cnt1]-1)%MOD)*POW2[cnt0])%MOD)%MOD
        return result
