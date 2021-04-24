#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
char get_char(int rem);
string to_decimal(string value, int base)
{
    int resultA = 0;
    double resultB = 0;
    int power = 0;
    string result;
    int i;
    int index;
    bool is_float = false;
    for (i = 0; i < value.size(); i++)
    {
        if (value[i] == '.')
        {
            index = i;
            is_float = true;
            break;
        }
        is_float = false;
    }
    if (is_float)
    {
        for (i = index - 1; i >= 0; i--)
        {
            if (value[i] >= '0' && value[i] <= '9')
            {
                resultA += (value[i] - '0') * pow(base, power);
                power++;
            }
            else if (value[i] >= 'A' && value[i] <= 'F')
            {
                resultA += ((value[i] - 'A') + 10) * pow(base, power);
                power++;
            }
        }
        power = -1;
        for (i = index + 1; i < value.size(); i++)
        {
            if (value[i] >= '0' && value[i] <= '9')
            {
                resultB += (value[i] - '0') * pow(base, power);
                power--;
            }
            else if (value[i] >= 'A' && value[i] <= 'F')
            {
                resultB += ((value[i] - 'A') + 10) * pow(base, power);
                power--;
            }
        }
        result = to_string(resultA + resultB);
        return result;
    }
    else
    {
        for (i = value.size() - 1; i >= 0; i--)
        {
            if (value[i] >= '0' && value[i] <= '9')
            {
                resultA += (value[i] - '0') * pow(base, power);
                power++;
            }
            else if (value[i] >= 'A' && value[i] <= 'F')
            {
                resultA += ((value[i] - 'A') + 10) * pow(base, power);
                power++;
            }
        }
        result = to_string(resultA);
        return result;
    }
}
string from_decimal(string value, int base)
{
    string resultA;
    string resultB;
    string result;
    string temp;
    char ch;
    float converted_value = stof(value);
    int i;
    int rem;
    bool is_float = false;
    for (i = 0; i < value.size(); i++)
    {
        if (value[i] == '.')
        {
            is_float = true;
            break;
        }
        is_float = false;
    }
    if (is_float)
    {
        int integral_converted_value = int(converted_value);
        float float_converted_value = converted_value - integral_converted_value;
        i = 0;
        while (integral_converted_value != 0)
        {
            rem = (int)integral_converted_value % base;
            ch = get_char(rem);
            temp.push_back(ch);
            integral_converted_value /= base;
            i++;
        }
        for (i = temp.size() - 1; i >= 0; i--)
        {
            resultA.push_back(temp[i]);
        }
        i = 0;
        while (!(i < 7) || float_converted_value != 0)
        {
            float_converted_value *= base;
            rem = int(float_converted_value);
            ch = get_char(rem);
            resultB.push_back(ch);
            float_converted_value -= rem;
            i++;
        }
        for (i = 0; i < resultA.size(); i++)
        {
            result.push_back(resultA[i]);
        }
        result.push_back('.');
        for (i = 0; i < resultB.size(); i++)
        {
            result.push_back(resultB[i]);
        }
        return result;
    }
    else
    {
        i = 0;
        while (converted_value != 0)
        {
            rem = (int)converted_value % base;
            char ch = get_char(rem);
            temp.push_back(ch);
            converted_value = int(converted_value / base);
            i++;
        }
        for (i = temp.size() - 1; i >= 0; i--)
        {
            resultA.push_back(temp[i]);
        }
        return resultA;
    }
}
char get_char(int rem)
{
    if (rem >= 0 && rem <= 9)
    {
        return (char)(rem+48);
    }
    else if (rem == 10)
    {
        return 'A';
    }
    else if (rem == 11)
    {
        return 'B';
    }
    else if (rem == 12)
    {
        return 'C';
    }
    else if (rem == 13)
    {
        return 'D';
    }
    else if (rem == 14)
    {
        return 'E';
    }
    else if (rem == 15)
    {
        return 'F';
    }
    return 'Q';
}