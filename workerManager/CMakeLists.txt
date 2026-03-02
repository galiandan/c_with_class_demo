# 1. 直接定义库并列出文件
add_library(workerManager_lib STATIC 
    workerManager.cpp 
    workerManager.h
)

# 2. 设置包含目录
# 使用 '.' 代表当前目录，PUBLIC 确保根项目也能找到这里的头文件
target_include_directories(workerManager_lib PUBLIC .)