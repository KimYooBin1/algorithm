#include<cstring>
#include<iostream>
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define MAX_SIZE 2000001
bool arr[MAX_SIZE];

bool checkPalin(int x){
    std::string str = "";
    while(x){
        str += '0' + x % 10;
        x /= 10;
    }

    int s = 0;
    int e = str.length() - 1;
    while (s < e) {
        if(str[s++] != str[e--]) return false;
    }
    return true;
}
int main(){
    FIO;
    int n;
    std::cin >> n;
    for(int i=2;i<MAX_SIZE;i++){
        if(arr[i]) continue;
        for(int j=i*2;j<MAX_SIZE;j+=i){
            arr[j] = true;
        }
    }
    if(n == 1) n++;
     
    for (int i = n; i < MAX_SIZE; i++) {
        if(arr[i]) continue;
        if(!checkPalin(i)) continue;
        std::cout << i << "\n";
        return 0;
    }
}
