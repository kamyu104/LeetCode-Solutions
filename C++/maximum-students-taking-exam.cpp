// Time:  O(m * n * sqrt(m * n))
// Space: O(m * n)

// template from https://www.geeksforgeeks.org/hopcroft-karp-algorithm-for-maximum-matching-set-2-implementation/
static const int NIL = 0;
static const int INF = numeric_limits<int>::max();

// A class to represent Bipartite graph for Hopcroft
// Karp implementation
// Time:  O(E * sqrt(V))
// Space: O(V)
class BipGraph
{
    // m and n are number of vertices on left
    // and right sides of Bipartite Graph
    int m, n;

    // adj[u] stores adjacents of left side
    // vertex 'u'. The value of u ranges from 1 to m.
    // 0 is used for dummy vertex
    list<int> *adj;

    // These are basically pointers to arrays needed
    // for hopcroftKarp()
    int *pairU, *pairV, *dist;

public:
    BipGraph(int m, int n); // Constructor
    void addEdge(int u, int v); // To add edge

    // Returns true if there is an augmenting path
    bool bfs();

    // Adds augmenting path if there is one beginning
    // with u
    bool dfs(int u);

    // Returns size of maximum matcing
    int hopcroftKarp();
};

// Returns size of maximum matching
int BipGraph::hopcroftKarp()
{
    // pairU[u] stores pair of u in matching where u
    // is a vertex on left side of Bipartite Graph.
    // If u doesn't have any pair, then pairU[u] is NIL
    pairU = new int[m+1];

    // pairV[v] stores pair of v in matching. If v
    // doesn't have any pair, then pairU[v] is NIL
    pairV = new int[n+1];

    // dist[u] stores distance of left side vertices
    // dist[u] is one more than dist[u'] if u is next
    // to u'in augmenting path
    dist = new int[m+1];

    // Initialize NIL as pair of all vertices
    for (int u=0; u<=m; u++)
        pairU[u] = NIL;
    for (int v=0; v<=n; v++)
        pairV[v] = NIL;

    // Initialize result
    int result = 0;

    // Keep updating the result while there is an
    // augmenting path.
    while (bfs())
    {
        // Find a free vertex
        for (int u=1; u<=m; u++)

            // If current vertex is free and there is
            // an augmenting path from current vertex
            if (pairU[u]==NIL && dfs(u))
                result++;
    }
    return result;
}

// Returns true if there is an augmenting path, else returns
// false
bool BipGraph::bfs()
{
    queue<int> Q; //an integer queue

    // First layer of vertices (set distance as 0)
    for (int u=1; u<=m; u++)
    {
        // If this is a free vertex, add it to queue
        if (pairU[u]==NIL)
        {
            // u is not matched
            dist[u] = 0;
            Q.push(u);
        }

        // Else set distance as infinite so that this vertex
        // is considered next time
        else dist[u] = INF;
    }

    // Initialize distance to NIL as infinite
    dist[NIL] = INF;

    // Q is going to contain vertices of left side only.
    while (!Q.empty())
    {
        // Dequeue a vertex
        int u = Q.front();
        Q.pop();

        // If this node is not NIL and can provide a shorter path to NIL
        if (dist[u] < dist[NIL])
        {
            // Get all adjacent vertices of the dequeued vertex u
            list<int>::iterator i;
            for (i=adj[u].begin(); i!=adj[u].end(); ++i)
            {
                int v = *i;

                // If pair of v is not considered so far
                // (v, pairV[V]) is not yet explored edge.
                if (dist[pairV[v]] == INF)
                {
                    // Consider the pair and add it to queue
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }

    // If we could come back to NIL using alternating path of distinct
    // vertices then there is an augmenting path
    return (dist[NIL] != INF);
}

// Returns true if there is an augmenting path beginning with free vertex u
bool BipGraph::dfs(int u)
{
    if (u != NIL)
    {
        list<int>::iterator i;
        for (i=adj[u].begin(); i!=adj[u].end(); ++i)
        {
            // Adjacent to u
            int v = *i;

            // Follow the distances set by BFS
            if (dist[pairV[v]] == dist[u]+1)
            {
                // If dfs for pair of v also returns
                // true
                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }

        // If there is no augmenting path beginning with u.
        dist[u] = INF;
        return false;
    }
    return true;
}

// Constructor
BipGraph::BipGraph(int m, int n)
{
    this->m = m;
    this->n = n;
    adj = new list<int>[m+1];
}

// To add edge from u to v and v to u
void BipGraph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add u to v’s list.
}

// Hopcroft-Karp bipartite matching
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        static vector<pair<int, int>> directions = {{-1, -1}, {0, -1}, {1, -1},
                                                    {-1, 1}, {0, 1}, {1, 1}};
        unordered_map<int, int> lookup;
        int u = 0, v = 0;
        for (int i = 0; i < seats.size(); ++i) {
            for (int j = 0; j < seats[0].size(); ++j) {
                if (seats[i][j] != '.') {
                    continue;
                }
                lookup[i * seats[0].size() + j] = (j % 2 == 0) ? ++u : ++v;
            }
        }
        BipGraph g(seats.size() * seats[0].size(), seats.size() * seats[0].size());
        for (int i = 0; i < seats.size(); ++i) {
            for (int j = 0; j < seats[0].size(); j += 2) {
                if (seats[i][j] != '.') {
                    continue;
                }
                for (const auto& [dx, dy] : directions) {
                    const auto& [ni, nj] = make_pair(i + dx, j + dy);
                    if (0 <= ni && ni < seats.size() &&
                        0 <= nj && nj < seats[0].size() &&
                        seats[ni][nj] == '.') {
                        g.addEdge(lookup[i * seats[0].size() + j],
                                  lookup[ni * seats[0].size() + nj]);
                    }
                }
            }
        }
        return u + v - g.hopcroftKarp();
    }
};

// Time:  O(|V| * |E|) = O(m^2 * n^2)
// Space: O(|V| + |E|) = O(m * n)
// Hungarian bipartite matching
class Solution2 {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int count = 0;
        for (int i = 0; i < seats.size(); ++i) {
            for (int j = 0; j < seats[0].size(); ++j) {
                if (seats[i][j] != '.') {
                    continue;
                }
                ++count;
            }
        }
        return count - Hungarian(seats);
    }

private:
    int Hungarian(const vector<vector<char>>& seats) {
        int result = 0;
        vector<vector<pair<int, int>>> matching(seats.size(),
                                                vector<pair<int, int>>(seats[0].size(), {-1, -1}));
        for (int i = 0; i < seats.size(); ++i) {
            for (int j = 0; j < seats[0].size(); j += 2) {
                if (seats[i][j] != '.') {
                    continue;
                }
                vector<vector<bool>> lookup(seats.size(),
                                            vector<bool>(seats[0].size(), false));
                if (dfs(seats, {i, j}, &lookup, &matching)) {
                    ++result;
                }
            }
        }
        return result;
    }

    int dfs(const vector<vector<char>>& seats,
            const pair<int, int>& e,
            vector<vector<bool>> *lookup,
            vector<vector<pair<int, int>>> *matching) {
        static vector<pair<int, int>> directions = {{-1, -1}, {0, -1}, {1, -1},
                                                    {-1, 1}, {0, 1}, {1, 1}};
        const auto& [i, j] = e;
        for (const auto& [dx, dy] : directions) {
            const auto& [ni, nj] = make_pair(i + dx, j + dy);
            if (0 <= ni && ni < seats.size() &&
                0 <= nj && nj < seats[0].size() &&
                seats[ni][nj] == '.' &&
                !(*lookup)[ni][nj]) {
                (*lookup)[ni][nj] = true;
                if ((*matching)[ni][nj].first == -1 ||
                    dfs(seats, (*matching)[ni][nj], lookup, matching)) {
                    (*matching)[ni][nj] = e;
                    return true;
                }
            }
        }
        return false;
    }
};

// Time:  O(m * 2^n * 2^n) = O(m * 4^n)
// Space: O(2^n)
// dp solution
class Solution3 {
public:
    int maxStudents(vector<vector<char>>& seats) {
        const int state_size = 1 << seats[0].size();
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (const auto& row : seats) {
            int invalid_mask = 0;
            for (int i = 0; i < row.size(); ++i) {
                if (row[i] == '#') {
                    invalid_mask |= 1 << i;
                }
            }
            unordered_map<int, int> new_dp;
            for (const auto& [mask1, v1] : dp) {
                for (int mask2 = 0; mask2 < state_size; ++mask2) {
                    if ((mask2 & invalid_mask) ||
                        (mask2 & (mask1 << 1)) || (mask2 & (mask1 >> 1)) ||
                        (mask2 & (mask2 << 1)) || (mask2 & (mask2 >> 1))) {
                        continue;
                    }
                    new_dp[mask2] = max(new_dp.count(mask2) ? new_dp[mask2] : 0,
                                        v1 + __builtin_popcount(mask2));
                }
            }
            dp = move(new_dp);
        }
        return dp.empty() ? 0 : max_element(dp.cbegin(), dp.cend(),
                                            [](const auto& a, const auto& b) {
                                                return a.second < b.second;
                                            })->second;
    }
};
