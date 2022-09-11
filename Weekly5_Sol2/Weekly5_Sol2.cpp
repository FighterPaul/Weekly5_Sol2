//จงเขียนโปรแกรมรับ string มา 1 ชุด แล้วหาว่าตัวอักษรใดมีจำนวนตัวมากที่สุด(Level 3)

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>						//Problem 56, Solution 2, ID Student 65010902


int store[94];          //character				!    "   #   ...    }  ~
						//index array			0    1   2   ...   92  93
						//ASCII					33  34  35   ...   125 126


bool zeroall = true;	//ใช้เช็คว่า เป็น0 หมดทุกตัวไหม






void store_num(int j)		// function ทำหน้าที่ บวกจำนวนตัวอักษร store[]
{
	store[j - 33] += 1;
}

int compare(int num, int i)
{
	if (num > i)
		return num;
	if (num == i)
		return num;
	if (num < i)
		return i;
}







int main()
{


	char str[100];
	scanf("%s", str);


	for (int i = 0; i <= (strlen(str) - 1); i++)
	{
		for (int j = 33; j <= 126; j++)            //  !  "   #  --->  }  ~
		{
			if (str[i] == j)
			{
				store_num(j);
			}
		}
	}



	for (int x = 0; x <= 93; x++)
	{
		if (store[x] != 0)
		{
			zeroall = false;
			break;
		}
	}
	if (zeroall == true)
	{
		for (int y = 33; y <= 126; y++)
		{
			printf("%c ", y);					// กรณี = 0หมด ปริ้นทุกตัว
		}
	}


	
			
	int most = compare(store[0], store[1]);

	for (int i = 2; i <= 93; i++)						// เปรียบเทียบว่าสุดท้ายแล้ว ตัวอักษรที่มีมากที่สุด มีกี่ตัว
	{
		most = compare(most, store[i]);
	
	}
													
  	for (int k = 0; k <= 93; k++)
	{
		if (store[k] == most)
		{
			printf("%c ", k + 33);
		}
	}
	
	
	
	
	
		

	

	
	return 0;
}