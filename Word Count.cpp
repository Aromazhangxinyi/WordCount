#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void count(char *filename)//ͳ���ļ�filename���ַ��͵��������ĺ��� 
{
	FILE *file;
	char c;
	char buffer[1000];
	int bufferlength;//�����ַ����� 
	int isLastBlank=1;//�ϸ��ַ��Ƿ��ǿո� 
	int wordCount=0;//���嵥��������ʼΪ0 
	int charCount=0;//�����ַ�������ʼΪ0 
	
	if((file=fopen(filename,"rb"))==NULL)
	{
		printf("�ļ����ܴ�");
		exit(0);
	}//�ļ����ܴ򿪵���� 
	//�ļ��� 
	while(fgets(buffer,1000,file)!=NULL)//��ȡ�ı��ļ��е��ַ������ı��ļ������ݲ���NULL����� 
	{
		bufferlength=strlen(buffer);//�ַ�����=��ȡ��ȫ���ַ����� 
		for(int i=0;i<bufferlength;i++)//ɨ���ı��ļ��ڵ������ַ� 
		{
			c=buffer[i];//ÿ�ζ�ȡ��һ�����ݣ����䱣�浽buffer[]�� 
			if(c==' ' || c=='\t' || c=='\n')//��ɨ�赽���ַ��� �ո� �����е��ַ� 
			{
				charCount++;//�ַ�����+1 
			}
			
			if(c==' ' || c==',')//�� ɨ�赽���ǿո�򶺺� 
			{
				if(isLastBlank==0)//���ϸ��ַ����ǿո� 
				{
					wordCount++;//�򵥴�����+1 
				}
				isLastBlank=1;
			}
			
			if(c!=' ' && c!=',' && c!='\t' && c!='\n')//�� ɨ�赽�Ĳ��� �ո� ���� �����С����е��ַ� 
			{
				isLastBlank=0;//���ϸ��ַ����ǿո� 
			}
		}
		
		if(isLastBlank==0)
		{
			wordCount++;
		}
		fclose(file);//�ر��ı��ļ� 
		printf("��������%d\n",wordCount);
		printf("�ַ�����%d\n",charCount);
	}
}
int main()//������ 
{
	char filename[]="D:\\gitku\\wordcount.txt"; //���ı��ļ� 
	count(filename);//ͳ�Ƹ��ı��ļ��ڵ��ַ������͵������� 
	return 0;
	
}

