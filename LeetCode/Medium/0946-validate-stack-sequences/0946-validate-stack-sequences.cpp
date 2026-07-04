class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;

        int push = 0;
        int N = pushed.size();
        
        for(int i = 0; i < N; i++){
            while(s.empty() || s.top() != popped[i]){
                if(push == N) break;

                s.push(pushed[push++]);
            }

            if(s.top() != popped[i]) return false;

            s.pop();
        }

        return true;
    }
};