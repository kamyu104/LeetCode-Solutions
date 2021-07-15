# Time:  O(n)
# Space: O(1)

class Solution(object):
    def isDecomposable(self, s):
        """
        :type s: str
        :rtype: bool
        """
        found, i = False, 0
        while i < len(s):
            l = 1
            for j in xrange(i+1, min(i+3, len(s))):
                if s[j] != s[i]:
                    break
                l += 1
            if l < 2:
                return False
            if l == 2:
                if found:
                    return False
                found = True
            i += l  
        return found
        

# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def isDecomposable(self, s):
        """
        :type s: str
        :rtype: bool
        """
        found, l = False, 0
        for i, c in enumerate(s):
            if not l or c != s[i-1]:
                if l:
                    return False
                l = 1
                continue
            l += 1
            if l == 2:
                if i == len(s)-1 or s[i] != s[i+1]:
                    if found:
                        return False
                    found, l = True, 0
            elif l == 3:
                 l =  0
        return found
