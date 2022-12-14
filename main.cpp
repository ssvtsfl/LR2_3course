#include <iostream>
#include <fstream>
#include<string>

using namespace std;

bool isDevider(string ch)
{
    return (ch == "." || ch == "!" || ch == "?" || ch == "\"");
}

bool isDeviderExt(string ch)
{
    return (ch == "." || ch == "!" || ch == "?" || ch == "\"" || ch == " " || ch == "\t" || ch == "\n");
}

bool check(string a) // проверка на наличие кавычек в строке
{
    if (a.find('<<') != string::npos)
    {
        return 0;
    }
    else return 1;
}

void readFile()
{
    setlocale(LC_ALL, "Russian");

    ifstream fin; // создаем объект класса ifstream
    string filename = "/Users/sofiakondrateva/Downloads/TP_2lr_2/TP_2lr_2/text.txt"; // объявляем название файла

    fin.open(filename); // открываем файл
    if (!fin.is_open()) // если файл не открылся, значит вызываем исключение, что файл не найден
    {
        throw "Исключение: файл " + filename + " не найден";
    }

    string str[100];
    string c;
    char ch;
    int count = 0;

    while (!fin.eof()) // пока файл не пуст
    {
        fin.get(ch); // получаем строку (предложение до знака "." или "?" или "!")
        c = ch;

        if (!isDeviderExt(c)) // пока строка не равна конце предложения (то есть точки и т.д)
        {
            while (!fin.eof()) // пока файл не пуст
            {
                str[count] += c; // добавляем предложение
                fin.get(ch);
                c = ch;
                if (isDevider(c)) // если это конец предложения
                {
                    if (check(str[count])) // проверка на запятую
                    {
                        cout << "" << endl;
                    } else {
                        cout << str[count] << endl; // выводим предложения в кавычках
                    }
                    
                    count++;
                    break;
                }
            }
        }
    }
    fin.close();
}


int main()
{
readFile();
}
