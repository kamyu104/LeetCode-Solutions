# Time:  ctor:   O(n), n is number of words in the dictionary.
#        lookup: O(1)
# Space: O(k), k is number of unique words.

import collections


class ValidWordAbbr(object):
    def __init__(self, dictionary):
        """
        initialize your data structure here.
        :type dictionary: List[str]
        """
        self.lookup_ = collections.defaultdict(set)
        for word in dictionary:
            abbr = self.abbreviation(word)
            self.lookup_[abbr].add(word)


    def isUnique(self, word):
        """
        check if a word is unique.
        :type word: str
        :rtype: bool
        """
        abbr = self.abbreviation(word)
        return self.lookup_[abbr] <= {word}


    def abbreviation(self, word):
        if len(word) <= 2:
            return word
        return word[0] + str(len(word)-2) + word[-1]



