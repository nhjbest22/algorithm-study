#include <iostream>
#include <vector>
long long sum (std::vector<int> &a){
    long long Sum = 0;
    long long num = a.size();
    for (long long i=0; i< num;i++){
        Sum += a[i];
    }
    return Sum;
}
