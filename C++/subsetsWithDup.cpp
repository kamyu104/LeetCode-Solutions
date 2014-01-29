// Time Complexity: O(2^n)
// Space Complexity: O(1)

class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            sort(S.begin(), S.end());
            vector<vector<int> > result(1);
            size_t previous_size = 0;
            for (size_t i = 0; i < S.size(); ++i) {
                const size_t size = result.size();
                for (size_t j = 0; j < size; ++j) {
                    // only union non-duplicate element or new union set 
                    if (i == 0 || S[i] != S[i-1] || j >= previous_size) { 
                        result.push_back(result[j]);
                        result.back().push_back(S[i]);
                    }
                }
                previous_size = size;
            }
            return result;
        }
};
