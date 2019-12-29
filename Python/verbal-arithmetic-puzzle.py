# Time:  O(10! * n * l)
# Space: O(n * l)

import collections


class Solution(object):
    def isSolvable(self, words, result):
        """
        :type words: List[str]
        :type result: str
        :rtype: bool
        """
        def backtracking(words, result, i, j, carry, lookup, used):
            if j == len(result):
                return carry == 0

            if i != len(words):
                if j >= len(words[i]) or words[i][j] in lookup:
                    return backtracking(words, result, i+1, j, carry, lookup, used)     
                for val in xrange(10):
                    if val in used or (val == 0 and j == len(words[i])-1):
                        continue
                    lookup[words[i][j]] = val
                    used.add(val)
                    if backtracking(words, result, i+1, j, carry, lookup, used):
                        return True
                    used.remove(val)
                    del lookup[words[i][j]]
                return False

            carry, val = divmod(carry + sum(lookup[w[j]] for w in words if j < len(w)), 10)
            if result[j] in lookup:
                return val == lookup[result[j]] and \
                       backtracking(words, result, 0, j+1, carry, lookup, used)
            if val in used or (val == 0 and j == len(result)-1):
                return False
            lookup[result[j]] = val
            used.add(val)
            if backtracking(words, result, 0, j+1, carry, lookup, used):
                return True
            used.remove(val)
            del lookup[result[j]]
            return False
        
        return backtracking([w[::-1] for w in words], result[::-1], 0, 0, 0, {}, set())


# Time:  O(10! * n * l)
# Space: O(n * l)
class Solution2(object):
    def isSolvable(self, words, result):
        """
        :type words: List[str]
        :type result: str
        :rtype: bool
        """
        def merge(A, B):
            result = []
            i, j = 0, 0
            while i != len(A) or j != len(B):
                if j == len(B) or (i != len(A) and A[i] < B[j]):
                    result.append(A[i])
                    i += 1
                else:
                    result.append(B[j])
                    j += 1
            return result

        def backtracking(words, result, i, j, carry, lookup, word_idxs, digits):
            if j == len(result):
                return carry == 0

            if i != len(word_idxs):
                if words[word_idxs[i]][j] in lookup:
                    return backtracking(words, result, i+1, j, carry, lookup, word_idxs, digits)
                for val in digits:
                    if val == 0 and j == len(words[word_idxs[i]])-1:
                        continue
                    lookup[words[word_idxs[i]][j]] = val
                    digits.remove(val)
                    if backtracking(words, result, i+1, j, carry, lookup, word_idxs, digits):
                        return True
                    digits.add(val)
                    del lookup[words[word_idxs[i]][j]]
                return False

            carry, val = divmod(carry + sum(lookup[w[j]] for w in words if j < len(w)), 10)
            if result[j] in lookup:
                restore = [k for k in word_idxs if j+1 >= len(words[k])]
                word_idxs[:] = [k for k in word_idxs if j+1 < len(words[k])]
                if val == lookup[result[j]] and \
                   backtracking(words, result, 0, j+1, carry, lookup, word_idxs, digits):
                    return True
                word_idxs[:] = merge(word_idxs, restore)
                return False

            if val not in digits or (val == 0 and j == len(result)-1):
                return False
            lookup[result[j]] = val
            restore = [k for k in word_idxs if j+1 >= len(words[k])]
            word_idxs[:] = [k for k in word_idxs if j+1 < len(words[k])]
            digits.remove(val)
            if backtracking(words, result, 0, j+1, carry, lookup, word_idxs, digits):
                return True
            digits.add(val)
            word_idxs[:] = merge(word_idxs, restore)
            del lookup[result[j]]
            return False
        
        return backtracking([w[::-1] for w in words], result[::-1], 0, 0, 0, {}, range(len(words)), set(range(10)))
