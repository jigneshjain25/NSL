#include<iostream>
#include<cctype>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	string s,key;

	cout<<"Enter Ciphertext\n";
	getline(cin,s);
	int len = s.length();

	cout<<"Enter Key\n";
	getline(cin,key);
		
	map<char,char> mymap;
	for(int i=0;i<26;i++)mymap[key[i]]='a'+i;
	
	for(int i=0;i<len;i++)if(isalpha(s[i]))s[i]=mymap[tolower(s[i])];
	cout<<s<<endl<<endl;
}	
