#include <iostream>
#include <random>
void vvod(int *arr, int x)
{
    std::cout << "Введите элементы массива. ";
    int move = 1;
    for (int i = 0; i < x; i++)
    {
        if (!(std::cin >> arr[i]))
        {
            std::cout << "Элемент массива должен быть целым числом.";
            delete[] arr;
            std::exit(-1);
        }
    }
}
void print(int *arr, int x)
{
    for (int i = 0; i < x; i++)
    {
        std::cout << arr[i] << " ";
    }
}
void randompr(int *arr, int x, int y, int z, std::mt19937 &gen)
{
    std::uniform_int_distribution<int> dist(y, z);
    for (int i = 0; i < x; i++)
    {
        arr[i] = dist(gen);
    }
}
void task9(int *arr, int x)
{
    std::cout << "Массив:\n";
    print(arr, x);
    int first = 0;
    for (int i = 0; i < x; i++)
    {
        if (arr[i] < 0)
        {
            int temp = arr[i];
            for (int j = i; j > first; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[first] = temp;
            first++;
        }
    }
    std::cout << "\nПреобразованный массив:\n";
    print(arr, x);
}
int main()
{
    std::string answer;
    std::mt19937 gen(45218965);
    setlocale(LC_ALL, ".65001");
    int n, c, d;
    std::cout << "Введите количество элементов масcива? ";
    if (!(std::cin >> n) || n <= 0)
    {
        std::cout << "Число должно быть целым положительным.";
        return -1;
    }
    int *arr9 = new int[n];
    std::cout << "Как заполнить массив? Вручную/Random ";
    if (!(std::cin >> answer) || (answer != "Вручную" && answer != "Random"))
    {
        std::cout << "Неверный ввод.";
        delete[] arr9;
        return (-1);
    }
    if (answer == "Вручную")
    {
        vvod(arr9, n);
        task9(arr9, n);
    }
    else
    {
        std::cout << "Введите границы интервала, к которому будут принадлежать элементы массива [c, d] ";
        if (!(std::cin >> c >> d))
        {
            std::cout << "Неверный ввод.";
            delete[] arr9;
            return (-1);
        }
        if (c > d)
        {
            std::cout << "c должно быть меньше d";
            delete[] arr9;
            return (-1);
        }
        randompr(arr9, n, c, d, gen);
        task9(arr9, n);
    }
    delete[] arr9;
    return 0;
}
