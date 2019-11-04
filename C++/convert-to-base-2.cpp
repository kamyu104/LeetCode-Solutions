// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    string baseNeg2(int N) {
        string result;
        while (N) {
            result += to_string(-N & 1);  // N % -2
            N = -(N >> 1);  // N /= -2
        }
        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }
};

// Time:  O(logn)
// Space: O(1)
class Solution2 {
public:
    string baseNeg2(int N) {
        static const int BASE = -2;
        string result;
        while (N) {
            int r = N % BASE;
            if (r < 0) {
                r -= BASE;
                ++N;
            }
            result += to_string(r);
            N /= BASE;
        }
        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }
};
