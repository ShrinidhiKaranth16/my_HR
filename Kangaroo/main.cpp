#include<bits/stdc++.h>
using namespace std;
string kangaroo(int x1, int v1, int x2, int v2) {
    while(true){
        if(x2 > x1 && v2 > v1 || x1 > x2 && v1 > v2 || v1 == v2){
           return "NO";
        }
        if((x1 += v1) == (x2 +=v2)){
            return "YES";
        }
    }
    return 0;
}
   
int main()
{
    int x1,v1,x2,v2;
    cin>>x1>>v1>>x2>>v2;
    string result = kangaroo(x1,v1,x2,v2);
   cout<<result;
}