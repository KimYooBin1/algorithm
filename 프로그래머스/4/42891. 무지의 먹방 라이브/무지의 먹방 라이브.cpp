#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
struct food {
    ll time;
    ll index;
};
struct compare {
    bool operator ()(const food & a, const food & b){
        return a.time > b.time;
    }
};
int solution(vector<int> food_times, ll k) {
    ll sum = 0;
    for(auto & time: food_times){
        sum += time;
    }
    if(sum <= k) return -1;
    
    priority_queue<food, vector<food>, compare> pq;
    for(int i=1;i<=food_times.size();i++){
        pq.push({food_times[i - 1], i});
    }
    
    ll ate_food = 0;
    while((pq.top().time - ate_food) * pq.size() <= k){
        k -= (pq.top().time - ate_food) * pq.size();
        ate_food += pq.top().time - ate_food;
        pq.pop();
    }
    vector<ll> v;
    while(!pq.empty()){
        v.push_back(pq.top().index);
        pq.pop();
        
    }
    sort(v.begin(), v.end());

    return v[k % v.size()];
}