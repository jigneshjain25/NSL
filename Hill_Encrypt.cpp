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

int main(){
    string key,plaintext,ciphertext="";
    cout<<"Enter key and plaintext\n";
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
    
    /*for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)        
            cout<<kmatrix[i][j]<<" ";
        cout<<endl;
    }*/
    
    for(int i=0;i<plaintext.length();i+=3)
    {
        string temp="";
        temp+=plaintext[i];
        temp+=plaintext[i+1];
        temp+=plaintext[i+2];
        ciphertext+=solve(temp,kmatrix);
      //  cout<<ciphertext<<" ";
    }
    cout<<ciphertext<<endl<<endl;
}
