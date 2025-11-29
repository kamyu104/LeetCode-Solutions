# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def convertNumber(self, s):
        """
        :type s: str
        :rtype: str
        """
        LOOKUP = {"zero":'0', "one":'1', "two":'2', "three":'3', "four":'4', "five":'5', "six":'6', "seven":'7', "eight":'8', "nine":'9'}
        result = []
        i = 0
        while i < len(s):
            for l in xrange(3, 5+1):
                if s[i:i+l] in LOOKUP:
                    result.append(LOOKUP[s[i:i+l]])
                    break
            else:
                l = 1
            i += l
        return "".join(result)
