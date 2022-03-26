// 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*#include <iostream>
#include <string>
std::string crypt(const std::string& text) {
	std::string cyphertext;
	for (char c : text) {
		cyphertext += char(24 - (c - 'a') + 1) + 'a';
	}
	return cyphertext;
}
int main() {
	std::string text;
	std::getline(std::cin, text);
	std::string crypted = crypt(text);
	std::cout << "Crypted text: " << crypted << std::endl;
	std::cout << "Twice crypted text: " << crypt(crypted) << std::endl;
	return 0;
	system("pause");
}*/

/*#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iterator>
#include <unordered_map>

std::string getChoice();
std::vector<std::string> getCoords();

int main() {
    std::string choice = getChoice();

    if (choice == "e") {
        std::cout << "Input string: ";
        std::string input;
        std::getline(std::cin, input);
        input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

        std::unordered_map<char, unsigned int> alphaToInt = {
            {'A', 11},
            {'B', 12},
            {'C', 13},
            {'D', 14},
            {'E', 15},
            {'F', 21},
            {'G', 22},
            {'H', 23},
            {'I', 24},
            {'J', 24}, // same as I
            {'K', 25},
            {'L', 31},
            {'M', 32},
            {'N', 33},
            {'O', 34},
            {'P', 35},
            {'Q', 41},
            {'R', 42},
            {'S', 43},
            {'T', 44},
            {'U', 45},
            {'V', 51},
            {'W', 52},
            {'X', 53},
            {'Y', 54},
            {'Z', 55},
        };

        for (int i = 0; i < input.length(); ++i) {
            std::cout << alphaToInt[input[i]] << ' ';
        }
    }
    else {
        std::vector<std::string> coords = getCoords();
        std::string output;

        const std::string squareIJ[5][5] = {
            {"A", "B", "C", "D", "E"},
            {"F", "G", "H", "I", "K"},
            {"L", "M", "N", "O", "P"},
            {"Q", "R", "S", "T", "U"},
            {"V", "W", "X", "Y", "Z"},
        };

        for (int i = 0; i < coords.size(); ++i) {
            std::string coord = coords[i];
            output.append(squareIJ[coord[0] - '1'][coord[1] - '1']);
        }

        std::cout << output;

    }

    std::cout << '\n';
    return 0;
    system("pause");
}

std::string getChoice() {
    std::string choice;
    do {
        std::cout << "Encrypt or decrypt [e/d] = ";
        std::getline(std::cin, choice);
        if (choice == "E") choice = "e";
        std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
    } while (choice != "e" && choice != "d");

    return choice;
}

std::vector<std::string> getCoords() {
    std::cout << "Coordinates (separate with spaces): ";
    std::string strCoords;
    std::getline(std::cin, strCoords);
    std::stringstream streamCoords(strCoords);
    std::istream_iterator<std::string> begin(streamCoords);
    std::istream_iterator<std::string> end;
    std::vector<std::string> coords(begin, end);
    return coords;
}*/



#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iomanip>

using namespace std;

int main()

{
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    system("cls");

    {

        char* string = new char[36];

        const int m = 6;

        const int n = 6;

        int i, j, l;

        cout << "Шифр квадрата Полибия: \n";

        char A[m][n] = { {'А', 'Б', 'В', 'Г', 'Д', 'Е' },

        {'Ж', 'З', 'И', 'К', 'Л', 'М' },

        {'Н', 'О', 'П', 'Р', 'С', 'Т' },

        {'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш' },

        {'Щ', 'Ъ', 'Ы', 'Ь','Э', 'Ю' },

        {'Я', '.', ',', '?', '!', ' ' } };

        for (int i = 0; i < m; i++)

        {
            for (int j = 0; j < n; j++)

            {
                cout << setw(2) << A[i][j] << ' ';

            }
            cout << endl;

        }

        cout << "Введите слово : \n";

        cin >> string;

        for (int k = 0; k < strlen(string); k++)
        {
            for (i = 0; i < m; i++)
            {

                for (j = 0; j < n; j++)

                {

                    if (string[k] == A[i][j])

                    {
                        cout << i + 1 << j + 1 << setw(2);
                    }
                }
            }
        }

        cout << "\n";

        l = 0;
        i = 1;

        for (int k = 0; k < 6; k++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (string[i] == A[k][j])
                    l++;
            }
        }
        if (l == 0)
            cout << "Ваша строка не подходит, в следующий раз введите строку с русскими заглавными буквами. \n";

        cout << "\n";

    }

    system("pause");

    return 0;
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
