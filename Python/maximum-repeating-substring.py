# Time:  O(n)
# Space: O(m)

# kmp solution
class Solution(object):
    def maxRepeating(self, sequence, word):
        """
        :type sequence: str
        :type word: str
        :rtype: int
        """
        def getPrefix(pattern):
            prefix = [-1] * len(pattern)
            j = -1
            for i in xrange(1, len(pattern)):
                while j > -1 and pattern[j + 1] != pattern[i]:
                    j = prefix[j]
                if pattern[j+1] == pattern[i]:
                    j += 1
                prefix[i] = j
            return prefix

        if len(sequence) < len(word):
            return 0

        prefix = getPrefix(word)
        result, count, j, prev = 0, 0, -1, -1
        for i in xrange(len(sequence)):
            while j > -1 and word[j+1] != sequence[i]:
                j = prefix[j]
            if word[j+1] == sequence[i]:
                j += 1
            if j == len(word)-1:     
                count = count+1 if i-prev == len(word) else 1
                result = max(result, count)
                j, prev = -1, i
        return result
