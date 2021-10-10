// Time:  O(n)
// Space: O(min(n, r)), r is the range size of nums

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        static const int K = 2;

        unordered_map<int, int> cnt;
        vector<int> result;
        for (const auto& nums : {&nums1, &nums2, &nums3}) {
            for (const auto& x : unordered_set<int>(cbegin(*nums), cend(*nums))) {
                if (++cnt[x] == K) {
                    result.emplace_back(x);
                }
            }
        }
        return result;
    }
};
