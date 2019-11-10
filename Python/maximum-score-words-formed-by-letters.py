# Time:  O(n * 2^n)
# Space: O(n)

import collections


class Solution(object):
    def maxScoreWords(self, words, letters, score):
        """
        :type words: List[str]
        :type letters: List[str]
        :type score: List[int]
        :rtype: int
        """
        def backtracking(words, scores, word_counts, curr, curr_score, count, result):
            result[0] = max(result[0], curr_score) 
            for i in xrange(curr, len(words)):
                if any(count[c] < word_counts[i][c] for c in word_counts[i]):
                    continue
                backtracking(words, scores, word_counts, i+1,
                             curr_score+scores[i], count-word_counts[i],
                             result)

        result = [0]
        count = collections.Counter(letters)    
        word_counts = map(collections.Counter, words)
        scores = {i:sum(score[ord(c)-ord('a')] for c in words[i])
                  for i in xrange(len(words))}
        backtracking(words, scores, word_counts, 0, 0, count, result)
        return result[0]
