# Time:  O(nlogn + q)
# Space: O(nlogn)

# sparse table
class Solution(object):
    def maxActiveSectionsAfterTrade(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        # RMQ - Sparse Table
        # Template: https://github.com/kamyu104/GoogleCodeJam-Farewell-Rounds/blob/main/Round%20D/genetic_sequences2.py3
        # Time:  ctor:  O(NlogN) * O(fn)
        #        query: O(fn)
        # Space: O(NlogN)
        class SparseTable(object):
            def __init__(self, arr, fn):
                self.fn = fn
                self.bit_length = [0]
                n = len(arr)
                k = n.bit_length()-1  # log2_floor(n)
                for i in xrange(k+1):
                    self.bit_length.extend(i+1 for _ in xrange(min(1<<i, (n+1)-len(self.bit_length))))
                self.st = [[0]*n for _ in xrange(k+1)]
                if not self.st:
                    return
                self.st[0] = arr[:]
                for i in xrange(1, k+1):  # Time: O(NlogN) * O(fn)
                    for j in xrange((n-(1<<i))+1):
                        self.st[i][j] = fn(self.st[i-1][j], self.st[i-1][j+(1<<(i-1))])
        
            def query(self, L, R):  # Time: O(fn)
                i = self.bit_length[R-L+1]-1
                return self.fn(self.st[i][L], self.st[i][R-(1<<i)+1])

        lookup = [-1]*len(s)
        idxs = []
        cnt1 = 0
        for i, x in enumerate(s):
            if x == '0':
                if i-1 >= 0 and s[i-1] == '0':
                    idxs[-1][1] += 1
                else:
                    idxs.append([i, 1])
            else:
                cnt1 += 1
            lookup[i] = len(idxs)-1
        if not idxs:
            return [cnt1]*len(queries)
        arr = [0]*(len(idxs)-1)
        for i in xrange(len(idxs)-1):
            arr[i] = idxs[i][1]+idxs[i+1][1]
        st = SparseTable(arr, max)
        result = [cnt1]*len(queries)
        for i, (l, r) in enumerate(queries):
            left, right  = lookup[l]+1, lookup[r]-int(s[r] == '0')
            left_cnt = idxs[lookup[l]][1]-(l-idxs[lookup[l]][0]) if lookup[l] != -1 else -1
            right_cnt = r-idxs[lookup[r]][0]+1 if lookup[r] != -1 else -1
            if left <= right-1:
                result[i] = max(result[i], cnt1 + st.query(left, right-1))
            if s[l] == '0' and s[r] == '0' and lookup[l]+1 == lookup[r]:
                result[i] = max(result[i], cnt1+left_cnt+right_cnt)
            if s[l] == '0' and lookup[l]+1 <= right:
                result[i] = max(result[i], cnt1+left_cnt+idxs[lookup[l]+1][1])
            if s[r] == '0' and left <= lookup[r]-1:
                result[i] = max(result[i], cnt1+right_cnt+idxs[lookup[r]-1][1])
        return result
