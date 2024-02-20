# Time:  O((n + m) * l)
# Space: O(t)

# trie
class Solution(object):
    def longestCommonPrefix(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        for x in arr1:
            reduce(dict.__getitem__, str(x), trie)
        result = 0
        for x in arr2:
            curr = trie
            for i, c in enumerate(str(x)):
                if c not in curr:
                    break
                curr = curr[c]
            else:
                i += 1
            result = max(result, i)
        return result


# Time:  O((n + m) * l)
# Space: O(n)
# hash table
class Solution2(object):
    def longestCommonPrefix(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        lookup = {0}
        for x in arr1:
            while x not in lookup:
                lookup.add(x)
                x //= 10
        result = 0
        for x in arr2:
            l = len(str(x))
            while x not in lookup:
                x //= 10
                l -= 1
            result = max(result, l)
        return result
