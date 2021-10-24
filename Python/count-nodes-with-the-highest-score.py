# Time:  O(n)
# Space: O(n)

class Solution(object):
    def countHighestScoreNodes(self, parents):
        """
        :type parents: List[int]
        :rtype: int
        """
        def iter_dfs(adj):
            result = [0]*2
            stk = [(1, (0, [0]))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    i, ret = args
                    cnts = [[0] for _ in xrange(len(adj[i]))]
                    stk.append((2, (cnts, ret)))
                    for j, child in enumerate(adj[i]):
                        stk.append((1, (child, cnts[j])))
                elif step == 2:
                    cnts, ret = args
                    ret[0] = sum(cnt[0] for cnt in cnts)+1
                    score = max((len(adj)-ret[0]), 1)*reduce(lambda x, y: x*y[0], cnts, 1)
                    if score > result[0]:
                        result[:] = [score, 1]
                    elif score == result[0]:
                        result[1] += 1
            return result[1]

        adj = [[] for _ in xrange(len(parents))]  # Space: O(n)
        for i in xrange(1, len(parents)):
            adj[parents[i]].append(i)
        return iter_dfs(adj)


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def countHighestScoreNodes(self, parents):
        """
        :type parents: List[int]
        :rtype: int
        """
        def dfs(adj, i, result):
            cnts = [dfs(adj, child, result) for child in adj[i]]
            total = sum(cnts)+1
            score = max((len(adj)-total), 1)*reduce(lambda x, y: x*y, cnts, 1)
            if score > result[0]:
                result[:] = [score, 1]
            elif score == result[0]:
                result[1] += 1
            return total

        adj = [[] for _ in xrange(len(parents))]  # Space: O(n)
        for i in xrange(1, len(parents)):
            adj[parents[i]].append(i)
        result = [0]*2
        dfs(adj, 0, result)
        return result[1]
