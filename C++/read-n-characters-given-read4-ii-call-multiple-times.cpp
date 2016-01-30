// Time:  O(n)
// Space: O(1)

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n) {
            if (i4_ < n4_) {  // Any characters in buf4.
                buf[i++] = buf4_[i4_++];
            } else if (n4_ = read4(buf4_)) {  // Read more characters.
                i4_ = 0;
            } else {  // Buffer has been empty.
                break;
            }
        }
        return i;
    }

private:
    char buf4_[4];
    int i4_ = 0, n4_ = 0;
};
