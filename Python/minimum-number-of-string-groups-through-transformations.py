# Time:  O(n * l)
# Space: O(n * l)

# hash table, string
class Solution(object):
    def minimumGroups(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        def least_rotation(s):
            n = len(s)
            i, j, k = 0, 1, 0
            while i < n and j < n and k < n:
                a = s[(i+k)%n]
                b = s[(j+k)%n]
                if a == b:
                    k += 1
                else:
                    if a > b:
                        i += k+1
                    else:
                        j += k+1
                    if i == j:
                        j += 1
                    k = 0
            return min(i, j)

        def canonical(s):
            i = least_rotation(s)
            return s[i:]+s[:i]

        return len({(canonical(w[::2]), canonical(w[1::2])) for w in words})
