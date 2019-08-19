#include <windows.h>
#include<iostream>
#include <stdio.h>
#include<easyx.h> 
using namespace std;
int leap[12]={5,1,2,5,0,3,5,1,4,6,2,4};//存放闰年月码的数组
int common[12]={6,2,2,5,0,3,5,1,4,6,2,4};//存放平年月码的数组
int year,month=1;
void print();
void main()
{
	initgraph(600,900);
	while(1)
	{
		SYSTEMTIME sys; 
		GetLocalTime(&sys);
		year=sys.wYear;
		while(month<13)
		{
			print();
			month++;
		}
	}
}
void print()
{
	SYSTEMTIME sys1; 
	GetLocalTime(&sys1);
	int d=1;
	int max;
	int begin;//存放这一年中第一天的星期值
	int n=0;
	char c[8];
	sprintf(c,"%d",month);
	outtextxy((month-1)%3*200,n*20+(month-1)/3*200,c);
	outtextxy((month-1)%3*200+10,n*20+(month-1)/3*200,"月");
	n=1;
	for(int i=0;i<7;i++)
	{	
		switch(i)
		{
		case 0:outtextxy(i*20+(month-1)%3*200,n*20+(month-1)/3*200,"日");
			break;
		case 1:outtextxy(i*20+(month-1)%3*200,n*20+(month-1)/3*200,"一");
			break;
		case 2:outtextxy(i*20+(month-1)%3*200,n*20+(month-1)/3*200,"二");
			break;
		case 3:outtextxy(i*20+(month-1)%3*200,n*20+(month-1)/3*200,"三");
			break;
		case 4:outtextxy(i*20+(month-1)%3*200,n*20+(month-1)/3*200,"四");
			break;
		case 5:outtextxy(i*20+(month-1)%3*200,n*20+(month-1)/3*200,"五");
			break;
		case 6:outtextxy(i*20+(month-1)%3*200,n*20+(month-1)/3*200,"六");
			break;
		}
	}
	n=2;
	if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))//闰年
	{
		begin=((year%100+year%100/4)%7+leap[month-1]+1)%7;
		for(int i=0;i<begin;i++)
		{
			outtextxy((i-1)*20+(month-1)%3*200,n*20+(month-1)/3*200+(month-1)/3*200,"");
		}
		sprintf(c,"%d",d);
		if(d==sys1.wDay&&month==sys1.wMonth)
		settextcolor(RED);
		outtextxy(i*20+(month-1)%3*200,n*20+(month-1)/3*200,c);
		settextcolor(WHITE);
		d++;
		switch(month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			max=31;
			break;
		case 2:
			max=29;
			break;
		case 4: case 6: case 9: case 11:
			max=30;
			break;
		}
		for(;d<=max;d++)
		{
			if((d+begin-1)%7==0)
			{
				n++;
				sprintf(c,"%d",d);
				if(d==sys1.wDay&&month==sys1.wMonth)
				settextcolor(RED);
				outtextxy(((d+begin-1)%7)*20+(month-1)%3*200,n*20+(month-1)/3*200,c);
				settextcolor(WHITE);
			}
			else
			{
				sprintf(c,"%d",d);
				if(d==sys1.wDay&&month==sys1.wMonth)
				settextcolor(RED);
				outtextxy(((d+begin-1)%7)*20+(month-1)%3*200,n*20+(month-1)/3*200,c);
				settextcolor(WHITE);
			}
		}
	}
	else//平年
	{
		begin=((year%100+year%100/4)%7+common[month-1]+1)%7;
		for(int i=0;i<begin;i++)
		{
			outtextxy((i-1)*20+(month-1)%3*200,n*20+(month-1)/3*200,"");
		}
		sprintf(c,"%d",d);
		if(d==sys1.wDay&&month==sys1.wMonth)
		settextcolor(RED);
		outtextxy(i*20+(month-1)%3*200,n*20+(month-1)/3*200,c);
		settextcolor(WHITE);
		d++;	
		switch(month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			max=31;
			break;
		case 2:
			max=28;
			break;
		case 4: case 6: case 9: case 11:
			max=30;
			break;
		}
		for(;d<=max;d++)
		{	
			if((d+begin-1)%7==0)
			{
				n++;
				sprintf(c,"%d",d);
				if(d==sys1.wDay&&month==sys1.wMonth)
				settextcolor(RED);
				outtextxy(((d+begin-1)%7)*20+(month-1)%3*200,n*20+(month-1)/3*200,c);
				settextcolor(WHITE);
			}
			else
			{
				sprintf(c,"%d",d);
				if(d==sys1.wDay&&month==sys1.wMonth)
				settextcolor(RED);
				outtextxy(((d+begin-1)%7)*20+(month-1)%3*200,n*20+(month-1)/3*200,c);
				settextcolor(WHITE);
			}
		}
	}
	cout<<endl;
}