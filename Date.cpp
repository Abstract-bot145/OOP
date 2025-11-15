#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;

public:
	void Init(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}

	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	void setYear(int y) { year = y; }
	void setMonth(int m) { month = m; }
	void setDay(int d) { day = d; }

	void display()
	{
		cout << year << "年" << month << "月" << day << "日";
	}

	int calWeekday()
	{
		int y = year;
		int m = month;
		int d = day;

		if (m == 1 || m == 2)
		{
			m += 12;
			y--;
		}

		int weekday = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;

		return weekday;
	}

	void displayWeekday()
	{
		int weekday = calWeekday();
		string weekdays[] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
		cout << weekdays[weekday];
	}
};

int main() {
	Date today;
	today.Init(2025, 7, 15);

	cout << "日期: ";
	today.display();
	cout << "，";
	today.displayWeekday();
	cout << endl;

	today.setYear(2026);
	today.setMonth(8);
	today.setDay(20);

	cout << "修改后日期: ";
	today.display();
	cout << "，";
	today.displayWeekday();
	cout << endl;

	return 0;
}