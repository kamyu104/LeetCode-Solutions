# Time:  O(n^2)
# Space: O(1)

# Definition for a category handler.
class CategoryHandler:
    def haveSameCategory(self, a, b):
        pass


# brute force
class Solution(object):
    def numberOfCategories(self, n, categoryHandler):
        """
        :type n: int
        :type categoryHandler: CategoryHandler
        :rtype: int
        """
        return sum(all(not categoryHandler.haveSameCategory(j, i) for j in xrange(i)) for i in xrange(n))
