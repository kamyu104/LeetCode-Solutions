# Time:  O(n * l^2)
# Space: O(n * l)

# Given a list of words, please write a program that returns
# all concatenated words in the given list of words.
#
# A concatenated word is defined as a string that is comprised entirely of
# at least two shorter words in the given array.
#
# Example:
# Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
#
# Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
#
# Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
#  "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
# "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
# Note:
# The number of elements of the given array will not exceed 10,000
# The length sum of elements in the given array will not exceed 600,000.
# All the input string will only include lower case letters.
# The returned elements order does not matter.

class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        lookup = set(words)
        result = []
        for word in words: 
            dp = [False] * (len(word)+1)
            dp[0] = True
            for i in xrange(len(word)):
                if not dp[i]:
                    continue
                
                for j in xrange(i+1, len(word)+1):
                    if j - i < len(word) and word[i:j] in lookup: 
                        dp[j] = True

                if dp[len(word)]:
                    result.append(word)
                    break

        return result
