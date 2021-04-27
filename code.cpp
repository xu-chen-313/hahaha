#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h> 
#include<conio.h>
#include<time.h>
struct student//先定义一个结构体数组 
{
 int num; 
 char name[20]; 
 int score;
 int banji;
 char xibie[20]; 
 struct student *next;//一个结构体指针 
};
void insert(struct student *head)//输入学生信息 
{
 FILE *fp;//将学生信息直接写到文件中
 int n;
 fp=fopen("D:\\wenjian.txt","w");
 struct student *l=head;
 struct student *p=head->next;//使用链表## 标题
 printf("请输入你要输入的学生的个数：");
 scanf("%d",&n);
 printf("\n");
 for(int i=1;i<=n;i++)
 {
  {
  struct student *p=(struct student *)malloc(sizeof(struct student));
  printf("请输入该生的学号：");
  scanf("%d",&p->num);
     printf("请输入该生的姓名：");
  scanf("%s",p->name);
  printf("请输入该生的成绩：");
  scanf("%d",&p->score);
  printf("请输入该生的班级："); 
  scanf("%d",&p->banji);
  printf("请输入该生的系别：");
  scanf("%s",p->xibie);
  printf("\n\n");   
  p->next=NULL;
  l->next=p;
  l=l->next;
  }
  p=head->next;//返回头 
  {
   fprintf(fp,"%d\t%s\t%d\t%d\t%s\t",l->num,l->name,l->score,l->banji,l->xibie);
       fputs("\n",fp);
  }  
 }
 fclose(fp);
 system("cls");
 printf("     输入完成！\n\n");
}
void add(struct student *head)//添加学生信息 
{
 FILE *fp;
 int n;
 fp=fopen("D:\\wenjian.txt","a+");
 struct student *l=head;
 while(l->next)
 l=l->next;
 printf("请输入你要添加的学生的个数：");
 scanf("%d",&n);
 printf("\n");
  for(int i=1;i<=n;i++)
  {
     struct student *p=(struct student *)malloc(sizeof(struct student));
     printf("请输入该生的学号：");
     scanf("%d",&p->num);
     printf("请输入该生的姓名：");
     scanf("%s",p->name);
     printf("请输入该生的成绩：");
     scanf("%d",&p->score);
     printf("请输入该生的班级："); 
     scanf("%d",&p->banji);
     printf("请输入该生的系别：");
     scanf("%s",p->xibie);
     printf("\n\n");   
     p->next=NULL;
     l->next=p;
     l=l->next;
  }
 l=head->next;   
 fclose(fp);
 fp=fopen("D:\\wenjian.txt","w");
 
 while(l!=NULL)
 {
  fprintf(fp,"%d\t%s\t%d\t%d\t%s\t",l->num,l->name,l->score,l->banji,l->xibie);
   fputs("\n",fp);
     l=l->next;
    }
    fclose(fp);
 system("cls");
 printf("     添加完成！\n\n");
}
