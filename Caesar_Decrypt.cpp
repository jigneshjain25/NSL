#include<iostream>
#include<string.h>
#include<cctype>
#include<string>
#include<cstdio>
using namespace std;

string solve(char *s,int len,int key){
	string ans="";
		for(int i=0;i<len;i++){
			if(!isalpha(s[i]))ans+=s[i];
			else{
				char ch = tolower(s[i]);
				ch = ((ch-'a')-key);
				if(ch < 0)ch+=26;
				ch+='a';
				if(isupper(s[i]))ch=toupper(ch);
				ans+=ch;
			}
		}
	return ans;
}
int main(){
	char s[200000];
	int len,key;
	char option;
	
	cout<<"Enter cipher text\n";
	gets(s);
	len = strlen(s);
	
	cout<<"Do you know the key (Y or N)?\n";

	cin>>option;
	option = tolower(option);
	if(option=='y'){
		cout<<"Enter key\n";		
		cin>>key;
		cout<<solve(s,len,key)<<endl;
	}
	else{
		for(int i=1;i<=25;i++)
			{
				cout<<"****\n";
				cout<<"Key: "<<i<<endl;
				cout<<"Plaintext: "<<solve(s,len,i)<<endl;
				cout<<"****\n\n";
			}
	}
	
}
