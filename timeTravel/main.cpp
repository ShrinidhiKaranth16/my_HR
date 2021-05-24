#include<bits/stdc++.h> 
using namespace std;
string dayOfProgrammer(int y) {
bool leap = false,julian =false;
if(y % 4 == 0)
    {
        julian = true;
        //Nested if else
        if( y % 100 == 0)
        {
            if ( y % 400 == 0)
               leap = true;
        }
        else
           leap = true;
    }
    string result;
    string a = "12.09.";
    string b = "13.09.";
     if(julian && y<=1917) 
     {
     result = a + to_string(y);
     return result;
     }
    if(leap&& y>1917)
    result = a + to_string(y);
    else
    result =  b +to_string(y);
    return result;
}
int main()
{
    int year;
    //cin>>year;
    string result = dayOfProgrammer(1800);
    cout<<result;
}