#pragma once
#include <iostream>
#include "../member/worker.h"
#include "../member/employee.h"
#include "../member/manager.h"
#include "../member/boss.h"

class WorkerManager
{
public:
    // 空构造
    WorkerManager();

    // 展示菜单
    void ShowMenu();

    // 退出功能
    void ExitSystem();

    // 添加职工
    void Add_Emp();

    // 空析构
    ~WorkerManager();

protected:
    int m_EmpNum;

    Worker **m_EmpArray;
};