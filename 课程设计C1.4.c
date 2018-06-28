/************************************************************
Copyright (C), 1988-1999, mingda Tech. Co., Ltd.
FileName: 设计.cpp
Author:闭龙堂   Version :1.4   Date:2018.06.26
Description: // 模块描述
Version: 1.4版// 版本信息
Function List: // 主要函数及其功能
1.main（）函数主要是根据用户的指令调用各个功能函数。
2.read()函数主要是读取职工工资数据。
3.write()函数主要是保存职工工资数据。
4.void fin()函数主要是查询职工工资数据。
5.list()函数主要是浏览职工工资数据。
6.modify()函数主要是修改职工工资。
7.del()函数主要是删除职工工资数据。
8.add()函数主要是添加职工工资数据。
9.grsds()函数主要是计算个人所得税
History: // 历史修改记录
<author> <time> <version > <desc>
David 96/10/12 1.0 build this moudle
*************************************************************/
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
struct zg
{
	char  gh[10];    //工号
	char name[10];   //名字
	float gwgz;		 //岗位工资
	float xjgz;		 //薪级工资
	float zwjt;      //职务津贴
	float jxgz;      //绩效工资
	float yfgz;      //应发工资
	float grsds;    //个人所得税
	float sfgz;     //实发工资
}zg[100];
int n=0;
int read()								//读文件模块
{		
	FILE *fp;                               //定义文件指针
	if((fp=fopen("gx.dat","rb"))==NULL)     //判断文件是否成功打开
	{
		printf("文件打开出错\n");
		exit(1);
	}			                  
	for(n;n<100;n++)
	{			
		fread(&(zg[n]),sizeof(struct zg),1,fp);  //每次从文件中读取一条数据到结构体
		grsds();
		if(feof(fp))                       //判断文件是否到末尾
		{
			break;
		}
	}
	fclose(fp);	                          //关闭文件
	return 0;
}
int write()                                   //5.保存模块
{
	int i;
	FILE *fp;                                     
	if((fp=fopen("gx.dat","wb"))==NULL)  
		{
			printf("文件打开出错\n");
			exit(1);
		}
	for(i=0;i<n;i++)
	{
		fwrite(&(zg[i]),sizeof(struct zg),1,fp);	//把结构体中的数据写入文件
	}
	printf("保存数据成功\n");
	fclose(fp);                                    //关闭文件
	system("pause");
	return 0;
}
int grsds()								//计算个人所得税模块
{
	zg[n].yfgz=zg[n].gwgz+zg[n].jxgz+zg[n].xjgz+zg[n].zwjt;  //计算应发工资  
	if(zg[n].yfgz>=0&&zg[n].yfgz<=500)                  //计算应发工资在0到500的个人所得税
	{
		zg[n].grsds=(zg[n].yfgz*5)/100;
	}
	else if(zg[n].yfgz>500&&zg[n].yfgz<=2000)					//计算应发工资在500到2000的个人所得税
	{
		zg[n].grsds=(500.0*5+(zg[n].yfgz-500)*10)/100;
	}
	else if(zg[n].yfgz>2000&&zg[n].yfgz<=5000)							//计算应发工资在2000到5000的个人所得税
	{
		zg[n].grsds=(500.0*5+1500*10+(zg[n].yfgz-2000)*15)/100;
	}
	else if(zg[n].yfgz>5000&&zg[n].yfgz<=20000)								//计算应发工资在5000到20000的个人所得税
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+(zg[n].yfgz-5000)*20)/100;
	}
	else if(zg[n].yfgz>20000&&zg[n].yfgz<=40000)									//计算应发工资在20000到40000的个人所得税
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+(zg[n].yfgz-20000)*25)/100;
	}
	else if(zg[n].yfgz>40000&&zg[n].yfgz<=60000)										//计算应发工资在400000到60000的个人所得税
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+(zg[n].yfgz-40000)*30)/100;
	}
	else if(zg[n].yfgz>60000&&zg[n].yfgz<=80000)											//计算应发工资在60000到80000的个人所得税
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+20000*30+(zg[n].yfgz-60000)*35)/100;
	}
	else if(zg[n].yfgz>80000&&zg[n].yfgz<=100000)												//计算应发工资在80000到100000的个人所得税
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+20000*30+20000*35+(zg[n].yfgz-80000)*40)/100;
	}	
	else if(zg[n].yfgz>100000)																		//计算应发工资在100000以上个人所得税
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+20000*30+20000*35+20000*40+(zg[n].yfgz-100000)*45)/100;
	} 
	zg[n].sfgz=zg[n].yfgz-zg[n].grsds;  //计算实发工资
	return 0;
}
int find()                     //查找模块
{
	int i;					  
	char gh[20];              //输入查找工号
	printf("请按工号查找职员工资信息\n");
	scanf("%s",gh);
	for(i=0;i<=n;i++)
	{
	    if(strcmp(zg[i].gh,gh)==0)             //判断查找的工号是否与文件中符合
		{
			printf("工号\t  姓名\t\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t  个人所得税  \t实发工资\n");
			printf("%-10s",zg[i].gh);
			printf("%-10s",zg[i].name);
			printf("%12.2f\t",zg[i].gwgz);
			printf("%8.2f\t",zg[i].xjgz);
			printf("%8.2f\t",zg[i].zwjt);
			printf("%8.2f\t",zg[i].jxgz);
			printf("%8.2f\t",zg[i].yfgz);
			printf("%8.2f\t",zg[i].grsds);
			printf("%8.2f\t\n",zg[i].sfgz);
			   break;
		}
		if(i==n) 
		{
			printf("所查工号不存在\n");
		}
		
	}	
	system("pause");
	return 0;
}
int add()               //添加模块
{
	int i;
	if(n==100)              //判断文件是否存储满
	{
		printf("文件存储数据已满");
		return 0;

	}
	printf("请输入职工工号: ");
	scanf("%s",&zg[n].gh);
	for(i=0;i<n;i++)
	{
		if(strcmp(zg[n].gh,zg[i].gh)==0)               //判断工号是否存在
		{
			printf("所输入的工号已存在，请重新输入\n");
			printf("请输入职工工号\n");
			scanf("%s",zg[n].gh);
			i=0;                                      //重新判断
		}
	}
	printf("请输入职工姓名: ");
	scanf("%s",&zg[n].name);
	printf("请输入职工岗位工资: ");
	scanf("%f",&zg[n].gwgz);
	printf("请输入职工薪级工资: ");
	scanf("%f",&zg[n].xjgz);
	printf("请输入职工职务工资: ");
	scanf("%f",&zg[n].zwjt);
	printf("请输入职工绩效工资: ");
	scanf("%f",&zg[n].jxgz);
	zg[n].yfgz=zg[n].gwgz+zg[n].jxgz+zg[n].xjgz+zg[n].zwjt; //计算应发工资
	grsds();                                                //计算个人所得税
	zg[n].sfgz=zg[n].yfgz-zg[n].grsds;                       //计算实发工资
	n++;                                                    //添加成功数据后n+1
	system("pause");
	return 0;
}
int del()                                                   //删除模块
{
	int i,j,choice;
	char gh[20];
	printf("请输入所要删除的职工工号\n");
	scanf("%s",gh);
	for(i=0;i<=n;i++)
	{
		if(strcmp(zg[i].gh,gh)==0)                         //判断工号是否存在
		{	
			printf("是否确认删除，删除请输入1，取消请输入0:\n");   //选择是否要删除
			scanf("%d",&choice);
			if(choice==1)
			{
				j=i;
				for(j;j<=n;j++)
				{	
					zg[j]=zg[j+1];             //删除查找到的工号
					n--;
				}
				printf("删除成功\n");
				break;
			}
			if(choice==0)
			{
				break;
			}
		}
		if(i==n) 
		{
			printf("所查工号不存在\n");
		}
	}
	system("pause");
	return 0;
}
int list()                        //显示模块
{
	int i;
	printf("工号\t  姓名\t\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t  个人所得税  \t实发工资\n");
	for(i=0;i<n;i++)
	{
		
		printf("%-10s",zg[i].gh);
		printf("%-10s",zg[i].name);
		printf("%12.2f\t",zg[i].gwgz);
		printf("%8.2f\t",zg[i].xjgz);
		printf("%8.2f\t",zg[i].zwjt);
		printf("%8.2f\t",zg[i].jxgz);
		printf("%8.2f\t",zg[i].yfgz);
		printf("%8.2f\t",zg[i].grsds);
		printf("%8.2f\t\n",zg[i].sfgz);
	}
	system("pause");
	return 0;
}
void modify()    //修改模块
{
	int i,choice;
	char gh[20];
	printf("请输入要修改的职工的工号\n");
	scanf("%s",gh);
	for(i=0;i<n;i++)
	{
		if(strcmp(zg[i].gh,gh)==0)
		{

			printf("工号\t  姓名\t\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t  个人所得税  \t实发工资\n");
			printf("%-10s",zg[i].gh);
			printf("%-10s",zg[i].name);
			printf("%12.2f\t",zg[i].gwgz);
			printf("%8.2f\t",zg[i].xjgz);
			printf("%8.2f\t",zg[i].zwjt);
			printf("%8.2f\t",zg[i].jxgz);
			printf("%8.2f\t",zg[i].yfgz);
			printf("%8.2f\t",zg[i].grsds);
			printf("%8.2f\t\n",zg[i].sfgz);
			printf("请输入你需要修改的地方  1.姓名   2.岗位工资   3.薪级工资  4.职务工资  5.绩效工资 6.退出\n");
		do{
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:                               //修改姓名
					printf("请修改职工姓名\n");
					scanf("%s",&zg[i].name);
					break;
			case 2:								//修改岗位工资
					printf("请修改职工岗位工资\n");
					scanf("%f",&zg[i].gwgz);
					break;
			case 3:								//修改薪级工资
					printf("请修改职工薪级工资\n");
					scanf("%f",&zg[i].xjgz);
					break;
			case 4:								//修改职位工资
					printf("请修改职工职务工资\n");
					scanf("%f",&zg[i].zwjt);
					break;
			case 5:								//修改绩效工资
					printf("请修改职工绩效工资\n");
					scanf("%f",&zg[i].jxgz);
					break;
			case 6:
				break;
			}
			zg[i].yfgz=zg[i].gwgz+zg[i].jxgz+zg[i].xjgz+zg[i].zwjt;
			zg[i].sfgz=zg[i].yfgz-zg[i].grsds;
			printf("继续修改请重新选择：1.姓名   2.岗位工资   3.薪级工资  4.职务工资  5.绩效工资 6.退出\n");
		}while(choice!=6);
		printf("修改后的结果\n");
		printf("工号\t  姓名\t\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t  个人所得税  \t实发工资\n");
		printf("%-10s",zg[i].gh);
		printf("%-10s",zg[i].name);
		printf("%12.2f\t",zg[i].gwgz);
		printf("%8.2f\t",zg[i].xjgz);
		printf("%8.2f\t",zg[i].zwjt);
		printf("%8.2f\t",zg[i].jxgz);
		printf("%8.2f\t",zg[i].yfgz);
		printf("%8.2f\t",zg[i].grsds);
		printf("%8.2f\t\n",zg[i].sfgz);
		}
		if(i==n)    //判断工号是否存在
			printf("所查工号不存在\n");
	}
	system("pause");
}
void main()
{
	int i;	
	read();
	grsds();
	do{	
		system("cls");
		printf("*--------------************************************欢迎使用职工工资管理系统************************************-----------------*\n");
		printf("*                                                    请选择所需功能:                                                            *\n");
		printf("*                                            1.查询信息   2.修改信息   3.增添信息                                               *\n");
		printf("*                                     4.删除信息   5.保存信息    6.浏览信息  7.退出程序                                         *\n");
		printf("*--------------***************************************************************************************************--------------*\n");
		printf("请输入您所要选择的功能：");
		scanf("%d",&i);
		    if(i==1)
			{
			    find();			//调用查询函数
			}
		    else if(i==2)
			{
			    modify();		//调用修改函数
			}
		   else if(i==3)
			{
			    add();			//调用添加信息函数
			}
	   	    else if(i==4)
			{
			    del();			//调用删除函数
			}
		   else if(i==5)
			{
		 	    write();		//调用保存函数
			}
		    else if(i==6)
			{
			    list();          //调用浏览函数
			}
		    else if(i==7)
			{
				printf("--------------************************************欢迎下次使用职工工资管理系统************************************--------------\n");
		  	    exit(0);
			}
			else  
				printf("没有这个功能，请重新选择");
		}while(i!=7);
}