# Time:  O(b * b! * h!)
# Space: O(b * b! * h!)

import collections


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

