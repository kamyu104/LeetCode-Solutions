# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def discountPrices(self, sentence, discount):
        """
        :type sentence: str
        :type discount: int
        :rtype: str
        """
        result = []
        i = 0
        while i < len(sentence):
            j = sentence.find(' ', i)
            if j == -1: j = len(sentence)
            if sentence[i] == '$' and j-(i+1) > 0 and all(sentence[k].isdigit() for k in xrange(i+1, j)):
                cnt = reduce(lambda x, y: x*10+int(y), (sentence[k] for k in xrange(i+1, j)), 0)
                result.append("${:d}.{:02d}".format(*divmod(cnt*(100-discount), 100)))
            else:
                for k in xrange(i, j):
                    result.append(sentence[k])
            if j != len(sentence):
                result.append(' ')
            i = j+1
        return "".join(result)

    
# Time:  O(n)
# Space: O(n)
# string
class Solution2(object):
    def discountPrices(self, sentence, discount):
        """
        :type sentence: str
        :type discount: int
        :rtype: str
        """
        def format(discount, x):
            return "${:d}.{:02d}".format(*divmod(int(x[1:])*(100-discount), 100)) if x[0] == '$' and x[1:].isdigit() else x

        return " ".join(format(discount, x) for x in sentence.split())
