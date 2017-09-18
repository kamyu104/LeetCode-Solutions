# Time:  O(n), n is the length of key
# Space: O(t), t is the number of nodes in trie

# Implement a MapSum class with insert, and sum methods.
#
# For the method insert, you'll be given a pair of (string, integer).
# The string represents the key and the integer represents the value.
# If the key already existed, then the original key-value pair will be overridden to the new one.
#
# For the method sum, you'll be given a string representing the prefix,
# and you need to return the sum of all the pairs' value whose key starts with the prefix.
#
# Example 1:
# Input: insert("apple", 3), Output: Null
# Input: sum("ap"), Output: 3
# Input: insert("app", 2), Output: Null
# Input: sum("ap"), Output: 5

class MapSum(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        _trie = lambda: collections.defaultdict(_trie)
        self.__root = _trie()

    
    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: void
        """
        # Time: O(n)
        curr = self.__root
        for c in key:
            curr = curr[c]
        delta = val
        if "_end" in curr:
            delta -= curr["_end"]
        
        curr = self.__root
        for c in key:
            curr = curr[c]
            if "_count" in curr:
                curr["_count"] += delta
            else:
                curr["_count"] = delta
        curr["_end"] = val


    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        # Time: O(n)
        curr = self.__root
        for c in prefix:
            if c not in curr:
                return 0
            curr = curr[c]
        return curr["_count"]


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
