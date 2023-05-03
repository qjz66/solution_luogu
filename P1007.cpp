//
// Created by qjz on 2023/5/1.
//
#include "iostream"
#include "cmath"
#include "algorithm"

using namespace std;

int main(){
    int l, n, mintime = 0, maxtime = 0;
    cin>> l >> n;
    int a[n];
    if(!n){
        cout<< "0 0";
        return 0;
    }
    for(int i = 0;i < n;i++)
        cin>> a[i];
    sort(a, a + n);//对距离做排序
    for(int j = 0;j < n;j++){
        mintime = max(min(a[j], l + 1 - a[j]), mintime); //最小时间是所有人的最小时间中最大的
    }
    maxtime = max(l + 1 - a[0], a[n - 1]);//最大时间是两端点到较远端点的距离
    cout<< mintime << ' ' << maxtime;
}