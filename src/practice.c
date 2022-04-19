/*
 ============================================================================
 Name        : practice.c
 Author      : JK
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void mArr() {
	char s[2][6];
	//将Jerry复制到二维数组的第一个数组中
	strcpy(s[0], "Jerry");
	//字符可以做数学运算，是通过ASC码计算的
	printf("%d \n", 'a' - 'b');
	char l = s[0][5];
	printf("%d \n", l);
	printf("%d \n", '\0');
	//字符数组不足6的会用'\0'补齐
	if ('\0' == l) {
		printf("%s\n", "compare");
	}
	for (int i = 0; i < 6; i++) {
		printf("%c \n", s[0][i]);
	}
	strcpy(s[1], "Tom");
	s[0][5] = '&';
	printf("%s \n", s);  //Jerry&Tom
}

// char *c 代表数组，也可写为 char c[]
void reverseArr(char *c) {
	int i;
	for (i = strlen(c) - 1; i >= 0; i--) {
		//形参不管是 *c还是c[] c都代表数组的首地址，*c则取数组第一个
		printf("%c \n", *(c + i));
	}
}
/*
 * 输出三角形
 * 1
 * 1 2
 * 1 2 3
 * ...
 * 1 2 3 4 5 6 7 8 9
 */
void printTringle() {
	int arr[9][9] = { };
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d ", j);
		}
		printf("\n");

	}
}

/*
 * 求阶乘
 * sum = 1/1! + 1/2! + 1/3! + 1/4!
 * 直到最后一项小于0.000006
 */
double factorial(double n) {
	double d;
	if (n == 0 || n == 1) {
		return 1;
	}
	d = n * factorial(n - 1);
	return d;
}

//运算符优先级
/*
 *
 表2 运算符优先级和结合律 优先级 	运算符 	结合律
 1 	后缀运算符：[]    ()    ·    ->    ++    --(类型名称){列表} 	从左到右
 2 	一元运算符：++    --    !    ~    +    -    *    &    sizeof_Alignof 	从右到左
 3 	类型转换运算符：(类型名称) 	从右到左
 4 	乘除法运算符：*    /    % 	从左到右
 5 	加减法运算符：+    - 	从左到右
 6 	移位运算符：<<    >> 	从左到右
 7 	关系运算符：<<=    >>= 	从左到右
 8 	相等运算符：==    != 	从左到右
 9 	位运算符 AND：& 	从左到右
 10 	位运算符 XOR：^ 	从左到右
 11 	位运算符 OR：| 	从左到右
 12 	逻辑运算符 AND：&& 	从左到右
 13 	逻辑运算符 OR：|| 	从左到右
 14 	条件运算符：?: 	从右到左
 15 	赋值运算符：
 =         +=        -=       *=       /=      %=       &=       ^=      |=
 <<=      >>= 	从右到左
 16 	逗号运算符：， 	从左到右
 */

/**
 * 结构体类型
 */
typedef struct person{
	int age;
	char name [20]; //记得初始化个数
} PER;

void stuctTest(){
	PER p[3] = {{1,"test1"},{12,"test2"}}; //要是两个大括号
	for(int i = 0; i < 3 ;i++){
		printf("%d \t %s",p[i].age, p[i].name);
	}
}

void calcu() {
	int a = 1, b = 2, c = 3;
	//先计算再逻辑

	int r = (a || b - a && c + !a);
	printf("%d %d \n", r, 1 && 3); // 1,1
}

/**
 * 读写文件
 * ASC
 * a = 97
 * A = 97-32 = 65
 * 0 = 48
 */
void readFile() {
	FILE *fp1, *fp2;
	char ch;
	fp1 = fopen("/Users/cuijiangkun/test.txt", "r");
	fp2 = fopen("/Users/cuijiangkun/test1.txt", "w+");

	//NULL即为0 在stdio中
	if (fp1 == NULL || fp2 == NULL) {
		//正常退出
		exit(0);
	}
	//feof文件结束返回非0
	while (!feof(fp1)) {
		ch = fgetc(fp1);
		putchar(ch);
		if (ch >= '0' && ch <= '9') {
			ch = 'Z' - (ch - 48);
		}
		//记得写完后重制指针
		fputc(ch, fp2);
	}
	//重制指针
	rewind(fp2);
	while (!feof(fp2)) {
		ch = fgetc(fp2);
		putchar(ch);
	}
	//正确关闭会返回0
	fclose(fp1);
	fclose(fp2);

	/*
	 * 写入字符串到文件，返回写入的字符数，否则返回EOF（-1）
	 * fputs(char *str, FILE *fp);
	 *
	 * 读取到str
	 * char fgets(char * str, int length, FILE*fp);
	 */
}

/**
 * 将数组n个元素右移m个位置
 */

int move(int arr[], int n, int m) {
	int temp;
	int i, j;
	for (i = 0; i < m; i++) {
		temp = arr[n - 1];
		for (j = n - 1; j > 0; j--) {
			arr[j] = arr[j - 1];
		}
		arr[0] = temp;
	}
	//纪录下n个元素变动后的索引
	int tmparr[n];
	for (int i = n - 1; i >= 0; i--) {
		tmparr[i] = arr[i];
		arr[i + m] = arr[i];
		arr[i] = tmparr[i];
	}
	return 0;
}

void scanArr() {
	int a[20];
	int i, n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		printf("%5d", a[i]);
	}
	printf("\n");
	move(a, n, m);
	for (i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");
	return;
}

//数组排序
//5483627910
void sortArr() {
	int i, j, k, tmp, arr[10], arr2[10];
	int len = sizeof(arr) / sizeof(&arr);
	printf("arr len = %d\n", len);
	for (i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 10; i++) {
		arr2[i] = arr[i];
	}
	//选择排序
	for (j = 0; j < 10; j++) {
		for (k = j + 1; k < 10; k++) {
			if (arr[j] < arr[k]) {
				tmp = arr[k];
				arr[k] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
	//冒泡排序
	for (int j = 0; j < 10 - 1; j++) {
		for (int i = 0; i < 10 - j - 1; i++) {
			if (arr2[i + 1] > arr2[i]) {
				tmp = arr2[i];
				arr2[i] = arr2[i + 1];
				arr2[i + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d", arr2[i]);
	}
}

//判断三角形
void isTriangle(){
	int i,j,k;
	scanf("%d",&i);
	scanf("%d",&j);
	scanf("%d",&k);
	if(i + j > k || i + k > j || k + j > i){
		printf("Is Triangle");
	} else {
		printf("No triangle");
	}
}

int main() {
	int size = sizeof("123");
	int len = strlen("123");
	//sizeof计算字符长度，包含最后的\0，strlen计算真实长度不包含\0
	printf("%d \n", size);
	printf("%d \n", len);
	//字符数组
//	mArr();

	//字符反转输出
//	char str[10];
//	scanf("%s \n", &str);
//	reverseArr(str);

	printTringle();

	double sum = 0;
	for (double i = 1; factorial(i) < pow(10, 6); i++) {
		sum = sum + 1 / factorial(i);
	}

	printf("%d \n", (5 << 3));

	calcu();

	//readFile();

	//  sizeof没法求出数组中的具体个数
	//	int arr[10] = {1,2,3,4};
	//	printf("%d, %d", sizeof(arr), sizeof(arr[0]));// 40，4

	//平移数组
	//scanArr();

	//错误的C语言常数：019（0代表八进制，八进制不会有9的出现）0xag(0x开头代表16进制，不会有g的数值)
	//宏命令只是单纯的字符代入，不会做任何解析如#define X 3+5; printf("%d", 5 * X) 输出20

	printf("%f\n", sqrt(4)); //2.00
	printf("%f\n", pow(4, 2)); //16.00
	printf("%f\n", 1.2e3);   //1200.00
	printf("%f\n", 1.2e-3);   //0.001200

	char ch[10] = "world", *p = ch;
	//putchar只能输出char，不能输出字符串！
	putchar('a');
	//输出字符串
	printf("%s\n", ch);
	printf("%s\n", p);

	//sortArr();
	isTriangle();

	stuctTest();
	return EXIT_SUCCESS;
}
