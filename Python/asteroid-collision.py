# Time:  O(n)
# Space: O(n)

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3

class Solution(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        result = []
        for asteroid in asteroids:
            while result and asteroid < 0 < result[-1]:
                if result[-1] < -asteroid:
                    result.pop()
                    continue
                elif result[-1] == -asteroid:
                    result.pop()
                break
            else:
                result.append(asteroid)
        return result

