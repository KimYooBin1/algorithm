#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

bool calc(string str1, string str2){
    vector<int> v1(26, 0);
    vector<int> v2(26, 0);
    int len1 = str1.length();
    int len2 = str2.length();
    if(abs(len1 - len2) > 1) return false;
    for (int i = 0; i < str1.length(); i++) {
        v1[str1[i] - 'A']++;
    }
    for (int i = 0; i < str2.length(); i++) {
        v2[str2[i] - 'A']++;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if(v1[i] == v2[i]) continue;
        if(abs(v1[i] - v2[i]) == 1){
            cnt++;
        }else return false;
    }
    return cnt < 3;

//    int sum1 = 0;
//    int sum2 = 0;
//    for (int i = 0; i < 26; i++) {
////        cout<<v1[i]<<" "<<v2[i]<<"\n";
//        if(v1[i] == v2[i]) continue;
//        else if(abs(v1[i] - v2[i]) == 1){
//            sum1 += v1[i] > v2[i] ? 1 : 0;
//            sum2 += v2[i] > v1[i] ? 1 : 0;
//        }
//        else return false;
//    }
//    return sum1 == 1 || sum2 == 1 || sum1 == sum2;

}

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int result = 0;
    for(int i=1;i<n;i++){
        if(calc(v[0], v[i])) result++;
    }

    cout<<result<<"\n";
}