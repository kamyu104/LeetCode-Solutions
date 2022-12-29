# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def closetTarget(self, words, target, startIndex):
        """
        :type words: List[str]
        :type target: str
        :type startIndex: int
        :rtype: int
        """
        INF = float("inf")
        result = INF
        for i, w in enumerate(words):
            if w == target:
                result = min(result, (i-startIndex)%len(words), (startIndex-i)%len(words))
        return result if result != INF else -1
