#include "iostream"
using namespace std;
//用递推的思想解决
//以4为例 4 41 42 421有四种 可以将其分为4本身+2的数目+1的数目
//同上推出fn = 1 + f(n/2) + f(n/2-1) + ... + f1
//从小到大递推f1->f2->f3->f4.....
//用 一个数组来存fn(n <= 1000)
int main(){
    long long f[1001] = {0};
    int n;
    cin >> n;
    for(int i = 1;i < 1001;i++){
        for(int j = 1;j <= i / 2;j++)
            f[i] += f[j];
        f[i]++;
    }
    cout << f[n];
}

