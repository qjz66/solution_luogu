//
// Created by qjz on 2023/5/2.
//
#include "iostream"
using namespace std;

int main(){
    int a, n, m, x;
    cin >> a>> n>> m>> x;//������cin>>a,n,m,x!!!!
    int sum[n], add[n -1];//sum ����װ�ڴ�վ�뿪ʱ������
    sum[0] = a;
    sum[1] = a;
    add[0] = a;
    if(x == 1 || x == 2)//��Ϊǰ��վ�ͺ���վ��ֱ�����
        cout << a;
    else if(x == n - 1 || x == n)
        cout << m;
    else{
        for(int i = 0;;i++){//ö���ڵڶ���վ�ϳ�������y
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