#include "bits/stdc++.h"

using namespace std;
#define maxnum 50005
long long dis, ans;
int num, m;
int a[maxnum];

bool judge(int mid);

int main(){
    cin >> dis >> num >> m;
    int start = 0, end = dis, mid;
    for(int i = 1;i < num + 1;i++)
        cin >> a[i];
    a[num + 1] = dis;
    while(start <= end){
        mid = (start + end) / 2;
        if(judge(mid)){
            start = mid + 1;
            ans = mid;
        }else end = mid - 1;
    }
    cout << ans;
    return 0;
}

bool judge(int mid){
    int i = 1, now = 0, total = 0;
    while(i <= num + 1){
        if(a[i] - a[now] < mid){
            total++;
        }else now = i;
        i++;
    }
    if(total > m)
        return false;
    else return true;
}