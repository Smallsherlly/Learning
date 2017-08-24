#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
const char* mtos (mode_t m) 
{
    static char s[11];
    if (S_ISDIR (m))
        strcpy (s, "d");
    else
    if (S_ISLNK (m))
        strcpy (s, "l");
    else
    if (S_ISBLK (m))
        strcpy (s, "b");
    else
    if (S_ISCHR (m))
        strcpy (s, "c");
    else
    if (S_ISSOCK (m))
        strcpy (s, "s");
    else
    if (S_ISFIFO (m))
        strcpy (s, "p");
    else
        strcpy (s, "-");
    strcat (s, m & S_IRUSR ? "r" : "-");
    strcat (s, m & S_IWUSR ? "w" : "-");
    strcat (s, m & S_IXUSR ? "x" : "-");
    strcat (s, m & S_IRGRP ? "r" : "-");
    strcat (s, m & S_IWGRP ? "w" : "-");
    strcat (s, m & S_IXGRP ? "x" : "-");
    strcat (s, m & S_IROTH ? "r" : "-");
    strcat (s, m & S_IWOTH ? "w" : "-");
    strcat (s, m & S_IXOTH ? "x" : "-");
    if (m & S_ISUID)
        s[3] = (s[3] == 'x' ? 's' : 'S');
    if (m & S_ISGID)
        s[6] = (s[6] == 'x' ? 's' : 'S');
    if (m & S_ISVTX)
        s[9] = (s[9] == 'x' ? 't' : 'T');
    return s;
}
const char* ttos (time_t t) 
{
    static char s[20];
    struct tm* lt = localtime (&t);
    sprintf (s, "%04d-%02d-%02d %02d:%02d:%02d",
        lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday,
        lt->tm_hour, lt->tm_min, lt->tm_sec);
    return s;
}
int main (int argc, char* argv[]) 
{
    if (argc < 2)
        goto usage;
    struct stat st;
    if (argc < 3) 
    {
        if (stat (argv[1], &st) == -1) 
        {
            perror ("stat");
            return -1;
        }
    }
    else if (! strcmp (argv[2], "-l")) 
    {
        if (lstat (argv[1], &st) == -1) 
        {
            perror ("lstat");
            return -1;
        }
    }
    else
        goto usage;
    printf ("           设备ID：%u\n", st.st_dev);
    printf ("          i节点号：%u\n", st.st_ino);
    printf ("             模式：%s\n", mtos (st.st_mode));
    printf ("         硬链接数：%u\n", st.st_nlink);
    printf ("           属主ID：%u\n", st.st_uid);
    printf ("           属组ID：%u\n", st.st_gid);
    printf ("       特殊设备ID：%u\n", st.st_rdev);
    printf ("         总字节数：%u\n", st.st_size);
    printf ("      I/O块字节数：%u\n", st.st_blksize);
    printf ("占用块(512字节)数：%u\n", st.st_blocks);
    printf ("     最后访问时间：%s\n", ttos (st.st_atime));
    printf ("     最后修改时间：%s\n", ttos (st.st_mtime));
    printf (" 最后状态改变时间：%s\n", ttos (st.st_ctime));
    return 0;
usage:
    fprintf (stderr, "用法：%s <文件> [-l]\n", argv[0]);
    return -1;
}
