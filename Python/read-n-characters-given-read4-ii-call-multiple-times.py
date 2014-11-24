# Time:  O(n)
# Space: O(1)
#
# The API: int read4(char *buf) reads 4 characters at a time from a file.
# 
# The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
# 
# By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
# 
# Note:
# The read function may be called multiple times.
#

# The read4 API is already defined for you.
# @param buf, a list of characters
# @return an integer
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
        
class Solution:
    def __init__(self):
        self.buffer_size, self.offset = 0, 0
        self.buffer = [None for _ in xrange(4)]
    
    # @param buf, Destination buffer (a list of characters)
    # @param n,   Maximum number of characters to read (an integer)
    # @return     The number of characters read (an integer)
    def read(self, buf, n):
        read_bytes = 0
        eof = False
        while not eof and read_bytes < n:
            if self.buffer_size == 0:
                size = read4(self.buffer)
            else:
                size = self.buffer_size
            if self.buffer_size == 0 and size < 4:
                eof = True   
            bytes = min(n - read_bytes, size)
            for i in xrange(bytes):
                buf[read_bytes + i] = self.buffer[self.offset + i]
            self.offset = (self.offset + bytes) % 4
            self.buffer_size = size - bytes
            read_bytes += bytes
        return read_bytes

if __name__ == "__main__":
    global file_content
    sol = Solution()
    buf = ['' for _ in xrange(100)]
    file_content = "ab"
    print buf[:sol.read(buf, 1)]
    print buf[:sol.read(buf, 2)]    
