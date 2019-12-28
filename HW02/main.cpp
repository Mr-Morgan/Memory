#include <iostream>
#include <iomanip>

/*
1.  Составить и проверить в действии функцию, составляющую 32-разрядное беззнаковое целое значение uint32_t из четырех байт
    данных. Обращаться со значением нужно при этом как с простым массивом из 4 элементов типа unsigned char. При этом:

    - Использовать указатели;
    - Применить операции приведения типов данных;
    - Заполненное 32-разрядное значение должно быть возвращено из функции.
*/

using namespace std;

uint32_t fourCharToInt32U(const unsigned char set[4])
{
    uint32_t rez = 0;
    uint32_t *p_rez = &rez;
    void *p = static_cast<void*>(p_rez);
    unsigned char *iterator = static_cast<unsigned char*>(p);
    for (int i = 0; i < 4; ++i)
        *(iterator + i) = set[i];
    return rez;
}//uint32_t fourCharToInt32U(const unsigned char set[4])

void printArrUcharFromUint32(uint32_t *a)
{
//    uint32_t *p_a = a;
    void *p = static_cast<void*>(a);
    unsigned char *iterator = static_cast<unsigned char*>(p);
    for (int i = 0; i < 4; ++i)
        cout << *(iterator + i) << " ";
    cout << endl;
}//void printArrUcharFromUint32(const uint32_t &a)

void printBinary(uint32_t &a)
{
    for (; a > 0; a /= 2)
        cout << ((!(a % 2))? '0':'1') << ' ';
    cout << endl;
}//void printBinary(uint32_t &a)

void printBinary(unsigned char &a)
{
    for (; a > 0; a /= 2)
        cout << ((!(a % 2))? '0':'1') << ' ';
    cout << '\t';
}//void printBinary(unsigned char &a)

int main()
{
    unsigned char set[4] = {'1', '2', '3', '4'};
    uint32_t rezult = fourCharToInt32U(set);
    cout << rezult << endl;
    printArrUcharFromUint32(&rezult);

    printBinary(rezult);
    for (int i = 0; i < 4; ++i)
        printBinary(set[i]);
    cout << endl;

    return 0;
}//int main()
