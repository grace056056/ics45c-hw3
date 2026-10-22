#include <iostream>
#include "string.hpp"
using namespace std;


bool String::operator==(const String &s) const {
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String &s) const {
    return strcmp(buf, s.buf) != 0;
}

bool String::operator<(const String &s) const {
    return strcmp(buf, s.buf) < 0;
}

bool String::operator>(const String &s) const {
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<=(const String &s) const {
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(const String &s) const {
    return strcmp(buf, s.buf) >= 0;
}

String &String::operator=(const String &s) {
    strcpy(buf, s.buf);
    return *this;
}

int String::strlen(const char *s){
	int len = 0;
	while (s[len]!='\0'){
		++len;
	}
	return len;
}

char *String::strcpy(char *dest, const char *src){
	 int i = 0;
	 for( ; src[i]!='\0';++i){
	 	dest[i]=src[i];
	 }
	 dest[i]='\0';
	 return dest;
}

char *String::strncpy(char *dest, const char *src, int n){
	int i = 0;
	for( ; src[i]!='\0'&&i<n; ++i){
		dest[i]=src[i];
	}
	dest[i]='\0';
	return dest;
}

int String::strcmp(const char *left, const char *right){
	int i=0;
	while(left[i]==right[i] && left[i]!='\0'){
		++i;
	}
	return left[i]-right[i];
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
