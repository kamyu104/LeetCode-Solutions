// Time:  O(n^3)
// Space: O(1)

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int len = num.size();
        int left, right, sum;
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        for (int i = 0; i < len - 3; ++i) {
            if (i && num[i] == num[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < len - 2; ++j) {
                if (j != i + 1 && num[j] == num[j - 1]) {
                    continue;
                }
                sum = target - num[i] - num[j];
                left = j + 1, right = len - 1;
                while (left < right) {
                    if (num[left] + num[right] == sum) {
                        res.emplace_back(move(vector<int>{num[i], num[j], num[left], num[right]}));
                        ++left, --right;
                        while (left < right && num[left] == num[left - 1]) {
                            ++left;
                        }
                        while (left < right && num[right] == num[right + 1]) {
                            --right;
                        }
                    } else {
                        if (num[left] + num[right] > sum) {
                            --right;
                        } else {
                            ++left;
                        }
                    }
                }
            }
        }
        return res;
    }
};

// Time:  O(n^4)
// Space: O(n^2)
class Solution2 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ans;
        if (num.size() < 4)  {
            return ans;
        }
        sort(num.begin(), num.end());
        unordered_multimap<int, pair<int, int>> cache;

        for (int i = 0; i < num.size(); ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                cache.emplace(num[i] + num[j], make_pair(i, j));
            }
        }

        for (auto i = cache.begin(); i != cache.end(); ++i) {
            auto a = i->second.first;
            auto b = i->second.second;
            int x = target - i->first;
            auto range = cache.equal_range(x);
            for (auto j = range.first; j != range.second; ++j) {
                auto c = j->second.first;
                auto d = j->second.second;
                if (b < c) {
                    ans.emplace_back(move(vector<int>{num[a], num[b], num[c], num[d]}));
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
