class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto s: stones) pq.push(s);

        while(pq.size() > 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();

            int res = abs(a - b);

            if(res > 0) pq.push(res);
        }

        return pq.empty() ? 0 : pq.top();
    }
};
