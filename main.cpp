#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
    WorkerManager wm;
    int choice = 0;
    while (true)
    {
        wm.ShowMenu();

        std::cout << "请输入你的选择" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 0: // 退出管理系统
            wm.ExitSystem();
            break;
        case 1: // 增加职工信息
            wm.Add_Emp();
            break;
        case 2: // 显示职工信息
            wm.show_Emp();
            break;
        case 3: // 删除离职员工
            wm.Del_Emp();
            break;
        case 4: // 修改职工信息
            wm.Mod_Emp();
            break;
        case 5: // 查找职工信息
            wm.Find_Emp();
            break;
        case 6: // 按照编号排序
            wm.Sort_Emp();
            break;
        case 7: // 清空所有档案
            wm.Clean_File();
            break;
        default:
            system("cls");
            break;
        }
    }
}