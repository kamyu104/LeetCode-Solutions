# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def answerString(self, word, numFriends):
        """
        :type word: str
        :type numFriends: int
        :rtype: str
        """
        if numFriends == 1:
            return word
        idx, l = 0, 1
        for i in xrange(1, len(word)):
            if word[i] == word[idx+(l-1)]:
                l += 1
            elif word[i] < word[idx+(l-1)]:
                l = 1
            elif word[i] > word[idx+(l-1)]:
                if word[i-(l-1)] >= word[i]:
                    idx = i-(l-1)
                else:
                    idx = i
                l = 1    
        return word[idx:len(word)-max((numFriends-1)-idx, 0)]
