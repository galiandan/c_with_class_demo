#include "workerManager.h"
// 构造
WorkerManager::WorkerManager()
{
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}

// 从文件中读取数据
void WorkerManager::readFile()
{
    std::fstream fs;
    fs.open("Date.txt", std::ios::in);

    if (!fs.is_open())
    {
        std::cout << "文件不存在或打开失败" << std::endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        return;
    }

    int id;
    std::string name;
    std::string deptId;
    int num = 0;

    while (fs >> id >> name >> deptId)
    {
        num++;
    }

    this->m_EmpNum = num;

    if (this->m_EmpNum == 0)
    {
        this->m_EmpArray = NULL;
        fs.close();
        return;
    }

    this->m_EmpArray = new Worker *[this->m_EmpNum];

    fs.clear();
    fs.seekg(0, std::ios::beg);

    int index = 0;
    while (fs >> id >> name >> deptId)
    {
        Worker *worker = NULL;
        int deptNum = 0;

        if (deptId == "员工")
        {
            deptNum = 1;
            worker = new Employee(id, name, deptNum);
        }
        else if (deptId == "经理")
        {
            deptNum = 2;
            worker = new Manager(id, name, deptNum);
        }
        else
        {
            deptNum = 3;
            worker = new Boss(id, name, deptNum);
        }

        this->m_EmpArray[index] = worker;
        index++;
    }

    fs.close();
}

// 向文件中写入数据
void WorkerManager::writeFile()
{
    std::fstream fs;
    fs.open("Date.txt", std::ios::out);

    if (!fs.is_open())
    {
        std::cout << "文件打开失败" << std::endl;
        return;
    }

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        fs << this->m_EmpArray[i]->getId() << " "
           << this->m_EmpArray[i]->getName() << " "
           << this->m_EmpArray[i]->getDeptName() << std::endl;
    }

    fs.close();
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
    WorkerManager::readFile();
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
    WorkerManager::writeFile();
    system("pause");
    system("cls");
}

// 显示职工信息
void WorkerManager::show_Emp()
{
    WorkerManager::readFile();
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
    WorkerManager::writeFile();
    system("pause");
    system("cls");
}

// 删除离职员工
void WorkerManager::Del_Emp()
{
    WorkerManager::readFile();
    int choice = 0;
    std::cout << "请选择删除方式" << std::endl;
    std::cout << "1、按照编号删除 2、按照姓名删除 3、取消删除操作" << std::endl;
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
            system("pause");
            system("cls");
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
            WorkerManager::writeFile();
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
            system("pause");
            system("cls");
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
            WorkerManager::writeFile();
            system("pause");
            system("cls");
        }
    }
    break;
    case 3:
    {
        std::cout << "已取消删除" << std::endl;
        system("pause");
        system("cls");
    }
    default:
        break;
    }
}

// 修改职员信息
void WorkerManager::Mod_Emp()
{
    WorkerManager::readFile();
    std::cout << "请选择通过1、编号查找修改 2、姓名查找修改" << std::endl;
    int choice = 0;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int id;
        std::cout << "请输入要修改的职工编号：" << std::endl;
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
            this->m_EmpArray[index]->modName();
            this->m_EmpArray[index]->modDept();
            this->m_EmpArray[index]->modId();
            std::cout << "修改成功！" << std::endl;
            WorkerManager::writeFile();
            system("pause");
        }
    }
    break;
    default:
        break;
    }
}

// 查找职工信息
void WorkerManager::Find_Emp()
{
    WorkerManager::readFile();
    std::cout << "请选择通过1、编号查找 2、姓名查找" << std::endl;
    int choice = 0;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int id;
        std::cout << "请输入要查找的职工编号：" << std::endl;
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
            WorkerManager::writeFile();
        }
    }
    break;
    default:
        break;
    }
}

// 按照编号排序
void WorkerManager::Sort_Emp()
{
    WorkerManager::readFile();
    for (int i = 0; i < this->m_EmpNum - 1; i++)
    {
        for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
        {
            if (this->m_EmpArray[j]->getId() > this->m_EmpArray[j + 1]->getId())
            {
                Worker *temp = this->m_EmpArray[j];
                this->m_EmpArray[j] = this->m_EmpArray[j + 1];
                this->m_EmpArray[j + 1] = temp;
            }
        }
    }
    std::cout << "排序成功！" << std::endl;
    WorkerManager::writeFile();
    system("pause");
    system("cls");
}

// 清空所有档案
void WorkerManager::Clean_File()
{
    WorkerManager::readFile();
    if (this->m_EmpArray != NULL)
    {
        std::cout << "确认清空吗？" << std::endl;
        std::cout << "1、确认清空 2、取消清空" << std::endl;
        int select = 0;
        std::cin >> select;
        if (select == 2)
        {
            std::cout << "已取消清空" << std::endl;
            system("pause");
            system("cls");
            return;
        }

        for (int i = 0; i < this->m_EmpNum; i++)
        {
            delete this->m_EmpArray[i];
            this->m_EmpArray[i] = NULL;
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
        this->m_EmpNum = 0;
        std::cout << "清空成功！" << std::endl;
        WorkerManager::writeFile();
        system("pause");
        system("cls");
    }
    else
    {
        std::cout << "当前没有数据！" << std::endl;
        system("pause");
        system("cls");
    }
}

// 析构
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