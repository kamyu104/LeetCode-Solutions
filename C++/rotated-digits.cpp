// Time:  O(logn)
// Space: O(logn)

// memoization (top-down dp)
class Solution {
private:
    template <typename A, typename B, typename C>
    struct TupleHash {
        size_t operator()(const tuple<A, B, C>& p) const {
            size_t seed = 0;
            A a; B b; C c;
            tie(a, b, c) = p;
            seed ^= std::hash<A>{}(a) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<B>{}(b) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<C>{}(c) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
    
public:
    int rotatedDigits(int N) {
        vector<int> A;
        for (; N; N /= 10) {
            A.emplace_back(N % 10);
        }
        reverse(A.begin(), A.end());
        unordered_map<tuple<int, bool, bool>, int, TupleHash<int, bool, bool>> lookup;
        return dp(A, 0, true, false, &lookup);
    }

private:
    int dp(const vector<int>& A, int i, bool is_prefix_equal, bool is_good,
           unordered_map<tuple<int, bool, bool>, int, TupleHash<int, bool, bool>> *lookup) {
        if (i == A.size()) {
            return static_cast<int>(is_good);
        }
        if (!lookup->count(make_tuple(i, is_prefix_equal, is_good))) {
            const auto& ceil = is_prefix_equal ? A[i] + 1 : 10;
            int result = 0;
            for (int d = 0; d < ceil; ++d) {
                if (invalid.count(d)) continue;
                result += dp(A, i + 1,
                             is_prefix_equal && d == A[i],
                             is_good || diff.count(d),
                             lookup);
            }
            (*lookup)[make_tuple(i, is_prefix_equal, is_good)] = result;
        }
        return (*lookup)[make_tuple(i, is_prefix_equal, is_good)];
    }

    const unordered_set<int> invalid = {3, 4, 7};
    const unordered_set<int> diff = {2, 5, 6, 9};
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int rotatedDigits(int N) {
        enum State {INVALID, SAME, DIFF};
        const vector<int> same = {0, 1, 8};
        const vector<int> diff = {2, 5, 6, 9};
        vector<State> dp(N + 1);
        dp[0] = SAME;
        for (int i = 0; 10 * i <= N; ++i) {
            if (dp[i] != INVALID) {
                for (const auto& j : same) {
                    if (i * 10 + j <= N) {
                        dp[i * 10 + j] = max(SAME, dp[i]);
                    }
                }
                for (const auto& j : diff) {
                    if (i * 10 + j <= N) {
                        dp[i * 10 + j] = DIFF;
                    }
                }
            }
        }
        return count(dp.cbegin(), dp.cend(), DIFF);
    }
};

// Time:  O(nlogn) = O(n), because O(logn) = O(32) by this input
// Space: O(logn) = O(1)
class Solution3 {
public:
    int rotatedDigits(int N) {
        const unordered_set<char> invalid = {'3', '4', '7'};
        const unordered_set<char> diff = {'2', '5', '6', '9'};
        int result = 0;
        for (int i = 0; i <= N; ++i){
            string s(to_string(i));
            unordered_set<char> lookup(s.begin(),s.end());
            if (intersect(invalid, lookup)) {
                continue;
            }
            if (intersect(diff, lookup)) {
                ++result;
            }
        }
        return result; 
    }

private:
    template <typename T>
    bool intersect(const unordered_set<T>& a, const unordered_set<T>& b) {
        if (a.size() > b.size()) {
            return intersect(b, a);
        }
        return any_of(a.cbegin(), a.cend(),
                      [&b](const T& e) {
                          return b.count(e);
                      });
    }
};
