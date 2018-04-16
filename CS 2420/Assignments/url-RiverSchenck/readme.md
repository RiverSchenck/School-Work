# URL Class

Uniform Resource Locators (URLs) are commonly used in the world wide web as addresses for HTML web pages.
URLs can be divided into distinct segments including the scheme, user, password, host, port, path, query and fragment.
You will create a class for storing and manipulating URLs by subclassing your DynamicString class.  As before, you are **not allowed** to use the string header file, cstring header file or C++ strings.

## Goals:
The purpose of this project is to continue working with C++ classes and inheritance, design and implement algorithms for parsing strings and begin working on the pieces necessary to implelement a basic web crawler.

## Requirements:
The URL class will store absolute URLs. In addition to the inherited methods from the DynamicString class, the class will need to implement the following methods:

- Constructor that takes a URL as a const DynamicString& and stores the URL. Throws an invalid_argument exception if the string is not a valid URL.
- Constructor that takes a URL as a const char* and stores the URL. Throws an invalid_argument exception if the string is not a valid URL.
- getScheme - returns the scheme of the URL as a DynamicString
- getAuthority - returns the host (including user, password and port if applicable) of the URL as a DynamicString
- getPath - returns the path of the URL as a DynamicString
- getQuery - returns the query of the URL as a DynamicString
- getFragment - returns the fragment of the URL as a DynamicString
- compare - compares this URL with another URL and returns a value<0 if the other URL is lexicographically earlier or smaller than this URL, 0 if the URLs are identical and a value<1 if the other URL is lexicographically later or larger than this URL.  The compare should take into consideration which parts of the URL are case-sensitive and which parts of the URL are case-insensitive. Each piece is considered separately. For example, if the scheme is equal continue to the authority and so on.
- compareIgnoreFrag - compares this URL with another URL and returns a value<0 if the other URL is lexicographically earlier or smaller than this URL, 0 if the URLs are identical and a value<1 if the other URL is lexicographically later or larger than this URL.  The compare should take into consideration which parts of the URL are case-sensitive and which parts of the URL are case-insensitive. Each piece is considered separately. For example, if the scheme is equal continue to the authority and so on. Also, the fragment should be ignored.
- resolveRelativeURL - takes a relative URL as a const DynamicString&, resolves it relative to this base url and returns the resulting absolute URL.
- isHTML - returns true if the path points to an html document based on the following assumptions.  A path is an html document if it ends in one of the following extensions (.html .htm .shtml .cgi .jsp .asp .aspx .php .pl .cfm .py) or if the path does not have an extension.
- friend operator<< which outputs the URL to an output stream.

Starter code is provided and you will need to modify the files appropriately.
Your code should pass all of the test cases in the URLTest.cpp driver file.
Any modifications to the URLTest.cpp driver file will be discarded.


## Tips and suggestions:
- You might want to store each of the pieces (path, query, etc) as a private data member.
- Look at the driver files. Just because you will not be making changes to that code, you should still understand what it is doing. The tests are examples of expected results for each of the different methods. If you want to know what isHTML is supposed to do, look at the input and expected output.
- Make sure to comment each method.
- Work on one thing at a time and compile and commit early and often.  For example, implement the getScheme method, compile it, test it, commit it.  The more often you compile and test the easier it will be to pinpoint errors.
- Use the debugger.  When you are getting unexpected results, set a breakpoint and trace exactly what is happening in the code.
