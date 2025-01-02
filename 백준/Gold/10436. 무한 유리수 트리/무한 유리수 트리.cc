#include<cstring>
#include<iostream>
#include<tuple>
#include<vector>
using namespace std;
pair<int,int> calc(string str){
    int num = 0;
    int index = 0;
    vector<int> result;
    while (index < str.length()) {
        if (str[index] == '/') {
            result.push_back(num);
            num = 0;
            index++;
            continue;
        }
        num = num * 10 + str[index++] - '0';
    }
    result.push_back(num);
    return {result[0], result[1]};
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int index;
        string str;
        cin >> index >> str;
        int left, right;
        tie(left, right) = calc(str);
        if(right == 1){
            cout << index << " " << 1 << "/" << left + 1 << "\n";
            continue;
        }
        int k = left / right;
        int x = left % right;
        int y = right - x;
        x = x + y;
        y = y + x * k;
        cout << index << " " << x << "/" << y << "\n";
    }
}