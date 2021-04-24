#include <bits/stdc++.h>
using namespace std;
int point;
bool Verify_binary_number(string value)
{
    point = 0;
    int i;
    for (i = 0; i < value.size(); i++)
    {
        if (value[i] == '.')
        {
            point++;
        }
        if (value[i] != '1' && value[i] != '0' && value[i] != '.')
        {
            point = 100;
        }
    }
    if (point > 1)
    {
        cout << "The Number is not an Binary Number" << endl;
        return false;
    }
    return true;
}
bool Verify_octal_number(string value)
{
    int point = 0;
    int i;
    for (i = 0; i < value.size(); i++)
    {
        if (value[i] == '.')
        {
            point++;
        }
        if (!(value[i] >= '0' && value[i] <= '7') && value[i] != '.')
        {
            point = 100;
        }
    }
    if (point > 1)
    {
        cout << "The Number is not an Octal Number" << endl;
        return false;
    }
    return true;
}
bool Verify_decimal_number(string value)
{
    int point = 0;
    int i;
    for (i = 0; i < value.size(); i++)
    {
        if (value[i] == '.')
        {
            point++;
        }
        if (!(value[i] >= '0' && value[i] <= '9') && value[i] != '.')
        {
            point = 100;
        }
    }
    if (point > 1)
    {
        cout << "The Number is not an Decimal Number" << endl;
        return false;
    }
    return true;
}
bool Verify_hexadecimal_number(string value)
{
    int point = 0;
    int i;
    for (i = 0; i < value.size(); i++)
    {
        if (value[i] == '.')
        {
            point++;
        }
        if (!(value[i] >= '0' && value[i] <= '9') && !(value[i] >= 'A' && value[i] <= 'F') && value[i] != '.')
        {
            point = 100;
        }
    }
    if (point > 1)
    {
        cout << "The Number is not an Hexadecimal Number" << endl;
        return false;
    }
    return true;
}
bool Verify_number(string value, int a)
{
    bool res;
    if (a == 1)
    {
        res = Verify_binary_number(value);
    }
    if (a == 2)
    {
        res = Verify_octal_number(value);
    }
    if (a == 3)
    {
        res = Verify_decimal_number(value);
    }
    if (a == 4)
    {
        res = Verify_hexadecimal_number(value);
    }
    return res;
}