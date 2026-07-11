# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minOperations(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        if s1 == "1" and s2 == "0":
            return -1
        result = 0
        changed = False
        for i in xrange(len(s1)):
            curr = '0' if changed else s1[i]
            changed = False
            if curr == s2[i]:
                continue
            if curr == '0':
                result += 1
            elif i+1 < len(s1):
                result += 1 if s1[i+1] == '1' else 2
                changed = True
            else:
                result += 2
        return result



# Time:  O(n)
# Space: O(n)
# greedy
class Solution2(object):
    def minOperations(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        if s1 == "1" and s2 == "0":
            return -1
        s1 = list(s1)
        result = 0
        for i in xrange(len(s1)):
            if s1[i] == s2[i]:
                continue
            if s1[i] == '0':
                result += 1
            elif i+1 < len(s1):
                result += 1 if s1[i+1] == '1' else 2
                s1[i+1] = '0'
            else:
                result += 2
        return result
