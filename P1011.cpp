//
// Created by qjz on 2023/5/2.
//
#include "iostream"
using namespace std;

int main(){
    int a, n, m, x;
    cin >> a>> n>> m>> x;//不能用cin>>a,n,m,x!!!!
    int sum[n], add[n -1];//sum 用来装在此站离开时的人数
    sum[0] = a;
    sum[1] = a;
    add[0] = a;
    if(x == 1 || x == 2)//若为前两站和后两站可直接输出
        cout << a;
    else if(x == n - 1 || x == n)
        cout << m;
    else{
        for(int i = 0;;i++){//枚举在第二个站上车的人数y
            for(int j = 1;j <= n - 2;j++){
                if(j <= 1) add[j] = i;
                else{
                    add[j] = add[j - 2] + add[j - 1];
                    sum[j] = sum[j - 1] + add[j - 2];
                }
            }
            if(sum[n - 2] == m) break;
        }
        cout << sum[x - 1];
    }
    return 0;
}