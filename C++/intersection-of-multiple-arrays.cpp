// Time:  O(n * l + r), n = len(nums), l = len(nums[0])
// Space: O(r), r = max(nums)-min(nums)

// freq table, counting sort
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        static const int MAX_NUM = 1000;
        vector<int> cnt(MAX_NUM + 1);
        for (const auto& num : nums) {
            for (const auto& x : num) {
                ++cnt[x];
            }
        }
        vector<int> result;
        for (int i = 1; i <= MAX_NUM; ++i) {
            if (cnt[i] == size(nums)) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};

// Time:  O(n * l + r), n = len(nums), l = len(nums[0]), r = max(nums)-min(nums)
// Space: O(l)
// hash table, counting sort
class Solution2 {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_set<int> lookup(cbegin(nums[0]), cend(nums[0]));
        for (int i = 1; i < size(nums); ++i) {
            unordered_set<int> new_lookup;
            for (const auto& x : nums[i]) {
                if (lookup.count(x)) {
                    new_lookup.emplace(x);
                }
            }
            lookup = move(new_lookup);
        }
        if (empty(lookup)) {
            return {};
        }
        const int mn = *min_element(cbegin(lookup), cend(lookup));
        const int mx = *max_element(cbegin(lookup), cend(lookup));
        vector<int> result;
        for (int i = mn; i <= mx; ++i) {
            if (lookup.count(i)) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};

// Time:  O(n * l + llogl), n = len(nums), l = len(nums[0])
// Space: O(l)
// hash table, sort
class Solution3 {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_set<int> lookup(cbegin(nums[0]), cend(nums[0]));
        for (int i = 1; i < size(nums); ++i) {
            unordered_set<int> new_lookup;
            for (const auto& x : nums[i]) {
                if (lookup.count(x)) {
                    new_lookup.emplace(x);
                }
            }
            lookup = move(new_lookup);
        }
        vector<int> result(cbegin(lookup), cend(lookup));
        sort(begin(result), end(result));
        return result;
    }
};
