// Time:  O(logf)
// Space: O(logf)

// math
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        const auto& count = [&](int64_t x) {
            int64_t result = 0;
            const auto& str_x = to_string(x);
            const int l = size(str_x) - size(s);
            int i = 0;
            for (int64_t base = powl(limit + 1, max(l - 1, 0)); i < l; ++i, base /= limit + 1) {
                result += (min((str_x[i] - '0') - 1, limit) - 0 + 1) * base;
                if (str_x[i] - '0' > limit) {
                    break;
                }
            }
            if (i == size(str_x) - size(s)) {
                if (stoll(str_x.substr(size(str_x) - size(s))) >= stoll(s)) {
                    ++result;
                }
            }
            return result;
        };

        return count(finish) - count(start - 1);
    }
};
