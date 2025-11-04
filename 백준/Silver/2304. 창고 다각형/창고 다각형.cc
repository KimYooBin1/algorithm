#include<cstring>
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
struct stick {
    int index;
    int length;
};
int main(){
    FIO;
    int n;
    cin>>n;
    vector<stick> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].index >> s[i].length;
    }
    sort(s.begin(), s.end(), [](stick a, stick b) {
        return a.index < b.index;
    });
    int result = 0;

    int l = s[0].length;    // 최대 높이
    int last_index = s[0].index;    // 최대 높이를 가진 index
    stack<stick> ss;
    for(auto info : s){
        int index = info.index;
        int length = info.length;
//        cout << index << " " << result << "\n";
        // 0 번쨰 인덱스는 스킵
        if(index == last_index) continue;
        if(l <= length) {
            result += (index - last_index) * l;
            last_index = index;
            l = length;
            while(!ss.empty()) ss.pop();
        }else{
            while(!ss.empty() && ss.top().length <= length){
                ss.pop();
            }
            ss.push(stick{index, length});
        }
    }

    if(!ss.empty()){
        int index1 = ss.top().index;
        int length1 = ss.top().length;
        ss.pop();
        int index2 = 0;
        int length2 = 0;
        while (!ss.empty()) {
            index2 = ss.top().index;
            length2 = ss.top().length;
            ss.pop();
            result += (index1 - index2) * length1;

            index1 = index2;
            length1 = length2;
        }
        result += (index1 - last_index) * length1;
    }
    cout << result + l << "\n";
}

/**
*
7
2 4
11 8
15 4
4 6
5 3
8 10
13 6
*/
/**
*
7
2 4
11 6
15 4
4 6
5 3
8 10
13 8
*/