#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
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
}zg[100];
int n=0;
int read()								//���ļ�ģ��
{		
		FILE *fp;                               //�����ļ�ָ��
		if((fp=fopen("gx.dat","rb"))==NULL)     //�ж��ļ��Ƿ�ɹ���
		{
			printf("�ļ��򿪳���\n");
			exit(1);
		}
			                  //�ж��ļ��Ƿ�ĩβ
		for(n;n<100;n++)
		{			
			fread(&(zg[n]),sizeof(struct zg),1,fp);
			grsds();
			if(feof(fp))
			break;
		}
		fclose(fp);	                          //�ر��ļ�
		return 0;
}
int write()                                   //5.����ģ��
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
		fwrite(&(zg[i]),sizeof(struct zg),1,fp);	//�ѽṹ���е�����д���ļ�
	}
	printf("�������ݳɹ�\n");
	fclose(fp);                                    //�ر��ļ�
	return 0;
}
int grsds()								//�����������˰ģ��
{
	zg[n].yfgz=zg[n].gwgz+zg[n].jxgz+zg[n].xjgz+zg[n].zwjt;  //����Ӧ������  
	if(zg[n].yfgz>=0&&zg[n].yfgz<=500)                  //����Ӧ��������0��500�ĸ�������˰
	{
		zg[n].grsds=(zg[n].yfgz*5)/100;
	}
	else if(zg[n].yfgz>500&&zg[n].yfgz<=2000)					//����Ӧ��������500��2000�ĸ�������˰
	{
		zg[n].grsds=(500.0*5+(zg[n].yfgz-500)*10)/100;
	}
	else if(zg[n].yfgz>2000&&zg[n].yfgz<=5000)							//����Ӧ��������2000��5000�ĸ�������˰
	{
		zg[n].grsds=(500.0*5+1500*10+(zg[n].yfgz-2000)*15)/100;
	}
	else if(zg[n].yfgz>5000&&zg[n].yfgz<=20000)								//����Ӧ��������5000��20000�ĸ�������˰
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+(zg[n].yfgz-5000)*20)/100;
	}
	else if(zg[n].yfgz>20000&&zg[n].yfgz<=40000)									//����Ӧ��������20000��40000�ĸ�������˰
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+(zg[n].yfgz-200000)*25)/100;
	}
	else if(zg[n].yfgz>40000&&zg[n].yfgz<=60000)										//����Ӧ��������400000��60000�ĸ�������˰
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+(zg[n].yfgz-400000)*30)/100;
	}
	else if(zg[n].yfgz>60000&&zg[n].yfgz<=80000)											//����Ӧ��������60000��80000�ĸ�������˰
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+20000*30+(zg[n].yfgz-600000)*35)/100;
	}
	else if(zg[n].yfgz>80000&&zg[n].yfgz<=100000)												//����Ӧ��������80000��100000�ĸ�������˰
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+20000*30+20000*35+(zg[n].yfgz-800000)*40)/100;
	}	
	else if(zg[n].yfgz>100000)																		//����Ӧ��������100000���ϸ�������˰
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+20000*30+20000*35+20000*40+(zg[n].yfgz-100000)*45)/100;
	} 
	zg[n].sfgz=zg[n].yfgz-zg[n].grsds;  //����ʵ������
	return 0;
}
int find()                     //����ģ��
{
	int i;					  
	char gh[20];              //������ҹ���

	 printf("�밴���Ų���ְԱ������Ϣ\n");
	 scanf("%s",gh);
	 for(i=0;i<=n;i++)
	 {
		if(strcmp(zg[i].gh,gh)==0)             //�жϲ��ҵĹ����Ƿ����ļ��з���
			{
				printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
				printf("%s\t%s\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\n",zg[i].gh,zg[i].name,zg[i].gwgz,zg[i].xjgz,zg[i].zwjt,zg[i].jxgz,zg[i].yfgz,zg[i].grsds,zg[i].sfgz);
			    break;
			}
		if(i==n) 
			printf("���鹤�Ų�����\n");
		
	}	
	return 0;
}
int add()               //���ģ��
{
	int i;
	printf("������ְ������\n");
	scanf("%s",&zg[n].gh);
	for(i=0;i<n;i++)
	{
		if(strcmp(zg[n].gh,zg[i].gh)==0)               //�жϹ����Ƿ����
		{
			printf("������Ĺ����Ѵ��ڣ�����������\n");
			printf("������ְ������\n");
			scanf("%s",zg[n].gh);
			i=0;                                      //�����ж�
		}
	}
	printf("������ְ������\n");
	scanf("%s",&zg[n].name);
	printf("������ְ����λ����\n");
	scanf("%f",&zg[n].gwgz);
	printf("������ְ��н������\n");
	scanf("%f",&zg[n].xjgz);
	printf("������ְ��ְ����\n");
	scanf("%f",&zg[n].zwjt);
	printf("������ְ����Ч����\n");
	scanf("%f",&zg[n].jxgz);
	
	zg[n].yfgz=zg[n].gwgz+zg[n].jxgz+zg[n].xjgz+zg[n].zwjt; //����Ӧ������
	grsds();     //�����������˰
	zg[n].sfgz=zg[n].yfgz-zg[n].grsds;                       //����ʵ������
	n++;
	
	return 0;
}
int del()                                                   //ɾ��ģ��
{
	int i,j,choice;
	char gh[20];
	printf("��������Ҫɾ����ְ������\n");
	scanf("%s",gh);
	for(i=0;i<=n;i++)
	{
		if(strcmp(zg[i].gh,gh)==0)                         //�жϹ����Ƿ����
		{	
			printf("�Ƿ�ȷ��ɾ����ɾ��������1��ȡ��������0:/n");
			scanf("%d",&choice);
			if(choice==1)
			{
				j=i;
				for(j;j<=n;j++)
				{	
					zg[j]=zg[j+1];
					n--;
				}
				printf("ɾ���ɹ�\n");
				break;
			}
			if(choice==0)
			break;
		}
		if(i==n) 
			printf("���鹤�Ų�����\n");
	}
	return 0;
}
int list()                        //��ʾģ��
{
	int i;
	printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
	for(i=1;i<n;i++)
	{
		printf("%s\t%s\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\n",zg[i].gh,zg[i].name,zg[i].gwgz,zg[i].xjgz,zg[i].zwjt,zg[i].jxgz,zg[i].yfgz,zg[i].grsds,zg[i].sfgz);
	}
	return 0;
}
void modify()    //�޸�ģ��
{
	int i,choice;
	char gh[20];
	printf("������Ҫ�޸ĵ�ְ���Ĺ���\n");
	scanf("%s",gh);
	for(i=0;i<n;i++)
	{
		if(strcmp(zg[i].gh,gh)==0)
		{

			printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
			printf("%s\t%s\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\n",zg[i].gh,zg[i].name,zg[i].gwgz,zg[i].xjgz,zg[i].zwjt,zg[i].jxgz,zg[i].yfgz,zg[i].grsds,zg[i].sfgz);
			printf("����������Ҫ�޸ĵĵط�  1.����   2.��λ����   3.н������  4.ְ����  5.��Ч���� 6.�˳�\n");
		do{
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:                               //�޸�����
					printf("���޸�ְ������\n");
					scanf("%s",&zg[i].name);
					break;
			case 2:								//�޸ĸ�λ����
					printf("���޸�ְ����λ����\n");
					scanf("%f",&zg[i].gwgz);
					break;
			case 3:								//�޸�н������
					printf("���޸�ְ��н������\n");
					scanf("%f",&zg[i].xjgz);
					break;
			case 4:								//�޸�ְλ����
					printf("���޸�ְ��ְ����\n");
					scanf("%f",&zg[i].zwjt);
					break;
			case 5:								//�޸ļ�Ч����
					printf("���޸�ְ����Ч����\n");
					scanf("%f",&zg[i].jxgz);
					break;
			case 6:
				break;
			}
			zg[i].yfgz=zg[i].gwgz+zg[i].jxgz+zg[i].xjgz+zg[i].zwjt;
			zg[i].sfgz=zg[i].yfgz-zg[i].grsds;
			printf("�����޸�������ѡ��\n");
		}while(choice!=6);
		printf("�޸ĺ�Ľ��\n");
		printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
		printf("%8s\t%s8\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\t%8.2f\n",zg[i].gh,zg[i].name,zg[i].gwgz,zg[i].xjgz,zg[i].zwjt,zg[i].jxgz,zg[i].yfgz,zg[i].grsds,zg[i].sfgz);
		}
		if(i==n)    //�жϹ����Ƿ����
			printf("���鹤�Ų�����\n");
	}
	
}
void main()
{
	int i;	
	read();
	grsds();
	printf("-------------******************��ӭʹ��ְ�����ʹ���ϵͳ******************-------------\n");
	do{
		//system("pause");
	//	system("cls");
		printf("��ѡ�����蹦��:  1.��ѯ��Ϣ   2.�޸���Ϣ   3.������Ϣ   4.ɾ����Ϣ   5.������Ϣ    6.�����Ϣ  7.�˳�����\n");
		scanf("%d",&i);
		    if(i==1)
			{
			    find();			//���ò�ѯ����
			}
		    else if(i==2)
			{
			    modify();		//�����޸ĺ���
			}
		   else if(i==3)
			{
			    add();			//���������Ϣ����
			}
	   	    else if(i==4)
			{
			    del();			//����ɾ������
			}
		   else if(i==5)
			{
		 	    write();		//���ñ��溯��
			}
		    else if(i==6)
			{
			    list();          //�����������
			}
		    else if(i==7)
			{
				printf("-------------******************��ӭ�´�ʹ��ְ�����ʹ���ϵͳ******************-------------\n");
		  	    exit(0);
			}
			else
				printf("û��������ܣ�");
		}while(i!=7);
}
