#include "DynamicString.h"
#include <iostream>
#include <stdexcept>
#define DEFAULT_SIZE 20
using std::cout;
using std::endl;

int DynamicString::myStringLen(const char* str){
   
	int size = 0;
	while (*str++) size++;
	return size;
	
}

DynamicString::DynamicString() {
	
	cstr = new char[1];
	*cstr = '\0';


}

DynamicString::DynamicString(const char* str) {

	int size = myStringLen(str);
	cstr = new char[size + 1];

	for (int i = 0; i <= size; i++)
		cstr[i] = str[i];

}

int DynamicString::len() const {
	
	int len = 0;
	while (cstr[len] != '\0')
	{
		len++;
	}

	return len;
	

}

const char* DynamicString::c_str() const {

	return cstr;
}

char& DynamicString::char_at(int position) {
	if (position >= len() || position < 0)
		throw std::out_of_range("NUMBER IS OUT OF RANGE");

	return cstr[position];
}

char DynamicString::char_at(int position) const {
	if (position >= len() || position < 0)
		throw std::out_of_range("NUMBER IS OUT OF RANGE");

	return cstr[position];
}

char& DynamicString::operator[](int position) {
	if (position >= len() || position < 0)
		throw std::out_of_range("NUMBER IS OUT OF RANGE");
	
	return cstr[position];
}

char DynamicString::operator[](int position) const {
	if (position >= len() || position < 0)
		throw std::out_of_range("NUMBER IS OUT OF RANGE");

	return cstr[position];
}

bool DynamicString::isPrefix(const DynamicString& other) const {


		for (int i = 0; i < other.len(); i++)
		{
			if (cstr[i] != other.cstr[i]) {

				return false;
			}
		}
		return true;

}

	


bool DynamicString::isIPrefix(const DynamicString& other) const {

	char lettercstr;
	char letterother;

	if (other.len() <= len()) {

		for (int i = 0; i < other.len(); i++)
		{
			lettercstr = cstr[i];
			if (lettercstr >= 'A' && lettercstr <= 'Z')
				lettercstr = lettercstr - 'A' + 'a';

			letterother = other.cstr[i];
			if (letterother >= 'A' && letterother <= 'Z')
				letterother = letterother - 'A' + 'a';

			if (lettercstr != letterother)
				return false;

		}
		return true;
	}

	return false;

}

bool DynamicString::isSuffix(const DynamicString& other) const {

	int cstrlength = len();
	int otherlength = other.len();

	if (otherlength <= cstrlength) {

		while (otherlength >= 0) {

			if (cstr[cstrlength] != other.cstr[otherlength]) {

				return false;
			}
			cstrlength--;
			otherlength--;	
		}
		return true;
	}
	return false;
}

bool DynamicString::isISuffix(const DynamicString& other) const {

	int cstrlength = len();
	int otherlength = other.len();

	char cstrletter;
	char otherletter;

	if (otherlength <= cstrlength) {

		while (otherlength >= 0) {

				cstrletter = cstr[cstrlength];
				if (cstrletter >= 'A' && cstrletter <= 'Z')
					cstrletter = cstrletter - 'A' + 'a';

				otherletter = other.cstr[otherlength];
				if (otherletter >= 'A' && otherletter <= 'Z')
					otherletter = otherletter - 'A' + 'a';

					if (cstrletter != otherletter) {

						return false;
					}
					cstrlength--;
					otherlength--;
		}
		return true;
	}
	return false;
}

int DynamicString::compare(const DynamicString& other) const {
	return 100;
}

int DynamicString::iCompare(const DynamicString& other) const {
	return 10;
}

DynamicString& DynamicString::toLower() {
	
	char cstrletter;

	for (int i = 0; i <= len(); i++) {
		cstrletter = cstr[i];

			if (isupper(cstrletter))
				cstr[i] = tolower(cstrletter);
	}
	return *this;
}

DynamicString& DynamicString::toUpper() {

	char cstrletter;

	for (int i = 0; i <= len(); i++) {
		cstrletter = cstr[i];

		if (islower(cstrletter))
			cstr[i] = toupper(cstrletter);
	}
	return *this;
}


DynamicString::DynamicString(const DynamicString& other) {
	int size = other.len();
	cstr = new char[other.len() + 1];
	copyStr(cstr, other.cstr, other.len());
}

DynamicString::~DynamicString() {
	if (cstr) {
		delete cstr;
		cstr = nullptr;
	}
}

DynamicString& DynamicString::operator=(const DynamicString& other) {
	int size = other.len();
	if (cstr) {
		delete cstr;
		cstr = nullptr;
	}
	cstr = new char[other.len() + 1];
	if (this != &other) {
		for (int i = 0; i < size + 1; i++) {
			cstr[i] = other.cstr[i];
		}
	}
	return *this;
}

DynamicString& DynamicString::trim() {
	int first = 0;
	while (cstr[first] == ' ' || cstr[first] == '\n' || cstr[first] == '\r' || cstr[first] == '\t') {

		first++;
	}

	int second = len() - 1;
	while (cstr[second] == ' ' || cstr[second] == '\n' || cstr[second] == '\r' || cstr[second] == '\t') {

		second--;
	}

	if (first != 0 || second != len() - 1) {
		int x = 0;
		int i;

		for (i = first; i <= second; i++, x++) {

			cstr[x] = cstr[i];

		}
		cstr[x] = '\0';
	}

return *this;

}

DynamicString DynamicString::operator+(const DynamicString& other) const {
	return this->concat(other);
}

DynamicString DynamicString::concat(const DynamicString& other) const {
	char* concat = new char[len() + other.len() + 1];
	copyStr(concat, cstr, len());
	copyStr(concat + len(), other.cstr, other.len());
	DynamicString retVal(concat);
	delete[] concat;
	concat = nullptr;

	return retVal;
}


int DynamicString::find(int start, char c) const {

	for (int i = start; i < len(); i++) {

		if (cstr[i] == c) {
			return i;
		}
		
	}
return -1;
}

int DynamicString::reverseFind(int start, char c) const {
	for (int i = start; i >= 0; i--) {
		if (cstr[i] == c) {
			return i;
		}
	}
	return -1;
}

void DynamicString::subStr(char* buf, int start, int end) const {

		for (int i = start, j = 0; i < end; i++, j++) {
			buf[j] = cstr[i];
		}


		buf[end - start] = '\0';
	
	
}

void DynamicString::copyStr(char* buf, char* old, int size) const {
	for (int i = 0; i <= size; i++) {
	buf[i] = old[i];

	}
	buf[size] = '\0';

}
