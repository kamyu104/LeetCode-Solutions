// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    string concatHex36(int n) {
        static const string LOOKUP = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        const auto& convert = [](int n, int l) {
            string result;
            for (; n; n /= l) {
                result.push_back(LOOKUP[n % l]);
            }
            reverse(begin(result), end(result));
            return result;
        };

        return convert(n * n, 16) + convert(n * n * n, 36);
    }
};
