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

	p2 = (struct MyStruct){ 'a', 90, 235, 'd' };  //�ṹ����Խ����������͵�ǿ��ת����̫ˬ�ˣ�

	printf("She's name is %c, her hometown is %c, her atk is %d", p1.name, p1.hometown, p1.atk);
	printf("\nShe's name is %c, her hometown is %c, her atk is %d", p2.name, p2.hometown, p2.atk);

	p2 = p1;
	printf("\nShe's name is %c, her hometown is %c, her atk is %d", p2.name, p2.hometown, p2.atk);  //�ṹ��֮����Ը�ֵ��nice����

	// �ṹ��ĵ�ַ��Ҫ��&����ã���������������

	struct MyStruct* Date = &p1;
	printf("%d", Date);

	return 0;
}