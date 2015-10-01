# Time:  ctor:   O(n), n is number of words in the dictionary. 
#        lookup: O(1)
# Space: O(k), k is number of unique words.

from sets import Set

class ValidWordAbbr(object):
    def __init__(self, dictionary):
        """
        initialize your data structure here.
        :type dictionary: List[str]
        """
        self.lookup_ = {}
        for word in dictionary:
            hash_word = self.hash(word)
            if hash_word not in self.lookup_:
                self.lookup_[hash_word] = Set([word])
            else:
                self.lookup_[hash_word].add(word)
        

    def isUnique(self, word):
        """
        check if a word is unique.
        :type word: str
        :rtype: bool
        """
        l = len(word)
        hash_word = self.hash(word)
        return hash_word not in self.lookup_ or \
               (word in self.lookup_[hash_word] and len(self.lookup_[hash_word]) == 1)


    def hash(self, word):
        return word[0] + str(len(word)) + word[-1]


# Your ValidWordAbbr object will be instantiated and called as such:
# vwa = ValidWordAbbr(dictionary)
# vwa.isUnique("word")
# vwa.isUnique("anotherWord")
