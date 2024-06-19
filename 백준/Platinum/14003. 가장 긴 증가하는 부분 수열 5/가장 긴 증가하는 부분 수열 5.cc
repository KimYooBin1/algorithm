
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_SIZE 1000000
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int dir[MAX_SIZE];
int num[MAX_SIZE];
//int lower_bound(int s, int e, int value, vector<int> v){
//    while(s<e){
//        int m = (s + e) / 2;
//        if(v[m] < value){
//            s = m + 1;
//        }
//        else{
//            e = m;
//        }
//    }
//    return e;
//}

int main(){
    FIO;
    int n;
    cin>>n;
    vector<int> ret;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>num[i];
        auto index = lower_bound(ret.begin(), ret.end(), num[i]);
//        auto a=lower_bound(ret.begin(),ret.end(),num);
        dir[i] = index - ret.begin() + 1;
        if(index==ret.end()){
            ret.push_back(num[i]);
            ans+=1;
        }
        else{
            *index=num[i];
            
        }
    }
    cout<<ans<<"\n";
    vector<int> result;

    for(int i=n-1;i>=0;i--){

        if(dir[i] == ans){
            ans--;
            result.push_back(num[i]);
        }
    }
    reverse(result.begin(), result.end());
    cout<<"\n";
    for (auto a: result) {
        cout<<a<<" ";
    }
    cout<<"\n";
}