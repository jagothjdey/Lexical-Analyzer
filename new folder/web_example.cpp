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

void removeduplicate();
void final();
char op[8]= {'+','-','*','/','=','<','>','%'};
char del[8]= {'}','{',';','(',')','[',']',','};
char *key[]= {"int","void","main","char","float","return","float","double","long long","singed","unsigned","bool","const","static","string"};
int idi=0,idj=0,k,opi=0,opj=0,deli=0,uqdi=0,uqidi=0,uqoperi=0,kdi=0,liti=0,ci=0;
int uqdeli[20],uqopi[20],uqideni[20],l=0,j;
char uqdel[20],uqiden[20][20],uqop[20][20],keyword[20][20];
char iden[20][20],oper[20][20],delem[20],litral[20][20],lit[20],constant[20][20];
string str;
set<string>::iterator it;
set<string>uni_id,uni_op,uni_key,uni_del,uni_cons;

int Isiden(char ch)
{
    if(isalpha(ch)||ch=='_'||isdigit(ch)||ch=='.')
        return 1;
    else
        return 0;
}

int Isop(char ch)
{
    int f=0;
    for(int i=0; i<8&&!f; i++)
    {
        if(ch==op[i])
            f=1;
    }
    return f;
}

int Isdel(char ch)
{
    int f=0;
    for(int i=0; i<8&&!f; i++)
    {
        if(ch==del[i])
            f=1;
    }
    return f;
}

int Iskey(string str)
{
    int f=0;
    for(int i=0; i<5; i++)
    {
        if(!strcmp(key[i],str))
            f=1;
    }
    return f;
}

void lexanalysis(string str)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(Isiden(str[i]))     //for identifiers
        {
            while(Isiden(str[i]))
            {
                iden[idi][idj++]=str[i++];
            }
            iden[idi][idj]='\0';
            string temp_str;
            if(idj>0)( for( int j = 0 ; j < idj ; j++ )
            {
                temp_str += iden[idi][j];
            }
            uni_id.insert(temp_str);
            idj=0;
            idi++;

        }
        else if(str[i]=='"')        //for literals
        {
            lit[l++]=str[i];
            for(j=i+1; str[j]!='"'; j++)
            {
                lit[l++]=str[j];
            }
            lit[l++]=str[j];
            lit[l]='\0';
            strcpy(litral[liti++],lit);
            i=j+1;
        }
        else if(Isop(str[i]))       // for operators
        {
            while(Isop(str[i]))
            {
                oper[opi][opj++]=str[i++];
            }
            oper[opi][opj]='\0';

            opi++;
            opj=0;
        }
        else if(Isdel(str[i]))    //for delemeters
        {
            while(Isdel(str[i]))
            {
                delem[deli++]=str[i++];
            }
        }
        else
        {
            i++;
        }
    }

    removeduplicate();

}


void removeduplicate()
{
    int i,j;
    for(i=0; i<20; i++)
    {
        uqdeli[i]=0;
        uqopi[i]=0;
        uqideni[i]=0;
    }
    for(i=1; i<deli+1; i++) //removing duplicate delemeters
    {
        if(uqdeli[i-1]==0)
        {
            uqdel[uqdi++]=delem[i-1];
            for(j=i; j<deli; j++)
            {
                if(delem[i-1]==delem[j])
                    uqdeli[j]=1;
            }
        }
    }

    for(i=1; i<idi+1; i++) //removing duplicate  identifiers
    {
        if(uqideni[i-1]==0)
        {
            strcpy(uqiden[uqidi++],iden[i-1]);
            for(j=i; j<idi; j++)
            {
                if(!strcmp(iden[i-1],iden[j]))
                    uqideni[j]=1;
            }
        }
    }

    for(i=1; i<opi+1; i++) //removing duplicate  operators
    {
        if(uqopi[i-1]==0)
        {
            strcpy(uqop[uqoperi++],oper[i-1]);
            for(j=i; j<opi; j++)
            {
                if(!strcmp(oper[i-1],oper[j]))
                    uqopi[j]=1;
            }
        }
    }

}


void final()
{
    int i=0;
    idi=0;
    for(i=0; i<uqidi; i++)
    {
        if(Iskey(uqiden[i]))        //identifying keywords
            strcpy(keyword[kdi++],uqiden[i]);
        else if(isdigit(uqiden[i][0]))   //identifying constants
            strcpy(constant[ci++],uqiden[i]);
        else
            strcpy(iden[idi++],uqiden[i]);
    }

// printing the outputs

    printf("\n\tDelemeter are : \n");
    for(i=0; i<uqdi; i++)
        printf("\t%c\n",uqdel[i]);

    printf("\n\tOperators are : \n");
    for(i=0; i<uqoperi; i++)
    {
        printf("\t");
        puts(uqop[i]);
    }

    printf("\n\tIdentifiers are : \n");
    for(i=0; i<idi; i++)
    {
        printf("\t");
        puts(iden[i]);
    }

    printf("\n\tKeywords are : \n");
    for(i=0; i<kdi; i++)
    {
        printf("\t");
        puts(keyword[i]);
    }

    printf("\n\tConstants are :\n");
    for(i=0; i<ci; i++)
    {
        printf("\t");
        puts(constant[i]);
    }

    printf("\n\tLiterals are :\n");
    for(i=0; i<liti; i++)
    {
        printf("\t");
        puts(litral[i]);
    }
}

int main()
{
    //char str[50];
    //clrscr();
    int line = 1 ;
    printf("\nEnter the string : ");
    //gets(str);
    while(getline(cin,str))
    {
        uni_id.clear();
        uni_op.clear();
        uni_key.clear();
        uni_del.clear();
        uni_cons.clear();
        lexanalysis(str);
        cout<<"In lin No : "<<line++<<endl;
        final();
    }
    return 0 ;

}
