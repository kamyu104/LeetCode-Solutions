# Time:  O(n)
# Space: O(1)

class Solution(object):
    def findOcurrences(self, text, first, second):
        """
        :type text: str
        :type first: str
        :type second: str
        :rtype: List[str]
        """
        result = []
        first += ' '
        second += ' '
        third = []
        i, j, k = 0, 0, 0
        while k < len(text):
            c = text[k]
            k += 1
            if i != len(first):
                if c == first[i]:
                    i += 1
                else:
                    i = 0
                continue
            if j != len(second):
                if c == second[j]:
                    j += 1
                else:
                    k -= j+1
                    i, j = 0, 0
                continue
            if c != ' ':
                third.append(c)
                continue
            k -= len(second) + len(third) + 1
            i, j = 0, 0
            result.append("".join(third))
            third = []
        if third:
            result.append("".join(third))
        return result
