#include <iostream>
#include <ctime>

/*
1.  Составить программу, выводящую на экран текущую среду сборки (Windows/Linux), дату и время последней успешной сборки.
    Использовать константу TIME для вывода времени.
*/

using namespace std;

int main()
{
#ifdef __linux__
    cout << "Linux ";
#elif _WIN32
    cout << "Windows ";
#elif _WIN64
    cout << "Windows ";
#else __APPLE__
    cout << "MacOS "
#endif
    cout << __DATE__ << " " << __TIME__ << endl;
    return 0;
}//int main()
