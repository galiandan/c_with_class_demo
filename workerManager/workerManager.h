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

    // 显示职工信息
    void show_Emp();

    // 删除离职员工
    void Del_Emp();

    // 修改职员信息
    void Mod_Emp();

    // 查找职工信息
    void Find_Emp();

    // 按照编号排序
    void Sort_Emp();

    // 清空所有档案
    void Clean_File();

    // 空析构
    ~WorkerManager();

protected:
    int m_EmpNum;

    Worker **m_EmpArray;
};