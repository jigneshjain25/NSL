#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

int main(){
	
    srand(time(0));
	string s,key ="abcdefghijklmnopqrstuvwxyz";		

	cout<<"Enter Plaintext\n";
	getline(cin,s);
	int len = s.length();
	
	for(int i=0;i<len;i++){
        int x = rand()%len;
        swap(key[x],key[i]);
    }
	
	cout<<"Random key: "<<key<<endl;
	
    map<char,char> mymap;
	for(int i=0;i<26;i++)mymap['a'+i]=key[i];
	
	for(int i=0;i<len;i++)if(isalpha(s[i]))s[i]=mymap[tolower(s[i])];
	cout<<s<<endl<<endl;
}	

