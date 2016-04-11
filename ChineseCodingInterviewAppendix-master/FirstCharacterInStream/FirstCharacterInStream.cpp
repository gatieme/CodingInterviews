/* 
 * Question Description:
 * (Question 77 in <Coding Intervies>) Implement a function to find the first character in a stream that 
 * only appears once at any time while reading the stream. For example, when the first two characters “go” 
 * are read from a stream, the first character which appears once is the character ‘g’. When the first 
 * six characters “google” are read, the first character appearing only once is ‘l’.
*/

#include <vector>
#include <limits>

using namespace std;

class CharStatistics
{
public:
    CharStatistics() : index (0)
    {
        for(int i = 0; i < 256; ++i)
            occurrence[i] = -1;
    }
    
    void Insert(char ch)
    {
        if(occurrence[ch] == -1)
            occurrence[ch] = index;
        else if(occurrence[ch] >= 0)
            occurrence[ch] = -2;  
        
        index++;  
    }
    
    char FirstAppearingOnce()
    {
        char ch = '\0';
        int minIndex = numeric_limits<int>::max();
        for(int i = 0; i < 256; ++i)
        {
            if(occurrence[i] >= 0 && occurrence[i] < minIndex)
            {
                ch = (char)i;
                minIndex = occurrence[i];
            }
        }
        
        return ch;
    }
    
private:
    // occurrence[i]: A character with ASCII value i;
    // occurrence[i] = -1: The character has not found;
    // occurrence[i] = -2: The character has been found for mutlple times
    // occurrence[i] >= 0: The character has been found only once
    int occurrence[256];
    int index;
};

// ==================== Test Code ====================
void Test(char* testName, CharStatistics chars, char expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(chars.FirstAppearingOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    CharStatistics chars;

    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

	return 0;
}
