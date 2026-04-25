#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int arr[26];

int main (){
    string str;
    int line;
    char ch;
    int num = 0;
    cin >> line;
    for (int i = 0 ; i < line;i++){
        for (int i = 0 ; i< 26;i++){
            arr[i] = 0;
        }
        cin >> str;
        ch = str[0];
        arr[ch -'a']++;
        if (str.size() == 1){
            num++;
            continue;
        }
        for (int i = 0; i < str.size()-1;i++){
            if (str[i+1] != str[i])
            {
                if(arr[str[i+1]-'a'] != 0)
                    break;
                if (i == str.size()-2)
                    num++;
                arr[str[i+1]-'a']++; 
            }
            else if(i == str.size()-2)
                num++;
        }
    }
    cout<<num;
    return 0;
}