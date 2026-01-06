// Time:  O(n^4)
// Space: O(n)

// sort, brute force, hash table
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        ranges::sort(words);
        unordered_map<int, vector<int>> lookup;
        for (int i = 0; i < size(words); ++i) {
            lookup[words[i][0] - 'a'].emplace_back(i);
            lookup[(words[i][0] - 'a') + (words[i][3] - 'a' + 1) * 27].emplace_back(i);
        }
        vector<vector<string>> result;
        for (int i = 0; i < size(words); ++i) {
            for (const auto& j : lookup[words[i][0] - 'a']) {
                if (j == i) {
                    continue;
                }
                for (const auto& k : lookup[words[i][3] - 'a']) {
                    if (k == i || k == j) {
                        continue;
                    }
                    for (const auto& l : lookup[(words[j][3] - 'a') + (words[k][3] - 'a' + 1) * 27]) {
                        if (l == i || l == j || l == k) {
                            continue;
                        }
                        result.push_back({words[i], words[j], words[k], words[l]});
                    }
                }
            }
        }
        return result;
    }
};

// Time:  O(n^4)
// Space: O(1)
// sort, brute force
class Solution2 {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        ranges::sort(words);
        vector<vector<string>> result;
        for (int i = 0; i < size(words); ++i) {
            for (int j = 0; j < size(words); ++j) {
                if (j == i || words[j][0] != words[i][0]) {
                    continue;
                }
                for (int k = 0; k < size(words); ++k) {
                    if (k == i || k == j || words[k][0] != words[i][3]) {
                        continue;
                    }
                    for (int l = 0; l < size(words); ++l) {
                        if (l == i || l == j || l == k || words[l][0] != words[j][3] || words[l][3] != words[k][3]) {
                            continue;
                        }
                        result.push_back({words[i], words[j], words[k], words[l]});
                    }
                }
            }
        }
        return result;
    }
};
