/*
* Question Description:
* (Question 12 in <Coding Intervies>) How do you check whether a string stands for a number or not?
* Numbers include positive and negative integers and floats. For example, strings "+100.", "5e2", "-.123", "3.1416", and "-1E-16"
* stand for numbers, but "12e", "1a3.14", "1.2.3", "+-5", and "12e+5.4" do not.
*/

#include <stdio.h>

bool scanDigits(char** str);
bool isExponential(char** str);

bool isNumeric(char* str)
{
    if (str == NULL)
        return false;

    if (*str == '+' || *str == '-')
        ++str;
    if (*str == '\0')
        return false;

    bool numeric = true;

    bool hasDigits = scanDigits(&str);
    if (*str != '\0')
    {
        // for floats
        if (*str == '.')
        {
            ++str;
            if (*str == 'e' || *str == 'E')
                return false;
            if (!hasDigits && *str == '\0')
                return false;

            scanDigits(&str);

            if (*str == 'e' || *str == 'E')
                numeric = isExponential(&str);
        }
        // for integers
        else if (*str == 'e' || *str == 'E')
            numeric = isExponential(&str);
        else
            numeric = false;
    }

    return numeric && *str == '\0';
}

bool scanDigits(char** str)
{
    char* pBefore = *str;

    while (**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);

    // return true when there are some digits in str
    return *str > pBefore;
}

bool isExponential(char** str)
{
    if (**str != 'e' && **str != 'E')
        return false;

    ++(*str);
    if (**str == '+' || **str == '-')
        ++(*str);

    if (**str == '\0')
        return false;

    scanDigits(str);
    return (**str == '\0') ? true : false;
}

// ==================== Test Code ====================

void Test(char* testName, char* str, bool expected)
{
    if (testName != NULL)
        printf("%s begins: ", testName);

    if (isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "+.", false);

    return 0;
}
