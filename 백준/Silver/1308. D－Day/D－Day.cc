#include <cstring>
#include <iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int D[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 *
 * @return true : 평년 29일
 *         false : 윤년 28일
 */
bool check(int year){
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0) return false;
            else return true;
        }else return false;
    }
    return true;
}

int main(){
    FIO;
    int syear, smonth, sday;
    int eyear, emonth, eday;
    cin >> syear >> smonth >> sday;
    cin >> eyear >> emonth >> eday;
    if(syear == eyear){
        if(smonth == emonth){
            cout << "D-" << eday - sday << "\n";
            return 0;
        }
        else{
            int result = -sday;
            for (int i = smonth; i < emonth; i++) {
                if(!check(syear) && i == 2) result++;
                result += D[i];
            }
            result += eday;
            cout << "D-" << result << "\n";
        }
        return 0;
    }
    if (1000 < eyear - syear || (1000 == eyear - syear && (smonth < emonth || (smonth == emonth && sday <= eday)))) {
        cout << "gg\n";
        return 0;
    }
    // 시작 년도
    int remain_day = -sday;
    for (int i = smonth; i <= 12; i++) {
        if (!check(syear) && i == 2) remain_day++;
        remain_day += D[i];
    }

    for (int i = syear + 1; i < eyear; i++) {
        remain_day += 365;
        if(!check(i)) remain_day++;
    }
    //마지막 년도
    for (int i = 1; i < emonth; i++) {
        remain_day += D[i];
        if (!check(eyear) && i == 2) remain_day++;
    }
    remain_day += eday;

    cout << "D-" << remain_day << "\n";
    return 0;
}