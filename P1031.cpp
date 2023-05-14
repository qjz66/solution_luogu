#include "iostream"

using namespace std;

int main(){
    int n, sum, servage, ans = 0;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    servage = sum / n;
    for(int i = 0;i < n - 1;i++){
        if(a[i] != servage){
            a[i + 1] += a[i] - servage;
            a[i] = servage;
            ans++;
        }
    }
    cout << ans;
}
