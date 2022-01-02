# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def asteroidsDestroyed(self, mass, asteroids):
        """
        :type mass: int
        :type asteroids: List[int]
        :rtype: bool
        """
        asteroids.sort()
        for x in asteroids:
            if x > mass:
                return False
            mass += min(x, asteroids[-1]-mass)
        return True
