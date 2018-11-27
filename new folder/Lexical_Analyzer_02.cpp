#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring>
#include <conio.h>

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int,int> paii;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<double>vd;
typedef vector<ll>vll;
typedef vector<string> vs;
typedef vector<vi>vvi;
typedef map<string,int> msi;
typedef map<int,int>mii;
typedef map<paii,int>mpi;

#define INF (1<<28)
#define MAX 1010
#define ERR 1e-9
#define PI 3.141592653589793

#define REP(i,n) for (i=0;i<n;i++)
#define REV(i,n) for (i=n;i>=0;i--)
#define FOR(i,p,k) for (i=p; i<k;i++)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)

#define All(x) x.begin(),x.end()
#define Sort(x) sort(All(x))
#define Reverse(x) reverse(All(x))
#define MP(a,b) make_pair(a,b)
#define Clear(x,with) memset(x,with,sizeof(x))
#define SZ(x) (int)x.size()
#define length(x) (int)x.length()
#define pb push_back
#define popcount(i) __builtin_popcount(i)
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define maximum(v) *max_element(All(v))
#define minimum(v) *min_element(All(v))
#define fs first
#define sc second

string sequence ;

char op[8]= {'+','-','*','/','=','<','>','%'};
char del[8]= {'}','{',';','(',')','[',']',','};
char *key[]= {"int","void","main","char","float"};
int len , start ;

vector<char>identifier,operators,delimeter;
vector< string>constant,id;
set< string>unique_identifier,unique_operators,unique_constant;
map< string,int > mpid;
vector<char>unique_delimeter;

void display_result( )
{
    cout<<"                  IDENTIFIERS : "<<endl;
    cout<<"                  ";for( int i = 0 ; i < SZ(identifier) ; i++ ) cout<<identifier[i];
    cout<<endl;

    cout<<"                  OPERATORS : "<<endl;
    cout<<"                  ";for( int i = 0 ; i < SZ(operators) ; i++ ) cout<<operators[i];
    cout<<endl;

    cout<<"                  DELIMETERS : "<<endl;
    cout<<"                  ";for( int i = 0 ; i < SZ(delimeter) ; i++ ) cout<<delimeter[i]<<" ";
    cout<<endl;

    cout<<"                  CONSTANT : "<<endl;
    cout<<"                  ";for( int i = 0 ; i < SZ(constant) ; i++ ) cout<<constant[i];
    cout<<endl;

    return ;
}


bool isid(char ch )
{
    if( isalpha(ch) ) return true;
    return false;
}

bool isop(char ch)
{
    bool flag = false ;
    for( int i = 0 ; i < 8 ; i++ )
    {
        if( ch!=op[i] ) flag |= false;
        else flag |= true;
    }
    return flag;
}

bool isdeli(char ch)
{
    bool flag = false ;
    for( int i = 0 ; i < 8 ; i++ )
    {
        if( ch!=del[i] ) flag |= false;
        else flag |= true;
    }
    return flag;
}

bool iscons( char ch)
{
    if( ch>='1' and ch <='9' ) return true;
    return false;
}

void func()
{
    if( isid(sequence[start]) )
    {
        for( ; start < len ; start++ )
        {
            if( isid(sequence[start]) ) identifier.pb(sequence[start]);
            else { identifier.pb(' '); break;}
        }
    }

    if ( isop(sequence[start]) )
    {
        for( ; start < len ; start++ )
        {
            if( isop(sequence[start]) ) operators.pb(sequence[start]);
            else {operators.pb(' '); break;}
        }
    }

    if( isdeli(sequence[start]) )
    {
        for( ; start < len ; start++ )
        {
            if( isdeli(sequence[start]) ) delimeter.pb(sequence[start]);
            else break;
        }
    }

    if( iscons(sequence[start]))
    {
        if( start+2 < len and sequence[start+1]=='.' and iscons(sequence[start+2]) )
        {
            string str = "";

            str.pb(sequence[start]); start++;
            str.pb(sequence[start] ); start++;

            for( ; start < len ; start++ )
            {
                if( iscons(sequence[start]) ) { str.pb(sequence[start]);}
                else break;
            }
            constant.pb(str);
        }
        else
        {
            string str = "";
            for( ; start < len ; start++ )
            {
                if( iscons(sequence[start]) ) { str.pb(sequence[start]);}
                else break;
            }
            constant.pb(str);
        }
        constant.pb(" ");
    }

    return ;
}



void lexical_writing()
{
    int num = 1 ;
    cout<<"********************** LEXICAL ANALYZER NOTATION ********************"<<endl;
    set<string>::iterator it;
    string str = "";

    for( int i = 0 ; i < SZ(sequence) ; i++ )
    {
        str="";
        if( isid(sequence[i]) )
        {
            for( int j = i ; j < len ; j++ )
            {
                if( isid(sequence[j]) ) str += sequence[j];
                else break;
            }
        }
        if( SZ(str)>=1 and !mpid[str] ) mpid[str]=num++;
    }

    str="";

    cout<<"          ";
    for( int i = 0 ; i < SZ(sequence) ; i++ )
    {
        if( isid(sequence[i]) )
        {
            for( int j = i ; j < len ; j++ )
            {
                if( isid(sequence[j]) ) str += sequence[j];
                else break;
            }
            if( mpid[str]>=1 ) cout<<"<id,"<<mpid[str]<<">";
        }
        else cout<<sequence[i];
        str="";
    }
    cout<<endl;
    return ;
}


void making_unique()
{
    cout<<"***************************************"<<endl;
    set<string>::iterator it;
    string str = "";
    for( int i = 0 ; i < SZ(identifier) ; i++ )
    {
        if( identifier[i]==' ' ) { unique_identifier.insert(str); str="";}
        else str+=identifier[i];
    }

    cout<<"UNIQUE IDENTIFIER ->";
    for (it=unique_identifier.begin(); it!=unique_identifier.end(); ++it)  { id.pb(*it); cout << *it<<" ";}
    cout<<endl;




    //***************************************************************************************************************

    for( int i = 0 ; i < SZ(operators) ; i++ )
    {
        if( operators[i]==' ' ) { unique_operators.insert(str); str="";}
        else str+=operators[i];
    }

    cout<<"UNIQUE OPERATOR ->";
    for (it=unique_operators.begin(); it!=unique_operators.end(); ++it)  cout << *it<<" ";
    cout<<endl;

    //****************************************************************************************************************

    map<char,bool>mp;
    mp.clear();

    for( int i = 0 ; i < SZ(delimeter) ; i++ )
    {
        if( !mp[delimeter[i]] ) {unique_delimeter.pb(delimeter[i]); mp[delimeter[i]]=true;}
    }

    cout<<"UNIQUE DELIMETER -> ";
    for (int i=0; i<SZ(unique_delimeter); i++)  cout << unique_delimeter[i]<<" ";
    cout<<endl;

    //*****************************************************************************************************************


    for( int i = 0 ; i < SZ(constant) ; i++ ) unique_constant.insert(constant[i]);

    cout<<"UNIQUE CONSTANT ->";
    for (it=unique_constant.begin(); it!=unique_constant.end(); ++it)  cout << *it<<" ";
    cout<<endl;

    cout<<"*************************************"<<endl;
    lexical_writing();
    return ;
}

void Lexical_analyzer()
{
    len = SZ(sequence);
    for( start = 0 ; start < len; ) func();
    display_result();
    making_unique();
    return ;
}

string remove_whitespace(string sss)
{
    string s = "";
    for( int i = 0 ; i < SZ(sss) ; i++ )
    {
        if( sss[i] !=' ' ) s.pb(sss[i]);
    }
    return s;
}

int main()
{
    while(1)
    {
        cout<<"INPUT STRING -> ";
        string sss;
        getline(cin,sss);
        sequence=remove_whitespace(sss);
        cout<<"After Removing Whitespace -> "<<sequence<<endl;
        cout<<"*******************************************************"<<endl;
        start = 0 ;
        Lexical_analyzer();
        sequence.clear(); identifier.clear(); operators.clear(); delimeter.clear(); constant.clear(); mpid.clear();
        cout<<"***********************************************************"<<endl;
    }
    return 0 ;
}
