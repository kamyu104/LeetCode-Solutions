# Time:  O(n^2)
# Space: O(n)

# This problem is an interactive problem new to the LeetCode platform.
#
# We are given a word list of unique words, each word is 6 letters long,
# and one word in this list is chosen as secret.
#
# You may call master.guess(word) to guess a word.
# The guessed word should have type string and must be from the original
# list with 6 lowercase letters.
#
# This function returns an integer type,
# representing the number of exact matches (value and position)
# of your guess to the secret word.
# Also, if your guess is not in the given wordlist, it will return -1 instead.
#
# For each test case, you have 10 guesses to guess the word.
# At the end of any number of calls, if you have made 10 or
# less calls to master.guess
# and at least one of these guesses was the secret, you pass the testcase.
#
# Besides the example test case below,
# there will be 5 additional test cases, each with 100 words in the word list.
# The letters of each word in those testcases were chosen independently at
# random from 'a' to 'z',
# such that every word in the given word lists is unique.
#
# Example 1:
# Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]
#
# Explanation:
#
# master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
# master.guess("acckzz") returns 6, because "acckzz" is secret
# and has all 6 matches.
# master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
# master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
# master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
#
# We made 5 calls to master.guess and one of them was the secret,
# so we pass the test case.
# Note:  Any solutions that attempt to circumvent the judge will result
# in disqualification.
#
# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master(object):
#    def guess(self, word):
#        """
#        :type word: str
#        :rtype int
#        """

import collections
import itertools

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        def solve(H, possible):
            min_max_group, best_guess = possible, None
            for guess in possible:
                groups = [[] for _ in xrange(7)]
                for j in possible:
                    if j != guess:
                        groups[H[guess][j]].append(j)
                max_group = max(groups, key=len)
                if len(max_group) < len(min_max_group):
                    min_max_group, best_guess = max_group, guess
            return best_guess

        H = [[sum(a == b for a, b in itertools.izip(wordlist[i], wordlist[j]))
                  for j in xrange(len(wordlist))]
                  for i in xrange(len(wordlist))]
        possible = range(len(wordlist))
        n = 0
        while possible and n < 6:
            guess = solve(H, possible)
            n = master.guess(wordlist[guess])
            possible = [j for j in possible if H[guess][j] == n]


# Time:  O(n^2)
# Space: O(n)
class Solution2(object):
    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        def solve(H, possible):
            min_max_group, best_guess = possible, None
            for guess in possible:
                groups = [[] for _ in xrange(7)]
                for j in possible:
                    if j != guess:
                        groups[H[guess][j]].append(j)
                max_group = groups[0]
                if len(max_group) < len(min_max_group):
                    min_max_group, best_guess = max_group, guess
            return best_guess

        H = [[sum(a == b for a, b in itertools.izip(wordlist[i], wordlist[j]))
                  for j in xrange(len(wordlist))]
                  for i in xrange(len(wordlist))]
        possible = range(len(wordlist))
        n = 0
        while possible and n < 6:
            guess = solve(H, possible)
            n = master.guess(wordlist[guess])
            possible = [j for j in possible if H[guess][j] == n]
