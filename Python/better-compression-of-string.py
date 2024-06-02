# Time:  O(n + 26)
# Space: O(26)

# freq table, counting sort
class Solution(object):
    def betterCompression(self, compressed):
        """
        :type compressed: str
        :rtype: str
        """
        cnt = [0]*26
        x, curr = -1, 0
        for i in xrange(len(compressed)):
            if not compressed[i].isdigit():
                x = ord(compressed[i])-ord('a')
                continue
            curr = curr*10+int(compressed[i])
            if i+1 == len(compressed) or not compressed[i+1].isdigit():
                cnt[x] += curr
                curr = 0
        return "".join("%s%s" % (chr(ord('a')+i), x) for i, x in enumerate(cnt) if x)
