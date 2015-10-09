# Time:  O(m * n * k), where m is string length, n is dictionary size, k is word length

# Space: O(n * k)
#
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

class Solution:
    # @param S, a string
    # @param L, a list of string
    # @return a list of integer
    def findSubstring(self, S, L):
        result, word_num, word_len = [], len(L), len(L[0])
        words = collections.defaultdict(int)
        for i in L:
            words[i] += 1

        for i in xrange(len(S) + 1 - word_len * word_num):
            cur, j = collections.defaultdict(int), 0
            while j < word_num:
                word = S[i + j * word_len:i + j * word_len + word_len]
                if word not in words: 
                    break
                cur[word] += 1
                if cur[word] > words[word]:
                    break
                j += 1
            if j == word_num:
                result.append(i)
                
        return result

if __name__ == "__main__":
    print Solution().findSubstring("barfoothefoobarman", ["foo", "bar"])
