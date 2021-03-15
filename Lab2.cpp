#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <istream>
#include <clocale>
#include <conio.h>
#include <string>

using namespace std;
class ATM
{
	bool ATM_condition;
	bool correct_pass;
	int daily_limit;
	int one_time_limit;
	int max_bills;
	int billArr[101]{};
	int billQuant[101]{ -1 };
	;//динамически можно в принципе
	string menuNumber[12] = { "0.","1.","2.","3.","4.", "5.","6.", "7.","8.","9.","10." };
	string cash_withdrawal = "Снятие наличных.\n";
	string work_stop = "Выход.\n";
	string dop_func = "?\n";
	string standard_sum = "Выбрать стандартную сумму.\n";
	string th5000 = "Вывести 5000";
	string non_standard_sum = "Ввести свою сумму.\n"; // сделать два конструктора, по умолчанию станд купюры, не по умолч станд куп+новые, но тогда нужен массив чисел или не констр, а сеттерами

public:
	ATM() //switch для случаев когда пятитысячных нет, чтобы не выводить в меню
	{
		for (int billNumbDiv100 = 1; billNumbDiv100 < 101; billNumbDiv100++)
			billArr[billNumbDiv100] = billNumbDiv100 * 100;
		for (int billNumbDiv100 = 1; billNumbDiv100 < 6; billNumbDiv100 = billNumbDiv100 + 4)
		{
			billQuant[billNumbDiv100] = 10;
			billQuant[billNumbDiv100 * 10] = 10;
		}
		billQuant[2] = 10;
		daily_limit = 28;
		one_time_limit = 12000;
		max_bills = 7;
	}
	void setMaxBills(int valueMaxBills)
	{
		max_bills = valueMaxBills;
	}
	void setDailyLimit(int valueDailyLimit)
	{
		daily_limit = valueDailyLimit;
	}
	void setOneTimeLimit(int valueOneTimeLimit)
	{
		one_time_limit = valueOneTimeLimit;
	}
	void setBill(int denomBill, int valueBillQuant)
	{
		if (denomBill != 0)
			billArr[denomBill / 100] = valueBillQuant;
	}
	void deletBill(int denomBill)
	{
		billArr[denomBill / 100] = -1;
	}
	void mainMenu()
	{
		cout << menuNumber[1] << cash_withdrawal << menuNumber[2] << work_stop; // через кейсы делать меню типа если купюра есть тру/фалс то вывести ее в меню и тд
	}
	void cash_withdMenu()
	{
		cout << menuNumber[1] << standard_sum << menuNumber[2] << non_standard_sum;
	}
	void standardSumMenu()
	{
		//cout << menuNumber[1] << bill_100 << menuNumber[2] << bill_200;
	}
	void issueStandardSum()
	{

	}
	void nonStandardSumMenu()
	{

	}
	void finish()
	{

	}
};

int main()
{
	setlocale(LC_ALL, "Russian_Russia.1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ATM user;
	return 0;
}