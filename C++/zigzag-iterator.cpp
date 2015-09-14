// Time:  O(n)
// Space: O(1)

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            deq.emplace_back(make_pair(v1.size(), v1.begin()));
        }
        if (!v2.empty()) {
            deq.emplace_back(make_pair(v2.size(), v2.begin()));
        }
    }

    int next() {
        const auto len = deq.front().first;
        const auto it = deq.front().second;
        deq.pop_front();
        if (len > 1) {
            deq.emplace_back(make_pair(len - 1, it + 1));
        }
        return *it;
    }

    bool hasNext() {
        return !deq.empty();
    }

private:
    deque<pair<int, vector<int>::const_iterator>> deq;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
