#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <dirent.h>
#include <errno.h>

const char* right(mode_t m) 
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
    return s;
}

const char* data(time_t t)
{
	static char s[20] = {};
	int d = t/(60*60*24);
	int year = 1970;
	for(;d>364;year++)
	{
		
		if(year%400!=0&&year%4==0||year%400==0)
		{
			d = d-366;
			
		}
		else
		{
			d = d-365;
		}
	}

	int mon = 1;
	int flag = 0;
	if(year%400!=0&&year%4==0||year%400==0)
	{
		for(;flag!=1;mon++)
		{
			switch(mon)
			{
				case 1:
				{
					d = d-30;
					if(d<30)
						flag = 1;
					break;
				}
				case 2:
				{
					d = d-29;
					if(d<32)
						flag = 1;
					break;
				}
				case 3:
				{
					d = d-31;
					if(d<31)
						flag = 1;
					break;
				}
				case 4:
				{
					d = d-30;
					if(d<32)
						flag = 1;
					break;
				}
				case 5:
				{
					d = d-31;
					if(d<31)
						flag = 1;
					break;
				}
				case 6:
				{
					d = d-30;
					if(d<32)
						flag = 1;
					break;
				}
				case 7:
				{
					d = d-31;
					if(d<32)
						flag = 1;
					break;
				}
				case 8:
				{
					d = d-31;
					if(d<31)
						flag = 1;
					break;
				}
				case 9:
				{
					d = d-30;
					if(d<32)
						flag = 1;
					break;
				}
				case 10:
				{
					d = d-31;
					if(d<31)
						flag = 1;
					break;
				}
				case 11:
				{
					d = d-30;
					if(d<32)
						flag = 1;
					break;
				}
				case 12:
				{
					d = d-31;
					flag = 1;
					break;
				}
			}
		}
			
	}
	else
	{
		for(;flag!=1;mon++)
		{
			switch(mon)
			{
				case 1:
				{
					d = d-30;
					if(d<29)
						flag = 1;
					break;
				}
				case 2:
				{
					d = d-28;
					if(d<32)
						flag = 1;
					break;
				}
				case 3:
				{
					d = d-31;
					if(d<31)
						flag = 1;
					break;
				}
				case 4:
				{
					d = d-30;
					if(d<32)
						flag = 1;
					break;
				}
				case 5:
				{
					d = d-31;
					if(d<31)
						flag = 1;
					break;
				}
				case 6:
				{
					d = d-30;
					if(d<32)
						flag = 1;
					break;
				}
				case 7:
				{
					d = d-31;
					if(d<32)
						flag = 1;
					break;
				}
				case 8:
				{
					d = d-31;
					if(d<31)
						flag = 1;
					break;
				}
				case 9:
				{
					d = d-30;
					if(d<32)
						flag = 1;
					break;
				}
				case 10:
				{
					d = d-31;
					if(d<31)
						flag = 1;
					break;
				}
				case 11:
				{
					d = d-30;
					if(d<32)
						flag = 1;
					break;
				}
				case 12:
				{
					d = d-31;
					flag = 1;
					break;
				}
			}
		}
	}
	
	int m = t%(60*60*24)%(60*60)/(60);
	int h = t%(60*60*24)/(60*60);
	sprintf (s, "%2d月 %2d %02d:%02d",mon,d,h+8,m);
	return s;
}
int main (int argc, char* argv[]) 
{
	char cwd[255] = {};
	if (! getcwd (cwd, sizeof (cwd))) 
    {
        perror ("getcwd");
        return -1;
    }
 
    struct stat st;
    if (argc < 3&&!strcmp (argv[1], "-l")) 
    {
    	
    	DIR* dp = opendir (cwd);
    	if (! dp) 
    	{
    	    perror ("opendir");
    	    return -1;
    	}
    	errno = 0;
    	struct dirent* de;
    	for (de = readdir (dp); de; de = readdir (dp))
    	{
    		if (stat (de->d_name, &st) == -1) 
        	{
           		perror ("stat");
            	return -1;
        	}
        	if(de->d_name[0]!='.')
        	{
    			printf ("%s ", right(st.st_mode));
    			printf ("%u ", st.st_nlink);
    			struct passwd* passwd = getpwuid(st.st_uid);
    			printf ("%s ",passwd->pw_name);
    			struct group* group = getgrgid(st.st_gid);
    			printf ("%s ",group->gr_name);
    			printf ("%5u ", st.st_size);
    			printf ("%s ",data(st.st_mtime));
    			printf ("%s\n",de->d_name);
    		}
    	}
    	if (errno) 
    	{
      		perror ("readdir");
      		return -1;
    	}
    	closedir (dp);
    }
    else
    {
        printf ("用法：%s <目录> [-l]\n", argv[0]);
        return -1;
    }
    
    

	return 0;
}
