// Time:  O(nloga)
// Space: O(n)

// optimized from Solution3
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        for (int i = 0; i < size(scores); ++i) {
            players.emplace_back(scores[i], ages[i]);
        }
        sort(begin(players), end(players));
        set<int> sorted_ages(cbegin(ages), cend(ages));
        unordered_map<int, int> lookup;
        for (const auto& age : sorted_ages) {
            lookup[age] = size(lookup);
        }
        SegmentTree segment_tree(size(lookup));
        int result = 0;
        for (const auto& [score, age] : players) {
            segment_tree.update(lookup[age], lookup[age], segment_tree.query(0, lookup[age]) + score);
        }
        return segment_tree.query(0, size(lookup) - 1);
    }

private:
    class SegmentTree {
    public:
        SegmentTree(int N)
            : N_(N),
              tree_(2 * N),
              lazy_(N)
        {
            H_ = 1;
            while ((1 << H_) < N) {
                ++H_;
            }
        }

        void update(int L, int R, int h) {
            L += N_; R += N_;
            int L0 = L, R0 = R;
            while (L <= R) {
                if ((L & 1) == 1) {
                    apply(L++, h);
                }
                if ((R & 1) == 0) {
                    apply(R--, h);
                }
                L >>= 1; R >>= 1;
            }
            pull(L0); pull(R0);
        }

        int query(int L, int R) {
            L += N_; R += N_;
            auto result = 0;
            push(L); push(R);
            while (L <= R) {
                if ((L & 1) == 1) {
                    result = max(result, tree_[L++]);
                }
                if ((R & 1) == 0) {
                    result = max(result, tree_[R--]);
                }
                L >>= 1; R >>= 1;
            }
            return result;
        }

    private:
        int N_, H_;
        vector<int> tree_, lazy_;

        void apply(int x, int val) {
            tree_[x] = max(tree_[x], val);
            if (x < N_) {
                lazy_[x] = max(lazy_[x], val);
            }
        }

        void pull(int x) {
            while (x > 1) {
                x >>= 1;
                tree_[x] = max(tree_[x * 2], tree_[x * 2 + 1]);
                tree_[x] = max(tree_[x], lazy_[x]);
            }
        }

        void push(int x) {
            for (int h = H_; h > 0; --h) {
                int y = x >> h;
                if (lazy_[y] > 0) {
                    apply(y * 2, lazy_[y]);
                    apply(y * 2 + 1, lazy_[y]);
                    lazy_[y] = 0;
                }
            }
        }
    };
};

// Time:  O(nlogs)
// Space: O(n)
// optimized from Solution4
class Solution2 {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        for (int i = 0; i < size(scores); ++i) {
            players.emplace_back(ages[i], scores[i]);
        }
        sort(begin(players), end(players));
        set<int> sorted_scores(cbegin(scores), cend(scores));
        unordered_map<int, int> lookup;
        for (const auto& score : sorted_scores) {
            lookup[score] = size(lookup);
        }
        SegmentTree segment_tree(size(lookup));
        int result = 0;
        for (const auto& [age, score] : players) {
            segment_tree.update(lookup[score], lookup[score], segment_tree.query(0, lookup[score]) + score);
        }
        return segment_tree.query(0, size(lookup) - 1);
    }

private:
    class SegmentTree {
    public:
        SegmentTree(int N)
            : N_(N),
              tree_(2 * N),
              lazy_(N)
        {
            H_ = 1;
            while ((1 << H_) < N) {
                ++H_;
            }
        }

        void update(int L, int R, int h) {
            L += N_; R += N_;
            int L0 = L, R0 = R;
            while (L <= R) {
                if ((L & 1) == 1) {
                    apply(L++, h);
                }
                if ((R & 1) == 0) {
                    apply(R--, h);
                }
                L >>= 1; R >>= 1;
            }
            pull(L0); pull(R0);
        }

        int query(int L, int R) {
            L += N_; R += N_;
            auto result = 0;
            push(L); push(R);
            while (L <= R) {
                if ((L & 1) == 1) {
                    result = max(result, tree_[L++]);
                }
                if ((R & 1) == 0) {
                    result = max(result, tree_[R--]);
                }
                L >>= 1; R >>= 1;
            }
            return result;
        }

    private:
        int N_, H_;
        vector<int> tree_, lazy_;

        void apply(int x, int val) {
            tree_[x] = max(tree_[x], val);
            if (x < N_) {
                lazy_[x] = max(lazy_[x], val);
            }
        }

        void pull(int x) {
            while (x > 1) {
                x >>= 1;
                tree_[x] = max(tree_[x * 2], tree_[x * 2 + 1]);
                tree_[x] = max(tree_[x], lazy_[x]);
            }
        }

        void push(int x) {
            for (int h = H_; h > 0; --h) {
                int y = x >> h;
                if (lazy_[y] > 0) {
                    apply(y * 2, lazy_[y]);
                    apply(y * 2 + 1, lazy_[y]);
                    lazy_[y] = 0;
                }
            }
        }
    };
};

// Time:  O(n * a)
// Space: O(n)
// optimized from Solution5
class Solution3 {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        for (int i = 0; i < size(scores); ++i) {
            players.emplace_back(scores[i], ages[i]);
        }
        sort(begin(players), end(players));
        set<int> sorted_ages(cbegin(ages), cend(ages));
        unordered_map<int, int> dp;
        int result = 0;
        for (const auto& [score, age] : players) {
            int max_score = 0;
            for (const auto& a : sorted_ages) {
                if (a > age) {
                    break;
                }
                max_score = max(max_score, dp[a]);
            }
            dp[age] = max_score + score;
            result = max(result, dp[age]);
        }
        return result;
    }
};

// Time:  O(n * s)
// Space: O(n)
// optimized from Solution6
class Solution4 {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        for (int i = 0; i < size(scores); ++i) {
            players.emplace_back(ages[i], scores[i]);
        }
        sort(begin(players), end(players));
        set<int> sorted_scores(cbegin(scores), cend(scores));
        unordered_map<int, int> dp;
        int result = 0;
        for (const auto& [age, score] : players) {
            int max_score = 0;
            for (const auto& s : sorted_scores) {
                if (s > score) {
                    break;
                }
                max_score = max(max_score, dp[s]);
            }
            dp[score] = max_score + score;
            result = max(result, dp[score]);
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// longest_increasing_subsequence like dp solution
class Solution5 {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        for (size_t i = 0; i < scores.size(); ++i) {
            players.emplace_back(scores[i], ages[i]);
        }
        sort(begin(players), end(players));
        vector<int> dp(size(scores));
        int result = 0;
        for (int i = 0; i < size(players); ++i) {
            dp[i] = players[i].first;
            for (int j = 0; j < i; ++j) {
                if (players[j].second <= players[i].second) {
                    dp[i] = max(dp[i], dp[j] + players[i].first);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// longest_increasing_subsequence like dp solution
class Solution6 {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        for (size_t i = 0; i < scores.size(); ++i) {
            players.emplace_back(ages[i], scores[i]);
        }
        sort(begin(players), end(players));
        vector<int> dp(size(scores));
        int result = 0;
        for (int i = 0; i < size(players); ++i) {
            dp[i] = players[i].second;
            for (int j = 0; j < i; ++j) {
                if (players[j].second <= players[i].second) {
                    dp[i] = max(dp[i], dp[j] + players[i].second);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
