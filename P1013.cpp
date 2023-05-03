#include "iostream"
#include "string"
using namespace std;

int a[200], b[200];//a b 分别存储翻转和未翻转数字
string s;//s存字符串

void trans(int l);//将字符串转化为对应进制整数存入a
void turn(int l);//将a翻转存入b
int add(int n, int l);//高精度加
bool judge(int l);//判断是否为回文

int main(){
    int n, l, ans;//n为进制数，l为字符串长度，ans为步骤数
    cin >> n >> s;
    l = s.length();
    trans(l);//将字符串转化为数字只做一次，后续的判断，相加等都在a中进行，省去互相转换的步骤
    for(ans = 1;ans <= 30;ans++){
        turn(l);
        l = add(n, l);//得到新数字的长度
        if(judge(l)){//若为回文串则输出ans
            cout << "STEP=" << ans;
            return 0;
        }
    }
    cout << "Impossible!";//从循环中出来只可能是ans > 30
    return  0;
}

void trans(int l){
    for(int i = 0;i < l;i++){
        if(s[l - i - 1] >= '0' && s[l - i - 1] <= '9')//若为0-9则 - ‘0’ 将其转化为数字
            a[i] = s[l - i - 1] - '0';
        else//为A-F则- 'A' + 10转化为数字
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
        a[i + 1] += (a[i] + b[i]) / n;//先算a[i + 1]以免a[i]被改变
        a[i] = (a[i] + b[i]) % n;//mod n
    }
    while(a[l] != 0) l++;//更新l
    return l;
}

bool judge(int l){
    for(int i = 0;i < l / 2;i++){
        if(a[i] != a[l - i - 1])//只要有一个不相等返回false
            return false;
    }
    return true;
}