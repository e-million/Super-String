#include <iostream>
#include <cstring> 
#include <cstdlib>
#include "CSuperString.h"
// Class: CSuperString 

// check if functions need to be const or not 

#pragma region Constructors DONE

// --------------------------------------------------------------------------------
// Name: Constructors 
// Abstract: Parameterized constructors, default, copy
// -------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Name: Default Constructor 
// Abstract: Initializes a CSuperString object with default values.
// -------------------------------------------------------------------------------
CSuperString::CSuperString() {
    Initialize(0);
};

// --------------------------------------------------------------------------------
// Name: Char Pointer Constructor 
// Abstract: Initializes a CSuperString object with the content of a given C-style string.
// -------------------------------------------------------------------------------
CSuperString::CSuperString(const char* pstrStringToCopy) {
    Initialize(pstrStringToCopy);
}

// --------------------------------------------------------------------------------
// Name: Boolean Constructor 
// Abstract: Initializes a CSuperString object with the string representation of a boolean value.
// -------------------------------------------------------------------------------
CSuperString::CSuperString(const bool blnBooleanToCopy) {
    Initialize(blnBooleanToCopy ? "true" : "false");
}

// --------------------------------------------------------------------------------
// Name: Char Constructor 
// Abstract: Initializes a CSuperString object with a single character.
// -------------------------------------------------------------------------------
CSuperString::CSuperString(const char chrLetterToCopy) {
    char buffer[2] = { chrLetterToCopy, '\0' };
    Initialize(buffer);
}

// --------------------------------------------------------------------------------
// Name: Short Constructor 
// Abstract: Initializes a CSuperString object with the string representation of a short integer.
// -------------------------------------------------------------------------------
CSuperString::CSuperString(const short shtShortToCopy) {
    char buffer[20]; // Adjust size based on the expected range of short
    sprintf_s(buffer, sizeof(buffer), "%hd", shtShortToCopy);
    Initialize(buffer);
}
// int
CSuperString::CSuperString(const int intIntegerToCopy) {
    // Assuming integers can be represented in 12 characters (including sign and null terminator)
    char buffer[12];
    sprintf_s(buffer, sizeof(buffer), "%d", intIntegerToCopy);
    Initialize(buffer);
}

// --------------------------------------------------------------------------------
// Name: Long Constructor 
// Abstract: Initializes a CSuperString object with the string representation of a long integer.
// -------------------------------------------------------------------------------
CSuperString::CSuperString(const long lngLongToCopy) {
    char buffer[20]; // Adjust size based on the expected range of long
    sprintf_s(buffer, sizeof(buffer), "%ld", lngLongToCopy);
    Initialize(buffer);
}

// --------------------------------------------------------------------------------
// Name: Float Constructor 
// Abstract: Initializes a CSuperString object with the string representation of a float.
// -------------------------------------------------------------------------------
CSuperString::CSuperString(const float sngFloatToCopy) {
    char buffer[32]; // Adjust size based on the expected precision of float
    sprintf_s(buffer, sizeof(buffer), "%f", sngFloatToCopy);
    Initialize(buffer);
}

// --------------------------------------------------------------------------------
// Name: Double Constructor 
// Abstract: Initializes a CSuperString object with the string representation of a double.
// -------------------------------------------------------------------------------
CSuperString::CSuperString(const double dblDoubleToCopy) {
    char buffer[32];
    sprintf_s(buffer, sizeof(buffer), "%lf", dblDoubleToCopy);
    Initialize(buffer);
}

// --------------------------------------------------------------------------------
// Name: Copy Constructor 
// Abstract: Initializes a CSuperString object by copying the content of another CSuperString.
// -------------------------------------------------------------------------------
CSuperString::CSuperString(const CSuperString& ssStringToCopy) {
    Initialize(ssStringToCopy.ToString());
}

#pragma endregion

#pragma region Constructor Helpers DONE

// --------------------------------------------------------------------------------
// Name: Initialize 
// Abstract: Set class pointers to zero and then call set methods 
// --------------------------------------------------------------------------------

void CSuperString::Initialize(const char* pstrSource) {
    // Assign other member variables to 0
    m_pstrSuperString = 0;
    m_pstrUpperCase = 0;
    m_pstrLowerCase = 0;
    m_pstrTrimLeft = 0;
    m_pstrTrimRight = 0;
    m_pstrTrim = 0;
    m_pstrReversed = 0;
    m_pstrLeft = 0;
    m_pstrRight = 0;
    m_pstrSubstring = 0;
    m_pstrInsert = 0; 
    m_pstrReplace = 0;

    // Funnell all memory allocation through the assignment operator 
    *this = pstrSource;
};


// --------------------------------------------------------------------------------
// Name: Cleanup() 
// Abstract: Deallocates ALL dynamically allocated memory at once
// --------------------------------------------------------------------------------
void CSuperString::Cleanup() {

    // frees memory of other member variables with the m_pstr prefix
    DeleteString(m_pstrSuperString);
    DeleteString(m_pstrUpperCase);
    DeleteString(m_pstrLowerCase);
    DeleteString(m_pstrTrimLeft);
    DeleteString(m_pstrTrimRight);
    DeleteString(m_pstrTrim);
    DeleteString(m_pstrReversed);
    DeleteString(m_pstrLeft);
    DeleteString(m_pstrRight);
    DeleteString(m_pstrSubstring);
    DeleteString(m_pstrInsert);
    DeleteString(m_pstrReplace);
}

// --------------------------------------------------------------------------------
// Name: DeleteString 
// Abstract: Deallocates any dynamically allocated memory one by one
// --------------------------------------------------------------------------------
void CSuperString::DeleteString(char*& pstrSource) {
    if (pstrSource != 0) {
        delete[] pstrSource;
        pstrSource = 0;
  }
}

    // --------------------------------------------------------------------------------
    // Name: ~CSuperString (Destructor) 
    // Abstract: Deallocates any dynamically allocated memory by calling the Cleanup method.
    // --------------------------------------------------------------------------------
        CSuperString::~CSuperString() {
            // Deallocate any dynamically allocated memory
            Cleanup();
        }

// --------------------------------------------------------------------------------
// Name: Deep copy 
// Abstract: memory-allocated copy 
// --------------------------------------------------------------------------------
void CSuperString::DeepCopy(const char* pstrSource) {
    if (pstrSource != nullptr) {
        m_pstrSuperString = CloneString(pstrSource); // deep copy 
    }
    else {
        m_pstrSuperString = nullptr;
    }
}

    // --------------------------------------------------------------------------------
    // Name: CloneString 
    // Abstract: makes a clone with newly allocated memory (deepcopy)
    // --------------------------------------------------------------------------------
    char* CSuperString::CloneString(const char* pstrSource) {

        // if source is not empty, continue
        if (pstrSource != nullptr) {
            // decalare variables
            char* pstrClone = 0;
            long lngLength = 0;

            lngLength = strlen(pstrSource); // length of pstrSource
            // char array allocated mem using new so its a deep copy with a different address than the copy
            pstrClone = new char[lngLength + 1];
            strcpy_s(pstrClone, lngLength + 1, pstrSource); // copy pstrSource into pstrClone 

            return pstrClone;
        }        

        return nullptr;
    }



#pragma endregion

#pragma region "Assignment = Operator Overloads DONE"

// --------------------------------------------------------------------------------
// Name: operator= Overload  
// Abstract: Assigns a new   tring to the CSuperString, deallocating any dynamically allocated memory and performing a deep copy.
// --------------------------------------------------------------------------------


// --------------------------------------------------------------------------------
// Name: operator= Overload (char*)
// Abstract: Overloads the assignment operator to copy the content of a C-style string.
// -------------------------------------------------------------------------------
    void CSuperString::operator= (const char* pstrStringToCopy) {
   
    // declare new pointer 
    char* pstrCopyOfSource = 0;

    // store the current string in m_pstrSuperString
        pstrCopyOfSource = CloneString(pstrStringToCopy);

    // deallocates memory of the current string 
    Cleanup();

    // stores the new (uppercase) string into the newly deallocated m_pstrSuperString
    this->m_pstrSuperString = pstrCopyOfSource;

    }


// --------------------------------------------------------------------------------
// Name: operator= Overload (char)
// Abstract: Overloads the assignment operator to copy a single character.
// -------------------------------------------------------------------------------
void CSuperString::operator= (const char chrLetterToCopy) {
    // Check if the string is already stored and is different
    if (this->m_pstrSuperString != nullptr && *m_pstrSuperString == chrLetterToCopy) {
        // No need to copy, return reference to current object
       // return *this;
    }

    // No, clean up and...
    Cleanup();

    // Deep Copy 
    char temp[2] = { chrLetterToCopy, '\0' };
    DeepCopy(temp);
}


// --------------------------------------------------------------------------------
// Name: operator= Overload (&CSuperString obj)
// Abstract: Overloads the assignment operator to copy the content of another CSuperString.
// -------------------------------------------------------------------------------
void CSuperString::operator= (const CSuperString& ssStringToCopy) {

    if (this != &ssStringToCopy) {
        // No, clean up and...
        Cleanup();

        // Deep Copy 
        DeepCopy(ssStringToCopy.m_pstrSuperString);
    }
}

#pragma endregion

#pragma region "Concatenate += Operator Overloads DONE"

// --------------------------------------------------------------------------------
// Name: operator+= Overload (const char*, char, CSuperString& )
// Abstract: Concatenates the current CSuperString with the given C-style string 
//           using the + operator, and then assigns the result to the current object.
// -------------------------------------------------------------------------------
void CSuperString::operator += (const char* pstrStringToAppend) {
    *this = *this + pstrStringToAppend;
}

void CSuperString::operator += (const char chrCharacterToAppend) {
    *this = *this + chrCharacterToAppend;
}

void CSuperString::operator += (const  CSuperString& ssStringToAppend) {
    *this = *this + ssStringToAppend;
}

#pragma endregion 

#pragma region "Concatenate + Operator Overloads DONE"

// --------------------------------------------------------------------------------
// Name: Append
// Abstract: Concatenates the current CSuperString with another CSuperString.
//           Allocates memory for the concatenated string, copies both strings, 
//           and updates the pointer to the new concatenated string.
// -------------------------------------------------------------------------------
void CSuperString::Append(const CSuperString &ssRight) {

    // Calculate lengths of the strings
    size_t leftLength = Length(); 
    size_t rightLength = ssRight.Length(); 

    // Allocate memory for the concatenated string
    char* concatenatedString = new char[leftLength + rightLength + 1];

    // Copy the current string to the result
    strcpy_s(concatenatedString, leftLength + 1, m_pstrSuperString);

    // Concatenate the other string to the result
    strcat_s(concatenatedString, leftLength + rightLength + 1, ssRight.ToString());

    // Free the current dynamically allocated memory
    DeleteString(m_pstrSuperString);

    // Update the pointer to the new concatenated string
    m_pstrSuperString = CloneString(concatenatedString);
}

// --------------------------------------------------------------------------------
// Name: operator+ Overload (CSuperString & CSuperString)
// Abstract: Overloads the + operator to concatenate two CSuperString objects.
//           Creates a new object with the content of the left object,
//           appends the content of the right object using the Append function,
//           and returns the concatenated CSuperString object.
// -------------------------------------------------------------------------------
CSuperString operator+ (const CSuperString &ssLeft, const CSuperString &ssRight) {

    // new object instantianted with the left obj so it creates a copy 
    CSuperString result(ssLeft);  // Copy constructor

    // calls Append function on left side to append right side (parameter)
    result.Append(ssRight);

    // returns concatenated string in obj
    return result;
}

// --------------------------------------------------------------------------------
// Name: operator+ Overload (char* Left & CSuperString)
// Abstract: Overloads the + operator to concatenate a C-style string and a CSuperString.
//           Creates a new object with the content of the C-style string,
//           appends the content of the CSuperString using the Append function,
//           and returns the concatenated CSuperString object.
// -------------------------------------------------------------------------------
CSuperString operator+ (const char* pstrLeft, const CSuperString &ssRight) {

    // new object instantianted with the left obj so it creates a copy 
    CSuperString result(pstrLeft);

    // calls Append function on left side to append right side (parameter)
    result.Append(ssRight);

    // returns concatenated string in obj
    return result;
}

// --------------------------------------------------------------------------------
// Name: operator+ Overload (CSuperString & (char*) Right)
// Abstract: Overloads the + operator to concatenate a CSuperString and a C-style string.
//           Creates a new object with the content of the CSuperString,
//           appends the content of the C-style string using the Append function,
//           and returns the concatenated CSuperString object.
// -------------------------------------------------------------------------------
CSuperString operator+ (const CSuperString &ssLeft, const char* pstrRight) {

    // new object instantianted with the left obj so it creates a copy 
    CSuperString ssResult(ssLeft);

    // calls Append function on left side to append right side (parameter)
    ssResult.Append(pstrRight);

    // returns concatenated string in obj
    return ssResult;
}



#pragma endregion 

#pragma region FindIndexOf Methods DONE
// --------------------------------------------------------------------------------
// Name: FindFirstIndexOf
// Abstract: Finds the first occurrence of a character in the CSuperString.
// Returns the index of the first occurrence, or -1 if not found or the string is empty.
// -------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind) const {
    // Check if m_pstrSuperString is not nullptr
    if (m_pstrSuperString != nullptr) {
        const char* result = strchr(m_pstrSuperString, chrLetterToFind);

        if (result != nullptr) {
            // Calculate the index based on the pointer difference
            return result - m_pstrSuperString;
        }
    }

    // If the character is not found or the string is empty, return -1
    return -1;
}

// --------------------------------------------------------------------------------
// Name: FindFirstIndexOf
// Abstract: Finds the first occurrence of a character in the CSuperString 
//           starting from a specific index. Returns the index of the first 
//           occurrence, or -1 if not found, the string is empty, or the start
//           index is out of range.
// -------------------------------------------------------------------------------

long CSuperString::FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex) const {
    // Check if m_pstrSuperString is not nullptr
    if (m_pstrSuperString != nullptr) {
        // Validate the start index
        if (lngStartIndex >= 0 && lngStartIndex < Length()) {
            const char* strResult = strchr(m_pstrSuperString + lngStartIndex, chrLetterToFind);

            if (strResult != nullptr) {
                // Calculate the index based on the pointer difference
                return strResult - m_pstrSuperString;
            }
        }
    }

    // If the character is not found or the string is empty, return -1
    return -1;
}

// --------------------------------------------------------------------------------
// Name: FindFirstIndexOf
// Abstract: Finds the first occurrence of a substring in the CSuperString.
// Returns the index of the first occurrence, or -1 if not found, the string is empty, 
// or the substring is nullptr.
// -------------------------------------------------------------------------------

long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind) const {
    // Check if m_pstrSuperString is not nullptr and substring is not nullptr
    if (m_pstrSuperString != nullptr && pstrSubStringToFind != nullptr) {
        const char* strResult = strstr(m_pstrSuperString, pstrSubStringToFind);

        if (strResult != nullptr) {
            // Calculate the index based on the pointer difference
            return strResult - m_pstrSuperString;
        }
    }

    // If the substring is not found or the string is empty, return -1
    return -1;
}

// --------------------------------------------------------------------------------
// Name: FindFirstIndexOf
// Abstract: Finds the first occurrence of a substring in the CSuperString 
//           starting from a specific index. Returns the index of the first 
//           occurrence, or -1 if not found, the string is empty, the substring
//           is nullptr, or the start index is out of range.
// -------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex) const {
    // Check if m_pstrSuperString is not nullptr, substring is not nullptr, and start index is valid
    if (m_pstrSuperString != nullptr && pstrSubStringToFind != nullptr &&
        lngStartIndex >= 0 && lngStartIndex < Length()) {
        const char* strResult = strstr(m_pstrSuperString + lngStartIndex, pstrSubStringToFind);

        if (strResult != nullptr) {
            // Calculate the index based on the pointer difference
            return strResult - m_pstrSuperString;
        }
    }

    // If the substring is not found or the string is empty, return -1
    return -1;
}

// --------------------------------------------------------------------------------
// Name: FindLastIndexOf
// Abstract: Finds the last occurrence of a character in the CSuperString.
// Returns the index of the last occurrence, or -1 if not found or the string is empty.
// -------------------------------------------------------------------------------
long CSuperString::FindLastIndexOf(const char chrLetterToFind) const {
    // Check if m_pstrSuperString is not nullptr
    if (m_pstrSuperString != nullptr) {
        const char* strResult = strrchr(m_pstrSuperString, chrLetterToFind);

        if (strResult != nullptr) {
            // Calculate the index based on the pointer difference
            return strResult - m_pstrSuperString;
        }
    }

    // If the character is not found or the string is empty, return -1
    return -1;
}

// --------------------------------------------------------------------------------
// Name: FindLastIndexOf
// Abstract: Finds the last occurrence of a substring in the CSuperString.
// Returns the index of the last occurrence, or -1 if not found, the string is empty, 
// or the substring is nullptr.
// -------------------------------------------------------------------------------
long CSuperString::FindLastIndexOf(const char* pstrSubStringToFind) const {

    // Check if m_pstrSuperString is not nullptr and substring is not nullptr
    if (m_pstrSuperString != nullptr && pstrSubStringToFind != nullptr) {
        const char* strResult = strstr(m_pstrSuperString, pstrSubStringToFind);
        const char* strLastResult = nullptr;

        while (strResult != nullptr) {
            strLastResult = strResult;
            strResult = strstr(strResult + 1, pstrSubStringToFind);
        }

        if (strLastResult != nullptr) {
            // Calculate the index based on the pointer difference
            return strLastResult - m_pstrSuperString;
        }
    }

    // If the substring is not found or the string is empty, return -1
    return -1;
}

#pragma endregion

#pragma region "String Manipulation Methods (ToUpper, Trim, etc.) DONE"

// --------------------------------------------------------------------------------
// Name: Length
// Abstract: Returns the length of the CSuperString.
// -------------------------------------------------------------------------------
long CSuperString::Length() const{
    // Check if m_pstrSuperString is not nullptr
    if (m_pstrSuperString != nullptr) {
        return strlen(m_pstrSuperString);
    }
    else {
        return 0; // If the string is empty or null, length is zero
    }
}

// --------------------------------------------------------------------------------
// Name: ToUpperCase
// Abstract: Converts the CSuperString to uppercase.
// -------------------------------------------------------------------------------
const char* CSuperString::ToUpperCase() {
    // deletes allocated memory from previous function call
    DeleteString(m_pstrUpperCase);

    // makes a clone of m_pstrSuperString and stores it in m_pstrUpperCase
    m_pstrUpperCase = CloneString(m_pstrSuperString);

    // makes clone all lowercase
    size_t length = strlen(m_pstrUpperCase);
    _strupr_s(m_pstrUpperCase, length + 1); // +1 for null terminator

    // returns clone variable
    return m_pstrUpperCase;
}

// --------------------------------------------------------------------------------
// Name: ToLowerCase
// Abstract: Converts the CSuperString to lowercase.
// -------------------------------------------------------------------------------
const char* CSuperString::ToLowerCase() {
    // deletes allocated memory from previous function call
    DeleteString(m_pstrLowerCase);

    // makes a clone of m_pstrSuperString and stores it in m_pstrUpperCase
    m_pstrLowerCase = CloneString(m_pstrSuperString);

    // makes clone all lowercase
    size_t length = strlen(m_pstrLowerCase);
    _strlwr_s(m_pstrLowerCase, length + 1); // +1 for null terminator

    // returns clone variable
    return m_pstrLowerCase;
}

// --------------------------------------------------------------------------------
// Name: Replace
// Abstract: Replaces occurrences of a specified character in the CSuperString.
// -------------------------------------------------------------------------------
const char* CSuperString::Replace(char chrLetterToFind, char chrReplace) {
    DeleteString(m_pstrReplace); 

    char* pTempString = CloneString(m_pstrSuperString);

    size_t length = strlen(pTempString);

    for (size_t i = 0; i < length; ++i) {
        if (pTempString[i] == chrLetterToFind) {
            // chenge the char at the index to chrReplace 
            pTempString[i] = chrReplace;
        }
    }


    m_pstrReplace = CloneString(pTempString);

    DeleteString(pTempString);

    return m_pstrReplace;
}

// --------------------------------------------------------------------------------
// Name: Replace
// Abstract: Replaces occurrences of a specified substring in the CSuperString 
//           with another substring.
// --------------------------------------------------------------------------------
const char* CSuperString::Replace(const char* pstrFind, const char* pstrReplace) {
    DeleteString(m_pstrReplace);

    size_t findLength = strlen(pstrFind);
    size_t replaceLength = strlen(pstrReplace);

    // Create a temporary string to build the modified string
    char* pTempString = new char[2 * Length() + 1];  // Twice the length for safety, +1 for the null terminator
    pTempString[0] = '\0';  // Ensure tempString is initially an empty string

    size_t index = 0;

    while (m_pstrSuperString[index] != '\0') {
        if (strncmp(m_pstrSuperString + index, pstrFind, findLength) == 0) {
            // Concatenate pstrReplace to pTempString
            strcat_s(pTempString, 2 * Length() + 1, pstrReplace);
                
                // Move the index to the end of the replaced substring
            index += findLength;
        }
        else {
            // Concatenate the current character to pTempString
            strncat_s(pTempString, 2 * Length() + 1, m_pstrSuperString + index, 1);
            // Move to the next character in m_pstrSuperString
            ++index;
        }
    }
    // Clone and return m_pstrSuperString
    m_pstrReplace = CloneString(pTempString);

    DeleteString(pTempString);

    return m_pstrReplace;
}

// --------------------------------------------------------------------------------
// Name: Insert
// Abstract: Inserts a specified character into the CSuperString at the specified index.
// --------------------------------------------------------------------------------
const char* CSuperString::Insert(const char chrLetterToInsert, long lngIndex) {
    // Delete any existing content in m_pstrInsert
    DeleteString(m_pstrInsert);

    size_t length = Length();

    // Allocate memory for a temporary string to build the modified string
    char* pTempString = new char[length + 2];  // +2 for the inserted character and null terminator

    // Extract the left substring before the insertion point
    const char* pstrLeft = CloneString(Substring(0, lngIndex));
    size_t lengthLeft = strlen(pstrLeft);

    // Copy the left substring to the temporary string
    for (int j = 0; j < lengthLeft; j++) {
        pTempString[j] = pstrLeft[j];
    }

    // Insert the specified character at the insertion point
    pTempString[lengthLeft] = chrLetterToInsert;

    // Extract the right substring after the insertion point
    const char* pstrRight = CloneString(Substring(lngIndex, length));
    size_t lengthRight = strlen(pstrRight);

    // Copy the right substring to the temporary string after the inserted character
    for (int j = lengthLeft + 1, k = 0; k < lengthRight; j++, k++) {
        pTempString[j] = pstrRight[k];
    }

    // Ensure the temporary string is null-terminated
    pTempString[length + 1] = '\0';

    // Clone the temporary string to m_pstrInsert
    m_pstrInsert = CloneString(pTempString);

    // Delete the temporary string to avoid memory leaks
    DeleteString(pTempString);

    // Return the modified CSuperString with the inserted character
    return m_pstrInsert;
}

// --------------------------------------------------------------------------------
// Name: Insert
// Abstract: Inserts a specified substring into the CSuperString at the specified index.
// --------------------------------------------------------------------------------
const char* CSuperString::Insert(const char* pstrSubString, long lngIndex) {
    // Delete any existing content in m_pstrInsert
    DeleteString(m_pstrInsert);

    // Calculate the current length of the CSuperString and the length of the substring to insert
    size_t length = Length();
    size_t subStringLength = strlen(pstrSubString);

    // Check if the index is within bounds
    if (lngIndex < 0 || lngIndex > length) {
        std::cerr << "Invalid index\n";
        return nullptr;
    }

    // Allocate memory for a temporary string to build the modified string
    char* pTempString = new char[length + subStringLength + 1]; // +1 for the null terminator

    // Extract the left substring before the insertion point
    const char* pstrLeft = CloneString(Substring(0, lngIndex));
    size_t lengthLeft = strlen(pstrLeft);
    for (int j = 0; j < lengthLeft; j++) {
        pTempString[j] = pstrLeft[j];
    }

    // Copy the substring to be inserted into the temporary string
    for (int j = 0; j < subStringLength; j++) {
        pTempString[lengthLeft + j] = pstrSubString[j];
    }

    // Extract the right substring after the insertion point
    const char* pstrRight = CloneString(Substring(lngIndex, length));
    size_t lengthRight = strlen(pstrRight);
    for (int j = lengthLeft + subStringLength, k = 0; k < lengthRight; j++, k++) {
        pTempString[j] = pstrRight[k];
    }

    // Ensure the temporary string is null-terminated
    pTempString[length + subStringLength] = '\0';

    // Clone the temporary string to m_pstrInsert
    m_pstrInsert = CloneString(pTempString);

    // Delete the temporary string to avoid memory leaks
    DeleteString(pTempString);

    // Return the modified CSuperString with the inserted substring
    return m_pstrInsert;
}

// --------------------------------------------------------------------------------
// Name: Reverse
// Abstract: Reverses the characters in the CSuperString.
// --------------------------------------------------------------------------------

const char* CSuperString::Reverse() {
    DeleteString(m_pstrReversed);

    if (m_pstrSuperString == nullptr) {
        return "";  // Return an empty string if the original string is nullptr
    }

    size_t strLength = strlen(m_pstrSuperString);

    // Allocate memory for the reversed string
    char* pTempString = 0;
    pTempString = new char[strLength + 1]; // +1 for the null-terminator

    // loop through char arr storing the last index (j) into the first index (i) of new string, and iterates
    for (size_t i = 0, j = strLength - 1; i < strLength; ++i, --j) {
        // Copy characters in reverse order
        pTempString[i] = m_pstrSuperString[j];
    }

    pTempString[strLength] = '\0';  // Null-terminate the reversed string

    // allocate memory  to member variable 
    m_pstrReversed = CloneString(pTempString);

    // free allocated memory 
    DeleteString(pTempString);

    return m_pstrReversed;
}

// --------------------------------------------------------------------------------
// Name: TrimHelper
// Abstract: Trims whitespaces from the CSuperString based on the specified direction.
// --------------------------------------------------------------------------------
const char* CSuperString::TrimHelper(char*& trimmedString, int trimDirection) {
    // trimDirection: 
    // 0 is Trim()
    // 1 is TrimLeft()
    // 2 is TrimRight() 
 
    // delete mem from previous call
    DeleteString(trimmedString);

    char* tempString = CloneString(m_pstrSuperString);

    // Trim leading whitespaces if specified
    if (trimDirection == 1 || trimDirection == 0) {
        char* start = tempString;
        start = start + FindFirstNonWhitespaceIndex(start);
        // length of the new trimmed string
        size_t startLength = strlen(start);
        // Move the trimmed substring to the beginning of the string
        if (start != trimmedString) {
            // store newly trimmed string (start) into trimmedString
            trimmedString = CloneString(start);

            // if trimDirection is 0 ( Trim() ) then skip this return and trim the end as well
            // if it is 1 ( TrimLeft() ) then return value here
            if (trimDirection == 1) {
                DeleteString(tempString);
                return trimmedString;
            }
        }
    }
    // Trim trailing whitespaces if specified
    if (trimDirection == 2 || trimDirection == 0) {
        size_t startLength = strlen(tempString);
        char* end = tempString + startLength;
        end = tempString + FindLastNonWhitespaceIndex(tempString, startLength);
        // put a nullptr after the last nonwhite space character to end the array
        *(end + 1) = '\0';
        // Move the trimmed substring to the beginning of the string
        if (tempString != trimmedString) {
            // store newly trimmed string (tempString) into trimmedString
            trimmedString = CloneString(tempString);
            DeleteString(tempString);
            return trimmedString;
        }
    }
    DeleteString(tempString);
    return "";
}

// --------------------------------------------------------------------------------
// Name: Trim
// Abstract: Trims whitespaces from the CSuperString.
// --------------------------------------------------------------------------------
const char* CSuperString::Trim() {
    if (m_pstrSuperString != nullptr && strlen(m_pstrSuperString) > 0) {
        return TrimHelper(m_pstrTrim, 0);
    }
    return "";
}

// --------------------------------------------------------------------------------
// Name: TrimLeft
// Abstract: Trims leading whitespaces from the CSuperString.
// --------------------------------------------------------------------------------
const char* CSuperString::TrimLeft() {
    if (m_pstrSuperString != nullptr && strlen(m_pstrSuperString) > 0) {
        return TrimHelper(m_pstrTrimLeft, 1);
    }
    return "";
}

// --------------------------------------------------------------------------------
// Name: TrimRight
// Abstract: Trims trailing whitespaces from the CSuperString.
// --------------------------------------------------------------------------------
const char* CSuperString::TrimRight() {
    if (m_pstrSuperString != nullptr && strlen(m_pstrSuperString) > 0) {
        return TrimHelper(m_pstrTrimRight, 2);
    }
    return "";
}

// --------------------------------------------------------------------------------
// Name: Substring
// Abstract: Retrieves a substring from the CSuperString starting from the specified index.
// --------------------------------------------------------------------------------
const char* CSuperString::Substring(long lngStart, long lngSubStringLength) {
    // Deallocate any existing content in m_pstrSubstring
    DeleteString(m_pstrSubstring);

    // Make a copy of the original string to leave the original unaffected
    char* pstrSourceClone = CloneString(m_pstrSuperString);

    // Get the length of the original string (m_pstrSuperString)
    size_t originalLength = strlen(pstrSourceClone);

    // Adjust the start pointer to point to the beginning of the substring
    char* pStart = pstrSourceClone + lngStart;

    // Allocate memory for the substring
    char* pTempString = new char[lngSubStringLength + 1]; // +1 for the null-terminator

    // Copy characters to pTempString
    for (size_t i = 0; i < lngSubStringLength; ++i) {
        pTempString[i] = pStart[i];
    }

    // Null-terminate the substring
    pTempString[lngSubStringLength] = '\0';

    // Store the substring in m_pstrSubstring
    m_pstrSubstring = CloneString(pTempString);

    // Deallocate memory to avoid memory leaks
    DeleteString(pTempString);
    DeleteString(pstrSourceClone);

    // Return a pointer to the substring
    return this->m_pstrSubstring;
}

// --------------------------------------------------------------------------------
// Name: Left
// Abstract: Retrieves the left substring of the CSuperString with the specified number of characters.
// --------------------------------------------------------------------------------
CSuperString CSuperString::Left(long lngCharactersToCopy) {

    CSuperString ssLeft; 

    ssLeft = Substring(0, lngCharactersToCopy); 

    return ssLeft; 

}

// --------------------------------------------------------------------------------
// Name: Right
// Abstract: Retrieves the right substring of the CSuperString with the specified number of characters.
// --------------------------------------------------------------------------------
const char* CSuperString::Right(long lngCharactersToCopy) {
    DeleteString(m_pstrRight);

    // Ensure lngCharactersToCopy is not negative
    if (lngCharactersToCopy < 0) {
        // Handle invalid input as needed, e.g., return an error code or throw an exception
        return "";
    }

    char* stringCopy = CloneString(m_pstrSuperString);
    size_t lengthOfString = strlen(stringCopy);

    // Calculate the start index for the substring
    long lngStartIndex = lengthOfString - lngCharactersToCopy;

    const char* tempString = Substring(lngStartIndex, lngCharactersToCopy);

    // Call Substring with corrected parameters
    m_pstrRight = CloneString(tempString);

    // Clean up temporary memory
    DeleteString(stringCopy);

    return m_pstrRight;
}

// --------------------------------------------------------------------------------
// Name: FindFirstNonWhitespaceIndex
// Abstract: Finds the index of the first non-whitespace character in the given string.
// --------------------------------------------------------------------------------
long CSuperString::FindFirstNonWhitespaceIndex(const char* str) const {
    for (long i = 0; str[i] != '\0'; ++i) {
        if (!std::isspace(str[i])) {
            return i;
        }
    }
    return -1;  // No non-whitespace character found
}

// --------------------------------------------------------------------------------
// Name: FindLastNonWhitespaceIndex
// Abstract: Finds the index of the last non-whitespace character in the given string, up to a specified maximum length.
// --------------------------------------------------------------------------------
long CSuperString::FindLastNonWhitespaceIndex(const char* pStr, long lngMaxLength) const {
    long lngLastIndex = -1;
    for (long i = 0; i < lngMaxLength && pStr[i] != '\0'; ++i) {
        if (!std::isspace(pStr[i])) {
            lngLastIndex = i;
        }
    }
    return lngLastIndex;
}

#pragma endregion

#pragma region Subscript Operator DONE
// --------------------------------------------------------------------------------
// Name: Subscript Operator
// Abstract: Overloads the subscript operator for both const and non-const contexts.
// --------------------------------------------------------------------------------
   // Const version of subscript operator overloading
const char& CSuperString::operator [ ] (long lngIndex) const {
    if (lngIndex >= 0 && m_pstrSuperString[lngIndex] != '\0') {
        return m_pstrSuperString[lngIndex];
    }
    else {
        // Handle out-of-bounds access or null terminator
        std::cerr << "Index out of bounds or null terminator reached.\n";
        return '\0';  // Return null character or handle it differently
    }
}

// Non-const version of subscript operator overloading
 char& CSuperString::operator [ ] (long lngIndex)  {
    if (lngIndex >= 0 && m_pstrSuperString[lngIndex] != '\0') {
        return m_pstrSuperString[lngIndex];
    }
    else {
        // Handle out-of-bounds access or null terminator
        std::cerr << "Index out of bounds or null terminator reached.\n";
        // You might choose to throw an exception or handle it differently in a non-const context
        // For simplicity, returning a reference to a static variable here, which is not a good practice.
        static char nullChar = '\0';
        return nullChar;
    }
}
#pragma endregion

#pragma region To<DataType> DONE

 // --------------------------------------------------------------------------------
 // Name: ToString
 // Abstract: Returns the C-style string representation of the CSuperString.
 // --------------------------------------------------------------------------------

const char* CSuperString::ToString() const {
    
    // throws error for << overload nullptr is passed
    if (m_pstrSuperString != nullptr) { 
        return m_pstrSuperString;
    }
    return "";    
}

// --------------------------------------------------------------------------------
// Name: ToBoolean
// Abstract: Converts the CSuperString to a boolean value.
// --------------------------------------------------------------------------------
bool CSuperString::ToBoolean() {
    bool blnValue = false;

    // True or 1?
    if (_stricmp(ToLowerCase(), "true") == 0 || _stricmp(m_pstrSuperString, "1") == 0) {
        blnValue = true;
    }

    return blnValue;
}

// --------------------------------------------------------------------------------
// Name: ToShort
// Abstract: Converts the CSuperString to a short integer.
// --------------------------------------------------------------------------------
short CSuperString::ToShort() {
    short shtValue = 0;

    shtValue = (short) atoi( m_pstrSuperString );

    return shtValue;
}

// --------------------------------------------------------------------------------
// Name: ToInteger
// Abstract: Converts the CSuperString to an integer.
// --------------------------------------------------------------------------------
int CSuperString::ToInteger() {
    int intValue = 0;

    intValue = (int) atoi(m_pstrSuperString);

    return intValue;
}

// --------------------------------------------------------------------------------
// Name: ToLong
// Abstract: Converts the CSuperString to a long integer.
// --------------------------------------------------------------------------------
long CSuperString::ToLong() {
    long lngValue = 0;

    lngValue = (long) atoi(m_pstrSuperString);

    return lngValue;
}

// --------------------------------------------------------------------------------
// Name: ToFloat
// Abstract: Converts the CSuperString to a float.
// --------------------------------------------------------------------------------
float CSuperString::ToFloat() {
    float floatValue = strtof(m_pstrSuperString, nullptr);
    return floatValue;
}

// --------------------------------------------------------------------------------
// Name: ToDouble
// Abstract: Converts the CSuperString to a double.
// --------------------------------------------------------------------------------
double CSuperString::ToDouble() {
    double dblValue = strtod(m_pstrSuperString, nullptr);
    return dblValue;
}

#pragma endregion

#pragma region "io/os stream  >> / << Operator Overloads DONE"
// --------------------------------------------------------------------------------
// Name: << Operator   
// Abstract: Overloaded << operator for CSuperString, outputs its string representation
// --------------------------------------------------------------------------------

//  Operator << CSuperSTring& 
std::ostream& operator<<(std::ostream& os, const CSuperString& ssRight) {
    os << ssRight.ToString();
    return os;
}

// Operator >> CSuperString&
std::istream& operator >> (std::istream& isIn, CSuperString& ssInput) {
    ssInput.ReadFromStream(isIn); 
    return isIn;
}

// ----------------------------------------------------------------------------
// Name: ReadFromStream
// Abstract: Reads a line from the specified input stream and updates the
//           CSuperString object with the contents of the read line.
// ----------------------------------------------------------------------------
void CSuperString::ReadFromStream(std::istream& isIn) {
    // free the existing memory
    DeleteString(m_pstrSuperString);

    // Read a line from the input stream
    char buffer[256];  // Adjust the buffer size as needed
    isIn.getline(buffer, sizeof(buffer));

    // Use DeepCopy to set obj = buffer
    DeepCopy(buffer);
}

#pragma endregion

#pragma region "Comparison == Operator Overloads DONE"
// --------------------------------------------------------------------------------
// Name: operator== (CSuperString)
// Abstract: Compares the CSuperString with another CSuperString for equality.
// --------------------------------------------------------------------------------
bool CSuperString::operator==(const CSuperString& other) const {
    if (strcmp(m_pstrSuperString, other.m_pstrSuperString) == 0) {
        return true;
    }
    else {
        return false;
    }
}

// --------------------------------------------------------------------------------
// Name: operator== (const char*)
// Abstract: Compares the CSuperString with a C-style string for equality.
// --------------------------------------------------------------------------------
bool CSuperString::operator==(const char* pstr) const {
    if (strcmp(m_pstrSuperString, pstr) == 0) {
        return true;
    }
    else {
        return false;
    }
}

// --------------------------------------------------------------------------------
// Name: operator== (char)
// Abstract: Compares the CSuperString with a single character for equality.
// --------------------------------------------------------------------------------
bool CSuperString::operator==(char ch) const {
    if (strlen(m_pstrSuperString) == 1 && m_pstrSuperString[0] == ch) {
        return true;
    }
    else {
        return false;
    }
}
#pragma endregion

#pragma region "Not Equal != Operator Overloads DONE"

// --------------------------------------------------------------------------------
// Name: operator!= (CSuperString)
// Abstract: Compares the CSuperString with another CSuperString for inequality.
// --------------------------------------------------------------------------------
bool CSuperString::operator!=(const CSuperString& other) const {
    return !(*this == other);  // Utilize the existing operator== implementation
}

// --------------------------------------------------------------------------------
// Name: operator!= (const char*)
// Abstract: Compares the CSuperString with a C-style string for inequality.
// --------------------------------------------------------------------------------
bool CSuperString::operator!=(const char* pstr) const {
    return !(*this == pstr);  // Utilize the existing operator== implementation
}

// --------------------------------------------------------------------------------
// Name: operator!= (char)
// Abstract: Compares the CSuperString with a single character for inequality.
// --------------------------------------------------------------------------------
bool CSuperString::operator!=(char ch) const {
    return !(*this == ch);  // Utilize the existing operator== implementation
}
#pragma endregion

#pragma region "Greater Than > Operator Overloads DONE"

// --------------------------------------------------------------------------------
// Name: operator> (CSuperString)
// Abstract: Compares the CSuperString with another CSuperString to check if it's greater.
// --------------------------------------------------------------------------------
bool CSuperString::operator>(const CSuperString& other) const {
    return Length() > other.Length();
}

// --------------------------------------------------------------------------------
// Name: operator> (const char*)
// Abstract: Compares the CSuperString with a C-style string to check if it's greater.
// --------------------------------------------------------------------------------
bool CSuperString::operator>(const char* pstr) const {
    return Length() > strlen(pstr);
}

// --------------------------------------------------------------------------------
// Name: operator> (char)
// Abstract: Compares the CSuperString with a single character to check if it's greater.
// --------------------------------------------------------------------------------
bool CSuperString::operator>(char ch) const {
    return Length() > 1; // Assuming Length() returns the actual length of the string
}
#pragma endregion

#pragma region "Less Than < Operator Overloads DONE"

// --------------------------------------------------------------------------------
// Name: operator< (CSuperString)
// Abstract: Compares the CSuperString with another CSuperString to check if it's less.
// --------------------------------------------------------------------------------
bool CSuperString::operator<(const CSuperString& other) const {
    return Length() < other.Length();
}

// --------------------------------------------------------------------------------
// Name: operator< (const char*)
// Abstract: Compares the CSuperString with a C-style string to check if it's less.
// --------------------------------------------------------------------------------
bool CSuperString::operator<(const char* pstr) const {
    return Length() < strlen(pstr);
}

// --------------------------------------------------------------------------------
// Name: operator< (char)
// Abstract: Compares the CSuperString with a single character to check if it's less.
// --------------------------------------------------------------------------------
bool CSuperString::operator<(char ch) const {
    return Length() < 1; // Assuming Length() returns the actual length of the string
}
#pragma endregion

#pragma region "Greater Than or Equal To >= Operator Overloads DONE"

// --------------------------------------------------------------------------------
// Name: operator>= (CSuperString)
// Abstract: Compares the CSuperString with another CSuperString to check if it's greater than or equal.
// --------------------------------------------------------------------------------
bool CSuperString::operator>=(const CSuperString& other) const {
    return Length() >= other.Length();
}

// --------------------------------------------------------------------------------
// Name: operator>= (const char*)
// Abstract: Compares the CSuperString with a C-style string to check if it's greater than or equal.
// --------------------------------------------------------------------------------
bool CSuperString::operator>=(const char* pstr) const {
    return Length() >= strlen(pstr);
}

// --------------------------------------------------------------------------------
// Name: operator>= (char)
// Abstract: Compares the CSuperString with a single character to check if it's greater than or equal.
// --------------------------------------------------------------------------------
bool CSuperString::operator>=(char ch) const {
    return Length() >= 1; // Assuming Length() returns the actual length of the string
}

#pragma endregion

#pragma region "Less Than or Equal To <= Operator Overloads DONE"

// --------------------------------------------------------------------------------
// Name: operator<= (CSuperString)
// Abstract: Compares the CSuperString with another CSuperString to check if it's less than or equal.
// --------------------------------------------------------------------------------
bool CSuperString::operator<=(const CSuperString& other) const {
    return Length() <= other.Length();
}

// --------------------------------------------------------------------------------
// Name: operator<= (const char*)
// Abstract: Compares the CSuperString with a C-style string to check if it's less than or equal.
// --------------------------------------------------------------------------------
bool CSuperString::operator<=(const char* pstr) const {
    return Length() <= strlen(pstr);
}

// --------------------------------------------------------------------------------
// Name: operator<= (char)
// Abstract: Compares the CSuperString with a single character to check if it's less than or equal.
// --------------------------------------------------------------------------------
bool CSuperString::operator<=(char ch) const {
    return Length() <= 1; // Assuming Length() returns the actual length of the string
}
#pragma endregion

#pragma region Print 
// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Prints the CSuperString with an optional caption to the console.
// --------------------------------------------------------------------------------

void CSuperString::Print(const char* pstrCaption) const {
    // Caption
    std::cout << "\n" << pstrCaption << "\n";
    std::cout << "----------------------------------\n";

    // Length not 0?
    if (Length() > 0) {
        // Yes, print string
        std::cout << m_pstrSuperString << "\n";
    }
    else {
        // No, print empty string
        std::cout << "-Empty string\n";
    }

    std::cout << "\n";
}
#pragma endregion 
