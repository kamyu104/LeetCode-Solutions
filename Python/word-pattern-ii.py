# Time:  O(n * C(n + c - 1, c - 1)), n is length of str, c is unique count of pattern,
#                                    there are C(n + c - 1, c - 1) possible splits of string,
#                                    and each one costs O(n) to check if it matches the word pattern.
# Space: O(n + c)

class Solution(object):
    def wordPatternMatch(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        w2p, p2w = {}, {}
        return self.match(pattern, str, 0, 0, w2p, p2w)


    def match(self, pattern, str, i, j, w2p, p2w):
        is_match = False
        if i == len(pattern) and j == len(str):
            is_match = True
        elif i < len(pattern) and j < len(str):
            p = pattern[i]
            if p in p2w:
                w = p2w[p]
                if w == str[j:j+len(w)]:  # Match pattern.
                    is_match = self.match(pattern, str, i + 1, j + len(w), w2p, p2w)
                # Else return false.
            else:
                for k in xrange(j, len(str)):
                    w = str[j:k+1]
                    if w not in w2p:
                        # Build mapping. Space: O(n + c)
                        w2p[w], p2w[p] = p, w;
                        is_match = self.match(pattern, str, i + 1, k + 1, w2p, p2w)
                        w2p.pop(w), p2w.pop(p);
                    if is_match:
                        break
                    # Else try longer word.
        return is_match

