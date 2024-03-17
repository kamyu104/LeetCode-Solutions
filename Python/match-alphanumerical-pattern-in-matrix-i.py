# Time:  O(n * m * r * c)
# Space: O(1)

# brute force, hash table
class Solution(object):
    def findPattern(self, board, pattern):
        """
        :type board: List[List[int]]
        :type pattern: List[str]
        :rtype: List[int]
        """
        def check(i, j):
            lookup = [-1]*26
            lookup2 = [False]*10
            for r in xrange(len(pattern)):
                for c in xrange(len(pattern[0])):
                    y = board[i+r][j+c]
                    if pattern[r][c].isdigit():
                        if int(pattern[r][c]) != y:
                            return False
                        continue
                    x = ord(pattern[r][c])-ord('a')
                    if lookup[x] == -1:
                        if lookup2[y]:
                            return False
                        lookup2[y] = True
                        lookup[x] = y
                        continue
                    if lookup[x] != y:
                        return False
            return True
                    
        return next(([i, j] for i in xrange(len(board)-len(pattern)+1) for j in xrange(len(board[0])-len(pattern[0])+1) if check(i, j)), [-1, -1])
    
