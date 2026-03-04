#pragma once
#include <iostream>
#include "worker.h"

class Boss : public Worker
{
public:
    // 空构造
    Boss();
    Boss(int, std::string, int);

    // 显示个人信息
    virtual void showInfo() override;

    // 获取岗位名称
    virtual std::string getDeptName() override;

    // 获得个人ID
    virtual int getId() override;

    // 获得个人名字
    virtual std::string getName() override;

    // 修改姓名
    virtual void modName() override;

    // 修改部门
    virtual void modDept() override;

    // 修改ID
    virtual void modId() override;
};