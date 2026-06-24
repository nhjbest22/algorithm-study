class MinStack {
public:
    pair<int, int> stack[30'005];
    int ptr;

    MinStack() {
        ptr = 0;
    }
    
    void push(int value) {
        int MIN = ptr ? min(stack[ptr-1].second, value) : value;

        stack[ptr++] = {value, MIN};
    }
    
    void pop() {
        ptr--;
    }
    
    int top() {
        return stack[ptr-1].first;
    }
    
    int getMin() {
        return stack[ptr-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */