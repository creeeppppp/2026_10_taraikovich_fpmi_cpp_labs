#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
std::time_t Now() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}
std::string FormatTime(time_t time, bool is_utc_format) {
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4996)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    std::ostringstream oss;
    oss << (is_utc_format
        ? std::put_time(std::gmtime(&time), "%d.%m.%Y %H:%M:%S")
        : std::put_time(std::localtime(&time), "%d.%m.%Y %H:%M:%S"));

#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

    return oss.str();
}

std::string RLE(const std::string& text)
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

bool empty_file(std::ifstream& fin) {
    return fin.peek() == std::ifstream::traits_type::eof();
}
std::string read_string_from_file(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        throw "Couldn't open file \"" + filename + "\".";
    }
    if (empty_file(fin)) {
        throw "File \"" + filename + "\" is empty";
    }
    std::string line;
    std::getline(fin, line);
    return line;
}
void write_string_to_file(const std::string& line, const std::string& filename){
    std::ofstream fout(filename);
    if (!fout.is_open()) {
    throw "Coudln't open file \"" + filename + "\".";
    }
    fout << line;
    fout.close();

}
void log_file(const std::string& line, const std::string& filename) {
    std::ofstream lout(filename, std::ios::app);
    if (!lout.is_open()) {
        throw "Couldn't open file \"" + filename + "\".";
    }
    lout << line;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const std::string input_filename = "input.txt";
    const std::string output_filename = "output.txt";
    const std::string log_filename = "log.txt";
    std::ofstream(log_filename, std::ios::trunc).close();

    try {
        log_file(FormatTime(Now(), false) + " | opening and reading file \"" + input_filename + "\"\n", log_filename);
        std::string text = read_string_from_file(input_filename);
        log_file(FormatTime(Now(), false) + " | file \"" + input_filename + "\" has been read successfully\n", log_filename);
        log_file(FormatTime(Now(), false) + " | got line:\"" + text +  "\"\n", log_filename);

        std::string result = RLE(text);
        log_file(FormatTime(Now(), false) + " | RLE completed\n", log_filename);

        log_file(FormatTime(Now(), false) + " | opening and writing to file \"" + output_filename + "\"\n", log_filename);
        write_string_to_file(result, output_filename);
        log_file(FormatTime(Now(), false) + " | result written to \"" + output_filename + "\" successfully\n", log_filename);
        std::cout << "Original text: " << text << "\n";
        std::cout << "Result: " << result;

    }
    catch (const std::string& msg) {
        std::cerr << msg;
        log_file(FormatTime(Now(), false) + " | " + msg + '\n', log_filename);
    }
        log_file(FormatTime(Now(), false) + " | progam has ended with code 0\n", log_filename);
        return 0;
}
