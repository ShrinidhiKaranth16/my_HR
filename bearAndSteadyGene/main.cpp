#include<iostream>
#include<map>
using namespace std;

int steadyGene(string gene) {
    int n = gene.size();
    int left = 0,right = n-1;
    map<char,int> gMap;
    while(right>=left)
    {
        if(gMap[gene[right]]==n/4)
        {
            right++;
            break;
        }
        gMap[gene[right]]++;
        right--;
    }
    cout<<right<<endl;
    if(right<0) return 0;
    int minLength = right;
    cout<<"A "<<gMap['A']<<endl;
     cout<<"T "<<gMap['T']<<endl;
      cout<<"C "<<gMap['C']<<endl;
       cout<<"G "<<gMap['G']<<endl;
cout<<"_______________________"<<endl;
    while(right<n){
        gMap[gene[left]]++;
        while(right<n && gMap[gene[left]]>n/4)
        {
            gMap[gene[right]]--;
            right++;
        }
        cout<<"A "<<gMap['A']<<endl;
        cout<<"T "<<gMap['T']<<endl;
        cout<<"C "<<gMap['C']<<endl;
        cout<<"G "<<gMap['G']<<endl;
        int length = right-left-1;
        cout<<"right "<<right<<" left "<<left<<endl;
        cout<<"_______________________"<<endl;
        minLength = min(minLength,length);
        left++;
    }
    return minLength;
}

int main()
{
    int  n;
    cin>>n;
    string gene;
    cin>>gene;
   int r = steadyGene(gene);
   cout<<r<<endl;
}