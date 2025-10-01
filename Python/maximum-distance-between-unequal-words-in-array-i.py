# Time:  O(n * l)
# Space: O(1)

# array
class Solution(object):
    def maxDistance(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        if words[0] != words[-1]:
            return (len(words)-1)-0+1
        i = next((i for i in reversed(xrange(len(words))) if words[i] != words[0]), -1)
        j = next((j for j in xrange(len(words)) if words[j] != words[-1]), len(words))
        return max(i-0+1, (len(words)-1)-j+1)
