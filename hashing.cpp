#include "Header.h"

string create_salt()
{
	srand(time(NULL));
	string salt;
	int variant, size = rand() % (25 - 10 + 1) + 10; //����� ������ ���� �� 10 �� 25 ��������.
	char symbol;
	for (int i = 0; i < size; i++)
	{
		variant = rand() % (3 - 1 + 1) + 1;
		if (variant == 1)
			symbol = rand() % (57 - 48 + 1) + 48; //�����.
		if (variant == 2)
			symbol = rand() % (90 - 65 + 1) + 65; //����� �������� ��������.
		if (variant == 3)
			symbol = rand() % (122 - 97 + 1) + 97; //����� ������� ��������.
		salt += symbol;
	}
	return salt;
}

string hash_password(string password)
{
	hash<string> hash_str;
	size_t hash = hash_str(password);
	int digit_hash = hash;
	string hashed_password = to_string(digit_hash);
	return hashed_password;
}