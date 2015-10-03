# Time:  ctor:   O(n), n is number of words in the dictionary. 
#        lookup: O(1)
# Space: O(k), k is number of unique words.

class ValidWordAbbr(object):
    def __init__(self, dictionary):
        """
        initialize your data structure here.
        :type dictionary: List[str]
        """
        self.lookup_ = collections.defaultdict(set)
        for word in dictionary:
            abbr = self.abbr(word)
            self.lookup_[abbr].add(word)
            

    def isUnique(self, word):
        """
        check if a word is unique.
        :type word: str
        :rtype: bool
        """
        l = len(word)
        abbr = self.abbr(word)
        return self.lookup_[abbr] <= {word}


    def abbr(self, word):
        return word[0] + str(len(word)) + word[-1]


# Your ValidWordAbbr object will be instantiated and called as such:
# vwa = ValidWordAbbr(dictionary)
# vwa.isUnique("word")
# vwa.isUnique("anotherWord")
