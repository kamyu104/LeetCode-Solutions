// Time:  O(n)
// Space: O(n)

struct Node {
    Node(int value) :
         val(value),
         next(nullptr),
         prev(nullptr) {}
    int val;
    Node *next;
    Node *prev;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : size_(0) {
        head_ = tail_ = new Node(-1);
        head_->next = tail_;
        tail_->prev = head_;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (0 <= index && index <= size_ / 2) {
            return forward(0, index, head_->next)->val;
        } else if (size_ / 2 < index && index < size_) {
            return backward(size_, index, tail_)->val;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list.
        After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        add(head_, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        add(tail_->prev, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list.
        If index equals to the length of linked list,
        the node will be appended to the end of linked list.
        If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (0 <= index && index <= size_ / 2) {
            add(forward(0, index, head_->next)->prev, val);
        } else if (size_ / 2 < index && index <= size_) {
            add(backward(size_, index, tail_)->prev, val);
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (0 <= index && index <= size_ / 2) {
            remove(forward(0, index, head_->next));
        } else if (size_ / 2 < index && index < size_) {
            remove(backward(size_, index, tail_));
        }
    }
    
private:
    void add(Node *preNode, int val) {
        auto node = new Node(val);
        node->prev = preNode;
        node->next = preNode->next;
        node->prev->next = node->next->prev = node;
        ++size_;
    }
        
    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        --size_;
    }
        
    Node *forward(int start, int end, Node *curr) {
        while (start != end) {
            ++start;
            curr = curr->next;
        }
        return curr;
    }
    
    Node *backward(int start, int end, Node *curr) {
        while (start != end) {
            --start;
            curr = curr->prev;
        }
        return curr;
    }

    Node *head_;
    Node *tail_;
    int size_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
 
