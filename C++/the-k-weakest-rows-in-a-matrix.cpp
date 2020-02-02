// Time:  O(m * n)
// Space: O(k)

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        unordered_set<int> lookup;
        for (int j = 0; j < mat[0].size(); ++j) {
            for (int i = 0; i < mat.size(); ++i) {
                if (mat[i][j] || lookup.count(i)) {
                    continue;
                }
                lookup.emplace(i);
                result.emplace_back(i);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        for (int i = 0; i < mat.size(); ++i) {
            if (lookup.count(i)) {
                continue;
            }
            lookup.emplace(i);
            result.emplace_back(i);
            if (result.size() == k) {
                break;
            }
        }
        return result;
    }
};

// Time:  O(m * n)
// Space: O(k)
class Solution2 {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        OrderedDict<int, bool> lookup;
        for (int j = 0; j < mat[0].size(); ++j) {
            for (int i = 0; i < mat.size(); ++i) {
                if (mat[i][j] || lookup.count(i)) {
                    continue;
                }
                lookup[i] = true;
                if (lookup.size() == k) {
                    return lookup.keys();
                }
            }
        }
        for (int i = 0; i < mat.size(); ++i) {
            if (lookup.count(i)) {
                continue;
            }
            lookup[i] = true;
            if (lookup.size() == k) {
                break;
            }
        }
        return lookup.keys();
    }

private:
    template<typename K, typename V>
    class OrderedDict {
    public:
        bool count(const K& key) const {
            return map_.count(key);
        }
        
        V& operator[](const K& key) {
            if (!map_.count(key)) {
                list_.emplace_front();
                list_.begin()->first = key;
                map_[key] = list_.begin();
            }
            return map_[key]->second;
        }

        void popitem() {
            auto del = list_.front(); list_.pop_front();
            map_.erase(del.first);
        }
        
        vector<K> keys() const {
            vector<K> result;
            transform(list_.crbegin(), list_.crend(), back_inserter(result),
                      [](const auto& x) {
                          return x.first;
                      });
            return result;
        }
        
        int size() const {
            return list_.size();
        }
    
    private:
        list<pair<K, V>> list_;
        unordered_map<K, typename list<pair<K, V>>::iterator> map_;
    };
};

// Time:  O(m * n + klogk)
// Space: O(m)
class Solution3 {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> nums;
        for (int i = 0; i < mat.size(); ++i) {
            nums.emplace_back(accumulate(mat[i].cbegin(), mat[i].cend(), 0), i);
        }
        nth_element(nums.begin(), nums.begin() + k, nums.end());
        sort(nums.begin(), nums.begin() + k);
        vector<int> result;
        transform(nums.cbegin(), nums.cbegin() + k, back_inserter(result),
                  [](const auto& x) {
                      return x.second;
                  });
        return result;
    }
};
