# Time:  O(n * 2^n)
# Space: O(n)

class Solution(object):
    def shoppingOffers(self, price, special, needs):
        """
        :type price: List[int]
        :type special: List[List[int]]
        :type needs: List[int]
        :rtype: int
        """
        def shoppingOffersHelper(price, special, needs, i):
            if i == len(special):
                return sum(map(lambda x, y: x*y, price, needs))
            result = shoppingOffersHelper(price, special, needs, i+1)
            for j in xrange(len(needs)):
                needs[j] -= special[i][j]
            if all(need >= 0 for need in needs):
                result = min(result, special[i][-1] + shoppingOffersHelper(price, special, needs, i))
            for j in xrange(len(needs)):
                needs[j] += special[i][j]
            return result

        return shoppingOffersHelper(price, special, needs, 0)

