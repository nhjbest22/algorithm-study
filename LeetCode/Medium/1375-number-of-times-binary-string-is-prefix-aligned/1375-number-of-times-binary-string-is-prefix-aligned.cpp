class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int N = flips.size();
        int ans = 0;
        
        bool isFlipped[50'005] = {false, };
        priority_queue<int, vector<int>, greater<>> pq;
        for(int i = 1; i <= N; i++) pq.push(i);

        for(int i = 0; i < N; i++){
            auto& flip = flips[i];
            isFlipped[flip] = true;

            while(!pq.empty()){
                auto cur = pq.top();
                if(!isFlipped[cur]) break;

                pq.pop();
            }

            ans += (pq.empty() ? 1 : pq.top() > (i + 1));
        }

        return ans;
    }
};