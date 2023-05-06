#include "iostream"
#include "cmath"
#include "iomanip"
using namespace std;
int num = 0;
double a, b, c, d;
void iterate(double x, double y);

int main(){
   double step = 1;//stepΪ����
   double i = -100, j;
   cin >> a >> b >> c >>d;
   while(num < 3 && i < 100){
       j = i + 1;
       double f1 = a * pow(i,3) + b * pow(i,2) + c * i + d;
       double f2 = a * pow(j,3) + b * pow(j,2) + c * (j) + d;
       if(!f1){//���f1Ϊ0����ֱ�������ǰi
           printf("%.2lf ", i);
           num++;
       }
       if((f1 > 0 && f2 < 0) || (f1 < 0 && f2 > 0))//�м��и��ö��ֵݹ�
           iterate(i, j);
       i += step;
   }
    return 0;
}

void iterate(double x, double y){
    double mid = (x + y) / 2;
    double fl = a * pow(x,3) + b * pow(x,2) + c * x + d;
    double f = a * pow(mid,3) + b * pow(mid,2) + c * mid + d;
    if(y - x < 0.001){
        printf("%.2lf ", mid);
        num++;
        return;
    }
    if((fl > 0 && f < 0) || (fl < 0 && f > 0))
        iterate(x, mid);
    else
        iterate(mid , y);
}