#include<bits/stdc++.h>
using namespace std;
long long m,n,ans;
int main(){
    cin>>m>>n;
    if(m==n) ans--;
    n*=m;//�������Ļ�����n��
    for(long long i=1;i<=sqrt(n);i++){
        if(n%i==0&&__gcd(i,n/i)==m) ans+=2;
    }
    cout<<ans;
    return 0;
}