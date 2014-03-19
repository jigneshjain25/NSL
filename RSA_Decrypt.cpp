#include<iostream>
#include<vector>
using namespace std;

int modulo(int a,int b,int c){
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; 
        b /= 2;
    }
    return x%c;
}


int main(){
   int n,d,c;
   cout<<"Enter n and private key\n";
   cin>>n>>d;

   cout<<"Enter ciphertext\n";

   vector<int> v;
   while(cin>>c)
       v.push_back(c);

   for(int i=0;i<v.size();i++)
       cout<<char(modulo(v[i],d,n));
   
   cout<<endl<<endl;
}

