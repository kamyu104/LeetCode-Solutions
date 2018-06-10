// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    enum { OPEN = 1, CLOSE = -1};
    
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<vector<int>> events;
        set<int> Xvals;
        for (const auto& rec: rectangles) {
            events.emplace_back(vector<int>{rec[1], OPEN, rec[0], rec[2]});
            events.emplace_back(vector<int>{rec[3], CLOSE, rec[0], rec[2]});
            Xvals.emplace(rec[0]);
            Xvals.emplace(rec[2]);
        }
        sort(events.begin(), events.end());
        vector<int> X(Xvals.cbegin(), Xvals.cend());
        unordered_map<int, int> Xi;
        for (int i = 0; i < X.size(); ++i) {
            Xi[X[i]] = i;
        }

        auto st = new SegmentTreeNode(0, X.size() - 1, X);
        int64_t result = 0;
        int64_t cur_x_sum = 0;
        int cur_y = events[0][0];
        for (const auto& event: events) {
            int y = event[0], type = event[1], x1 = event[2], x2 = event[3];
            result += cur_x_sum * (y - cur_y);
            cur_x_sum = st->update(Xi[x1], Xi[x2], type);
            cur_y = y;
        }
        return result % static_cast<int64_t>(1e9 + 7);
    }

    class SegmentTreeNode {
    public:
        SegmentTreeNode(int start, int end, const vector<int>& X) :
            start_(start),
            end_(end),
            X_(X),
            left_(nullptr),
            right_(nullptr),
            count_(0),
            total_(0) {
        }

        int mid() const {
            return start_ + (end_ - start_) / 2;
        }

        SegmentTreeNode *left() {
            if (left_ == nullptr) {
                left_ = new SegmentTreeNode(start_, mid(), X_);
            }
            return left_;
        }

        SegmentTreeNode *right() {
            if (right_ == nullptr) {
                right_ = new SegmentTreeNode(mid(), end_, X_);
            }
            return right_;
        }
        
        int64_t total() const {
            return total_;
        }

        int64_t update(int i, int j, int val) {
            if (i >= j) {
                return 0;
            }
            if (start_ == i && end_ == j) {
                count_ += val;
            } else {
                left()->update(i, min(mid(), j), val);
                right()->update(max(mid(), i), j, val);
            }
            if (count_ > 0) {
                total_ = X_[end_] - X_[start_];
            } else {
                total_ = left()->total() + right()->total();
            }
            return total_;
        }
        
    private:
        int start_, end_;
        const vector<int>& X_;
        SegmentTreeNode *left_, *right_;
        int count_;
        int64_t total_;
    };
};
