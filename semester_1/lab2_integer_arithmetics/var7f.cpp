#include <iostream>

bool al(int x, int y);

int main()
{
    using std::cin;
    using std::cout;
    setlocale(LC_ALL, ".65001");
    int n, m, k = 1, a = 0, b = 0, c = 0, j = 2;
    cout << "Введите до какого натурального n будут пифагоровы тройки. ";
    if (!(cin >> n))
    {
        cout << "error";
        std::exit(-1);
    }

    while (true)
    {
        m = k + 1;
        if (m * m + k * k > n)
        {
            break;
        }
        while (true)
        {
            a = m * m - k * k;
            b = 2 * k * m;
            c = m * m + k * k;
            if (c > n)
            {
                break;
            }
            if (al(m, k))
            {
                cout << "(" << a << ", " << b << ", " << c << ")" << std::endl;
                while ((c * j) <= n)
                {
                    cout << "(" << a * j << ", " << b * j << ", " << c * j << ")" << std::endl;
                    j++;
                }
            }
            j = 2;
            m++;
        }
        k++;
    }
}
bool al(int x, int y)
{
    int s = (x - y) % 2;
    int temp;
    while (y != 0)
    {
        temp = y;
        y = x % y;
        x = temp;
    }
    if ((temp == 1) && (s != 0))
    {
        return true;
    }
    return false;
}