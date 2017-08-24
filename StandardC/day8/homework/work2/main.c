#include"Guest.h"
#include"register.h"
#include<stdio.h>
//#include"start.h"
Gue gue[100] = {0};	

int main()
{
	
	int t =show();
	if(t==1)
	{
		login();
	}else if(t==2){
		reg();
		//FILE *fp = fopen("./shuju.txt","r+");
		
//	fread(&gue[1],sizeof(Gue),1,fp);
//	printf("%s %s\n",gue[1].name,gue[1].psw);
//	fread(&gue[2],sizeof(Gue),1,fp);
//	printf("%s %s",gue[2].name,gue[2].psw);//读取测试模块
	
		//fclose(fp);
	}
		return 0;	
}
