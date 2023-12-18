#include <iostream>
#include "CSuperString.h"

// Function prototypes (if any)

int main() {
    CSuperString ssBuffer("I Love Star Trek");

    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "CSuperString Tests" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << std::endl; 

    std::cout << "Double Call Bug" << std::endl;
    printf("Left( 2 ): %s, Left( 4 ): %s\n", ssBuffer.Left(2).ToString(), ssBuffer.Left(4).ToString());
    
    std::cout << "\n\n\n";

    //void MuahahahTest1()
    //{
    {
        CSuperString ssTest;
        cout << "Muahahah Test #1: " << ssTest << endl;
    }

    {
        CSuperString ssTest = "I Love Star Wars and I Love Star Trek";

        ssTest = ssTest.Replace("Love", "Really Love Love");

        cout << "Muahahah Test #2: " << ssTest << endl;

    }

    std::cout << "\n\n\n";


#pragma region "Constructors" 
    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** Constructors ******************************" << std::endl;
    std::cout << "****************************************************************" << std::endl;


    {
        CSuperString ssBuffer;

        // #1a - Constructor: const char *
        CSuperString ssSource1("I Love Star Trek");
        ssSource1.Print("#1a - Constructor: const char *");

        // #1b - Constructor: const bool
        CSuperString ssSource2(true);
        ssSource2.Print("#1b - Constructor: const bool");

        // #1c - Constructor: const char
        CSuperString ssSource3('X');
        ssSource3.Print("#1c - Constructor: const char");

        // #1d - Constructor: const short
        CSuperString ssSource4((short)(42));
        ssSource4.Print("#1d - Constructor: const short");

        // #1e - Constructor: const int
        CSuperString ssSource5(123);
        ssSource5.Print("#1e - Constructor: const int");

        // #1f - Constructor: const long
        CSuperString ssSource6(456L);
        ssSource6.Print("#1f - Constructor: const long");

        // #1g - Constructor: const float
        CSuperString ssSource7(3.14159f);
        ssSource7.Print("#1g - Constructor: const float");

        // #1h - Constructor: const double
        CSuperString ssSource8(2.718);
        ssSource8.Print("#1h - Constructor: const double");

        // #1i - Constructor: CSuperString &
        CSuperString ssSource9 = "I Love Star Wars";
        CSuperString ssSource10(ssSource9);
        ssSource10.Print("#1i - Constructor: CSuperString &");

    }

#pragma endregion 

    std::cout << "\n\n\n";

#pragma region "Assigment Operator Tests"
    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** Assigment Operator ************************" << std::endl;
    std::cout << "****************************************************************" << std::endl;

    // #2a - Assignment Operator: const char *
    CSuperString ssSource;
    ssSource = "I Love Star Trek";
    ssSource.Print("#2 - Assignment Operator: const char *");

    // #2b - Assignment Operator: const char
    ssSource = 'X';
    ssSource.Print("#3 - Assignment Operator: const char");

    // #2c - Assignment Operator: CSuperString &
    CSuperString ssSource2 = "I Love Star Wars";
    ssSource = ssSource2;
    ssSource.Print("#4 - Assignment Operator: CSuperString &");
#pragma endregion

    std::cout << "\n\n\n";

#pragma region "Length"
    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** Length  ***********************************" << std::endl;
    std::cout << "****************************************************************" << std::endl;

    // #3 - Length 
    ssSource.Print("#3 - Length");
    std::cout << "#3 - Length: 16? " << ssSource.Length() << std::endl;
#pragma endregion 

    std::cout << "\n\n\n";

#pragma region "Concatenate Operator +="
    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** Concatenate Operator += *******************" << std::endl;
    std::cout << "****************************************************************" << std::endl;


    // #4a - Concatenate Operator: const char *
    CSuperString ssConcat1("Hello");
    const char* strToAppend1 = " World";
    std::cout << "Super String: " << ssConcat1.ToString() << ", String to Append: " << strToAppend1 << std::endl;
    ssConcat1 += strToAppend1;
    ssConcat1.Print("#4a - Concatenate Operator +=: const char *");

    // #4b - Concatenate Operator: const char
    CSuperString ssConcat2("Hello");
    char charToAppend2 = '!';
    std::cout << "Super String: " << ssConcat2.ToString() << ", Character to Append: " << charToAppend2 << std::endl;
    ssConcat2 += charToAppend2;
    ssConcat2.Print("#4b - Concatenate Operator +=: const char");

    // #4c - Concatenate Operator: CSuperString &
    CSuperString ssConcat3("Hello");
    CSuperString ssAppend(" World");
    std::cout << "Super String: " << ssConcat3.ToString() << ", String to Append: " << ssAppend.ToString() << std::endl;
    ssConcat3 += ssAppend;
    ssConcat3.Print("#4c - Concatenate Operator +=: CSuperString &");

#pragma endregion 

    std::cout << "\n\n\n";

#pragma region "Concatenate Operator +"
    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** Concatenate Operator + ********************" << std::endl;
    std::cout << "****************************************************************" << std::endl;


    // #5a - Operator +: CSuperString + CSuperString
    CSuperString ssLeft1("Hello");
    CSuperString ssRight1(" World");
    CSuperString ssResult1 = ssLeft1 + ssRight1;
    std::cout << "Left String: " << ssLeft1.ToString() << ", Right String: " << ssRight1.ToString() << std::endl;
    ssResult1.Print("#5a - Operator +: CSuperString + CSuperString");

    // #5b - Operator +: const char* + CSuperString
    const char* pstrLeft2 = "I Love";
    CSuperString ssRight2(" C++");
    CSuperString ssResult2 = pstrLeft2 + ssRight2;
    std::cout << "Left String: " << pstrLeft2 << ", Right String: " << ssRight2.ToString() << std::endl;
    ssResult2.Print("#5b - Operator +: const char* + CSuperString");

    // #5c - Operator +: CSuperString + const char*
    CSuperString ssLeft3("I Love");
    const char* pstrRight3 = " Programming";
    CSuperString ssResult3 = ssLeft3 + pstrRight3;
    std::cout << "Left String: " << ssLeft3.ToString() << ", Right String: " << pstrRight3 << std::endl;
    ssResult3.Print("#5c - Operator +: CSuperString + const char*");

#pragma endregion 

    std::cout << "\n\n\n";

#pragma region "FindFirst/FindLast Index"
    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** FindFirst/FindLast Index ******************" << std::endl;
    std::cout << "****************************************************************" << std::endl;

    // #6a - FindFirstIndexOf: const char
    CSuperString ssSearch("Hello World");
    char charToFind1 = 'o';
    long firstIndex1 = ssSearch.FindFirstIndexOf(charToFind1);
    ssSearch.Print("#6a - FindFirstIndexOf: const char");
    std::cout << "Current String: " << ssSearch.ToString() << ", Character to Find: " << charToFind1 << std::endl;
    std::cout << "First Index: " << firstIndex1 << std::endl;

    // #6b - FindFirstIndexOf: const char, with start index
    char charToFind2 = 'o';
    long startIndex2 = 4;
    long firstIndex2 = ssSearch.FindFirstIndexOf(charToFind2, startIndex2);
    ssSearch.Print("#6b - FindFirstIndexOf: const char, with start index");
    std::cout << "Current String: " << ssSearch.ToString() << ", Character to Find: " << charToFind2 << ", Start Index: " << startIndex2 << std::endl;
    std::cout << "First Index: " << firstIndex2 << std::endl;

    // #6c - FindLastIndexOf: const char
    char charToFind3 = 'o';
    long lastIndex3 = ssSearch.FindLastIndexOf(charToFind3);
    ssSearch.Print("#6c - FindLastIndexOf: const char");
    std::cout << "Current String: " << ssSearch.ToString() << ", Character to Find: " << charToFind3 << std::endl;
    std::cout << "Last Index: " << lastIndex3 << std::endl;

    // #6d - FindFirstIndexOf: const char*
    const char* strToFind4 = "World";
    long firstIndex4 = ssSearch.FindFirstIndexOf(strToFind4);
    ssSearch.Print("#6d - FindFirstIndexOf: const char*");
    std::cout << "Current String: " << ssSearch.ToString() << ", String to Find: " << strToFind4 << std::endl;
    std::cout << "First Index: " << firstIndex4 << std::endl;

    // #6e - FindFirstIndexOf: const char*, with start index
    const char* strToFind5 = "World";
    long startIndex5 = 0;
    long firstIndex5 = ssSearch.FindFirstIndexOf(strToFind5, startIndex5);
    ssSearch.Print("#6e - FindFirstIndexOf: const char*, with start index");
    std::cout << "Current String: " << ssSearch.ToString() << ", String to Find: " << strToFind5 << ", Start Index: " << startIndex5 << std::endl;
    std::cout << "First Index: " << firstIndex5 << std::endl;

    // #6f - FindLastIndexOf: const char*
    const char* strToFind6 = "o";
    long lastIndex6 = ssSearch.FindLastIndexOf(strToFind6);
    ssSearch.Print("#6f - FindLastIndexOf: const char*");
    std::cout << "Current String: " << ssSearch.ToString() << ", String to Find: " << strToFind6 << std::endl;
    std::cout << "Last Index: " << lastIndex6 << std::endl;



#pragma endregion 

    std::cout << "\n\n\n";

#pragma region "Upper/Lower/Trim"
    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** Upper/Lower/Trim **************************" << std::endl;
    std::cout << "****************************************************************" << std::endl;

    // #7a - ToUpperCase
    CSuperString ssTest7a("Hello World");
    ssTest7a.Print("#7a - ToUpperCase");
    const char* upperCaseResult = ssTest7a.ToUpperCase();
    std::cout << "Result: " << upperCaseResult << std::endl;

    // #7b - ToLowerCase
    ssTest7a.Print("#7b - ToLowerCase");
    const char* lowerCaseResult = ssTest7a.ToLowerCase();
    std::cout << "Result: " << lowerCaseResult << std::endl;

    // #7c - TrimLeft
    CSuperString ssTest7b("   Hello World   ");
    ssTest7b.Print("#7c - TrimLeft");
    const char* trimmedLeftResult = ssTest7b.TrimLeft();
    std::cout << "Result: " << trimmedLeftResult << std::endl;

    // #7d - TrimRight
    ssTest7b.Print("#7d - TrimRight");
    const char* trimmedRightResult = ssTest7b.TrimRight();
    std::cout << "Result: " << trimmedRightResult << "test Right space" << std::endl;

    // #7e - Trim
    ssTest7b.Print("#7e - Trim");
    const char* trimmedResult = ssTest7b.Trim();
    std::cout << "Result: " << trimmedResult << "test Right space" <<  std::endl;

    // #7f - Reverse
    ssTest7a.Print("#7f - Reverse");
    const char* reversedResult = ssTest7a.Reverse();
    std::cout << "Result: " << reversedResult << std::endl;
#pragma endregion 

    std::cout << "\n\n\n";

#pragma region "String Manipulation"

    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** String Manipulation ***********************" << std::endl;
    std::cout << "****************************************************************" << std::endl;

    // #8a - Left
    CSuperString ssTest8a("Hello World");
    ssTest8a.Print("#8a - After Left(5)");
    std::cout << "Result: " << ssTest8a.Left(4).ToString() << std::endl;

    // #8b - Right
    const char* rightResult = ssTest8a.Right(5);
    ssTest8a.Print("#8b - After Right(5)");
    std::cout << "Result: " << rightResult << std::endl;

    // #8c - Substring
    const char* substringResult = ssTest8a.Substring(6, 5);
    ssTest8a.Print("#8c - After Substring(6, 5)");
    std::cout << "Result: " << substringResult << std::endl;

    // #8d - Replace (char)
    const char* replacedCharResult = ssTest8a.Replace('o', 'X');
    ssTest8a.Print("#8d - After Replace('o', 'X')");
    std::cout << "Result: " << replacedCharResult << std::endl;

    // #8e - Replace (const char*)
    const char* replacedStrResult = ssTest8a.Replace("World", "Universe");
    ssTest8a.Print("#8e - After Replace(\"World\", \"Universe\")");
    std::cout << "Result: " << replacedStrResult << std::endl;

    // #8f - Insert (char)
    const char* insertedCharResult = ssTest8a.Insert('X', 6);
    ssTest8a.Print("#8f - After Insert('X', 6)");
    std::cout << "Result: " << insertedCharResult << std::endl;

    // #8g - Insert (const char*)
    const char* insertedStrResult = ssTest8a.Insert("Beautiful ", 5);
    ssTest8a.Print("#8g - After Insert(\"Beautiful \", 5)");
    std::cout << "Result: " << insertedStrResult << std::endl;
#pragma endregion 

    std::cout << "\n\n\n";

#pragma region "Subscript Operator"
    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** Subscript Operators ***********************" << std::endl;
    std::cout << "****************************************************************" << std::endl;

    const char* initialString9a = "Hello World";
    CSuperString ssTest9a(initialString9a);

    // #9a - Subscript operator (non-const)
    ssTest9a.Print("#9a - Subscript operator (non-const)");
    char charAtIndex = ssTest9a[6];
    std::cout << "Character at index 6: " << charAtIndex << std::endl;

    // #9b - Subscript operator (const)
    ssTest9a.Print("#9b - Subscript operator (const)");
    const char& constCharAtIndex = ssTest9a[3];
    std::cout << "Constant character at index 3: " << constCharAtIndex << std::endl;

    // #9c - Subscript operator (non-const) modification
    ssTest9a.Print("#9c - Subscript operator (non-const) modification");
    ssTest9a[0] = 'X';
    std::cout << "Modified String after changing character at index 0: " << ssTest9a.ToString() << std::endl;

#pragma endregion 

    std::cout << "\n\n\n";

#pragma region "ToDataTypes"
    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** ToDataTypes *******************************" << std::endl;
    std::cout << "****************************************************************" << std::endl;
    // #10a - ToString
    CSuperString ssTest10aToString("12345");
    ssTest10aToString.Print("#10a - ToString");
    const char* toStringResult = ssTest10aToString.ToString();
    std::cout << "Result of ToString: " << toStringResult << std::endl;

    // #10b - ToBoolean
    CSuperString ssTest10bToBoolean("true");
    ssTest10bToBoolean.Print("#10b - ToBoolean");
    bool toBooleanResult = ssTest10bToBoolean.ToBoolean();
    std::cout << "Result of ToBoolean: " << std::boolalpha << toBooleanResult << std::endl;

    // #10c - ToShort
    CSuperString ssTest10cToShort(std::numeric_limits<short>::max());
    ssTest10cToShort.Print("#10c - ToShort");
    short toShortResult = ssTest10cToShort.ToShort();
    std::cout << "Result of ToShort: " << toShortResult << std::endl;

    // #10d - ToInteger
    CSuperString ssTest10dToInteger(std::numeric_limits<int>::max());
    ssTest10dToInteger.Print("#10d - ToInteger");
    int toIntegerResult = ssTest10dToInteger.ToInteger();
    std::cout << "Result of ToInteger: " << toIntegerResult << std::endl;

    // #10e - ToLong
    CSuperString ssTest10eToLong(std::numeric_limits<long>::max());
    ssTest10eToLong.Print("#10e - ToLong");
    long toLongResult = ssTest10eToLong.ToLong();
    std::cout << "Result of ToLong: " << toLongResult << std::endl;

    // #10f - ToFloat
    CSuperString ssTest10fToFloat("123.45f");
    ssTest10fToFloat.Print("#10f - ToFloat");
    float toFloatResult = ssTest10fToFloat.ToFloat();
    std::cout << "Result of ToFloat: " << ssTest10fToFloat.ToFloat() << std::endl;

    // #10g - ToDouble
    CSuperString ssTest10gToDouble("123.45");
    ssTest10gToDouble.Print("#10g - ToDouble");
    double toDoubleResult = ssTest10gToDouble.ToDouble();
    std::cout << "Result of ToDouble: " << ssTest10gToDouble.ToDouble() << std::endl;

#pragma endregion

    std::cout << "\n\n\n";

#pragma region "stream operators" 
    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** Stream Operators **************************" << std::endl;
    std::cout << "****************************************************************" << std::endl;
    // #11a - Operator<< (ostream)
    CSuperString ssTest11a("Hello, Operator<<!");
    ssTest11a.Print("#11a - Operator<< (ostream)");
    std::cout << "Result of Operator<<: " << ssTest11a << std::endl;

    // #11b - Operator>> (istream)
    CSuperString ssTest11b;
    std::cout << "Enter a string for Operator>>: ";
    std::cin >> ssTest11b;
    ssTest11b.Print("#11b - Operator>> (istream)");
#pragma endregion 

    std::cout << "\n\n\n";

#pragma region "Comparison Operators"
    std::cout << "****************************************************************" << std::endl;
    std::cout << "******************** Comparison Operators **********************" << std::endl;
    std::cout << "****************************************************************" << std::endl;

    // #12a - Comparison operators
    CSuperString ssTest("Hello");
    ssTest.Print("Original String");

    // Equality
    std::cout << "Equality Tests:" << std::endl;
    std::cout << "Is \"" << ssTest << "\" equal to == \"Hello\"? " << (ssTest == "Hello") << std::endl;
    std::cout << "Is \"" << ssTest << "\" equal to == \"World\"? " << (ssTest == "World") << std::endl;
    std::cout << "Is \"" << ssTest << "\" equal to == 'H'? " << (ssTest == 'H') << std::endl;

    // Inequality
    std::cout << "\nInequality Tests:" << std::endl;
    std::cout << "Is \"" << ssTest << "\" not equal to != \"Hello\"? " << (ssTest != "Hello") << std::endl;
    std::cout << "Is \"" << ssTest << "\" not equal to != \"World\"? " << (ssTest != "World") << std::endl;
    std::cout << "Is \"" << ssTest << "\" not equal to != 'H'? " << (ssTest != 'H') << std::endl;

    // Greater Than
    std::cout << "\nGreater Than Tests:" << std::endl;
    std::cout << "Is \"" << ssTest << "\" greater than > \"Hello\"? " << (ssTest > "Hello") << std::endl;
    std::cout << "Is \"" << ssTest << "\" greater than > \"World\"? " << (ssTest > "World") << std::endl;
    std::cout << "Is \"" << ssTest << "\" greater than > 'H'? " << (ssTest > 'H') << std::endl;

    // Less Than
    std::cout << "\nLess Than Tests:" << std::endl;
    std::cout << "Is \"" << ssTest << "\" less than < \"Hello\"? " << (ssTest < "Hello") << std::endl;
    std::cout << "Is \"" << ssTest << "\" less than < \"World\"? " << (ssTest < "World") << std::endl;
    std::cout << "Is \"" << ssTest << "\" less than < 'H'? " << (ssTest < 'H') << std::endl;

    // Greater Than or Equal To
    std::cout << "\nGreater Than or Equal To Tests:" << std::endl;
    std::cout << "Is \"" << ssTest << "\" greater than or equal to >= \"Hello\"? " << (ssTest >= "Hello") << std::endl;
    std::cout << "Is \"" << ssTest << "\" greater than or equal to >= \"World\"? " << (ssTest >= "World") << std::endl;
    std::cout << "Is \"" << ssTest << "\" greater than or equal to >= 'H'? " << (ssTest >= 'H') << std::endl;

    // Less Than or Equal To
    std::cout << "\nLess Than or Equal To Tests:" << std::endl;
    std::cout << "Is \"" << ssTest << "\" less than or equal to <= \"Hello\"? " << (ssTest <= "Hello") << std::endl;
    std::cout << "Is \"" << ssTest << "\" less than or equal to <= \"World\"? " << (ssTest <= "World") << std::endl;
    std::cout << "Is \"" << ssTest << "\" less than or equal to <= 'H'? " << (ssTest <= 'H') << std::endl;


#pragma endregion 

    return 0;
}


