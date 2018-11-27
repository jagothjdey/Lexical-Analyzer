#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<iostream>
#include<string>
#include<math.h>
#include<set>
#include <sstream>

using namespace std;

#define pb(b) push_back(b);
#define oo (1<<29)
#define ll long long
#define mp(a,b) make_pair(a,b)
#define PI  2.0*acos(0.0)
#define Reverse(x) reverse(x.begin(),x.end())

// prime number upto 50 {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
//set<ll>s;
//set<ll>:: iterator it;
//v.erase(unique(v.begin(),v.end()),v.end());
//map<string,int>mymap;
//map<string,int>:: iterator it;
// reverse(aa.begin(),aa.end()); /// for string


/// binary to decimal

//int ans=0;
//    for(int i=0;i<j;i++)
//    {
//        ans=ans*2+str[i]-'0';
//    }


/// string to int
//string a="10";
//ss<<a;
//int ans;
//ss>>ans;
//printf("%d\n", ans+20);
//

/// int to string
//int a=10;
//string aa;
//ss<<a;
//aa=ss.str();
//cout<<aa<<endl;



///int rr[]= {-1,-1,0,0,1,1};
///int cc[]= {-1,0,-1,1,0,1};
///int rr[]= {0,0,1,-1};/*4 side move*/
///int cc[]= {-1,1,0,0};/*4 side move*/
///int rr[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int cc[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int rr[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
///int cc[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

#define mx 100100

char str[mx];
string aa,bb;
vector<string>keyword,store_the_word,store_the_headerfile,store_the_comment,store_the_define;

void make_keyword(void);
void make_token(void);
void token_type(void);

int main(void)
{
    int i,j;
    make_keyword();
    freopen("input1.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while(getline(cin,bb))
    {
        if( bb.size()==0 ) continue;
        int tem,flag=0;
        for(i=0;i<(int)bb.size();i++)
        {
            if( bb[i]==' ' ) continue;
            else
            {
//                printf("tem is:%d\n", tem);
                tem=i;
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            aa="";
            for(i=tem;i<(int)bb.size();i++) aa+=bb[i];
//            cout<<aa<<endl;
        }

        if( aa[0]=='/' && aa[1]=='/' )
        {
            store_the_comment.pb(aa);
        }
        else if( aa[0]=='#' && aa[1]=='i')
        {
            store_the_headerfile.pb(aa);
        }
        else if( aa[0]=='#' && aa[1]=='d' )
        {
            store_the_define.pb(aa);
        }
        else if( aa[0]!='#' || (aa[0]!='/' && aa[1]!='/') )
        {
            if( aa[aa.size()-1]!=';' )
            {
                aa+=' ';
            }
            make_token();
        }
        aa.clear();
        bb.clear();
    }


    token_type();
    for(i=0;i<(int)store_the_word.size();i++)
    {
        cout<<store_the_word[i]<<endl;
    }

    return 0;
}

void make_keyword(void)
{
    keyword.pb("and"); keyword.pb("and_eq"); keyword.pb("asm"); keyword.pb("auto"); keyword.pb("bitand");keyword.pb("bitor");  keyword.pb("bool");
    keyword.pb("break"); keyword.pb("case"); keyword.pb("catch"); keyword.pb("char"); keyword.pb("class");keyword.pb("compl");  keyword.pb("const");
    keyword.pb("const_cast"); keyword.pb("continue"); keyword.pb("default"); keyword.pb("delete"); keyword.pb("do"); keyword.pb("double");  keyword.pb("dynamic_cast");
    keyword.pb("else");keyword.pb("enum");keyword.pb("explicit");keyword.pb("export");keyword.pb("extern");keyword.pb("false");keyword.pb("float");
    keyword.pb("for");keyword.pb("friend");keyword.pb("goto");keyword.pb("if");keyword.pb("inline");keyword.pb("int");keyword.pb("long");
    keyword.pb("mutable");keyword.pb("namespace");keyword.pb("new");keyword.pb("not");keyword.pb("not_eq");keyword.pb("operator");keyword.pb("or");
    keyword.pb("or_eq");keyword.pb("private");keyword.pb("protected");keyword.pb("public");keyword.pb("register");keyword.pb("reinterpret_cast");keyword.pb("return");
    keyword.pb("short");keyword.pb("signed");keyword.pb("sizeof");keyword.pb("static");keyword.pb("static_cast");keyword.pb("struct");
    keyword.pb("switch");keyword.pb("template");keyword.pb("this");keyword.pb("throw");keyword.pb("true");keyword.pb("try");
    keyword.pb("typedef");keyword.pb("typeid");keyword.pb("typename");keyword.pb("union");keyword.pb("unsigned");keyword.pb("using");
    keyword.pb("virtual");keyword.pb("void");keyword.pb("volatile");keyword.pb("wchar_t");keyword.pb("while");keyword.pb("xor");keyword.pb("xor_eq");
    keyword.pb("cin"); keyword.pb("cout"); keyword.pb("printf"); keyword.pb("scanf"); keyword.pb("void");keyword.pb("vector");keyword.pb("string");
    keyword.pb("getline"); keyword.pb("gets"); keyword.pb("clear"); keyword.pb("std"); keyword.pb("main");keyword.pb("size");
    keyword.pb("stdout"); keyword.pb("stdin"); keyword.pb("Set"); keyword.pb("map"); keyword.pb("Set");

    sort(keyword.begin(),keyword.end());

    return ;
}

void make_token(void)
{
    int i,j;
    string bb="";
    for(i=0;i<(int)aa.size();i++)
    {
        if( aa[i]=='&' && aa[i+1]!='&')
        {
            if( bb.size()!=0 )store_the_word.pb(bb);
            bb="";
            bb+=aa[i];
            if( bb.size()!=0) store_the_word.pb(bb);
            bb="";
        }
        if( aa[i]==';' )
        {
            if( bb.size()!=0 )store_the_word.pb(bb);
            bb="";
            bb+=aa[i];
            if( bb.size()!=0) store_the_word.pb(bb);
            bb="";
        }
        else if( aa[i]==',' )
        {
            if( bb.size()!=0 )store_the_word.pb(bb);
            bb="";
            bb+=aa[i];
            if( bb.size()!=0) store_the_word.pb(bb);
            bb="";
        }
        else if( aa[i]=='&' )
        {
            int flag=0;
            if( bb.size()!=0 ) store_the_word.pb(bb);
            bb="";
            bb+=aa[i];
            for(j=i+1; ;j++)
            {
                bb+=aa[j];
                if( aa[j]=='&' ) { flag=1; break;}
            }
            i=j;
            if(bb.size()!=0 && flag==1)
            {
                bb="and(&&)";
                store_the_word.pb(bb);
            }
//            cout<<"fdfddsfdsfdsfdsfdsfdfdsfdsfdsfdsfdsfdsfdsfdsfdsfdsf"<<bb<<endl;
            bb="";
        }
        else if( aa[i]=='|' )
        {
            if( bb.size()!=0 ) store_the_word.pb(bb);
            bb="";
            bb+=aa[i];
            for(j=i+1; ;j++)
            {
                bb+=aa[j];
                if( aa[j]=='|' ) break;
            }
            i=j;
            if(bb.size()!=0) store_the_word.pb(bb);
            bb="";
        }
        else if( aa[i]==39 )
        {
            if( bb.size()!=0 ) store_the_word.pb(bb);
            bb="";
            bb+=aa[i];
            for(j=i+1; ;j++)
            {
                bb+=aa[j];
                if( aa[j]==39 ) break;
            }
            i=j;
            if(bb.size()!=0) store_the_word.pb(bb);
            bb="";
        }
        else if( aa[i]=='"' )
        {
            if( bb.size()!=0 ) store_the_word.pb(bb);
            bb="";
            bb+=aa[i];
            for(j=i+1; ;j++)
            {
                bb+=aa[j];
                if( aa[j]=='"' ) break;
            }
            i=j;
            if(bb.size()!=0) store_the_word.pb(bb);
            bb="";
        }
        else if( aa[i]=='_' || (aa[i]>='a' and aa[i]<='z') || (aa[i]>='A' and aa[i]<='Z') || (aa[i]>='0' and aa[i]<='9') || aa[i]=='#' || aa[i]=='.')
        {
            bb+=aa[i];
        }
        else if( aa[i]==' ' )
        {
            if( bb.size()!=0 ) store_the_word.pb(bb);
            bb="";
        }
        else if( aa[i]=='=' || aa[i]=='+' || aa[i]=='-' || aa[i]=='*' || aa[i]=='/' || aa[i]=='(' || aa[i]==')' || aa[i]=='{' || aa[i]=='}' || aa[i]=='[' || aa[i]==']' || aa[i]=='<' || aa[i]=='>' || aa[i]=='!' || aa[i]=='?')
        {
            if( bb.size()!=0 )store_the_word.pb(bb);
            bb.clear();
            bb+=aa[i];
            if( bb.size()!=0 )store_the_word.pb(bb);
            bb="";
        }
    }

    sort(store_the_word.begin(),store_the_word.end());
    store_the_word.erase(unique(store_the_word.begin(),store_the_word.end()),store_the_word.end());


    return ;
}

void token_type(void)
{
    int i,j;
    string cc;

    cc="&";
    for(i=0;i<(int)store_the_word.size();i++)
    {
        if( store_the_word[i]=="&" )
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf("And operator\n");
        }
    }

    cc="&&";
    for(i=0;i<(int)store_the_word.size();i++)
    {
        if( store_the_word[i]=="&&" )
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf("And operator\n");
        }
    }
    cc="||";
    for(i=0;i<(int)store_the_word.size();i++)
    {
        if( store_the_word[i]=="||" )
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf("OR operator\n");
        }
    }


    for(i=0;i<(int)store_the_word.size();i++)
    {
        cc=store_the_word[i];
        if( binary_search( keyword.begin(),keyword.end(),cc ) )
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf("This is a key word.\n");
        }
    }
    for(i=0;i<(int)store_the_word.size();i++)
    {
        cc=store_the_word[i];
        if( cc[0]=='_' || (cc[0]>='a'&&cc[0]<='z') || (cc[0]>='A'&& cc[0]<='Z') )
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf("This is a identifier.\n");
        }
    }
    for(i=0;i<(int)store_the_word.size();i++)
    {
        cc=store_the_word[i];
        if( cc[0]=='('  || cc[0]=='{'  || cc[0]=='[' )
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf("This is a Parentheses.\n");
        }
    }
    for(i=0;i<(int)store_the_word.size();i++)
    {
        cc=store_the_word[i];
        if( cc[0]==')'  || cc[0]=='}'  || cc[0]==']' )
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf("This is a Parentheses.\n");
        }
    }
    for(i=0;i<(int)store_the_word.size();i++)
    {
        cc=store_the_word[i];
        if( cc[0]==';' )
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf("End of statement.\n");
        }
    }

    for(i=0;i<(int)store_the_word.size();i++)
    {
        cc=store_the_word[i];
        if( cc[0]=='+' || cc[0]=='-' || cc[0]=='*' || cc[0]=='/' || cc[0]=='=' || cc[0]=='<' || cc[0]=='>' || cc[0]=='!')
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf("Operator.\n");
        }
    }
    for(i=0;i<(int)store_the_word.size();i++)
    {
        cc=store_the_word[i];
        if( cc[0]>='0' && cc[0]<='9')
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf("Numerical Number.\n");
        }
    }

    for(i=0;i<(int)store_the_word.size();i++)
    {
        cc=store_the_word[i];
        if( cc[0]>=39)
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf(" Identifier\n");
        }
    }
    for(i=0;i<(int)store_the_word.size();i++)
    {
        cc=store_the_word[i];
        if( cc[0]>='"')
        {
            store_the_word[i]="";
            cout<<cc<<" ";
            printf("Literals\n");
        }
    }

    for(i=0;i<(int)store_the_headerfile.size();i++)
    {
        cout<<store_the_headerfile[i]<<" ";
        printf("HeaderFile\n");
    }
////    printf("\n\n\n\ndfdfsf\n\n\n");
    for(i=0;i<(int)store_the_comment.size();i++)
    {
        cout<<store_the_comment[i]<<" ";
        printf("Comment\n");
    }
    for(i=0;i<(int)store_the_define.size();i++)
    {
        cout<<store_the_define[i]<<" ";
        printf("Define\n");
    }

    return ;
}
