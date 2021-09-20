// Time:  O(n * (n/k)!)
// Space: O(n)

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> cnts(26);
        for (const auto& c : s) {
            ++cnts[c - 'a'];
        }
        string new_s;
        for (const auto& c : s) {
            if (cnts[c - 'a'] < k) {
                continue;
            }
            new_s.push_back(c);
        }
        string result, curr;
        backtracking(new_s, k, &curr, &cnts, &result);
        return result;
    }

private:    
    void backtracking(const string& s, int k, string *curr, vector<int> *cnts, string *result) {
        if (!check(s, k, *curr)) {
            return;
        }
        if (size(*curr) > size(*result)) {
            *result = *curr;
        }
        for (char c = 'z'; c >= 'a'; --c) {;
            if ((*cnts)[c -'a'] < k) {
                continue;
            }
            (*cnts)[c -'a'] -= k;
            curr->push_back(c);
            backtracking(s, k, curr, cnts, result);
            curr->pop_back();
            (*cnts)[c -'a'] += k;
        }
    }

    bool check(const string& s, int k, const string& curr) {
        if (empty(curr)) {
            return true;
        }
        int i = 0;
        for (const auto& c: s) {
            if (curr[i] != c || ++i != size(curr)) {
                continue;
            }
            i = 0, --k;
            if (k == 0) {
                return true;
            }
        }
        return false;
    }
};
