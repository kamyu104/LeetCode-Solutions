# Time:  O(n + 26)
# Space: O(n + 26)

# greedy, hash table, stack
class Solution(object):
    def clearStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = list(s)
        lookup = [[] for _ in range(26)]
        for i, x in enumerate(s):
            if x != '*':
                lookup[ord(x)-ord('a')].append(i)
                continue
            for stk in lookup:
                if not stk:
                    continue
                result[stk.pop()] = '*'
                break
        return "".join(x for x in result if x != '*')
