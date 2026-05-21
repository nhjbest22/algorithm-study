#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i =a;i<b;i++)

int solution(string s) {
    vector<string> numbers = {"zero" ,"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for(int i = 0; i < 10; i++){
        regex r = regex(numbers[i]);
        s = regex_replace(s, r, to_string(i));
    }
    
    

    return stoi(s);
}