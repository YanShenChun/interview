#include <stdio.h>

enum Status {kValid = 0, kInvalid};
int g_nStatus = kValid;

long long StrToIntCore(const char*, bool);

int StrToInt(const char *str)
{
    g_nStatus = kInvalid;
    long long num = 0;

    if (str != NULL && *str != '\0')
    {
        bool minus = false;
        if (*str == '+')
            str++;
        else if (*str == '-')
        {
            str++;
            minus = true;
        }

        if (*str != '\0')
        {
            num = StrToIntCore(str, minus);
        }
    }

    return (int)num;
}

long long StrToIntCore(const char *digit, bool minus)
{
    long long num = 0;

    while (*digit != '\0')
    {
        if (*digit >= 0 && *digit <= '9')
        {
            int flag = minus? -1 : 1;
            num = num * 10 + flag * (*digit - '0');

            if ((!minus && num > 0x7FFFFFFF)
                || (minus && num < (signed int)0x80000000))
                {
                    num = 0;
                    break;
                }

            digit++;
        }
        else
        {
            num = 0;
            break;
        }
    }

    if (*digit == '\0')
    {
        g_nStatus = kValid;
    }

    return num;
}

// -----------------------testing code ------------------
void Test(char *string)
{
    int result = StrToInt(string);

    if (result == 0 && g_nStatus == kInvalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

int main()
{
    Test(NULL);
    Test("");
    Test("123");
    Test("+123");
    Test("-123");
    Test("1a33");
    Test("+0");
    Test("-0");

    Test("+12313213131313");
    Test("-12213324343244");

    Test("+");
    Test("-");

    return 0;
}
