#ifndef STRUCT_H_
#define STRUCT_H_

struct account
{
	long id[2];
	char name[20];
	char psw[20];
	int money;
	char idnum[18];
};

struct msg
{
	short type;
	struct account acc;
};



#endif//STRUCT_H_
