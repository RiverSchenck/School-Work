#ifndef URL
#define URL
/**This is the Url class. Its job is to manage url links
 * methods are provided to validate parse and resolve urls.
 * @param <Start URL>
 */

#include "DynamicString.h"
#include <iostream>

class Url: public DynamicString{

 public:

    Url(const DynamicString& other);
    Url(const char* url_);

    DynamicString getUrl() const;

    DynamicString getScheme() const;

    DynamicString getAuthority() const;

    DynamicString getPath() const;

    DynamicString getQuery() const;

    DynamicString getFragment() const;

    int compare(const Url & other) const;

	DynamicString backone() const; // goes back one in path

	DynamicString backtwo() const; // goes back twice in path

	DynamicString wayback() const; // goes back 6 times in path

    int compareIgnoreFrag(const Url & other) const;

    Url resolveRelativeURL(const DynamicString& relativeUrl_)const;

    bool isHTML() const;

    friend std::ostream& operator<<(std::ostream& out, const Url& url);
	//DynamicString url, scheme, authority, path, query, fragment;
	//void parse_url();

};
#endif
