# Time:  O(n)
# Space: O(1)

class Solution(object):
    def areSentencesSimilar(self, sentence1, sentence2):
        """
        :type sentence1: str
        :type sentence2: str
        :rtype: bool
        """
        if len(sentence1) > len(sentence2):
            sentence1, sentence2 = sentence2, sentence1
        count = 0
        for idx in (lambda x:x, lambda x:-1-x):
            for i in xrange(len(sentence1)+1):
                c1 = sentence1[idx(i)] if i != len(sentence1) else ' '
                c2 = sentence2[idx(i)] if i != len(sentence2) else ' '
                if c1 != c2:
                    break
                if c1 == ' ':
                    count += 1
        return count >= sentence1.count(' ')+1
