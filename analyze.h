#include<bits/stdc++.h>
using namespace std;

static stack<double> num;
static stack<char> opt;
static char fln[100];

void calc()
{
    double b=num.top();num.pop();
    double a=num.top();num.pop();
    char op=opt.top();opt.pop();
    switch(op)
    {
        case '+': num.push(a+b);break;
        case '-': num.push(a-b);break;
        case '*': num.push(a*b);break;
        case '/': num.push(a/b);break;
        case '^': num.push(pow(a,b));break;
    }
}

double getval(string s,double x)
{
    while(!num.empty()) num.pop();
    while(!opt.empty()) opt.pop();
    int p=0;s+='#';
    while(p<s.length())
    {
        char c=s[p++];
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
            
            case 'x':
                num.push(x);
                break;

            default:
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