#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void count(int n,char *filename);
int main()
{
	char filename[30];
	int n;
	char operand[2];
	scanf("%s",operand);
	scanf("%s",filename);
	if(strcmp(operand,"-c")==0)
		n = 0;
	else if(strcmp(operand,"-w")==0)
		n = 1;
	else
		printf("ERROR!!!\n");
	count(n,filename);
 } 
 void count(int n,char *filename)
 {
 FILE *fp;
	char buffer[1000];
	char c;
	int bufferlen;
	int isLastBlank = 0; 
	int charCount=0;
	int wordCount=0;
	int lineCount=0;
	int i;
 
	if((fp=fopen(filename,"rb"))==NULL){
		printf("文件不能打开\n");
		exit(0);
	}
	while(fgets(buffer,1000,fp)!=NULL){
		bufferlen=strlen(buffer);
		for(i=0;i<bufferlen;i++){
			c=buffer[i];
			if(c==' ' || c=='\t' || c == ','){//空格，制表，逗号均为分隔，代表一个单词 
				if(isLastBlank==0){
					wordCount++;
				}
				isLastBlank=1;
			}else{
				if(c == '\n') //换行加2 
				charCount+=2;
				charCount++;
				isLastBlank=0;
			}
 
		}
		if(isLastBlank==0)
			wordCount++;
		isLastBlank=1;
		lineCount++;
	}
	fclose(fp);
	if(n==0)
	printf("字符数：%d\n",charCount);
	else
	printf("单词数：%d\n",wordCount);
	
 }
