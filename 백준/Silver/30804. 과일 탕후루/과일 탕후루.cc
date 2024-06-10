#include <cstring>
#include <iostream>
#include <set>
#include <map>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 200001
using namespace std;
int arr[MAX_SIZE];
int main(){
    FIO;
    set<int> s;
    map<int, int> m;
    int n;
    cin>>n;
    int start = 0;
    int end = 0;
    int result = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(end < n){
//        cout<<start<<" "<<end<<"\n";
        s.insert(arr[end]);
        m[arr[end]]++;
        // 과일의 종류가 2개를 넘었을 떄
        while(2 < s.size()){
            m[arr[start]]--;
            if(m[arr[start]] == 0){
                s.erase(arr[start]);
            }
            start++;
        }
        result = max(result, end-start+1);
        end++;
    }
    cout<<result<<"\n";
}