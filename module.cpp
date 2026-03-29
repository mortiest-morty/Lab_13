# include "Header.h"


void task_1() {
	using namespace std;

	int k;
	vector<int> V, duble;

	while (true) {
		cout << "Введите число k: ";
		cin >> k;

		if (cin.fail() || k<1) {
			cout << "Ошибка! Введите НАТУРАЛЬНОЕ ЧИСЛО!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	
	cout << endl;
	inputVector(V);

	auto n = search_n(V.begin(), V.end(), k, 0, [](int el, int) {
		return el > 0;
		}
	);
	
	if (n != V.end()) {
		V.insert(n + k, n, n + k);
	}
	else {
		cout << "\nНе найдено! А всё, а всё, а надо было нормальный вектор вводить! Сами виноваты\n";
	}

	outputVector(V);
}


void task_2() {
	using namespace std;
	int k = 0, input, n, num;
	list<int> L;
	list<int> l1;
	list<int> l2;

	while (true) {
		cout << "Введите число k: ";
		cin >> k;

		if (cin.fail() || k<1 || k>4) {
			cout << "Ошибка! Введите НАТУРАЛЬНОЕ ЧИСЛО 1-4!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	
	srand((time(nullptr)));

	cout << "\n===== Заполнение списка =====\n 1 - c консоли\n 2 - рандомно\n 3 - из файла\n";
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
		while (n < 10) {
			cout << "Ошибка!\nВведите натуральное число не меньше 10!\n ";
			n = getNumber();
		}

		int* a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = rand() % 100 + 1;
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

	auto firstEl = L.begin();
	auto lastEl = L.begin();
	advance(lastEl, 5);
	l2.insert(l2.begin(), firstEl, lastEl);

	auto middleEl = l2.begin();
	advance(middleEl, l2.size() - k);
	rotate_copy(
		l2.begin(),
		middleEl,
		l2.end(),
		back_inserter(l1)
	);
	l2.clear();

	auto first = L.begin();
	auto last = L.end();
	advance(first, L.size() - 5);
	l2.insert(l2.begin(), first, last);	
	L.insert(L.end(), l1.begin(), l1.end());

	l1.clear();
	auto middle = l2.begin();
	advance(middle, k);
	rotate_copy(
		l2.begin(),
		middle,
		l2.end(),
		back_inserter(l1)
	);
	L.insert(L.begin(), l1.begin(), l1.end());

	outputList(L);
}


void task_3() {
	using namespace std;

	deque<int> D;
	inputDeque(D);

	stable_sort(
		D.begin(),
		D.end(),
		[](int a, int b) {
			return a < 0 && b > 0 || a < 0 && b == 0 || a == 0 && b > 0;
		}
	);

	outputDeque(D);
}


void task_4() {
	using namespace std;

	int output;
	list<int> L;
	inputList(L);
	vector<double> v(L.size());

	adjacent_difference(
		L.begin(), 
		L.end(),
		v.begin(),
		[](int a, int b) {
			return (double) (a + b) / 2;
		}
	);
	
	auto i = v.begin();
	v.erase(i);

	cout << "\n===== Вывод вектора =====\n 1 - в консоль\n 2 - в файл\n";
	output = getNumber();
	while (output < 1 || output>2) {
		cout << "Ошибка!\nНужна цифра от 1 до 2!\n ";
		output = getNumber();
	}
	switch (output) {
	case 1:
		cout << "\nВектор: ";
		for (auto it = v.begin(); it != v.end(); ++it) {
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
			for (auto it = v.begin(); it != v.end(); ++it) {
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
