# Time:  O(logr) = O(1)
# Space: O(1)

# bitmasks
class Solution(object):
    def kthCharacter(self, k, operations):
        """
        :type k: int
        :type operations: List[int]
        :rtype: str
        """
        result = 0
        k -= 1
        for i in xrange(min(len(operations), k.bit_length())):
            if k&(1<<i):
                result = (result+operations[i])%26
        return chr(ord('a')+result)
