#include "DynamicString.h"
#include <iostream>
#include <stdexcept>
#include <cstring>

using std::cout;
using std::endl;
using std::out_of_range;
using std::strcmp;

template <typename T>
void test(int testNum, int& correct, T actual, T expected) {

	if (actual == expected) {
		correct++;
		cout << "Passed Test " << testNum << endl;
	}
	else {
		cout << "***Failed Test " << testNum << "***" << endl;
		cout << "Actual: " << actual << " Expected: " << expected << endl;
	}
}

void testString(int testNum, int& correct, const char* actual, const char* expected) {

	if (actual && expected && strcmp(actual, expected) == 0) {
		correct++;
		cout << "Passed Test " << testNum << endl;
	}
	else {
		cout << "***Failed Test " << testNum << "***" << endl;
		if (actual && expected) {
			cout << "Actual: " << actual << " Expected: " << expected << endl;
		}
	}
}

int main() {

	int testNum = 1;
	int correct = 0;

	cout << "--------Trim Tests--------" << endl;
	DynamicString s1;
	test(testNum++, correct, s1.trim().len(), 0);
	testString(testNum++, correct, s1.trim().c_str(), "");
	DynamicString s2("abc");
	test(testNum++, correct, s2.trim().len(), 3);
	testString(testNum++, correct, s2.trim().c_str(), "abc");
	DynamicString s3("   abcd");
	test(testNum++, correct, s3.trim().len(), 4);
	testString(testNum++, correct, s3.trim().c_str(), "abcd");
	DynamicString s4(" \ncba");
	test(testNum++, correct, s4.trim().len(), 3);
	testString(testNum++, correct, s4.trim().c_str(), "cba");
	DynamicString s5("\t\ncb");
	test(testNum++, correct, s5.trim().len(), 2);
	testString(testNum++, correct, s5.trim().c_str(), "cb");
	DynamicString s6("abc  ");
	test(testNum++, correct, s6.trim().len(), 3);
	testString(testNum++, correct, s6.trim().c_str(), "abc");
	DynamicString s7(" \nbac\n ");
	test(testNum++, correct, s7.trim().len(), 3);
	testString(testNum++, correct, s7.trim().c_str(), "bac");
	DynamicString s8(" \t\nbac\n\t");
	test(testNum++, correct, s8.trim().len(), 3);
	testString(testNum++, correct, s8.trim().c_str(), "bac");
	DynamicString s9(" \t?\na bc\n\t");
	test(testNum++, correct, s9.trim().len(), 6);
	testString(testNum++, correct, s9.trim().c_str(), "?\na bc");



	cout << "--------Concatentation Tests--------" << endl;
	DynamicString s10 = s1 + s2;
	test(testNum++, correct, s10.len(), 3);
	testString(testNum++, correct, s10.c_str(), "abc");
	DynamicString s11 = s2 + s3;
	test(testNum++, correct, s11.len(), 3);
	testString(testNum++, correct, s11.c_str(), "abc");
	DynamicString s12 = s2 + s2;
	test(testNum++, correct, s12.len(), 6);
	testString(testNum++, correct, s12.c_str(), "abcabc");
	DynamicString s13 = s6 + s3;
	test(testNum++, correct, s13.len(), 12);
	testString(testNum++, correct, s13.c_str(), "abc     abcd");
	DynamicString s14 = s1.concat(s2);
	test(testNum++, correct, s14.len(), 3);
	testString(testNum++, correct, s14.c_str(), "abc");
	DynamicString s15 = s2.concat(s3);
	test(testNum++, correct, s15.len(), 3);
	testString(testNum++, correct, s15.c_str(), "abc");
	DynamicString s16 = s2.concat(s2);
	test(testNum++, correct, s16.len(), 6);
	testString(testNum++, correct, s16.c_str(), "abcabc");
	DynamicString s17 = s6.concat(s3);
	test(testNum++, correct, s17.len(), 12);
	testString(testNum++, correct, s17.c_str(), "abc     abcd");


	cout << "--------Find Tests--------" << endl;
	test(testNum++, correct, s1.find(0, 'a'), -1);
	test(testNum++, correct, s2.find(0, 'a'), 0);
	test(testNum++, correct, s2.find(1, 'a'), -1);
	test(testNum++, correct, s2.find(0, 'b'), 1);
	test(testNum++, correct, s2.find(0, 'd'), -1);
	test(testNum++, correct, s2.find(10, 'a'), -1);
	DynamicString s18("baa baa black sheep");
	test(testNum++, correct, s18.find(0, 'c'), 11);
	test(testNum++, correct, s18.find(7, 'a'), 10);
	test(testNum++, correct, s18.find(0, 'p'), 18);


	cout << "--------Reverse Find Tests--------" << endl;
	test(testNum++, correct, s1.reverseFind(0, 'a'), -1);
	test(testNum++, correct, s2.reverseFind(2, 'a'), 0);
	test(testNum++, correct, s2.reverseFind(2, 'b'), 1);
	test(testNum++, correct, s2.reverseFind(2, 'd'), -1);
	test(testNum++, correct, s2.reverseFind(10, 'a'), 0);
	test(testNum++, correct, s18.reverseFind(18, 'c'), 11);
	test(testNum++, correct, s18.reverseFind(18, 'a'), 10);
	test(testNum++, correct, s18.reverseFind(4, 'a'), 2);
	test(testNum++, correct, s18.reverseFind(10, 'p'), -1);


	cout << "--------Substring Tests--------" << endl;
	char* tmp = new char[32];
	s2.subStr(tmp, 0, 1);
	testString(testNum++, correct, tmp, "a");
	s2.subStr(tmp, 0, 3);
	testString(testNum++, correct, tmp, "abc");
	s18.subStr(tmp, 8, 13);
	testString(testNum++, correct, tmp, "black");
	s18.subStr(tmp + 5, 0, 13);
	testString(testNum++, correct, tmp, "blackbaa baa black");
	delete[] tmp;


	cout << "--------Memory Management Tests--------" << endl;
	DynamicString* s19 = new DynamicString(s2);
	s19->char_at(0) = 'b';
	test(testNum++, correct, s19->char_at(0), 'b');
	test(testNum++, correct, s2.char_at(0), 'a');
	DynamicString* s20 = new DynamicString(*s19);
	*s20 = s18;
	s20->char_at(0) = 'a';
	test(testNum++, correct, s20->char_at(0), 'a');
	test(testNum++, correct, s18.char_at(0), 'b');
	delete s20;
	delete s19;
	test(testNum++, correct, 0, 0);


	cout << "Passed " << correct << "/" << --testNum << " tests" << endl;
	cout << "Score: " << correct / float(testNum) << endl;
	cout << "Points: " << 60 * correct / float(testNum) << endl;

}