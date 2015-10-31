# Time:  O(n)
# Space: O(10) = O(1)


# You are playing the following Bulls and Cows game with your friend:
# You write a 4-digit secret number and ask your friend to guess it,
# each time your friend guesses a number, you give a hint, the hint 
# tells your friend how many digits are in the correct positions 
# (called "bulls") and how many digits are in the wrong positions 
# (called "cows"), your friend will use those hints to find out the
# secret number.
#
# For example:
#
# Secret number:  1807
# Friend's guess: 7810
# Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
# According to Wikipedia: "Bulls and Cows (also known as Cows and Bulls
# or Pigs and Bulls or Bulls and Cleots) is an old code-breaking mind or 
# paper and pencil game for two or more players, predating the similar 
# commercially marketed board game Mastermind. The numerical version of 
# the game is usually played with 4 digits, but can also be played with 
# 3 or any other number of digits."
#
# Write a function to return a hint according to the secret number and 
# friend's guess, use A to indicate the bulls and B to indicate the cows,
# in the above example, your function should return 1A3B.
#
# You may assume that the secret number and your friend's guess only contain
# digits, and their lengths are always equal.
#

# One pass solution.
from collections import defaultdict
from itertools import izip

class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        A, B = 0, 0
        s_lookup, g_lookup = defaultdict(int), defaultdict(int)
        for s, g in izip(secret, guess):
            if s == g:
                A += 1
            else:
                if s_lookup[g]:
                    s_lookup[g] -= 1
                    B += 1
                else:
                    g_lookup[g] += 1
                if g_lookup[s]:
                    g_lookup[s] -= 1
                    B += 1
                else:
                    s_lookup[s] += 1
                    
        return "%dA%dB" % (A, B)


# Two pass solution.
from collections import Counter
from itertools import imap

class Solution2(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        A = sum(imap(operator.eq, secret, guess))
        B = sum((Counter(secret) & Counter(guess)).values()) - A
        return "%dA%dB" % (A, B)
  
