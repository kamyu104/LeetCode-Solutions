# Time:  O(mlogm)
# Space: O(1)

# sort
class Solution(object):
    def sortTheStudents(self, score, k):
        """
        :type score: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        score.sort(key=lambda x: x[k], reverse=True)
        return score
