// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ans;
        if (num.size() < 4) 
            return ans;
        sort(num.begin(), num.end());
        unordered_multimap<int, pair<int, int>> cache;

        for (int i = 0; i + 1 < num.size(); ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                cache.insert(make_pair(num[i] + num[j], make_pair(i, j)));
            }
        }

        for (auto i = cache.begin(); i != cache.end(); ++i) {
            int x = target - i->first;
            auto range = cache.equal_range(x);
            for (auto j = range.first; j != range.second; ++j) {
                auto a = i->second.first;
                auto b = i->second.second;
                auto c = j->second.first;
                auto d = j->second.second;
                if (b < c) {
                    ans.push_back({num[a], num[b], num[c], num[d]});
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
