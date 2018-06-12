void Combination(char *string ,int number,vector<char> &result);

void Combination(char *string)
{
    assert(string != NULL);
    vector<char> result;
    int i , length = strlen(string);
    for(i = 1 ; i <= length ; ++i)
        Combination(string , i ,result);
}

void Combination(char *string ,int number , vector<char> &result)
{
    assert(string != NULL);
    if(number == 0)
    {
        static int num = 1;
        printf("第%d个组合\t",num++);

        vector<char>::iterator iter = result.begin();
        for( ; iter != result.end() ; ++iter)
            printf("%c",*iter);
        printf("\n");
        return ;
    }
    if(*string == '\0')
        return ;
    result.push_back(*string);
    Combination(string + 1 , number - 1 , result);
    result.pop_back();
    Combination(string + 1 , number , result);
}
int main(void)
{
    char str[] = "abc";
    Combination(str);
    return 0;
}
