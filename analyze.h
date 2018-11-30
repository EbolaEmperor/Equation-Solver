#include<bits/stdc++.h>
using namespace std;

static const char LG=1;
static const char LN=2;
static const char SIN=3;
static const char COS=4;
static const char TAN=5;

static stack<double> num;
static stack<char> opt;
static char fln[100];

void calc()
{
    double a,b=num.top();num.pop();
    char op=opt.top();opt.pop();
    if(op>5) a=num.top(),num.pop();
    switch(op)
    {
        case '+': num.push(a+b);break;
        case '-': num.push(a-b);break;
        case '*': num.push(a*b);break;
        case '/': num.push(a/b);break;
        case '^': num.push(pow(a,b));break;
        case LG: num.push(log10(b));break;
        case LN: num.push(log(b));break;
        case SIN: num.push(sin(b));break;
        case COS: num.push(cos(b));break;
        case TAN: num.push(tan(b));break;
    }
}

double getval(string s,double x)
{
    while(!num.empty()) num.pop();
    while(!opt.empty()) opt.pop();
    int p=0;s+='#';
    while(p<s.length())
    {
        double a;
        char c=s[p++],c1,c2;
        switch(c)
        {
            case '#': break;
            case '+': case '-':
                while(!opt.empty()&&opt.top()!='(') calc();
                opt.push(c);
                break;

            case '*': case '/':
                while(!opt.empty()&&opt.top()!='+'&&opt.top()!='-') calc();
                opt.push(c);
                break;
                
            case '(': case '^':
                opt.push(c);
                break;

            case ')':
                while(!opt.empty()&&opt.top()!='(') calc();
                opt.pop();
                break;
            
            case '!':
                a=num.top();
                if(fabs(round(a)-a)>1e-9) printf("No Factorial for Decimal!"),exit(0);
                for(int i=(int)round(a)-1;i>=1;i--) a*=i;
                num.pop();num.push(a);
                break;
            
            case 'x':
                num.push(x);
                break;
            
            case 'l':
                c1=s[p++];
                if(c1!='g'&&c1!='n') printf("Format Error!"),exit(0);
                if(c1=='g') opt.push(LG);
                if(c1=='n') opt.push(LN);
                break;
            
            case 's':
                c1=s[p++];c2=s[p++];
                if(c1!='i'||c2!='n') printf("Format Error!"),exit(0);
                opt.push(SIN);
                break;
            
            case 'c':
                c1=s[p++];c2=s[p++];
                if(c1!='o'||c2!='s') printf("Format Error!"),exit(0);
                opt.push(COS);
                break;
            
            case 't':
                c1=s[p++];c2=s[p++];
                if(c1!='a'||c2!='n') printf("Format Error!"),exit(0);
                opt.push(TAN);
                break;
            
            default:
                if(!isdigit(c)) printf("Format Error!"),exit(0);
                double v=0.0;int len=0;
                while(isdigit(c)||c=='.') fln[len++]=c,c=s[p++];
                fln[len]='\0';p--;
                sscanf(fln,"%lf",&v);
                num.push(v);
                break;
        }
    }
    while(!opt.empty()) calc();
    return num.top();
}
