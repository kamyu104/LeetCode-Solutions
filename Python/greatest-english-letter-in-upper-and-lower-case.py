# Time:  O(n)
# Space: O(1)

# string, hash table
class Solution(object):
    def greatestLetter(self, s):
        """
        :type s: str
        :rtype: str
        """
        lookup = set(s)
        result = ""
        for c in s:
            if c.isupper() and lower(c) in s:
                if c > result:
                    result = c
        return result


# Time:  O(n)
# Space: O(1)
import itertools
import string


# string, hash table
class Solution2(object):
    def greatestLetter(self, s):
        """
        :type s: str
        :rtype: str
        """
        lookup = set(s)
        return next((C for c, C in itertools.izip(reversed(string.ascii_lowercase), reversed(string.ascii_uppercase)) if c in lookup and C in lookup), "")
   
