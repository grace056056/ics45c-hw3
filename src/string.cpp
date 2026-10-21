#include <iostream>
#include "string.hpp"
using namespace std;

int String::strlen(const char *s){
	int len = 0;
	while (s[len]!='\0'){
		++len;
	}
	return len;
}

char *String::strncpy(char *dest, const char *src, int n){
	int i = 0;
	for( ; src[i]!='\0'&&i<n; ++i){
		dest[i]=src[i];
	}
	dest[i]='\0';
	return dest;
}

String::String(const char *s){
	strncpy(buf, s, MAXLEN-1);
}

String::String(const String &s){
	strncpy(buf, s.buf, MAXLEN-1);
}

String::~String(){
	cout<<"String "<<buf<<" is destructing."<<endl;
}

int String::size() const{
	return strlen(buf);
}

void String::print(std::ostream &out) const{
	out<<buf;
}

ostream &operator<<(ostream &out, const String &s){
	s.print(out);
	return out;
}
