# Time:  O(k^n)
# Space: O(k^n)

class Solution(object):
    def crackSafe(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        M = k**(n-1)
        P = [q*k+i for i in xrange(k) for q in xrange(M)]  # rotate: i*k^(n-1) + q => q*k + i
        result = [str(k-1)]*(n-1)
        for i in xrange(k**n):
            j = i
            # concatenation in lexicographic order of Lyndon words
            while P[j] >= 0:
                result.append(str(j//M))
                P[j], j = -1, P[j]
        return "".join(result)


# Time:  O(n * k^n)
# Space: O(n * k^n)
class Solution2(object):
    def crackSafe(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        result = [str(k-1)]*n
        lookup = {"".join(result)}
        total = k**n
        while len(lookup) < total:
            node = result[len(result)-n+1:]
            for i in xrange(k):
                neighbor = "".join(node) + str(i)
                if neighbor not in lookup:
                    lookup.add(neighbor)
                    result.append(str(i))
                    break
        return "".join(result)


# Time:  O(n * k^n)
# Space: O(n * k^n)
class Solution3(object):
    def crackSafe(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        def dfs(k, node, lookup, result):
            for i in xrange(k):
                neighbor = node + str(i)
                if neighbor not in lookup:
                    lookup.add(neighbor)
                    result.append(str(i))
                    dfs(k, neighbor[1:], lookup, result)
                    break

        result = [str(k-1)]*(n-1)
        lookup = set()
        dfs(k, "".join(result), lookup, result)
        return "".join(result)

