#include<iostream>
#include <string.h>


using namespace std;
int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t; cin.ignore();
        int temp=stoi(t),pointer=0;
        int val1=0,val2=0;
        while(temp>0)
        {
            int tempo=temp%10;
            if(pointer<3)
             val1+=tempo;
            if(pointer>2)
            val2+=tempo;
            temp /= 10;
            pointer++;

        }

        if(val1==val2)
        cout<<"true";

        else cout<<"false";

        
    }

    
}