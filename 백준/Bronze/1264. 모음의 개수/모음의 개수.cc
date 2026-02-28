#include<cstring>
#include<iostream>
using namespace std;
int main(){
    string str;
    while(getline(cin, str)){
        int result = 0;
        if(str == "#") break;
        for(auto &c: str){

            if(c == 'a' || c=='e'||c=='i'||c=='o'||c=='u') result++;
            if(c == 'A' || c=='E'||c=='I'||c=='O'||c=='U') result++;

        }
        cout<<result<<"\n";
    }
}