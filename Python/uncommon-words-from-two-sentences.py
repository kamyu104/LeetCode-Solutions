# Time:  O(m + n)
# Space: O(m + n)

# We are given two sentences A and B. 
# (A sentence is a string of space separated words.
# Each word consists only of lowercase letters.)
#
# A word is uncommon if it appears exactly once in one of the sentences,
# and does not appear in the other sentence.
#
# Return a list of all uncommon words. 
#
# You may return the list in any order.
#
# Example 1:
#
# Input: A = "this apple is sweet", B = "this apple is sour"
# Output: ["sweet","sour"]
# Example 2:
#
# Input: A = "apple apple", B = "banana"
# Output: ["banana"]
#
# Note:
# - 0 <= A.length <= 200
# - 0 <= B.length <= 200
# - A and B both contain only spaces and lowercase letters.

import collections

    
class Solution(object):
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        count = collections.Counter(A.split())
        count += collections.Counter(B.split())
        return [word for word in count if count[word] == 1]
