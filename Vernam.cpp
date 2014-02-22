#include<iostream>
#include<cstdlib>
using namespace std;

string solve(string a,string b){
    string ans="";
    for(int i=0;i<a.length();i++)
    {
        unsigned char x = a[i];
        unsigned char y = b[i];
        unsigned char c = x^y;
        ans+=c;
    }
    return ans;
}

int main(){
    string plaintext,key="";
    cout<<"Enter text\n";
    getline(cin,plaintext);
    cout<<"Do you know the key? (y/n)";
    char option; cin>>option;
    if(option=='y'){
        cout<<"Enter the key\n";
        cin>>key;
        string okey=key;
        while(key.length() < plaintext.length())key+=okey;
    }
    else if(option=='n'){
        for(int i=0;i<plaintext.length();i++)
            key += (rand()%26) + 'a';    
        cout<<"Key: "<<key<<endl;
    }
    else return 1;
    cout<<solve(plaintext,key)<<endl;
}
