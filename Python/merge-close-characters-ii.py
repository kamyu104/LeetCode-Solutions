# Time:  O(n)
# Space: O(n)

# greedy, hash table
class Solution(object):
    def mergeCharacters(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        lookup = [-1]*26
        result = []
        for x in s:
            c = ord(x)-ord('a')
            if not (lookup[c] == -1 or len(result)-lookup[c] > k):
                continue
            lookup[c] = len(result)
            result.append(x)
        return "".join(result)
