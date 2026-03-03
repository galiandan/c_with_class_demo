#include "workerManager.h"

// 构造
WorkerManager::WorkerManager()
{
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}

// 展示菜单
void WorkerManager::ShowMenu()
{
    for (int i = 0; i < 44; i++)
    {
        std::cout << "*";
    }
    std::cout << "\n";
    std::cout << "********** 欢迎使用职工管理系统！***********" << std::endl;
    std::cout << "************** 0.退出管理系统 **************" << std::endl;
    std::cout << "************** 1.增加职工信息 **************" << std::endl;
    std::cout << "************** 2.显示职工信息 **************" << std::endl;
    std::cout << "************** 3.删除离职员工 **************" << std::endl;
    std::cout << "************** 4.修改职工信息 **************" << std::endl;
    std::cout << "************** 5.查找职工信息 **************" << std::endl;
    std::cout << "************** 6.按照编号排序 **************" << std::endl;
    std::cout << "************** 7.清空所有档案 **************" << std::endl;
    for (int i = 0; i < 44; i++)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
}

// 退出功能
void WorkerManager::ExitSystem()
{
    std::cout << "欢迎下次使用" << std::endl;
    system("pause");
    exit(0);
}

// 添加职工
void WorkerManager::Add_Emp()
{
    while (1)
    {
        std::cout << "请输入添加的职工的数量" << std::endl;
        int addNum = 0;
        std::cin >> addNum;
        if (addNum > 0)
        {
            int newSize = this->m_EmpNum + addNum;

            Worker **newspace = new Worker *[newSize];

            if (this->m_EmpArray != NULL)
            {
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    newspace[i] = this->m_EmpArray[i];
                }
            }
            for (int i = 0; i < addNum; i++)
            {
                int id;
                std::string name;
                int dSelect;
                std::cout << "现在已有" << this->m_EmpNum << "名员工,";
                std::cout << "请输入第" << this->m_EmpNum + i + 1 << "个新员工编号：" << std::endl;
                std::cin >> id;

                std::cout << "请输入第" << this->m_EmpNum + i + 1 << "个新员姓名：" << std::endl;
                std::cin >> name;

                std::cout << "请选择该职工岗位" << std::endl;
                std::cout << "1、普通职工" << std::endl;
                std::cout << "2、经理" << std::endl;
                std::cout << "3、老板" << std::endl;
                std::cin >> dSelect;

                Worker *worker = NULL;
                switch (dSelect)
                {
                case 1:
                    worker = new Employee(id, name, dSelect);
                    break;
                case 2:
                    worker = new Manager(id, name, dSelect);
                    break;
                case 3:
                    worker = new Boss(id, name, dSelect);
                    break;
                default:
                    break;
                }

                newspace[this->m_EmpNum + i] = worker;
            }

            // 释放原来数组指针
            delete[] this->m_EmpArray;

            // 更新新数组指针
            this->m_EmpArray = newspace;

            // 更新职工人数
            this->m_EmpNum = newSize;

            std::cout << "成功添加" << addNum << "名新员工" << std::endl;
            break;
        }
        else
        {
            std::cout << "输入有误" << std::endl;
        }
    }
    system("pause");
    system("cls");
}

// 显示职工信息
void WorkerManager::show_Emp()
{
    if (this->m_EmpNum == 0)
    {
        std::cout << "还未添加职工" << std::endl;
    }
    else
    {
        system("cls");
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

// 删除离职员工
void WorkerManager::Del_Emp()
{
    int choice = 0;
    std::cout << "请选择删除方式" << std::endl;
    std::cout << "1、按照编号删除 2、按照姓名删除" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int id;
        std::cout << "请输入要删除的职工编号：" << std::endl;
        std::cin >> id;
        int index = -1;
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArray[i]->getId() == id)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            std::cout << "未找到该职工编号" << std::endl;
        }
        else
        {
            std::cout << "找到职工编号为" << id << "的职工" << std::endl;
            std::cout << "信息为：" << std::endl;
            this->m_EmpArray[index]->showInfo();
            std::cout << "确认删除吗？" << std::endl;
            std::cout << "1、确认删除 2、取消删除" << std::endl;
            int select = 0;
            std::cin >> select;
            if (select == 2)
            {
                std::cout << "已取消删除" << std::endl;
                system("pause");
                system("cls");
                break;
            }
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            std::cout << "删除成功！" << std::endl;
            system("pause");
            system("cls");
        }
    }
    break;
    case 2:
    {
        std::string name;
        std::cout << "请输入要删除的职工姓名：" << std::endl;
        std::cin >> name;
        int index = -1;
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArray[i]->getName() == name)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            std::cout << "未找到该职工姓名" << std::endl;
        }
        else
        {
            std::cout << "找到职工姓名为" << name << "的职工" << std::endl;
            std::cout << "信息为：" << std::endl;
            this->m_EmpArray[index]->showInfo();
            std::cout << "确认删除吗？" << std::endl;
            std::cout << "1、确认删除 2、取消删除" << std::endl;
            int select = 0;
            std::cin >> select;
            if (select == 2)
            {
                std::cout << "已取消删除" << std::endl;
                system("pause");
                system("cls");
                break;
            }
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            std::cout << "删除成功！" << std::endl;
            system("pause");
            system("cls");
        }
    }
    break;

    default:
        break;
    }
}
// 空析构
WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            delete this->m_EmpArray[i];
            this->m_EmpArray[i] = NULL;
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}