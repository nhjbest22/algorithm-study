class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    int K;

    KthLargest(int k, vector<int>& nums) {
        pq = priority_queue<int, vector<int>, greater<>> ();
        K = k;

        for(auto num: nums) pq.push(num);
        while(pq.size() > k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K) pq.pop();

        return pq.top();
    }
};
