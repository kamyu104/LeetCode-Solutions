// Time:  O(n^3)
// Space: O(n^3)

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
    using Lookup = unordered_map<tuple<int, int, int>, int, TupleHash<int, int, int>>;

public:
    int mergeStones(vector<int>& stones, int K) {        
        if ((stones.size() - 1) % (K - 1)) {
            return -1;
        }
        Lookup lookup;
        vector<int> prefix(stones.size() + 1, 0);
        partial_sum(stones.cbegin(), stones.cend(),
                    next(prefix.begin()), plus<int>());
        int result = dp(prefix, K, 0, stones.size() - 1, 1, &lookup);
        return result != numeric_limits<int>::max() ? result : 0;
    }
    
private:
    int dp(const vector<int>& prefix, int K, int i, int j, int k,
           Lookup *lookup) {
        if (lookup->count(make_tuple(i, j, k))) {
            return (*lookup)[make_tuple(i, j, k)];
        }
        int result = 0;
        if (i == j) {
            result = k == 1 ? 0 : numeric_limits<int>::max();
        } else {
            if (k == 1) {
                result = dp(prefix, K, i, j, K, lookup) +
                         prefix[j + 1] - prefix[i];
            } else {
                result = numeric_limits<int>::max();
                for (int mid = i; mid < j; mid += K - 1) {
                    result = min(result, dp(prefix, K, i, mid, 1, lookup) + 
                                         dp(prefix, K, mid + 1, j, k - 1, lookup));
                }
            }
        }
        (*lookup)[make_tuple(i, j, k)] = result;
        return result;
    }
};
