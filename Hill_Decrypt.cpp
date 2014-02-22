#include<iostream>
using namespace std;

string solve(string P, int kmatrix[3][3]){
    int pmatrix[3];
    for(int i=0;i<3;i++)
        pmatrix[i]=P[i]-'a';
    int ans[3];
    for(int i=0;i<3;i++)
        {
            ans[i]=pmatrix[0]*kmatrix[0][i];
            ans[i]+=pmatrix[1]*kmatrix[1][i];
            ans[i]+=pmatrix[2]*kmatrix[2][i];
            ans[i]%=26;
           // cout<<ans[i]<<" ";
        }
    string finalans="";
    for(int i=0;i<3;i++)finalans+=ans[i]+'a';
    return finalans;
}

int minverse(int x){
    for(int i=1;;i++)
        if((x*i)%26==1)return i;
    return 0;
}
int main(){
    string key,plaintext,ciphertext="";
    cout<<"Enter key and ciphertext\n";
    cin>>key>>plaintext;
    if(key.length()!=9){
        cout<<"Key must be 9 in length\n";
        return 1;
    }
    while(plaintext.length()%3!=0)plaintext+='z';
    int kmatrix[3][3];
    int cnt=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)        
            kmatrix[i][j]=key[cnt++]-'a'; 
    
    int cofactor[3][3],det;
    det = kmatrix[0][0]*(kmatrix[1][1]*kmatrix[2][2] - kmatrix[1][2]*kmatrix[2][1]) -kmatrix[0][1]*(kmatrix[1][0]*kmatrix[2][2] - kmatrix[1][2]*kmatrix[2][0]) + kmatrix[0][2]*(kmatrix[1][0]*kmatrix[2][1] - kmatrix[1][1]*kmatrix[2][0]);
    
    det%=26;
    if(det < 0)det+=26;
    cout<<det<<endl;
    det = minverse(det);
   // cout<<det<<endl;

    
    cofactor[0][0] = kmatrix[1][1]*kmatrix[2][2] - kmatrix[1][2]*kmatrix[2][1];
    cofactor[0][1] = -kmatrix[1][0]*kmatrix[2][2] + kmatrix[1][2]*kmatrix[2][0];
    cofactor[0][2] = kmatrix[1][0]*kmatrix[2][1] - kmatrix[1][1]*kmatrix[2][0];
    cofactor[1][0] = -kmatrix[0][1]*kmatrix[2][2] + kmatrix[0][2]*kmatrix[2][1];
    cofactor[1][1] = kmatrix[0][0]*kmatrix[2][2] - kmatrix[0][2]*kmatrix[2][0];
    cofactor[1][2] = -kmatrix[0][0]*kmatrix[2][1] + kmatrix[0][1]*kmatrix[2][0];
    cofactor[2][0] = kmatrix[0][1]*kmatrix[1][2] - kmatrix[0][2]*kmatrix[1][1];
    cofactor[2][1] = -kmatrix[0][0]*kmatrix[1][2] + kmatrix[0][2]*kmatrix[1][0];
    cofactor[2][2] = kmatrix[0][0]*kmatrix[1][1] - kmatrix[0][1]*kmatrix[1][0];
    
    int kinverse[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            kinverse[i][j]=(det*cofactor[j][i])%26;
            if(kinverse[i][j]<0)kinverse[i][j]+=26;
        }

  /*  for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)        
            cout<<kinverse[i][j]<<" ";
        cout<<endl;
    }*/
    
    for(int i=0;i<plaintext.length();i+=3)
    {
        string temp="";
        temp+=plaintext[i];
        temp+=plaintext[i+1];
        temp+=plaintext[i+2];
        ciphertext+=solve(temp,kinverse);
      //  cout<<ciphertext<<" ";
    }
    cout<<ciphertext<<endl;
}
