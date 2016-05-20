// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || s.length() < t.length()) {
            return "";
        }

        const int ASCII_MAX = 256;
        vector<int> exp_cnt(ASCII_MAX, 0);
        vector<int> cur_cnt(ASCII_MAX, 0);

        int cnt = 0;
        int start = 0;
        int min_start = 0;
        int min_width = numeric_limits<int>::max();

        for (const auto& c : t) {
            ++exp_cnt[c];
        }

        for (int i = 0; i < s.length(); ++i) {
            if (exp_cnt[s[i]] > 0) {
                ++cur_cnt[s[i]];
                if (cur_cnt[s[i]] <= exp_cnt[s[i]]) {  // Counting expected elements.
                    ++cnt;
                }
            }
            if (cnt == t.size()) {  // If window meets the requirement.
                while (exp_cnt[s[start]] == 0 ||  // Adjust left bound of window.
                       cur_cnt[s[start]] > exp_cnt[s[start]]) {
                    --cur_cnt[s[start]];
                    ++start;
                }

                if (min_width > i - start + 1) {  // Update minimum window.
                    min_width = i - start + 1;
                    min_start = start;
                }
            }
        }

        if (min_width == numeric_limits<int>::max()) {
            return "";
        }

        return s.substr(min_start, min_width);
    }
};
