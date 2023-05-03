//
// Created by qjz on 2023/5/1.
//
#include "iostream"
using namespace std;

int main(){
    long long  n, factor = 1, sum = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        factor = factor * i;
        sum += factor;
    }
    cout << sum;
    return 0;
}