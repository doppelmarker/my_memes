#include "Header.h"

void show_begin_menu()
{
	cout << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	cout << " | � |  ��������� ��� �ר�� �������� � ����������� �������� " << setfill(' ') << setw(2) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 1 |       ����� � ������� " << setfill(' ') << setw(33) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 0 |       ����� " << setfill(' ') << setw(43) << "|" << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	choose_answer(2, authorization);
}

void show_admin_menu()
{
	your_account();
	cout << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	cout << " | � |                ������ ��������������                  |" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 1 |       ���������� �������� �������� ������������� " << setfill(' ') << setw(6) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 2 |       ������ � ������� " << setfill(' ') << setw(32) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 0 |       ����� �� ������� ������ " << setfill(' ') << setw(25) << "|" << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	choose_answer(3, show_begin_menu, show_users_managment_menu, show_working_with_data_menu);
}

void show_users_managment_menu()
{
	your_account();
	cout << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	cout << " | � |      ���������� �ר����� �������� ������������� " << setfill(' ') << setw(7) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 1 |       ����������� ������ ������� ������� " << setfill(' ') << setw(14) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 2 |       ������������� ������ ������� ������ " << setfill(' ') << setw(13) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 3 |       ���������������� ����� ������� ������ " << setfill(' ') << setw(11) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 4 |       ������� ������� ������ " << setfill(' ') << setw(26) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 0 |       ����� " << setfill(' ') << setw(43) << "|" << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	choose_answer(5, show_admin_menu, show_users, edit_user, add_user, delete_user);
}

void show_unsuccessful_auth_menu(int fail_counter)
{
	cout << endl;
	cout << "  " << setfill('-') << setw(41) << " " << endl;
	cout << " | ���������� ��������� ������� ����� | " << fail_counter << " |" << endl;
	cout << " |" << setfill('-') << setw(41) << "|" << endl;
	cout << " | 1 | ���������� ������� �����           |" << endl;
	cout << " |" << setfill('-') << setw(41) << "|" << endl;
	cout << " | 0 | �������� ������� �����             |" << endl;
	cout << "  " << setfill('-') << setw(41) << " " << endl;
}

void show_working_with_data_menu()
{
	your_account();
	cout << endl;
	cout << "  " << setfill('-') << setw(41) << " " << endl;
	cout << " | � |         ������ � �������     " << setfill(' ') << setw(7) << "|" << endl;
	cout << " |" << setfill('-') << setw(41) << "|" << endl;
	cout << " | 1 |       ����� ��������������  " << setfill(' ') << setw(8) << "|" << endl;
	cout << " |" << setfill('-') << setw(41) << "|" << endl;
	cout << " | 2 |       ����� ��������� ������  " << setfill(' ') << setw(6) << "|" << endl;
	cout << " |" << setfill('-') << setw(41) << "|" << endl;
	cout << " | 0 |       �����  " << setfill(' ') << setw(23) << "|" << endl;
	cout << "  " << setfill('-') << setw(41) << " " << endl;
	choose_answer(3, show_admin_menu /**/ /**/);
}

void show_data_management_menu()
{
	//your_account();
	cout << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	cout << " | � |             ����� �������������� ������         " << setfill(' ') << setw(7) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 1 |       ����������� ������ ���������� �������� " << setfill(' ') << setw(10) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 2 |       ������������� ������ ��������� �������� " << setfill(' ') << setw(9) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 3 |       ���������������� ������ ��������� �������� " << setfill(' ') << setw(6) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 4 |       ������� ��������� �������� " << setfill(' ') << setw(22) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 0 |       ����� " << setfill(' ') << setw(43) << "|" << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	//choose_answer()

}

void choose_answer(int answer, void(*func0)(), void(*func1)(), void(*func2)(), void(*func3)(), void(*func4)(), void(*func5)())
{
	int choice;
	if (answer == 2)
	{
		choice = choose_number(0, 1);
		switch (choice)
		{
		case 1:
			system("cls");
			func0();
			break;
		case 0:
			system("cls");
			break;
		}
	}
	else if (answer == 3)
	{
		choice = choose_number(0, 2);
		switch (choice)
		{
		case 1:
			system("cls");
			func1();
			break;
		case 2:
			system("cls");
			func2();
			break;
		case 0:
			system("cls");
			func0();
			break;
		}
	}
	else if (answer == 4)
	{
		choice = choose_number(0, 3);
		switch (choice)
		{
		case 1:
			system("cls");
			func1();
			break;
		case 2:
			system("cls");
			func2();
			break;
		case 3:
			system("cls");
			func3();
			break;
		case 0:
			system("cls");
			func0();
			break;
		}
	}
	else if (answer == 5)
	{
		choice = choose_number(0, 4);
		switch (choice)
		{
		case 1:
			system("cls");
			read_from_file_with_users();
			if (v_users.empty())
			{
				cout << endl << " ������ ������� ������� ����!" << endl;
				show_users_managment_menu();
				break;
			}
			func1();
			show_users_managment_menu();
			break;
		case 2:
			system("cls");
			func2();
			break;
		case 3:
			system("cls");
			func3();
			break;
		case 4:
			system("cls");
			func4();
			break;
		case 0:
			system("cls");
			func0();
			break;
		}
	}
	else if (answer == 6)
	{
		choice = choose_number(0, 5);
		switch (choice)
		{
		case 1:
			system("cls");
			func1();
			break;
		case 2:
			system("cls");
			func2();
			break;
		case 3:
			system("cls");
			func3();
			break;
		case 4:
			system("cls");
			func4();
			break;
		case 5:
			system("cls");
			func5();
			break;
		case 0:
			system("cls");
			func0();
			break;
		}
	}
}