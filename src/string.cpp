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

char* String::strcpy(char *dest, const char *src){
	 int i = 0;
	 for( ; src[i]!='\0';++i){
	 	dest[i]=src[i];
	 }
	 dest[i]='\0';
	 return dest;
}

char* String::strncpy(char *dest, const char *src, int n){
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

char* String::strcat(char *dest, const char *src){
	int i=0;
	while(dest[i]!='\0'){
		++i;
	}
	strcpy(dest + i, src);
	return dest;
}

char* String::strncat(char *dest, const char *src, int n){
	int i=0;
	while(dest[i]!='\0'){
		++i;
	}
	strncpy(dest + i, src, n);
	return dest;
}

int String::indexOf(char c) const {
    const char *p = strchr(buf, c);
    if (p == nullptr)
        return -1;
    return p - buf;
}

const char *String::strchr(const char *str, char c){
	int i = 0;
    	for ( ; str[i] != '\0'; ++i){
        	if (str[i] == c)
            	return &str[i];
    	}
    	if (c == '\0')
        	return &str[i];
    	return nullptr;
}

int String::indexOf(const String &s) const {
    const char *p = strstr(buf, s.buf);
    if (p == nullptr)
        return -1;
    return p - buf;
}

const char *String::strstr(const char *haystack, const char *needle){
    for (int i = 0; ; ++i){
        int j = 0;
        while (needle[j] != '\0' && haystack[i + j] == needle[j])
            ++j;
        if (needle[j] == '\0')
            return &haystack[i];
        if (haystack[i] == '\0')
            return nullptr;
    }
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

void String::reverse_cpy(char *dest, const char *src){
    int len = strlen(src);
    for (int i = 0; i < len; ++i)
        dest[i] = src[len - 1 - i];
    dest[len] = '\0';
}

String String::reverse() const {
    String result;
    reverse_cpy(result.buf, buf);
    return result;
}

void String::print(std::ostream &out) const{
	out<<buf;
}

ostream &operator<<(ostream &out, const String &s){
	s.print(out);
	return out;
}
