

int Main()
{
	char str1[10] = "abcdf";
	char str2[10] = "abcd";
	int r0 = myStrcmp(str1,str2);
	if( r0 == 0)
		ring_now();
	else
		led();
}
