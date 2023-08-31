/* Напишите две функции, выполняющие одинаковые действия(в соответствии с указанным
	вариантом) :
	 использующую только строки в стиле С
	 использующую строки типа string
	В функциях разрешается использовать библиотечные функции из <cctype> и методы класса
	string, но запрещается(!) пользоваться функциями из <cstring>.
	Если функция формирует новую строку, то она должна иметь вид :
 char* foo(char* destination, const char* source, …)
Для функции, работающей со строками в стиле C.Где destination – строка, в которую
помещается результат, source – исходная строка(строки), возвращаемое значение –
указатель на строку назначения.
Строка destination должна быть передана в функцию извне, чтобы избежать выделения
динамической памяти внутри функции(по примеру стандартных функций из <cstring>).
При работе со строками в стиле C не следует передавать в функцию размер строки или
вычислять его внутри функции в отдельном цикле.В этом нет необходимости, т.к.все
строки должны оканчиваться символом ‘\0’ и можно работать с ними, учитывая это
правило.
 string bar(const string& source, …)
Для функции, работающей с объектами string.
Объект string сам управляет содержащейся в нём динамической памятью и имеет
конструктор копирования.Поэтому результат можно вернуть из функции по значению.
Объект string имеет метод size(), возвращающий размер строки, так что работать с
символом ‘\0’ не нужно.
Напишите функцию main для проверки ваших функций :
 Строки в стиле С следует разместить в динамической памяти.
 Длину строки(строк) и сами символы строки считывать из файла, как строку в стиле C.В
файле может быть сколько угодно строк.
 Каждая строка описывается в файле двумя строчками : первая – количество символов в
строке(выделяя память не забывайте про завершающий символ ‘\0’), вторая – символы
строки.
 Для считывания самой строки удобнее всего использовать метод getline() класса istream.
 Объект string для демонстрации работы второй фукции можно получить из строки в стиле
C.
 Результаты работы программы вывести в поток cout.
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
14 вариант. Сформировать новую строку, содержащую все латинские буквы, отсутствующие в исходной
строке.Заглавные и строчные буквы не различаются.Буквы новой строки должны следовать в
порядке возрастания их кодов ASCII.*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
char* foo(char* destination, const char* source);
std::string bar(const std::string& source);
int main() {
	setlocale(LC_ALL, "Russian");
	std::ifstream file;
	file.open("file_string.txt");

	int size = 0;
	while (file >> size) {
		++size; // для размещения символа завершения строки "\0"
		char* textC = new char[size];
		char* itog = new char[27];
		file.ignore();
		file.getline(textC, (size));
		std::string textS = textC;
		std::cout << "Размер входной строки = " << size - 1 << '\n';
		std::cout << "входная строка:" << textC << '\n';
		std::cout << "В стиле С = " << foo(itog, textC) << '\n';
		std::cout << "Объект string = " << bar(textS) << '\n' << '\n';
		delete[] textC;
		delete[] itog;
		size = 0;
	}
	file.close();
	return 0;
}
char* foo(char* destination, const char* source) {
	short int count = 0;
	for (int i = static_cast<int>('a'); i <= static_cast<int>('z'); i++) {
		bool flag = 1;
		for (int j = 0; source[j] != '\0'; j++) {
			if (static_cast<char>(i) == tolower(source[j])) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			destination[count] = static_cast<char>(i);
			count++;;
		}
	}
	destination[count] = '\0';
	return destination;
}
std::string bar(const std::string& source) {
	std::string bar;
	for (int i = static_cast<int>('a'); i <= static_cast<int>('z'); i++) {
		bool flag = 1;
		for (int j = 0; j <= source.size(); j++) {
			if (static_cast<char>(i) == tolower(source[j])) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			bar.push_back(static_cast<char>(i));
		}
	}
	return bar;
}