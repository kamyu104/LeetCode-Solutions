# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def generateTag(self, caption):
        """
        :type caption: str
        :rtype: str
        """
        L = 100
        result = ['#']
        for i in xrange(len(caption)):
            if caption[i] == ' ':
                continue
            result.append(caption[i].upper() if i == 0 or caption[i-1] == ' ' else caption[i].lower())
            if len(result) == L:
                break
        if 1 < len(result):
            result[1] = result[1].lower()
        return "".join(result)


# Time:  O(n)
# Space: O(n)
# string
class Solution2(object):
    def generateTag(self, caption):
        """
        :type caption: str
        :rtype: str
        """
        L = 100
        return ('#'+"".join(x.lower() if i == 0 else x[0].upper()+x[1:].lower() for i, x in enumerate(caption.split())))[:L]
