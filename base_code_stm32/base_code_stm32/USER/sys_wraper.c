#include <stdio.h>
#include <sys/stat.h>
#include "usart.h"
int _close_r(struct _reent *r, int fd)
{
    return -1; // 返回错误代码
}

int _fstat_r(struct _reent *r, int fd, struct stat *st)
{
    return -1; // 返回错误代码
}

int _getpid_r(struct _reent *r)
{
    return 1; // 返回一个固定的进程 ID，例如 1
}

int _isatty_r(struct _reent *r, int fd)
{
    return 0; // 假设没有终端设备，返回 0 表示不是终端
}

int _kill_r(struct _reent *r, int pid, int sig)
{
    return -1; // 返回错误代码，表示不支持
}

int _lseek_r(struct _reent *r, int fd, int pos, int whence)
{
    return -1; // 返回错误代码，表示不支持
}

int _read_r(struct _reent *r, int fd, void *buf, size_t count)
{
    return -1; // 返回错误代码，表示不支持
}

int _write(int fd, char *pBuffer, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
            ;
        USART_SendData(USART1, (uint8_t)*pBuffer++);
    }
    return size;
}