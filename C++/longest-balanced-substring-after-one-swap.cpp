// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int longestBalanced(string s) {
        int cnt0 = count(cbegin(s), cend(s), '0');
        int cnt1 = size(s) - cnt0;
        if (cnt0 < cnt1) {
            swap(cnt0, cnt1);
            for (auto& x : s) {
                x = (x == '1') ? '0' : '1';
            }
        }
        unordered_map<int, vector<int>> lookup;
        lookup[0] = {-1};
        int result = 0;
        for (int i = 0, bal = 0; i < size(s); i++) {
            bal += s[i] == '1' ? +1 : -1;
            if (size(lookup[bal]) != 2) {
                lookup[bal].emplace_back(i);
            }
            result = max(result, i - lookup[bal][0]);     
            for (const auto& j : lookup[bal + 2]) {
                if ((i - j - 2) / 2 <= cnt1 - 1) {
                    result = max(result, i - j);
                }
            }
        }
        return result;
    }
};
