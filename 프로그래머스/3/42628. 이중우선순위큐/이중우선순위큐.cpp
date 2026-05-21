#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<string> split(string& str, string delimeter){
    vector<string> res;
    
    int prev = 0;
    int pos;
    string token;
    
    while((pos = str.find(delimeter, prev)) != string::npos){
        token = str.substr(prev, pos);
        res.push_back(token);
        
        prev = pos + 1;
    }
    
    res.push_back(str.substr(prev));
    return res;
}

vector<int> solution(vector<string> operations) {
    multiset<int> s;
    
    for(string& op: operations){
        string OP = op.substr(0 ,1);
        int num = stoi(op.substr(2));
        
        if(OP == "I"){
            s.insert(num);
            continue;
        }
        
        if(s.empty()) continue;
        
        if(num == -1) s.erase(s.begin());
        else s.erase(prev(s.end()));
    }
    
    if(s.empty()) return {0, 0};
    else return {*(prev(s.end())), *(s.begin())};
}