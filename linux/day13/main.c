#include "list.h"

int main()
{
	List list;
	init(&list);

	for(int i=0; i<10; i++)
	{
		push_tail(&list,i);
	}
	travel(&list);
	
	pop_head(&list);
	travel(&list);
	
	insert(&list,3,11);
	travel(&list);
	
	delete(&list,3);
	travel(&list);
	
	modify(&list,1,110);
	travel(&list);
	
	updata(&list,110,120);
	travel(&list);
	
	return 0;
}
