# Time:  O(n + 26)
# Space: O(26)

# simulation, hash table
class Solution(object):
    def mergeCharacters(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        result = []
        lookup = [-1]*26
        for x in s:
            if lookup[ord(x)-ord('a')] != -1 and len(result)-lookup[ord(x)-ord('a')] <= k:
                continue
            lookup[ord(x)-ord('a')] = len(result)
            result.append(x)
        return "".join(result)


# Time:  O(n + 26)
# Space: O(26)
# simulation, freq table, two pointers
class Solution2(object):
    def mergeCharacters(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        result = []
        cnt = [0]*26
        for x in s:
            if cnt[ord(x)-ord('a')]:
                continue
            cnt[ord(x)-ord('a')] += 1
            result.append(x)
            if len(result) >= k+1:
                cnt[ord(result[-(k+1)])-ord('a')] -= 1
        return "".join(result)
