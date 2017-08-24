系统调用
	Linux系统中的大部分功能都是通过系统调用实现的
	系统调用被封装成了C函数形式，但他们不是标准C
	标准库的函数大部分情况运行在用户态，但部分函数运行在内核态
		printf scanf malloc free fopen fwrite
	程序员也直接调用内核态的代码和数据
		brk/sbrk/mmap/munmap
	系统调用的实现在内核中，但他的调用接口定义在了C库
		通过接口使用系统调用是通过软件中断来实现的

一切皆文件
	在Linux系统中几乎一切都是文件（除了网卡）
	在Linux系统中使用文件可以为操作系统和设备提供简单统一的接口
	在Linux系统中程序访问设备可以像访问普通文件一样来访问
		打印机／串口／声卡
	访问文件常用的系统调用:\
		open/close/write/read/ioctl
	在Linux系统中不同的对象，当作不同的文件类型
	文件的分类：
		普通文件
		目录文件
		设备文件
			控制台 /dev/console
			声卡 /dev/audio
			标准输入输出 /dev/tty
			空设备 /dev/null

文件相关的系统调用
	open    打开或创建文件
	creat   专门用来创建文件
	close   关闭文件
	read    读文件
	write   写文件
	lseek   调整文件的位置指针
	fcntl   修改文件的属性
	unlink  删除一个硬链表
	remove  删除文件(标准C函数,通过调用unlink实现)
	rmdir   删除空目录

unlink/remove删除的文件如果是最后一个硬链接。并且没进程打开他,那么存储文件的硬盘区域会立即标记为自由,如果有进程打开他，会在进程结束后把他标记为自由

如果删除的是软链接,目标文件不受影响

rmdir只能删除空目录，删除非空目录时要先进入目录，然后把目录内所有文件全部删除，再退出目录，把空目录删除

文件描述符
	由系统调用返回的(open/creat),只能被内核使用的一个非负整数
	表示一个打开的文件
	文件描述符与标准C里的函数指针类似
	有三个默认打开的文件：
		0 标准输入设备 stdin
		1 标准输出设备 stdout
		2 标准错误设备 stderr
	这三个文件描述符在 unistd.h 被定义成了宏
		#define STDIN_FILEO   0
		#define STDOUT_FILEO  1
		#define STDERR_FILEO  2
	现在使用的系统中他们统统指向了终端

	文件描述符的范围：
		0  64
		0  255
		0  OPEN_MAX//已经取消
		查看：ulimit -a
		设置：unlimit -n 2048

open/creat/close
	int open(
		const char* path,//文件路径
		int flags,//打开文件的方式
		mod_t mod//只有创建文件的时候才有效，创建文件的权限
	);//能打开也能创建

	int open(
		const char* path,//文件路径
		int flags,//打开文件的方式
	);//专门用来打开文件

	int close(int fd);//关闭文件
	
	int creat(
		const char* path,//文件路径
		mod_t mod,//创建权限
	);//专门用来创建文件的，他是调用open来实现
write
	ssize_t write(
		int fd,//文件描述符
		void* buf,//要写入的数据
		size_t count//要写入的字节数
	);
	写入失败时返回 -1

	size_t unsigned long int;
	ssize_t signed long int;

	只能写入二进制,想写入文本要先转换成字符串,再写入_____write.c
read
	ssize_t read(
		int fd,//文件描述符
		void* buf,//读取的数据存放的位置
		size_t count//想读取的字节数
	);
	成功返回实际读取的字节数，失败返回-1

1.把data.bin读取并显示
2.把data.txt读取并显示

标准IO/系统IO
标准IO在读写数据时会有缓存区的存在，写入的数据不会立刻交给内核写入磁盘，而是等待缓冲区满了，才把数据批量交给内核写入文件，可以大大提高文件读写的效率，缺点是数据不能即时写入文件

系统IO在读写数据时会立即把数据写入磁盘，需要频繁进出内核，在内核态与用户态之间切换时会浪费大量时间，最好建立缓存区，来提高读写效率
lseek
 与fseek用法相似，都用来调整文件的位置指针

off_t:专门用来做偏移值的int类型
off_t lseek(
	int fd,
	off_t off,
	int whence,
		SEEK_SET
		SEEK_CUR
		SEEK_END
);

系统调用中没tell函数，ftell
	lseek(fd,0,SEEK_CUR);//功能与ftell类似，返回值是文件的当前读写位置
	
	lseek(fd,0,SEEK_END);//返回的虽然是位置，但可以代表文件的大小

	当文件位置指针调整到文件最后位置之后，再进行写文件的话就会造成文件黑洞
	黑洞不会写入磁盘，但记入到文件大小

打开文件的内核数据结构
p57  3-1

dup/dup2
