// Time:  O(m * n * sqrt(m + n))
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
    int maximumInvitations(vector<vector<int>>& grid) {
        BipGraph graph(size(grid), size(grid[0]));
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                graph.addEdge(i + 1, j + 1);
            }
        }
        return graph.hopcroftKarp();
    }
};

// Time:  O(|V| * |E|) = O(min(m, n) * (m * n))
// Space: O(|V|) = O(min(m, n))
// Hungarian bipartite matching with less space
class Solution2 {
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        return hungarian(grid);
    }

private:
    int hungarian(const vector<vector<int>>& grid) {
        unordered_map<int, int> match;
        for (int i = 0; i < min(size(grid), size(grid[0])); ++i) {
            unordered_set<int> lookup;  // visited u
            augment(grid, i, &lookup, &match);
        }
        return size(match);
    }

    bool augment(const vector<vector<int>>& grid, int u,
                 unordered_set<int> *lookup,
                 unordered_map<int, int> *match) {
        lookup->emplace(u);
        for (int v = 0; v < max(size(grid), size(grid[0])); ++v) {
            if (!get_grid(grid, u, v) || (match->count(v) && lookup->count((*match)[v]))) {
                continue;
            }
            if (!match->count(v) || augment(grid, (*match)[v], lookup, match)) {
                (*match)[v] = u;
                return true;
            }
        }
        return false;
    }

    int get_grid(const vector<vector<int>>& grid, int u, int v) {
        return (size(grid) < size(grid[0])) ? grid[u][v] : grid[v][u];
    }
};

// Time:  O(|V| * |E|) = O(min(m, n) * (m * n))
// Space: O(|E|) = O(m * n)
// Hungarian bipartite matching
class Solution3 {
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                if (size(grid) < size(grid[0])) {
                    adj[i].emplace_back(j);
                } else {
                    adj[j].emplace_back(i);
                }
            }
        }
        return hungarian(adj);
    }

private:
    int hungarian(const unordered_map<int, vector<int>>& adj) {
        unordered_map<int, int> match;
        for (const auto& [i, _] : adj) {
            unordered_set<int> lookup;  // visited v
            augment(adj, i, &lookup, &match);
        }
        return size(match);
    }

    bool augment(const unordered_map<int, vector<int>>& adj, int u,
                 unordered_set<int> *lookup,
                 unordered_map<int, int> *match) {
        for (const auto& v : adj.at(u)) {
            if (lookup->count(v)) {
                continue;
            }
            lookup->emplace(v);
            if (!match->count(v) || augment(adj, (*match)[v], lookup, match)) {
                (*match)[v] = u;
                return true;
            }
        }
        return false;
    }
};
