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
	srand(time(0));
	char s[1000],key[]="hifgstjklmnabcdeuopqrvwxyz";		
	cout<<"Enter Plaintext\n";
	gets(s);
	int len = strlen(s);
	
	int times = rand()%1000000;
	while(next_permutation(key,key+26) && times--)next_permutation(key,key+26);
	
	cout<<key<<endl;
	map<char,char> mymap;
	for(int i=0;i<26;i++)mymap['a'+i]=key[i];
	
	for(int i=0;i<len;i++)if(isalpha(s[i]))s[i]=mymap[tolower(s[i])];
	puts(s);
}	

