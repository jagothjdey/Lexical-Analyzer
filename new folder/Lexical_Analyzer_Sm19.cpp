#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define SZ(a) (int) a.size()

set<string>Identifier,Constant,Keywords,Delimeter,Operator;
map<string,int>MKey,Moperator,Mdelimiter;

void MappingObject(void)
{
    MKey["int"]=1;MKey["void"]=1;MKey["main"]=1;MKey["float"]=1;MKey["double"]=1;MKey["return"]=1;
    Moperator["+"]=1;Moperator["-"]=1;Moperator["*"]=1;Moperator["/"]=1;Moperator["%"]=1;Moperator["="]=1;
    Mdelimiter["{"]=1;Mdelimiter["}"]=1;Mdelimiter["("]=1;Mdelimiter[")"]=1;Mdelimiter["["]=1;Mdelimiter["]"]=1;Mdelimiter[";"]=1;
    return;
}

vector<string> RemoveWhiteSpace(string str)
{
    int len=(int)str.size();
    vector<string>ans;string s;
    for(int i=0;i<len;i++)
    {
        if(str[i]==' '){if(!s.empty())ans.push_back(s);s.clear();}
        else s+=str[i];
    }
    return ans;
}

bool Key(string str)
{
    return (MKey.count(str));
}

bool Iden(string str)
{
    int len=str.size();
    for(int i=0;i<len;i++) if(!isalpha(str[i])) return 0;
    return 1;
}

bool Cons(string str)
{
    for(int i=0;i<str.size();i++)
    {
        if(isdigit(str[i]) || str[i]=='.'){}
        else return 0;
    }
    return 1;
}

bool Delim(string str)
{
    return (Mdelimiter.count(str));
}

bool Opert(string str)
{
    return (Moperator.count(str));
}

void LexicalAnalyzer(vector<string> V)
{
    int len=V.size();
    for(int i=0;i<len;i++)
    {
        if(Key(V[i])) Keywords.insert(V[i]);
        else if(Iden(V[i])) Identifier.insert(V[i]);
        else if(Cons(V[i])) Constant.insert(V[i]);
        else if(Delim(V[i])) Delimeter.insert(V[i]);
        else if(Opert(V[i])) Operator.insert(V[i]);
    }
    return;
}

void OutputTheResult(void)
{
    set<string> :: iterator it;
    if(SZ(Identifier)) puts("\n\nAll Identifier:---->> ");
    for(it=Identifier.begin();it!=Identifier.end();it++)
    {
        cout<<(*it)<<endl;
    }
    if(SZ(Constant)) puts("\nAll Constants:----->> ");
    for(it=Constant.begin();it!=Constant.end();it++)
    {
        cout<<(*it)<<endl;
    }
    if(SZ(Keywords)) puts("\nAll Keywords:----->> ");
    for(it=Keywords.begin();it!=Keywords.end();it++)
    {
        cout<<(*it)<<endl;
    }
    if(SZ(Delimeter)) puts("\nAll Delimiter:----->> ");
    for(it=Delimeter.begin();it!=Delimeter.end();it++)
    {
        cout<<(*it)<<endl;
    }
    if(SZ(Operator)) puts("\nAll Operator:----->> ");
    for(it=Operator.begin();it!=Operator.end();it++)
    {
        cout<<(*it)<<endl;
    }
    puts("");

    return;
}

vector<string>ParsingStr(string str)
{
    int len=SZ(str);
    string s;vector<string>ans;
    for(int i=0;i<len;i++)
    {
        if(str[i]==' ')
        {
            if(!s.empty()) {ans.push_back(s);s.clear();}
        }
        if(Delim((string(1,str[i]))))
        {
            ans.push_back(string(1,str[i]));
            if(!s.empty()) {ans.push_back(s);s.clear();}
        }
        else if(Opert(string(1,str[i])))
        {
            ans.push_back(string(1,str[i]));
            if(!s.empty()) {ans.push_back(s);s.clear();}
        }
        else s+=str[i];
    }
    return ans;
}

int main()
{
    MappingObject();
    string str;
    while(getline(cin,str))
    {
        str+=" ";
        //vector<string> V=RemoveWhiteSpace(str);
        vector<string> V=ParsingStr(str);

//        for(int i=0;i<SZ(V);i++)
//        {
//            cout<<i<<" "<<V[i]<<endl;
//        }

        LexicalAnalyzer(V);
        OutputTheResult();
    }
    return 0;
}


/**

int main(){ret 0;}
int k=123.1231;

**/
