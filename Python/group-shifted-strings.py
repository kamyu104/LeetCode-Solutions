# Time:  O(nlogn)
# Space: O(n)

class Solution:
    # @param {string[]} strings
    # @return {string[][]}
    def groupStrings(self, strings):
        groups = {};
        for s in strings:  # Grouping.
            if self.hashStr(s) not in groups:
                groups[self.hashStr(s)] = [s]
            else:
                groups[self.hashStr(s)].append(s)

        result = []
        for key, val in groups.iteritems():
            result.append(sorted(val))
        
        return result

    def hashStr(self, s):
        base = ord(s[0])
        hashcode = ""
        for i in xrange(len(s)):
            if ord(s[i]) - base >= 0:
                hashcode += unichr(ord('a') + ord(s[i]) - base)
            else:
                hashcode += unichr(ord('a') + ord(s[i]) - base + 26)
        return hashcode
