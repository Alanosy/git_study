#include <stdio.h>
#include <windows.h>
//定义最大人数为多少
#define max 100
//定义存放数据的数组
int student[max][2];
//声明一个临时数组
int temparr[max][2]; 
//定义实际人数
int actual=0;
//声明归并函数的拆分函数与归并函数
void split();
void merge();
void print();
void aes();
void copy();
int x_2();
//菜单
void menu()
{
	 printf("=========================================\n");
	 printf("||           ----------------          ||\n"); 
	 printf("||**********学生信息管理系统***********||\n");
	 printf("||           ----------------          ||\n");
	 printf("||                                     ||\n");
	 printf("||~~~~~~~~~~~1.录入学生信息~~~~~~~~~~~~||\n");
	 printf("||~~~~~~~~~~~2.删除学生信息~~~~~~~~~~~~||\n");
	 printf("||~~~~~~~~~~~3.修改学生信息~~~~~~~~~~~~||\n");
	 printf("||~~~~~~~~~~~4.查询学生信息~~~~~~~~~~~~||\n");
	 printf("||~~~~~~~~~~~5.显示学生信息~~~~~~~~~~~~||\n");
	 printf("||~~~~~~~~~~~6.排序学生信息~~~~~~~~~~~~||\n");
	 printf("||~~~~~~~~~~~7.显示最高成绩~~~~~~~~~~~~||\n");
	 printf("||~~~~~~~~~~~0.退        出~~~~~~~~~~~~||\n");
	 printf("||                                     ||\n");
	 printf("||*************************************||\n");
} 
//录入成绩
void add()
{
	int i;
    for (i = 0; i < max - actual;i++)
    {
        int temp,k=0;//temp用来存放学号
        //当数组有成绩时
        if (actual>0) {
            printf("请输入第%d位学生的学号为：", actual+1);
            scanf("%d", &temp);
            //判断是否有重复学号
            while (temp!=student[k][0]&&k<actual)
            {
                k++;
            }
            if(temp==student[k][0])
            {
                //如果在数组中找到相同学号，则跳出本次循环重新输入
                printf("学号重复请重新输入!\n");
                continue;
            }
            else
            {
                student[actual][0]=temp;
                printf("请输学号为%d的同学成绩：", student[actual][0]);
                scanf("%d", &student[actual][1]);
                actual++;

            }
            //判断是否继续
            getchar();
            printf("还要继续么(y/n):");
            char c = getchar();
            if (c == 'y' || c == 'Y')
            {
                system("cls");
            }
            else if (c == 'n' || c == 'N')
            {
            	system("cls");
                break;
            }
            else
            {
                printf("输入错误，即将退出录入系统!\n");
                system("cls");
                break;
            }
            }
            //当数组没有成绩时
            else if (actual==0) {
            printf("请输入第%d位学生的学号为：", i + 1);
            scanf("%d", &temp);
            //查找并判断是否有重复的学号
            while (temp!=student[k][0]&&k<actual)
            {
                k++;
            }
            if(temp==student[k][0])
            {
                //如果在数组中找到相同学号，则跳出本次循环重新输入
                printf("学号重复请重新输入!\n");
                continue;
            }
            else
            {
                student[i][0]=temp;
                printf("请输学号为%d的同学成绩：", student[i][0]);
                scanf("%d", &student[i][1]);
                actual++;

            }
            getchar();
            printf("还要继续么(y/n):");
            char c = getchar();
            if (c == 'y' || c == 'Y') { system("cls");
            } else if (c == 'n' || c == 'N') {
            	system("cls");
                break;
            } else {
                printf("输入错误，即将退出录入系统!\n");
                system("cls");
                break;
            }
        }


    }
}
//删除成绩
void delete()
{
    while (1) {
    	if(actual==0)
    	{
    		printf("无学生成绩信息\n");
			system("pause");
			break;
			 
		}
		else
		{
			int m;
	   		printf("成绩表如下（学号-成绩）：\n");
	    	for(m=0;m<actual;m++)
	    	{
	        	printf("%4d%4d\n",student[m][0],student[m][1]);
	    	}	
	        int number, i = 0;
	        //输入要删除成绩的学号
	        printf("请输入要删除成绩的学号：");
	        scanf("%d", &number);
	        //查找学号
	        while (number != student[i][0] && i < actual)
	        {
	            i++;
	        }
	        //判断是否有此学号
	        if (number == student[i][0])
	        {
	        	system("cls");
	            printf("查询到如下信息：\n");
	            printf("%4d%4d\n",student[i][0],student[i][1]);
	            getchar();
	            printf("请问是否删除该信息(y/n):");
	            char a = getchar();
	            if (a == 'y' || a == 'Y')
	            {
	                ;
	            }
	            else if (a == 'n' || a == 'N')
	            {
	                break;
	            }
	            else
	            {
	                printf("输入错误，即将退出修改系统!\n");
	            }
	            //如果有，则后面的成绩覆盖要删除的成绩，后面依次往前挪
	            for(;i<actual;i++)
	            {
	                student[i][0]=student[i+1][0];
	                student[i][1]=student[i+1][1];
	
	            }
	            printf("删除成功!\n");
	            actual--;
	        }
	        else
	        {
	            //如果没有，则输出查无此人
	            printf("查无此人!\n");
	        }
	        //删除一个成绩则实际人数减一
	
	        //判断是否继续删除
	        getchar();
	        printf("还要继续么(y/n)：");
	        char c = getchar();
	        if (c == 'y' || c == 'Y')
	        {
	            //如果输入为y则执行空语句
	            system("cls");
	        }
	        else if (c == 'n' || c == 'N')
	        {
	        	system("cls");
	            break;
	        }
	        else
	        {
	            printf("输入错误，即将退出删除系统!\n");
	            system("cls");
	            break;
	
	        }
		}

    }
}
//修改成绩
void alter() {
    while (1) {
    	if(actual==0)
    	{
    		printf("无学生成绩信息\n");
			system("pause");
			break;
			 
		}
		else
		{
			int m;
	   		printf("成绩表如下（学号-成绩）：\n");
	    	for(m=0;m<actual;m++)
	    	{
	        	printf("%4d%4d\n",student[m][0],student[m][1]);
	    	}	
	        int number, i = 0;
	        //输入要修改成绩的学号
	        printf("请输入要修改的学号：");
	        scanf("%d", &number);
	        //开始查找与学号配对的成绩位置
	        while (number != student[i][0] && i < actual)
	        {
	            i++;
	        }
	        //判断是否有该学号的成绩
	        if (number == student[i][0])
	        {
	        	system("cls");
	            printf("查询到如下信息：\n");
	            printf("%4d%4d\n",student[i][0],student[i][1]);
	            getchar();
	            printf("请问是否修改该信息(y/n):");
	            char a = getchar();
	            if (a == 'y' || a == 'Y')
	            {
	                ;
	            }
	            else if (a == 'n' || a == 'N')
	            {
	                break;
	            }
	            else
	            {
	                printf("输入错误，即将退出修改系统!\n");
	                break;
	            }
	            //有该学号则输入修改后的成绩
	            printf("请输入要修改的成绩：");
	            scanf("%d", &student[i][1]);
	            printf("修改成功\n");
	        }
	        else
	        {
	            //没有则输出查无此人
	            printf("查无此人\n");
	        }
	        //判断是否继续修改
	        getchar();
	        printf("还要继续么(y/n)：");
	        char c = getchar();
	        if (c == 'y' || c == 'Y')
	        {
	            system("cls");
	        }
	        else if (c == 'n' || c == 'N')
	        {
	        	system("cls");
	            break;
	        }
	        else
	        {
	        	
	            printf("输入错误，即将退出修改系统!\n");
	            sleep(5);
	            system("cls");
	        }	
		}
    	

    }
}
//查找成绩
void find()
{
    while (1) {

        if(actual==0)
        {
        	printf("无学生成绩信息\n");
			system("pause");
			break;
		}
		else
		{
			int number, i = 0;
	        //输入要查找成绩的学号
	        printf("请输入要查找的学号：");
	        scanf("%d", &number);
	        //查找学号对应的成绩位置
	        while (number != student[i][0] && i < actual)
	        {
	            i++;
	        }
	        //判断是否有与之对应的学号
	        if (number == student[i][0])
	        {
	            //有则输出成绩
	            printf("学号为%d的成绩为：%d\n",number,student[i][1]);
	        }
	        else
	        {
	            //没有则输出查无此人
	            printf("查无此人\n");
	        }
	        //判断是否继续
	        getchar();
	        printf("还要继续么(y/n)：");
	        char c = getchar();
	        if (c == 'y' || c == 'Y')
	        {
	            system("cls");
	        }
	        else if (c == 'n' || c == 'N')
	        {
	        	system("cls");
	            break;
	        }
	        else
	        {
	            printf("输入错误，即将退出查找系统\n");
	            sleep(5);
	            system("cls");
	            break;
	
	        }
		}

    }

}
//打印成绩表
void print()
{
	if(actual==0)
	{
		printf("无学生成绩信息\n");
		system("pause");
	 } 
    else
    {
    	//用for循环依次打印出实际人数的学号成绩对应表
	    int i,j;
	    printf("成绩表如下（学号-成绩）：\n");
	    for(i=0;i<actual;i++)
	    {
	        printf("%4d%4d\n",student[i][0],student[i][1]);
	    }
	    float average=0.0;
	    float sum=0.0;
	    for(j=0;j<actual;j++)
	    {
	        sum=sum+student[j][1];
	    }
	    
	    average=sum/actual;
	    printf("全班的平均成绩为%2.2f\n",average);
	    system("pause");
	}
}

//冒泡排序
void maopao()
{
    int temp=0,num=0,i,j;                               //初始化存放成绩和学号的临时变量
    for(i=0;i<actual-1;i++)                     //遍历实际人数-1次
    {
        for(j=0;j<actual-i-1;j++)               //遍历实际人数减-1-1次；2人一组对比所以比要再减1次
        {
            if(temparr[j][1]>temparr[j+1][1])       //判断前后两数的大小，如果前面的成绩比后面成绩大
            {
                //交换成绩
                temp=temparr[j][1];
                temparr[j][1]= temparr[j+1][1];
                temparr[j+1][1]=temp;
                //交换学号
                num=temparr[j][0];
                temparr[j][0]=temparr[j+1][0];
                temparr[j+1][0]=num;
            }
        }
    }
	                      
}
//选择排序
void choice()
{
    int a=0,b=0,min,i,j;
    for(i=0;i<actual-1;i++)
    {
        min=i;                          //假设最小值位置
        for(j=i+1;j<actual;j++)     //开始遍历找所有的值对比
        {
            if(temparr[j][1]<temparr[min][1])       //如果后面的数小于最小值，则记录最小值的位置
            {
                min=j;
            }
        }
        if(min!=i)                      //如果最小值不等于最开始的位置，则
        {
            //交换学号
            b=temparr[min][0];
            temparr[min][0]=temparr[i][0];
            temparr[i][0]=b;
            //交换成绩
            a=temparr[min][1];
            temparr[min][1]=temparr[i][1];
            temparr[i][1]=a;

        }
    }
	                          //打印成绩
}
//插入排序小甲鱼版 
void insert()
{

    int i,j;
    int temp,id;
    for(i=1;i<actual;i++)
    {
        if(temparr[i][1]<temparr[i-1][1])           //如果后面的数小于前面的数
        {
            temp=temparr[i][1];                     //保存后面的数到temp
            id=temparr[i][0];                       //对应的学号保存到ou
            for(j=i-1;temparr[j][1]>temp;j--)       //开始将前面到数移位，当前面的数大于temp就开始循环，直到有比temp大的数和最前面则跳出循环
            {
                temparr[j+1][1]=temparr[j][1];      //将成绩向后移
                temparr[j+1][0]=temparr[j][0];      //学号向后移
                if(j<0)                             //当最小到数移动到第一位后
                {
                    break;                          //退出循环
                }
            }
            temparr[j+1][1]=temp;                     //将temp的值插入到比temp大的数的前面
            temparr[j+1][0]=id;                       //将对应的学号插入到对应的位置

        }
    }

}
//插入排序教师版 -简洁易懂 
void insert_2()
{
	int i,j,temp;
	for(i=1;i<actual;i++)
	{
		for(j=i;j>0;j--)
		{
			if(temparr[j-1][1]>temparr[j][1])
			{
				temp=temparr[j-1][1];
				temparr[j-1][1]=temparr[j][1];
				temparr[j][1]=temp;
				temp=temparr[j-1][0];
				temparr[j-1][0]=temparr[j][0];
				temparr[j][0]=temp;
			}
		}
	}
}
//归并排序
//分治  递归
void merge_split(){
    split(temparr,1,actual);
    
}
//将数组用递归拆成单个元素
void split(int arr[][2],int p,int q)
{
    int mid;
    //确保拆成单个元素
    if(arr== NULL ||p>q||p==q)
    {
        return ;
    }
    mid=(p+q)/2;
    split(arr,p,mid);
    split(arr,mid+1,q);
    merge(arr,p,mid,q);
}
//排序归并在一起
void merge(int arr[][2],int p,int mid,int q){
    int i,j,k;
    int L,R;
    //定义临时存放左右数组的数组
    int LL[max][2];
    int RR[max][2];
    //定义左右数组长度
    L=mid-p+1;
    R=q-mid;
    //将左边数组存放到临时数组
    for(i=0;i<L;i++)
    {
        LL[i][1]=arr[p-1+i][1];
        LL[i][0]=arr[p-1+i][0];
    }
    //将右边数组存放到临时数组
    for(i=0;i<R;i++)
    {
        RR[i][1]=arr[mid+i][1];
        RR[i][0]=arr[mid+i][0];
    }
    i=0;
    j=0;
    for(k=p;k<=q;k++)
    {
        //当LL与RR没有元素时，放入原来数组
        if(i==L)
        {
            arr[k-1][1]=RR[j][1];
            arr[k-1][0]=RR[j][0];
            j++;

        }
        else if(j==R)
        {
            arr[k-1][1]=LL[i][1];
            arr[k-1][0]=LL[i][0];
            i++;
        }
        else
        {
            //当LL与RR还有元素时，放入原来数组
            if(LL[i][1]<RR[j][1])
            {
                arr[k-1][1]=LL[i][1];
                arr[k-1][0]=LL[i][0];
                i++;
            }
            else
            {
                arr[k-1][1]=RR[j][1];
                arr[k-1][0]=RR[j][0];
                j++;
            }
        }
    }
}
//排序算法目录
int short_1()
{
        int i;
        printf("===============\n");
        printf("1、冒泡排序\n");
        printf("2、选择排序\n");
        printf("3、插入排序\n");
        printf("4、归并排序\n");
        printf("===============\n");
        printf("请输入要使用的排序方法：");
        scanf("%d",&i);
        switch (i) {
            case 1: system("cls");copy();maopao();x_2();system("cls");break;
            case 2: system("cls");copy();choice();x_2();system("cls");break;
            case 3: system("cls");copy();insert_2();x_2();system("cls");break;
            case 4: system("cls");copy();merge_split();x_2();system("cls");break;
            default: system("cls");printf("输入错误，请重新输入\n");break;

        }

}

void aes()
{
	int t=0,i;                               //初始化存放成绩和学号的临时变量
    for(i=0;i<actual/2;i++)                     //遍历实际人数-1次
    {
    	t = temparr[i][1];
    	temparr[i][1] = temparr[actual-1-i][1];
    	temparr[actual-1-i][1] = t;

    }
 }
void copy()
{
	int i;
	for(i=0;i<actual;i++)
	{
		temparr[i][0]=student[i][0];
		temparr[i][1]=student[i][1];
	}
 }
void  paste()
{
	int i;
	for(i=0;i<actual;i++)
	{
		student[i][0]=temparr[i][0];
		student[i][1]=temparr[i][1];
	}
}
void max_score()
{
	copy();
	merge_split();
	printf("最高成绩信息如下：\n");
	printf("%4d%4d\n",temparr[actual-1][0],temparr[actual-1][1]);
	system("pause");
 } 
int x_2()
{
	getchar();
	printf("请选择升序还是降序排序（升:y/降:n):");
	char s=getchar();
	switch (s)
	{
		case 'y': system("cls");; break;
		case 'Y': system("cls");; break;
		case 'n': system("cls");aes();break;
		case 'N': system("cls");aes();break;
		default:
			system("cls");printf("输入错误\n");return 0;break;
	}
	if(actual==0)
	{
		printf("无学生成绩信息\n");
		system("pause");
	
	}
	else
	{
		printf("排序后的学生成绩表如下：\n");
		int i;
		for(i=0;i<actual;i++)
		{
			printf("%4d%4d\n",temparr[i][0],temparr[i][1]);
		}
		getchar();
		printf("是否将排序过后的数据做为新表（y/n）：");
	    char c = getchar();
	    if (c == 'y' || c == 'Y')
	    {
	    	paste();
	        system("cls");
	    }
	    else if (c == 'n' || c == 'N')
	    {
	    	system("cls");
	    }
	    else
	    {
	        printf("输入错误，即将退出查找系统\n");
	        system("cls");
	
	    }
		
	}
	
}
//程序入口
int main() 
{
	system("title 学生成绩管理系统");
	while (1)
    {
        int i;
        menu();
        printf("请输入要选择的功能：");
        scanf("%d",&i);
        switch (i)
        {
            case 1: system("cls");add();system("cls");break;
            case 2: system("cls");delete();system("cls");break;
            case 3: system("cls");alter();system("cls");break;
            case 4: system("cls");find();system("cls");break;
            case 5: system("cls");print();system("cls");break;
            case 6: system("cls");short_1();system("cls");break;
            case 7: system("cls");max_score();system("cls");break;
            case 0: return 0;
            default: system("cls");printf("输入错误，请重新输入\n");break;
        }
    }
    
}
