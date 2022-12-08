#include <stdio.h>
#include <stdlib.h>
//定义结构体
typedef struct student
{
    //信息域
    int num;
    char name[10];
    char sex;
    float score;
    //指针域
    struct student *next;
}stu;
//定义头指针
stu *head=NULL;
//目录
void menu()
{
    printf("===============\n");
    printf("1、学生成绩录入\n");
    printf("2、学生成绩删除\n");
    printf("3、学生成绩修改\n");
    printf("4、学生成绩查询\n");
    printf("5、学生成绩打印\n");
    printf("6、学生成绩保存\n");
    printf("7、释 放 空 间\n");
    printf("0、退       出\n");
    printf("===============\n");
}

void add()
{
    //定义选择变量
    int choose;
    //定义尾指针
    stu *last=NULL;
    while (1)
    {
        //当链表为空时，head当next成员指向last，last为新节点，用来存放数据，last当next成员指向空
        if(head==NULL)
        {
            //给第一个节点分配空间，当链表只有一个节点时，这个节点就是这个链表当last
            last=(stu *)malloc(sizeof (stu));
            last->next=NULL;
            head=(stu *)malloc(sizeof (stu));
            head->next=last;
            //录入信息到信息域
            printf("请输入学号：");
            scanf("%d",&last->num);
            printf("请输入姓名：");
            scanf("%s",last->name);
            getchar();
            printf("请输入性别（男:M,女:F)：");
            scanf("%c",&last->sex);
            printf("请输入成绩：");
            scanf("%f",&last->score);
        }
        //当链表不为空时，找到最后一个节点，last的next成员分配空间，然后最新的将last这个指针指向刚刚建立的空间为最新的last，然后最新的last的next成员指向null
        else if(head!=NULL)
        {
            //查找链表的最后一个节点
            last=head->next;
            while(last->next!=NULL)
            {
                last=last->next;
            }
            //分配新节点空间
            last->next=(stu *)malloc(sizeof (stu));
            //标注新的last
            last=last->next;
            last->next=NULL;
            //录入信息到信息域
            printf("请输入学号：");
            scanf("%d",&last->num);
            printf("请输入姓名：");
            scanf("%s",last->name);
            getchar();
            printf("请输入性别（男:M,女:F)：");
            scanf("%c",&last->sex);
            printf("请输入成绩：");
            scanf("%f",&last->score);
        }
        getchar();
        printf("还有继续么(y/n)：");
        char c = getchar();
        if (c == 'y' || c == 'Y')
        {
            //如果输入为y则执行空语句
            ;
        }
        else if (c == 'n' || c == 'N')
        {
            break;
        }
        else
        {
            printf("输入错误，即将退出删除系统!\n");
            break;

        }
    }
}
//删除成绩
void delete()
{
    while (1)
    {
        int num;
        if(head==NULL)
        {
            printf("学生成绩表无信息\n");
            break;
        }
        printf("请输入要删除成绩的学号：");
        scanf("%d",&num);
        stu *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            if(num==temp->next->num)
            {
                stu *del=temp->next;
                temp->next=temp->next->next;
                free(del);
                break;
            }
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("查无此人");
        }

        getchar();
        printf("还有继续么(y/n)：");
        char c = getchar();
        if (c == 'y' || c == 'Y')
        {
            //如果输入为y则执行空语句
            ;
        }
        else if (c == 'n' || c == 'N')
        {
            break;
        }
        else
        {
            printf("输入错误，即将退出删除系统!\n");
            break;

        }
    }
}
//void delete()
//{
//    int num;
//    char choose;
//    printf("请输入要删除的学号:");
//    scanf("%d",&num);
//    stu *temp=head;
//    while(temp->next!=NULL)
//    {
//        if(temp->next->num==num)
//            break;
//        temp=temp->next;
//    }
//    if(temp->next==NULL || temp->next->num!=num)
//    {
//        printf("没有符合条件的记录!\n");
//        system("pause");
//    }
//    else
//    {
//        printf("找到的信息如下:\n");
//        printf("学号:%d,姓名:%s,性别:%c,成绩:%5.2f\n",temp->next->num,temp->name,temp->next->sex,temp->next->score);
//        getchar();
//        printf("是否为您要删除的记录?(y/n)");
//        choose = getchar();
//        if(choose=='y' || choose=='Y')
//        {
//            stu *del=temp->next;
//            temp->next=temp->next->next;
//            free(del);
//            return ;
//        }
//    }
//
//}
//修改成绩
void alter()
{
    while (1)
    {
        int num;
        if(head==NULL)
        {
            printf("学生成绩表无信息\n");
            break;
        }
        printf("请输入要修改成绩的学号：");
        scanf("%d",&num);
        stu *temp;
        temp=head->next;
        while(temp!=NULL)
        {
            if(num==temp->num)
            {
                printf("请输入要修改的成绩：");
                scanf("%f",&temp->score);
                break;
            }
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("查无此人");
        }

        getchar();
        printf("还有继续么(y/n)：");
        char c = getchar();
        if (c == 'y' || c == 'Y')
        {
            //如果输入为y则执行空语句
            ;
        }
        else if (c == 'n' || c == 'N')
        {
            break;
        }
        else
        {
            printf("输入错误，即将退出删除系统!\n");
            break;

        }
    }
}
//链表当输出
void print()
{
    stu *temp;
    temp=head->next;
    printf("学号\t\t\t\t姓名\t\t性别\t\t成绩\n");
    while(temp!=NULL)
    {
        printf("%-16d%-8s%-8c%-8.2f\n",temp->num,temp->name,temp->sex,temp->score);
        temp=temp->next;
    }
    return;

}
//释放空间
void release()
{
    stu *temp_2;
    while(head!=NULL)
    {
        temp_2=head;
        head=head->next;
        free(temp_2);
    }

}
//查找成绩
void find()
{
    while (1)
    {
        int num;
        if(head==NULL)
        {
            printf("学生成绩表无信息\n");
            break;
        }
        printf("请输入要查找的学号：");
        scanf("%d",&num);
        stu *temp;
        temp=head->next;
        while(temp!=NULL)
        {
            if(num==temp->num)
            {
                printf("你要查找的学生信息如下：\n");
                printf("学号\t\t\t\t姓名\t\t性别\t\t成绩\n");
                printf("%-16d%-8s%-8c%-8.2f\n",temp->num,temp->name,temp->sex,temp->score);
                break;
            }
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("查无此人");
        }

        getchar();
        printf("还有继续么(y/n)：");
        char c = getchar();
        if (c == 'y' || c == 'Y')
        {
            //如果输入为y则执行空语句
            ;
        }
        else if (c == 'n' || c == 'N')
        {
            break;
        }
        else
        {
            printf("输入错误，即将退出删除系统!\n");
            break;

        }
    }
}
void save()
{
    FILE *fp;
    fp= fopen("/Users/alan/Desktop/student.txt ","a+");
    if(fp==NULL) {
        printf("文件打开失败了！\n");
        return;
    }
    stu *temp=head->next;
    while(temp!=NULL)
    {
        fwrite(temp,sizeof(stu),1,fp);
        temp=temp->next;
    }
    fclose(fp);
    printf("文件保存成功\n");
    return;

}
//void read()
//{
//    int i;
//     stu *p,*r;   //r是尾节点
//    FILE *fp;
//    //if((fp=fopen("student2.txt","r"))==NULL) //如果文件不存在则建立文件
//    //{
//    //	fp=fopen("student2.txt","w");
//    //}
//    if((fp=fopen("student2.txt","r"))==NULL)
//    {
//        printf("文件无法打开！\n");
//        exit(1);
//    }
//    r=head;
//    fscanf(fp,"%d",&N);
//    for(i=0;i<N;i++)
//    {
//        p=(struct node *)malloc(sizeof(struct node));
//        fscanf(fp,"%-16d%-8s%-8c%-8.2f",p->num,p->name,p->sex,p->score);//将数据读取到节点的数据域中
//        r->next=p;  //每读取到一个数据就将节点插入表尾
//        r=p;
//    }
//    r->next=NULL;
//    fclose(fp);
//}//
//选择功能
int select()
{
    while (1)
    {
        int i;
        menu();
        printf("请输入要选择的功能：");
        scanf("%d",&i);
        switch (i)
        {
            case 1: add();break;
            case 2: delete();break;
            case 3: alter();break;
            case 4: find();break;
            case 5: print();break;
            case 6: save();break;
            case 7: release();break;
            case 0: return 0;
            default: printf("输入错误，请重新输入");break;
        }
    }
}
int main()
{
    select();
}