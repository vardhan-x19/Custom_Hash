#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    // 1. Basic String Operations
    // Creating and Initializing Strings
    string s1 = "Hello";        // Direct initialization
    string s2("World");         // Constructor initialization
    string s3(s1);              // Copy initialization
    string s4(5, 'A');          // "AAAAA" (repeats character 5 times)

    // Taking Input (cin vs getline)
    string s;
    cin >> s;        // Takes single word input (stops at space)
    getline(cin, s); // Takes full line input (including spaces)

    // 2. String Modification Operations
    // Concatenation (+ or append())
    string s1 = "Hello";
    string s2 = " World";
    string s3 = s1 + s2; // "Hello World"
    s1.append(s2);       // "Hello World"

    // Insert a String
    string str = "HelloWorld";
    str.insert(5, " ");  // Inserts a space, str becomes "Hello World"

    // Erase Part of a String
    string str = "Hello World";
    str.erase(5, 1); // Removes one character at index 5, str becomes "HelloWorld"

    // Replace Part of a String
    string str = "Hello World";
    str.replace(6, 5, "C++"); // "Hello C++"

    // 3. Searching in Strings
    // Find a Substring
    string str = "Hello World";
    size_t pos = str.find("World"); // Returns index 6
    if (pos != string::npos)
        cout << "Found at index " << pos << endl;

    // Find Last Occurrence
    size_t lastPos = str.rfind("o"); // Finds last 'o' in "Hello World"

    // Check if a Substring Exists
    if (str.find("XYZ") != string::npos)
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    // 4. Extracting Parts of a String
    // Substring Extraction (substr())
    string str = "C++ Programming";
    string sub = str.substr(4, 11); // "Programming"

    // Splitting a String using stringstream
    string str = "C++ is fun";
    stringstream ss(str);
    string word;
    while (ss >> word)
        cout << word << endl; // Outputs: "C++" "is" "fun"

    // 5. Comparing Strings
    // Lexicographical Comparison (<, >, ==)
    string s1 = "apple", s2 = "banana";
    if (s1 < s2) // True (because "apple" comes before "banana")
        cout << "apple is smaller";

    // Using compare()
    string s1 = "apple", s2 = "banana";
    int result = s1.compare(s2); // Returns <0, 0, or >0

    // 6. Changing Case
    // Convert to Uppercase & Lowercase
    string str = "Hello";
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str; // Output: HELLO

    // 7. Reversing and Sorting a String
    // Reverse a String
    string str = "Hello";
    reverse(str.begin(), str.end()); // "olleH"

    // Sort a String
    string str = "dcba";
    sort(str.begin(), str.end()); // "abcd"

    // 8. Counting Characters
    // Count Specific Character
    string str = "banana";
    int countA = count(str.begin(), str.end(), 'a'); // Returns 3

    // 9. Numeric String Operations
    // Convert String to Integer & Vice Versa
    string numStr = "123";
    int num = stoi(numStr); // Converts "123" to integer 123

    int val = 456;
    string str = to_string(val); // Converts 456 to "456"

    // Convert String to Float
    float f = stof("3.14"); // 3.14

    // 10. Checking if a String is a Palindrome
    bool isPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }

    cout << isPalindrome("madam"); // Output: 1 (true)

    return 0;
}
