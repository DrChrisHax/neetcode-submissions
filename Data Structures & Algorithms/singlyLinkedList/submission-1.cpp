struct Node {
    int val;
    Node* next;  
};

class LinkedList {
public:
    LinkedList() {
        head_ = new Node(-1, nullptr);
    }

    ~LinkedList() {
        while(head_) {
            Node* temp = head_->next;
            delete head_;
            head_ = temp;
        }
    }

    int get(int index) {
        Node* curr = head_->next;
        while (curr && index > 0) {
            curr = curr->next;
            --index;
        }
        if (curr) {
            return curr->val;
        } else {
            return -1;
        }
    }

    void insertHead(int val) {
        Node* temp = head_->next;
        Node* newNode = new Node(val, temp);
        head_->next = newNode;   
    }
    
    void insertTail(int val) {
        Node* curr = head_;
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = new Node(val, nullptr);
    }

    bool remove(int index) {
        Node* prev = head_;
        Node* curr = head_->next;
        while (curr && index > 0) {
            prev = curr;
            curr = curr->next;
            --index;
        }

        if (curr) {
            prev->next = curr->next;
            delete curr;
            return true;
        } else {
            return false;
        }
    }

    vector<int> getValues() {
        std::vector<int> res;
        Node* curr = head_->next;
        while(curr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }

private:
    Node* head_;
};
