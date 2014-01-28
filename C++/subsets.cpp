// Time Complexity: O(2^n)
// Space Complexity: O(1)

class Solution {
    public:
        vector<vector<int> > subsets(vector<int> &S) {
            const int size = S.size();
            const int setSize = 1 << size;
            vector<vector<int> > ans;
            vector<int> v;

            sort(S.begin(), S.end());

            for(int i = 0; i < setSize; ++i) {
                for(int j = 0; j < size; j++) {
                    if(i & (1 << j))
                        v.push_back(S[j]);
                }
                ans.push_back(v);
                v.clear();
            }

            return ans;
        }
};
