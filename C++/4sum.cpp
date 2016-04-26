// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        int len = nums.size();
        int left, right, sum;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i = 0; i < len - 3; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < len - 2; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                sum = target - nums[i] - nums[j];
                left = j + 1, right = len - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == sum) {
                        tmp.clear();
                        tmp.emplace_back(nums[i]);
                        tmp.emplace_back(nums[j]);
                        tmp.emplace_back(nums[left]);
                        tmp.emplace_back(nums[right]);
                        res.emplace_back(tmp);
                        left++, right--;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                    } else {
                        if (nums[left] + nums[right] > sum) {
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

        for (int i = 0; i + 1 < num.size(); ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                cache.emplace(num[i] + num[j], make_pair(i, j));
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
