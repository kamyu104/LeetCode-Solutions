# Time:  O(r), r = len(result)
# Space: O(r)

import collections


# simulation, deque
class Solution(object):
    def processStr(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = collections.deque()
        right = True
        for x in s:
            if x == '*':
                if not result:
                    continue
                if right:
                    result.pop()
                else:
                    result.popleft()
            elif x == '#':
                result.extend(result)
            elif x == '%':
                right = not right
            else:
                if right:
                    result.append(x)
                else:
                    result.appendleft(x)
        if not right:
            result.reverse()
        return "".join(result)
