// Time:  O(n)
// Space: O(1)

class Solution {
public:
    long long numberOfSubstrings(string s) {
        unordered_map<char, int> cnt;
        int64_t result = 0;
        for (const auto& c : s) {
            result += ++cnt[c];
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    long long numberOfSubstrings(string s) {
        unordered_map<char, int64_t> cnt;
        
        for (const auto& c : s) {
            ++cnt[c];
        }
        int64_t result = 0;
        for (const auto& [_, v] : cnt) {
            result += v * (v + 1) / 2;
        }
        return result;
    }
};
