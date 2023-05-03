#include "iostream"
#include "string"
using namespace std;

int a[200], b[200];//a b �ֱ�洢��ת��δ��ת����
string s;//s���ַ���

void trans(int l);//���ַ���ת��Ϊ��Ӧ������������a
void turn(int l);//��a��ת����b
int add(int n, int l);//�߾��ȼ�
bool judge(int l);//�ж��Ƿ�Ϊ����

int main(){
    int n, l, ans;//nΪ��������lΪ�ַ������ȣ�ansΪ������
    cin >> n >> s;
    l = s.length();
    trans(l);//���ַ���ת��Ϊ����ֻ��һ�Σ��������жϣ���ӵȶ���a�н��У�ʡȥ����ת���Ĳ���
    for(ans = 1;ans <= 30;ans++){
        turn(l);
        l = add(n, l);//�õ������ֵĳ���
        if(judge(l)){//��Ϊ���Ĵ������ans
            cout << "STEP=" << ans;
            return 0;
        }
    }
    cout << "Impossible!";//��ѭ���г���ֻ������ans > 30
    return  0;
}

void trans(int l){
    for(int i = 0;i < l;i++){
        if(s[l - i - 1] >= '0' && s[l - i - 1] <= '9')//��Ϊ0-9�� - ��0�� ����ת��Ϊ����
            a[i] = s[l - i - 1] - '0';
        else//ΪA-F��- 'A' + 10ת��Ϊ����
            a[i] = s[l - i - 1] - 'A' + 10;
    }
}

void turn(int l){
    for(int i = 0;i < l;i++){
        b[i] = a[l - i - 1];
    }
}

int add(int n, int l){
    for(int i = 0;i < l;i++){
        a[i + 1] += (a[i] + b[i]) / n;//����a[i + 1]����a[i]���ı�
        a[i] = (a[i] + b[i]) % n;//mod n
    }
    while(a[l] != 0) l++;//����l
    return l;
}

bool judge(int l){
    for(int i = 0;i < l / 2;i++){
        if(a[i] != a[l - i - 1])//ֻҪ��һ������ȷ���false
            return false;
    }
    return true;
}