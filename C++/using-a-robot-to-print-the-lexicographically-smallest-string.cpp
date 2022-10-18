// Time:  O(n)
// Space: O(n)

// freq table, greedy
class Solution {
public:
    string robotWithString(string s) {
        vector<int> cnt(26);
        for (const auto& c : s){
            ++cnt[c - 'a'];
        }
        string result, stk;
        char mn = 'a';
        for (const auto& c : s) {
            stk.push_back(c);
            --cnt[c - 'a'];
            for (; mn < 'z' && cnt[mn - 'a'] == 0; ++mn);
            while (!empty(stk) && stk.back() <= mn) {
                result.push_back(stk.back());
                stk.pop_back();
            }
        }
        return result;
    }
};
