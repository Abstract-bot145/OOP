#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

using namespace std;


const double FEE_RATE = 0.02;
const double WARNING_BALANCE = 10.0;


struct Card
{
	long long id;
	string name;
	double balance;
	int transactions;
};


namespace card
{
	void printLine(char c = '-', int len = 60)
	{
		for (int i = 0; i < len; ++i)
			cout << c;
		cout << endl;
	}

	void title(const string& s)
	{
		cout << "\n=== " << s << " ===\n";
	}
}


Card* createCards(int n)
{
	try
	{
		Card* p = new Card[n];
		return p;
	}
	catch (const bad_alloc& e)
	{
		cerr << "内存分配失败: " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

void destroyCards(Card* p)
{
	delete[] p;
}


void inputCards(Card* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "请输入学号、姓名和初始余额: ";
		try
		{
			cin >> arr[i].id >> arr[i].name >> arr[i].balance;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				throw runtime_error("输入格式错误，请输入正确的数据类型。");
			}
			if (arr[i].balance < 0)
			{
				throw invalid_argument("初始余额不能为负数！");
			}
			arr[i].transactions = 0;
			cout << "账户创建成功！" << endl;
		}
		catch (const exception& e)
		{
			cout << "输入异常：" << e.what() << endl;
			i--;
		}
	}
}


void deposit(Card& c, double amount, double fee = FEE_RATE)
{
	try
	{
		if (amount < 0)
			throw invalid_argument("充值金额不能为负数！");

		double feeAmount = amount * fee;
		double netAmount = amount - feeAmount;

		c.balance += netAmount;
		c.transactions++;

		cout << "充值成功！充值 " << amount << " 元，手续费 " << feeAmount
			<< " 元，实际到账 " << netAmount << " 元" << endl;
	}
	catch (const exception& e)
	{
		cout << "充值异常：" << e.what() << endl;
	}
}


bool spend(Card& c, double cost)
{
	if (c.balance >= cost)
	{
		c.balance -= cost;
		c.transactions++;
		return true;
	}
	return false;
}

bool spend(Card& c, double cost, const string& item)
{
	cout << "消费项目：" << item << endl;
	try
	{
		if (cost < 0)
			throw invalid_argument("消费金额不能为负数！");
		if (c.balance < cost)
			throw runtime_error("余额不足，消费失败！");

		c.balance -= cost;
		c.transactions++;
		cout << "消费成功！扣除 " << cost << " 元" << endl;
		return true;
	}
	catch (const exception& e)
	{
		cout << "消费异常：" << e.what() << endl;
		return false;
	}
}


void showBalance(const Card& c)
{
	cout << c.name << "(" << c.id << ") 当前余额为: " << c.balance << " 元" << endl;
	if (c.balance < WARNING_BALANCE) {
		cout << "⚠️  余额不足预警！请及时充值。" << endl;
	}
}

void viewStudentID(const Card* p)
{
	cout << "账户ID为: " << p->id << endl;
}


int toCent(double amount)
{
	return static_cast<int>(amount * 100);
}


void printReport(const Card* arr, int n)
{
	using card::printLine;
	card::title("账户报表");
	printLine('=');
	cout << left << setw(16) << "ID"
		<< setw(12) << "Name"
		<< right << setw(14) << "Balance"
		<< setw(14) << "Transactions" << endl;
	printLine('=');

	cout.setf(ios::fixed);
	cout << setprecision(2);

	for (int i = 0; i < n; ++i)
	{
		cout << left << setw(16) << arr[i].id
			<< setw(12) << arr[i].name
			<< right << setw(14) << arr[i].balance
			<< setw(14) << arr[i].transactions << endl;
	}
	printLine('=');
}


Card* findUserByID(Card* users, int n, long long targetID) {
	for (int i = 0; i < n; i++) {
		if (users[i].id == targetID) {
			return &users[i];
		}
	}
	return nullptr;
}


void showMenu() {
	cout << "\n===== 校园一卡通消费管理系统 =====" << endl;
	cout << "1. 账户充值" << endl;
	cout << "2. 账户消费" << endl;
	cout << "3. 查询余额" << endl;
	cout << "4. 查看报表" << endl;
	cout << "5. 退出系统" << endl;
	cout << "请选择操作: ";
}


int main()
{
	using card::title;

	title("校园一卡通消费管理系统");

	int n;
	cout << "请输入学生数量: ";
	cin >> n;

	Card* users = createCards(n);
	inputCards(users, n);

	
	while (true) {
		showMenu();

		int choice;
		cin >> choice;

		if (choice == 5) {
			cout << "感谢使用校园一卡通系统，再见！" << endl;
			break;
		}

		long long studentID;
		Card* currentUser = nullptr;

		if (choice >= 1 && choice <= 3) {
			cout << "请输入学号: ";
			cin >> studentID;
			currentUser = findUserByID(users, n, studentID);
			if (!currentUser) {
				cout << "未找到学号 " << studentID << " 对应的用户！" << endl;
				continue;
			}
		}

		switch (choice) {
		case 1: {
			double amount;
			cout << "请输入充值金额: ";
			cin >> amount;
			deposit(*currentUser, amount);
			break;
		}
		case 2: { 
			double cost;
			string item;
			cout << "请输入消费金额: ";
			cin >> cost;
			cout << "请输入消费项目: ";
			cin >> item;
			spend(*currentUser, cost, item);
			break;
		}
		case 3:
			showBalance(*currentUser);
			break;
		case 4:
			printReport(users, n);
			break;
		default:
			cout << "无效选择！请重新选择。" << endl;
		}
	}

	destroyCards(users);
	system("pause");
	return 0;
}