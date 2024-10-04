#include <iostream>
#include <vector>
#include <algorithm>
#define FIO ios_base::sync_with_stdio(false); std::cin.tie(NULL);
using namespace std;
int main()
{
    FIO;
    while(true){
        vector<int> result;
        int n, p;
        cin>>n;
        if(!n) break;
        cin>>p;
        result.push_back(n+1-p);
        // 홀수
        if(p%2){
            result.push_back(p+1);
            result.push_back(n+1-(p+1));
        }
        // 짝수수
        else{
            result.push_back(p-1);
            result.push_back(n+1-(p-1));
        }
        sort(result.begin(), result.end());
        for(auto a: result){
            cout<<a<<" ";
        }
        cout<<"\n";
    }

    return 0;
}