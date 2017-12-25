// Time:  O(k^n)
// Space: O(k^n)

// https://en.wikipedia.org/wiki/De_Bruijn_sequence
class Solution {
public:
    string crackSafe(int n, int k) {
        const int M = pow(k, n - 1);
        vector<int> P;
        for (int i = 0; i < k; ++i) {
            for (int q = 0; q < M; ++q) {
                P.emplace_back(q * k + i);
            }
        }
        const int total = pow(k, n);
        string result(n - 1, '0' + k - 1);
        for (int i = 0; i < total; ++i) {
            int j = i;
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

// Time:  O(n * k^n)
// Space: O(n * k^n)
class Solution2 {
public:
    string crackSafe(int n, int k) {
        string result(n, '0' + k - 1);
        unordered_set<string> lookup;
        lookup.emplace(result);
        const int total = pow(k, n);
        while (lookup.size() < total) {
            auto node = result.substr(result.length() - n + 1);
            for (int i = 0; i < k; ++i) {
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
class Solution3 {
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
        for (int i = 0; i < k; ++i) {
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
