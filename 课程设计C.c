#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
struct zg
{
	char  gh[10];    //����
	char name[10];   //����
	float gwgz;		 //��λ����
	float xjgz;		 //н������
	float zwjt;      //ְ�����
	float jxgz;      //��Ч����
	float yfgz;      //Ӧ������
	float grsds;    //��������˰
	float sfgz;     //ʵ������
	

};
int n=0;
int read(struct zg zg[])								
{		
		FILE *fp;
		struct zg w;
		if((fp=fopen("gx.dat","rb"))==NULL)
		{
			printf("�ļ��򿪳���\n");
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
int write(struct zg zg[])                                   //5.����ģ��
{
	int i;
	FILE *fp;
	if((fp=fopen("gx.dat","wb"))==NULL)
		{
			printf("�ļ��򿪳���\n");
			exit(1);
		}
	for(i=0;i<n;i++)
	{
		fwrite(&zg[i],sizeof(struct zg),1,fp);
	}
	fclose(fp);
	return 0;
}
/*int grsds()								//�����������˰ģ��
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
int find(struct zg zg[])                  //����ģ��
{
	int i;
	char gh[20];
	char ch;
//	do
//	{
	    printf("�밴���Ų���ְԱ������Ϣ\n");
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
int add(struct zg zg[])               //���ģ��
{
	char ch;
	FILE *fp;
	struct zg zgrl;
	if((fp=fopen("gx.dat","wb"))==NULL)
		{
			printf("�ļ��򿪳���\n");
			exit(1);
		}
//	do
//	{	
	    printf("������ְ������\n");
	    scanf("%s",zgrl.gh);
		printf("������ְ������\n");
		scanf("%s",zgrl.name);
		printf("������ְ����λ����\n");
		scanf("%f",&zgrl.gwgz);
		printf("������ְ��н������\n");
		scanf("%f",&zgrl.xjgz);
		printf("������ְ��ְ����\n");
		scanf("%f",&zgrl.zwjt);
		printf("������ְ����Ч����\n");
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
	printf("��������Ҫɾ����ְ������\n");
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
		
		printf("��ѡ�����蹦��:  1.��ѯ��Ϣ   2.�޸���Ϣ   3.������Ϣ   4.ɾ����Ϣ   5.������Ϣ    6.�����Ϣ \n");
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
				printf("û���������\n");
			}
		}while(i!=7);
	*/
	//add(zg);
	 modify(zg);
}
