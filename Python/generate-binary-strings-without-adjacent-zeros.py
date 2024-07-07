# Time:  O(n * 2^n)
# Space: O(n)

# backtracking
class Solution(object):
    def validStrings(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def backtracking(i):
            if i == n:
                result.append("".join(curr))
                return
            if not curr or curr[-1] == '1':
                curr.append('0')
                backtracking(i+1)
                curr.pop()
            curr.append('1')
            backtracking(i+1)
            curr.pop()

        result, curr = [], []
        backtracking(0)
        return result


# Time:  O(n * 2^n)
# Space: O(n * 2^n)
# bfs
class Solution2(object):
    def validStrings(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        q = [[]]
        for _ in xrange(n):
            new_q = []
            for x in q:
                if not x or x[-1] == '1':
                    new_q.append(x+['0'])
                new_q.append(x+['1'])
            q = new_q
        return ["".join(x) for x in q]
