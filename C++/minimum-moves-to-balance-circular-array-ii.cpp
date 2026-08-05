// Time:  O(n^2 * logn)
// Space: O(n)

// heap
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        const auto& total = accumulate(cbegin(balance), cend(balance), 0LL);
        if (total < 0) {
            return -1;
        }

        const auto& cost = [&](int i) {
            long long result = 0, prefix = 0;
            priority_queue<int64_t> max_heap;
            for (int j = 0; j < size(balance); ++j) {
                prefix += balance[(i + j) % size(balance)];
                const auto c = clamp(prefix, 0LL, total);
                result += llabs(prefix - c);
                // heap-based l1 isotonic regression
                // reference: https://codeforces.com/contest/13/problem/C
                max_heap.emplace(c);
                if (max_heap.top() > c) {
                    result += max_heap.top() - c;
                    max_heap.pop();
                    max_heap.emplace(c);
                }
            }
            return result;
        };

        long long result = numeric_limits<long long>::max();
        for (int i = 0; i < size(balance); ++i) {
            result = min(result, cost(i));
        }
        return result;
    }
};

// Time:  O(F * E * logV) = O(n^2 * logn), V = O(n), E = O(n), and each augmentation saturates a supply or demand edge, so there are only O(n) augmentations
// Space: O(V + E) = O(n)
// min-cost max-flow
#include <bits/stdc++.h>

// Time: O(F * E * logV
// Space: O(V + E)
// Template: https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/MinCostMaxFlow.h
const long long INF = numeric_limits<long long>::max();

struct MCMF {
    struct edge {
        int from, to, rev;
        long long cap, cost, flow;
    };

    int N;
    vector<vector<edge>> ed;
    vector<int> seen;
    vector<long long> dist, pi;
    vector<edge*> par;

    MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

    void addEdge(int from, int to, long long cap, long long cost) {
        if (from == to) return;
        ed[from].push_back({from, to, (int)ed[to].size(), cap, cost, 0});
        ed[to].push_back({to, from, (int)ed[from].size() - 1, 0, -cost, 0});
    }

    void path(int s) {
        fill(seen.begin(), seen.end(), 0);
        fill(dist.begin(), dist.end(), INF);
        fill(par.begin(), par.end(), nullptr);
        dist[s] = 0;
        using State = pair<long long, int>;
        priority_queue<State, vector<State>, greater<State>> q;
        q.push({0, s});
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (d != dist[u]) continue;
            seen[u] = 1;
            for (edge& e : ed[u]) {
                if (e.cap - e.flow <= 0) continue;
                long long val = d + pi[u] - pi[e.to] + e.cost;
                if (val < dist[e.to]) {
                    dist[e.to] = val;
                    par[e.to] = &e;
                    q.push({val, e.to});
                }
            }
        }
        for (int i = 0; i < N; ++i)
            if (dist[i] != INF)
                pi[i] += dist[i];
    }

    pair<long long, long long> maxflow(int s, int t) {
        long long totflow = 0, totcost = 0;
        while (path(s), seen[t]) {
            long long fl = INF;
            for (edge* x = par[t]; x; x = par[x->from])
                fl = min(fl, x->cap - x->flow);
            totflow += fl;
            for (edge* x = par[t]; x; x = par[x->from]) {
                x->flow += fl;
                ed[x->to][x->rev].flow -= fl;
            }
        }
        for (int i = 0; i < N; ++i)
            for (edge& e : ed[i])
                totcost += e.cost * e.flow;
        return {totflow, totcost / 2};
    }
};

class Solution2 {
public:
    long long minMoves(vector<int>& balance) {
        const auto& total = accumulate(cbegin(balance), cend(balance), 0LL);
        if (total < 0) {
            return -1;
        }
        int S = size(balance), T = size(balance) + 1;
        MCMF mcmf(size(balance) + 2);
        for (int i = 0; i < size(balance); ++i) {
            mcmf.addEdge(i, (i + 1) % size(balance), INF, 1);
            mcmf.addEdge((i + 1) % size(balance), i, INF, 1);
        }
        int64_t demand = 0;
        for (int i = 0; i < size(balance); ++i) {
            if (balance[i] > 0) {
                mcmf.addEdge(S, i, balance[i], 0);
            } else if (balance[i] < 0) {
                mcmf.addEdge(i, T, -balance[i], 0);
                demand += -balance[i];
            }
        }
        const auto& [flow, cost] = mcmf.maxflow(S, T);
        return flow == demand ? cost : -1;
    }
};
