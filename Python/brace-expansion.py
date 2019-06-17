# Time:  O(p*l * log(p*l)), p is the production of all number of options
#                         , l is the length of a word
# Space: O(p*l)

class Solution(object):
    def expand(self, S):  # nested is fine
        """
        :type S: str
        :rtype: List[str]
        """
        def form_words(options):
            words = []
            total = 1
            for opt in options:
                total *= len(opt)
            for i in xrange(total):
                tmp = []
                for opt in reversed(options):
                    i, c = divmod(i, len(opt))
                    tmp.append(opt[c])
                tmp.reverse()
                words.append("".join(tmp))
            return words

        def generate_option(pattern, i):
            option_set = set()
            start = i[0]
            while i[0] != len(pattern) and pattern[i[0]] != "}":
                i[0] += 1  # { or ,
                for option in generate_words(pattern, i):
                    option_set.add(option)
            i[0] += 1  # }
            option = list(option_set)
            option.sort()
            return option

        def generate_words(pattern, i):
            start = i[0] 
            options = []
            while i[0] != len(pattern) and pattern[i[0]] not in ",}":
                tmp = []
                if pattern[i[0]] not in "{,}":
                    tmp.append(pattern[i[0]])
                    i[0] += 1  # a-z
                elif pattern[i[0]] == "{":
                    tmp = generate_option(pattern, i)
                options.append(tmp)
            return form_words(options)

        return generate_words(S, [0])
