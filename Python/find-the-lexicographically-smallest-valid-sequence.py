# Time:  O(n + m)
# Space: O(m)

# hash table, greedy
class Solution(object):
    def validSequence(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: List[int]
        """
        j = len(word2)-1
        lookup = [-1]*len(word2)
        for i in reversed(xrange(len(word1))):
            if word1[i] != word2[j]:
                continue
            lookup[j] = i
            j -= 1
            if j == -1:
                break
        result = []
        cnt = 0
        for i in xrange(len(word1)):
            if not (word1[i] == word2[len(result)] or
                    (cnt == 0 and (len(result)+1 == len(word2) or i < lookup[len(result)+1]))):
                continue
            if word1[i] != word2[len(result)]:
                cnt += 1
            result.append(i)
            if len(result) == len(word2):
                return result
        return []
