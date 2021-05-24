#include<bits/stdc++.h>
using namespace std;

int lilysHomework(vector<int> arr) {
    int i,j,k;
    int count = 0;
    for(i=0;i<arr.size();i++)
    {
        int min = arr[i];
         int r = 0, l;
        for(j=i+1;j<arr.size();j++)
        {
            if (arr[j]< min)
            {
                r++;
                l = j;
                min = arr[j];
            }
        }
        if(r>0)
            {
                cout<<"MINIMUM IS :"<< arr[l];
                cout<<"Incrementing"<<endl;
                 count++;
                int temp = arr[i];
                arr[i] = arr[l];
                arr[l] = temp;
            }
            cout<<"Array is: ";
            for(int p: arr)
            cout<<p<<",";
            cout<<endl;
    }
    cout<<"COUNt :"<<count<<endl;
    return 2;
}

 int main()
{
    int n;
    int i;
    cin>>n;
    vector<int> numbers;
    for(i=0;i<n;i++)
    {
        int num;
        cin>>num;
        numbers.push_back(num);
    }

     
      int result = lilysHomework(numbers);
      cout<<result<<endl;
}