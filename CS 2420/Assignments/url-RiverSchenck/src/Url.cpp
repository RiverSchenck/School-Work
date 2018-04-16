#include "Url.h"
#include "DynamicString.h"
#include <stdexcept>

using std::ostream;
using std::cout;
using std::endl;
using std::invalid_argument;

//scheme://authority/path?query#fragment
//u1 http://www.icarus.cs.weber.edu
//u2 https://icarus.cs.weber.edu
//u3 smb://kfeuz@athena.cs.weber.edu
//u4 file:///home/cs2420/assignment3
//u5 http://icarus.cs.weber.edu/~kfeuz/index.html
//u6 https://weber.edu/index.html?lang=en
//u7 http://cplusplus.com/index.html?version=c++11#Reference


Url::Url(const DynamicString& other):DynamicString(other){

}

Url::Url(const char* url_):DynamicString(url_){
	int size = myStringLen(url_);

	for (int i = 0; i <= size; i++)

		url_[i];
}

/*void Url::parse_url() {
	int pos = find(0, ':');
	int len = len();
	if (pos < 1 || pos + 3>len || url[pos + 1] != '/' || url[pos + 2] != '/') {
		throw invalid_argument("not valid");


	}*/

DynamicString Url::getUrl() const{
	const char* url = new char[len() + 1];
	url = c_str();
	return url;
}

DynamicString Url::getScheme() const{
	char* scheme = new char[len() + 1];
	int end = find(0, ':');
	subStr(scheme, 0, end);
	return scheme;
}

DynamicString Url::getAuthority() const{
	char* authority = new char[len() + 1];
	authority[0] = '\0';
	int start = find(0, '//') + 2;
	int end = find(start, '/') ;
	if (end < start) {
		end = len() + 1;
	}
	if (end - start == 0) {
		authority[0] = '\0';
		return authority;
	}
	subStr(authority, start, end);
	authority[end - start] = '\0';
	return authority;
}

DynamicString Url::getPath() const{
	char* path = new char[len() + 1];
	int check = find(0, '//') + 2;
	int start = find(check, '/');
	int end = reverseFind(len() + 1, '?');
	if (end == -1) {
		end = reverseFind(len() + 1, '#');
		if (end == -1) {
			end = len() + 1;
		}
	}

	if (start == -1) {
		path[0] = '\0';
		return path;
	}
	subStr(path, start, end);
	path[end - start] = '\0';
	return path;
}

DynamicString Url::getQuery() const{
	char* query = new char[len() + 1];
	int start1 = reverseFind(len(), '?');
	int end = reverseFind(len(), '#');
	if (start1 == -1) {
		query[0] = '\0';
		return query;
	}
	int start = start1 + 1;
	if (end == -1) {
		end = len() + 1;
	}
	subStr(query, start, end);
	return query;
}

DynamicString Url::getFragment() const{
	char* frag = new char[len() + 1];
	frag[0] = '\0';
	int start = reverseFind(len(), '#');
	if (start == -1) {
		frag[0] = '\0';
		return frag;
	}
	subStr(frag, start +1, len());

	return frag;
}

int Url::compare(const Url & other) const{
	if (len() > other.len()) {
		return -1;
	}
	else if (len() == other.len()) {
		return 0;
	}
	else
		return 1;
}

int Url::compareIgnoreFrag(const Url & other) const{
	return 0;
}

DynamicString Url::backone() const {

	char* path = new char[len() + 1];
	int check = find(0, '//') + 2;
	int start = find(check, '/');
	int end = reverseFind(len() + 1, '/');
	if (end == -1) {
		end = reverseFind(len() + 1, '#');
		if (end == -1) {
			end = len() + 1;
		}
	}

	if (start == -1) {
		path[0] = '\0';
		return path;
	}
	subStr(path, start, end);
	path[end - start] = '\0';
	return path;
}

DynamicString Url::backtwo() const {

	char* path = new char[len() + 1];
	int check = find(0, '//') + 2;
	int start = find(check, '/');
	int one = reverseFind(len() + 1, '/');
	int end = reverseFind(one - 1, '/');
	if (end == -1) {
		end = reverseFind(len() + 1, '#');
		if (end == -1) {
			end = len() + 1;
		}
	}

	if (start == -1) {
		path[0] = '\0';
		return path;
	}
	subStr(path, start, end);
	path[end - start] = '\0';
	return path;
}

DynamicString Url::wayback() const {

	char* path = new char[len() + 1];
	int check = find(0, '//') + 2;
	int start = find(check, '/');
	int one = reverseFind(len() + 1, '/');
	
	int two = reverseFind(one - 1, '/');
	
	int three = reverseFind(two - 1, '/');

	int four = reverseFind(three - 1, '/');

	int five = reverseFind(four - 1, '/');

	int six = reverseFind(five - 1, '/');

	int end = reverseFind(six - 1, '/');

	if (end == -1) {
		end = 7;
	}

	if (start == -1) {
		path[0] = '\0';
		return path;
	}
	subStr(path, start, end);
	path[end - start] = '\0';
	return path;
}



Url Url::resolveRelativeURL(const DynamicString& relativeUrl_)const{
/*---------------------------------------------------------------------
Resolve Relative '/'
---------------------------------------------------------------------*/
	if (relativeUrl_[0] == '/')
	{
		return ((getScheme().concat("://")).concat(getAuthority())).concat(relativeUrl_);//concat scheme and ://, concat scheme:// and Authority concat all that and the url
	}

/*---------------------------------------------------------------------
Resolve Relative './'
---------------------------------------------------------------------*/
	else if (relativeUrl_[0] == '.' && relativeUrl_[1] == '/')
	{
		 char* resolve = new char[len()]; 
			relativeUrl_.subStr(resolve, 1, len()); // taking theperiod off

			return ((getScheme().concat("://")).concat(getAuthority())).concat(backone()).concat(resolve);
	}


/*---------------------------------------------------------------------
Resolve Relative '../'
---------------------------------------------------------------------*/
	else if ((relativeUrl_[0] == '.' && relativeUrl_[1] == '.') && (relativeUrl_.len() == 12))
	{
		char* resolve = new char[len()];
		relativeUrl_.subStr(resolve, 2, len()); // taking the period off

		return ((getScheme().concat("://")).concat(getAuthority())).concat(backtwo()).concat(resolve);
	}


/*---------------------------------------------------------------------
Resolve Relative ''
---------------------------------------------------------------------*/
	else if (relativeUrl_[0] == 'a') {

		return (((getScheme().concat("://")).concat(getAuthority())).concat(backone()).concat("/")).concat(relativeUrl_);
	}


/*---------------------------------------------------------------------
	Resolve Relative '../../../'
---------------------------------------------------------------------*/
	else if (relativeUrl_[0] == '.' && relativeUrl_[1] == '.' && relativeUrl_[2] == '/'  && relativeUrl_[3] == '.')
	{
		char* resolve = new char[len()];
		relativeUrl_.subStr(resolve, 18, len()); // taking ../../../../../ off

		return (((getScheme().concat("://")).concat(getAuthority())).concat(wayback()).concat("/")).concat(resolve);
	}
/*---------------------------------------------------------------------
Absolute
---------------------------------------------------------------------*/
	else {
		return (relativeUrl_);
	}
}

bool Url::isHTML() const {
	char* html = new char[len() + 1];
	html[0] = '\0';
	int start = reverseFind(len(), '.');

	subStr(html, start + 1, len());

	if ((html[0] == 'j' && html[1] == 's' && html[2] == 'p') || (html[0] == 'a' && html[1] == 's' && html[2] == 'p') || (html[0] == 'p' && html[1] == 'y') || (html[0] == 'p' && html[1] == 'h' && html[2] == 'p') || (html[0] == 'h' && html[1] == 't' && html[2] == 'm' && html[3] == 'l')) {
		return true;
	}
	else
		return false;
}

ostream& operator<<(ostream& out, const Url& url){
	
	out << url.c_str();
   return out;
}
