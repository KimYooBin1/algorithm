#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    string str1, str2, str3, str4;
    cin >> str1 >> str2 >> str3 >> str4;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; i++) {
        if(str1[i] != str3[i]) continue;
        if(str2[i] == str4[i]){
            v1.push_back(str2[i] - '0');
        }else{
            cout<<"htg!\n";
            return 0;
        }
    }
    for(auto a: v1){
        cout << a;
    }
    cout << "\n";
    return 0;
}