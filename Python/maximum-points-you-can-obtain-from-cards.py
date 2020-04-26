# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maxScore(self, cardPoints, k):
        """
        :type cardPoints: List[int]
        :type k: int
        :rtype: int
        """
        result, total, curr, left = float("inf"), 0, 0, 0
        for right, point in enumerate(cardPoints):
            total += point
            curr += point
            if right-left+1 > len(cardPoints)-k:
                curr -= cardPoints[left]
                left += 1
            if right-left+1 == len(cardPoints)-k:
                result = min(result, curr)
        return total-result
