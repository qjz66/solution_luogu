#include "bits/stdc++.h"

using namespace std;

int maxvalue, num;

bool cmp(int a, int b);

int main(){
    cin >> maxvalue >> num;
    int a[num], ans = 0, s = 0, t = num - 1;
    for(int i = 0;i < num;i++)
        cin >> a[i];
    sort(a, a + num, cmp);
    while(s <= t){
        if(s == t){
            ans++;
            break;
        }
        if(a[s] + a[t] <= maxvalue){
            ans++;
            s++;
            t--;
        }else{
            s++;
            ans++;
        }
    }
    cout << ans << endl;
}

bool cmp(int a, int b){
    return a > b;
}