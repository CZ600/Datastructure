#include<stdio.h>

int main()
{
	struct MyStruct
	{
		char name;
		int level;
		int atk;
		char hometown;
	};

	struct MyStruct p1, p2;

	p1.name = 'k';
	p1.atk = 325;
	p1.level = 90;
	p1.hometown = 'l';

	p2 = (struct MyStruct){ 'a', 90, 235, 'd' };  //结构体可以进行数据类型的强制转换（太爽了）

	printf("She's name is %c, her hometown is %c, her atk is %d", p1.name, p1.hometown, p1.atk);
	printf("\nShe's name is %c, her hometown is %c, her atk is %d", p2.name, p2.hometown, p2.atk);

	p2 = p1;
	printf("\nShe's name is %c, her hometown is %c, her atk is %d", p2.name, p2.hometown, p2.atk);  //结构体之间可以赋值（nice！）

	// 结构体的地址需要用&来获得，而不像数组那样

	struct MyStruct* Date = &p1;
	printf("%d", Date);

	return 0;
}