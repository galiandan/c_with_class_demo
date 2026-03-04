#include "manager.h"

// 构造
Manager::Manager(int Id, std::string name, int dId)
{
    this->m_Id = Id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

// 显示职员信息
void Manager::showInfo()
{
    std::cout << "职工编号:" << this->m_Id
              << "\t职工姓名:" << this->m_Name
              << "\t岗位:" << this->getDeptName()
              << "\t岗位职责：完成老板交给的任务，并下发给员工" << std::endl;
}

// 获取岗位名称
std::string Manager::getDeptName()
{
    return std::string("经理");
}

// 获取个人ID
int Manager::getId()
{
    return this->m_Id;
}

// 获取个人名字
std::string Manager::getName()
{
    return this->m_Name;
}

// 修改姓名
void Manager::modName()
{
    std::cout << "请输入新的姓名：";
    std::cin >> this->m_Name;
}

// 修改部门
void Manager::modDept()
{
    std::cout << "请输入新的部门编号：";
    std::cin >> this->m_DeptId;
}

// 修改ID
void Manager::modId()
{
    std::cout << "请输入新的ID：";
    std::cin >> this->m_Id;
}
