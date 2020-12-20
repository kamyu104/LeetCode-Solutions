# Time:  O(n)
# Space: O(1)

# inplace solution
class Solution(object):
    def reformatNumber(self, number):
        """
        :type number: str
        :rtype: str
        """
        number = list(number)
        src_len = 0
        for c in number:  # remove non-digit characters
            if c.isdigit():
                number[src_len] = c
                src_len += 1
        dst_len = src_len + (src_len-1)//3
        if dst_len > len(number):  # resize the buffer to expected final size
            number.extend([0]*(dst_len-len(number)))
        while dst_len < len(number):
            number.pop()
        curr = dst_len-1
        for l, i in enumerate(reversed(xrange(src_len)), (3-src_len%3)%3):
            if l and l%3 == 0:  # group by 3 digits
                number[curr] = '-'
                curr -= 1
            number[curr] = number[i]
            curr -= 1
        if dst_len >= 3 and number[dst_len-2] == '-':  # adjust for the 4 digits case
            number[dst_len-3], number[dst_len-2] = number[dst_len-2], number[dst_len-3]            
        return "".join(number)
