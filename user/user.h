struct stat;
struct rtcdate;

// system calls
 // 创建子进程
int fork(void);
// 终止当前进程的执行，并返回到父进程
// int：表示进程退出的状态码
int exit(int) __attribute__((noreturn)); 
// 等待子进程终止，并返回子进程的ID
// int*：指向一个整型变量的指针，用于存储子进程的退出状态
int wait(int*);
// 创建一个管道，用于进程间的通信
// int*：指向一个整型数组的指针，用于存储创建的管道的读写文件描述符
int pipe(int*);
// 写入数据到文件中
//int：表示文件描述符，指示要写入的文件。
// const void*：指向要写入的数据的指针。
// int：表示要写入的字节数
int write(int, const void*, int);
// 从文件中读取数据
// int：表示文件描述符，指示要读取的文件
// void*：指向接收读取数据的缓冲区的指针
// int：表示要读取的字节数
int read(int, void*, int);
// 关闭文件描述符
// int：表示要关闭的文件描述符
int close(int);
// 向指定的进程发送信号，终止进程的执行
// int：表示要终止的进程的进程ID
int kill(int);
int exec(char*, char**);
// 打开一个文件，并返回一个新的文件描述符
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);

// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void fprintf(int, const char*, ...);
void printf(const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
int memcmp(const void *, const void *, uint);
void *memcpy(void *, const void *, uint);
