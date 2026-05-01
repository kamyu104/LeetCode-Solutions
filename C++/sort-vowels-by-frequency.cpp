// Time:  O(n)
// Space: O(1)

// freq table, sort
class Solution {
public:
    string sortVowels(string s) {
        static const string VOWELS = "aeiou";
    
        unordered_map<char, vector<int>> cnt;
        for (int i = 0; i < size(s); ++i) {
            if (VOWELS.find(s[i]) == string::npos) {
                continue;
            }
            if (!cnt.count(s[i])) {
                cnt[s[i]] = vector<int>{0, i};
            }
            ++cnt[s[i]][0];
        }
        vector<tuple<char, int, int>> sorted_cnt;
        for (const auto& [k, v] : cnt) {
            sorted_cnt.emplace_back(k, v[0], v[1]);
        }
        ranges::sort(sorted_cnt, [](const auto& a, const auto& b) {
            return get<1>(a) == get<1>(b) ? get<2>(a) > get<2>(b) : get<1>(a) < get<1>(b);
        });
        for (int i = 0; i < size(s); ++i) {
            if (VOWELS.find(s[i]) == string::npos) {
                continue;
            }
            s[i] = get<0>(sorted_cnt.back());
            if (!(--get<1>(sorted_cnt.back()))) {
                sorted_cnt.pop_back();
            }
        }
        return s;
    }
};
