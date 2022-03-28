// Time:  O(n * l)
// Space: O(1)

// math
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        const long long max_x = pow(10, (intLength + 1) / 2)  - 1;
        const auto& reverse = [](auto x) {
            decltype(x) result = 0;
            for (; x; x /= 10) {
                result = result * 10 + x % 10;
            }
            return result;
        };
        const auto& f = [&intLength, &max_x, &reverse](long long x) {
            x = pow(10, (intLength - 1) / 2) + (x - 1);
            if (x > max_x) {
                return -1ll;
            }
            return static_cast<long long>(x * pow(10, intLength / 2) + reverse(intLength % 2 ? x / 10 : x));
        };
        vector<long long> result;
        for (const auto& q : queries) {
            result.emplace_back(f(q));
        }
        return result;
    }
};
