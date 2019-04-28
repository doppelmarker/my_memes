#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

const string FILE_OF_PARTICIPANTS = "D://Fundamentals_of_algorithmization_and_programming//Partitcipants.txt";
const string FILE_OF_USERS = "D://Fundamentals_of_algorithmization_and_programming//Users.txt";

struct User {
	string login;
	string password;
	string salt;
	string role;
};

struct Participant {
	string name;
	int year_of_birth;
	string country;
	string instrument;
	int place;
};

extern User user;
extern Participant participant;

extern bool is_logged_in;

extern int account;

extern vector<User> v_users;
extern vector<Participant> v_participants;

void show_begin_menu();
void show_admin_menu();
void show_users_managment_menu();
void show_unsuccessful_auth_menu(int fail_counter);
void show_data_management_menu();
void choose_answer(int answer, void(*func0)() = NULL, void(*func1)() = NULL, void(*func2)() = NULL, void(*func3)() = NULL, void(*func4)() = NULL, void(*func5)() = NULL);

void superadmin_account_creation();
void show_users();
void add_user();
void edit_user();
void show_user_to_edit(int number);
bool is_only_one_superadmin();
void what_to_edit();
void delete_user();

void show_working_with_data_menu();

void read_from_file_with_users();
void write_to_file_with_users();

void authorization();
void unsuccessful_auth(int fail_counter, bool &is_logged_in);
void wait_when_3_or_5_attempts(int fail_counter);
bool is_auth_successful(string login, string password, int &account, int &fail_counter);
bool is_admin(int account);
void your_account();

bool is_number_numeric();
bool is_choose_range_correct(int number, int left_range, int right_range);
int choose_user(int left_range, int right_range, int number_of_students);
int choose_number(int left_range, int right_range);
string input_string();
string input_password_when_auth();
string input_login_when_add_user();
bool is_login_unique(string login);
string input_login_when_edit_user();
string input_password_when_add_user();
string input_password_when_edit_user();
bool is_login_correct(string login);
bool is_password_correct(string password);
string input_role_when_add_user();
string input_role_when_edit_user();

string create_salt();
string hash_password(string password);
