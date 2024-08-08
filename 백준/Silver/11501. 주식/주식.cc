#include<cstring>
#include<iostream>
#include<stack>
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
typedef long long ll;
int main(){
    FIO;
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        ll arr[n];
        std::stack<int> s;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
            s.push(arr[i]);
        }
        ll result = 0;
        int max_price = s.top(); s.pop();
        while (!s.empty()) {
            int current = s.top(); s.pop();
            if(max_price < current){
                max_price = current;
                continue;
            }
            result += max_price - current;
        }
        std::cout << result << "\n";
    }
    return 0;
}