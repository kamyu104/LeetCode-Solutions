// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int pos = 0;
        for (const auto& group : groups) {
            pos = KMP(nums, group, pos);
            if (pos == -1) {
                return false;
            }
            pos += size(group);
        }
        return true;
    }

private:
    int KMP(const vector<int>& text, const vector<int>& pattern, int start) {
        const auto& prefix = getPrefix(pattern);
        int j = -1;
        for (int i = start; i < size(text); ++i) {
            while (j + 1 > 0 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j + 1 == size(pattern)) {
                return i - j;
            }
        }
        return -1;
    }

    vector<int> getPrefix(const vector<int>& pattern) {
        vector<int> prefix(size(pattern), -1);
        int j = -1;
        for (int i = 1; i < size(pattern); ++i) {
            while (j + 1 > 0 && pattern[j + 1] != pattern[i]) {
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

// Time:  O(n * m)
// Space: O(1)
class Solution2 {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        auto cit = cbegin(nums);
        for (const auto& group: groups) {
            cit = search(cit, cend(nums), cbegin(group), cend(group));
            if (cit == cend(nums)) {
                return false;
            }
            cit += size(group);
        }
        return true;
    }
};
