// Time:  precompute: O(r)
//        runtime:    O(nlogr)
// Space: O(r + nlogr)

// number theory, bfs
vector<int> linear_sieve_of_eratosthenes(int n) {  // Time: O(n), Space: O(n)
    vector<int> spf(n + 1, -1);
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (spf[i] == -1) {
            spf[i] = i;
            primes.emplace_back(i);
        }
        for (const auto& p : primes) {
            if (i * p > n || p > spf[i]) {
                break;
            }
            spf[i * p] = p;
        }
    }
    return spf;
};

const int MAX_NUM = 1e6;
const auto& SPF = linear_sieve_of_eratosthenes(MAX_NUM);
class Solution {
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < size(nums); ++i) {
            int x = nums[i];
            while (x != 1) {
                const auto& p = SPF[x];
                while (x % p == 0) {
                    x /= p;
                }
                adj[p].emplace_back(i);
            }
        }
        vector<int> dist(size(nums), -1);
        dist[0] = 0;
        vector<int> q = {0};
        while (!empty(q)) {
            vector<int> new_q;
            for (const auto& i : q) {
                if (i == size(nums) - 1) {
                    return dist.back();
                }
                for (const auto& di : {-1, +1}) {
                    const int ni = i + di;
                    if (0 <= ni && ni < size(nums) && dist[ni] == -1) {
                        dist[ni] = dist[i] + 1;
                        new_q.emplace_back(ni);
                    }
                }
                const int p = nums[i];
                if (SPF[p] != p || !adj.count(p)) {
                    continue;
                }
                for (const auto& ni : adj[p]) {
                    if (dist[ni] != -1) {
                        continue;
                    }
                    dist[ni] = dist[i] + 1;
                    new_q.emplace_back(ni);
                }
                adj.erase(p);
            }
            q = move(new_q);
        }
        return -1;
    }
};
