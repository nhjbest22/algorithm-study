#include <string>
#include <vector>


using namespace std;

int GCD(int a, int b){
    if(b == 0) return a;
    
    return GCD(b, a%b);
}

int LCM(int a, int b){
    return a/GCD(a,b)*b;
}

int solution(vector<int> arr) {
    int lcm = 1;
    for(int i = 0; i < arr.size(); i++){
        lcm = LCM(lcm, arr[i]);
    }
    
    return lcm;
}