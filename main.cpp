#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <functional>
#include <fstream>


class Array;

class Vector; // GenerateRandVec(),

class Pointer;

class HelpfullFunction; // Range(), StringToVector(), VectorToString(), TrimWhitspaces(), FindSubstringMatches(), ReplaceSubstringMatches()
class LambdaExpression; // for_each(), copy_if() #filterfunction, transform, Recursive Lambda Function, sort()
class TryAndCatch;

class RandomNumber; //While, Break, Do-While
class String; // Ascii Code, str.append(), str.erase(), str.substring(), str.find(), reverse(), transform toUpper tolower
class Math; // max(), min(), ceil(), floor(), exp2(), exp(), log2(), log10(), ...

// OOP Concepts
class Animal; // Setter, Getter, private, public, protected, static, constructor, deconstructor, virtual Methode, FriendClass
class GetPrivateInformationAnimal; // Fried class from Animal => has access to private Fields from Animal
class SubAnimal; //Override, inheritance
struct Shape; // Structs are used to model new data types, while // classes model more complex real world objects
class Circle;



int main() {


    return 0;
}

class Array {
    int main() {
        // Array
        // An array is a collection of data of the same type
        // Declare an array of ints with the value of 1
        // Once the size is defined it can't change
        int arrnNums[10] = {1};

        // Leave out the array length
        int arrnNums2[] = {1, 2, 3};

        // Create an array and assign some values
        int arrnNums3[5] = {8, 9};

        // Access array values using indexes starting with 0
        std::cout << "1st Value : " << arrnNums3[0] << "\n";

        // Change a value
        arrnNums3[0] = 7;
        std::cout << "1st Value : " << arrnNums3[0] << "\n";

        // Get array size by getting the number of bytes
        // set aside for the array and then divide by the size
        // of the 1st element
        std::cout << "Array size : " <<
                  sizeof(arrnNums3) / sizeof(*arrnNums3) << "\n";

        // A multidimensional array is like a spreadsheet
        // If you think of each as layers that contain columns
        // 1st Number : Which layer
        // 2nd Number : Which column
        // 3rd Number : Which row
        int arrnNums4[2][2][2] = {{{1, 2}, {3, 4}},
                                  {{5, 6}, {7, 8}}};
        std::cout << arrnNums4[1][1][1] << "\n";
    }


};

class Vector {
public:
    int main() {
        // Use vectors when you don't know how big your
        // arrays may be

        // Create a vector with 2 spaces to start
        std::vector<int> vecnRandNums(2);

        // Add values
        vecnRandNums[0] = 10;
        vecnRandNums[1] = 20;

        // Add another value to the vector
        vecnRandNums.push_back(30);

        // Get size of vector
        std::cout << "Vector Size : " << vecnRandNums.size() << "\n";

        // Get last value
        std::cout << "Last Index : " <<
                  vecnRandNums[vecnRandNums.size() - 1] << "\n";
    }

    std::vector<int> GenerateRandVec(int numOfNums,
                                     int min, int max) {
        std::vector<int> vecValues;
        srand(time(NULL));
        int i = 0, randVal = 0;
        while (i < numOfNums) {
            randVal = min + std::rand() % ((max + 1) - min);
            vecValues.push_back(randVal);
            i++;
        }
        return vecValues;
    }
};

class Pointer {
    // Change Value of from formal Parameter
    // void AssignAge(int age); // Does not Change the because its Call by Value and void ;
    // int AssignAge2(int age); // Does Change because call by Value and return new Value
    // void AssignAge3(int *pAge); // Call by Reference (function receives pointers)

    // Double values in array passed
    // void DoubleArray(int *arr, int size);
public:
    // ----- FUNCTION PROTOTYPES -----
    double AddNumbers(double num1, double num2);



    // ----- END OF FUNCTION PROTOTYPES -----

    int main() {

        int age = 43;
        AssignAge(age);
        std::cout << "New Age " << age << "\n";

        // You could change the value by passing it back
        age = AssignAge2(age);
        std::cout << "New Age " << age << "\n";

        // A Pointer stores a address in memory
        // You declare a pointer to be of the same type as the data
        // type to which it points
        // If you are storing the address of an int then the
        // pointer is an int
        // When you declare a pointer give it a null value
        int *pAge = NULL;

        // The reference operator returns the address for a
        // variable that can be stored in a pointer
        pAge = &age;

        // Print the address Hexidecimal Number
        std::cout << "Address : " << pAge << "\n";

        // Get the value at that address with the dereference operator
        std::cout << "Value at Address : " << *pAge << "\n";

        // We can create a pointer to an array and cycle through
        // the data with ++ and --
        int intArray[] = {1, 2, 3, 4};
        int *pIntArray = intArray;

        std::cout << "1st " << *pIntArray << " Address " << pIntArray << "\n";
        pIntArray++;
        std::cout << "2nd " << *pIntArray << " Address " << pIntArray << "\n";
        pIntArray--;
        std::cout << "1st"
                     " " << *pIntArray << " Address " << pIntArray << "\n";

        // You can pass a pointer to a function and then the function
        // can change that variables value globally
        age = 43;

        // Send the address for age to the function
        AssignAge3(&age);

        std::cout << "Pointer Age " << age << "\n";

        // Create an array and double values
        int arr[] = {1, 2, 3, 4};
        DoubleArray(arr, 4);
        for (int i = 0; i < 4; ++i) {
            std::cout << "Array " << arr[i] << "\n";
        }

        return 0;
    }

    void AssignAge(int age) {
        age = 24;
    }

    int AssignAge2(int age) {
        age = 24;
        return age;
    }

// Function that receives a pointer
    void AssignAge3(int *pAge) {

        // Use dereference operator to change the value at the address
        *pAge = 22;

    }

// Double values in array
    void DoubleArray(int *arr, int size) {
        for (int i = 0; i < size; ++i) {
            arr[i] = arr[i] * 2;
        }
    }
};

class HelpfullFunction {
public:

// ----- 0. Return VECTOR in Range(start, max, step) -----
    std::vector<int> Range(int start, int max,
                           int step) {

        // Every while statement needs an index
        // to start with
        int i = start;

        // Will hold returning vector
        std::vector<int> range;

        // Make sure we don't go past max value
        while (i <= max) {

            // Add value to the vector
            range.push_back(i);

            // Increment the required amount
            i += step;
        }
        return range;
    }
// ----- END CONVERT STRING TO VECTOR -----


// ----- 1. CONVERT STRING TO VECTOR -----
    std::vector<std::string> StringToVector(std::string,
                                            char separator) {
        std::string sSentence = "This is a random string";

        // Create a vector
        std::vector<std::string> vecsWords;

        // A stringstream object receives strings separated
        // by a space and then spits them out 1 by 1
        std::stringstream ss(sSentence);

        // Will temporarily hold each word in the string
        std::string sIndivStr;

        // While there are more words to extract keep
        // executing
        // getline takes strings from a stream of words stored
        // in the stream and each time it finds a blanks space
        // it stores the word proceeding the space in sIndivStr
        while (getline(ss, sIndivStr, separator)) {

            // Put the string into a vector
            vecsWords.push_back(sIndivStr);
        }

        return vecsWords;
    }
// ----- END CONVERT STRING TO VECTOR -----


// ----- 2. PROBLEM CONVERT VECTOR TO STRING -----
    std::string VectorToString(std::vector<std::string> &vec,
                               char separator) {

        std::string theString = "";
        for (auto cust: vec)
            theString += cust + separator;

        return theString;

    }
// ----- END PROBLEM CONVERT VECTOR TO STRING -----

// ----- 3. STRIP WHITESPACE -----
    std::string TrimWhitespace(std::string theString) {
        // find_last_not_of finds the last character
        // that doesn't match a list of defined characters
        std::string whitespaces(" \t\f\n\r");
        theString.erase(theString.find_last_not_of(whitespaces) + 1);

        // find_first_not_of does the same for the front of the string
        theString.erase(0, theString.find_first_not_of(whitespaces));

        return theString;
    }
// ----- END STRIP WHITESPACE -----

// ----- 4. PROBLEM FIND ALL INDEX MATCHES RETURN VECTOR -----
    std::vector<int> FindSubstringMatches(std::string theString,
                                          std::string substring) {
        std::vector<int> matchingIndexes;

        // Check for matching substring
        int index = theString.find(substring, 0);

        // Keep adding indexes until none are left
        while (index != std::string::npos) {
            matchingIndexes.push_back(index);
            index = theString.find(substring, index + 1);
        }

        return matchingIndexes;
    }

// ----- END PROBLEM FIND ALL INDEX MATCHES RETURN VECTOR -----

// ----- 5. PROBLEM REPLACE ALL SUBSTRINGS -----
    std::string ReplaceAllSubstrings(std::string theString,
                                     std::string substring, std::string newString) {

        // Get a vector that contains all matching indexes
        std::vector<int> matches = FindSubstringMatches(theString,
                                                        substring);

        if (matches.size() != 0) {
            // Get size difference between substring and newString
            int lengthDifference = newString.size() - substring.size();

            // Times through loop
            int timesLooped = 0;

            for (auto index: matches) {
                theString.replace(index + (timesLooped * lengthDifference),
                                  substring.size(),
                                  newString);
                timesLooped++;
            }
        }

        return theString;

    }
// ----- END PROBLEM REPLACE ALL SUBSTRINGS -----
};

class TryanCatch {
public:
    int main() {

// ----- EXCEPTION HANDLING EX 1 -----
        // Exceptions are errors that occur when things don't
        // go as expected.
        // 1. You expect and int and get a string
        // 2. You expect a file to be available and it isn't
        // 3. You expect the user to not enter 0 and they do

        // You try to execute code that could be troublesome
        // and if an error occurs you catch it and throw
        // it to another block of code for handling

        double num1 = 0, num2 = 0;

        std::cout << "Enter number 1 : ";
        std::cin >> num1;
        std::cout << "Enter number 2 : ";
        std::cin >> num2;

        try {
            if (num2 == 0) {
                throw "Division by zero is not possible";
            } else {

                printf("%.1f / %.1f = %.2f", num1, num2,
                       (num1 / num2));
            }
        }

        catch (const char *exp) {
            std::cout << "Error : " << exp << "\n";
        }

        // ----- END OF EXCEPTION HANDLING EX 1 -----

// ----- EXCEPTION HANDLING EX 2 -----
        try {
            std::cout << "Throwing exception\n";

            // Another way to throw an exception
            throw std::runtime_error("Error Occurred");

            // This point is never reached
            std::cout << "Can you print me?\n";
        }

            // All exceptions are based on std::exception
        catch (std::exception &exp) {

            // what() Prints an explanatory string
            std::cout << "Handled Exception : " <<
                      exp.what() << "\n";
        }

            // If exceptions aren't caught any place else
            // this will catch it
        catch (...) {
            std::cout << "Default exception catch\n";
        }


    }
};

class RandomNumber {
public:
    int main() {

// ----- DO WHILE LOOPS -----
        // Needed for the time function
        // #include <ctime>

        // Do while loops are guaranteed to execute at least once
        // We'll create a secret number guessing game

        // Generate random number from 0 - 10

        // We need to seed the random number generator
        // time() returns the number of seconds since 1, 1, 1970
        srand(time(NULL));

        // If you divide any number it is impossible to get a
        // remainder >= 11
        int secretNum = std::rand() % 11;
        int guess = 0;

        do {

            std::cout << "Guess the number : ";
            std::cin >> guess;

            if (guess > secretNum) std::cout << "To Big\n";
            if (guess < secretNum) std::cout << "To Small\n";

        } while (secretNum != guess);

        std::cout << "You guessed it\n";


        // ----- END OF DO WHILE LOOPS -----

// ----- PROBLEM CREATE A DO WHILE LOOP WITH WHILE -----
        secretNum = std::rand() % 11;
        while (true) {
            std::cout << "Guess the number : ";
            std::cin >> guess;

            if (guess > secretNum) std::cout << "To Big\n";
            if (guess < secretNum) std::cout << "To Small\n";

            if (guess == secretNum) break;
        }

        std::cout << "You guessed it\n";
    }
};

class String {
public:
    int main() {

        // A C character string is an array of characters
        // with a null character at the end \0
        char cString[] = {'A', ' ', 'S', 't', 'r', 'i', 'n', 'g', '\0'};
        std::cout << cString << "\n";

        // Get array size (null is included)
        std::cout << "Array Size " << sizeof(cString) << "\n";

        // C strings are troublesome because if you forget \0, or
        // add to much information it can lead your program to crash,
        // or for your system to crash

        // You can create a vector of strings
        std::vector<std::string> strVec(10);

        // C++ std::string can grow in size and is much safer
        std::string str("I'm a string");
        strVec[0] = str;

        // You can access characters with an index
        std::cout << str[0] << "\n";

        // You can also use at()
        std::cout << str.at(0) << "\n";

        // Front returns first char and back returns last
        std::cout << str.front() << " " << str.back() << "\n";

        // Get the string length
        std::cout << "Length : " << str.length() << "\n";

        // You can copy a string to another
        std::string str2(str);
        strVec[1] = str2;

        // You can copy after the 1st 4 characters
        std::string str3(str, 4);
        strVec[2] = str3;

        // Repeat a value to make a string
        std::string str4(5, 'x');
        strVec[3] = str4;

        // Combine strings with append or +
        strVec[4] = str.append(" and your not");
        str += " and your not";

        // Append part of a string
        str.append(str, 34, 37);
        strVec[5] = str;

        // Erase characters from a string from an index to another
        // or the last
        str.erase(13, str.length() - 1);
        strVec[6] = str;

        for (auto y: strVec)
            std::cout << y << "\n";

        // find() returns index where pattern is found
        // or npos
        if (str.find("string") != std::string::npos)
            std::cout << "1st not " << str.find("string") << "\n";

        // substr(x, y) returns a substring starting at
        // index x with a length of y
        std::cout << "Substr " << str.substr(6, 6) << "\n";

        // Reverse a string by passing the beginning and end
        // of a string
        reverse(str.begin(), str.end());
        std::cout << "Reverse " << str << "\n";

        // Case conversion
        transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
        std::cout << "Upper " << str2 << "\n";
        transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
        std::cout << "Lower " << str2 << "\n";

        // You can get the ascii code for a char by saving
        // the char as an int or with (int)
        // a - z : 97 - 122
        // A - Z : 65 - 90
        char aChar = 'Z';
        int aInt = aChar;
        std::cout << "A Code " << (int) 'a' << "\n";

        // Convert int to string
        std::string strNum = std::to_string(1 + 2);
        std::cout << "String " << strNum << "\n";

        // ----- PROBLEM : SECRET STRING -----
        // Receive an uppercase string and hide its meaning
        // by turning it into ascii codes
        // Translate it back to the original letters

        std::string normalStr, secretStr = "";
        std::cout << "Enter your string in uppercase : ";
        std::cin >> normalStr;

        // Cycle through each character converting
        // them into ascii codes which are stored in
        // a string
        for (char c: normalStr)
            secretStr += std::to_string((int) c);
        // secretStr += std::to_string((int)c - 23);

        std::cout << "Secret : " << secretStr << "\n";

        normalStr = "";

        // Cycle through numbers in string 2 at a time
        for (int i = 0; i < secretStr.length(); i += 2) {

            // Get the 2 digit ascii code
            std::string sCharCode = "";
            sCharCode += secretStr[i];
            sCharCode += secretStr[i + 1];

            // Convert the string into int
            int nCharCode = std::stoi(sCharCode);

            // Convert the int into a char
            char chCharCode = nCharCode;
            // char chCharCode = nCharCode + 23;

            // Store the char in normalStr
            normalStr += chCharCode;
        }

        std::cout << "Original : " << normalStr << "\n";

        // ----- END OF PROBLEM : SECRET STRING -----

        // ----- BONUS PROBLEM -----
        // Allow the user to enter upper and lowercase
        // letters by subtracting and adding 1 value
        // ----- END OF BONUS PROBLEM -----

        return 0;

    }
};

class Math {
    int main() {
        // ----- MATH FUNCTIONS -----
        // C++ has numerous math functions
        // http://en.cppreference.com/w/cpp/numeric/math

        // Needed for math functions
        // #include <cmath>


        std::cout << "abs(-10) = " << std::abs(-10) << "\n";

        std::cout << "max(5,4) = " << std::max(5, 4) << "\n";

        std::cout << "min(5,4) = " << std::min(5, 4) << "\n";

        std::cout << "fmax(5.3,4.3) = " << std::fmax(5.3, 4.3) << "\n";

        std::cout << "fmin(5.3,4.3) = " << std::fmin(5.3, 4.3) << "\n";

        // e ^ x
        std::cout << "exp(1) = " << std::exp(1) << "\n";

        // 2 ^ x
        std::cout << "exp2(1) = " << std::exp2(1) << "\n";

        // e * e * e ~= 20 so log(20.079) ~= 3
        std::cout << "log(20.079) = " << std::log(20.079) << "\n";

        // 10 * 10 * 10 = 1000, so log10(1000) = 3
        std::cout << "log10(1000) = " << std::log10(1000)
                  << "\n";

        // 2 * 2 * 2 = 8
        std::cout << "log2(8) = " << std::log2(8)
                  << "\n";

        // 2 ^ 3
        std::cout << "pow(2,3) = " << std::pow(2, 3)
                  << "\n";

        // Returns what times itself equals the provided value
        std::cout << "sqrt(100) = " << std::sqrt(100)
                  << "\n";

        // What cubed equals the provided
        std::cout << "cbrt(1000) = " << std::cbrt(1000)
                  << "\n";

        // Hypotenuse : SQRT(A^2 + B^2)
        std::cout << "hypot(2,3) = " << std::hypot(2, 3)
                  << "\n";

        std::cout << "ceil(10.45) = " << std::ceil(10.45)
                  << "\n";

        std::cout << "floor(10.45) = " << std::floor(10.45)
                  << "\n";

        std::cout << "round(10.45) = " << std::round(10.45)
                  << "\n";

        // Also sin, cos, tan, asin, acos, atan, atan2,
        // sinh, cosh, tanh, asinh, acosh, atanh

        return 0;


    }
};

class LambdaExpression {
    int main() {
        // ----- LAMBDA EXPRESSIONS -----

        Vector vector;
        std::vector<int> vecVals = vector.GenerateRandVec(10, 1, 50);

        // Lambda Expressions make it easy to perform list
        // operations in one line of code. You designate
        // them with []
        // Here we sort a vector
        std::sort(vecVals.begin(), vecVals.end(),
                  [](int x, int y) { return x < y; });

        for (auto val: vecVals)
            std::cout << val << "\n";

        std::cout << "\n";

        // copy_if works like filter does in other languages
        // Here we keep only even values in a new vector
        std::vector<int> evenVecVals;

        std::copy_if(vecVals.begin(), vecVals.end(),
                     std::back_inserter(evenVecVals),
                     [](int x) { return (x % 2) == 0; });

        for (auto val: evenVecVals)
            std::cout << val << "\n";

        // ----- SUM A LIST -----
        int sum = 0;

        // for_each cycles through all values
        // [&] captures all variables used
        // in the body of the lambda by reference
        std::for_each(vecVals.begin(), vecVals.end(),
                      [&](int x) { sum += x; });

        std::cout << "SUM : " << sum << "\n";

        // ----- END SUM A LIST -----

        // ----- PROBLEM DYNAMIC LIST DIVISABLE BY A VALUE -----

        // You can define what value is checked for divisability
        // by passing the value to check in the capture list
        // which lies between []
        // Send a value entered by the user through the capture
        // list and create a list based on it
        int divisor;
        std::vector<int> vecVals2;
        std::cout << "List of values divisable by : ";
        std::cin >> divisor;
        std::copy_if(vecVals.begin(), vecVals.end(),
                     std::back_inserter(vecVals2),
                     [divisor](int x) { return (x % divisor) == 0; });
        for (auto val: vecVals2)
            std::cout << val << "\n";

        // ----- END PROBLEM DYNAMIC LIST DIVISABLE BY A VALUE -----

        // ----- MULTIPLY ALL VALUES BY 2 -----
        std::vector<int> doubleVec;

        // For_each cycles through all values in the vector
        // and doubles them.
        std::for_each(vecVals.begin(), vecVals.end(),
                      [&](int x) { doubleVec.push_back(x * 2); });

        for (auto val: doubleVec)
            std::cout << "DBL : " << val << "\n";

        // ----- END MULTIPLY ALL VALUES BY 2 -----

        // ----- PERFORMING OPERATIONS USING MULTIPLE VECTORS -----
        // Add values in separate vectors and save them to another
        std::vector<int> vec1 = {1, 2, 3, 4, 5};
        std::vector<int> vec2 = {1, 2, 3, 4, 5};
        std::vector<int> vec3(5);
        transform(vec1.begin(), vec2.end(),
                  vec2.begin(), vec3.begin(),
                  [](int x, int y) { return x + y; });

        for (auto val: vec3)
            std::cout << "vec3 " << val << "\n";

        // ----- END PERFORMING OPERATIONS USING MULTIPLE VECTORS -----

        // ----- TERNARY OPERATOR -----

        // A ternary operator works like a compact if else
        // statement. If the condition is true the first
        // value is stored and otherwise the second
        int age = 43;
        bool canIVote = (age >= 18) ? true : false;
        // Shows bool values as true or false
        std::cout.setf(std::ios::boolalpha);
        std::cout << "Can Derek Vote : " << canIVote << "\n";

        // ----- END TERNARY OPERATOR -----

        // ----- RECURSIVE LAMBDA FUNCTIONS -----

        // Recursive Lambda to calculate Fibonacci Numbers
        std::function<int(int)> Fib =
                [&Fib](int n) { return n < 2 ? n : Fib(n - 1) + Fib(n - 2); };

        // Fib(0) = 0
        // Fib(1) = 1
        // Fib(2) = 1
        // Fib(3) = 2
        // Fib(4) = 3
        std::cout << "Fib 4 : " << Fib(4) << "\n";

        // ----- END RECURSIVE LAMBDA FUNCTIONS -----


        return 0;


    }
};

class Animal {
    // Private variables are only available to methods
    // in the class
private:
    std::string name;
    double height;
    double weight;

    // Static variables share the same value for all
    // objects of the Animal class
    static int numOfAnimals;

    // A Friend Class has access to private Information from this class
    friend class GetPrivateInformationAnimal;

    // Public fields and methods can be accessed by
    // anything with access to the object
public:

    // Getter Methoden
    std::string GetName(){return name;}
    double GetHeight(){return height;}
    double GetWeight(){return weight;}

    // Setter Methode
    void SetName(std::string name){this->name = name;}
    void SetHeight(double height){this->height = height;}
    void SetWeight(double weight){this->weight = weight;}

    // You can declare function prototypes
    void SetAll(std::string, double, double);

    // A constructor is called each time an object is created
    Animal(std::string, double, double);

    // Create an overloaded constructor for when no data is passed
    Animal();

    // A deconstructor is called automatically when an object
    // is deleted or is no longer used
    // The default is fine, but you should create custom ones
    // when you must release memory, or resources
    ~Animal();

    // Static methods can only access static fields
    static int GetNumOfAnimals(){return numOfAnimals;}

    // Created to be overwritten
    virtual void ToString();

};

class GetPrivateInformationAnimal{
// Just a Demo fried Class from Animal
public:
    std::string name;
};

class SubAnimal: public Animal{
public:
    std::string sound = "Wooof";

    // Override To String
    void ToString() override{
        std::cout << "I am a Dog" << "\n";
    }
};

// Classes have default private fields and methods
// while structs have public
// Structs are used to model new data types, while
// classes model more complex real world objects
struct Shape{
    // Variables are public by default
    double length, width;

    // Constructors are public by default
    Shape(double l = 1, double w = 1){
        length = l;
        width = w;
    }

    // Structs can contain functions
    double Area(){
        return length * width;
    }

    // Structs can contain private members
private:
    int id;
};

// You can inherit from a struct
struct Circle : Shape{
    // Override the constructor
    // You also use this with structs
    Circle(double width){
        this->width = width;
    }

    // Override Area()
    double Area(){
        return 3.14159 * std::pow((width / 2), 2);
    }
};