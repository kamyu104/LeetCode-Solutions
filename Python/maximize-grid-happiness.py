# Time:  O(C(m * n, i) * C(m * n - i, e))
# Space: O(m + n)

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
        
        result = 0
        stk = [(2, ([], introvertsCount, extrovertsCount, 0))]
        while stk:
            step, params = stk.pop()
            if step == 2:
                curr, ins, exs, total = params
                if ins < 0 or exs < 0:
                    continue                
                if len(curr) == m*n or (ins == 0 and exs == 0):
                    result = max(result, total)                
                    continue
                if total + (ins+exs)*120 < result:  # pruning
                    continue
                stk.append((3, (curr,)))
                stk.append((2, (curr, ins, exs-1, count_total(curr, 2, total))))
                stk.append((1, (curr, 2)))

                stk.append((3, (curr,)))
                stk.append((2, (curr, ins-1, exs, count_total(curr, 1, total))))
                stk.append((1, (curr, 1)))

                if left(curr) or up(curr):  # leave unoccupied iff left or up is occupied
                    stk.append((3, (curr,)))
                    stk.append((2, (curr, ins, exs, total)))
                    stk.append((1, (curr, 0)))
            elif step == 1:
                curr, x = params
                curr.append(x)
            elif step == 3:
                curr = params[0]
                curr.pop()
        return result


# Time:  O(C(m * n, i) * C(m * n - i, e))
# Space: O(m + n)
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
        
        def backtracking(curr, ins, exs, total, result):
            if ins < 0 or exs < 0:
                return                
            if len(curr) == m*n or (ins == 0 and exs == 0):
                result[0] = max(result[0], total)                
                return
            if total + (ins+exs)*120 < result[0]:  # pruning
                return
            if left(curr) or up(curr):  # leave unoccupied iff left or up is occupied
                curr.append(0)
                backtracking(curr, ins, exs, total, result)
                curr.pop()

            new_total = count_total(curr, 1, total)
            curr.append(1)
            backtracking(curr, ins-1, exs, new_total, result)
            curr.pop()
            
            new_total = count_total(curr, 2, total)
            curr.append(2)
            backtracking(curr, ins, exs-1, new_total, result)
            curr.pop()

        result = [0]
        backtracking([], introvertsCount, extrovertsCount, 0, result)
        return result[0]
