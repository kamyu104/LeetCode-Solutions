# Time:  O(n), n is the length of sequence
# Space: O(m), m is the length of word

# optimized kmp solution
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
            if j+1 == len(word):     
                count = count+1 if i-prev == len(word) else 1
                result = max(result, count)
                j, prev = -1, i
        return result


# Time:  O(n), n is the length of sequence
# Space: O(n)
# kmp solution
class Solution2(object):
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

        new_word = word*(len(sequence)//len(word))
        prefix = getPrefix(new_word)
        result, j = 0, -1
        for i in xrange(len(sequence)):
            while j > -1 and new_word[j+1] != sequence[i]:
                j = prefix[j]
            if new_word[j+1] == sequence[i]:
                j += 1
            result = max(result, j+1)
            if j+1 == len(new_word):     
                break
        return result//len(word)
