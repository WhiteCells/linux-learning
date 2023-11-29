/*
    #include <unistd.h>
    // 将文件系统缓存提交到磁盘

    // sync（update 守护进程会周期性(一般每隔30s)的调用 sync 函数。命令 sync 也会调用 sync 函数）：
    // 将所有修改过的块缓冲区排入写队列
    // 不等待实际写磁盘操作结束
    void sync(void);

    #include <unistd.h>
    // 将文件的内核状态与存储设备同步

    // 只对由 fd 指定的单个文件起作用
    // 等待写磁盘操作结束才返回
    // 会同时更新文件的属性
    int fsync(int fd);
        argument:
            - fd: 指定写回的文件

        return:
            - 成功返回 0
            - 失败返回 -1，并设置 errno

    // 只影响文件的数据部分
    // 等待写磁盘操作结束才返回
    int fdatasync(int fd);
 */