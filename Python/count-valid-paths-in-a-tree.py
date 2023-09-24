# Time:  O(n)
# Space: O(n)

# number theory, tree dp, iterative dfs
class Solution(object):
    def countPaths(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        def linear_sieve_of_eratosthenes(n):  # Time: O(n), Space: O(n)
            primes = []
            spf = [-1]*(n+1)  # the smallest prime factor
            for i in xrange(2, n+1):
                if spf[i] == -1:
                    spf[i] = i
                    primes.append(i)
                for p in primes:
                    if i*p > n or p > spf[i]:
                        break
                    spf[i*p] = p
            return spf
        
        def is_prime(u):
            return spf[u] == u

        def iter_dfs():
            result = 0
            stk = [(1, (0, -1, [0]*2))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, p, cnt = args
                    cnt[:] = [1-is_prime(u+1), is_prime(u+1)]
                    stk.append((2, (u, p, cnt, 0)))
                elif step == 2:
                    u, p, cnt, i = args
                    if i == len(adj[u]):
                        continue
                    v = adj[u][i]
                    if v == p:
                        stk.append((2, (u, p, cnt, i+1)))
                        continue
                    new_cnt = [0]*2
                    stk.append((3, (u, p, cnt, new_cnt, i)))
                    stk.append((1, (v, u, new_cnt)))
                elif step == 3:
                    u, p, cnt, new_cnt, i = args
                    result += cnt[0]*new_cnt[1]+cnt[1]*new_cnt[0]
                    if is_prime(u+1):
                        cnt[1] += new_cnt[0]
                    else:
                        cnt[0] += new_cnt[0]
                        cnt[1] += new_cnt[1]
                    stk.append((2, (u, p, cnt, i+1)))
            return result

        spf = linear_sieve_of_eratosthenes(n)
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            u, v = u-1, v-1
            adj[u].append(v)
            adj[v].append(u)
        return iter_dfs()


# Time:  O(n)
# Space: O(n)
# number theory, tree dp, dfs
class Solution2(object):
    def countPaths(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        def linear_sieve_of_eratosthenes(n):  # Time: O(n), Space: O(n)
            primes = []
            spf = [-1]*(n+1)  # the smallest prime factor
            for i in xrange(2, n+1):
                if spf[i] == -1:
                    spf[i] = i
                    primes.append(i)
                for p in primes:
                    if i*p > n or p > spf[i]:
                        break
                    spf[i*p] = p
            return spf
        
        def is_prime(u):
            return spf[u] == u

        def dfs(u, p):
            cnt = [1-is_prime(u+1), is_prime(u+1)]
            for v in adj[u]:
                if v == p:
                    continue
                new_cnt = dfs(v, u)
                result[0] += cnt[0]*new_cnt[1]+cnt[1]*new_cnt[0]
                if is_prime(u+1):
                    cnt[1] += new_cnt[0]
                else:
                    cnt[0] += new_cnt[0]
                    cnt[1] += new_cnt[1]
            return cnt

        spf = linear_sieve_of_eratosthenes(n)
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            u, v = u-1, v-1
            adj[u].append(v)
            adj[v].append(u)
        result = [0]
        dfs(0, -1)
        return result[0]
