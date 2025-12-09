// Time:  O(n)
// Space: O(n)

// quick select, greedy
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        vector<int> idxs(size(technique1));
        iota(begin(idxs), end(idxs), 0);
        nth_element(begin(idxs), begin(idxs) + (k - 1), end(idxs), [&](const auto& a, const auto& b) {
            return technique1[a] - technique2[a] > technique1[b] - technique2[b];
        });
        int64_t result = 0;
        for (int i = 0; i < size(technique1); ++i) {
            result += i < k ? technique1[idxs[i]] : max(technique1[idxs[i]], technique2[idxs[i]]);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, greedy
class Solution2 {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        vector<int> idxs(size(technique1));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return technique1[a] - technique2[a] > technique1[b] - technique2[b];
        });
        int64_t result = 0;
        for (int i = 0; i < size(technique1); ++i) {
            result += i < k ? technique1[idxs[i]] : max(technique1[idxs[i]], technique2[idxs[i]]);
        }
        return result;
    }
};
