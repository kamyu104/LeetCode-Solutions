# Time:  O(s + n * k), n is the number of the word_lens
# Space: O(n)

class Solution(object):
    def minimumCost(self, sentence, k):
        """
        :type sentence: str
        :type k: int
        :rtype: int
        """
        if len(sentence) <= k:
            return 0

        word_lens = []
        j = 0
        for i in xrange(len(sentence)+1):
            if i != len(sentence) and sentence[i] != ' ':
                continue
            word_lens.append(i-j)
            j = i+1
        dp = [float("inf")]*(len(word_lens))  # dp[i]: min cost of sentence[i:]
        i, total = len(word_lens)-1, -1
        while total + (word_lens[i]+1) <= k:  # find max i s.t. the length of the last line > k
            total += (word_lens[i]+1)
            dp[i] = 0
            i -= 1
        for j in reversed(xrange(i+1)):
            total = word_lens[j]
            for l in xrange(j+1, len(dp)):
                dp[j] = min(dp[j], dp[l] + (k-total)**2)
                total += (word_lens[l]+1)
                if total > k:
                    break
        return dp[0]


# Time:  O(s + n * k), n is the number of the word_lens
# Space: O(n)
class Solution2(object):
    def minimumCost(self, sentence, k):
        """
        :type sentence: str
        :type k: int
        :rtype: int
        """
        if len(sentence) <= k:
            return 0

        word_lens = []
        j = 0
        for i in xrange(len(sentence)+1):
            if i != len(sentence) and sentence[i] != ' ':
                continue
            word_lens.append(i-j)
            j = i+1
        dp = [float("inf")]*(1+(len(word_lens)-1))  # dp[i]: min cost of the first i word_lens where i in [0, len(words)-1]
        dp[0] = 0
        for i in xrange(1, (len(word_lens)-1)+1):
            total = word_lens[i-1]
            for j in reversed(xrange(i)):
                dp[i] = min(dp[i], dp[j] + (k-total)**2)
                if j-1 < 0:
                    continue
                total += (word_lens[j-1]+1)
                if total > k:
                    break
        i, total = len(word_lens)-1, word_lens[-1]
        while total + (word_lens[i-1]+1) <= k:  # find min i s.t. the length of the last line <= k
            total += (word_lens[i-1]+1)
            i -= 1
        return min(dp[j] for j in xrange(i, len(dp)))
