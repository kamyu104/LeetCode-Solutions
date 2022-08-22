# Time:  O(n)
# Space: O(n)

# line sweep
class Solution(object):
    def shiftingLetters(self, s, shifts):
        """
        :type s: str
        :type shifts: List[List[int]]
        :rtype: str
        """
        events = [0]*(len(s)+1)
        for b, e, d in shifts:
            events[b] += 1 if d else -1
            events[e+1] -= 1 if d else -1
        result = []
        curr = 0
        for i in xrange(len(s)):
            curr += events[i]
            result.append(chr(ord('a')+(ord(s[i])-ord('a')+curr)%26))
        return "".join(result)
