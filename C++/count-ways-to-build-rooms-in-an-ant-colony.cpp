// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        vector<vector<int>> adj(size(prevRoom));
        for (int i = 1; i < size(prevRoom); ++i) {
            adj[prevRoom[i]].emplace_back(i);
        }
        return dfs(adj, 0).first;
    }

private:
    pair<int, int> dfs(const vector<vector<int>>& adj, int curr) {
        static const int MOD = 1e9 + 7;
        int total_ways = 1, total_cnt = 0;
        for (const auto& child : adj[curr]) {
            const auto& [ways, cnt] = dfs(adj, child);
            total_cnt += cnt;
            total_ways = mulmod(mulmod(total_ways, ways, MOD), nCr(total_cnt, cnt, MOD), MOD);
        }
        return {total_ways, total_cnt + 1};
    }

    int nCr(int n, int k, uint32_t mod) {
        while (size(inv_) <= n) {  // lazy initialization
            fact_.emplace_back(mulmod(fact_.back(), size(inv_), mod));
            inv_.emplace_back(mulmod(inv_[mod % size(inv_)], mod - mod / size(inv_), mod));  // https://cp-algorithms.com/algebra/module-inverse.html
            inv_fact_.emplace_back(mulmod(inv_fact_.back(), inv_.back(), mod));
        }
        return mulmod(mulmod(fact_[n], inv_fact_[n - k], mod), inv_fact_[k], mod);
    }

    uint32_t addmod(uint32_t a, uint32_t b, uint32_t mod) {  // avoid overflow
        a %= mod, b %= mod;
        if (mod - a <= b) {
            b -= mod;  // relied on unsigned integer overflow in order to give the expected results
        }
        return a + b;
    }

    // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
    uint32_t mulmod(uint32_t a, uint32_t b, uint32_t mod)  {  // avoid overflow
        a %= mod, b %= mod;
        uint32_t result = 0;
        if (a < b) {
            swap(a, b);
        }
        while (b > 0)  { 
            if (b % 2 == 1) {
                result = addmod(result, a, mod);
            }
            a = addmod(a, a, mod);
            b /= 2; 
        } 
        return result; 
    }

    static const int MOD = 1e9 + 7;
    vector<int> fact_ = {1, 1};
    vector<int> inv_ = {0, 1};
    vector<int> inv_fact_ = {1, 1};
};
