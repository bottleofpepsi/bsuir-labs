#include "InputException.h"

void InputException::printException()						//������� ������ ������ �� �����
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14 << 4 | 12);
	Exception::printException();
	cout << inputMessage + "." << endl;
	SetConsoleTextAttribute(h, 14 << 4 | 0);
}

int inputInt(istream& in, int min, int max)					//���� ������ ����� � ���������
{
	int tmp = 0;

	while (true)
	{
		try
		{
			rewind(stdin);
			in >> tmp;
			if (!in || in.peek() != '\n')
				throw InputException("������ ������� ������", "������� ����� �����");
			if (tmp > max || tmp < min)
			{
				throw InputException("������ ������ �� �������", "������� ����� � �������� �� " + to_string(min) + " �� " + to_string(max));
			}
			return tmp;
		}
		catch (InputException obj)
		{
			in.clear();										//������� ����� ������
			obj.printException();							//����� ������
		}
	}
}

float inputFloat(istream& in, float min, float max)			//���� ������������� ����� � ���������
{
	float tmp = 0;

	while (true)
	{
		try
		{
			rewind(stdin);
			in >> tmp;
			if (!in || in.peek() != '\n')
				throw InputException("������ ������� ������", "������� ������������ �����");
			if (tmp > max || tmp < min)
				throw InputException("������ ������ �� �������", "������� ����� � �������� �� " + to_string(min) + " �� " + to_string(max));
			return tmp;
		}
		catch (InputException obj)
		{
			in.clear();										//������� ����� ������
			obj.printException();							//����� ������
		}
	}
}

char* inputString(istream& in, int size)					//���� ������
{
	char* buf = new char[size + 1];

	while (true)
	{
		try
		{
			rewind(stdin);
			in.getline(buf, size, '\n');
			if (!in)
				throw InputException("������ ������ �� �������", "������� ������ �� " + to_string(size) + " ��������");
			return buf;
		}
		catch (InputException obj)
		{
			in.clear();										//������� ����� ������
			obj.printException();							//����� ������
		}
	}
}

char* inputCyrillicString(istream& in, int size)			//���� ������ ����������
{
	char* buf = new char[size + 1];

	while (true)
	{
		try
		{
			rewind(stdin);
			in.getline(buf, size, '\n');
			if (!in)
				throw InputException("������ ������ �� �������", "������� ������ �� " + to_string(size) + " ��������");
			for (unsigned int i = 0; i < strlen(buf); i++)
				if ((buf[i] < '�' || buf[i] > '�') && buf[i] != ' ' && buf[i] != ',' && buf[i] != '.'
					&& buf[i] != '!' && buf[i] != '?' && buf[i] != '(' && buf[i] != ')' && buf[i] != '�')
					throw InputException("������ ����� ���������� ������", "������� ������ ����������");
			return buf;
		}
		catch (InputException obj)
		{
			in.clear();										//������� ����� ������
			obj.printException();							//����� ������
		}
	}
}

char* inputLatinicString(istream& in, int size)				//���� ������ ���������
{
	char* buf = new char[size + 1];

	while (true)
	{
		try
		{
			rewind(stdin);
			in.getline(buf, size, '\n');
			if (!in)
				throw InputException("������ ������ �� �������", "������� ������ �� " + to_string(size) + " ��������");
			for (unsigned int i = 0; i < strlen(buf); i++)
				if ((buf[i] < 'A' || buf[i] > 'Z') && (buf[i] < 'a' || buf[i] > 'z') && buf[i] != ' ' && buf[i] != ','
					&& buf[i] != '.' && buf[i] != '!' && buf[i] != '?' && buf[i] != '(' && buf[i] != ')' && buf[i] != '�')
					throw InputException("������ ����� ���������� ������", "������� ������ ���������");
			return buf;
		}
		catch (InputException obj)
		{
			in.clear();										//������� ����� ������
			obj.printException();							//����� ������
		}
	}
}