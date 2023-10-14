# Time:  O(n)
# Space: O(n)

class Solution(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        result = []
        for x in asteroids:
            if x > 0:
                result.append(x)
                continue
            while result and 0 < result[-1] < -x:
                result.pop()
            if result and 0 < result[-1]:
                if result[-1] == -x:
                    result.pop()
                continue
            result.append(x)
        return result


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        result = []
        for x in asteroids:
            while result and x < 0 < result[-1]:
                if result[-1] < -x:
                    result.pop()
                    continue
                elif result[-1] == -x:
                    result.pop()
                break
            else:
                result.append(x)
        return result
