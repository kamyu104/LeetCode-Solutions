from sets import Set

class ValidWordAbbr(object):
    def __init__(self, dictionary):
        """
        initialize your data structure here.
        :type dictionary: List[str]
        """
        self.lookup_ = {}
        for word in dictionary:
            hash_val = word[0] + str(len(word)) + word[-1]
            if hash_val not in self.lookup_:
                self.lookup_[hash_val] = Set([word])
            else:
                self.lookup_[hash_val].add(word)
        

    def isUnique(self, word):
        """
        check if a word is unique.
        :type word: str
        :rtype: bool
        """
        l = len(word)
        hash_val = word[0] + str(len(word)) + word[-1]
        return hash_val not in self.lookup_ or \
               (word in self.lookup_[hash_val] and len(self.lookup_[hash_val]) == 1)


# Your ValidWordAbbr object will be instantiated and called as such:
# vwa = ValidWordAbbr(dictionary)
# vwa.isUnique("word")
# vwa.isUnique("anotherWord")
