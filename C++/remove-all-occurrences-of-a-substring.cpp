// Time:  O(n + m)
// Space: O(n + m)

// kmp solution
class Solution {
public:
    string removeOccurrences(string s, string part) {
        const auto& prefix = getPrefix(part);
        string result;
        vector<int> lookup;
        int i = -1;
        for (const auto& c : s) {
            while (i != -1 && part[i + 1] != c) {
                i = prefix[i];
            }
            if (part[i + 1] == c) {
                ++i;
            }
            result.push_back(c);
            lookup.emplace_back(i);
            if (i == size(part) - 1) {
                result.resize(size(result) - size(part));
                lookup.resize(size(lookup) - size(part));
                i = !empty(lookup) ? lookup.back() : -1;
            }
        }
        return result;
    }

private:
    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(size(pattern), -1);
        int j = -1;
        for (int i = 1; i < size(pattern); ++i) {
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};
