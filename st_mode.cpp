//
// Created by wq on 2021/7/19.
// 打印文件类型

#include <sys/stat.h>
#include <iostream>

#define MAXLINE 1024

static void
err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
    char	buf[MAXLINE];

    vsnprintf(buf, MAXLINE-1, fmt, ap);
    if (errnoflag)
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1, ": %s",
                 strerror(error));
    strcat(buf, "\n");
    fflush(stdout);		/* in case stdout and stderr are the same */
    fputs(buf, stderr);
    fflush(nullptr);		/* flushes all stdio output streams */
}

void
err_ret(const char *fmt, ...)
{
    va_list		ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
}

int main(int argc, char* argv[]){
    struct stat buf{};
    std::string str;
    for (int j = 1; j < argc; ++j) {
        std::cout << argv[j] << ' ' << std::flush;
        if (lstat(argv[j], &buf) < 0){
            err_ret("lstat error");
            continue;
        }
        if (S_ISREG(buf.st_mode)){
            str = "regular";
        }
        else if (S_ISDIR(buf.st_mode)){
            str = "directory";
        }
        else if (S_ISCHR(buf.st_mode)){
            str = "CHARACTER SPECIAL";
        }
        else if (S_ISBLK(buf.st_mode)){
            str = "BLOCK SPECIAL";
        }
        else if (S_ISFIFO(buf.st_mode)){
            str = "FIFO";
        }
        else if (S_ISLNK(buf.st_mode)){
            str = "SYSBOLIC LINK";
        }
        else if (S_ISSOCK(buf.st_mode)){
            str = "SOCKET";
        }
        else{
            str = "unkwown mode";
        }
        std::cout << str << '\n';
    }
    return 0;
}

