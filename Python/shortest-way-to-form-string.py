# Time:  O(m + n), m is the length of source
#                , n is the length of target
# Space: O(m)

# greedy solution
class Solution(object):
    def shortestWay(self, source, target):
        """
        :type source: str
        :type target: str
        :rtype: int
        """
        lookup = [[None for _ in xrange(26)] for _ in xrange(len(source)+1)]
        find_char_next_pos = [None]*26
        for i in reversed(xrange(len(source))):
            find_char_next_pos[ord(source[i])-ord('a')] = i+1
            lookup[i] = list(find_char_next_pos)

        result, start = 1, 0
        for c in target:
            start = lookup[start][ord(c)-ord('a')]
            if start != None:
                continue
            result += 1
            start = lookup[0][ord(c)-ord('a')]
            if start == None:
                return -1
        return result
