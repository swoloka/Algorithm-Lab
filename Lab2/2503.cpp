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
// #include <deque>
// #include <list>
// #include <set>
// #include <stack>
// #include <queue>
// #include <numeric>
// #include <iomanip>
// #include <bitset>
// #include <sstream>
// #include <fstream>

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