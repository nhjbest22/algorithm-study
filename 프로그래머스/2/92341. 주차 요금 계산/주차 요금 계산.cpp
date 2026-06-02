#include <bits/stdc++.h>

using namespace std;

#define cost COST

int timeToMinute(const string& t){
    int hour = stoi(t.substr(0,2));
    int minute = stoi(t.substr(3));
    
    return 60*hour + minute;
}

vector<string> parse_string(const string& str){
    vector<string> ret;
    int prev = 0;
    int cur;
    
    while((cur = str.find(" ", prev)) != string::npos){
        ret.push_back(str.substr(prev, cur - prev));
        
        prev = cur + 1;
    }
    ret.push_back(str.substr(prev));
    
    return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    unordered_map<string, int> carToIn; // 번호, 입차 시간
    unordered_map<string, int> carToTime; // 번호, 누적 시간
    
    for(auto& record: records){
        auto r = parse_string(record);
        
        string& t = r[0];
        string& carNo = r[1];
        string& op = r[2];
        
        int event_time = timeToMinute(t);
        
        if(op == "IN"){
            carToIn[carNo] = event_time;
            continue;
        }
        
        int inTime = carToIn[carNo];
        carToIn.erase(carNo);
        
        carToTime[carNo] += (event_time - inTime);
    }
    
    int enTime = timeToMinute("23:59");
    
    for(auto p: carToIn){
        string carNo = p.first;
        int inTime = p.second;
        
        carToTime[carNo] += (enTime - inTime);
    }
    
    vector<pair<int, int>> cost; // 차량 번호, 주차 비용
    
    int& basic_duration = fees[0];
    int& basic_cost = fees[1];
    
    int& unit_duration = fees[2];
    int& unit_cost = fees[3];
    
    for(auto p: carToTime){
        int carNo = stoi(p.first);
        int duration = p.second;
        
        int c = basic_cost;
        duration -= basic_duration;
    
        if(duration > 0){
            c += (duration / unit_duration) * unit_cost;
            c += (duration % unit_duration > 0 ? unit_cost : 0);
        }
        
        cost.push_back({carNo, c});
    }
    
    sort(cost.begin(), cost.end());
    
    for(auto& p: cost){
        answer.push_back(p.second);
    }
    
    return answer;
}