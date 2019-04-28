#include "Header.h"

void authorization()
{
	read_from_file_with_users(); //Считываем в вектор из файла.
	string login, password, salt;
	is_logged_in = false; 
	bool wish_to_exit_when_fail = false;
	int fail_counter = 0;  //fail_counter - счётчик проваленных попыток входа.
	while (!is_logged_in && !wish_to_exit_when_fail)
	{
		cout << endl << "  Введите Ваш логин." << endl;
		login = input_string(); //Ввод логина.
		cout << endl << "  Введите ваш пароль." << endl;
		password = input_password_when_auth(); //Ввод пароля.
		account = 0; //Обнуляем счётчик.
		if (is_auth_successful(login, password, account, fail_counter))
			is_logged_in = true;
		else
		{
			unsuccessful_auth(fail_counter, wish_to_exit_when_fail);
			if (!wish_to_exit_when_fail)
			continue;
		}


		if (wish_to_exit_when_fail)
		{
			system("cls");
			is_logged_in = true;
			show_begin_menu();
		}
		else
			if (is_admin(account))
			{
				system("cls");
				show_admin_menu();
			}
			else
			{
				system("cls");
				//show_user_menu();
			}
	}
}

void unsuccessful_auth(int fail_counter, bool &wish_to_exit_when_fail)
{
	system("cls");
	wait_when_3_or_5_attempts(fail_counter); //Требование подождать 30/50 секунд для следующей попытки авторизации.
	if (fail_counter == 6) //Выход при 6 неудачных попытках входа.
	{
		cout << "  " << setfill('-') << setw(70) << " " << endl;
		cout << " |           ПРЕВЫШЕНО МАКСИМАЛЬНОЕ КОЛИЧЕСТВО ПОПЫТОК ВХОДА!          |" << endl;
		cout << " |" << setfill('-') << setw(70) << " |" << endl;
		cout << " |    ********   ****   ****   ****       *****    **    **   *****    | " << endl;
		cout << " |    *         *    * *    *  *    *     *    *     ****     *        | " << endl;
		cout << " |    *         *    * *    *  *    *     *****       **      *****    | " << endl;
		cout << " |    *   ***** *    * *    *  *    *     *    *      **      *        | " << endl;
		cout << " |    *   *   * *    * *    *  *    *     *    *      **      *        | " << endl;
		cout << " |    ********   ****   ****   ****       ******      **      *****    | " << endl;
		cout << "  " << setfill('-') << setw(70) << " " << endl << endl;
		is_logged_in = true;
		return;
	}

	cout << endl << "  Неверный логин или пароль!" << endl;
	show_unsuccessful_auth_menu(fail_counter);
	int answer = choose_number(0, 1);
	switch (answer)
	{
	case 1:
		system("cls");
		break;
	case 0:
		wish_to_exit_when_fail = true;
	}
}

void wait_when_3_or_5_attempts(int fail_counter)
{
	if (fail_counter == 3 || fail_counter == 5)
	{
		int time, delta;
		if (fail_counter == 3)
			time = 30;
		else
			time = 50;
		for (int i = time; i != 0; i--)
		{
			cout << "  " << setfill('-') << setw(42) << " " << endl;
			if (i < 10)
				delta = 3;
			else
				delta = 2;
			cout << " | ПОВТОРИТЕ ПОПЫТКУ АВТОРИЗАЦИИ ЧЕРЕЗ |" << i << setfill(' ') << setw(delta) << "|" << endl;
			cout << "  " << setfill('-') << setw(42) << " " << endl;
			Sleep(1000);
			system("cls");
		}
	}
}

bool is_auth_successful(string login , string password, int &account, int &fail_counter)
{
	bool auth = false;
	for (account = 0; account < v_users.size(); account++)
	{
		if (v_users.at(account).login == login)
			if (v_users.at(account).password == hash_password(v_users.at(account).salt + password + v_users.at(account).salt))
			{
				auth = true;
				return auth;
			}
	}
	if (auth == false)
		fail_counter++;
		return auth;
}

bool is_admin(int account)
{
	bool admin = true;
	if (v_users.at(account).role == "1" || (v_users.at(account).role == "admin"))
		return admin;
	else
		admin = false;
	return admin;
}

void your_account()
{
	int delta1 = 33 - v_users.at(account).login.size();
	int delta2;
	if (v_users.at(account).role == "admin")
		delta2 = 0;
	else
		delta2 = 5;
	cout << endl << "  " << setfill('-') << setw(62) << " " << endl;
	cout << " | ВЫ ВОШЛИ ПОД ЛОГИНОМ |" << v_users.at(account).login << setfill(' ') << setw(delta1) << "|" << v_users.at(account).role << setfill(' ') << setw(delta2) << "|" << endl;
	cout << "  " << setfill('-') << setw(62) << " " << endl;
}