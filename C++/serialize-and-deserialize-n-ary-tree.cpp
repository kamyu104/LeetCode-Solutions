// Time:  O(n)
// Space: O(h)

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {        
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        int start = 0;
        return deserializeHelper(data, &start);
    }

private:
    void serializeHelper(const Node *root, ostringstream& out) {
        if (!root)  {
            return;
        }

        out << root->val << " ";
        for (const auto& child : root->children) {
            serializeHelper(child, out);
        }
        out <<  "# ";
    }
    
    Node *deserializeHelper(const string& data, int *start) {
        int num;
        if (!getNumber(data, start, &num)) {
            return nullptr;
        }
        auto root = new Node(num);
        for (auto child = deserializeHelper(data, start);
             child != nullptr; 
             child = deserializeHelper(data, start)) {
            root->children.emplace_back(child);
        }
        return root;
    }

    bool getNumber(const string& data, int *start, int *num) {
        int sign = 1;
        if (data[*start] == '#') {
            *start += 2;  // Skip "# ".
            return false;
        } else if (data[*start] == '-') {
            sign = -1;
            ++(*start);
        }

        for (*num = 0; isdigit(data[*start]); ++(*start)) {
            *num = *num * 10 + data[*start] - '0';
        }
        *num *= sign;
        ++(*start);  // Skip " ".

        return true;
    }
};

// Time:  O(n)
// Space: O(n)
class Codec2 {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {        
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        istringstream in(data);  // Space: O(n)
        return deserializeHelper(in);
    }

private:
    void serializeHelper(const Node *root, ostringstream& out) {
        if (!root)  {
            return;
        }

        out << root->val << " ";
        for (const auto& child : root->children) {
            serializeHelper(child, out);
        }
        out <<  "# ";
    }

    Node *deserializeHelper(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        }
        auto root = new Node(stoi(val));
        for (auto child = deserializeHelper(in);
             child != nullptr; 
             child = deserializeHelper(in)) {
            root->children.emplace_back(child);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
