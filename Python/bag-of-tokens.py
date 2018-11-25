# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def bagOfTokensScore(self, tokens, P):
        """
        :type tokens: List[int]
        :type P: int
        :rtype: int
        """
        tokens.sort()
        result, points = 0, 0
        left, right = 0, len(tokens)-1
        while left <= right:
            if P >= tokens[left]:
                P -= tokens[left]
                left += 1
                points += 1
                result = max(result, points)
            elif points > 0:
                points -= 1
                P += tokens[right]
                right -= 1
            else:
                break
        return result
