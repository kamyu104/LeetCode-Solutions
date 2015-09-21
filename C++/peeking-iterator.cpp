// Time:  O(1) per peek(), next(), hasNext()
// Space: O(1)

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums), has_next_(Iterator::hasNext()) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!has_peeked_) {
            has_peeked_ = true;
            val_ = Iterator::next();
        }
        return val_;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        val_ = peek();
        has_peeked_ = false;
        has_next_ = Iterator::hasNext();
        return val_;
    }

    bool hasNext() const {
        return has_next_;
    }

private:
    int val_;
    bool has_next_;
    bool has_peeked_ = false;
};
