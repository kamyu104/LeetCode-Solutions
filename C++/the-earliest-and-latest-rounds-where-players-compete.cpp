// Time:  O(n^2) states * O(n^2) per state = O(n^4)
// Space: O(n^2 + (n/2)^2 + (n/4)^2 + ... ) = O(n^2)

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
    using Lookup = unordered_map<tuple<int, int, int>, vector<int>, TupleHash<int, int, int>>;

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        Lookup lookup;
        return memoization(n, firstPlayer - 1, n - secondPlayer, &lookup);
    }

private:
    vector<int> memoization(int t, int l, int r, Lookup *lookup) {
        // t: total number of players,
        // l: number of players left to the nearest top2 player,
        // r: number of players right to the nearest top2 player
        if (!lookup->count(tuple(t, l, r))) {
            if (l == r) {
                return {1, 1};
            }
            if (l > r) {  // make sure l <= r
                swap(l, r);
            }
            vector<int> result = {numeric_limits<int>::max(), 0};
            for (int i = 0; i <= l; ++i) {
                const auto nt = (t + 1) / 2;
                const auto pair_cnt = t / 2;
                const auto l_lose_cnt = l - i;
                const auto l_win_cnt = i + 1;
                int min_j = max(l_lose_cnt, r - (pair_cnt - l_lose_cnt));  // j >= l_lose_cnt and j >= r-(pair_cnt-l_lose_cnt)
                int max_j = min(r - l_win_cnt, (nt - l_win_cnt) - 1);  // j <= r-l_win_cnt and j <= (nt-l_win_cnt)-1
                for (int j = min_j; j <= max_j; ++j) {
                    const auto& tmp = memoization(nt, i, j, lookup);
                    result = {min(result[0], tmp[0] + 1), max(result[1], tmp[1] + 1)};
                }
            }
            (*lookup)[tuple(t, l, r)] = move(result);
        }
        return (*lookup)[tuple(t, l, r)];
    }
};
