// Time:  O(rlogn)
// Space: O(r)

// if r = O(1), this is better
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = size(removable);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (!check(s, p, removable, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool check(const string& s, const string& p, const vector<int>& removable, int x) {
        unordered_set<int> lookup;
        for (int i = 0; i < x; ++i) {
            lookup.emplace(removable[i]);
        }
        int j = 0;
        for (int i = 0; i < size(s); ++i) {
            if (lookup.count(i) || s[i] != p[j]) {
                continue;
            }
            if (++j == size(p)) {
                return true;
            }
        }
        return false;
    }
};

// Time:  O(rlogn)
// Space: O(n)
// if r = O(n), this is better
class Solution2 {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        vector<int> lookup(size(s), numeric_limits<int>::max());
        for (int i = 0; i < size(removable); ++i) {
             lookup[removable[i]] = i + 1;
        }
        int left = 0, right = size(removable);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (!check(s, p, lookup, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool check(const string& s, const string& p, const vector<int>& lookup, int x) {
        int j = 0;
        for (int i = 0; i < size(s); ++i) {
            if (lookup[i] <= x || s[i] != p[j]) {
                continue;
            }
            if (++j == size(p)) {
                return true;
            }
        }
        return false;
    }
};
