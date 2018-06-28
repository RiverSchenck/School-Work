#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>

#include "Infix.h"

using namespace std;


//This helps with testing, do not modify.
bool checkTest(string testName, string whatItShouldBe, string whatItIs) {

   //get rid of spaces
   whatItIs.erase(whatItIs.begin(), std::find_if(whatItIs.begin(), whatItIs.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
   whatItIs.erase(std::find_if(whatItIs.rbegin(), whatItIs.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), whatItIs.end());

   if (whatItShouldBe == whatItIs) {
      cout << "Passed test " << testName << " ***  Output was \""<< whatItIs << "\"" << endl;
      return true;
   }
   else {
      if (whatItShouldBe == "") {
         cout << "***Failed test " << testName << " *** " << endl << "   Output was \""<< whatItIs << "\"" << endl << "  Output should have been blank. " << endl;
      } else {
         cout << "***Failed test " << testName << " *** " << endl << "   Output was \""<< whatItIs << "\"" << endl << "  Output should have been \"" << whatItShouldBe << "\"" << endl;
      }
      return false;
   }
}

//This helps with testing, do not modify.
bool checkTest(string testName, int whatItShouldBe, int whatItIs) {

  
   if (whatItShouldBe == whatItIs) {
      cout << "Passed test " << testName << " ***  Output was \""<< whatItIs << "\"" << endl;
      return true;
   }
   else {
      cout << "***Failed test " << testName << " *** " << endl << "   Output was \""<< whatItIs << "\"" << endl << "  Output should have been \"" << whatItShouldBe << "\"" << endl;
      return false;
   }
}


int main() {

   //Test Default Constructor
   Infix myInfix;
   checkTest("Test #1", "", myInfix.getInfix());
   checkTest("Test #2", "", myInfix.getPostfix());
   checkTest("Test #3", 0, myInfix.getNumberOfOperands());
   checkTest("Test #4", 0, myInfix.getNumberOfOperators());

   //SetInfix
   string expression = "(2+3)";
   myInfix.setInfix(expression);
   checkTest("Test #5", "(2+3)", myInfix.getInfix());   
   checkTest("Test #6", 2, myInfix.getNumberOfOperands());
   checkTest("Test #7", 1, myInfix.getNumberOfOperators());
   checkTest("Test #8", "2 3 +", myInfix.getPostfix());

   //Clear
   myInfix.clear();
   checkTest("Test #9", "", myInfix.getInfix());
   checkTest("Test #10", "", myInfix.getPostfix());
   checkTest("Test #11", 0, myInfix.getNumberOfOperands());
   checkTest("Test #12", 0, myInfix.getNumberOfOperators());

   //Lots More Expression
   expression = "2+3";
   myInfix.setInfix(expression);
   checkTest("Test #13", "2 3 +", myInfix.getPostfix());
   checkTest("Test #14", 2, myInfix.getNumberOfOperands());
  

   expression = "(123+456)";
   myInfix.setInfix(expression);
   checkTest("Test #15", "123 456 +", myInfix.getPostfix());

   expression = "(8-5)";
   myInfix.setInfix(expression);
   checkTest("Test #16", "8 5 -", myInfix.getPostfix());

   expression = "((3-4)-5)";
   myInfix.setInfix(expression);
   checkTest("Test #17", "3 4 - 5 -", myInfix.getPostfix());
   checkTest("Test #18", 2, myInfix.getNumberOfOperators());

   expression = "(3 - (4 - 5))";
   myInfix.setInfix(expression);
   checkTest("Test #19", "3 4 5 - -", myInfix.getPostfix());

   expression = "(3*(8/2))";
   myInfix.setInfix(expression);
   checkTest("Test #20", "3 8 2 / *", myInfix.getPostfix());
   checkTest("Test #21", 3, myInfix.getNumberOfOperands());

   expression = "3 + 8 / 2";
   myInfix.setInfix(expression);
   checkTest("Test #22", "3 8 2 / +", myInfix.getPostfix());

   expression = "24 / 3 + 2";
   myInfix.setInfix(expression);
   checkTest("Test #23", "24 3 / 2 +", myInfix.getPostfix());

   expression = "((1 + 2) * (3 + 4))";
   myInfix.setInfix(expression);
   checkTest("Test #24", "1 2 + 3 4 + *", myInfix.getPostfix());

   expression = "2^3";
   myInfix.setInfix(expression);
   checkTest("Test #25", "2 3 ^", myInfix.getPostfix());

   expression = "8 + 3^4";
   myInfix.setInfix(expression);
   checkTest("Test #26", "8 3 4 ^ +", myInfix.getPostfix());

   expression = "5 ^ 6 - 9";
   myInfix.setInfix(expression);
   checkTest("Test #27", "5 6 ^ 9 -", myInfix.getPostfix());

   expression = "5 ^ (8 * 4)";
   myInfix.setInfix(expression);
   checkTest("Test #28", "5 8 4 * ^", myInfix.getPostfix());

   expression = "(4 + 3) * (7 ^56)";
   myInfix.setInfix(expression);
   checkTest("Test #29", "4 3 + 7 56 ^ *", myInfix.getPostfix());
   checkTest("Test #30", 3, myInfix.getNumberOfOperators());

   expression = "1999 ^ 9991";
   myInfix.setInfix(expression);
   checkTest("Test #31", "1999 9991 ^", myInfix.getPostfix());

   expression = "5 ^ 4 ^ 7 + 9";
   myInfix.setInfix(expression);
   checkTest("Test #32", "5 4 ^ 7 ^ 9 +", myInfix.getPostfix());

   expression = "55 ^ (667 ^ 32) * 89";
   myInfix.setInfix(expression);
   checkTest("Test #33", "55 667 32 ^ ^ 89 *", myInfix.getPostfix());
   checkTest("Test #34", 4, myInfix.getNumberOfOperands());

   expression = "(((3+12)-7)*120)/(2+3)";
   myInfix.setInfix(expression);
   checkTest("Test #35", "3 12 + 7 - 120 * 2 3 + /", myInfix.getPostfix());

   expression = "((((9+(2*(110-(20/2))))*8)+1000)/2)-((400*2500)-1000001)";
   myInfix.setInfix(expression);
   checkTest("Test #36", "9 2 110 20 2 / - * + 8 * 1000 + 2 / 400 2500 * 1000001 - -", myInfix.getPostfix());
   checkTest("Test #37", 10, myInfix.getNumberOfOperators());
   checkTest("Test #38", 11, myInfix.getNumberOfOperands());

   //Infix String Constructors
   myInfix = Infix("");
   checkTest("Test #39", "", myInfix.getInfix());
   checkTest("Test #40", "", myInfix.getPostfix());
   checkTest("Test #41", 0, myInfix.getNumberOfOperands());
   checkTest("Test #42", 0, myInfix.getNumberOfOperators());

   myInfix = Infix("2 + 3");
   checkTest("Test #43", "2 + 3", myInfix.getInfix());
   checkTest("Test #44", "2 3 +", myInfix.getPostfix());
   checkTest("Test #45", 1, myInfix.getNumberOfOperators());
   checkTest("Test #46", 2, myInfix.getNumberOfOperands());

   myInfix = Infix("(2 + 3)");
   checkTest("Test #47", "2 3 +", myInfix.getPostfix());

   myInfix = Infix("123 + 456");
   checkTest("Test #48", "123 456 +", myInfix.getPostfix());

   myInfix = Infix("8 - 5");
   checkTest("Test #49", "8 5 -", myInfix.getPostfix());

   myInfix = Infix("3 - 4 - 5");
   checkTest("Test #50", "3 4 - 5 -", myInfix.getPostfix());

   myInfix = Infix("3 - (4 - 5)");
   checkTest("Test #51", "3 4 5 - -", myInfix.getPostfix());
   checkTest("Test #52", "3 - (4 - 5)", myInfix.getInfix());
   checkTest("Test #53", 2, myInfix.getNumberOfOperators());
   checkTest("Test #54", 3, myInfix.getNumberOfOperands());

   return 0;
}

