#include "bits/stdc++.h"

using namespace std;

int main(){
    int num;
    cin >> num;
    int a[num + 1];
    for(int i = 0;i < num + 1;i++)
        cin >> a[i];
    if(num == 0){
        cout << a[0];
        return 0;
    }
    for(int j = num;j >= 0;j--){
        if(j == num){
            if(a[num - j] == 1)
                cout <<"x^" << j;
            else if(a[num - j] == -1)
                cout << '-' << "x^" << j;
            else
                cout << a[num - j] << "x^" << j;
        }else if(j == 1){
            if(a[num - j] == 1)
                cout << "+x";
            else if(a[num - j] == -1)
                cout << "-x";
            else{
                if(a[num - j] > 0)
                    cout << '+' << a[num - j] << 'x';
                else if(a[num - j] < 0)
                    cout << a[num - j] << 'x';
                else ;
            }
        }else if(j == 0){
            if(a[num - j] == 1)
                cout << "+1";
            else if(a[num - j] == -1)
                cout << "-1";
            else{
                if(a[num - j] == 0)
                    ;
                else if(a[num - j] > 0)
                    cout << '+' << a[num - j];
                else
                    cout << a[num - j];
            }
        }else{
            if(a[num - j] == 1)
                cout << "+x^" << j;
            else if(a[num - j] == -1)
                cout << "-x^" << j;
            else{
                if(a[num - j] > 0)
                    cout << '+' << a[num - j] << "x^" << j;
                else if(a[num - j] < 0)
                    cout << a[num - j] << "x^" << j;
                else ;
            }
        }
    }
}