// Time:  O(n^4 * n!)
// Space: O(n * n!)

// bfs
class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        const auto& bfs = [](const auto& start, const auto& target) {
            const auto& join = [](const auto& vals, const char delim = ',') {
                string result;
                for (const auto& x : vals) {
                    result += to_string(x);
                    result.push_back(delim);
                }
                return result;
            };

            int d = 0;
            if (start == target) {
                return d;
            }
            unordered_set<string> lookup = {join(start)};
            vector<vector<int>> q = {start};
            ++d;
            for (; !empty(q); ++d) {
                vector<vector<int>> new_q;
                for (const auto& u : q) {
                    for (int l = 0; l < size(u); ++l) {
                        for (int r = l; r < size(u); ++r) {
                            vector<int> sub(cbegin(u) + l, cbegin(u) + (r + 1));
                            vector<int> rem(cbegin(u) , cbegin(u) + l);
                            rem.insert(end(rem), cbegin(u) + (r + 1), cend(u));
                            for (int i = 0; i <= size(rem); ++i) {
                                if (i == l) {
                                    continue;
                                }
                                vector<int> v = rem;
                                v.insert(begin(v) + i, cbegin(sub), cend(sub));
                                const auto& key = join(v);
                                if (lookup.count(key)) {
                                    continue;
                                }
                                if (v == target) {
                                    return d;
                                }
                                lookup.emplace(key);
                                new_q.emplace_back(v);
                            }
                        }
                    }
                }
                q = move(new_q);
            }
            return -1;
        };

        return bfs(nums1, nums2);
    }
};

// Time:  O(n^4 * n!)
// Space: O(n * n!)
// bfs
class Solution2 {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        const auto& bfs = [](const auto& start, const auto& target) {
            const auto& join = [](const vector<int>& vals, const char delim = ',') {
                string result;
                for (const auto& x : vals) {
                    result += to_string(x);
                    result.push_back(delim);
                }
                return result;
            };

            unordered_set<string> lookup = {join(start)};
            vector<vector<int>> q = {start};
            for (int d = 0; !empty(q); ++d) {
                vector<vector<int>> new_q;
                for (const auto& u : q) {
                    if (u == target) {
                        return d;
                    }
                    for (int l = 0; l < size(u); ++l) {
                        for (int r = l; r < size(u); ++r) {
                            vector<int> sub(cbegin(u) + l, cbegin(u) + (r + 1));
                            vector<int> rem(cbegin(u) , cbegin(u) + l);
                            rem.insert(end(rem), cbegin(u) + (r + 1), cend(u));
                            for (int i = 0; i <= size(rem); ++i) {
                                if (i == l) {
                                    continue;
                                }
                                vector<int> v = rem;
                                v.insert(begin(v) + i, cbegin(sub), cend(sub));
                                const auto& key = join(v);
                                if (lookup.count(key)) {
                                    continue;
                                }
                                lookup.emplace(key);
                                new_q.emplace_back(v);
                            }
                        }
                    }
                }
                q = move(new_q);
            }
            return -1;
        };

        return bfs(nums1, nums2);
    }
};
