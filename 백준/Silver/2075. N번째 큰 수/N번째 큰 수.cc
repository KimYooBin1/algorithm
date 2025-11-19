#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
//    vector<vector<int>> v(n, vector<int>(n));
//    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            pq.push(num);
            if(pq.size() > n) pq.pop();
        }
    }
//    while(--n) {
//        cout << pq.top() << " ";
//        pq.pop();
//    }
//    cout << "\n";
    cout << pq.top() << "\n";

}