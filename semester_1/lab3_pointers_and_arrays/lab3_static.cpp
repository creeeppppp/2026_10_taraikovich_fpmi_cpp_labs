#include <iostream>
#include <random>

void vvod(double *arr, int x)
{
    std::cout << "Введите элементы массива. ";
    int move = 1;
    for (int i = 0; i < x; i++)
    {
        if (!(std::cin >> arr[i]))
        {
            std::cout << "Элемент массива должен быть вещественным числом.";
            std::exit(-1);
        }
    }
}
void print(double *arr, int x)
{
    for (int i = 0; i < x; i++)
    {
        std::cout << arr[i] << " ";
    }
}
void randompr(double *arr, int x, double y, double z, std::mt19937 &gen)
{
    std::uniform_real_distribution<double> dist(y, z);
    for (int i = 0; i < x; i++)
    {
        arr[i] = dist(gen);
    }
}
void task7(double *arr, int x)
{
    std::cout << "Массив:\n";
    print(arr, x);
    int next_even = ((x - 1) / 2) * 2;
    int count = 0;
    for (int i = 0; i < x; i++)
    {
        if (((arr[i] < 11) && (arr[i] > 0)))
        {
            count++;
        }
    }
    if (x % 2 == 0)
    {
        if (count > (x / 2))
        {
            std::cout << "\nНевозможно преобразовать массив. \n";
            std::exit(-1);
        }
    }
    else
    {
        if (count > (x + 1) / 2)
        {
            std::cout << "\nНевозможно преобразовать массив. \n";
            std::exit(-1);
        }
    }
    std::cout << "\nПреобразованный массив: \n";
    for (int i = x - 1; i >= 0; i--)
    {
        if (((arr[i] < 11) && (arr[i] > 0)))
        {
            if (i == next_even)
            {
                next_even -= 2;
                continue;
            }
            double temp = arr[i];
            for (int j = i; j < next_even; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[next_even] = temp;
            next_even -= 2;
        }
    }
    print(arr, x);
}
int main()
{
    std::string answer;
    std::mt19937 gen(45218965);
    setlocale(LC_ALL, ".65001");
    const int MAX = 100'000;
    int n;
    double arr7[MAX], a, b;
    std::cout << "Введите количество элементов масcива? ";
    if (!(std::cin >> n) || n <= 0)
    {
        std::cout << "Число должно быть ццелым положительным.";
        return -1;
    }
    std::cout << "Как заполнить массив? Вручную/Random ";
    if (!(std::cin >> answer) || (answer != "Вручную" && answer != "Random"))
    {
        std::cout << "Неверный ввод.";
        return (-1);
    }
    if (answer == "Вручную")
    {
        vvod(arr7, n);
        task7(arr7, n);
    }
    else
    {
        std::cout << "Введите границы интервала, к которому будут принадлежать элементы массива [a, b] ";
        if (!(std::cin >> a >> b))
        {
            std::cout << "Неверный ввод.";
            std::exit(-1);
        }
        if (a > b)
        {
            std::cout << "a должно быть меньше b";
            std::exit(-1);
        }
        randompr(arr7, n, a, b, gen);
        task7(arr7, n);
    }
    return 0;
}
