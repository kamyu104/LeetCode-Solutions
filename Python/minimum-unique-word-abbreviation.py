# Time:  O(2^n)
# Space: O(n)

class Solution(object):
    def minAbbreviation(self, target, dictionary):
        """
        :type target: str
        :type dictionary: List[str]
        :rtype: str
        """
        def bits_len(target, bits):
            return sum((bits >> i) & 3 == 0 for i in xrange(len(target)-1))

        diffs = set()
        for word in dictionary:
            if len(word) != len(target):
                continue
            diffs.add(sum(2**i for i, c in enumerate(word) if target[i] != c))

        if not diffs:
            return str(len(target))

        bits = 2**len(target) - 1
        for i in xrange(2**len(target)):
            if all(d & i for d in diffs) and bits_len(target, i) > bits_len(target, bits):
                bits = i

        abbr = []
        pre = 0
        for i in xrange(len(target)):
            if bits & 1:
                if i - pre > 0:
                    abbr.append(str(i - pre))
                pre = i + 1
                abbr.append(str(target[i]))
            elif i == len(target) - 1:
                abbr.append(str(i - pre + 1))
            bits >>= 1

        return "".join(abbr)
