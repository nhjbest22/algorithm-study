class MinStack {
public:
    vector<pair<int ,int>> v;

    MinStack() {
        v.clear();
    }
    
    void push(int value) {
        if(v.empty()){
            v.push_back({value, value});
            return;
        }

        auto& b = v.back();
        v.push_back({value, min(value, b.second)});
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
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