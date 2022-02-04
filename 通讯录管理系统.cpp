#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//联系人结构体
struct Person
{
	string m_Name;
	int  m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};
//添加联系人
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size==MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		cout << "请输入性别:" << endl;
		cout << "1  ---  男" << endl;
		cout << "2  ---  女" << endl;
		int sex = 0;
		
		while (true)
		{
			cin >> sex;
			if (sex==1||sex==2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		cout << "请输入年龄:" << endl;
		int age = 0;
		while (true)
		{
			
			cin >> age;
			if (age > 0 && age<150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		
		cout << "请输入联系电话:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		cout << "请输入家庭住址:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		abs->m_Size++;//更新
		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏
	}
}
//显示联系人
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex==1?"男":"女")<< "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone<< "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << endl;

		}
	}
	system("pause");
	system("cls");
}
//检查联系人是否存在，存在返回其在数组中位置，不存在返回-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if ( ret!= -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");//清屏
}
//查找联系人
void findPerson(Addressbooks *abs)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");//清屏
}
//修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		cout << "请输入性别:" << endl;
		cout << "1  ---  男" << endl;
		cout << "2  ---  女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		cout << "请输入年龄:" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}
		cout << "请输入联系电话:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		cout << "请输入家庭住址:" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");//清屏
}
//清空联系人
void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");//清屏
}
//菜单界面
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
}
int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true)
	{
		showMenu();//菜单
		cin >> select;
		switch (select)
		{
		case 1://1.添加联系人
			addPerson(&abs);//地址传递，可以修饰实参
			break;
		case 2://2.显示联系人
			showPerson(&abs);
			break;
		case 3://3.删除联系人
			deletePerson(&abs);
			break;
		case 4://4.查找联系人
			findPerson(&abs);
			break;
		case 5://5.修改联系人
			modifyPerson(&abs);
			break;
		case 6://6.清空联系人
			clearPerson(&abs);
			break;
		case 0://0.退出通讯录
			cout << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "请重新输入" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}


//不在全局区：局部变量，const修饰局部变量
//全局区：全局变量，静态变量，static关键字，常量，字符串常量，const修饰全局变量