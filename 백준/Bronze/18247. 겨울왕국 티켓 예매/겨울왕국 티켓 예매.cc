#include<cstring>
#include<iostream>
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
int main(){
    FIO;
    int t, n, m;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        if(m < 4 || n < 12){
            std::cout << "-1\n";
            continue;
        }
        std::cout << m * 11 + 4 << "\n";
    }
    return 0;
}