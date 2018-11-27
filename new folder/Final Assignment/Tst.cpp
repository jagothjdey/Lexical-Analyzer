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

typedef vector<string> VS;
typedef pair<int,int> PII;
typedef vector<pair<int,int> >VPII;
typedef map<string,int> MS;

int main()
{
    freopen("MM.txt","r",stdin);
    freopen("MMOUT.txt","w",stdout);
    string str;
    int t=0;
    while(cin>>str)
    {
        t++;
        string s="MKey[\""+str+"\"]=1";
        cout<<s<<";";
        if(t%5==0) {puts("");cout<<"\t";}
    }
    return 0;
}


