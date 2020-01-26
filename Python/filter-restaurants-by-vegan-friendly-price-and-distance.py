# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def filterRestaurants(self, restaurants, veganFriendly, maxPrice, maxDistance):
        """
        :type restaurants: List[List[int]]
        :type veganFriendly: int
        :type maxPrice: int
        :type maxDistance: int
        :rtype: List[int]
        """
        restaurants.sort(key=lambda (i, r, v, p, d): (-r, -i))
        return [i for i, r, v, p, d in restaurants if v >= veganFriendly and p <= maxPrice and d <= maxDistance]
