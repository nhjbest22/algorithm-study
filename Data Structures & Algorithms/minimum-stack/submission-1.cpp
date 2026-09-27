class MinStack {
private:
    vector<pair<int, int>> v;

public:
    MinStack() {
    }
    
    void push(int val) {
        int MIN = v.empty() ? val : min(v.back().second, val);
        v.push_back({val, MIN});
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
