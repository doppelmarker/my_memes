#include "Header.h"

User user;
Participant participant;

bool is_logged_in; //Переменная для контроля за входом в аккаунт.

int account; //Переменная для отслеживания, с какого аккаунта осуществлён вход.

vector<User> v_users;
vector<Participant> v_participants;

int main()
{
	setlocale(LC_ALL, "RUS");
	system("chcp 1251>nul");
	superadmin_account_creation(); //При первом запуске файла с пользователями не существует, создаём его и добавляем суперадминистратора (или если файл пуст).
	show_begin_menu(); //Начальное окно.
	system("pause");
	return 0;
}