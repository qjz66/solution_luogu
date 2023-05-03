//
// Created by qjz on 2023/5/2.
//
#include "iostream"
#include "cmath"
using namespace std;

void divide(int n);

int main(){
    int n ;
    cin >> n;
    divide(n);
    return 0;
}

void divide(int n){//注意：“”里面是字符串，‘’里面是字符！！！！
    for(int i = 14;i >= 0;i--){ //从高到低寻找幂次
        if(pow(2, i) <= n){
            if(i == 1) cout << "2";//如果i=1，不用继续递归分解
            else if(i == 0) cout << "2(0)";//i=0,也不用递归分解
            else{
                cout << "2(";
                divide(i);//递归，将i分解
                cout << ")";
            }
            n = n - int(pow(2, i));//循环分解剩下的部分
            if (n != 0) cout << '+';//如果后面还有数则加一个'+'
        }
    }
}