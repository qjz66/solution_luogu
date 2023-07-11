#include "bits/stdc++.h"

using namespace std;

typedef struct people{
    string name;
    int side;//0È¦ÄÚ 1È¦Íâ
}peopleinfo;

int main(){
    int n,m,start = 0,ans;
    cin >> n >> m;
    peopleinfo a[n];
    int b[m][2];
    for(int i = 0;i < n;i++)
        cin >> a[i].side >> a[i].name;
    for(int j = 0;j < m;j++){
        cin >> b[j][0] >> b[j][1];
    }
    for(int k =0;k < m;k++){
        if(a[start].side  == 0 && b[k][0] == 0 || a[start].side  == 1 && b[k][0] == 1){
            start = start - b[k][1];
            if(start < 0)
                start = start % n + n;
            else
                start = start % n;
        }else{
            start = start + b[k][1];
            if(start < 0)
                start = start % n + n;
            else
                start = start % n;
        }
    }
    ans = start;
    cout << a[ans].name;
}