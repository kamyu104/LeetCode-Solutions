# Time:  O(n * l)
# Space: O(n)

class Solution(object):
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        def count(word):
            result = [0]*52
            for i, letter in enumerate(word):
                result[ord(letter)-ord('a') + 26*(i%2)] += 1
            return tuple(result)

        return len({count(word) for word in A})

