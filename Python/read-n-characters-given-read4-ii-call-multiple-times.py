# Time:  O(n)
# Space: O(1)

def read4(buf):
    global file_content
    i = 0
    while i < len(file_content) and i < 4:
        buf[i] = file_content[i]
        i += 1

    if len(file_content) > 4:
        file_content = file_content[4:]
    else:
        file_content = ""
    return i

# The read4 API is already defined for you.
# @param buf, a list of characters
# @return an integer
# def read4(buf):

class Solution(object):
    def __init__(self):
        self.__buf4 = [''] * 4
        self.__i4 = 0
        self.__n4 = 0

    def read(self, buf, n):
        """
        :type buf: Destination buffer (List[str])
        :type n: Maximum number of characters to read (int)
        :rtype: The number of characters read (int)
        """
        i = 0
        while i < n:
            if self.__i4 < self.__n4:  # Any characters in buf4.
                buf[i] = self.__buf4[self.__i4]
                i += 1
                self.__i4 += 1
            else:
                self.__n4 = read4(self.__buf4)  # Read more characters.
                if self.__n4:
                    self.__i4 = 0
                else:  # Buffer has been empty.
                    break

        return i

