// Time:  O(n * 2^n)
// Space: O(n^2)

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> seq;
        findSubsequencesHelper(nums, 0, &seq, &result);
        return result;
    }
    
    void findSubsequencesHelper(const vector<int>& nums, int i,
                                vector<int> *seq,
                                vector<vector<int>> *result) {
        if (seq->size() >= 2) {
            result->emplace_back(*seq);
        }
        unordered_set<int> lookup;
        for (; i < nums.size(); ++i) {
            if ((seq->empty() || nums[i] >= seq->back()) &&
                 lookup.find(nums[i]) == lookup.end()) {
                lookup.emplace(nums[i]);
                seq->emplace_back(nums[i]);
                findSubsequencesHelper(nums, i + 1, seq, result);
                seq->pop_back();
            }
        }
    }
};
