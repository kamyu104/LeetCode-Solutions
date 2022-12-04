// Time:  O(n)
// Space: O(n)

// freq table, prefix sum
class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
        unordered_map<int, int> lookup;
        lookup[0] = 1;
        int64_t result = 0, curr = 0;
        for (const auto& c : s) {
            curr += c == '0' ? -num2 : +num1;
            result += lookup[curr];
            ++lookup[curr];
        }
        return result;
    }
};
