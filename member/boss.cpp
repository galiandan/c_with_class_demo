#include "boss.h"

// 构造
Boss::Boss(int Id, std::string name, int dId)
{
    this->m_Id = Id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

// 显示职工信息
void Boss::showInfo()
{
    std::cout << "职工编号:" << this->m_Id
              << "\t职工姓名:" << this->m_Name
              << "\t岗位:" << this->getDeptName()
              << "\t岗位职责：管理公司的全部事物" << std::endl;
}

// 获取岗位名称
std::string Boss::getDeptName()
{
    return std::string("老板");
}

// 获取个人ID
int Boss::getId()
{
    return this->m_Id;
}

// 获取个人名字
std::string Boss::getName()
{
    return this->m_Name;
}

// 修改姓名
void Boss::modName()
{
    std::cout << "请输入新的姓名：";
    std::cin >> this->m_Name;
}

// 修改部门
void Boss::modDept()
{
    std::cout << "请输入新的部门编号：";
    std::cin >> this->m_DeptId;
}

// 修改ID
void Boss::modId()
{
    std::cout << "请输入新的ID：";
    std::cin >> this->m_Id;
}
