#include "bits/stdc++.h"

using namespace std;

typedef struct student{
    string name;
    int finalscore;//��ĩ�ɼ�
    int classscore;//�༶�ɼ�
    char iscadre;//�Ǹɲ�
    char iswest;//����ѧ��
    int n;//������
    int money;
}studentinfo;

int main(){
    int num;//ѧ������
    cin >> num;
    studentinfo a[num];
    for(int i = 0;i < num;i++){
        cin >> a[i].name >> a[i].finalscore >> a[i].classscore >> a[i].iscadre >> a[i].iswest >> a[i].n;
    }
    int academician[num],youth[num],score[num],west[num],classes[num];
    for(int i = 0;i < num;i++){
        //Ժʿ�����
        if(a[i].finalscore > 80 && a[i].n > 0)
            academician[i] = 1;
        else academician[i] = 0;
        if(a[i].finalscore > 85 && a[i].classscore >80)
            youth[i] = 1;
        else youth[i] = 0;
        if(a[i].finalscore > 90)
            score[i] = 1;
        else score[i] = 0;
        if(a[i].finalscore > 85 && a[i].iswest == 'Y')
            west[i] = 1;
        else west[i] = 0;
        if(a[i].classscore > 80 && a[i].iscadre == 'Y')
            classes[i] = 1;
        else classes[i] = 0;
    }
    for(int j = 0;j < num;j++){
        a[j].money = academician[j] * 8000 + youth[j] * 4000 + score[j] * 2000 + west[j] * 1000 + classes[j] * 850;
    }
    int maxmoney = a[0].money, max;
    for(int m = 1;m < num;m++){
        if(maxmoney < a[m].money){
            maxmoney = a[m].money;
            max = m;
        }
    }
    int sum = 0;
    for(int k = 0;k < num;k++)
        sum += a[k].money;
    cout << a[max].name << endl << a[max].money << endl << sum;
}