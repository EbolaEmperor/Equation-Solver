#include<bits/stdc++.h>
#include "analyze.h"
using namespace std;

static string a,b;
static double l,r,ans,f=1e18;
static int eps;

double getdelta(double x)
{
    double res=fabs(getval(a,x)-getval(b,x));
    if(res<f) f=res,ans=x;
    return res;
}
double RAND(){return (double)rand()/RAND_MAX;}
double accept(double d,double t){return d<0||RAND()<exp(-d/t);}
void anneal(double tem,double dta,double end)
{
    double p=0,now=getdelta(p);
    while(tem>end)
    {
        double x=p+tem*RAND()-tem/2;
        double nxtans=getdelta(x);
        if(accept(nxtans-now,tem))
            now=nxtans,p=x;
        tem*=dta;
    }
}

void output(int eps,double x)
{
    char format[10],res[30];
    format[0]='%';format[1]='.';
    sprintf(format+2,"%d",eps);
    int p=strlen(format);
    format[p++]='l';
    format[p++]='f';
    format[p]='\0';
    printf(format,x);
}

int main(int argv,char* argc[])
{
    srand(time(0));
    char *equ=argc[1];int eps;
    sscanf(argc[2],"%d",&eps);
    if(*equ=='-') a+='0';
    while(*equ!='=') a+=*equ,equ++;equ++;
    if(*equ=='-') b+='0';
    while(*equ!='\0') b+=*equ,equ++;
    double EPS=pow(10.0,-1.0*eps);
    anneal(2e9,0.9998,EPS/1000.0);
    if(getdelta(ans)>1e-3) printf("No Sulotion!");
    else printf("The answer is: "),output(eps,ans);
    return 0;
}