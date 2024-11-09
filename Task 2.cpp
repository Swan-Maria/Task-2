#include <iostream>
#include <cstring>
#include <Windows.h>
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char string[] = { 'д','о','б','р','о', 'е',' ','у','т','р','о','\0' };
    int length = sizeof(string) / sizeof(string[0]) - 1;
    char result[sizeof(string)];

    int spaceIndex = -1;
    for (int i = 0; i < length; ++i)
    {
        if (string[i] == ' ')
        {
            spaceIndex = i;
            break;
        }
    }

    if (spaceIndex == -1)
    {
        std::cout << "Пробел не найден!" << std::endl;
        return 1;
    }

    for (int i = 0; i < length - spaceIndex - 1; ++i)
    {
        result[i] = string[spaceIndex + 1 + i];
    }

    result[length - spaceIndex - 1] = ' ';

    for (int i = 0; i < spaceIndex; ++i)
    {
        result[length - spaceIndex + i] = string[i];
    }

    result[length] = '\0';

    std::cout << "Строка до:  " << string  << std::endl;
    std::cout << "Строка после:   " << result << std::endl;

    return 0;
}