#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<cctype>

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

int phi(int n){
    int ans=0;
    for(int i=1;i<n;i++)  if(__gcd(n,i)==1) ans++;
    return ans;
}

int inverse(int a,int n){
    if(__gcd(a,n)!=1)return -1;

    int times = phi(n) - 1;

    return modulo(a,times,n);
}

vector<int> primes;
void runEratosthenesSieve(int upperBound) {
      int upperBoundSquareRoot = (int)sqrt((double)upperBound);
      bool *isComposite = new bool[upperBound + 1];
      memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
      isComposite[0]=isComposite[1]=true;
      for (int m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
                  for (int k = m * m; k <= upperBound; k += m)
                        isComposite[k] = true;
            }
      }
      for (int m = 2; m <= upperBound; m++)
            if (!isComposite[m])
                  primes.push_back(m);
      delete [] isComposite;
}


int main(){
    srand(time(0));
   runEratosthenesSieve(1000);

   int x = rand()%primes.size();
   int y;

   do{
        y = rand()%primes.size();
   }while(y==x);

   int p = primes[x], q = primes[y];

  // p=17;q=11;

   //cout<<p<<" "<<q<<endl;
   int n = p*q;

   cout<<"N= "<<n<<endl;

   int phin = (p-1)*(q-1);

  // cout<<"PHI n = "<<phin<<endl;

   int e=-1,d;
   
      for(int i=2;i<phin;i++)
       if(__gcd(i,phin)==1) {
           e=i;
           break;
       }
    
   if(e==-1)return 1;
   cout<<"Public key = "<<e<<endl;

   //e=7;

   d = inverse(e,phin);
   cout<<"Private key = "<<d<<endl;

   // cout<<modulo(92345,12442,53663);

   cout<<endl;

}
