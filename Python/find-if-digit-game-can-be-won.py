# Time:  O(n)
# Space: O(1)

# brute force, game theory
class Solution(object):
    def canAliceWin(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        total1 = total2 = 0
        for x in nums:
            if x < 10:
                total1 += x
            else:
                total2 += x
        return total1 != total2


# Time:  O(n)
# Space: O(1)
# brute force, game theory
class Solution2(object):
    def canAliceWin(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return sum(x for x in nums if x < 10) != sum(x for x in nums if x >= 10)
