# Time:  O(n)
# Space: O(1)

# Implement function ToLowerCase() that has a string parameter str,
# and returns the same string in lowercase.

class Solution(object):
    def toLowerCase(self, str):
        """
        :type str: str
        :rtype: str
        """
        return "".join([chr(ord('a')+ord(c)-ord('A')) 
                        if 'A' <= c <= 'Z' else c for c in str])
