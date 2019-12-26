#include "categorizer.h"

/*
1.  Дана ссылка: https://drive.google.com/file/d/1262pLzDnw3yUK6yzhOYS10hOqkqtZucz/view
    Переработать исходный текст программы - анализатора яркостей из уровня 1, используя адреса, ссылки и указатели:

    - Обобщить однотипные операции;
    - Избавиться от копирования кода;
    - Динамически выделить память под имя с типом fstream и корректно освободить память после окончания записи файлов.
*/

using namespace std;

void printArray(U *arr, U const &arr_len)
{
    for (U i = 0; i < arr_len; ++i) {
        cout << "[" << i << "] ";
        for (U j = 0; j < arr[i]; ++j)
            cout << '|';
        cout << "(" << arr[i] << ")\n";
    }//for (U i = 0; i < arr_len; ++i)
}//void printArray(U *arr, U const &arr_len)

void printHistFile(U *arr, U const &arr_len)
{
    ofstream out("histogram.txt");
    for (U i = 0; i < arr_len; ++i) {
        out << "[" << i << "] ";
        for (U j = 0; j < arr[i]; ++j)
            out << '|';
        out << "(" << arr[i] << ")\n";
    }//for (U i = 0; i < arr_len; ++i)
}//void printHistFile(U *arr, U const &arr_len)

int main(int argc, char **args)
{
    unsigned histogram[256], hist_size = 0;
    for (int i = 1; i < argc; ++i) {
        try {
            pgmAnalysis pgm(args[i]);
            pgm.analys();
            pgm.getHistogram(histogram, hist_size);

            printArray(histogram, hist_size);
            printHistFile(histogram, hist_size);
        }//try
        catch (exception& e) {
            cerr << "error: " << e.what() << '\n';
            continue;
        }// catch (exception& e)
        catch (...) {
            cerr << "Oops: unknown exception!\n";
            return EXIT_FAILURE;
        }// catch (...)
    }//for (int i = 0; i < argc; ++i)
    return EXIT_SUCCESS;
}//int main(int argc, char **args)                                                                                                                                                                              1,1          Вес
