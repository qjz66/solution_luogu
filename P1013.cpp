#include "iostream"
#include "string"
using namespace std;

int main(){
    int n, m, flag;
    cin >> n >> m;//nΪָ���Ľ���,mΪ��ʼ���֣�
    for(int i = 1;i <= 30;i++){//����ѭ��30��
        int l, c, d;//���ַ������ȣ�����õ�����
        string a, b, e;//a��mת��Ϊ���ַ���,b�������෴��
        flag = 1;
        a = to_string(m);
        b = to_string(m);
        l = int(a.length());
        for(int j = 0; j < l; j++){//�õ�����
            b[j] = a[l - j - 1];
        }
        c = stoi(a, 0, n);
        d = stoi(b, 0, n);
        m = c + d;//�õ��µ�m
        e = to_string(m);
        l = e.length();
        for(int m = 0;m < l / 2;m++){
            if(e[m] != e[l - m - 1]){//����Ϊ���ģ���flag��0���˳�ѭ��
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << "STEP=" << i;
            return 0;
        }
    }
    cout << "Impossible!";
    return  0;
}