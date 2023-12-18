#pragma once
#include <ostream>
#include <iostream>
using namespace std; 

// --------------------------------------------------------------------------------
// Class: CSuperString 
// --------------------------------------------------------------------------------
class CSuperString
{

private:
	char* m_pstrSuperString;
	char* m_pstrUpperCase;
	char* m_pstrLowerCase;
	char* m_pstrTrimLeft;
	char* m_pstrTrimRight;
	char* m_pstrTrim;
	char* m_pstrReversed;
	char* m_pstrLeft;
	char* m_pstrRight;
	char* m_pstrSubstring;
	char* m_pstrInsert;
	char* m_pstrReplace;


public:
	// Constructors
	CSuperString();
	// Parameterized/Copy constructors
	// CSuperString ssBuffer( "I Love Star Trek" );
	// CSuperString ssBuffer( 3.14159f );
	CSuperString(const char* pstrStringToCopy);
	CSuperString(const bool blnBooleanToCopy);
	CSuperString(const char chrLetterToCopy);
	CSuperString(const short shtShortToCopy);
	CSuperString(const int intIntegerToCopy);
	CSuperString(const long lngLongToCopy);
	CSuperString(const float sngFloatToCopy);
	CSuperString(const double dblDoubleToCopy);
	CSuperString(const CSuperString &ssStringToCopy);

	// Constructor Helper / Created Methods 
	void Initialize(const char* pstrSource);
	void DeleteString(char*& pstrSource); 
	void DeepCopy(const char* pstrSource);
	char* CloneString( const char* pstrSource);
	virtual ~CSuperString();
	void Cleanup();
	long Length() const;
	void Append(const CSuperString& ssOther);
	void ReadFromStream(std::istream& isIn);




	// Assignment Operators
	void operator = (const char* pstrStringToCopy);
	void operator = (const char chrLetterToCopy);
	void operator = (const CSuperString &ssStringToCopy);
	// Extra credit for numeric parameters

	// Concatenate operator
	void operator += (const char* pstrStringToAppend);
	void operator += (const char chrCharacterToAppend);
	void operator += (const CSuperString &ssStringToAppend);
	// Extra credit for numeric parameters

	friend CSuperString operator + (const CSuperString &ssLeft, const CSuperString &ssRight);
	friend CSuperString operator + (const char* pstrLeftSide, const CSuperString &ssRightString);
	friend CSuperString operator + (const CSuperString &ssLeftString, const char* pstrRightSide);


	long FindFirstIndexOf(const char chrLetterToFind) const;
	long FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex) const;
	long FindLastIndexOf(const char chrLetterToFind) const;

	long FindFirstIndexOf(const char* pstrSubStringToFind) const;
	long FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex) const;
	long FindLastIndexOf(const char* pstrSubStringToFind) const; 

	// Do not change original string.  For example:
	// cout << ssBuffer.ToString( ) << endl;		// I Love Star Trek
	// cout << ssBuffer.ToUpperCase( ) << endl;	// I LOVE STAR TREK
	// cout << ssBuffer.ToString( ) << endl;		// I Love Star Trek
	const char* ToUpperCase();
	const char* ToLowerCase();
	const char* TrimHelper(char* &trimmedString, int trimDirection);
	const char* TrimLeft();
	const char* TrimRight();
	const char* Trim();
	const char* Reverse();

	CSuperString Left(long lngCharactersToCopy);
	const char* Right(long lngCharactersToCopy);
	const char* Substring(long lngStart, long lngSubStringLength);

	long FindFirstNonWhitespaceIndex(const char* str) const;
	long FindLastNonWhitespaceIndex(const char* str, long maxLength) const;

	const char* Replace(char chrLetterToFind, char chrReplace);
	// Hard
	const char* Replace(const char* pstrFind, const char* pstrReplace);
	const char* Insert(const char chrLetterToInsert, long lngIndex);
	const char* Insert(const char* pstrSubString, long lngIndex);



	// Subscript operator
	char& operator [ ] (long lngIndex);
	const char& operator [ ] (long lngIndex) const;

	const char* ToString() const;
	bool ToBoolean();
	short ToShort();
	int ToInteger();
	long ToLong();
	float ToFloat();
	double ToDouble();

	void Print(const char* pstrCaption) const;


	// cin >> ssBuffer;
	// cout << ssBuffer;

	// right side CSuperString&
	friend std::ostream &operator<<(std::ostream &os, const CSuperString &ssRight);
	friend std::istream &operator >> (std::istream &isIn, CSuperString &ssInput);

	// Don’t forget the comparison operators!!!
	// 
	 // Comparison operators
	bool operator==(const CSuperString& other) const;
	bool operator==(const char* pstr) const;
	bool operator==(char ch) const;

	// operator!= Overload for CSuperString
	bool operator!=(const CSuperString& other) const;
	bool operator!=(const char* pstr) const;
	bool operator!=(char ch) const;

	// operator> Overload for CSuperString
	bool operator>(const CSuperString& other) const;
	bool operator>(const char* pstr) const;
	bool operator>(char ch) const;

	// operator< Overload for CSuperString
	bool operator<(const CSuperString& other) const;
	bool operator<(const char* pstr) const;
	bool operator<(char ch) const;

	// operator>= Overload for CSuperString
	bool operator>=(const CSuperString& other) const;
	bool operator>=(const char* pstr) const;
	bool operator>=(char ch) const;

	// operator<= Overload for CSuperString
	bool operator<=(const CSuperString& other) const;
	bool operator<=(const char* pstr) const;
	bool operator<=(char ch) const;
};



// rest of operators 
// replace, insert, print, test for memory leakage 
