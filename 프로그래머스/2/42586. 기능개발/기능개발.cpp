#include <string>
#include <vector>

using namespace std;

bool isDeployed[105];

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int N = progresses.size();
    int day = 0;
    
    int cur = 0;
    while(cur < N){
        if(isDeployed[cur]) {
            cur++;
            continue;
        }
        
        int cnt = 1;
        
        while(progresses[cur] + speeds[cur]*day < 100)
            day++;
        
        int nxt = cur + 1;
        while(nxt < N){
            if(isDeployed[nxt]) {
                nxt++;
                continue;
            }
            
            if(progresses[nxt] + speeds[nxt]*day < 100) {
                break;
            }

            isDeployed[nxt] = true;
            cnt++;

        }
        
        answer.push_back(cnt);
        
        cur = nxt;
    }    
    
    return answer;
}