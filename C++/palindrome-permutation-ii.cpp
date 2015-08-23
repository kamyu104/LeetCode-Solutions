// Time:  O(n * n!)
// Space: O(n)

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> cnt;
        for (const auto& c : s) {
            ++cnt[c];
        }

        string mid, chars;
        for (const auto& kvp : cnt) {
            if (kvp.second % 2) {
                if (mid.empty()) {
                    mid.append(1, kvp.first);
                } else {  // The count of the middle char is at most one. 
                    return {};
                }
            }
            chars.append(kvp.second / 2, kvp.first);
        }

        vector<string> result;
        sort(chars.begin(), chars.end());
        do {
            string reverse_chars(chars.crbegin(), chars.crend());
            result.emplace_back(chars + mid + reverse_chars);
        } while (next_permutation(chars.begin(), chars.end()));
        return result;
    }
};\
