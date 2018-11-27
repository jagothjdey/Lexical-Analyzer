#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

#define SZ(a) (int) a.size()
#define pb push_back
#define mem(a) memset(a,b,sizeof(a))
#define FORI(a,b) for(int i=a;i<(int)b;i++)
#define FORJ(a,b) for(int j=a;j<(int)b;j++)
#define FOREACH(it,x)for(__typeof((x.begin())) it=x.begin();it!=x.end();it++)


typedef vector<string> VS;
typedef pair<int,int> PII;
typedef vector<pair<int,int> >VPII;
typedef map<string,int> MS;

set<string>Comment,Header,Define;
set<string>Identifier,Constant,Keywords,Delimeter,Operator;
map<string,int>MKey,Moperator,Mdelimiter;

void MappingKey(void)
{
    MKey["adjustfield"]=1;MKey["basefield"]=1;MKey["boolalpha"]=1;MKey["floatfield"]=1;MKey["internal"]=1;
	MKey["scientific"]=1;MKey["setbase"]=1;MKey["setiosflags"]=1;MKey["setprecision"]=1;MKey["showbase"]=1;
	MKey["showpoint"]=1;MKey["showpos"]=1;MKey["uppercase"]=1;MKey["_Bool"]=1;MKey["_Complex"]=1;
	MKey["_Imaginary"]=1;MKey["EXIT_FAILURE"]=1;MKey["EXIT_SUCCESS"]=1;MKey["size_t"]=1;MKey["bool"]=1;
	MKey["catch"]=1;MKey["class"]=1;MKey["const_cast"]=1;MKey["delete"]=1;MKey["dynamic_cast"]=1;
	MKey["explicit"]=1;MKey["export"]=1;MKey["false"]=1;MKey["friend"]=1;MKey["mutable"]=1;
	MKey["namespace"]=1;MKey["operator"]=1;MKey["private"]=1;MKey["protected"]=1;MKey["public"]=1;
	MKey["reinterpret_cast"]=1;MKey["static_cast"]=1;MKey["template"]=1;MKey["this"]=1;MKey["throw"]=1;
	MKey["true"]=1;MKey["typeid"]=1;MKey["typename"]=1;MKey["using"]=1;MKey["virtual"]=1;
	MKey["wchar_t"]=1;MKey["and_eq"]=1;MKey["bitand"]=1;MKey["bitor"]=1;MKey["compl"]=1;
	MKey["not_eq"]=1;MKey["or_eq"]=1;MKey["xor_eq"]=1;MKey["define"]=1;MKey["defined"]=1;
	MKey["elif"]=1;MKey["endif"]=1;MKey["error"]=1;MKey["ifdef"]=1;MKey["ifndef"]=1;
	MKey["include"]=1;MKey["pragma"]=1;MKey["undef"]=1;MKey["exception"]=1;MKey["bad_alloc"]=1;
	MKey["bad_exception"]=1;MKey["bad_cast"]=1;MKey["bad_typeid"]=1;MKey["ios_base::failure"]=1;MKey["logic_error"]=1;
	MKey["domain_error"]=1;MKey["invalid_argument"]=1;MKey["length_error"]=1;MKey["out_of_range"]=1;MKey["runtime_error"]=1;
	MKey["range_error"]=1;MKey["overflow_error"]=1;MKey["underflow_error"]=1;MKey["uncaught_exception"]=1;MKey["__DATE__"]=1;
	MKey["__FILE__"]=1;MKey["__LINE__"]=1;MKey["__STDC__"]=1;MKey["__STDC_HOSTED__"]=1;MKey["__STDC_IEC_559__"]=1;
	MKey["__STDC_IEC_559_COMPLEX__"]=1;MKey["__STDC_ISO_10646__"]=1;MKey["__STDC_VERSION__"]=1;MKey["__TIME__"]=1;MKey["__func__"]=1;
	MKey["__cplusplus"]=1;MKey["__BORLANDC__"]=1;MKey["__CYGWIN__"]=1;MKey["__CYGWIN32__"]=1;MKey["__GNUC__"]=1;
	MKey["__WIN32__"]=1;MKey["__WINDOWS__"]=1;MKey["assert"]=1;MKey["ctype"]=1;MKey["errno"]=1;
	MKey["float"]=1;MKey["limits"]=1;MKey["locale"]=1;MKey["math"]=1;MKey["setjmp"]=1;
	MKey["signal"]=1;MKey["stdarg"]=1;MKey["stddef"]=1;MKey["stdio"]=1;MKey["stdlib"]=1;
	MKey["string"]=1;MKey["time"]=1;MKey["complex"]=1;MKey["fenv"]=1;MKey["inttypes"]=1;
	MKey["iso646"]=1;MKey["stdbool"]=1;MKey["stdint"]=1;MKey["tgmath"]=1;MKey["wchar"]=1;
	MKey["wctype"]=1;MKey["algorithm"]=1;MKey["bitset"]=1;MKey["complex"]=1;MKey["deque"]=1;
	MKey["exception"]=1;MKey["fstream"]=1;MKey["functional"]=1;MKey["iomanip"]=1;MKey["ios"]=1;
	MKey["iosfwd"]=1;MKey["iostream"]=1;MKey["istream"]=1;MKey["iterator"]=1;MKey["limits"]=1;
	MKey["list"]=1;MKey["locale"]=1;MKey["map"]=1;MKey["memory"]=1;MKey["new"]=1;
	MKey["numeric"]=1;MKey["ostream"]=1;MKey["queue"]=1;MKey["set"]=1;MKey["sstream"]=1;
	MKey["stack"]=1;MKey["stdexcept"]=1;MKey["streambuf"]=1;MKey["string"]=1;MKey["typeinfo"]=1;
	MKey["utility"]=1;MKey["valarray"]=1;MKey["vector"]=1;MKey["cassert"]=1;MKey["cctype"]=1;
	MKey["cerrno"]=1;MKey["cfloat"]=1;MKey["climits"]=1;MKey["clocale"]=1;MKey["cmath"]=1;
	MKey["csetjmp"]=1;MKey["csignal"]=1;MKey["cstdarg"]=1;MKey["cstddef"]=1;MKey["cstdio"]=1;
	MKey["cstdlib"]=1;MKey["cstring"]=1;MKey["ctime"]=1; MKey["for"]=1; MKey["return"]=1;
	MKey["int"]=1; MKey["main"]=1; MKey["std"]=1;

}

void MappingObject(void)
{
    MappingKey();
    Moperator["+"]=1;Moperator["-"]=1;Moperator["*"]=1;Moperator["/"]=1;Moperator["%"]=1;Moperator["="]=1;
    Moperator["&"]=1;Moperator["=|"]=1; Moperator["!"]=1;Moperator["~"]=1;Moperator["^"]=1;
    Mdelimiter["{"]=1;Mdelimiter["}"]=1;Mdelimiter["("]=1;Mdelimiter[")"]=1;Mdelimiter["["]=1;Mdelimiter["]"]=1;
    Mdelimiter[";"]=1;Mdelimiter[","]=1;
    return;
}

string MakeStr(string str)
{
    string a;
    for(int i=0;i<SZ(str)-1;i++)
    {
        char c1,c2;
        c1=str[i];c2=str[i+1];
        if(c1=='/' and c2=='/') Comment.insert(str);
        else if(c1=='#' and c2=='i') Header.insert(str);
        else if(c1=='#' and c2=='d') Define.insert(str);
    }
    return str;
}

bool Key(string str)
{
//    cout<<"Mkey: "<<str<<endl;
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
    //cout<<"Opert: "<<str<<endl;
    return (Moperator.count(str));
}


void TakeIt(string a)
{
    if(a.empty()) return;
    if(Cons(a)) Constant.insert(a);
    else if(Key(a)) Keywords.insert(a);
    else if(Iden(a)) Identifier.insert(a);
}

void MakeToken(string str)
{
    string a;
    str+="  ";
    for(int i=0;i<SZ(str);i++)
    {
        if(str[i]==' ')
        {
            TakeIt(a);
            a.clear();
        }
        else
        {
            char c1=str[i];char c2=str[i+1];
            if(c1=='&' and c2=='&')
            {
                if(!a.empty()) TakeIt(a);a.clear();
                Operator.insert(string(2,c1));
            }
            else if(c1=='|' and c2=='|')
            {
                if(!a.empty()) TakeIt(a);a.clear();
                Operator.insert(string(2,c1));
            }
            else if(c1=='=' and c2=='=')
            {
                if(!a.empty()) TakeIt(a);a.clear();
                Operator.insert(string(2,c1));
            }
            else if(c1=='>' and c2== '=')
            {
                if(!a.empty()) TakeIt(a);a.clear();
                string t;t+=(char)c1;t+=(char)c2; Operator.insert(t);
            }
            else if(c1=='<' and c2=='=')
            {
                if(!a.empty()) TakeIt(a);a.clear();
                string t;t+=(char)c1;t+=(char)c2;Operator.insert(t);
            }
            else if(Opert(string(1,str[i])))
            {
                if(!a.empty()) TakeIt(a);a.clear();
                Operator.insert(string(1,str[i]));
            }
            else if(Delim(string(1,str[i])))
            {
                if(!a.empty()) TakeIt(a);a.clear();
                Delimeter.insert(string(1,str[i]));
            }
            else a+=str[i];
        }
    }

    return;
}

void ShowResult(void)
{
    if(SZ(Comment))
    {
        puts("Coments:\n");
        FOREACH(it,Comment) cout<<(*it)<<endl;
    }
    if(SZ(Header))
    {
        puts("\nHeader:\n");
        FOREACH(it,Header) cout<<(*it)<<endl;
    }
    if(SZ(Define))
    {
        puts("\nDefine :\n");
        FOREACH(it,Define) cout<<(*it)<<endl;
    }
    if(SZ(Identifier ))
    {
        puts("\nIdetifire:\n");
        FOREACH(it,Identifier) cout<<(*it)<<endl;
    }
    if(SZ(Constant ))
    {
        puts("\nContant:\n");
        FOREACH(it,Constant) cout<<(*it)<<endl;
    }
    if(SZ(Keywords))
    {
        puts("\nKeywords:\n");
        FOREACH(it,Keywords) cout<<(*it)<<endl;
    }
    if(SZ(Delimeter))
    {
        puts("\nDelimeter:\n");
        FOREACH(it,Delimeter) cout<<(*it)<<endl;
    }
    if(SZ(Operator))
    {
        puts("\nOprator: \n");
        FOREACH(it,Operator) cout<<(*it)<<endl;
    }
    return;
}

void ResetAll(void)
{
    Comment.clear(),Header.clear(),Define.clear();
    Identifier.clear(),Constant.clear(),Keywords.clear();
    Delimeter.clear(),Operator.clear();
    return;
}

int main()
{
    freopen("IN.txt","r",stdin);
    //freopen("OUT.txt","w",stdout);

    string str;
    MappingObject();
    puts("*********************  Lexical Analyzer  **************************\n");

    int cas=0;
    while(getline(cin,str))
    {
        if(str.empty()) continue;
        for(int i=0;i<SZ(str);i++)
        {
            if(str[i]==' ') continue;
            else
            {
                str=MakeStr(str.substr(i));
                //cout<<"Str: "<<str<<endl;
                break;
            }
        }
        MakeToken(str);
        cout<<"Line "<<++cas<<"  --- "<<str<<endl;
    }

    ShowResult();
    ResetAll();
    return 0;
}

