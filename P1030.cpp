#include "bits/stdc++.h"
#include "string"

using namespace std;

#define MAX 8

string mid, post;//pre放结果，mid存中序.post后序
int num = 0;
char h[MAX];

void get_pre(string mid1, string post1);//找先序
string get_midleft(string parent1, char b);//找中序左子树
string get_midright(string parent2, char c);//找中序右子树
string get_postleft(string parent3, string midleft);
string get_postright(string parent4, string midright);

int main(){
    cin >> mid;
    cin >> post;//读入字符串
    get_pre(mid, post);
    return 0;
}

void get_pre(string mid1, string post1){
    if(mid1 == post1 && (mid1.length() == 1 || mid1.length() == 0)){
        cout << mid1;
        return;
    }//递归结束条件
    int len = 0;
    char a;
    string left1, left2, right1, right2;
    while(mid1[len] != '\000')
        len++;//得到节点个数
    a = post1[len - 1];
    cout << a;
    left1 = get_midleft(mid1, a);//得到中序的左序列
    right1 = get_midright(mid1, a);//得到中序右序列
    left2 = get_postleft(post1, left1);//得到后序左序列
    right2 = get_postright(post1, right1);//得到中序左序列
    get_pre(left1, left2);
    if(right2.length() == 2){
        cout << right2[1] << right2[0];
        return;
    }
    get_pre(right1, right2);
}

string get_midleft(string parent1, char b){
    int i = 0;//定位根节点
    while(parent1[i] != b)
        i++;
    string a(i, 'x');
    for(int j = i - 1;j >= 0;j--)
        a[j] = parent1[j];
    return a;
}

string get_midright(string parent2, char c){
    int leng = parent2.length(),i;

    leng--;
    i = leng;
    while(parent2[leng] != c)
        leng--;
    string a(i - leng, 'x');
    for(int j = i;j > leng;j--)
        a[j - leng - 1] = parent2[j];
    return a;
}

string get_postleft(string parent3, string midleft){
    int leng = midleft.length();
    string a(leng, 'x');
    for(int i = 0;i < leng;i++)
        for(int j = 0;j < leng;j++){
            if(parent3[i] == midleft[j]){
                a[i] = parent3[i];
                break;
            }
        }
    return a;
}

string get_postright(string parent4, string midright){
    int leng1 = midright.length(), leng2 = parent4.length();
    string a(leng1, 'x');
    for(int i = leng2 - 2;i > leng2 - 2 - leng1;i--){
        for(int j = 0;j < leng1;j ++){
            if(parent4[i] == midright[j]){
                a[leng1 - 1 - (leng2 - 2 - i)] = midright[j];
                break;
            }
        }
    }
    return a;
}