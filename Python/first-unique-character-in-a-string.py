# Time:  O(n)
# Space: O(n)

# Given a string, find the first non-repeating character in it and
# return it's index. If it doesn't exist, return -1.
#
# Examples:
#
# s = "leetcode"
# return 0.
#
# s = "loveleetcode",
# return 2.
# Note: You may assume the string contain only lowercase letters.
import collections
import string


class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        lookup = collections.defaultdict(int)
        candidtates = set()
        for i, c in enumerate(s):
            if lookup[c]:
                candidtates.discard(lookup[c])
            else:
                lookup[c] = i + 1
                candidtates.add(i + 1)

        return min(candidtates) - 1 if candidtates else -1

    def firstUniqChar2(self, s):
        """
        :type s: str
        :rtype: int
        """
        return min([s.find(c) for c in string.ascii_lowercase if s.count(c) == 1] or [-1])

    def firstUniqChar3(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = collections.Counter(s)
        if cnt:
            for i in cnt.keys():
                if cnt[i] == 1:
                    return s.index(i)
            return -1
        else:
            return -1
