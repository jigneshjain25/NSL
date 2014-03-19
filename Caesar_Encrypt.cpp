#include<iostream>
#include<cctype>
using namespace std;

int main(){

	string s;
	int key;
	cout<<"Enter plaintext\n";
	getline(cin,s);
	cout<<"Enter key\n";
	cin>>key;
	
	for(int i=0;i<s.length();i++){
		if(!isalpha(s[i]))cout<<s[i];
		else{
			char ch = tolower(s[i]);
			ch = ((ch-'a')+key)%26 + 'a';
			if(isupper(s[i]))ch=toupper(ch);
			cout<<ch;
		}
	}
	cout<<endl<<endl;			
}
