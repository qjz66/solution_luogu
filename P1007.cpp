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
    sort(a, a + n);//�Ծ���������
    for(int j = 0;j < n;j++){
        mintime = max(min(a[j], l + 1 - a[j]), mintime); //��Сʱ���������˵���Сʱ��������
    }
    maxtime = max(l + 1 - a[0], a[n - 1]);//���ʱ�������˵㵽��Զ�˵�ľ���
    cout<< mintime << ' ' << maxtime;
}