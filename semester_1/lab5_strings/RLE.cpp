#include <iostream>
#include <string>
#include <windows.h>
std::string RLE(const std::string &text)
{
    if (text.empty())
        return "";
    std::string result_string;
    std::string::size_type counter;
    std::string::size_type size = text.size();
    for (std::string::size_type i = 0; i < size; i++)
    {
        counter = 1;
        while ((i + 1 < size) && (text[i] == text[i + 1]))
        {
            counter++;
            i++;
        }
        result_string += text[i];
        if (counter != 1)
        {
            result_string += std::to_string(counter);
        }
    }
    return result_string;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string text;
    std::cout << "Enter text: ";
    std::getline(std::cin, text);
    std::cout << "Original text: " << text << "\n";
    std::string result = RLE(text);
    std::cout << "Result: " << result;
}