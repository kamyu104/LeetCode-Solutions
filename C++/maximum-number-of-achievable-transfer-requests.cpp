// Time:  O((n + r) * 2^r)
// Space: O(n + r)

// early return solution
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        const auto& check =
            [&n, &requests](const auto& idx) {
                 vector<int> change(n);
                 for (const auto& i : idx) {
                     --change[requests[i][0]];
                     ++change[requests[i][1]];
                 }
                 return all_of(cbegin(change), cend(change),
                               [](const auto& x) {
                                   return x == 0;
                               });
             };
    
        for (int k = size(requests); k > 0; --k) {
            if (combinations(size(requests), k, check)) {
                return k;  // early return
            }
        }
        return 0;
    }

private:
    bool combinations(int n, int k, const function<bool (const vector<int>&)>& callback) {
        static const auto& next_pos =
            [](const auto& n, const auto& k, const auto& idxs) {
                int i = k - 1;
                for (; i >= 0; --i) {
                    if (idxs[i] != i + n - k) {
                        break;
                    }
                }
                return i;
            };
    
        vector<int> idxs(k);
        iota(begin(idxs), end(idxs), 0);
        if (callback(idxs)) {
            return true;
        }
        for (int i; (i = next_pos(n, k, idxs)) >= 0;) {
            ++idxs[i];
            for (int j = i + 1; j < k; ++j) {
                idxs[j] = idxs[j - 1] + 1;
            }
            if (callback(idxs)) {
                return true;
            }
        }
        return false;
    }
};

// Time:  O((n + r) * 2^r)
// Space: O(n + r)
// full search solution (much slower)
class Solution2 {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        const auto& evaluate =
            [&n, &requests](const auto& mask) {
                 vector<int> change(n);
                 int count = 0;
                 for (int i = 0, base = 1; i < size(requests); ++i, base <<= 1) {
                     if (base & mask) {
                         --change[requests[i][0]];
                         ++change[requests[i][1]];
                         ++count;
                     }
                 }
                 return all_of(cbegin(change), cend(change),
                               [](const auto& x) {
                                   return x == 0;
                               }) ? count : 0;
             };
    
        const auto& total = 1 << size(requests);
        int result = 0;
        for (int mask = 0; mask < total; ++mask) {
            result = max(result, evaluate(mask));
        }
        return result;
    }
};
