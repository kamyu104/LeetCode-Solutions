# Time:  O(s + n * k), n is the number of the word_lens
# Space: O(k)

class Solution(object):
    def minimumCost(self, sentence, k):
        """
        :type sentence: str
        :type k: int
        :rtype: int
        """
        def lens(sentence):
            j = len(sentence)-1
            for i in reversed(xrange(-1, len(sentence))):
                if i == -1 or sentence[i] == ' ':
                    yield j-i
                    j = i-1

        word_lens, dp = [], []  # dp[i]: min cost of word_lens[-1-i:]
        t = -1
        for l in lens(sentence):
            word_lens.append(l)
            dp.append(float("inf"))
            t += l+1
            if t <= k:
                dp[-1] = 0
                continue
            total = l
            for j in reversed(xrange(len(dp)-1)):
                dp[-1] = min(dp[-1], dp[j] + (k-total)**2)
                total += (word_lens[j]+1)
                if total > k:
                    word_lens = word_lens[j:]  # minimize len(word_lens) s.t. sum(word_lens) > k
                    dp = dp[j:]
                    break
        return dp[-1] if dp else 0


# Time:  O(s + n * k), n is the number of the word_lens
# Space: O(n)
class Solution2(object):
    def minimumCost(self, sentence, k):
        """
        :type sentence: str
        :type k: int
        :rtype: int
        """
        word_lens = []
        j = 0
        for i in xrange(len(sentence)+1):
            if i != len(sentence) and sentence[i] != ' ':
                continue
            word_lens.append(i-j)
            j = i+1
        dp = [float("inf")]*(len(word_lens))  # dp[i]: min cost of word_lens[i:]
        i, total = len(word_lens)-1, -1
        while i >= 0 and total + (word_lens[i]+1) <= k:  # find max i s.t. the length of the last line > k
            total += (word_lens[i]+1)
            dp[i] = 0
            i -= 1
        for i in reversed(xrange(i+1)):
            total = word_lens[i]
            for j in xrange(i+1, len(dp)):
                dp[i] = min(dp[i], dp[j] + (k-total)**2)
                total += (word_lens[j]+1)
                if total > k:
                    break
        return dp[0]


# Time:  O(s + n * k), n is the number of the word_lens
# Space: O(n)
class Solution3(object):
    def minimumCost(self, sentence, k):
        """
        :type sentence: str
        :type k: int
        :rtype: int
        """
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
        i, total = len(word_lens)-1, -1
        while i >= 0 and total + (word_lens[i]+1) <= k:  # find max i s.t. the length of the last line > k
            total += (word_lens[i]+1)
            i -= 1
        return min(dp[j] for j in xrange(i+1, len(dp)))
