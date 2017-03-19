# Time:  O(n * l) ~ O(n^2 * l^2)
# Space: O(n * l)

class Solution(object):
    def wordsAbbreviation(self, dict):
        """
        :type dict: List[str]
        :rtype: List[str]
        """
        def isUnique(prefix, words):
            return sum(word.startswith(prefix) for word in words) == 1
                        
        def toAbbr(prefix, word):
            abbr = prefix + str(len(word) - 1 - len(prefix)) + word[-1]
            return abbr if len(abbr) < len(word) else word

        abbr_to_word = collections.defaultdict(set)
        word_to_abbr = {}

        for word in dict:
            prefix = word[:1]
            abbr_to_word[toAbbr(prefix, word)].add(word)

        for abbr, conflicts in abbr_to_word.iteritems():
            if len(conflicts) > 1:
                for word in conflicts:
                    for i in xrange(2, len(word)):
                        prefix = word[:i]
                        if isUnique(prefix, conflicts):
                            word_to_abbr[word] = toAbbr(prefix, word)
                            break
            else:
                word_to_abbr[conflicts.pop()] = abbr

        return [word_to_abbr[word] for word in dict]
