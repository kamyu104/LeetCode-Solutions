// Time:  O(n)
// Space: O(n)

// freq table
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string curr;
        const auto& check = [&](int i, int j) {
            return islower(chunks[i][j]) ||
                (chunks[i][j] == '-' &&
                 (!empty(curr) && islower(curr.back())) &&
                 ((j + 1 < size(chunks[i]) && islower(chunks[i][j + 1])) || (j + 1 == size(chunks[i]) && i + 1 < size(chunks) && islower(chunks[i + 1][0])))
                );
        };

        unordered_map<string, int> cnt;
        for (int i = 0; i < size(chunks); ++i) {
            for (int j = 0; j < size(chunks[i]); ++j) {
                if (check(i, j)) {
                    curr.push_back(chunks[i][j]);
                    continue;
                }
                if (!empty(curr)) {
                    ++cnt[curr];
                    curr.clear();
                }
            }
        }
        if (!empty(curr)) {
            ++cnt[curr];
            curr.clear();
        }
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            if (cnt.count(queries[i])) {
                result[i] = cnt[queries[i]];
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// freq table
class Solution2 {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;
        const auto& check = [&](int i) {
            return islower(s[i]) ||
                (s[i] == '-' &&
                 (i - 1 >= 0 && islower(s[i - 1])) &&
                 (i + 1 < size(s) && islower(s[i + 1]))
                );
        };

        for (const auto& x : chunks) {
            s += x;
        }
        string curr;
        unordered_map<string, int> cnt;
        for (int i = 0; i < size(s); ++i) {
            if (check(i)) {
                curr.push_back(s[i]);
                continue;
            }
            if (!empty(curr)) {
                ++cnt[curr];
                curr.clear();
            }
        }
        if (!empty(curr)) {
            ++cnt[curr];
            curr.clear();
        }
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            if (cnt.count(queries[i])) {
                result[i] = cnt[queries[i]];
            }
        }
        return result;
    }
};
