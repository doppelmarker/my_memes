#include "Header.h"

bool is_number_numeric()
{
	if (cin.get() == '\n') return true;
	else
	{
		cin.clear();
		cin.ignore(100, '\n');
		return false;
	}
}

bool is_choose_range_correct(int number, int left_range, int right_range)
{
	if ((number >= left_range) && (number <= right_range))
		return true;
	else return false;
}

int choose_user(int left_range, int right_range, int number_of_students)
{
	int number;
	while (true)
	{
		cin >> number;
		if (is_number_numeric() && is_choose_range_correct(number, left_range, right_range))
			return number;
		else
		{
			cout << "\n  �������� ����!";
			cout << "\n  ������� ����� ������� ������, � �������� ������� ������� �� ����������� �����������������.\n\n";
		}
	}
}

int choose_number(int left_range, int right_range)
{
	int number;
	while (true)
	{
		cout << "\n  ��� �����: ";
		cin >> number;
		cout << "\n";
		if (is_number_numeric() && is_choose_range_correct(number, left_range, right_range))
			return number;
		else
		{
			cout << "\n  ������������ ����! ���������� �����.\n\n";
		}
	}
}

string input_string()
{
	string str;
	bool flag = true;
	while (flag)
	{
		cout << endl << "  ��� ����: ";
		getline(cin, str);
		if (str.size() == 0)
			continue;
		else flag = false;
	}
	return str;
}

string input_password_when_auth()
{
	string password;
	int ch = 0;
	cout << endl << "  ��� ����: ";
	while (true)
	{
		ch = _getch();
		if (ch == 13)
			break;
		else if (ch == 8)
		{
			if (password.size() == 0)
				continue;
			cout << (char)8 << ' ' << (char)8;
			if (!password.empty())
			{
				password.erase(password.size() - 1);
			}
		}
		else
		{
			cout << '*';
			password += (char)ch;
		}
	}
	return password;
}


string input_login_when_add_user()
{
	string login;
	bool flag = true;
	your_account();
	while (flag)
	{
		cout << endl << "  ������� ����� ����� ������� ������ (������������ ����� ������ ���������� 32 �������, ����� ����� ��������� ��������� ����� �������� � ������� ���������, ����� �� 0 �� 9)." << endl;
		login = input_string();
		if (is_login_correct(login))
			if (is_login_unique(login)) //�������� ������ �� ������������.
				flag = false;
			else
			{
				system("cls");
				your_account();
				cout << endl << "  ������� � ����� ������� ��� ���������������!" << endl;
			}
		else
		{
			system("cls");
			your_account();
			cout << endl << "  ��������� ������������ ��������� ���� ������!" << endl;
		}
	}
	return login;
}

bool is_login_unique(string login)
{
	bool uniqueness = true;
	for (int i = 0; i < v_users.size(); i++)
	{
		if (login == v_users.at(i).login)
			uniqueness = false;
	}
	return uniqueness;
}

string input_login_when_edit_user()
{
	string login;
	bool flag = true;
	while (flag)
	{
		cout << endl << "  ������� ����� ����� �������� (������������ ����� ������ ���������� 32 �������, ����� ����� ��������� ��������� ����� �������� � ������� ���������, ����� �� 0 �� 9)." << endl;
		login = input_string();
		if (is_login_correct(login))
			flag = false;
		else
			cout << "  ��������� ������������ ��������� ���� ������!";
	}
	return login;
}

string input_password_when_add_user()
{
	string password;
	bool flag = true;
	your_account();
	while (flag)
	{
		cout << endl << "  ������� ������ ����� ������� ������ (������������ ����� ������ ���������� 32 �������)." << endl;
		password = input_string();
		if (is_password_correct(password))
			flag = false;
		else
		{
			system("cls");
			your_account();
			cout << endl << "  ��������� ������������ ��������� ���� ������!" << endl;
		}
	}
	return password;
}

string input_password_when_edit_user()
{
	string password;
	bool flag = true;
	while (flag)
	{
		cout << endl << "  ������� ����� ������ ������� ������ (������������ ����� ������ ���������� 32 �������)." << endl;
		password = input_string();
		if (is_password_correct(password))
			flag = false;
		else
		{
			system("cls");
			cout << "  ��������� ������������ ��������� ���� ������!";
		}
	}
	return password;
}

bool is_login_correct(string login)
{
	bool correctness = true;
	for (int i = 0; i < login.size(); i++)
	if ((((int)login[i] < 48 || (int)login[i] > 57) && ((int)login[i] < 65 || (int)login[i] > 90) && ((int)login[i] < 97 || (int)login[i] > 122)) || login.size() > 32)
		correctness = false;
		return correctness;
}

bool is_password_correct(string password)
{
	bool correctness = true;
	for (int i = 0; i < password.size(); i++)
		if (password.size() > 32)
			correctness = false;
	return correctness;
}

string input_role_when_add_user()
{
	string role;
	your_account();
	while(true)
	{
		cout << "\n  ������� ������ ����� ������� ������: ";
		getline(cin, role);
		if (role.size() == 0)
			continue;
		if (role == "admin" || role == "1" || role == "0")
			return role;
		else
		{
			system("cls");
			your_account();
			cout << "\n  ������������ ����! ���������� �����.\n\n";
		}
	}
}

string input_role_when_edit_user()
{
	string role;
	while (true)
	{
		cout << "\n  ������� ����� ������ ������� ������: ";
		getline(cin, role);
		if (role.size() == 0)
			continue;
		if (role == "admin" || role == "1" || role == "0")
			return role;
		else
			cout << "\n  ������������ ����! ���������� �����.\n\n";
	}
}