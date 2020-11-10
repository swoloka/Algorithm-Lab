#include <iostream>
#include <string.h>
bool hash[80000];


int main(){
    int a,b;
    int n,m;
    scanf("%d",&n);
    memset(hash,0,sizeof(hash));
    bool ans=false; 
    while (n--)
    {   
        std::cin >> a;
        hash[40000+a]=1;
    }
    scanf("%d",&m);
    while (m--)
    {
        std::cin >> b;
        if (hash[50000-b])
        {
            ans=true;
        }
    }
    if (ans) 
        std::cout <<"YES\n";
    else 
        std::cout << "NO\n";
    return 0;
}