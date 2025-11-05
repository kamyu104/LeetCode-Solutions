// Time:  O(26 * n)
// Space: O(26)

// freq table, greedy
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        int c = 0;
        for (int i = 0; i < size(cnt); ++i) {
            c += cnt[i] % 2;
        }
        if (c > 1) {
            return "";
        }
        int x = -1;
        if (size(s) % 2) {
            for (int i = 0; i < size(cnt); ++i) {
                if (cnt[i] % 2) {
                    x = i;
                    --cnt[i];
                    break;
                }
            }
        }
        string result;
        int i = 0;
        for (; i < size(target) / 2; ++i) {
            cnt[target[i] - 'a'] -= 2;
            result.push_back(target[i]);
            if (cnt[target[i] - 'a'] < 0) {
                break;
            }
        }
        if (i == size(target) / 2) {
            if (size(target) % 2) {
                result.push_back('a' + x);
            }
            string ret(result);
            copy(crbegin(result) + (size(target) % 2), crend(result), std::back_inserter(ret));
            if (ret > target) {
                return ret;
            }
            if (size(target) % 2) {
                result.pop_back();
            }
        }
        while (!empty(result)) {
            const auto& c = result.back() - 'a'; result.pop_back();
            cnt[c] += 2;
            for (int i = c + 1; i < size(cnt); ++i) {
                if (!cnt[i]) {
                    continue;
                }
                cnt[i] -= 2;
                result.push_back('a' + i);
                for (int j = 0; j < size(cnt); ++j) {
                    if (!cnt[j]) {
                        continue;
                    }
                    while (cnt[j]) {
                        cnt[j] -= 2;
                        result.push_back('a' + j);
                    }
                    
                }
                if (size(target) % 2) {
                    result.push_back('a' + x);
                }
                string ret(result);
                copy(crbegin(result) + (size(target) % 2), crend(result), std::back_inserter(ret));
                return ret;
            }
        }
        return "";
    }
};
