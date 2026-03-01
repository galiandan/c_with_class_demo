#include "workerManager.h"
#include <iostream>

// 空构造
WorkerManager::WorkerManager()
{
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

// 空析构
WorkerManager::~WorkerManager()
{
}