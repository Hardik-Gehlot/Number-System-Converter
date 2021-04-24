#include <windows.h>
#include "Conversion.cpp"
#include "Verify.cpp"
using namespace std;
void show_menu();
void loop(int, int);
string input_value(int);
int close_loop(int, int);
int main()
{
    int a, b, c = 0;
    bool option = false;
    show_menu();
    while (option == false)
    {
        cout << "From: ";
        cin >> a;
        cout << "To: ";
        cin >> b;
        if (a > 0 && a <= 4 && b > 0 && b <= 4)
        {
            option = true;
            loop(a, b);
        }
        else
        {
            cout << "Invalid options" << endl;
            option = false;
        }
    }
    while (c != 3)
    {
        c = close_loop(a, b);
    }
    return 0;
}
void show_menu()
{
    system("cls");
    cout << "               +------------------------------------+" << endl;
    cout << "               |               NUMBER               |" << endl;
    cout << "               |               SYSTEM               |" << endl;
    cout << "               |              CONVERTOR             |" << endl;
    cout << "               +------------------------------------+" << endl;
    cout << endl;
    cout << endl;
    cout << "-+-+-+-+-+-+ Choose from the below number systems +-+-+-+-+-+-" << endl;
    cout << "+---------------+" << endl;
    cout << "| 1.Binary      |" << endl;
    cout << "| 2.Octal       |" << endl;
    cout << "| 3.Decimal     |" << endl;
    cout << "| 4.Hexadecimal |" << endl;
    cout << "+---------------+" << endl;
}
void loop(int a, int b)
{
    string value = input_value(a);
    string converted_value;
    int base;
    int base2;
    bool verified = Verify_number(value, a);
    if (verified)
    {
        if (a == b)
        {
            if (verified)
            {
                if (a == 1)
                {
                    cout << "Binary Conversion is: " << value << endl;
                }
                if (a == 2)
                {
                    cout << "Octal Conversion is: " << value << endl;
                }
                if (a == 3)
                {
                    cout << "Decimal Conversion is: " << value << endl;
                }
                if (a == 4)
                {
                    cout << "Hexadecimal Conversion is: " << value << endl;
                }
            }
        }
        else
        {
            switch (a)
            {
            case 1:

                base = 2;
                if (b == 2)
                {
                    converted_value = to_decimal(value, base);
                    converted_value = from_decimal(converted_value, 8);
                    break;
                }
                if (b == 3)
                {
                    converted_value = to_decimal(value, base);
                    break;
                }
                if (b == 4)
                {
                    converted_value = to_decimal(value, base);
                    converted_value = from_decimal(converted_value, 16);
                    break;
                }

            case 2:

                base = 8;
                if (b == 1)
                {
                    converted_value = to_decimal(value, base);
                    converted_value = from_decimal(converted_value, 2);
                    break;
                }
                if (b == 3)
                {
                    converted_value = to_decimal(value, base);
                    break;
                }
                if (b == 4)
                {
                    converted_value = to_decimal(value, base);
                    converted_value = from_decimal(converted_value, 16);
                    break;
                }

            case 3:

                if (b == 1)
                {
                    converted_value = from_decimal(value, 2);
                    break;
                }
                if (b == 2)
                {
                    converted_value = from_decimal(value, 8);
                    break;
                }
                if (b == 4)
                {
                    converted_value = from_decimal(value, 16);
                    break;
                }

            case 4:

                base = 16;
                if (b == 1)
                {
                    converted_value = to_decimal(value, base);
                    converted_value = from_decimal(converted_value, 2);
                    break;
                }
                if (b == 2)
                {
                    converted_value = to_decimal(value, base);
                    converted_value = from_decimal(converted_value, 8);
                    break;
                }
                if (b == 3)
                {
                    converted_value = to_decimal(value, 10);
                    break;
                }
            }
            if (b == 1)
            {
                cout << "Binary Conversion is: " << converted_value << endl;
            }
            if (b == 2)
            {
                cout << "Octal Conversion is: " << converted_value << endl;
            }
            if (b == 3)
            {
                cout << "Decimal Conversion is: " << converted_value << endl;
            }
            if (b == 4)
            {
                cout << "Hexadecimal Conversion is: " << converted_value << endl;
            }
        }
    }
    else
    {
        int valid = 0;
        while (valid == 0)
        {
            int pressed;
            cout << "Press" << endl;
            cout << "+------------------+" << endl;
            cout << "| 1.To Write Again |" << endl;
            cout << "| 2.Main Menu      |" << endl;
            cout << "| 3.Exit           |" << endl;
            cout << "+------------------+" << endl;
            cout << "Option: ";
            cin >> pressed;
            switch (pressed)
            {
            case 1:
            {
                valid = 1;
                loop(a, b);
                break;
            }
            case 2:
            {
                valid = 1;
                main();
                break;
            }
            case 3:
            {
                valid = 1;
                exit(0);
                break;
            }
            default:
            {
                valid = 0;
                cout << "Not a valid Option" << endl;
            }
            }
        }
    }
}
string input_value(int a)
{
    string value;
    if (a == 1)
    {
        cout << "Enter a Binary Number: " << endl;
    }
    if (a == 2)
    {
        cout << "Enter a Octal Number: " << endl;
    }
    if (a == 3)
    {
        cout << "Enter a Dcimal Number: " << endl;
    }
    if (a == 4)
    {
        cout << "Enter a Hexadecimal Number: " << endl;
    }
    cin >> value;
    return value;
}
int close_loop(int a, int b)
{
    int valid = 0;
    int pressed;
    while (valid == 0)
    {

        cout << "Press" << endl;
        cout << "+-------------------------+" << endl;
        cout << "| 1.Convert Another Value |" << endl;
        cout << "| 2.Main Menu             |" << endl;
        cout << "| 3.Exit                  |" << endl;
        cout << "+-------------------------+" << endl;
        cout << "Option: ";
        cin >> pressed;
        switch (pressed)
        {
        case 1:
        {
            valid = 1;
            loop(a, b);
            break;
        }
        case 2:
        {
            valid = 1;
            main();
            break;
        }
        case 3:
        {
            valid = 1;
            exit(0);
            break;
        }
        default:
        {
            valid = 0;
            cout << "Not a valid Option" << endl;
        }
        }
    }
    return pressed;
}