# Time:  O(n)
# Space: O(n)

import collections
import itertools


class Solution(object):
    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        possible = range(len(wordlist))
        n = 0
        while n < 6:
            count = [collections.Counter(w[i] for w in wordlist) for i in xrange(6)]
            guess = max(possible, key=lambda x: sum(count[i][c] for i, c in enumerate(wordlist[x])))
            n = master.guess(wordlist[guess])
            possible = [j for j in possible if sum(a == b for a, b in itertools.izip(wordlist[guess], wordlist[j])) == n]


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
                max_group = max(groups, key=len)
                if len(max_group) < len(min_max_group):
                    min_max_group, best_guess = max_group, guess
            return best_guess

        H = [[sum(a == b for a, b in itertools.izip(wordlist[i], wordlist[j]))
                  for j in xrange(len(wordlist))]
                  for i in xrange(len(wordlist))]
        possible = range(len(wordlist))
        n = 0
        while n < 6:
            guess = solve(H, possible)
            n = master.guess(wordlist[guess])
            possible = [j for j in possible if H[guess][j] == n]


# Time:  O(n^2)
# Space: O(n)
class Solution3(object):
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
        while n < 6:
            guess = solve(H, possible)
            n = master.guess(wordlist[guess])
            possible = [j for j in possible if H[guess][j] == n]

