# Time:  O(n^2 * l) ~ O(n * l^4)
# Space: O(n) ~ O(n * l^3)

# Two strings X and Y are similar if we can swap two letters
# (in different positions) of X, so that it equals Y.
#
# For example, "tars" and "rats" are similar (swapping at positions 0 and 2),
# and "rats" and "arts" are similar, but "star" is not similar to
# "tars", "rats", or "arts".
#
# Together, these form two connected groups by similarity:
# {"tars", "rats", "arts"} and {"star"}.
# Notice that "tars" and "arts" are in the same group
# even though they are not similar.
# Formally, each group is such that a word is in the group
# if and only if it is similar
# to at least one other word in the group.
#
# We are given a list A of unique strings.
# Every string in A is an anagram of every other string in A.
# How many groups are there?
#
# Example 1:
#
# Input: ["tars","rats","arts","star"]
# Output: 2
#
# Note:
# - A.length <= 2000
# - A[i].length <= 1000
# - A.length * A[i].length <= 20000
# - All words in A consist of lowercase letters only.
# - All words in A have the same length and are anagrams of each other.
# - The judging time limit has been increased for this question.

import collections
import itertools

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class UnionFind(object):
    def __init__(self, n):
        self.set = range(n)
        self.__size = n

    def find_set(self, x):
        if self.set[x] != x:
            self.set[x] = self.find_set(self.set[x])  # path compression.
        return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return False
        self.set[min(x_root, y_root)] = max(x_root, y_root)
        self.__size -= 1
        return True

    def size(self):
        return self.__size


class Solution(object):
    def numSimilarGroups(self, A):
        def isSimilar(a, b):
            diff = 0
            for x, y in itertools.izip(a, b):
                if x != y:
                    diff += 1
                    if diff > 2:
                        return False
            return diff == 2

        N, L = len(A), len(A[0])
        union_find = UnionFind(N)
        if N < L*L:
            for (i1, word1), (i2, word2) in \
                    itertools.combinations(enumerate(A), 2):
                if isSimilar(word1, word2):
                    union_find.union_set(i1, i2)
        else:
            buckets = collections.defaultdict(list)
            lookup = set()
            for i in xrange(len(A)):
                word = list(A[i])
                if A[i] not in lookup:
                    buckets[A[i]].append(i)
                    lookup.add(A[i])
                for j1, j2 in itertools.combinations(xrange(L), 2):
                    word[j1], word[j2] = word[j2], word[j1]
                    buckets["".join(word)].append(i)
                    word[j1], word[j2] = word[j2], word[j1]
            for word in A:  # Time:  O(n * l^4)
                for i1, i2 in itertools.combinations(buckets[word], 2):
                    union_find.union_set(i1, i2)
        return union_find.size()
