#include "iostream"
using namespace std;
//�õ��Ƶ�˼����
//��4Ϊ�� 4 41 42 421������ ���Խ����Ϊ4����+2����Ŀ+1����Ŀ
//ͬ���Ƴ�fn = 1 + f(n/2) + f(n/2-1) + ... + f1
//��С�������f1->f2->f3->f4.....
//�� һ����������fn(n <= 1000)
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

