#include<cstring>
#include<iostream>
using namespace std;
int main(){
    string str;
    cin>>str;
    char str1 = str[0];
    int result = 10;
    for(int i=1;i<str.length();i++){
        if(str1 != str[i]) {
            result += 10;
            str1 = str[i];
        }else result += 5;
    }
    cout<<result<<"\n";
}