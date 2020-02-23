// Time:  ctor:  O(n)
//        query: O(klogn), k = log2(Q/ERROR_RATE)
// Space: O(n)

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr)
      : arr_(arr)
      , gen_((random_device())())
    {
        for (int i = 0; i < arr_.size(); ++i) {
            inv_idx_[arr_[i]].emplace_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for (int i = 0; i < K; ++i) {
            const auto& m = arr_[uniform_int_distribution<int>{left, right}(gen_)];
            if (count(inv_idx_, m, left, right) >= threshold) {
                return m;
            }
        }
        return -1;
    }

private:
    int count(const unordered_map<int, vector<int>>& inv_idx, int m, int left, int right) {
        const auto& l = lower_bound(inv_idx_[m].cbegin(), inv_idx_[m].cend(), left);
        const auto& r = upper_bound(inv_idx_[m].cbegin(), inv_idx_[m].cend(), right);
        return r - l;
    }

    static constexpr int Q = 10000;
    static constexpr double ERROR_RATE = 0.001;
    static constexpr int K = log(Q / ERROR_RATE) / log(2) + 1;
    const vector<int>& arr_;
    unordered_map<int, vector<int>> inv_idx_;
    default_random_engine gen_;
};

// Time:  ctor:  O(n)
//        query: O(sqrt(n) * logn)
// Space: O(n)
class MajorityChecker2 {
public:
    MajorityChecker2(vector<int>& arr)
      : arr_(arr)
      , bound_(round(sqrt(arr_.size())))
    {
        for (int i = 0; i < arr_.size(); ++i) {
            inv_idx_[arr_[i]].emplace_back(i);
        }
        for (const auto& [i, group] : inv_idx_) {
            if (group.size() >= bound_) {
                majorities_.emplace_back(i);
            }
        }
    }
    
    int query(int left, int right, int threshold) {
        if (right - left + 1 < bound_) {
            const auto& m = boyer_moore_majority_vote(arr_, left, right);
            if (count(inv_idx_, m, left, right) >= threshold) {
                return m;
            }
        } else {
            for (const auto& m : majorities_) {
                if (count(inv_idx_, m, left, right) >= threshold) {
                    return m;
                }
            }
        }
        return -1;
    }

private:
    int count(const unordered_map<int, vector<int>>& inv_idx, int m, int left, int right) {
        const auto& l = lower_bound(inv_idx_[m].cbegin(), inv_idx_[m].cend(), left);
        const auto& r = upper_bound(inv_idx_[m].cbegin(), inv_idx_[m].cend(), right);
        return r - l;
    }
    
    int boyer_moore_majority_vote(const vector<int>& nums, int left, int right) {
        int m = nums[left], cnt = 1;
        for (int i = left; i <= right; ++i) {
            if (m == nums[i]) {
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) {
                    m = nums[i];
                    cnt = 1;
                }
            }
        }
        return m;
    }

    const vector<int>& arr_;
    const int bound_;
    unordered_map<int, vector<int>> inv_idx_;
    vector<int> majorities_;
};

// Time:  ctor:  O(nlogn)
//        query: O((logn)^2)
// Space: O(n)
class MajorityChecker3 {
private:
    struct SegmentTree {
    public:
        SegmentTree(const vector<int>& nums,
                    const function<int(int, int, int)>& count)
          : original_length_(nums.size())
          , count_(count)
        {
            int size = 1;
            while (size <= original_length_) {
                size *= 2;
            }
            if (original_length_ & (original_length_ - 1)) {
                size *= 2;
            }
            tree_ = vector<int>(size - 1, -1);
            constructTree(nums, 0, original_length_ - 1, 0);
        }

        pair<int, int> query(int i, int j) const {
            return queryRange(i, j, 0, original_length_- 1, 0);
        }

    private:
        void constructTree(const vector<int>& nums, int left, int right, int idx) {
            if (left > right) {
                 return;
            }
            if (left == right) {
                tree_[idx] = nums[left];
                return;
            }
            const auto& mid = left + (right - left) / 2;
            constructTree(nums, left, mid, idx * 2 + 1);
            constructTree(nums, mid+1, right, idx * 2 + 2);
            if (tree_[idx * 2 + 1] != -1 &&
                count_(tree_[idx * 2 + 1], left, right) * 2 > right - left + 1) {
                tree_[idx] = tree_[idx * 2 + 1];
            } else if (tree_[idx * 2 + 2] != -1 &&
                       count_(tree_[idx * 2 + 2], left, right) * 2 > right - left + 1) {
                tree_[idx] = tree_[idx * 2 + 2];
            }
        }
    
        pair<int, int> queryRange(int range_left, int range_right,
                                  int left, int right, int idx) const {
            if (left > right) {
                return {-1, -1};
            }
            if (right < range_left || left > range_right) {
                return {-1, -1};
            }
            if (range_left <= left && right <= range_right) {
                if (tree_[idx] != -1) {
                    const auto& c = count_(tree_[idx], range_left, range_right);
                    if (c * 2 > range_right - range_left + 1) {
                        return {tree_[idx], c};
                    }
                }
            } else {
                const auto& mid = left + (right - left) / 2;
                auto result = queryRange(range_left, range_right, left, mid, idx * 2 + 1);
                if (result.first != -1) {
                    return result;
                }
                result = queryRange(range_left, range_right, mid + 1, right, idx * 2 + 2);
                if (result.first != -1) {
                    return result;
                }
            }
            return {-1, -1};
        }
        
    private:
        const int original_length_;
        const function<int(int, int, int)> count_;
        vector<int> tree_;
    };

    int count(const unordered_map<int, vector<int>>& inv_idx, int m, int left, int right) {
        const auto& l = lower_bound(inv_idx_[m].cbegin(), inv_idx_[m].cend(), left);
        const auto& r = upper_bound(inv_idx_[m].cbegin(), inv_idx_[m].cend(), right);
        return r - l;
    }

public:
    MajorityChecker3(vector<int>& arr)
      : arr_(arr)
    {
        for (int i = 0; i < arr_.size(); ++i) {
            inv_idx_[arr_[i]].push_back(i);
        }
        segment_tree_ = make_unique<SegmentTree>(arr,
                            bind(&MajorityChecker3::count, this, cref(inv_idx_),
                                 placeholders::_1,
                                 placeholders::_2,
                                 placeholders::_3));
    }
    
    int query(int left, int right, int threshold) {
        const auto& result = segment_tree_->query(left, right);
        if (result.second >= threshold) {
            return result.first;
        }
        return -1;
    }

private:
    const vector<int>& arr_;
    unordered_map<int, vector<int>> inv_idx_;
    unique_ptr<SegmentTree> segment_tree_;
};

// Time:  ctor:  O(n)
//        query: O(sqrt(n) * logn)
// Space: O(n)
class MajorityChecker4 {
public:
    MajorityChecker4(vector<int>& arr)
      : arr_(arr)
      , bucket_size_(round(sqrt(arr_.size())))
    {
        for (int i = 0; i < arr_.size(); ++i) {
            inv_idx_[arr_[i]].emplace_back(i);
        }
        for (int left = 0; left < arr_.size(); left += bucket_size_) {
            const auto right = min(left + bucket_size_ - 1, int(arr_.size()) - 1);
            bucket_majorities_.emplace_back(boyer_moore_majority_vote(arr_, left, right));
        }
    }
    
    int query(int left, int right, int threshold) {
        int l = left / bucket_size_;
        int r = right / bucket_size_;
        if (l == r) {
            const auto& m = boyer_moore_majority_vote(arr_, left, right);
            if (count(inv_idx_, m, left, right) >= threshold) {
                return m;
            }
            return -1;
        }
        else {
            int m = boyer_moore_majority_vote(arr_, left, (l + 1) * bucket_size_ - 1);
            if (count(inv_idx_, m, left, right) >= threshold) {
                return m;
            }
            m = boyer_moore_majority_vote(arr_, r * bucket_size_, right);
            if (count(inv_idx_, m, left, right) >= threshold) {
                return m;
            }
            for (int i = l + 1; i < r; ++i) {
                if (count(inv_idx_, bucket_majorities_[i], left, right) >= threshold) {
                    return bucket_majorities_[i];
                }
            }
            return -1;
        }
    }

private:
    int count(const unordered_map<int, vector<int>>& inv_idx, int m, int left, int right) {
        const auto& l = lower_bound(inv_idx_[m].cbegin(), inv_idx_[m].cend(), left);
        const auto& r = upper_bound(inv_idx_[m].cbegin(), inv_idx_[m].cend(), right);
        return r - l;
    }
    
    int boyer_moore_majority_vote(const vector<int>& nums, int left, int right) {
        int m = nums[left], cnt = 1;
        for (int i = left; i <= right; ++i) {
            if (m == nums[i]) {
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) {
                    m = nums[i];
                    cnt = 1;
                }
            }
        }
        return m;
    }

    const vector<int>& arr_;
    const int bucket_size_;
    unordered_map<int, vector<int>> inv_idx_;
    vector<int> bucket_majorities_;
};
