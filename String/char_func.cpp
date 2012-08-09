#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;


int main()
{
	char a[100], b[100];
	scanf("%s", a);
	strcpy(b, a);
	printf("%s %s\n", a, b);
	printf("%d\n", strcmp(a, b));
	strcat(b, "a");
	printf("%d\n", strcmp(a, b));
	strcpy(b, "stu");
	
	char c[100];
	strncpy(c, strstr(a, b), strlen(b));
	c[strlen(b)] = 0;
	printf("%s\n", c);


	int d = 100;
	sprintf(c, "%d", d);
	printf("%s\n", c);



}
