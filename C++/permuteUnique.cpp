// Time Complexity: O(n!)
// Space Complexity: O(n)

class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int>& num) {
            sort(num.begin(), num.end());
            unordered_map<int, int> count_map;
            for(auto e : num) {
                if (count_map.find(e) != count_map.end())
                    count_map[e]++;
                else
                    count_map[e] = 1;
            }

            vector<vector<int> > ans;
            vector<int> path;
            n = num.size();
            permute(count_map, path, ans);

            return ans;
        }

    private:
        size_t n;
        void permute(unordered_map<int, int> &count_map, vector<int> &path, vector<vector<int> > &ans) {
            if (n == path.size()) {
                ans.push_back(path);
            }

            for (auto i = count_map.begin(); i != count_map.end(); ++i) {
                if (i->second) {
                    path.push_back(i->first);
                    i->second--;
                    permute(count_map, path, ans);
                    path.pop_back();
                    i->second++;
                }
            }
        }
};
