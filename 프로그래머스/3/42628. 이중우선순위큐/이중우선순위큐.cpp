#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    set<int> s;
    
    for(string& op: operations){
        stringstream ss(op);
        
        char OP;
        int num;
        
        ss >> OP >> num;
        
        if(OP == 'I'){
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