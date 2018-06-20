#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
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
	

};
int n=0;
int read(struct zg zg[])								
{		
		FILE *fp;
		struct zg w;
		if((fp=fopen("gx.dat","rb"))==NULL)
		{
			printf("文件打开出错\n");
			exit(1);
		}
		while(!feof(fp))
		{
			fread(&w,sizeof(struct zg),1,fp);
			zg[n]=w;
			n++;
		}
		fclose(fp);
		return n;
}
int write(struct zg zg[])                                   //5.保存模块
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
		fwrite(&zg[i],sizeof(struct zg),1,fp);
	}
	fclose(fp);
	return 0;
}
/*int grsds()								//计算个人所得税模块
{
	 if(zg[i].yfgz>=0&&zg[i].yfgz<=500)
	{
		zg[i].grsds=zg[i].yfgz*0.05;
	}
	else if(zg[i].yfgz>500&&zg[i].yfgz<=2000)
	{
		zg[i].grsds=500*0.05+1500*0.10;
	}
	else if(zg[i].yfgz>2000&&zg[i].yfgz<=5000)
	{
		zg[i].grsds=500*0.05+1500*0.10+3000*0.15;
	}
	else if(zg[i].yfgz>5000&&zg[i].yfgz<=20000)
	{
		zg[i].grsds=500*0.05+1500*0.10+3000*0.15+15000*0.2;
	}
	else if(zg[i].yfgz>20000&&zg[i].yfgz<=40000)
	{
		zg[i].grsds=500*0.05+1500*0.10+3000*0.15+15000*0.2+20000*0.25;
	}
	else if(zg[i].yfgz>40000&&zg[i].yfgz<=60000)
	{
		zg[i].grsds=500*0.05+1500*0.10+3000*0.15+15000*0.2+20000*0.25+20000*0.3;
	}
	else if(zg[i].yfgz>60000&&zg[i].yfgz<=80000)
	{
		zg[i].grsds=500*0.05+1500*0.10+3000*0.15+15000*0.2+20000*0.25+20000*0.3+0.35;
	}
	else if(zg[i].yfgz>80000&&zg[i].yfgz<=100000)
	{
		zg[i].grsds=500*0.05+1500*0.10+3000*0.15+15000*0.2+20000*0.25+20000*0.3+0.35+20000*0.4;
	}	
	else if(zg[i].yfgz>100000)
	{
		zg[i].grsds=500*0.05+1500*0.10+3000*0.15+15000*0.2+20000*0.25+20000*0.3+0.35+20000*0.4+(zg[i].yfgz-100000)*0.45;
	}
	return 0;
}*/
int find(struct zg zg[])                  //查找模块
{
	int i;
	char gh[20];
	char ch;
//	do
//	{
	    printf("请按工号查找职员工资信息\n");
	    scanf("%s",gh);
		for(i=0;i<n;i++)
		{
			if(zg[i].gh==gh)
			{
				printf("%s%s%f%f%f%f%f%f%f",zg[i].gh,zg[i].name,zg[i].gwgz,zg[i].xjgz,zg[i].zwjt,zg[i].jxgz,zg[i].yfgz,zg[i].grsds,zg[i].sfgz);

			}
		}
	//}while(ch!='@');
	return 0;
}
int add(struct zg zg[])               //添加模块
{
	char ch;
	FILE *fp;
	struct zg zgrl;
	if((fp=fopen("gx.dat","wb"))==NULL)
		{
			printf("文件打开出错\n");
			exit(1);
		}
//	do
//	{	
	    printf("请输入职工工号\n");
	    scanf("%s",zgrl.gh);
		printf("请输入职工姓名\n");
		scanf("%s",zgrl.name);
		printf("请输入职工岗位工资\n");
		scanf("%f",&zgrl.gwgz);
		printf("请输入职工薪级工资\n");
		scanf("%f",&zgrl.xjgz);
		printf("请输入职工职务工资\n");
		scanf("%f",&zgrl.zwjt);
		printf("请输入职工绩效工资\n");
		scanf("%f",&zgrl.jxgz);
		zg[n++]=zgrl;
		write(zg);
	//	scanf("%c",&ch);
//	}while(ch!='@');
	fclose(fp);
	return 0;
}
/*int del()
{
	int i;
	char gh[20];
	printf("请输入所要删除的职工工号\n");
	scanf(%s,gh);
	for(i=0;i<n;i++)
	{
		if(zg[i].gh=gh)
		{
			while(feof(fp))
			{
				zg[i]=zg[i+1];
			}
		}
	}
	return 0;
}*/
void modify(struct zg zg[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%s%s%f%f%f%f%f%f%f",zg[i].gh,zg[i].name,zg[i].gwgz,zg[i].xjgz,zg[i].zwjt,zg[i].jxgz,zg[i].yfgz,zg[i].grsds,zg[i].sfgz);
	}
}
void main()
{
	int i;
	struct zg zg[100];
	n=read(zg);
/*	do{
		
		printf("请选择所需功能:  1.查询信息   2.修改信息   3.增添信息   4.删除信息   5.保存信息    6.浏览信息 \n");
		scanf("%d",&i);
		    if(i==1)
			{
			    find(zg);
			}
		    if(i==2)
			{
			    modify();
			}
		    if(i==3)
			{
			    add(zg);
			}
	   	    if(i==4)
			{
			    del();
			}
		    if(i==5)
			{
		 	    write(p);
			}
		    if(i==6)
			{
			    read(zg);
			}
		    if(i==7)
			{
		  	    exit(0);
			}
	 	    else
			{
				printf("没有这个功能\n");
			}
		}while(i!=7);
	*/
	//add(zg);
	 modify(zg);
}
