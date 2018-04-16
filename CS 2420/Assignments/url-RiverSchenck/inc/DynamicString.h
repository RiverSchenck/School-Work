#ifndef DYNAMIC_STRING_H
#define DYNAMIC_STRING_H

/**
 * DynamicString class which stores strings
 * using dynamically re-sized char arrays.
 *
 * The char array should be null-terminated so
 * as to be compatible with c_string functions.
 *
 * Certain methods assume an 8-bit ascii char representation.
 *
 * You are not allowed to remove or rename any of the
 * data memebers of methods from this class.  However
 * you can add additional data members and methods as
 * you see fit.  You can also change the method
 * implementations as needed.
 *
 */
class DynamicString{

   public:
      /**
       * Calculate the length of the c-string
       * Assignment:Getting Started Github
       * @param str The c-string whose length will be determined
       * @return The number of characters in the c-string
       */
      static int myStringLen(const char* str);

      /**
       * c-string constructor. Creates a copy of
       * the provided c-string, allocating the
       * required amount of memory.
       * Assignment:Part1
       * @param str the c-string to store.
       */
      DynamicString(const char* str);


      /** Get the number of chars in the string
       * Assignment:Part1
       */
      int len() const;

      /** Get a pointer to the char buffer
       * Assignment:Part1
       */
      const char* c_str() const;

      /** Get a reference to the character at the specified position.
       * Assignment:Part1
       * @param position the 0-based index to retreive.
       * @return the character at the specified position.
       */
      char& char_at(int position);

      /** Get a copy of the character at the specified position.
       * Assignment:Part1
       * @param position the 0-based index to retreive.
       * @return the character at the specified position.
       */
      char char_at(int position) const;

      /** Get a reference to the character at the specified position.
       * Assignment:Part1
       * @param position the 0-based index to retreive.
       * @return the character at the specified position.
       */
      char& operator[](int position);

      /** Get a copy of the character at the specified position.
       * Assignment:Part1
       * @param position the 0-based index to retreive.
       * @return the character at the specified position.
       */
      char operator[](int position) const;

      /** Returns true if other is a prefix of this string.
       * Assignment:Part1
       * @param other the string to check as a prefix.
       * @return bool true if other is a prefix.
       */
      bool isPrefix(const DynamicString& other) const;

      /** Returns true if other is a prefix of this string
       * ignoring character case.
       * Assignment:Part1
       * @param other the string to check as a prefix.
       * @return bool true if other is a prefix.
       */
      bool isIPrefix(const DynamicString& other) const;

      /** Returns true if other is a suffix of this string.
       * Assignment:Part1
       * @param other the string to check as a suffix.
       * @return bool true if other is a suffix.
       */
      bool isSuffix(const DynamicString& other) const;

      /** Returns true if other is a suffix of this string
       * ignoring character case.
       * Assignment:Part1
       * @param other the string to check as a suffix.
       * @return bool true if other is a suffix.
       */
      bool isISuffix(const DynamicString& other) const;

       /** Compares this string to other.
        * Assignment:Part1
        * @param other the string to compare.
        * @return -1 if this string is smaller, 0 if they are the same, and 1 if this string is larger.
        */
      int compare(const DynamicString& other) const;

       /** Compares this string to other ignoring case.
        * Assignment:Part1
        * @param other the string to compare.
        * @return -1 if this string is smaller, 0 if they are the same, and 1 if this string is larger.
        */
      int iCompare(const DynamicString& other) const;


      /** Converts all characters to lowercase.
       * Contents are modified "in-place"
       * Assignment:Part1
       * @return self (the lowercased string)
       */
      DynamicString& toLower();

      /** Converts all characters to uppercase.
       * Contents are modified "in-place"
       * Assignment:Part1
       * @return self (the uppercased string)
       */
      DynamicString& toUpper();

      /**
       * Default constructor. Initializes an empty string.
       * Assignment:Part2
       */
      DynamicString();

      /**
       * Copy-constructor.  Performs a deep-copy.
       * Assignment:Part2
       * @param other the DynamicString to copy
       */
      DynamicString(const DynamicString& other);

      /**
       * Destructor. Releases memory resources"
       * Assignment:Part2
       */
      ~DynamicString();

      /**
       * Assignment operator. Performs a deep-copy.
       * Assignment:Part2
       * @param other the DynamicString to copy
       * @return self which now contains a deep-copy of other
       */
      DynamicString& operator=(const DynamicString& other);

      /** Removes leading and trailing whitespace.
       * The original DynamicString is not modified.
       * @return a DynamicString with all leading and
       * trailing whitespace characters removed.
       */
      DynamicString& trim();

      /** Returns a concatenation of this string and other.
       * The original strings are not modified.
       * @param other the string to append.
       * @returns the concatenated DynamicString
       * @throws out_of_range error if the string does not fit in the buffer.
       */
      DynamicString operator+(const DynamicString& other) const;

      /** Returns a concatenation of this string and other.
       * The original strings are not modified.
       * @param other the string to append.
       * @returns the concatenated DynamicString
       * @throws out_of_range error if the string does not fit in the buffer.
       */
      DynamicString concat(const DynamicString& other) const;

      /** Finds the first index of the character in the string
       * Assignment:Part2
       * @param start the position of the string to start at
       * @param c the char to look for
       * @return the index of the character or -1 if the character is not found.
       */
      int find(int start, char c) const;
	  void copyStr(char* buf, char* old, int size) const;
      /** Finds the last index of the character in the string
       * Assignment:Part2
       * @param start the position of the string to end at
       * @param c the char to look for
       * @return the index of the character or -1 if the character is not found.
       * Assignment:Part1
       */
      int reverseFind(int start, char c) const;

      /** Copy a sub-string into the buffer
       * Assignment:part2
       * @param buf the char buffer to copy the substring into
       * @param start the index to start copying from (inclusive)
       * @param end the index to stop copying at (exclusive)
       */
      void subStr(char* buf, int start, int end) const;

   private:
      char* cstr;
};

#endif
