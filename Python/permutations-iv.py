# Time:  O(n^2)
# Space: O(n)

# combinatorics
class Solution(object):
    def permute(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        result = []
        cnt = [1]*n
        for i in xrange(len(cnt)-1):
            cnt[i+1] = min(cnt[i]*((i+2)//2), k)
        lookup = [False]*n
        for i in xrange(n):
            for j in xrange(n):
                if not (not lookup[j] and ((i == 0 and n%2 == 0) or (j+1)%2 == (1 if not result else (result[-1]%2)^1))):
                    continue
                if k <= cnt[n-1-i]:
                    break
                k -= cnt[n-1-i]
            else:
                return []
            lookup[j] = True
            result.append(j+1)
        return result


# Time:  O(n^2)
# Space: O(n)
# combinatorics
class Solution2(object):
    def permute(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        result = []
        fact = [1]*(((n-1)+1)//2+1)
        for i in xrange(len(fact)-1):
            fact[i+1] = fact[i]*(i+1)
        lookup = [False]*n
        for i in xrange(n):
            cnt = fact[(n-1-i)//2]*fact[((n-1-i)+1)//2]
            for j in xrange(n):
                if not (not lookup[j] and ((i == 0 and n%2 == 0) or (j+1)%2 == (1 if not result else (result[-1]%2)^1))):
                    continue
                if k <= cnt:
                    break
                k -= cnt
            else:
                return []
            lookup[j] = True
            result.append(j+1)
        return result
