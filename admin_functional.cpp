#include "Header.h"

using namespace std;

void superadmin_account_creation()
{
	ifstream fin(FILE_OF_USERS, ios::in);	//fin.peek() ���������� ��� ���������� ������� � ����� � �������� "������� ������" �� ���� ������, ���� �� ���� ���� - (-1). fin.eof() ���������� 1, ���� ����� ����� ��� ���������, 0 - ���� ���.
	if (!fin.is_open() || fin.eof() == fin.peek() + 1)	//���� ����� � �������������� �� ����������,
	{
		ofstream fout(FILE_OF_USERS, ios::out); //�� ������ ��� � ��������� ������� ������������������� (��� ���� ���� ����������, �� ����).
		string salt = create_salt();
		string password = hash_password(salt + "sonne" + salt);
		fout << "rammstein" << " " << password << " " << salt << " "<< "admin";
		fout.close();
		return;
	}
	else
		fin.close();
}

void show_users()
{
	ifstream fin(FILE_OF_USERS, ios::in);
	cout << endl;
	cout << "  " << setfill('-') << setw(48) << " " << endl;
	cout << " |            ������ �ר���� �������             |" << endl;
	cout << " |" << setfill('-') << setw(48) << "|" << endl;
	cout << " |  �  |             �����              | ������ |" << endl;
	cout << " |" << setfill('-') << setw(48) << "|" << endl;
	int delta1;
	int delta2;
	int delta3 = 8;
	for (int i = 0; i < v_users.size(); i++)
	{
		if (i + 1 < 10)
			delta1 = 5;
		else
			delta1 = 4;
		delta3 = 8;
		if (v_users.at(i).role == "admin")
			delta3 = 4;
		delta2 = 33 - v_users.at(i).login.size();
		cout << " |" << i + 1 << setfill(' ') << setw(delta1) << "|" << v_users.at(i).login << setfill(' ') << setw(delta2) << "|" << v_users.at(i).role << setfill(' ') << setw(delta3) << "|" << endl;
		if (i < v_users.size() - 1)
		cout << " |" << setfill('-') << setw(48) << "|" << endl;
	}
	cout << "  " << setfill('-') << setw(48) << " " << endl;
	fin.close();
}

void add_user()
{
	ofstream fout(FILE_OF_USERS, ios::app);
	string login = input_login_when_add_user();
	fout << endl << login << " ";
	system("cls");
	string password = input_password_when_add_user();
	string salt = create_salt();
	password = hash_password(salt + password + salt); //����������� ������.
	fout << password << " ";
	fout << salt << " ";
	system("cls");
	string role = input_role_when_add_user();
	fout << role;
	system("cls");
	fout.close();
	cout << endl << "  ������� ������ ������� ���������!" << endl;
	show_users_managment_menu();
}

void edit_user()
{
	your_account();
	read_from_file_with_users();
	if (v_users.empty())
	{
		cout << endl << "  ������ ������� ������� ����!" << endl;
		show_users_managment_menu();
	}
	show_users();
	cout << endl << "  �������� ����� ������� ������, ������ ������� ������� ��������." << endl;
	int number = choose_number(1, v_users.size());
	if (v_users.at(account).role == "1" && number - 1 != account) //���� ������� ������ ����������� �������� ������ � �� �� ���������� ������������� ���� ������.
		if (v_users.at(number - 1).role == "admin" || v_users.at(number - 1).role == "1")
		{
			system("cls");
			cout << endl << "  ������� ������������� �� ����� ���� ��� ��������� ������� ������ ������������������� ��� ������ ���������������!" << endl;
			show_users_managment_menu();
			return;
		}
	show_user_to_edit(number);
	what_to_edit();
	string login, password, role;
	int answer = choose_number(1, 4);
	switch (answer)
	{
	case 1:
		while (true)
		{
			login = input_login_when_edit_user();
			if (is_login_unique(login))
			{
				v_users.at(number - 1).login = login;
				break;
			}
			else
				cout << endl << "  ����� ����� ��� �����!" << endl;
		}
		break;
	case 2:
		password = input_password_when_edit_user();
		v_users.at(number - 1).salt = create_salt();
		v_users.at(number - 1).password = hash_password(v_users.at(number-1).salt + password + v_users.at(number - 1).salt);
		break;
	case 3:
		role = input_role_when_edit_user();
		if (number - 1 == account) //��������� ����� ����������� ������� ������.
			if (v_users.at(number - 1).role == "1" && role == "admin")
			{
				system("cls");
				cout << endl << "  ������� ������������� �� ����� ��������� ���� ����� �������������������!" << endl;
				show_users_managment_menu();
				return;
			}
			if (v_users.at(number - 1).role == "admin" && role != "admin" && is_only_one_superadmin()) //��� �����������
			{
				system("cls");
				cout << endl << "  ������� ������������� ����������� ������������������� ����� ���� ����������!" << endl;
				show_users_managment_menu();
				return;
			}
		v_users.at(number - 1).role = role;
		break;
	case 4:
		while (true)
		{
			login = input_login_when_edit_user();
			if (is_login_unique(login))
				break;
			else
			cout << endl << "  ����� ����� ��� �����!" << endl;
		}
		password = input_password_when_edit_user();
		role = input_role_when_edit_user();
		if (number - 1 == account) //��������� ����� ����������� ������� ������.
			if (v_users.at(number - 1).role == "1" && role == "admin")
			{
				system("cls");
				cout << endl << "  ������� ������������� �� ����� ��������� ���� ����� �������������������!" << endl;
				show_users_managment_menu();
				return;
			}
			if (v_users.at(number - 1).role == "admin" && role != "admin" && is_only_one_superadmin())
			{
				system("cls");
				cout << endl << "  ������� ������������� ����������� ������������������� ����� ���� ����������!" << endl;
				show_users_managment_menu();
				return;
			}
		v_users.at(number - 1).login = login;
		v_users.at(number - 1).salt = create_salt();
		v_users.at(number - 1).password = hash_password(v_users.at(number - 1).salt + password + v_users.at(number - 1).salt);
		v_users.at(number - 1).role = role;
	}
	write_to_file_with_users();
	system("cls");
	cout << endl << "  ������ ������� ������ ������� ��������!" << endl;
	show_users_managment_menu();
}

bool is_only_one_superadmin()
{
	int counter = 0;
	for (int i = 0; i < v_users.size(); i++)
		if (v_users.at(i).role == "admin")
			counter++;
	if (counter == 1)
		return true;
	else return false;
}

void what_to_edit()
{
	cout << "  " << setfill('-') << setw(58) << " " << endl;
	cout << " | � |             ��� �� ������� ��������?                |" << endl;
	cout << " |" << setfill('-') << setw(58) << "|" << endl;
	cout << " | 1 | ������ �����." << setfill(' ') << setw(40) << "|" << endl;
	cout << " |" << setfill('-') << setw(58) << "|" << endl;
	cout << " | 2 | ������ ������." << setfill(' ') << setw(39) << "|" << endl;
	cout << " |" << setfill('-') << setw(58) << "|" << endl;
	cout << " | 3 | ������ ������." << setfill(' ') << setw(39) << "|" << endl;
	cout << " |" << setfill('-') << setw(58) << "|" << endl;
	cout << " | 4 | ��������� ������������ ������ ������� ������.       |" << endl;
	cout << "  " << setfill('-') << setw(58) << " " << endl;
}

void show_user_to_edit(int number)
{
	system("cls");
	your_account();
	cout << endl << "  " << setfill('-') << setw(42) << " " << endl;
	cout << " |             �����              | ������ |" << endl;
	cout << " |" << setfill('-') << setw(42) << "|" << endl;
	int delta1;
	int delta2 = 8;
	if (v_users.at(number - 1).role == "admin")
		delta2 = 4;
	delta1 = 33 - v_users.at(number - 1).login.size();
	cout << " |" << v_users.at(number - 1).login << setfill(' ') << setw(delta1) << "|"  << v_users.at(number - 1).role << setfill(' ') << setw(delta2) << "|" << endl;
	cout << "  " << setfill('-') << setw(42) << " " << endl;
}

void delete_user()
{
	your_account();
	read_from_file_with_users();
	if (v_users.empty()) //������� �� ���������
	{
		cout << endl << "  ������ ������� ������� ����!" << endl;
		show_users_managment_menu();
	}
	show_users();
	cout << endl << "  ������� ����� ������� ������, ������� ������� �������." << endl << endl;
	int number = choose_number(1, v_users.size());
	if (number - 1 == account) //�������� ����� ����������� ������� ������.
	{
		cout << endl << "  �� ������������� ������� ������� ���� �������?" << endl;
		cout << "  " << setfill('-') << setw(10) << " " << endl;
		cout << " | 1 | ��  |" << endl;
		cout << " |" << setfill('-') << setw(10) << "|" << endl;
		cout << " | 0 | ��� |" << endl;
		cout << "  " << setfill('-') << setw(10) << " " << endl;
		int answer = choose_number(0, 1);
		if (!answer)
		{
			system("cls");
			cout << endl << "  ���� ������� ������ �� ���� �������." << endl;
			show_users_managment_menu();
			return;
		}
		else
		if (v_users.at(number - 1).role == "admin" && is_only_one_superadmin())
		{
			system("cls");
			cout << endl <<"  �������� ��������� ���������� ������� ������ ������������������� ����������!" << endl;
			show_users_managment_menu();
			return;
		}
		v_users.erase(v_users.begin() + (number - 1));
		write_to_file_with_users();
		system("cls");
		cout << endl << "  �� ������� ������� ���� ������� ������!" << endl;
		show_begin_menu();
		return;
	}
	if (v_users.at(account).role == "1") //���� ������� ������ ����������� �������� ��������������.
		{
			system("cls");
			cout << endl << "  ������� ������������� �� ����� ���� ��� �������� ������� ������ ������������������� ��� ������ ���������������!" << endl;
			show_users_managment_menu();
			return;
		}
	v_users.erase(v_users.begin() + (number - 1));
	write_to_file_with_users();
	system("cls");
	cout << endl << "  ������� ������ ������� �������!" << endl;
	show_users_managment_menu();
}