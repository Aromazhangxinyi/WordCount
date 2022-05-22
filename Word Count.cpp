#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void count(char *filename)//统计文件filename里字符和单词数量的函数 
{
	FILE *file;
	char c;
	char buffer[1000];
	int bufferlength;//定义字符长度 
	int isLastBlank=1;//上个字符是否是空格 
	int wordCount=0;//定义单词数量初始为0 
	int charCount=0;//定义字符数量初始为0 
	
	if((file=fopen(filename,"rb"))==NULL)
	{
		printf("文件不能打开");
		exit(0);
	}//文件不能打开的情况 
	//文件打开 
	while(fgets(buffer,1000,file)!=NULL)//读取文本文件中的字符，当文本文件里内容不是NULL则继续 
	{
		bufferlength=strlen(buffer);//字符长度=读取的全部字符长度 
		for(int i=0;i<bufferlength;i++)//扫描文本文件内的所有字符 
		{
			c=buffer[i];//每次读取到一个数据，将其保存到buffer[]里 
			if(c==' ' || c=='\t' || c=='\n')//若扫描到的字符是 空格 、换行等字符 
			{
				charCount++;//字符数量+1 
			}
			
			if(c==' ' || c==',')//若 扫描到的是空格或逗号 
			{
				if(isLastBlank==0)//若上个字符不是空格 
				{
					wordCount++;//则单词数量+1 
				}
				isLastBlank=1;
			}
			
			if(c!=' ' && c!=',' && c!='\t' && c!='\n')//若 扫描到的不是 空格、 逗号 、换行、空行等字符 
			{
				isLastBlank=0;//则上个字符不是空格 
			}
		}
		
		if(isLastBlank==0)
		{
			wordCount++;
		}
		fclose(file);//关闭文本文件 
		printf("单词数：%d\n",wordCount);
		printf("字符数：%d\n",charCount);
	}
}
int main()//主函数 
{
	char filename[]="D:\\gitku\\wordcount.txt"; //打开文本文件 
	count(filename);//统计该文本文件内的字符数量和单词数量 
	return 0;
	
}

