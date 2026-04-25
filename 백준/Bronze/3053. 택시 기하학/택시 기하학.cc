#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#define PI 3.14159265358979323846264338327950288419716
using namespace std;
int main (){
    
    double num;
    cin>>num;
    cout.precision(10);
    printf("%lf\n",num*num*PI);
    cout.precision(10);
    cout<<num*num*2<<endl;
    return 0;
}