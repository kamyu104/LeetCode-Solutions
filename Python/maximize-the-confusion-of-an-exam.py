# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def maxConsecutiveAnswers(self, answerKey, k):
        """
        :type answerKey: str
        :type k: int
        :rtype: int
        """
        result = max_count = 0
        count = collections.Counter()
        for i in xrange(len(answerKey)):
            count[answerKey[i]] += 1
            max_count = max(max_count, count[answerKey[i]])
            if result-max_count >= k:
                count[answerKey[i-result]] -= 1
            else:
                result += 1
        return result
