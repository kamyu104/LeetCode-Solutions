// Time:  O(n! * n * m)
// Space: O(n! * n)

// bi-bfs
class Solution {
public:
    int sortArray(vector<int>& nums, vector<int>& pre) {
        const auto& to_string = [](const auto& arr) {
            string result;
            result.reserve(size(arr));
            for (const auto& x : arr) {
                result.push_back('0' + x);
            }
            return result;
        };

        const auto& bi_bfs = [&](const auto& start, const auto& target) {
            unordered_set<string> left = {start}, right = {target}, lookup;
            for (int steps = 0; !empty(left); ++steps) {
                if (size(left) > size(right)) {
                    swap(left, right);
                }
                for (const auto& x : left) {
                    lookup.emplace(x);
                }
                unordered_set<string> new_left;
                for (auto x : left) {
                    if (right.count(x)) {
                        return steps;
                    }
                    for (const auto& i : pre) {
                        reverse(begin(x), begin(x) + i);
                        if (!lookup.count(x)) {
                            new_left.emplace(x);
                        }
                        reverse(begin(x), begin(x) + i);
                    }
                }
                left = move(new_left);
            }
            return -1;
        };

        vector<int> arr(size(nums));
        iota(begin(arr), end(arr), 0);
        return bi_bfs(to_string(nums), to_string(arr));
    }
};

// Time:  O(n! * n * m)
// Space: O(n! * n)
// bfs
class Solution2 {
public:
    int sortArray(vector<int>& nums, vector<int>& pre) {
        const auto& to_string = [](const auto& arr) {
            string result;
            result.reserve(size(arr));
            for (const auto& x : arr) {
                result.push_back('0' + x);
            }
            return result;
        };

        const auto& bfs = [&](const auto& start, const auto& target) {
            unordered_set<string> lookup = {start};
            vector<string> q = {start};
            for (int steps = 0; !empty(q); ++steps) {
                vector<string> new_q;
                for (auto x : q) {
                    if (x == target) {
                        return steps;
                    }
                    for (const auto& i : pre) {
                        reverse(begin(x), begin(x) + i);
                        if (!lookup.count(x)) {
                            lookup.emplace(x);
                            new_q.emplace_back(x);
                        }
                        reverse(begin(x), begin(x) + i);
                    }
                }
                q = move(new_q);
            }
            return -1;
        };

        vector<int> arr(size(nums));
        iota(begin(arr), end(arr), 0);
        return bfs(to_string(nums), to_string(arr));
    }
};
