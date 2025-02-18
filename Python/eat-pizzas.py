# Time:  O(nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def maxWeight(self, pizzas):
        """
        :type pizzas: List[int]
        :rtype: int
        """
        l = len(pizzas)//4
        pizzas.sort(reverse=True)
        return sum(pizzas[i] for i in xrange((l+1)//2))+sum(pizzas[i] for i in xrange((l+1)//2+1, ((l+1)//2+1)+(l//2)*2, 2))
