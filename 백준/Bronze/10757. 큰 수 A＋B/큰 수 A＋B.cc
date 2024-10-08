#include <iostream>
#include <algorithm>
#include <vector>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int main() {
    FIO;
    string str1, str2;
    cin >> str1 >> str2;
    int length1 = str1.length();
    int length2 = str2.length();
    vector<int> v1(length1);
    vector<int> v2(length2);

    for (int i = 0; i < length1; i++) {
        v1[i] = str1[i] - '0';
    }
    for (int i = 0; i < length2; i++) {
        v2[i] = str2[i] - '0';
    }

    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());

    vector<int> result(max(length1, length2) + 1, 0);
    int index = 0;
    for (; index < min(length1, length2); index++) {
        result[index] += v1[index] + v2[index];
        if (10 <= result[index]) {
            result[index + 1]++;
            result[index] -= 10;
        }
    }
    if(length1 < length2){
        for (; index < length2; index++) {
            result[index] += v2[index];
            if(10 <= result[index]){
                result[index] -= 10;
                result[index + 1] += 1;
            }
        }
    }else if(length2 < length1){
        for (; index < length1; index++) {
            result[index] += v1[index];
            if(10 <= result[index]){
                result[index] -= 10;
                result[index + 1] += 1;
            }
        }
    }
    reverse(result.begin(), result.end());

    bool check = false;
    for (int i = 0; i < max(length1, length2) + 1; i++) {
        if(!check && !result[i]) continue;
        check = true;
        cout << result[i];
    }
    cout << "\n";
}