#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<tuple>
#include<set>
using namespace std;

struct J{
    int m,v;
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<J> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].m>>v[i].v;
    }
    multiset<int> bag;
    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        bag.insert(tmp);
    }
    sort(v.begin(), v.end(), [](J a, J b){
        return a.v>b.v;
    });
    long long ret=0;
    for(int i=0;i<v.size();i++){
        auto a = bag.lower_bound(v[i].m);
        if(bag.end() == a){
            continue;
        }
        else{
            ret += v[i].v;
            bag.erase(a);
        }
    }
    cout<<ret<<"\n";
}