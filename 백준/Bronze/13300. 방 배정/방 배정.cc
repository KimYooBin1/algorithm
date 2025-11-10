#include<cstring>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
struct student {
    int s, y;
};
int main(){
    FIO;
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    map<int, int> fm;
    for (int i = 0; i < n; i++) {
        int s, y;
        cin>>s>>y;
        if(s == 1){
            m[y]++;
        }else{
            fm[y]++;
        }
    }
    int result = 0;
    for (int i = 1; i <= 6; i++) {
        result += m[i] / k + (m[i] % k ? 1 : 0) + fm[i] / k + (fm[i] % k ? 1 : 0);
    }
    cout << result << "\n";
}