# Time:  O(n)
# Space: O(1)

class Solution(object):
    def equationsPossible(self, equations):
        """
        :type equations: List[str]
        :rtype: bool
        """
        graph = [[] for _ in xrange(26)]

        for eqn in equations:
            x = ord(eqn[0]) - ord('a')
            y = ord(eqn[3]) - ord('a')
            if eqn[1] == '!':
                if x == y:
                    return False
            else:
                graph[x].append(y)
                graph[y].append(x)

        color = [None]*26
        c = 0
        for i in xrange(26):
            if color[i] is not None:
                continue
            c += 1
            stack = [i]
            while stack:
                node = stack.pop()
                for nei in graph[node]:
                    if color[nei] is not None:
                        continue
                    color[nei] = c
                    stack.append(nei)

        for eqn in equations:
            if eqn[1] != '!':
                continue
            x = ord(eqn[0]) - ord('a')
            y = ord(eqn[3]) - ord('a')
            if color[x] is not None and \
               color[x] == color[y]:
                return False
        return True
