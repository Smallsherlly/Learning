1.课程内容
2.Unix操作系统
	简介 三高
	派生
		银行 电信 system V
		Mac os
		Linux
3.Linux操作系统
	简介 林纳克斯 GNU Linux
	标志 企鹅 全世界共同拥有
	版本
		cat /protc/version
		A 
		B 奇数为测试版 偶数为稳定版 
		C 
		D 
		E pae 物理地址扩展
	GPL
	POSIX 统一标准接口
	特点：
		多用户
		多任务
		安全稳定 开源
	发行版：
		Oracle Linux 数据库
		Redhat 服务器 收费
		CentOS 服务器 免费 6 7版本
		Ubuntu 使用最多
			LTS 稳定更新版
			12.04 LTS
		Debian apt-get 包比较多
4.GNU编译工具 MinGW
	编译多种语言
		C C++ java php OC 
	支持多平台
		Linux
		Windows
		Mac Xcode
	版本
		gcc -v
	构建
		1.预处理
			gcc -E hello.c -o hello.i
		2.汇编
			gcc -S hello.i 生成hello.s
		3.编译
			gcc -c hello.s 生成hello.o
		4.链接
			ld 链接脚本 目标文件 库文件 ->a.out
		5.装载
			a.out 从硬盘加载程序到内存
		6.执行
			cpu从内存读取指针执行
	文件后缀：
		.h 头文件
		.c 源文件
		.inh 有内联函数的头文件
		.cpp c++源文件
		.cxx 能交叉编译的源文件
		.i 预处理后的文件
		.s 汇编文件
		.o 目标文件 二进制
		.a 静态库
		.so 共享库（动态库）
	编译单个文件
		gcc hello.c
		-E 预处理
		-S 汇编
		-c 只编译
		-g 加入调试信息
		-x 指定编译语言
		-Wall 尽可能多地产生警告
		-Werror 把警告当作错误处理
		-pedantic 不符合ISO标准的语法产生警告
		-O1 O2 O3 编译器优化级别
	编译多个文件
		gcc main.c calc.c
		头文件的引用
			直接引用 
				#include " "  先在当前目录下查找头文件
				如果找不到再去系统指定的目录下查找
			-I 指定头文件的路径
				1.先在-I指定的路径下找
				2.在当前目录下找
				3.在系统指定的目录下找
			通过系统指定
				CPATH
				C_INCLUDE_PATH
				在命令行：
					export CPATH=~
					export C_INCLUDE_PATH=~
					临时有效
				写入配置文件
					只对当前用户有效
					vim ~/.bashrc
					export CPATH=$CPATH:~(路径):(路径)
					export C_INCLUDE_PATH=$C_INCLUDE_PATH:~(路径)
					source ~/.bashrc
					对所有用户有效 改完之后要重启
					vim /etc/environment
					env 查看所有环境变量
			预处理指令：
				#include //导入头文件
				#include_next //导入当前目录下个目录的头文件,几乎不用
				#define //定义宏
				#undef  //删除定义过的宏
				gcc -D ARR_LEN=10 test.c
				编译器编译期间定义宏
				#if		//预处理期间的分支判断
				#elif	//#if分支
				#endif  //#if结束标志
				#ifndef //判断宏是否定义过，没定义时结果为真
				#ifdef	//判断宏是否定义过，定义过时为真
				#define VAL_NAME(v) #v  //“#”把标识符转成字符串
				#define VAL_AND_VAL(a,b) a##b //“##”把标识符组合在一起成新的标识符
				#error	//产生错误
				#warning //产生警告
				#pragma
					#pragma GCC dependency <文件> //若<文件>比此文件新则警告，监控文件，防止被意外修改
					#pragma GCC poison goto	  //禁止使用某种语句
					#pragma pack(1/2/4/8)           //设置结构体按几字节对齐补齐,32位系统‘8’不起作用
				#line //设置代码的行号
				预定义的宏
					__BASE_FILE__ //正在编译的源文件名
					__FILE__	  //所在文件名
					__LINE__	  //当前行号
					__FUNCTION__
					__func__	  //当前所在函数
					__TIME__	  //显示系统时间
					__DATA__	  //显示系统日期
					__INCLUDE_LEVEL__//包含层数，从0开始
					__cplusplus g++中它等于1
				环境变量
					CPATH			//c语言头文件的查找路径
					C_INCLUDE_PATH	//同上
					LIBRARY_PATH	//库文件查找路径
					LD_LIBRARY_PATH //动态库加载路径
5.库
	代码的仓库，把字符形的源代码文件封装二进制的代码库
	分久必合
		方便管理
	合久必分
		增量编译
	静态库
		编译时会把静态库里的代码拷贝到a.out中
		运行时不依赖静态库
		速度快
		不利于更新，维护
		可执行程序的文件会过大
	共享库
		编译时把共享库的代码地址记录下来
		运行时跳转到共享库中执行，因此运行时需要依赖共享库
		速度慢
		有利于更新，维护，动态库更新后a.out不用重新编译
		可执行文件a.out的大小会降低
6.静态库
	创建静态库
		1.编辑代码 vi tools.c
		2.生成目标文件 gcc -c tools.c
		3.生成静态库文件 ar -r libtools.a tools.o
	使用静态库
		1.直接调用
			gcc main.c libtools.a
		2.指定库的路径
			gcc main.c -l tools -L 路径
		3.设置查找库的路径
			export LIBRARY_PATH = 路径
			gcc main.c -l tools
	执行
		可执行文件不依赖静态库，直接执行
	ar指令的参数：
		-r 创建一个库
		-q 追加
		-d 删除
		-t 列出库中所有的目标文件
		-x 把库展开成目标文件
7.共享库
	创建共享库
		1.编辑源代码 vi tools.c
		2.生成目标文件 gcc -c tools.c
		3.生成共享库 gcc -shared -o libtools.so tools.o
	使用共享库
		直接使用
		使用 -L参数
		使用 LIBRARY_PATH环境变量
		PS：共享库和静态库同时存在，优先加载共享库， 使用-static 优先加载静态库
	执行
		可执行文件依赖共享库
		可执行文件编译期间按LIBRARY_PATH来查找
		运行期间按LD_LIBRARY_PATH来查找共享库
		
8.动态加载共享库
	打开共享库
	获取函数指针
	关闭共享库
9.辅助工具
