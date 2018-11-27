#include<iostream.h>
#include<fstream.h>
#include<string.h>
int main()
struct sy_tab
{
    char a[20];
    char b[20];
};

char arr[5][10]= {"int","char","double","float","long"};
char key[32][10]= {"break","auto","case","const","char","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
char c;
int i,count=0,k,d;
char s[20],id[25],u[10];

ifstream fin("hi.c");
fin.get(c);

while(fin)
{

    fin.get(c);
    for(i=0; c!=' '; i++)
    {
        s[i]=c;
        fin.get(c);
        count++;
    }
    for(k=0; k<count; k++)
        u[k]=s[k];
    cout<<count;
    for(int j=0; j<5; j++)
    {
        if((strcmp(u,arr[j][0]))==0)
        {
            //insert in avl tree
        }
        do
        {
            fin.get(c);
        }
        while(c==' ');

        while(c!=';')

        {

            for(i=0; c!=','; i++)
            {
                id[i]=c;
                fin.get(c);
            }
            d=i;
            f=check_validity(id,i); //insert in tree in id field
            fin.get(c);
        }
    }
    else
        fin.get©;
}

int check_validity(char p[],int i)
{
    int j,t;
    for(j=0; j<i; j++)
    {
        if(isalpha(p[0])==0)
        {
            cout<<"error in naming"<<"\n";
            return 0;
        }

        if((isalnum(p[j])==0)||p[j]!='_')
        {
            return 0;
        }
    }
}
