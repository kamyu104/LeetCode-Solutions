// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int balancedString(string s) {
        unordered_map<int, int> count;
        for (const auto& c : s) {
            ++count[c];
        }
        int result = s.length();
        int left = 0;
        for (int right = 0; right < s.length(); ++right) {
            --count[s[right]];
            while (left < s.length() &&
                   all_of(count.cbegin(), count.cend(),
                          [&s](const auto& kvp) {
                              return kvp.second <= s.length() / 4;
                          })) {
                result = min(result, right - left + 1);
                ++count[s[left++]];
            }
        }
        return result;
    }
};
