#include "Header.h"

User user;
Participant participant;

bool is_logged_in; //���������� ��� �������� �� ������ � �������.

int account; //���������� ��� ������������, � ������ �������� ���������� ����.

vector<User> v_users;
vector<Participant> v_participants;

int main()
{
	setlocale(LC_ALL, "RUS");
	system("chcp 1251>nul");
	superadmin_account_creation(); //��� ������ ������� ����� � �������������� �� ����������, ������ ��� � ��������� ������������������� (��� ���� ���� ����).
	show_begin_menu(); //��������� ����.
	system("pause");
	return 0;
}