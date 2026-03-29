# include "Header.h"

// ======================== ПРОВЕРКА ВВОДА ========================
int getNumber() {
	using namespace std;
	int value;

	while (true) {
		cout << "Введите число: ";
		cin >> value;

		if (cin.fail()) {
			cout << "Ошибка! Введите ЧИСЛО, а не буквы!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return value;
		}
	}
}

std::string getText() {
	using namespace std;
	string input;
	bool hasDigit;

	while (true) {
		hasDigit = false;
		cout << "Введите имя файла: ";
		getline(cin, input);

		if (input.empty()) {
			cout << "Ошибка! Строка не может быть пустой!" << endl;
			continue;
		}

		for (int i = 0; i < input.length(); i++) {
			if (isdigit(input[i])) {
				hasDigit = true;
				break;
			}
		}

		if (hasDigit) {
			cout << "Ошибка! В тексте не должно быть цифр!" << endl;
		}
		else {
			return input;
		}
	}
}

// ================== ВВОД И ВЫВОД КОНТЕЙНЕРА "VECTOR" ==================
void inputVector(std::vector<int>& V) {
	using namespace std;

	int input, n, num;
	srand((time(nullptr)));

	cout << "===== Заполнение вектора =====\n 1 - c консоли\n 2 - рандомно\n 3 - из файла\n";
	input = getNumber();
	while (input < 1 || input>3) {
		cout << "Ошибка!\nНужна цифра от 1 до 3!\n ";
		input = getNumber();
	}
	switch (input) {
	case 1:
	{
		cout << "\n\n===== Введите числа (завершите ввод не-числом) =====\n";
		istream_iterator<int> in_it(cin), in_end;
		V.assign(in_it, in_end);
		cin.clear();
		break;
	}
	case 2:
	{
		cout << "\n\n===== Количество чисел =====\n";
		n = getNumber();
		while (n < 1) {
			cout << "Ошибка!\nВведите натуральное число!\n ";
			n = getNumber();
		}

		int* a = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = rand() % 120 - 60 + 1;
		}

		V.assign(a, a + n);

		cout << "Вектор: ";
		for (auto it = V.begin(); it != V.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

		delete a;
		break;
	}
	case 3:
	{
		string filename;
		filename = getText();

		ifstream file(filename);

		if (file.is_open()) {
			istream_iterator<int> file_it(file), file_end;
			V.assign(file_it, file_end);
			file.close();
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		cout << "Вектор: ";
		for (auto it = V.begin(); it != V.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		break;
	}
	}
}

void outputVector(std::vector<int>& V) {
	using namespace std;

	int output;

	cout << "\n\n===== Вывод вектора =====\n 1 - в консоль\n 2 - в файл\n";
	output = getNumber();
	while (output < 1 || output>2) {
		cout << "Ошибка!\nНужна цифра от 1 до 2!\n ";
		output = getNumber();
	}
	switch (output) {
	case 1:
		cout << "\nВектор: ";
		for (auto it = V.begin(); it != V.end(); ++it) {
			cout << *it << " ";
		}
		break;
	case 2:
	{
		string filename;
		filename = getText();

		ofstream file(filename);

		if (file.is_open()) {
			file << "Вектор: ";
			for (auto it = V.begin(); it != V.end(); ++it) {
				file << *it << " ";
			}
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		file.close();
		break;
	}
	}
}

// ================== ВВОД И ВЫВОД КОНТЕЙНЕРА "LIST" ==================
void inputList(std::list<int>& L) {
	using namespace std;

	int input, n, num;
	srand((time(nullptr)));

	cout << "===== Заполнение списка =====\n 1 - c консоли\n 2 - рандомно\n 3 - из файла\n";
	input = getNumber();
	while (input < 1 || input>3) {
		cout << "Ошибка!\nНужна цифра от 1 до 3!\n ";
		input = getNumber();
	}
	switch (input) {
	case 1:
	{
		cout << "\n\n===== Введите числа (завершите ввод не-числом) =====\n";
		istream_iterator<int> in_it(cin), in_end;
		L.assign(in_it, in_end);
		cin.clear();
		break;
	}
	case 2:
	{
		cout << "\n\n===== Количество чисел =====\n";
		n = getNumber();
		while (n < 1) {
			cout << "Ошибка!\nВведите натуральное число!\n ";
			n = getNumber();
		}

		int* a = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = rand() % 120 - 50 + 1;
		}
		L.assign(a, a + n);
		delete a;

		cout << "Список: ";
		for (auto it = L.begin(); it != L.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		break;
	}
	case 3:
	{
		string filename;
		filename = getText();

		ifstream file(filename);

		if (file.is_open()) {
			istream_iterator<int> file_it(file), file_end;
			L.assign(file_it, file_end);
			file.close();
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		cout << "Список: ";
		for (auto it = L.begin(); it != L.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		break;
	}
	}
}

void outputList(std::list<int>& L) {
	using namespace std;

	int output;

	cout << "\n===== Вывод списка =====\n 1 - в консоль\n 2 - в файл\n";
	output = getNumber();
	while (output < 1 || output>2) {
		cout << "Ошибка!\nНужна цифра от 1 до 2!\n ";
		output = getNumber();
	}
	switch (output) {
	case 1:
		cout << "\nСписок: ";
		for (auto it = L.begin(); it != L.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		break;
	case 2:
	{
		string filename;
		filename = getText();

		ofstream file(filename);

		if (file.is_open()) {
			file << "Список: ";
			for (auto it = L.begin(); it != L.end(); ++it) {
				file << *it << " ";
			}
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		file.close();
		break;
	}
	}
}

// ================== ВВОД И ВЫВОД КОНТЕЙНЕРА "DEQUE" ==================
void inputDeque(std::deque<int>& D) {
	using namespace std;

	int input, n, num;
	srand((time(nullptr)));

	cout << "======= Заполнение дека =======\n 1 - c консоли\n 2 - рандомно\n 3 - из файла\n";
	input = getNumber();
	while (input < 1 || input>3) {
		cout << "Ошибка!\nНужна цифра от 1 до 3!\n ";
		input = getNumber();
	}
	switch (input) {
	case 1:
	{
		cout << "\n\n===== Введите числа (завершите ввод не-числом) =====\n";
		istream_iterator<int> in_it(cin), in_end;
		D.assign(in_it, in_end);
		cin.clear();
		break;
	}
	case 2:
	{
		cout << "\n===== Количество чисел =====\n";
		n = getNumber();
		while (n < 1) {
			cout << "Ошибка!\nВведите натуральное число!\n ";
			n = getNumber();
		}

		int* a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = rand() % 120 - 60 + 1;
		}
		D.assign(a, a + n);
		delete a;

		cout << "Дек: ";
		for (auto it = D.begin(); it != D.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		break;
	}
	case 3:
	{
		string filename;
		filename = getText();

		ifstream file(filename);

		if (file.is_open()) {
			istream_iterator<int> file_it(file), file_end;
			D.assign(file_it, file_end);
			file.close();
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		cout << "Дек: ";
		for (auto it = D.begin(); it != D.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
		break;
	}
	}
}

void outputDeque(std::deque<int>& D) {
	using namespace std;

	int output;

	cout << "\n===== Вывод дека =====\n 1 - в консоль\n 2 - в файл\n";
	output = getNumber();
	while (output < 1 || output>2) {
		cout << "Ошибка!\nНужна цифра от 1 до 2!\n ";
		output = getNumber();
	}
	switch (output) {
	case 1:
		cout << "\nДек: ";
		for (auto it = D.begin(); it != D.end(); ++it) {
			cout << *it << " ";
		}
		break;
	case 2:
	{
		string filename;
		filename = getText();

		ofstream file(filename);

		if (file.is_open()) {
			file << "Дек: ";
			for (auto it = D.begin(); it != D.end(); ++it) {
				file << *it << " ";
			}
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}

		file.close();
		break;
	}
	}
}


