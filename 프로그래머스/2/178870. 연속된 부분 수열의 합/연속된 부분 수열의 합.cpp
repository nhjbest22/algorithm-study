#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define debug(x) cout<<#x<<" is "<<x<<endl;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int N = sequence.size();
    
    answer.push_back(0); answer.push_back(N);
    
    int st = -1, st_sum = 0, en_sum = 0;
    for(int en = 0; en < N; en++){
        en_sum += sequence[en];
        
        while(en_sum - st_sum > k){
            st_sum += sequence[++st];
        }
        
        if(en_sum - st_sum == k){
            if(answer[1] - answer[0] < en - st){
                continue;
            }
            
            answer[1] = en;
            answer[0] = st + 1;
        }
    }
    return answer;
}