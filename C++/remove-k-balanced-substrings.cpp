// Time:  O(n)
// Space: O(n)

// stack
class Solution {
public:
    string removeSubstring(string s, int k) {
        int cnt = 0;
        const auto& count = [&](char x) {
            if (x == '(') {
                if (cnt < k) {
                    ++cnt;
                } else if (cnt > k) {
                    cnt = 1;
                }
            } else {
                if (cnt >= k) {
                    ++cnt;
                } else {
                    cnt = 0;
                }
            }
        };

        string result;
        for (const auto& x : s) {
            result.push_back(x);
            count(x);
            if (cnt != 2 * k) {
                continue;
            }
            for (int _ = 0; _ < 2 * k; ++_) {
                result.pop_back();
            }
            cnt = 0;
            for (int i = max(static_cast<int>(size(result)) - (2 * k - 1), 0); i < size(result); ++i) {
                count(result[i]);
            }
        }
        return result;
    }
};
