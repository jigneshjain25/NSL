//"etaoinshrdlcumwfgypbvkjxqz";
// Deecrypting
#include<iostream>
#include<cstdio>
#include<string.h>
#include<cctype>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	char s[1000],key[30];
	cout<<"Enter Ciphertext\n";
	gets(s);
	int len = strlen(s);
	cout<<"Enter Key\n";
	gets(key);
	
	map<char,char> mymap;
	for(int i=0;i<26;i++)mymap[key[i]]='a'+i;
	
	for(int i=0;i<len;i++)if(isalpha(s[i]))s[i]=mymap[tolower(s[i])];
	puts(s);
}	

// zxywudefabcghijklmnopqrstv
