#include <iostream>
#include <random>

int **create_matrix(int n, int m)
{
    int **mat;
    mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[m];
    }
    return mat;
}
int **task_7(int n, int m, int **matrix)
{
    int *col_sum = new int[m]();
    int *row_sum = new int[n]();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            col_sum[j] += matrix[i][j];
            row_sum[i] += matrix[i][j];
        }
    }
    int **matrix_res = create_matrix(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix_res[i][j] = col_sum[j] + row_sum[i] - matrix[i][j];
        }
    }
    delete[] row_sum;
    delete[] col_sum;
    return matrix_res;
}
void delete_matrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void input_matrix(int **matrix, int n, int m)
{
    std::cout << "Введите элементы матрицы. ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!(std::cin >> matrix[i][j]))
            {
                std::cout << "Элемент массива должен быть целым числом.";
                delete_matrix(matrix, n);
                std::exit(-1);
            }
        }
    }
}
void print(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
void random_input(int **matrix, int n, int m, int a, int b, std::mt19937 &gen)
{
    std::uniform_int_distribution<int> dist(a, b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = dist(gen);
        }
    }
}
int main()
{
    std::mt19937 gen(45218965);
    setlocale(LC_ALL, ".65001");
    int n, m, a, b;
    std::cout << "Введите количество строк матрицы? ";
    if (!(std::cin >> n) || n <= 0)
    {
        std::cout << "Число должно быть целым положительным.";
        return -1;
    }
    std::cout << "Введите количество столбцов матрицы? ";
    if (!(std::cin >> m) || m <= 0)
    {
        std::cout << "Число должно быть целым положительным.";
        return -1;
    }

    int **A = create_matrix(n, m);
    std::cout << "Как заполнить массив? Вручную - 0, рандомно - 1 ";
    int answer;
    if (!(std::cin >> answer) || (answer != 1 && answer != 0))
    {
        std::cout << "Неверный ввод.";
        delete_matrix(A, n);
        return (-1);
    }
    if (answer == 0)
    {
        input_matrix(A, n, m);
    }
    else
    {
        std::cout << "Введите границы интервала, к которому будут принадлежать элементы массива [a, b] ";
        if (!(std::cin >> a >> b))
        {
            std::cout << "Неверный ввод.";
            delete_matrix(A, n);
            return (-1);
        }
        if (a > b)
        {
            std::cout << "a должно быть меньше b";
            delete_matrix(A, n);
            return (-1);
        }
        random_input(A, n, m, a, b, gen);
    }
    int **C = task_7(n, m, A);
    print(A, n, m);
    std::cout << "\n";
    print(C, n, m);
    delete_matrix(A, n);
    delete_matrix(C, n);
    return 0;
}