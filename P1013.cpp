#include "iostream"
#include "string"
using namespace std;

int main(){
    int n, m, flag;
    cin >> n >> m;//n为指定的进制,m为初始数字；
    for(int i = 1;i <= 30;i++){//至多循环30次
        int l, c, d;//存字符串长度，方便得到反串
        string a, b, e;//a存m转化为的字符串,b存他的相反串
        flag = 1;
        a = to_string(m);
        b = to_string(m);
        l = int(a.length());
        for(int j = 0; j < l; j++){//得到反串
            b[j] = a[l - j - 1];
        }
        c = stoi(a, 0, n);
        d = stoi(b, 0, n);
        m = c + d;//得到新的m
        e = to_string(m);
        l = e.length();
        for(int m = 0;m < l / 2;m++){
            if(e[m] != e[l - m - 1]){//若不为回文，将flag置0并退出循环
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