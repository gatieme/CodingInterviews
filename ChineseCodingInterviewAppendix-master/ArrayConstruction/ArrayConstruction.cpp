/* 
 * Question Description:
 * (Question 105 in <Coding Intervies>) Given an array A[0, 1, …, n-1], please construct an array 
 * B[0, 1, …, n-1] in which B[i]=A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]. No division should be 
 * involved to solve this problem. 
*/

#include <vector>
#include <stdio.h>

using namespace std;

void multiply(const vector<double>& array1, vector<double>& array2)
{
    int length1= array1.size();
    int length2 = array2.size();

    if(length1 == length2 && length2 > 1)
    {
        array2[0] = 1;
        for(int i = 1; i < length1; ++i)
        {
            array2[i] = array2[i - 1] * array1[i - 1];
        }
            
        double temp = 1;
        for(int i = length1 - 2; i >= 0; --i)
        {
            temp *= array1[i + 1];
            array2[i] *= temp;
        }
    }
}
    
//================= Test Code =================
static bool equalArrays(const vector<double>& array1, const vector<double>& array2)
{
    int length1= array1.size();
    int length2 = array2.size();

    if(length1 != length2)
        return false;
        
    for(int i = 0; i < length1; ++i)
    {
        if(abs(array1[i] - array2[i]) > 0.0000001)
            return false;
    }
        
    return true;
}

static void test(char* testName, const vector<double>& array1, vector<double>& array2, const vector<double>& expected){
    printf("%s Begins: ", testName);
        
    multiply(array1, array2);
    if(equalArrays(array2, expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}
    
static void test1()
{
    double array1[] = {1, 2, 3, 4, 5};
    double array2[] = {0, 0, 0, 0, 0};
    double expected[] = {120, 60, 40, 30, 24};
        
    test("Test1", vector<double>(array1, array1 + sizeof(array1) / sizeof(double)), 
        vector<double>(array2, array2 + sizeof(array2) / sizeof(double)), 
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}
    
static void test2()
{
    double array1[] = {1, 2, 0, 4, 5};
    double array2[] = {0, 0, 0, 0, 0};
    double expected[] = {0, 0, 40, 0, 0};
        
    test("Test2", vector<double>(array1, array1 + sizeof(array1) / sizeof(double)), 
        vector<double>(array2, array2 + sizeof(array2) / sizeof(double)), 
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}
    
static void test3()
{
    double array1[] = {1, 2, 0, 4, 0};
    double array2[] = {0, 0, 0, 0, 0};
    double expected[] = {0, 0, 0, 0, 0};
        
    test("Test3", vector<double>(array1, array1 + sizeof(array1) / sizeof(double)), 
        vector<double>(array2, array2 + sizeof(array2) / sizeof(double)), 
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}
    
static void test4()
{
    double array1[] = {1, -2, 3, -4, 5};
    double array2[] = {0, 0, 0, 0, 0};
    double expected[] = {120, -60, 40, -30, 24};
        
    test("Test4", vector<double>(array1, array1 + sizeof(array1) / sizeof(double)), 
        vector<double>(array2, array2 + sizeof(array2) / sizeof(double)), 
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}
    
static void test5()
{
    double array1[] = {1, -2};
    double array2[] = {0, 0};
    double expected[] = {-2, 1};
        
    test("Test5", vector<double>(array1, array1 + sizeof(array1) / sizeof(double)), 
        vector<double>(array2, array2 + sizeof(array2) / sizeof(double)), 
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}
    
void main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}
