#include<iostream>
#include<cmath>

# define M_PIl          3.141592653589793238462643383279502884L

using namespace std;

int Years(double a){
    double Square;
    int i1 = 0;
    int ss = a * M_PIl / 2;
    for (int Square = 0; Square < ss ;Square = Square + 50)
    {
        i1++;
    }
    return i1;
    
}
int main(){
    int in,year;
    double x,y;
    cin >> in;
    for (int i = 1; i <= in; i++)
    {   
        cin >> x;
        cin>>y;
        year = Years(pow(x,2)+pow(y,2));
        cout << "Property "<<i<<": This property will begin eroding in year "<<year<<".\n";
    }
    cout<<"END OF OUTPUT.\n";    
    return 0;
}


