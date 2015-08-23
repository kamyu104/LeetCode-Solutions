// Time:  O(n * n!)
// Space: O(n)

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        if (s.empty()) {
            return {};
        }

        unordered_map<char, int> cnt;
        for (const auto& c : s) {
            ++cnt[c];
        }

        string mid, chars;
        for (const auto& kvp : cnt) {
            if (kvp.second % 2) {
                if (mid.empty()) {
                    mid.push_back(kvp.first);
                } else {  // The count of the middle char is at most one. 
                    return {};
                }
            }
            chars.append(kvp.second / 2, kvp.first);
        }
        return permuteUnique(mid, chars);
    }
    
    vector<string> permuteUnique(const string& mid, string& chars) {
        vector<string> result;
        sort(chars.begin(), chars.end());
        do {
            string reverse_chars(chars.crbegin(), chars.crend());
            result.emplace_back(chars + mid + reverse_chars);
        } while (next_permutation(chars.begin(), chars.end()));
        return result;
    }
};

class Solution2 {
public:
    vector<string> generatePalindromes(string s) {
        if (s.empty()) {
            return {};
        }

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

        return permuteUnique(mid, chars);
    }
    
    vector<string> permuteUnique(const string& mid, string& s) {
        vector<string> result;
        vector<bool> used(s.length(), false);
        string ans;

        sort(s.begin(), s.end());
        permuteUniqueRecu(mid, s, &used, &ans, &result);
        return result;
    }

    void permuteUniqueRecu(const string& mid, const string& s, vector<bool> *used,
                           string *ans, vector<string> *result) {
        if (ans->length() == s.length()) {
            string reverse_ans(ans->crbegin(), ans->crend());
            result->emplace_back(*ans + mid + reverse_ans);
            return;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (!(*used)[i] && !(i != 0 && s[i - 1] == s[i] && (*used)[i - 1])) {
                (*used)[i] = true;
                ans->push_back(s[i]);
                permuteUniqueRecu(mid, s, used, ans, result);
                ans->pop_back();
                (*used)[i] = false;
            }
        }
    }
};
