// Time:  O(n)
// Space: O(n)

// mono stack
class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        const auto& count = [](const auto& right, const auto& l) {
            const auto left = max(right - l + 1, static_cast<int64_t>(0));
            return (left + right) * (right - left + 1) / 2;
        };

        int64_t result = 0;
        vector<int64_t> stk = {-1};
        for (int64_t i = 0, curr = 0; i < size(books); ++i) {
            while (stk.back() != -1 && books[stk.back()] >= books[i] - (i - stk.back())) {
                const int j = stk.back(); stk.pop_back();
                curr -= count(books[j], j - stk.back());
            }
            curr += count(books[i], i - stk.back());
            stk.emplace_back(i);
            result = max(result, curr);
        }
        return result;
    }
};
