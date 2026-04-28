#include<string>
#include <iostream>

using namespace std;

int cnt;

bool solution(string s)
{
    for(auto& c: s){
        if(c == '(') {
            cnt++;
            continue;
        }
        
        if(!cnt) return false;
        cnt--;
    }
    
    return cnt == 0;
}