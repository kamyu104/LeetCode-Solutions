# Time:  O(nlogn)
# Space: O(n)

# sort
class Solution(object):
    def sortPeople(self, names, heights):
        """
        :type names: List[str]
        :type heights: List[int]
        :rtype: List[str]
        """
        order = range(len(names))
        order.sort(key=lambda x: heights[x], reverse=True)
        return [names[i] for i in order]
