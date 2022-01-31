# Time:  O(n)
# Space: O(1)

# rolling hash
class Solution(object):
    def subStrHash(self, s, power, modulo, k, hashValue):
        """
        :type s: str
        :type power: int
        :type modulo: int
        :type k: int
        :type hashValue: int
        :rtype: str
        """
        h, idx = 0, -1
        pw = pow(power, k-1, modulo)
        for i in reversed(xrange(len(s))):
            if i+k < len(s):
                h = (h-(ord(s[i+k])-ord('a')+1)*pw)%modulo
            h = (h*power+(ord(s[i])-ord('a')+1))%modulo
            if h == hashValue:
                idx = i
        return s[idx:idx+k]
