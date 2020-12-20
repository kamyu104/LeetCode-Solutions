// Time:  O(n)
// Space: O(1)

// inplace solution
class Solution {
public:
    string reformatNumber(string number) {
        int src_len = 0;
        for (int i = 0; i < size(number); ++i) {  // remove non-digit characters
            if (isdigit(number[i])) {
                number[src_len++] = number[i];
            }
        }
        int dst_len = src_len + (src_len - 1) / 3;
        if (dst_len > size(number)) {  // make sure the size of result buffer is enough
            number.resize(dst_len);
        }
        for (int i = src_len - 1, curr = dst_len - 1, l = (3 - src_len % 3) % 3; i >= 0; --i, ++l) {
            if (l && l % 3 == 0) {  // group by 3 digits
                number[curr--] = '-';
            }
            number[curr--] = number[i];
        }
        if (dst_len >= 3 && number[dst_len - 2] == '-') {  // adjust for the 4 digits case
            swap(number[dst_len - 3], number[dst_len - 2]);
        }
        if (dst_len < size(number)) {  // resize the result buffer
            number.resize(dst_len);
        }
        return number;
    }
};
