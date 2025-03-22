#include<cstring>
#include<iostream>
#include<stack>
using namespace std;
bool check[1000000];
int main(){
    string a,b;
    cin>>a>>b;
    int str1=a.length();
    int str2=b.length();
    if(str2==1){
        for(int i=0;i<str1;i++){
            if(a[i]==b[0]){
                check[i]=true;
            }
        }
    }
    else{
        stack<pair<int,int>> s;
        for(int i=0;i<str1;i++){
            if(a[i]==b[0]){
                s.push(make_pair(i,0));
            }
            else{
                if(!s.empty()){
                    auto q=s.top();
                    if(a[i]==b[q.second+1]){
                        s.push(make_pair(i,q.second+1));
                        if(q.second+1==str2-1){
                            for(int j=0;j<str2;j++){
                                auto q=s.top();
                                check[q.first]=true;
                                s.pop();
                            }
                        }
                    }
                    else{
                        while(!s.empty()){
                            s.pop();
                        }
                    }
                }
            }
        }
    }
    bool ok=false;
    for(int i=0;i<str1;i++){
        if(check[i]==false){
            cout<<a[i];
            ok=true;
        }
    }
    if(!ok){
        cout<<"FRULA";
    }
    cout<<"\n";
}