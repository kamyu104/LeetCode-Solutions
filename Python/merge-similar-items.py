# Time:  O((m + n) * log(m + n))
# Space: O(m + n)

# freq table, sort
class Solution(object):
    def mergeSimilarItems(self, items1, items2):
        """
        :type items1: List[List[int]]
        :type items2: List[List[int]]
        :rtype: List[List[int]]
        """
        return sorted((Counter(dict(items1))+Counter(dict(items2))).iteritems())
