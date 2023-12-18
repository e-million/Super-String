# SuperString

## Project Overview

The SuperString project is a C++ implementation of the `CSuperString` class, emphasizing various methods for string manipulation. 

## Instructions and Guidelines

### Class Implementation

1. **Class Header File:**
   - Implement the necessary class header file, including the corresponding cpp file.

2. **Additional Properties and Methods:**
   - You may add any other properties and/or methods as needed. Consult with the instructor before adding new elements to ensure alignment with the project requirements.

3. **Main Function:**
   - Write a main function to test all the different methods.
   - Ensure readability by using regions and procedures to break up the logic.
   - Comment out calls to previously made procedures to facilitate focused testing.

4. **String Functions:**
   - You are allowed to use any standard string functions (e.g., strlen, strstr, etc.).
   - The built-in String class is not permitted.

5. **Operator Overloading:**
   - Overload the following operators with all reasonable parameters: ==, !=, >, <, >=, <=.

6. **Class Method Restrictions:**
   - None of the class methods (except constructors and assignment operators) should change `m_pstrSuperString`.
   - Assign the value back to the class instance to make it permanent.

### Evaluation and Grading Criteria

- **Memory Leaks:**
  - Minus one letter grade for any memory leak.
  - Minus two letter grades for a significant number of memory leaks.

- **Method Functionality:**
  - Minus one letter grade if `replace` with substrings doesn't work correctly.
  - Minus one letter grade if self-assignment doesn’t work correctly (e.g., `ssBuffer = ssBuffer.ToUpperCase()`).

- **Double Call Problem:**
  - Minus one letter grade if the double call problem is not solved.


## Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/SuperStringProject.git
