#include<cstring>
#include<deque>
#include<stack>
#include<iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    FIO;
    int n;
    cin >> n;
    deque<int> result;
    stack<int> tmp;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            tmp.push(result.back());
            result.pop_back();
        }
        result.push_back(i + 1);
        while (!tmp.empty()) {
            result.push_back(tmp.top());
            tmp.pop();
        }
    }




    for (auto &num: result) {
        cout << num << " ";
    }
    cout << "\n";

}