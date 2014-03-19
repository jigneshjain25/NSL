#include<iostream>
#include<string>
using namespace std;

int main(){
    char table[27][27];
    for(int i=0;i<26;i++)   table[0][i]=i+'a';
    for(int i=1;i<26;i++){
        for(int j=0;j<25;j++)
            table[i][j] = table[i-1][j+1];
        table[i][25]=table[i-1][0];
    }
    /*for(int i=0;i<26;i++){
        for(int j=0;j<26;j++)
            cout<<table[i][j];
        cout<<endl;
    }*/
    string key,pt;
    cout<<"Enter key and plaintext (all lowercase, no spaces)\n";
    cin>>key>>pt;
    string okey=key;
    while(key.length() < pt.length())key+=okey;

    for(int i=0;i<pt.length();i++)
        pt[i] = table[key[i]-'a'][pt[i]-'a'];
    cout<<pt<<endl<<endl;
}
