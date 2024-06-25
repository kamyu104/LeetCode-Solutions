# Time:  O(n * m * log(max(n, m)) + max(n, m)^2)
# Space: O(n * m * log(max(n, m)))

# sparse table
class Solution(object):
    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
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
                self.st[0] = arr[:]
                for i in xrange(1, k+1):  # Time: O(NlogN) * O(fn)
                    for j in xrange((n-(1<<i))+1):
                        self.st[i][j] = fn(self.st[i-1][j], self.st[i-1][j+(1<<(i-1))])
        
            def query(self, L, R):  # Time: O(fn)
                i = self.bit_length[R-L+1]-1  # log2_floor(R-L+1)
                return self.fn(self.st[i][L], self.st[i][R-(1<<i)+1])

        def minimumArea(min_i, max_i, min_j, max_j):
            min_r = min(st_min_i[min_i].query(min_j, max_j), max_i+1) if min_i < len(st_min_i) and min_j <= max_j else max_i+1
            max_r = max(st_max_i[max_i].query(min_j, max_j), min_i-1) if min_j <= max_j else min_i-1
            min_c = min(st_min_j[min_j].query(min_i, max_i), max_j+1) if min_j < len(grid[0]) and min_i <= max_i else max_j+1
            max_c = max(st_max_j[max_j].query(min_i, max_i), min_j-1) if min_i <= max_i else min_j-1
            return (max_r-min_r+1)*(max_c-min_c+1)

        st_min_i = [None]*len(grid)
        curr = [len(grid)]*len(grid[0])
        for i in reversed(xrange(len(grid))):
            for j in xrange(len(grid[0])):
                if grid[i][j]:
                    curr[j] = i
            st_min_i[i] = SparseTable(curr, min)
        st_max_i = [None]*len(grid)
        curr = [-1]*len(grid[0])
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if grid[i][j]:
                    curr[j] = i
            st_max_i[i] = SparseTable(curr, max)
        st_min_j = [None]*len(grid[0])
        curr = [len(grid[0])]*len(grid)
        for j in reversed(xrange(len(grid[0]))):
            for i in xrange(len(grid)):
                if grid[i][j]:
                    curr[i] = j
            st_min_j[j] = SparseTable(curr, min)
        st_max_j = [None]*len(grid[0])
        curr = [-1]*len(grid)
        for j in xrange(len(grid[0])):
            for i in xrange(len(grid)):
                if grid[i][j]:
                    curr[i] = j
            st_max_j[j] = SparseTable(curr, max)
        result = float("inf")
        for i in xrange(len(grid)):
            a = minimumArea(0, i, 0, len(grid[0])-1)
            for j in xrange(len(grid[0])):
                b = minimumArea(i+1, len(grid)-1, 0, j)
                c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
            for j in xrange(i+1, len(grid)):
                b = minimumArea(i+1, j, 0, len(grid[0])-1)
                c = minimumArea(j+1, len(grid)-1, 0, len(grid[0])-1)
                result = min(result, a+b+c)
            a = minimumArea(i+1, len(grid)-1, 0, len(grid[0])-1)
            for j in xrange(len(grid[0])):
                b = minimumArea(0, i, 0, j)
                c = minimumArea(0, i, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
        for j in xrange(len(grid[0])):
            a = minimumArea(0, len(grid)-1, 0, j)
            for i in xrange(len(grid)):
                b = minimumArea(0, i, j+1, len(grid[0])-1)
                c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
            for i in xrange(j+1, len(grid[0])):
                b = minimumArea(0, len(grid)-1, j+1, i)
                c = minimumArea(0, len(grid)-1, i+1, len(grid[0])-1)
                result = min(result, a+b+c)
            a = minimumArea(0, len(grid)-1, j+1, len(grid[0])-1)
            for i in xrange(len(grid)):
                b = minimumArea(0, i, 0, j)
                c = minimumArea(i+1, len(grid)-1, 0, j)
                result = min(result, a+b+c)
        return result


# Time:  O(n * m * log(max(n, m)) + max(n, m)^2)
# Space: O(n * m * log(max(n, m)))

# sparse table
class Solution2(object):
    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
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
                self.st[0] = arr[:]
                for i in xrange(1, k+1):  # Time: O(NlogN) * O(fn)
                    for j in xrange((n-(1<<i))+1):
                        self.st[i][j] = fn(self.st[i-1][j], self.st[i-1][j+(1<<(i-1))])
        
            def query(self, L, R):  # Time: O(fn)
                i = self.bit_length[R-L+1]-1  # log2_floor(R-L+1)
                return self.fn(self.st[i][L], self.st[i][R-(1<<i)+1])

        def minimumArea(min_i, max_i, min_j, max_j):
            min_r = min(st_min_i[min_i].query(min_j, max_j), max_i+1) if min_i < len(st_min_i) and min_j <= max_j else max_i+1
            max_r = max(st_max_i[max_i].query(min_j, max_j), min_i-1) if min_j <= max_j else min_i-1
            min_c = min(st_min_j[min_j].query(min_i, max_i), max_j+1) if min_j < len(grid[0]) and min_i <= max_i else max_j+1
            max_c = max(st_max_j[max_j].query(min_i, max_i), min_j-1) if min_i <= max_i else min_j-1
            return (max_r-min_r+1)*(max_c-min_c+1)

        result = float("inf")
        for _ in xrange(4):
            st_min_i = [None]*len(grid)
            curr = [len(grid)]*len(grid[0])
            for i in reversed(xrange(len(grid))):
                for j in xrange(len(grid[0])):
                    if grid[i][j]:
                        curr[j] = i
                st_min_i[i] = SparseTable(curr, min)
            st_max_i = [None]*len(grid)
            curr = [-1]*len(grid[0])
            for i in xrange(len(grid)):
                for j in xrange(len(grid[0])):
                    if grid[i][j]:
                        curr[j] = i
                st_max_i[i] = SparseTable(curr, max)
            st_min_j = [None]*len(grid[0])
            curr = [len(grid[0])]*len(grid)
            for j in reversed(xrange(len(grid[0]))):
                for i in xrange(len(grid)):
                    if grid[i][j]:
                        curr[i] = j
                st_min_j[j] = SparseTable(curr, min)
            st_max_j = [None]*len(grid[0])
            curr = [-1]*len(grid)
            for j in xrange(len(grid[0])):
                for i in xrange(len(grid)):
                    if grid[i][j]:
                        curr[i] = j
                st_max_j[j] = SparseTable(curr, max)        
            for i in xrange(len(grid)):
                a = minimumArea(0, i, 0, len(grid[0])-1)
                for j in xrange(len(grid[0])):
                    b = minimumArea(i+1, len(grid)-1, 0, j)
                    c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                    result = min(result, a+b+c)
                for j in xrange(i+1, len(grid)):
                    b = minimumArea(i+1, j, 0, len(grid[0])-1)
                    c = minimumArea(j+1, len(grid)-1, 0, len(grid[0])-1)
                    result = min(result, a+b+c)
            grid = zip(*grid[::-1])
        return result


# Time:  O(max(n, m)^2 * log(max(n, m)))
# Space: O(1)
# prefix sum, binary search
class Solution3(object):
    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left
        
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        def minimumArea(min_i, max_i, min_j, max_j):
            def count(x1, y1, x2, y2):
                if not (x1 <= x2 and y1 <= y2):
                    return 0
                cnt = grid[x2][y2]
                if x1-1 >= 0:
                    cnt -= grid[x1-1][y2]
                if y1-1 >= 0:
                    cnt -= grid[x2][y1-1]
                if x1-1 >= 0 and y1-1 >= 0:
                    cnt += grid[x1-1][y1-1]
                return cnt
    
            min_r = binary_search(min_i, max_i, lambda i: count(min_i, min_j, i, max_j))
            max_r = binary_search_right(min_i, max_i, lambda i: count(i, min_j, max_i, max_j))
            min_c = binary_search(min_j, max_j, lambda j: count(min_i, min_j, max_i, j))
            max_c = binary_search_right(min_j, max_j, lambda j: count(min_i, j, max_i, max_j))
            return (max_r-min_r+1)*(max_c-min_c+1)
    
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if i-1 >= 0:
                    grid[i][j] += grid[i-1][j]
                if j-1 >= 0:
                    grid[i][j] += grid[i][j-1]
                if i-1 >= 0 and j-1 >= 0:
                    grid[i][j] -= grid[i-1][j-1]
        result = float("inf")
        for i in xrange(len(grid)):
            a = minimumArea(0, i, 0, len(grid[0])-1)
            for j in xrange(len(grid[0])):
                b = minimumArea(i+1, len(grid)-1, 0, j)
                c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
            for j in xrange(i+1, len(grid)):
                b = minimumArea(i+1, j, 0, len(grid[0])-1)
                c = minimumArea(j+1, len(grid)-1, 0, len(grid[0])-1)
                result = min(result, a+b+c)
            a = minimumArea(i+1, len(grid)-1, 0, len(grid[0])-1)
            for j in xrange(len(grid[0])):
                b = minimumArea(0, i, 0, j)
                c = minimumArea(0, i, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
        for j in xrange(len(grid[0])):
            a = minimumArea(0, len(grid)-1, 0, j)
            for i in xrange(len(grid)):
                b = minimumArea(0, i, j+1, len(grid[0])-1)
                c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
            for i in xrange(j+1, len(grid[0])):
                b = minimumArea(0, len(grid)-1, j+1, i)
                c = minimumArea(0, len(grid)-1, i+1, len(grid[0])-1)
                result = min(result, a+b+c)
            a = minimumArea(0, len(grid)-1, j+1, len(grid[0])-1)
            for i in xrange(len(grid)):
                b = minimumArea(0, i, 0, j)
                c = minimumArea(i+1, len(grid)-1, 0, j)
                result = min(result, a+b+c)
        return result


# Time:  O(max(n, m)^2 * log(max(n, m)))
# Space: O(n * m)
# prefix sum, binary search
class Solution4(object):
    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left
        
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        def minimumArea(min_i, max_i, min_j, max_j):
            def count(x1, y1, x2, y2):
                if not (x1 <= x2 and y1 <= y2):
                    return 0
                cnt = prefix[x2][y2]
                if x1-1 >= 0:
                    cnt -= prefix[x1-1][y2]
                if y1-1 >= 0:
                    cnt -= prefix[x2][y1-1]
                if x1-1 >= 0 and y1-1 >= 0:
                    cnt += prefix[x1-1][y1-1]
                return cnt
    
            min_r = binary_search(min_i, max_i, lambda i: count(min_i, min_j, i, max_j))
            max_r = binary_search_right(min_i, max_i, lambda i: count(i, min_j, max_i, max_j))
            min_c = binary_search(min_j, max_j, lambda j: count(min_i, min_j, max_i, j))
            max_c = binary_search_right(min_j, max_j, lambda j: count(min_i, j, max_i, max_j))
            return (max_r-min_r+1)*(max_c-min_c+1)
    
        result = float("inf")
        for _ in xrange(4):
            prefix = [[0]*len(grid[0]) for _ in xrange(len(grid))]
            for i in xrange(len(grid)):
                for j in xrange(len(grid[0])):
                    prefix[i][j] = grid[i][j]
                    if i-1 >= 0:
                        prefix[i][j] += prefix[i-1][j]
                    if j-1 >= 0:
                        prefix[i][j] += prefix[i][j-1]
                    if i-1 >= 0 and j-1 >= 0:
                        prefix[i][j] -= prefix[i-1][j-1]
            for i in xrange(len(grid)):
                a = minimumArea(0, i, 0, len(grid[0])-1)
                for j in xrange(len(grid[0])):
                    b = minimumArea(i+1, len(grid)-1, 0, j)
                    c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                    result = min(result, a+b+c)
                for j in xrange(i+1, len(grid)):
                    b = minimumArea(i+1, j, 0, len(grid[0])-1)
                    c = minimumArea(j+1, len(grid)-1, 0, len(grid[0])-1)
                    result = min(result, a+b+c)
            grid = zip(*grid[::-1])
        return result


# Time:  O((n^2 + m^2 + 4 * n * m) * n * m) = O(max(n, m)^3 * min(n, m))
# Space: O(1)
# brute force
class Solution5(object):
    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def minimumArea(min_i, max_i, min_j, max_j):
            min_r, max_r, min_c, max_c = max_i+1, min_i-1, max_j+1, min_j-1
            for i in xrange(min_i, max_i+1):
                for j in xrange(min_j, max_j+1):
                    if grid[i][j] == 0:
                        continue
                    min_r, max_r, min_c, max_c = min(min_r, i), max(max_r, i), min(min_c, j), max(max_c, j)
            return (max_r-min_r+1)*(max_c-min_c+1)
    
        result = float("inf")
        for i in xrange(len(grid)):
            a = minimumArea(0, i, 0, len(grid[0])-1)
            for j in xrange(len(grid[0])):
                b = minimumArea(i+1, len(grid)-1, 0, j)
                c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
            for j in xrange(i+1, len(grid)):
                b = minimumArea(i+1, j, 0, len(grid[0])-1)
                c = minimumArea(j+1, len(grid)-1, 0, len(grid[0])-1)
                result = min(result, a+b+c)
            a = minimumArea(i+1, len(grid)-1, 0, len(grid[0])-1)
            for j in xrange(len(grid[0])):
                b = minimumArea(0, i, 0, j)
                c = minimumArea(0, i, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
        for j in xrange(len(grid[0])):
            a = minimumArea(0, len(grid)-1, 0, j)
            for i in xrange(len(grid)):
                b = minimumArea(0, i, j+1, len(grid[0])-1)
                c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                result = min(result, a+b+c)
            for i in xrange(j+1, len(grid[0])):
                b = minimumArea(0, len(grid)-1, j+1, i)
                c = minimumArea(0, len(grid)-1, i+1, len(grid[0])-1)
                result = min(result, a+b+c)
            a = minimumArea(0, len(grid)-1, j+1, len(grid[0])-1)
            for i in xrange(len(grid)):
                b = minimumArea(0, i, 0, j)
                c = minimumArea(i+1, len(grid)-1, 0, j)
                result = min(result, a+b+c)
        return result


# Time:  O((n^2 + m^2 + 4 * n * m) * n * m) = O(max(n, m)^3 * min(n, m))
# Space: O(n * m)
# brute force
class Solution6(object):
    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def minimumArea(min_i, max_i, min_j, max_j):
            min_r, max_r, min_c, max_c = max_i+1, min_i-1, max_j+1, min_j-1
            for i in xrange(min_i, max_i+1):
                for j in xrange(min_j, max_j+1):
                    if grid[i][j] == 0:
                        continue
                    min_r, max_r, min_c, max_c = min(min_r, i), max(max_r, i), min(min_c, j), max(max_c, j)
            return (max_r-min_r+1)*(max_c-min_c+1)
    
        result = float("inf")
        for _ in xrange(4):
            for i in xrange(len(grid)):
                a = minimumArea(0, i, 0, len(grid[0])-1)
                for j in xrange(len(grid[0])):
                    b = minimumArea(i+1, len(grid)-1, 0, j)
                    c = minimumArea(i+1, len(grid)-1, j+1, len(grid[0])-1)
                    result = min(result, a+b+c)
                for j in xrange(i+1, len(grid)):
                    b = minimumArea(i+1, j, 0, len(grid[0])-1)
                    c = minimumArea(j+1, len(grid)-1, 0, len(grid[0])-1)
                    result = min(result, a+b+c)
            grid = zip(*grid[::-1])
        return result
