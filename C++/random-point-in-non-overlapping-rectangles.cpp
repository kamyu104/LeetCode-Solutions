// Time:  ctor: O(n)
//        pick: O(logn)
// Space: O(n)

class Solution {
public:
    Solution(vector<vector<int>> rects) :
        rects_(move(rects)),
        gen_{(random_device())()} {

        for (const auto& rect : rects_) {
            const auto width = rect[2] - rect[0] + 1;
            const auto height = rect[3] - rect[1] + 1;
            if (prefix_sum_.empty()) {
                prefix_sum_.emplace_back(width * height);
            } else {
                prefix_sum_.emplace_back(prefix_sum_.back() + width * height);
            }
        }
        uni_ = uniform_int_distribution<int>{0, prefix_sum_.back() - 1};
    }

    vector<int> pick() {
        const auto target = uni_(gen_);
        const auto left = distance(prefix_sum_.cbegin(),
                                   upper_bound(prefix_sum_.cbegin(),
                                               prefix_sum_.cend(),
                                               target));
        const auto& rect = rects_[left];
        const auto width = rect[2] - rect[0] + 1;
        const auto height = rect[3] - rect[1] + 1;
        const auto base = prefix_sum_[left] - width * height;
        return {rect[0] + (target - base) % width, rect[1] + (target - base) / width};
    }

private:
    const vector<vector<int>> rects_;
    vector<int> prefix_sum_;
    default_random_engine gen_;
    uniform_int_distribution<int> uni_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */
 
