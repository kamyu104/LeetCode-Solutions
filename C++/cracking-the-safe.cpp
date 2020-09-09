// Time:  O(k^n)
// Space: O(k^n)

// https://en.wikipedia.org/wiki/De_Bruijn_sequence
// https://en.wikipedia.org/wiki/Lyndon_word
class Solution {
public:
    string crackSafe(int n, int k) {
        const int M = pow(k, n - 1);
        vector<int> P;
        for (int i = 0; i < k; ++i) {
            for (int q = 0; q < M; ++q) {
                P.emplace_back(q * k + i);  // rotate: i*k^(n-1) + q => q*k + i
            }
        }
        const int total = pow(k, n);
        string result(n - 1, '0' + k - 1);
        for (int i = 0; i < total; ++i) {
            int j = i;
            // concatenation in lexicographic order of Lyndon words
            while (P[j] >= 0) {
                result.push_back('0' + j / M);
                auto Pj = P[j];
                P[j] = -1;
                j = Pj;
            }
        }
        return result;
    }
};

// Time:  O(k^n)
// Space: O(k^n)
class Solution2 {
public:
    string crackSafe(int n, int k) {
        const int M = pow(k, n - 1);
        int unique_rolling_hash = 0;
        string result(n - 1, '0');
        unordered_set<int> lookup;
        const int total = pow(k, n);
        while (lookup.size() < total) {
            for (int i = k - 1; i >= 0; --i) {  // preorder like traversal relative to initial result to avoid getting stuck, i.e. don't use 0 until there is no other choice
                const auto& new_unique_rolling_hash = unique_rolling_hash * k + i;
                if (!lookup.count(new_unique_rolling_hash)) {
                    lookup.emplace(new_unique_rolling_hash);
                    result.push_back('0' + i);
                    unique_rolling_hash = new_unique_rolling_hash % M;
                    break;
                }
            }
        }
        return result;
    }
};

// Time:  O(k^n)
// Space: O(k^n)
class Solution3 {
public:
    string crackSafe(int n, int k) {
        const int M = pow(k, n - 1);
        int unique_rolling_hash = 0;
        unordered_set<int> lookup;
        string result(n - 1, '0');
        dfs(k, M, unique_rolling_hash, &lookup, &result);
        return result;
    }

private:
    void dfs(int k, int M, int unique_rolling_hash, unordered_set<int> *lookup, string *result) {
        for (int i = k - 1; i >= 0; --i) {  // preorder like traversal relative to initial result to avoid getting stuck, i.e. don't use 0 until there is no other choice
            const auto& new_unique_rolling_hash = unique_rolling_hash * k + i;
            if (!lookup->count(new_unique_rolling_hash)) {
                lookup->emplace(new_unique_rolling_hash);
                result->push_back('0' + i);
                dfs(k, M, new_unique_rolling_hash % M, lookup, result);
                break;
            }
        }
    }
};

// Time:  O(n * k^n)
// Space: O(n * k^n)
class Solution4 {
public:
    string crackSafe(int n, int k) {
        string result(n - 1, '0' + k - 1);
        unordered_set<string> lookup;
        const int total = pow(k, n);
        while (lookup.size() < total) {
            const auto& node = result.substr(result.length() - n + 1);
            for (int i = 0; i < k; ++i) {  // preorder like traversal relative to initial result to avoid getting stuck, i.e. don't use k-1 until there is no other choice
                const auto& neighbor = node + to_string(i);
                if (!lookup.count(neighbor)) {
                    lookup.emplace(neighbor);
                    result.push_back('0' + i);
                    break;
                }
            }
        }
        return result;
    }
};

// Time:  O(n * k^n)
// Space: O(n * k^n)
class Solution5 {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> lookup;
        string result(n - 1, '0' + k - 1);
        auto node = result;
        dfs(k, node, &lookup, &result);
        return result;
    }

private:
    void dfs(int k, const string& node, unordered_set<string> *lookup, string *result) {
        for (int i = 0; i < k; ++i) {  // preorder like traversal relative to initial result to avoid getting stuck, i.e. don't use k-1 until there is no other choice
            const auto& neighbor = node + to_string(i);
            if (!lookup->count(neighbor)) {
                lookup->emplace(neighbor);
                result->push_back('0' + i);
                dfs(k, neighbor.substr(1), lookup, result);
                break;
            }
        }
    }
};
