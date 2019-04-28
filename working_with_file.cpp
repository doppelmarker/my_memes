#include "Header.h"

void read_from_file_with_users()
{
	v_users.clear();
	ifstream fin(FILE_OF_USERS, ios::in);
	int i = 0;
	if (fin.eof() != fin.peek() + 1)
	while (!fin.eof())
	{
		v_users.push_back(user);
		fin >> v_users.at(i).login >> v_users.at(i).password >> v_users.at(i).salt >> v_users.at(i).role;
		i++;
	}
	fin.close();
}

void write_to_file_with_users()
{
	ofstream fout(FILE_OF_USERS, ios::trunc);
	for (int i = 0; i < v_users.size(); i++)
	{
		fout << v_users.at(i).login << " " << v_users.at(i).password << " " << v_users.at(i).salt << " " << v_users.at(i).role;
		if (i < v_users.size() - 1)
			fout << endl;
	}
	fout.close();
}