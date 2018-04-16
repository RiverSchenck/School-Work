#include "Url.h"
#include "DynamicString.h"
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::invalid_argument;
using std::strcmp;
using std::string;
using std::ostringstream;

template <typename T>
void test(int testNum, int& correct, T actual, T expected){

   if(actual == expected){
      correct++;
      cout << "Passed Test " << testNum << endl;
   }
   else{
      cout << "***Failed Test " << testNum << "***" << endl;
      cout << "Actual: " << actual << " Expected: " << expected << endl;
   }
}

void testString(int testNum, int& correct, const char* actual, const char* expected){

   if(actual && expected && strcmp(actual, expected) == 0){
      correct++;
      cout << "Passed Test " << testNum << endl;
   }
   else{
      cout << "***Failed Test " << testNum << "***" << endl;
      if(actual && expected){
         cout << "Actual: " << actual << " Expected: " << expected << endl;
      }
   }
}

int main(){

   int testNum  = 1;
   int correct = 0;

   cout << "--------URL Part 1 Tests--------" << endl;
   cout << "--------URL Parsing Tests--------" << endl;
   cout << "--------Scheme and Host--------" << endl;
   /*Scheme and Host*/
   Url u1("http://www.icarus.cs.weber.edu");
   testString(testNum++, correct, u1.c_str(), "http://www.icarus.cs.weber.edu");
   testString(testNum++, correct, u1.getScheme().c_str(), "http");
   testString(testNum++, correct, u1.getAuthority().c_str(), "www.icarus.cs.weber.edu");
   testString(testNum++, correct, u1.getPath().c_str(), "");
   testString(testNum++, correct, u1.getQuery().c_str(), "");
   testString(testNum++, correct, u1.getFragment().c_str(), "");

   /*Scheme and Host*/
   Url u2("https://icarus.cs.weber.edu");
   //7
   testString(testNum++, correct, u2.c_str(), "https://icarus.cs.weber.edu");
   testString(testNum++, correct, u2.getScheme().c_str(), "https");
   testString(testNum++, correct, u2.getAuthority().c_str(), "icarus.cs.weber.edu");
   testString(testNum++, correct, u2.getPath().c_str(), "");
   testString(testNum++, correct, u2.getQuery().c_str(), "");
   testString(testNum++, correct, u2.getFragment().c_str(), "");

   /*Scheme and Host*/
   Url u3("smb://kfeuz@athena.cs.weber.edu");
   //13
   testString(testNum++, correct, u3.c_str(), "smb://kfeuz@athena.cs.weber.edu");
   testString(testNum++, correct, u3.getScheme().c_str(), "smb");
   testString(testNum++, correct, u3.getAuthority().c_str(), "kfeuz@athena.cs.weber.edu");
   testString(testNum++, correct, u3.getPath().c_str(), "");
   testString(testNum++, correct, u3.getQuery().c_str(), "");
   testString(testNum++, correct, u3.getFragment().c_str(), "");


   /*Scheme and Path*/
   cout << "--------Scheme and Path--------" << endl;
   Url u4("file:///home/cs2420/assignment3/");
   //19
   testString(testNum++, correct, u4.c_str(), "file:///home/cs2420/assignment3/");
   testString(testNum++, correct, u4.getScheme().c_str(), "file");
   testString(testNum++, correct, u4.getAuthority().c_str(), "");
   testString(testNum++, correct, u4.getPath().c_str(), "/home/cs2420/assignment3/");
   testString(testNum++, correct, u4.getQuery().c_str(), "");
   testString(testNum++, correct, u4.getFragment().c_str(), "");

   /*Scheme Host and Path*/
   cout << "--------Scheme Host and Path--------" << endl;
   Url u5("http://icarus.cs.weber.edu/~kfeuz/index.html");
   //25
   testString(testNum++, correct, u5.c_str(), "http://icarus.cs.weber.edu/~kfeuz/index.html");
   testString(testNum++, correct, u5.getScheme().c_str(), "http");
   testString(testNum++, correct, u5.getAuthority().c_str(), "icarus.cs.weber.edu");
   testString(testNum++, correct, u5.getPath().c_str(), "/~kfeuz/index.html");
   testString(testNum++, correct, u5.getQuery().c_str(), "");
   testString(testNum++, correct, u5.getFragment().c_str(), "");

   /*Scheme Host and Path*/
   cout << "--------Scheme Host and Path--------" << endl;
   Url u26("https://kfeuz@github.com/feuz-cs2420-spring2018/");
   //31
   testString(testNum++, correct, u26.c_str(), "https://kfeuz@github.com/feuz-cs2420-spring2018/");
   testString(testNum++, correct, u26.getScheme().c_str(), "https");
   testString(testNum++, correct, u26.getAuthority().c_str(), "kfeuz@github.com");
   testString(testNum++, correct, u26.getPath().c_str(), "/feuz-cs2420-spring2018/");
   testString(testNum++, correct, u26.getQuery().c_str(), "");
   testString(testNum++, correct, u26.getFragment().c_str(), "");


   /*Scheme Host Path and Query*/
   cout << "--------Scheme Host Path and Query--------" << endl;
   Url u6("https://weber.edu/index.html?lang=en");
   //37
   testString(testNum++, correct, u6.c_str(), "https://weber.edu/index.html?lang=en");
   testString(testNum++, correct, u6.getScheme().c_str(), "https");
   testString(testNum++, correct, u6.getAuthority().c_str(), "weber.edu");
   testString(testNum++, correct, u6.getPath().c_str(), "/index.html");
   testString(testNum++, correct, u6.getQuery().c_str(), "lang=en");
   testString(testNum++, correct, u6.getFragment().c_str(), "");

   /*Scheme Host Path Query and Fragment*/
   cout << "--------Scheme Host Path Query and Fragment--------" << endl;
   Url u7("http://cplusplus.com/index.html?version=c++11#Reference");
   //43
   testString(testNum++, correct, u7.c_str(), "http://cplusplus.com/index.html?version=c++11#Reference");
   testString(testNum++, correct, u7.getScheme().c_str(), "http");
   testString(testNum++, correct, u7.getAuthority().c_str(), "cplusplus.com");
   testString(testNum++, correct, u7.getPath().c_str(), "/index.html");
   testString(testNum++, correct, u7.getQuery().c_str(), "version=c++11");
   testString(testNum++, correct, u7.getFragment().c_str(), "Reference");

   /*Scheme Host Path and Fragment*/
   cout << "--------Scheme Host Path and Fragment--------" << endl;
   Url u8("https://wikipedia.org/index.html#Help");
   //49
   testString(testNum++, correct, u8.c_str(), "https://wikipedia.org/index.html#Help");
   testString(testNum++, correct, u8.getScheme().c_str(), "https");
   testString(testNum++, correct, u8.getAuthority().c_str(), "wikipedia.org");
   testString(testNum++, correct, u8.getPath().c_str(), "/index.html");
   testString(testNum++, correct, u8.getQuery().c_str(), "");
   testString(testNum++, correct, u8.getFragment().c_str(), "Help");

   cout << "--------Compare--------" << endl;
   /*Compare*/
   test(testNum++, correct, u1.compare(u2)<0, true);
   test(testNum++, correct, u3.compare(u4)>0, true);
   test(testNum++, correct, u6.compare(u7)>0, true);
   test(testNum++, correct, u8.compare(u8), 0);
   Url u9("HTTP://cplusplus.com/index.html?version=c++11#Reference");
   test(testNum++, correct, u7.compare(u9), 0);
   Url u10("http://CPLUSPLUS.COM/index.html?version=c++11#Reference");
   test(testNum++, correct, u10.compare(u7), 0);
   Url u11("http://cplusplus.com/INDEX.html?version=c++11#Reference");
   test(testNum++, correct, u7.compare(u11)>0, true);
   /*CompareIgnoreFragx*/
   cout << "--------CompareIgnoreFrag--------" << endl;
   //"https://kfeuz@github.com/feuz-cs2420-spring2018/"
   Url u12("https://weber.edu/index.html?lang=en#Gotcha");
   test(testNum++, correct, u6.compareIgnoreFrag(u12), 0);
   Url u13("HTTPS://weber.edu/index.html?lang=en#Gotcha");
   test(testNum++, correct, u6.compareIgnoreFrag(u13), 0);
   Url u14("https://WEBER.edu/index.html?lang=en#IgnoreMe");
   test(testNum++, correct, u14.compareIgnoreFrag(u6), 0);
   Url u15("https://weber.edu/INDEX.html?lang=en#Gotcha");
   test(testNum++, correct, u6.compareIgnoreFrag(u15)>0, true);


   cout << "--------Error Checking--------" << endl;
   try{
      Url u21("google.com");//invalid argument(no scheme)
      test(testNum++, correct, 0, 1);
   }
   catch(invalid_argument){
      test(testNum++, correct, 0, 0);
   }
   try{
      Url u30("/index.html");//invalid argument (relative url)
      test(testNum++, correct, 0, 1);
   }
   catch(invalid_argument){
      test(testNum++, correct, 0, 0);
   }
   try{
      Url u27("://weber.edu");//invalid argument(no scheme)
      test(testNum++, correct, 0, 1);
   }
   catch(invalid_argument){
      test(testNum++, correct, 0, 0);
   }

   int correct1 = correct;
   int testNum1 = testNum-1;

   cout << "--------URL Part2 Tests--------" << endl;
   correct = 0;
   testNum = 1;

   cout << "--------Output Operator--------" << endl;
   ostringstream ostr;
   ostr << u1;
   test(testNum++, correct, ostr.str(), string("http://www.icarus.cs.weber.edu"));
   ostr.clear(); ostr.str("");
   ostr << u4;
   test(testNum++, correct, ostr.str(), string("file:///home/cs2420/assignment3/"));
   ostr.clear(); ostr.str("");
   ostr << u7;
   test(testNum++, correct, ostr.str(), string("http://cplusplus.com/index.html?version=c++11#Reference"));
   ostr.clear(); ostr.str("");
   ostr << u8;
   test(testNum++, correct, ostr.str(), string("https://wikipedia.org/index.html#Help"));

   cout << "--------Resolve Relative URLs--------" << endl;
   cout << "--------Resolve Relative '/'--------" << endl;
   DynamicString relURL("/images/logo.png");
   ostr.clear(); ostr.str("");
   ostr << u1.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("http://www.icarus.cs.weber.edu/images/logo.png"));
   ostr.clear(); ostr.str("");
   ostr << u4.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("file:///images/logo.png"));
   ostr.clear(); ostr.str("");
   ostr << u7.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("http://cplusplus.com/images/logo.png"));
   ostr.clear(); ostr.str("");
   ostr << u8.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("https://wikipedia.org/images/logo.png"));
   testString(testNum++, correct, u26.resolveRelativeURL(relURL).c_str(), "https://kfeuz@github.com/images/logo.png");

   cout << "--------Resolve Relative './'--------" << endl;
   relURL = "./local.js";
   ostr.clear(); ostr.str("");
   ostr << u2.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("https://icarus.cs.weber.edu/local.js"));
   ostr.clear(); ostr.str("");
   ostr << u4.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("file:///home/cs2420/assignment3/local.js"));
   ostr.clear(); ostr.str("");
   ostr << u5.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("http://icarus.cs.weber.edu/~kfeuz/local.js"));//
   ostr.clear(); ostr.str("");
   ostr << u7.resolveRelativeURL(relURL);;
   test(testNum++, correct, ostr.str(), string("http://cplusplus.com/local.js"));//
   testString(testNum++, correct, u26.resolveRelativeURL(relURL).c_str(), "https://kfeuz@github.com/feuz-cs2420-spring2018/local.js");


   cout << "--------Resolve Relative '../'--------" << endl;
   relURL = "../style.css";
   ostr.clear(); ostr.str("");
   ostr << u4.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("file:///home/cs2420/style.css"));
   ostr.clear(); ostr.str("");
   ostr << u5.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("http://icarus.cs.weber.edu/style.css"));
   ostr.clear(); ostr.str("");
   ostr << u2.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("https://icarus.cs.weber.edu/style.css"));
   testString(testNum++, correct, u26.resolveRelativeURL(relURL).c_str(), "https://kfeuz@github.com/style.css");


   cout << "--------Resolve Relative ''--------" << endl;
   relURL = "app.py?date=now&record=true#Today";
   ostr.clear(); ostr.str("");
   ostr << u1.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("http://www.icarus.cs.weber.edu/app.py?date=now&record=true#Today"));//
   ostr.clear(); ostr.str("");
   ostr << u4.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("file:///home/cs2420/assignment3/app.py?date=now&record=true#Today"));
   ostr.clear(); ostr.str("");
   Url u16 = u7.resolveRelativeURL(relURL);
   ostr << u16;
   test(testNum++, correct, ostr.str(), string("http://cplusplus.com/app.py?date=now&record=true#Today"));
   testString(testNum++, correct, u16.getPath().c_str(), "/app.py");
   testString(testNum++, correct, u16.getQuery().c_str(), "date=now&record=true");
   testString(testNum++, correct, u16.getFragment().c_str(), "Today");
   Url u28 = u26.resolveRelativeURL(relURL).c_str();
   testString(testNum++, correct, u28.c_str(), "https://kfeuz@github.com/feuz-cs2420-spring2018/app.py?date=now&record=true#Today");//
   testString(testNum++, correct, u28.getPath().c_str(), "/feuz-cs2420-spring2018/app.py");
   testString(testNum++, correct, u28.getQuery().c_str(), "date=now&record=true");
   testString(testNum++, correct, u28.getFragment().c_str(), "Today");

  //scheme://authority/path?query#fragment
   //u1 http://www.icarus.cs.weber.edu
   //u2 https://icarus.cs.weber.edu
   //u3 smb://kfeuz@athena.cs.weber.edu
   //u4 file:///home/cs2420/assignment3
   //u5 http://icarus.cs.weber.edu/~kfeuz/index.html
   //u6 https://weber.edu/index.html?lang=en
   //u7 http://cplusplus.com/index.html?version=c++11#Reference
   //u26https://kfeuz@github.com/feuz-cs2420-spring2018/
   cout << "--------Resolve Relative '../../../'--------" << endl;
   relURL = "../../../../../../wayback.jsp";
   ostr.clear(); ostr.str("");
   ostr << u1.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("http://www.icarus.cs.weber.edu/wayback.jsp"));
   ostr.clear(); ostr.str("");
   ostr << u4.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("file:///wayback.jsp"));
   ostr.clear(); ostr.str("");
   Url u17("http://my.example.com/this/is/a/long/path/to/some/file/name.htm");
   ostr << u17.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("http://my.example.com/this/is/wayback.jsp"));

   cout << "--------Resolve Relative 'absolute'--------" << endl;
   relURL = "http://osiris.cs.weber.edu/";
   ostr.clear(); ostr.str("");
   ostr << u1.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("http://osiris.cs.weber.edu/"));
   relURL = "file:///home/user/data.htm";
   ostr.clear(); ostr.str("");
   ostr << u1.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("file:///home/user/data.htm"));
   relURL = "https://osiris.cs.weber.edu/files/faq.php";
   ostr.clear(); ostr.str("");
   ostr << u1.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("https://osiris.cs.weber.edu/files/faq.php"));
   relURL = "smb://localhost/home/user/data.htm";
   ostr.clear(); ostr.str("");
   ostr << u1.resolveRelativeURL(relURL);
   test(testNum++, correct, ostr.str(), string("smb://localhost/home/user/data.htm"));
   relURL = "https://osiris.cs.weber.edu/files/faq.php?key=value#fake";
   Url u29 = u26.resolveRelativeURL(relURL);
   testString(testNum++, correct, u29.c_str(), "https://osiris.cs.weber.edu/files/faq.php?key=value#fake");
   testString(testNum++, correct, u29.getAuthority().c_str(), "osiris.cs.weber.edu");
   testString(testNum++, correct, u29.getPath().c_str(), "/files/faq.php");
   testString(testNum++, correct, u29.getQuery().c_str(), "key=value");
   testString(testNum++, correct, u29.getFragment().c_str(), "fake");

   cout << "--------isHTML--------" << endl;
   test(testNum++, correct, u5.isHTML(), true);
   test(testNum++, correct, u7.isHTML(), true);
   Url u18("http://localhost/styles.css");
   test(testNum++, correct, u18.isHTML(), false);
   Url u19("https://example.org/bs.js");
   test(testNum++, correct, u19.isHTML(), false);
   Url u20("file:///home/www/index.jsp");//
   test(testNum++, correct, u20.isHTML(), true);
   Url u21("smb://localhost/home/www/index.asp");
   test(testNum++, correct, u21.isHTML(), true);
   Url u22("file:///home/www/index.aspx");//
   test(testNum++, correct, u22.isHTML(), true);
   Url u23("file:///home/www/index.py");//
   test(testNum++, correct, u23.isHTML(), true);
   Url u24("file:///home/www/index.php");//
   test(testNum++, correct, u24.isHTML(), true);
   Url u25("file:///home/www/image.jpeg");
   test(testNum++, correct, u25.isHTML(), false);

   cout << endl << "-------Part 1 results-------" << endl;
   cout << "Passed " << correct1 << "/" << testNum1 << " tests" << endl;
   cout << "Score: " << correct1/float(testNum1) << endl;
   cout << "Points: " << 60*correct1/float(testNum1) << endl << endl;

   cout << "--------Part 2 results--------" << endl;
   cout << "Passed " << correct << "/" << --testNum << " tests" << endl;
   cout << "Score: " << correct/float(testNum) << endl;
   cout << "Points: " << 60*correct/float(testNum) << endl;

}
