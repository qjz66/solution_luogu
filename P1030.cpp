#include "bits/stdc++.h"
#include "string"

using namespace std;

#define MAX 8

string mid, post;//pre�Ž����mid������.post����
int num = 0;
char h[MAX];

void get_pre(string mid1, string post1);//������
string get_midleft(string parent1, char b);//������������
string get_midright(string parent2, char c);//������������
string get_postleft(string parent3, string midleft);
string get_postright(string parent4, string midright);

int main(){
    cin >> mid;
    cin >> post;//�����ַ���
    get_pre(mid, post);
    return 0;
}

void get_pre(string mid1, string post1){
    if(mid1 == post1 && (mid1.length() == 1 || mid1.length() == 0)){
        cout << mid1;
        return;
    }//�ݹ��������
    int len = 0;
    char a;
    string left1, left2, right1, right2;
    while(mid1[len] != '\000')
        len++;//�õ��ڵ����
    a = post1[len - 1];
    cout << a;
    left1 = get_midleft(mid1, a);//�õ������������
    right1 = get_midright(mid1, a);//�õ�����������
    left2 = get_postleft(post1, left1);//�õ�����������
    right2 = get_postright(post1, right1);//�õ�����������
    get_pre(left1, left2);
    if(right2.length() == 2){
        cout << right2[1] << right2[0];
        return;
    }
    get_pre(right1, right2);
}

string get_midleft(string parent1, char b){
    int i = 0;//��λ���ڵ�
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