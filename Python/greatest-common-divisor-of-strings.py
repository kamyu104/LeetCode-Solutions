# Time:  O(m + n)
# Space: O(1)

class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        def check(s, common):
            i = 0
            for c in s:
                if c != common[i]:
                    return False
                i = (i+1)%len(common)
            return True
    
        def gcd(a, b):  # Time: O(log(min(a, b)))
            while b:
                a, b = b, a % b
            return a
        
        if not str1 or not str2:
            return ""
        c = gcd(len(str1), len(str2))
        result = str1[:c]
        return result if check(str1, result) and check(str2, result) else ""
