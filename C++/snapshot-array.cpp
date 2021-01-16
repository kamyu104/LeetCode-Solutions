// Time:  set: O(1)
//        get: O(logn), n is the total number of set
// Space: O(n)

class SnapshotArray {
public:
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        if (!A_.count(index)) {
            A_[index].emplace_back(0, 0);
        }
        if (A_[index].back().first == snap_id_) {
            A_[index].back().second = val;
        } else {
            A_[index].emplace_back(snap_id_, val);
        }
    }
    
    int snap() {
        return snap_id_++;
    }
    
    int get(int index, int snap_id) {
        if (!A_.count(index)) {
            A_[index].emplace_back(0, 0);
        }
        const auto& it = prev(lower_bound(A_[index].cbegin(), A_[index].cend(),
                                          make_pair(snap_id + 1, numeric_limits<int>::min())));
        return it->second;
    }

private:
    unordered_map<int, vector<pair<int, int>>> A_;
    int snap_id_ = 0;
};

// Time:  set: O(logn)
//        get: O(logn), n is the total number of set
// Space: O(n)
class SnapshotArray2 {
public:
    SnapshotArray2(int length) {
    }
    
    void set(int index, int val) {
        if (!A_.count(index)) {
            A_[index][0] = 0;
        }
        A_[index][snap_id_] = val;
    }
    
    int snap() {
        return snap_id_++;
    }
    
    int get(int index, int snap_id) {
        if (!A_.count(index)) {
            A_[index][0] = 0;
        }
        const auto& it = prev(A_[index].upper_bound(snap_id));
        return it->second;
    }

private:
    unordered_map<int, map<int, int>> A_;
    int snap_id_ = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
