// Time:  O(n)
// Space: O(1)

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    using IT = vector<NestedInteger>::iterator;
    NestedIterator(vector<NestedInteger> &nestedList) {
        nodes_.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        const auto result = nodes_.top().first->getInteger();
        ++nodes_.top().first;
        return result;
    }
    
    bool hasNext() {
        while (!nodes_.empty()) {
            auto& cur = nodes_.top();
            if (cur.first == cur.second) {
                nodes_.pop();
            } else if (cur.first->isInteger()) {
                return true;
            } else {
                auto& nestedList = cur.first->getList();
                ++cur.first;
                nodes_.emplace(nestedList.begin(), nestedList.end());
            }
        }
        return false;
    }
private:
    stack<pair<IT, IT>> nodes_;
};

// Time:  O(n)
// Space: O(n)
class NestedIterator2 {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = static_cast<int>(nestedList.size()) - 1; i >= 0; --i) {
            nodes_.emplace(&nestedList[i]);
        }
    }

    int next() {
        auto result = nodes_.top()->getInteger();
        nodes_.pop();
        return result;
    }
    
    bool hasNext() {
        while (!nodes_.empty()) {
            auto *cur = nodes_.top();
            if (cur->isInteger()) {
                return true;
            }
            nodes_.pop();
            auto& children = cur->getList();
            for (int i = static_cast<int>(children.size()) - 1; i >= 0; --i) {
                nodes_.emplace(&children[i]);
            }
        }
        return false;
    }

private:
    stack<NestedInteger *> nodes_;
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
 
