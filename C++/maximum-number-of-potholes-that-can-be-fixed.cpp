// Time:  O(n)
// Space: O(n)

// counting sort, greedy
class Solution {
public:
    int maxPotholes(string road, int budget) {
        const auto& inplace_counting_sort = [](auto& nums, bool is_reverse) {
            if (empty(nums)) {
                return;
            }
            const int max_num = *max_element(cbegin(nums), cend(nums));
            vector<int> count(max_num + 1);
            for (const auto& num : nums) {
                ++count[num];
            }
            for (int i = 1; i < size(count); ++i) {
                count[i] += count[i - 1];
            }
            for (int i = size(nums) - 1; i >= 0; --i) {  // inplace but unstable sort
                while (nums[i] >= 0) {
                    --count[(nums)[i]];
                    const int j = count[(nums)[i]];
                    tie(nums[i], nums[j]) = pair(nums[j], ~nums[i]);
                }
            }
            for (auto& num : nums) {
                num = ~num;  // restore values
            }
            if (is_reverse) {  // unstable sort
                reverse(begin(nums), end(nums));
            }
        };

        vector<int> ls;
        for (int i = 0, l = 0; i < size(road); ++i) {
            ++l;
            if (i + 1 == size(road) || road[i + 1] != road[i]) {
                if (road[i] == 'x') {
                    ls.emplace_back(l);
                }
                l = 0;
            }
        }
        inplace_counting_sort(ls, false);
        int result = 0;
        for (int i = size(ls) - 1; i >= 0; --i) {
            const int c = min(ls[i] + 1, budget);
            if (c - 1 <= 0) {
                break;
            }
            result += c - 1;
            budget -= c;
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, greedy
class Solution2 {
public:
    int maxPotholes(string road, int budget) {
        vector<int> ls;
        for (int i = 0, l = 0; i < size(road); ++i) {
            ++l;
            if (i + 1 == size(road) || road[i + 1] != road[i]) {
                if (road[i] == 'x') {
                    ls.emplace_back(l);
                }
                l = 0;
            }
        }
        sort(begin(ls), end(ls));
        int result = 0;
        for (int i = size(ls) - 1; i >= 0; --i) {
            const int c = min(ls[i] + 1, budget);
            if (c - 1) {
                break;
            }
            result += c - 1;
            budget -= c;
        }
        return result;
    }
};
