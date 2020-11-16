# Time:  O(C(m * n, i) * C(m * n - i, e))
# Space: O(min(m * n, i + e))

class Solution(object):
    def getMaxGridHappiness(self, m, n, introvertsCount, extrovertsCount):
        """
        :type m: int
        :type n: int
        :type introvertsCount: int
        :type extrovertsCount: int
        :rtype: int
        """
        def left(curr):
            return len(curr)%n and curr[-1]

        def up(curr):
            return len(curr) >= n and curr[-n]

        def count_total(curr, t, total):
            return (total
                    - 30*(left(curr) == 1)
                    - 30*(up(curr) == 1)
                    + 20*(left(curr) == 2)
                    + 20*(up(curr) == 2)
                    + (120 - 30*(left(curr) != 0) - 30*(up(curr) != 0))*(t == 1)
                    + (40 + 20*(left(curr) != 0) + 20*(up(curr) != 0))*(t == 2))
        
        def iter_backtracking(i, e):
            result = 0
            stk = [(2, ([], i, e, 0))]
            while stk:
                step, params = stk.pop()
                if step == 2:
                    curr, i, e, total = params
                    if i < 0 or e < 0:
                        continue                
                    if len(curr) == m*n or (i == 0 and e == 0):
                        result = max(result, total)                
                        continue
                    if total + (i+e)*120 < result:  # pruning
                        continue
                    stk.append((3, (curr,)))
                    stk.append((2, (curr, i, e-1, count_total(curr, 2, total))))
                    stk.append((1, (curr, 2)))

                    stk.append((3, (curr,)))
                    stk.append((2, (curr, i-1, e, count_total(curr, 1, total))))
                    stk.append((1, (curr, 1)))

                    if left(curr) or up(curr):  # leave unoccupied iff left or up is occupied
                        stk.append((3, (curr,)))
                        stk.append((2, (curr, i, e, total)))
                        stk.append((1, (curr, 0)))
                elif step == 1:
                    curr, x = params
                    curr.append(x)
                elif step == 3:
                    curr = params[0]
                    curr.pop()
            return result
          
        return iter_backtracking(introvertsCount, extrovertsCount)


# Time:  O(C(m * n, i) * C(m * n - i, e))
# Space: O(min(m * n, i + e))
class Solution2(object):
    def getMaxGridHappiness(self, m, n, introvertsCount, extrovertsCount):
        """
        :type m: int
        :type n: int
        :type introvertsCount: int
        :type extrovertsCount: int
        :rtype: int
        """
        def left(curr):
            return len(curr)%n and curr[-1]

        def up(curr):
            return len(curr) >= n and curr[-n]

        def count_total(curr, t, total):
            return (total
                    - 30*(left(curr) == 1)
                    - 30*(up(curr) == 1)
                    + 20*(left(curr) == 2)
                    + 20*(up(curr) == 2)
                    + (120 - 30*(left(curr) != 0) - 30*(up(curr) != 0))*(t == 1)
                    + (40 + 20*(left(curr) != 0) + 20*(up(curr) != 0))*(t == 2))
        
        def backtracking(curr, i, e, total, result):
            if i < 0 or e < 0:
                return                
            if len(curr) == m*n or (i == 0 and e == 0):
                result[0] = max(result[0], total)                
                return
            if total + (i+e)*120 < result[0]:  # pruning
                return
            if left(curr) or up(curr):  # leave unoccupied iff left or up is occupied
                curr.append(0)
                backtracking(curr, i, e, total, result)
                curr.pop()

            new_total = count_total(curr, 1, total)
            curr.append(1)
            backtracking(curr, i-1, e, new_total, result)
            curr.pop()
            
            new_total = count_total(curr, 2, total)
            curr.append(2)
            backtracking(curr, i, e-1, new_total, result)
            curr.pop()

        result = [0]
        backtracking([], introvertsCount, extrovertsCount, 0, result)
        return result[0]
