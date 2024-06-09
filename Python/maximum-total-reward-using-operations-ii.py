# Time:  O(nlogn + r^2), r = max(rewardValues)
# Space: O(r)

# sort, dp, bitset
class Solution(object):
    def maxTotalReward(self, rewardValues):
        """
        :type rewardValues: List[int]
        :rtype: int
        """
        mx = max(rewardValues)
        dp = 1
        mask = (1<<mx)-1
        for v in sorted(set(rewardValues)):
            x = dp&((1<<v)-1)
            dp |= (x<<v)&mask
        return mx+(dp.bit_length()-1)


# Time:  O(nlogn + r^2), r = max(rewardValues)
# Space: O(r)
# sort, dp, bitset
class Solution2(object):
    def maxTotalReward(self, rewardValues):
        """
        :type rewardValues: List[int]
        :rtype: int
        """
        dp = 1
        for v in sorted(set(rewardValues)):
            x = dp&((1<<v)-1)
            dp |= x<<v
        return dp.bit_length()-1
