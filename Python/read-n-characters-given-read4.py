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
# The read function will only be called once for each test case.
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
    # @param buf, Destination buffer (a list of characters)
    # @param n,   Maximum number of characters to read (an integer)
    # @return     The number of characters read (an integer)
    def read(self, buf, n):
        read_bytes = 0
        eof = False
        buffer = ['' for _ in xrange(4)]
        while not eof and read_bytes < n:
            size = read4(buffer)
            if size < 4:
                eof = True
            bytes = min(n - read_bytes, size)
            for i in xrange(bytes):
                buf[read_bytes + i] = buffer[i]
            read_bytes += bytes
        return read_bytes

if __name__ == "__main__":
    global file_content
    buf = ['' for _ in xrange(100)]
    file_content = "a"
    print buf[:Solution().read(buf, 9)]    
    file_content = "abcdefghijklmnop"
    print buf[:Solution().read(buf, 9)]