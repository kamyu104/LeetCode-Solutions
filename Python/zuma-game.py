# Time:  O(b * b! * h!)
# Space: O(b * b! * h!)

# Think about Zuma Game. You have a row of balls on the table,
# colored red(R), yellow(Y), blue(B), green(G), and white(W).
# You also have several balls in your hand.
#
# Each time, you may choose a ball in your hand, and insert it into the row
# (including the leftmost place and rightmost place).
# Then, if there is a group of 3 or more balls in the same color touching,
# remove these balls. Keep doing this until no more balls can be removed.
#
# Find the minimal balls you have to insert to remove all the balls on the table.
# If you cannot remove all the balls, output -1.
#
# Examples:
#
# Input: "WRRBBW", "RB"
# Output: -1
# Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW
#
# Input: "WWRRBBWW", "WRBRW"
# Output: 2
# Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty
#
# Input:"G", "GGGGG"
# Output: 2
# Explanation: G -> G[G] -> GG[G] -> empty 
#
# Input: "RBYYBBRRB", "YRBGB"
# Output: 3
# Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 
#
# Note:
# You may assume that the initial row of balls on the table won’t have any 3 or
# more consecutive balls with the same color.
# The number of balls on the table won't exceed 20, and the string represents these balls
# is called "board" in the input.
# The number of balls in your hand won't exceed 5, and the string represents these balls
# is called "hand" in the input.
# Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.

class Solution(object):
    def findMinStep(self, board, hand):
        """
        :type board: str
        :type hand: str
        :rtype: int
        """
        def shrink(s):  # Time: O(n), Space: O(n)
                stack = []
                start = 0
                for i in xrange(len(s)+1):
                    if i == len(s) or s[i] != s[start]:
                        if stack and stack[-1][0] == s[start]:
                            stack[-1][1] += i - start
                            if stack[-1][1] >= 3:
                                stack.pop()
                        elif s and i - start < 3:
                            stack += [s[start], i - start],
                        start = i
                result = []
                for p in stack:
                    result += [p[0]] * p[1]
                return result
        
        def find(board, c, j):
            for i in xrange(j, len(board)):
                if board[i] == c:
                    return i
            return -1
        
        def findMinStepHelper(board, hand, lookup):
            if not board: return 0
            if not hand: return float("inf")
            if tuple(hand) in lookup[tuple(board)]: return lookup[tuple(board)][tuple(hand)]
    
            result = float("inf")
            for i in xrange(len(hand)):
                j = 0
                while j < len(board):
                    k = find(board, hand[i], j)
                    if k == -1:
                        break
                    
                    if k < len(board) - 1 and board[k] == board[k+1]:
                        next_board = shrink(board[0:k] + board[k+2:])
                        next_hand = hand[0:i] + hand[i+1:]
                        result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 1)
                        k += 1
                    elif i > 0 and hand[i] == hand[i-1]:
                        next_board = shrink(board[0:k] + board[k+1:])
                        next_hand = hand[0:i-1] + hand[i+1:]
                        result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 2)
                    j = k+1

            lookup[tuple(board)][tuple(hand)] = result
            return result

        lookup = collections.defaultdict(dict)
        board, hand = list(board), list(hand)
        hand.sort()
        result = findMinStepHelper(board, hand, lookup)
        return -1 if result == float("inf") else result
