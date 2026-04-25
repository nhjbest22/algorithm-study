#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
    int num;
    double get,sum = 0;
    cin >> num;
    vector<double> v;
    for (int i =0; i < num; i++){
        cin >> get;
        v.push_back(get);
    }
    double M = v[0];
    for (int i = 0 ; i < num; i++){
        M = max(M,v[i]);
    }
    for (int i =0; i< num;i++){
        sum += v[i];
    }
    cout<<double(sum/M*100/num)<<endl;


    return 0;
}