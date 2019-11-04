# Time:  O(logn)
# Space: O(logn)

class Solution(object):
    def confusingNumberII(self, N):
        """
        :type N: int
        :rtype: int
        """        
        lookup = {"0":"0", "1":"1", "6":"9", "8":"8", "9":"6"}
        centers = {"0":"0", "1":"1", "8":"8"}

        def totalCount(N):   
            s = str(N)
            total = 0 
            p = len(lookup)**(len(s)-1)
            for i in xrange(len(s)):
                if i+1 == len(s):
                    for c in lookup.iterkeys():
                        total += int(c <= s[i])
                    continue
                smaller = 0
                for c in lookup.iterkeys():
                    smaller += int(c < s[i])
                total += smaller * p
                if s[i] not in lookup:
                    break
                p //= len(lookup)
            return total

        def validCountInLessLength(N):
            s = str(N)
            valid = 0
            total = len(centers)
            for i in xrange(1, len(s), 2):
                if i == 1:
                    valid += total
                else:
                    valid += total * (len(lookup)-1)
                    total *= len(lookup)
            total = 1
            for i in xrange(2, len(s), 2):
                valid += total * (len(lookup)-1)
                total *= len(lookup)
            return valid

        def validCountInFullLength(N):
            s = str(N)
            half_s = s[:(len(s)+1)//2]
            total = 0
            p =  len(lookup)**(len(half_s)-2) * len(centers) if (len(s) % 2) else len(lookup)**(len(half_s)-1)
            choices = centers if (len(s) % 2) else lookup
            for i in xrange(len(half_s)):
                if i+1 == len(half_s):
                    for c in choices.iterkeys():
                        if c == '0' and i == 0:
                            continue
                        total += int(c < half_s[i])
                    if half_s[i] not in choices:
                        break
                    tmp = list(half_s)
                    for i in reversed(xrange(len(half_s)-(len(s) % 2))):
                        tmp.append(lookup[half_s[i]])
                    if int("".join(tmp)) <= N:
                        total += 1
                    continue

                smaller = 0
                for c in lookup.iterkeys():
                    if c == '0' and i == 0:
                        continue
                    smaller += int(c < half_s[i])
                total += smaller * p
                if half_s[i] not in lookup:
                    break
                p //= len(lookup)
            return total
            
        return totalCount(N) - validCountInLessLength(N) - validCountInFullLength(N)
