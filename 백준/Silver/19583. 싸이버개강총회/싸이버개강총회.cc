#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int time1, time2, time3;
int calc(string & str){
    return 60 * (str[0] * 10 + str[1]) + str[3] * 10 + str[4];
}

int main(){
    FIO;
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    time1 = calc(str1);
    time2 = calc(str2);
    time3 = calc(str3);

    string input_time, name;
    map<string, bool> m;
    int result = 0;
    while (cin >> input_time >> name) {
//        if(input_time == "0") break;
        int time = calc(input_time);
        // 제 시간에 입장
        if(time <= time1) m[name] = false;
        else if (time2 <= time && time <= time3) {
            if(m.find(name) == m.end()) continue;
            if(m[name]) continue;
            m[name] = true;
            result++;
        }

    }
    cout << result << "\n";
}