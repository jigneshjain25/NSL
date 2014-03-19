#include<iostream>
#include<string>
using namespace std;

int main(){
    string key,cipher;
    char table[6][6];

    // Input
    cout<<"Enter key and plaintext (all lowercase, no spaces)\n";
    cin>>key>>cipher;
    
    // Making table
    bool visited[26]={0};
    visited['j'-'a']=1;
    int r=0,c=0;
    for(int i=0;i<key.length();i++){
        if(key[i]=='j')key[i]='i';
        if(visited[key[i]-'a'])continue;
        visited[key[i]-'a']=1;
        table[r][c++]=key[i];
        if(c%5==0){
            c=0;
            r++;
        }
    }
    for(int i=0;i<26;i++)
        if(!visited[i]){
            table[r][c++]='a'+i;
            if(c%5==0){
                c=0;
                r++;
            }
        }
    
  /* for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }*/
    
       
   pair<int,int> P[26];
   for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            P[table[i][j]-'a']=make_pair(i,j);
    
   string ans="";
    for(int i=0;i<cipher.length();i+=2){
        char one=cipher[i],two=cipher[i+1];
        int r1 = P[one-'a'].first, c1 = P[one-'a'].second;
        int r2 = P[two-'a'].first, c2 = P[two-'a'].second;
        if(r1==r2){
            c1--;c2--;
            if(c1<0)c1=4;
            if(c2<0)c2=4;
            ans+=table[r1][c1];
            ans+=table[r2][c2];
        }
        else if(c1==c2){
            r1--;r2--;
            if(r1<0)r1=4;
            if(r2<0)r2=4;
            ans+=table[r1][c1];
            ans+=table[r2][c2];
        }
        else{
            ans+=table[r1][c2];
            ans+=table[r2][c1];
        }
    }
    string finalans="";
    finalans+=ans[0];
    for(int i=1;i<ans.length();i++)
        if(ans[i]!='x' || ans[i-1]!=ans[i+1] && ans[i+1]!='\0')finalans+=ans[i];
    cout<<finalans<<endl<<endl;
}
