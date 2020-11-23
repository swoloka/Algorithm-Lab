#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    map<string,string>M;
    string s1,s2,s;
    char str[15];
    while((cin>>str)&&strlen(str))//字典输入结束条件 
    {
        s1=s2="\0";
        int i;
        for(i=0;;i++)
            if(str[i]==' ')
            {
                str[i]='\0';
                break;
            }
        s1+=str;//英语 
        s2+=str+i+1;//外语 
        M[s2]=s1;//外语-英语的映射 
    }
    while(cin>>s)//查询输入结束条件 
    {
        if(M[s].size())//字典中存在该单词 
            cout<<M[s]<<endl;
        else//字典中不存在该单词 
            cout<<"eh"<<endl;
    }
    return 0;
} 



/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    char str[20], s1[20], s2[20];
    map<string, string>mymap;
    while (gets(str))
    {
        if (strlen(str) == 0) break;
        sscanf(str, "%s %s", s1, s2);
        mymap[s2] = s1;
    }
    while (gets(str))
    {
        if (mymap[str].length() == 0)
            puts("eh");
        else
            cout << mymap[str] << endl;
    }
    return 0;
}
*/