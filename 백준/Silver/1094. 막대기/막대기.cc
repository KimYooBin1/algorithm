#include<cstring>
#include<iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    int n;
    cin >> n;
    int len = 64;
    int totalLen = 0;
    int count = 0;
    int stickCount = 1;
    while(totalLen != n){
        if(n < totalLen + len){
            len /= 2;
            stickCount *= 2;
        }else{
            for (int i = 0; i < stickCount; i++) {
                if(n < totalLen + len) break;
                totalLen += len;
                count++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}