#include <string>
#include <vector>

using namespace std;

int timeToInt(string pos){
    string min = pos.substr(0, 2);
    string sec = pos.substr(3, 2);
    
    return 60*stoi(min) + stoi(sec);
}

string intTotime(int curTime){
    int min = curTime/60;
    int sec = curTime % 60;
    
    string m_str = to_string(min);
    string s_str = to_string(sec);
    
    return (m_str.length() == 1 ? ("0" + m_str) : m_str) + ":" + (s_str.length() == 1 ? ("0" + s_str) : s_str);
}

int cur, total;
int opStart, opEnd;



string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    total = timeToInt(video_len);
    cur = timeToInt(pos);
    opStart = timeToInt(op_start);
    opEnd = timeToInt(op_end);
    
    for(auto& com: commands){
        if(cur >= opStart && cur <= opEnd)
            cur = opEnd;

        if(com == "prev"){
            cur = max(cur - 10, 0);
        }else{
            cur = min(cur + 10, total);
        }
        
        if(cur >= opStart && cur <= opEnd)
            cur = opEnd;

    }
    
    
    
    
    string ret = intTotime(cur);
    // 마지막에 오프닝 건너뛰기
    return ret;
}