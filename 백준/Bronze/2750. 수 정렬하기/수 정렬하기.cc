#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main (){
    vector<int> v;
    int num, get;
    cin >> num;
    for (int i = 0; i < num; i++){
        cin>>get;
        v.push_back(get);
    }
    sort(v.begin(), v.end());
    for (auto i: v){
        cout<<i<<endl;
    }



    return 0;
}