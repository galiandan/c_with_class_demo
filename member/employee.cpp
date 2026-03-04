#include "employee.h"

// 构造
Employee::Employee(int Id, std::string name, int dId)
{
    this->m_Id = Id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

// 显示个人信息
void Employee::showInfo()
{
    std::cout << "职工编号:" << this->m_Id
              << "\t职工姓名:" << this->m_Name
              << "\t岗位:" << this->getDeptName()
              << "\t岗位职责：完成经理交给的任务" << std::endl;
}

// 获取岗位名称
std::string Employee::getDeptName()
{
    return std::string("员工");
}

// 获取个人ID
int Employee::getId()
{
    return this->m_Id;
}

// 获取个人名字
std::string Employee::getName()
{
    return this->m_Name;
}

// 修改姓名
void Employee::modName()
{
    std::cout << "请输入新的姓名：";
    std::cin >> this->m_Name;
}

// 修改部门
void Employee::modDept()
{
    std::cout << "请输入新的部门编号：";
    std::cin >> this->m_DeptId;
}

// 修改ID
void Employee::modId()
{
    std::cout << "请输入新的ID：";
    std::cin >> this->m_Id;
}
