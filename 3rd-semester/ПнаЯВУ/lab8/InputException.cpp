#include "InputException.h"

void InputException::printException()						//функци€ вывода ошибки на экран
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14 << 4 | 12);
	Exception::printException();
	cout << inputMessage + "." << endl;
	SetConsoleTextAttribute(h, 14 << 4 | 0);
}

int inputInt(istream& in, int min, int max)					//ввод целого числа с проверкой
{
	int tmp = 0;

	while (true)
	{
		try
		{
			rewind(stdin);
			in >> tmp;
			if (!in || in.peek() != '\n')
				throw InputException("ќшибка формата данных", "¬ведите целое число");
			if (tmp > max || tmp < min)
			{
				throw InputException("ќшибка выхода за границы", "¬ведите число в границах от " + to_string(min) + " до " + to_string(max));
			}
			return tmp;
		}
		catch (InputException obj)
		{
			in.clear();										//очистка флага ошибки
			obj.printException();							//вывод ошибки
		}
	}
}

float inputFloat(istream& in, float min, float max)			//ввод вещественного числа с проверкой
{
	float tmp = 0;

	while (true)
	{
		try
		{
			rewind(stdin);
			in >> tmp;
			if (!in || in.peek() != '\n') 
				throw InputException("ќшибка формата данных", "¬ведите вещественное число");
			if (tmp > max || tmp < min) 
				throw InputException("ќшибка выхода за границы", "¬ведите число в границах от " + to_string(min) + " до " + to_string(max));
			return tmp;
		}
		catch (InputException obj)
		{
			in.clear();										//очистка флага ошибки
			obj.printException();							//вывод ошибки
		}
	}
}

char* inputString(istream& in)								//ввод строки
{
	char* buf = new char[STR_LEN];

	while (true)
	{
		try
		{
			rewind(stdin);
			in.getline(buf, STR_LEN, '\n');
			if (!in)
				throw InputException("ќшибка выхода за границы", "¬ведите строку до " + to_string(STR_LEN) + " символов");
			return buf;
		}
		catch (InputException obj)
		{
			in.clear();										//очистка флага ошибки
			obj.printException();							//вывод ошибки
		}
	}
}

char* inputCyrillicString(istream& in)						//ввод строки кириллицей
{
	char* buf = new char[STR_LEN];

	while (true)
	{
		try
		{
			rewind(stdin);
			in.getline(buf, STR_LEN, '\n');
			if (!in)
				throw InputException("ќшибка выхода за границы", "¬ведите строку до " + to_string(STR_LEN) + " символов");
			for (unsigned int i = 0; i < strlen(buf); i++)
				if ((buf[i] < 'ј' || buf[i] > '€') && buf[i] != ' ' && buf[i] != ',' && buf[i] != '.'
					&& buf[i] != '!' && buf[i] != '?' && buf[i] != '(' && buf[i] != ')' && buf[i] != 'Ч')
					throw InputException("ќшибка ввода символьных данных", "¬ведите строку кириллицей");
			return buf;
		}
		catch (InputException obj)
		{
			in.clear();										//очистка флага ошибки
			obj.printException();							//вывод ошибки
		}
	}
}

char* inputLatinicString(istream& in)						//ввод строки латиницей
{
	char* buf = new char[STR_LEN];

	while (true)
	{
		try
		{
			rewind(stdin);
			in.getline(buf, STR_LEN, '\n');
			if (!in)
				throw InputException("ќшибка выхода за границы", "¬ведите строку до " + to_string(STR_LEN) + " символов");
			for (unsigned int i = 0; i < strlen(buf); i++)
				if ((buf[i] < 'A' || buf[i] > 'Z') && (buf[i] < 'a' || buf[i] > 'z') && buf[i] != ' ' && buf[i] != ',' 
					&& buf[i] != '.' && buf[i] != '!' && buf[i] != '?' && buf[i] != '(' && buf[i] != ')' && buf[i] != 'Ч')
					throw InputException("ќшибка ввода символьных данных", "¬ведите строку латиницей");
			return buf;
		}
		catch (InputException obj)
		{
			in.clear();										//очистка флага ошибки
			obj.printException();							//вывод ошибки
		}
	}
}