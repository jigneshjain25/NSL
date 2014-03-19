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
   int n,e;
   cout<<"Enter n and public key\n";
   cin>>n>>e;

   string text;
   cout<<"Enter text\n";
   cin.ignore();
   getline(cin,text);

   for(int i=0;i<text.length();i++)
   {
       int m = text[i];
       cout<<modulo(m,e,n)<<" ";
   }
   cout<<endl<<endl;
}
