#include<iostream>
#include<cstdio>
#include<string.h>
#include<cctype>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

	char s[2000];
	cout<<"Enter Ciphertext\n";
	gets(s);
	int len = strlen(s);
	int A[26];
	fill(A,A+26,0);
	for(int i=0;i<len;i++){
		if(!isalpha(s[i]))continue;
		A[tolower(s[i])-'a']++;
	}
	vector<pair<int,char> > v;
	for(int i=0;i<26;i++)
		v.push_back(make_pair(A[i],'a'+i));
	
	sort(v.begin(),v.end(),greater<pair<int,char> >());
	for(int i=0;i<v.size();i++)
		cout<<v[i].first<<" "<<v[i].second<<endl;
}	
