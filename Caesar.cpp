#include<iostream>
#include<string.h>
#include<cctype>
#include<cstdio>
using namespace std;
	char s[200000];
int main(){

	int key;
	//cout<<"Enter plaintext\n";
	gets(s);
	//cout<<"Enter key\n";
	//cin>>key;
	key=3;
	int len = strlen(s);
	for(int i=0;i<len;i++){
		if(!isalpha(s[i]))cout<<s[i];
		else{
			char ch = tolower(s[i]);
			ch = ((ch-'a')+key)%26 + 'a';
			if(isupper(s[i]))ch=toupper(ch);
			cout<<ch;
		}
	}
	cout<<endl;			
}
