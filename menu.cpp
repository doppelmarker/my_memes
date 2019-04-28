#include "Header.h"

void show_begin_menu()
{
	cout << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	cout << " | № |  ПРОГРАММА ДЛЯ УЧЁТА СВЕДЕНИЙ О МУЗЫКАЛЬНОМ КОНКУРСЕ " << setfill(' ') << setw(2) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 1 |       Войти в аккаунт " << setfill(' ') << setw(33) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 0 |       Выход " << setfill(' ') << setw(43) << "|" << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	choose_answer(2, authorization);
}

void show_admin_menu()
{
	your_account();
	cout << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	cout << " | № |                МОДУЛЬ АДМИНИСТРАТОРА                  |" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 1 |       Управление учётными записями пользователей " << setfill(' ') << setw(6) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 2 |       Работа с данными " << setfill(' ') << setw(32) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 0 |       Выход из учётной записи " << setfill(' ') << setw(25) << "|" << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	choose_answer(3, show_begin_menu, show_users_managment_menu, show_working_with_data_menu);
}

void show_users_managment_menu()
{
	your_account();
	cout << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	cout << " | № |      УПРАВЛЕНИЕ УЧЁТНЫМИ ЗАПИСЯМИ ПОЛЬЗОВАТЕЛЕЙ " << setfill(' ') << setw(7) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 1 |       Просмотреть список учётных записей " << setfill(' ') << setw(14) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 2 |       Редактировать данные учётной записи " << setfill(' ') << setw(13) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 3 |       Зарегистрировать новую учётную запись " << setfill(' ') << setw(11) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 4 |       Удалить учётную запись " << setfill(' ') << setw(26) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 0 |       Назад " << setfill(' ') << setw(43) << "|" << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	choose_answer(5, show_admin_menu, show_users, edit_user, add_user, delete_user);
}

void show_unsuccessful_auth_menu(int fail_counter)
{
	cout << endl;
	cout << "  " << setfill('-') << setw(41) << " " << endl;
	cout << " | Количество неудачных попыток входа | " << fail_counter << " |" << endl;
	cout << " |" << setfill('-') << setw(41) << "|" << endl;
	cout << " | 1 | Продолжить попытку входа           |" << endl;
	cout << " |" << setfill('-') << setw(41) << "|" << endl;
	cout << " | 0 | Прервать попытку входа             |" << endl;
	cout << "  " << setfill('-') << setw(41) << " " << endl;
}

void show_working_with_data_menu()
{
	your_account();
	cout << endl;
	cout << "  " << setfill('-') << setw(41) << " " << endl;
	cout << " | № |         РАБОТА С ДАННЫМИ     " << setfill(' ') << setw(7) << "|" << endl;
	cout << " |" << setfill('-') << setw(41) << "|" << endl;
	cout << " | 1 |       Режим редактирования  " << setfill(' ') << setw(8) << "|" << endl;
	cout << " |" << setfill('-') << setw(41) << "|" << endl;
	cout << " | 2 |       Режим обработки данных  " << setfill(' ') << setw(6) << "|" << endl;
	cout << " |" << setfill('-') << setw(41) << "|" << endl;
	cout << " | 0 |       Назад  " << setfill(' ') << setw(23) << "|" << endl;
	cout << "  " << setfill('-') << setw(41) << " " << endl;
	choose_answer(3, show_admin_menu /**/ /**/);
}

void show_data_management_menu()
{
	//your_account();
	cout << endl;
	cout << "  " << setfill('-') << setw(60) << " " << endl;
	cout << " | № |             РЕЖИМ РЕДАКТИРОВАНИЯ ДАННЫХ         " << setfill(' ') << setw(7) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 1 |       Просмотреть список участников конкурса " << setfill(' ') << setw(10) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 2 |       Редактировать данные участника конкурса " << setfill(' ') << setw(9) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 3 |       Зарегистрировать нового участника конкурса " << setfill(' ') << setw(6) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 4 |       Удалить участника конкурса " << setfill(' ') << setw(22) << "|" << endl;
	cout << " |" << setfill('-') << setw(60) << "|" << endl;
	cout << " | 0 |       Назад " << setfill(' ') << setw(43) << "|" << endl;
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
				cout << endl << " Список учётных записей пуст!" << endl;
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