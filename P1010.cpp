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

void divide(int n){//ע�⣺�����������ַ����������������ַ���������
    for(int i = 14;i >= 0;i--){ //�Ӹߵ���Ѱ���ݴ�
        if(pow(2, i) <= n){
            if(i == 1) cout << "2";//���i=1�����ü����ݹ�ֽ�
            else if(i == 0) cout << "2(0)";//i=0,Ҳ���õݹ�ֽ�
            else{
                cout << "2(";
                divide(i);//�ݹ飬��i�ֽ�
                cout << ")";
            }
            n = n - int(pow(2, i));//ѭ���ֽ�ʣ�µĲ���
            if (n != 0) cout << '+';//������滹�������һ��'+'
        }
    }
}