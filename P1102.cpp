#include "bits/stdc++.h"

using namespace std;

int n, c;
long long ans = 0;


int main(){
    /*cin >> n >> c;
    int a[n], b[n], start, end, mid, ans = 0, tmp;
    for(int i = 0;i < n;i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0;i < n - 1;i++){
        start = i + 1;
        end = n - 1;
        while(start <= end){
            mid = (start + end) / 2;
            if(a[mid] - a[i] == c){
                tmp = mid;
                while(a[mid--] == a[tmp])
                    ans++;
                mid = tmp;
                while(a[++mid] == a[tmp])
                    ans++;
                break;
            }else if(a[mid] - a[i] > c){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
    }*/
    map <int, int> m;
    cin >> n >> c;
    int a[n];
    for(int i =0 ;i < n;i++){
        cin >> a[i];
        m[a[i]]++;
        a[i] -= c;
    }
    for(int i = 0;i < n;i++)
        ans += m[a[i]];
    cout << ans << endl;
}
