class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min = std::numeric_limits<int>::max();
        if (!minStack_.empty()) {
            min = minStack_.top().second;
        }
        
        minStack_.push({val, std::min(val, min)});
    }
    
    void pop() {
        minStack_.pop();
    }
    
    int top() {
        return minStack_.top().first;
    }
    
    int getMin() {
        return minStack_.top().second;       
    }

private:
    std::stack<std::pair<int, int>> minStack_;
};
