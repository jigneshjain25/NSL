#include<iostream>
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

   while(cin>>c)
       cout<<char(modulo(c,d,n));
   
   cout<<endl;
}

