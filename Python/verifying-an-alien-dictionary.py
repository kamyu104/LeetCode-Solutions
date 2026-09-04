# Time:  O(n * l), l is the average length of words
# Space: O(1)

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        lookup = {}
        count = 0
        for char in order:
            lookup[char] = count + 1
            count+=1
            
        n = len(words)
        for i in range(n-1):
            word1 = words[i]
            word2 = words[i+1]
            n1 = len(word1)
            n2 = len(word2)
            n = min(n1, n2)
            count = 0
            for k in range(n):
                if word1[k] != word2[k]:
                    if lookup[word1[k]] > lookup[word2[k]]:
                        return False
                    break
                else:
                    count+=1
            if count == n and n1 > n2:
                return False
                    
        return True
