#include <iostream>
#include <algorithm>
#include <vector>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
vector<int> calc(vector<int> &vec1, vector<int> &vec2) {
    reverse(vec1.begin(), vec1.end());
    reverse(vec2.begin(), vec2.end());
    int len1 = vec1.size();
    int len2 = vec2.size();
    vector<int> result(len1 + len2, 0);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            result[i+j] += vec1[i] * vec2[j];
        }
    }
    for (int i = 0; i < len1 + len2; i++) {
        if (10 <= result[i]) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    while(!result.back()){
        result.pop_back();
    }
    reverse(result.begin(), result.end());
    reverse(vec2.begin(), vec2.end());

    return result;
}
int main() {
    FIO;
    vector<int> num1;
    string str;
    int a;
    int point_cnt = 0;
    cin >> str >> a;
    for (int i = 0; i < str.length(); i++) {
        if(str[i] == '.') {
            point_cnt = 0;
            continue;
        }
        point_cnt += 1;
        num1.push_back(str[i] - '0');
    }
    vector<int> tmp = num1;
    for (int i = 1; i < a; i++) {
        vector<int> calc_result = calc(tmp, num1);

        tmp = calc_result;
    }
    point_cnt *= a;
    int len = tmp.size();
    vector<char> result;
    // 정수가 1이상일 때
    if(point_cnt < len){
        result = vector<char> (tmp.size() );
        for (int i = 0; i < len; i++) {
            result[i] = tmp[i] + '0';
        }
        auto index = result.begin();
        result.insert(index + tmp.size() - point_cnt, '.');
    }
    // 정수가 0일때
    else if(len <= point_cnt){
        result = vector<char> (point_cnt + 2, '0');
        result[1] = '.';
        for (int i = 0; i < tmp.size(); i++) {
            result[result.size() - tmp.size() + i] = tmp[i] + '0';
        }
    }
    for (auto c: result) {
        cout << c;
    }
    cout << "\n";
}


