# Time:  O(m * n * k), where m is string length, n is dictionary size, k is word length
# Space: O(n * k)

# You are given a string, S, and a list of words, L, that are all of the same length. 
# Find all starting indices of substring(s) in S that is a concatenation of each word 
# in L exactly once and without any intervening characters.
# 
# For example, given:
# S: "barfoothefoobarman"
# L: ["foo", "bar"]
# 
# You should return the indices: [0,9].
# (order does not matter).
#

class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        result, word_num, word_len = [], len(words), len(words[0])
        lookup = collections.defaultdict(int)
        for i in words:
            lookup[i] += 1                                   # Space: O(n * k)

        for i in xrange(len(s) + 1 - word_len * word_num):   # Time: O(m)
            cur, j = collections.defaultdict(int), 0
            while j < word_num:                              # Time: O(n)
                word = s[i+j*word_len:i+j*word_len+word_len] # Time: O(k)
                if word not in lookup: 
                    break
                cur[word] += 1
                if cur[word] > lookup[word]:
                    break
                j += 1
            if j == word_num:
                result.append(i)
                
        return result


if __name__ == "__main__":
    print Solution().findSubstring("barfoothefoobarman", ["foo", "bar"])
