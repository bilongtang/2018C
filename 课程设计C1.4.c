/************************************************************
Copyright (C), 1988-1999, mingda Tech. Co., Ltd.
FileName: ���.cpp
Author:������   Version :1.4   Date:2018.06.26
Description: // ģ������
Version: 1.4��// �汾��Ϣ
Function List: // ��Ҫ�������书��
1.main����������Ҫ�Ǹ����û���ָ����ø������ܺ�����
2.read()������Ҫ�Ƕ�ȡְ���������ݡ�
3.write()������Ҫ�Ǳ���ְ���������ݡ�
4.void fin()������Ҫ�ǲ�ѯְ���������ݡ�
5.list()������Ҫ�����ְ���������ݡ�
6.modify()������Ҫ���޸�ְ�����ʡ�
7.del()������Ҫ��ɾ��ְ���������ݡ�
8.add()������Ҫ�����ְ���������ݡ�
9.grsds()������Ҫ�Ǽ����������˰
History: // ��ʷ�޸ļ�¼
<author> <time> <version > <desc>
David 96/10/12 1.0 build this moudle
*************************************************************/
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
/***************************************************************************
Function:read����           
Description:������ȡ�ļ���gx.dat���е����ݣ����浽�ṹ��zggz�� 
Calls:  grsds()   //���ø�������˰���������������˰                  
Called By:main()������                   
Table Accessed: �ļ���gx.dat��         
Table Updated: ��                    
Input:                
Output:              
Return:          
Others:         
***************************************************************************/

int read()								//���ļ�ģ��
{		
	FILE *fp;                               //�����ļ�ָ��
	if((fp=fopen("gx.dat","rb"))==NULL)     //�ж��ļ��Ƿ�ɹ���
	{
		printf("�ļ��򿪳���\n");
		exit(1);
	}			                  
	for(n;n<100;n++)
	{			
		fread(&(zg[n]),sizeof(struct zg),1,fp);  //ÿ�δ��ļ��ж�ȡһ�����ݵ��ṹ��
		grsds();
		if(feof(fp))                       //�ж��ļ��Ƿ�ĩβ
		{
			break;
		}
	}
	fclose(fp);	                          //�ر��ļ�
	return 0;
}

/***************************************************************************
Function:write����             // ��������
Description:�������ṹ��������д����gx.dat��                  // �������ܡ����ܵȵ�����
Calls:  system("pause")                   
Called By:main()������                   
Table Accessed: �ļ���gx.dat��          
Table Updated:  �ļ���gx.dat��                    
Input:               
Output:             
Return:          
Others:          
***************************************************************************/

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
	system("pause");
	return 0;
}

/***************************************************************************
Function:grsds����             // ��������
Description:�����������˰                  // �������ܡ����ܵȵ�����
Calls:  ��                    
Called By:read������add()������                   
Table Accessed: �ļ� ��          
Table Updated: ��                     
Input:                
Output:              
Return:         
Others:         
***************************************************************************/

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
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+(zg[n].yfgz-20000)*25)/100;
	}
	else if(zg[n].yfgz>40000&&zg[n].yfgz<=60000)										//����Ӧ��������400000��60000�ĸ�������˰
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+(zg[n].yfgz-40000)*30)/100;
	}
	else if(zg[n].yfgz>60000&&zg[n].yfgz<=80000)											//����Ӧ��������60000��80000�ĸ�������˰
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+20000*30+(zg[n].yfgz-60000)*35)/100;
	}
	else if(zg[n].yfgz>80000&&zg[n].yfgz<=100000)												//����Ӧ��������80000��100000�ĸ�������˰
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+20000*30+20000*35+(zg[n].yfgz-80000)*40)/100;
	}	
	else if(zg[n].yfgz>100000)																		//����Ӧ��������100000���ϸ�������˰
	{
		zg[n].grsds=(500.0*5+1500*10+3000*15+15000*20+20000*25+20000*30+20000*35+20000*40+(zg[n].yfgz-100000)*45)/100;
	} 
	zg[n].sfgz=zg[n].yfgz-zg[n].grsds;  //����ʵ������
	return 0;
}

/***************************************************************************
Function:find����             
Description:������ͬ���ŵ�ְ����Ϣ                  
Calls:  system("pause")                   
Called By:main()������                   
Table Accessed:           
Table Updated:                  
Input:  gh ����������ҵĹ���      
Output:  ������ҳ����˵�ȫ����Ϣ      
Return:          
Others:          
***************************************************************************/

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
			printf("����\t  ����\t\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t  ��������˰  \tʵ������\n");
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
			printf("���鹤�Ų�����\n");
		}
		
	}	
	system("pause");
	return 0;
}

/***************************************************************************
Function:add����             
Description:���ְ����¼                  
Calls:  system("pause")                   
Called By:main()������                   
Table Accessed:           
Table Updated:                     
Input:   ����ְ����Ϣ            
Output:             
Return:          
Others:          
***************************************************************************/

int add()               //���ģ��
{
	int i;
	if(n==100)              //�ж��ļ��Ƿ�洢��
	{
		printf("�ļ��洢��������");
		return 0;

	}
	printf("������ְ������: ");
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
	printf("������ְ������: ");
	scanf("%s",&zg[n].name);
	printf("������ְ����λ����: ");
	scanf("%f",&zg[n].gwgz);
	printf("������ְ��н������: ");
	scanf("%f",&zg[n].xjgz);
	printf("������ְ��ְ����: ");
	scanf("%f",&zg[n].zwjt);
	printf("������ְ����Ч����: ");
	scanf("%f",&zg[n].jxgz);
	zg[n].yfgz=zg[n].gwgz+zg[n].jxgz+zg[n].xjgz+zg[n].zwjt; //����Ӧ������
	grsds();                                                //�����������˰
	zg[n].sfgz=zg[n].yfgz-zg[n].grsds;                       //����ʵ������
	n++;                                                    //��ӳɹ����ݺ�n+1
	system("pause");
	return 0;
}

/***************************************************************************
Function:del����             
Description:ɾ��ָ��ְ������Ϣ                 
Calls:  system("pause")                   
Called By:main()������                   
Table Accessed:           
Table Updated:                      
Input: ��������ɾ��ְ���Ĺ��ţ�ѡ���Ƿ�ɾ������	              
Output:             
Return:          
Others:          
***************************************************************************/

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
			printf("����\t  ����\t\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t  ��������˰  \tʵ������\n");
			printf("%-10s",zg[i].gh);
			printf("%-10s",zg[i].name);
			printf("%12.2f\t",zg[i].gwgz);
			printf("%8.2f\t",zg[i].xjgz);
			printf("%8.2f\t",zg[i].zwjt);
			printf("%8.2f\t",zg[i].jxgz);
			printf("%8.2f\t",zg[i].yfgz);
			printf("%8.2f\t",zg[i].grsds);
			printf("%8.2f\t\n",zg[i].sfgz);
			printf("�Ƿ�ȷ��ɾ����ְ����ɾ��������1��ȡ��������0:\n");   //ѡ���Ƿ�Ҫɾ��
			scanf("%d",&choice);
			if(choice==1)
			{
				j=i;
				for(j;j<=n;j++)
				{	
					zg[j]=zg[j+1];             //ɾ�����ҵ��Ĺ���
					n--;
				}
				printf("ɾ���ɹ�\n");
				break;
			}
			if(choice==0)
			{
				break;
			}
		}
		if(i==n) 
		{
			printf("���鹤�Ų�����\n");
		}
	}
	system("pause");
	return 0;
}
/***************************************************************************
Function:list����             
Description:��ʾȫ��ְ����Ϣ��¼                  
Calls:  system("pause")                   
Called By:main()������                   
Table Accessed:           
Table Updated:                     
Input:               
Output:    ���ְ����Ϣ         
Return:          
Others:          
***************************************************************************/
int list()                        //��ʾģ��
{
	int i;
	printf("����\t  ����\t\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t  ��������˰  \tʵ������\n");
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

/***************************************************************************
Function:modify����             
Description:�޸�ְ����ĳһ����Ϣ                 
Calls:  system("pause")                   
Called By:main()������                   
Table Accessed:           
Table Updated:                      
Input:          ���������޸�����
Output:        ����޸�ǰ���޸ĺ���     
Return:          
Others:          
***************************************************************************/

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

			printf("����\t  ����\t\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t  ��������˰  \tʵ������\n");
			printf("%-10s",zg[i].gh);
			printf("%-10s",zg[i].name);
			printf("%12.2f\t",zg[i].gwgz);
			printf("%8.2f\t",zg[i].xjgz);
			printf("%8.2f\t",zg[i].zwjt);
			printf("%8.2f\t",zg[i].jxgz);
			printf("%8.2f\t",zg[i].yfgz);
			printf("%8.2f\t",zg[i].grsds);
			printf("%8.2f\t\n",zg[i].sfgz);
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
			printf("�����޸�������ѡ��1.����   2.��λ����   3.н������  4.ְ����  5.��Ч���� 6.�˳�\n");
		}while(choice!=6);
		printf("�޸ĺ�Ľ��\n");
		printf("����\t  ����\t\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t  ��������˰  \tʵ������\n");
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
		if(i==n)    //�жϹ����Ƿ����
			printf("���鹤�Ų�����\n");
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
		printf("                                 ### ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###                                 \n\n\n");
		printf("                                 ��ѡ��<1 - 7> :\n");
		printf("                                 ===============================================================                                 \n");
		printf("                                 |                 1.��ѯְ�����ʼ�¼                          |                                 \n");
		printf("                                 |                 2.�޸�ְ�����ʼ�¼                          |                                 \n");
		printf("                                 |                 3.���ְ�����ʼ�¼                          |                                 \n");
		printf("                                 |                 4.ɾ��ְ�����ʼ�¼                          |                                 \n");
		printf("                                 |                 5.�������ݵ��ļ�                            |                                 \n");
		printf("                                 |                 6.���ְ����¼                              |                                 \n");
		printf("                                 |                 7.�˳�ϵͳ                                  |                                 \n");
		printf("                                 ===============================================================                                 \n");
		printf("                                 ����������Ҫѡ��Ĺ��ܣ�");
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
				printf("--------------************************************��ӭ�´�ʹ��ְ�����ʹ���ϵͳ************************************--------------\n");
		  	    exit(0);
			}
			else  
				printf("û��������ܣ�������ѡ��");
		}while(1);
}