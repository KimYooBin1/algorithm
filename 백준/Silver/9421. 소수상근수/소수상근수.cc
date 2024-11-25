#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n+1, 0);
    for (int i = 2; i <= n; i++) {
        if(v[i] == 1) continue;
        for (int j = i * 2; j <= n; j += i) {
            v[j] = 1;
        }
    }
    vector<int> result;
    for (int i = 2; i < v.size(); i++) {
        if(v[i] == 1) continue;
        map<int,int> m;
        bool check = true;
        int num = i;
        while(true){
            if(num == 1) break;
            int sum = 0;
            while(true){
                int tmp = num % 10;
                sum += tmp * tmp;
                num /= 10;
                if (num == 0) break;
            }
            if(m.find(sum) != m.end()){
                check = false;
                break;
            }
            m[sum] = 1;
            num = sum;
        }
        if(!check) continue;
        result.push_back(i);
    }
    for(auto & num: result){
        cout << num << "\n";
    }
}