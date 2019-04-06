#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<io.h>
#include<stdio.h>
#include <windows.h>
#define  M 747158912
using namespace std;
//1092958934
class txl;//通讯录    51 
class yonghu;//用户     112 
string adddat(string );//加上地址    145 
void zcxz();//注册须知=    150 
void foundyonghu(yonghu &);//注册    167 
void dengluyonghu(yonghu &);//登录     224 
void lzh();//显示李振华    273 
void zhucaidan(yonghu &);//主菜单    308 
void yhcz(yonghu &);//用户操作     342
void txlcz(yonghu &);//通讯录操作    381 
void cktxl(yonghu &);//查案通讯录    426 
void xgtxl(yonghu &);//修改通讯录    471 
void gairen(yonghu &);//修改个人信息    522 
void tch();//退出    604
void zx(yonghu &);//注销     610 
void xgmm(yonghu &);//修改密码     619 
void jiaren(yonghu &);//加人    685
void ckqb(yonghu &);//查看全部     751
txl *creat(yonghu &);//创造动态类    773
void shanren(yonghu &);//删人    818
txl *search(yonghu &,txl *);//查看个人     857
txl *jieguo(int ,txl *,txl *,yonghu &);//搜索结果    939
txl *searchname(yonghu &,txl *);//名字搜索    991
txl *searchaddress(yonghu &,txl *);//地址搜索    1025
txl *searchmobile(yonghu &,txl *);//手机搜索    1059
txl *searchqq(yonghu &,txl *);//qq搜索    1093
txl *searchweibo(yonghu &,txl *);//微博搜索    1127
txl *searchrenren(yonghu &,txl *);//人人搜索    1161
txl *searchemail(yonghu &,txl *);//email搜索    1095
txl *searchothers(yonghu &,txl *);//备注搜索    1229
void jieguo(yonghu &,txl *,txl *);//修改结果    1263
void gainame(yonghu &,txl *,txl *);//修改名字    1309
void gaiaddress(yonghu &,txl *,txl *);//修改地址 1319
void gaimobile(yonghu &,txl *,txl *);//修改手机   1329
void gaiqq(yonghu &,txl *,txl *);//修改qq       1339
void gaiweibo(yonghu &,txl *,txl *);//修改微博   1349 
void gairenren(yonghu &,txl *,txl *);//修改人人   1359
void gaiemail(yonghu &,txl *,txl *);//修改email   1369
void gaiothers(yonghu &,txl *,txl *);//修改备注  1379

class txl//通讯录ALL
{
	char *name;
	char *address;
	char *mobile;
	char *qq;
	char *weibo;
	char *renren;
	char *email;
	char *others;
	txl *next;
	txl *bfor; 
	public:
		friend class yonghu;//其实没用，做个样子看看 
		friend void yhcz(class yonghu &);
		friend void cktxl(yonghu &);
		friend void xgtxl( yonghu &);
		friend void gairen(yonghu &);
		friend void jiaren(yonghu &);
		friend txl *creat(yonghu &);
		friend void ckqb(yonghu &);
		friend void shanren(yonghu &);
		friend txl *search(yonghu &,txl *c);
		friend txl *searchname(yonghu &,txl *c);
		friend txl *searchaddress(yonghu &,txl *c); 
        friend txl *searchmobile(yonghu &,txl *c); 
        friend txl *searchqq(yonghu &,txl *c); 
        friend txl *searchweibo(yonghu &,txl *c); 
        friend txl *searchrenren(yonghu &,txl *c); 
        friend txl *searchemail(yonghu &,txl *c); 
        friend txl *searchothers(yonghu &,txl *c); 
        friend txl *jieguo(int ,txl *,txl *,yonghu &);
        friend void gainame(yonghu &,txl *,txl *);
        friend void gaiaddress(yonghu &,txl *,txl *);
        friend void gaimobile(yonghu &,txl *,txl *);
        friend void gaiqq(yonghu &,txl *,txl *);
        friend void gaiweibo(yonghu &,txl *,txl *);
        friend void gairenren(yonghu &,txl *,txl *);
        friend void gaiemail(yonghu &,txl *,txl *);
        friend void gaiothers(yonghu &,txl *,txl *);
        friend void jieguo(yonghu &,txl *,txl *);
		txl()
		{			
		}
		void setname(char a[])
		{
			strcpy(name,a);
		}
		void setaddress(char &a)
		{
			*address=a;
		}
		void setmobile(char *a)
		{
			mobile=a;
		}//其他的省略吧，反正也没用，有这三个告诉我怎么用就可以了 
		~txl()
		{
		}
};

class yonghu//用户ALL
{
	string mima;
	string name;
	public:
		yonghu()
		{
			name='\0';
			mima='\0';
		}
		friend void foundyonghu(yonghu &);
		friend void dengluyonghu(yonghu &);
		friend string adddat(string );
		friend void yhcz(yonghu &);
		friend void xgmm(yonghu &);
		friend void jiaren(yonghu &);
		friend void ckqb(yonghu &);
		friend txl *creat(yonghu &);
		friend void shanren(yonghu &);
		friend void jieguo(yonghu &,txl *,txl *);
		~yonghu()
		{
		}
};

string adddat(string a)//加上地址ALL
{
	return ("d:\\通讯录\\"+a); /*文件\\编程\\C++\\随手编的\\*/
} 

void zcxz()//注册须知ALL
{
	cout<<"首先嘛，感谢你的支持啦，这是我首次开发的应该算是比较大型的软件吧~~~~"<<endl;
	cout<<"然后就该注意了，下面是注册须知："<<endl;
	cout<<"1、输密码之类的注意回车、退格也会读进去的"<<endl;
	cout<<"2、用户名虽然没要求字母、数字、符号、中文之类的，但最好就是只由数字和字母组成吧"<<endl; 
	cout<<"3、用户名当然也不要太长啦"<<endl;
	cout<<"4、密码嘛，6位，这个字母、数字、符号、中文都不限，区分大小写哦~~~"<<endl;
	cout<<"5、请以回车键结束输入"<<endl;
	cout<<"6、不要改动生成的文件，以免造成数据错误"<<endl; 
	cout<<"7、注意选项时要关闭大写\n\a"<<endl; 
	cout<<"	******特别注意：在D盘新建一个名为“通讯录”的文件夹！！!!!\n"<<endl; 
	cout<<"看完之后，就开始我们的注册吧；"<<endl;
	getch();
	system("cls");  
}

void foundyonghu(yonghu &a)//注册ALL
{
	char b[6];
	string c;
	cout<<"如需返回主菜单，请输入已有账号"<<endl; 
	cout<<"用户名：";
	cin>>a.name;     
	fstream fs;
	fs.open(adddat(a.name).c_str());
    if(fs)
    {        
    	cerr<<"该用户已存在，请重新注册"<<endl;//存在0，不存在1 
		cout<<"现在正在退回主菜单。。。。。"<<endl; 
		getch();                                                              
		system("cls"); 
		zhucaidan(a); 
		return;     
    }//判断用户可不可用 
	fs.close();
	cout<<"密码(6位)：   ";
	for(int i=0;i<=5;i++)
	{
		b[i]=getch();
	    cout<<'*'; 
	    if(i==5) 
		    cout<<"\n";
	}
	a.mima=b;
	cout<<"再输一次密码：";
	for(int i=0;i<=5;i++)
	{
		b[i]=getch();
	    cout<<'*'; 
	    if(i==5) 
		    cout<<"\n";  
	}
	c=b;
	if(c==a.mima)
	{
		ofstream fout(adddat(a.name).c_str());
		fout<<a.mima<<endl;//写入文件 
		cout<<"成功注册！"<<endl; 
		cout<<"请按任意键回主菜单...."<<endl; 
		getch();
		system("cls"); 
		zhucaidan(a);
		fout.close();  
	} 
	else
	{
		cout<<"密码不一致，请重新注册"<<endl;
		getch();
		system("cls"); 
		zhucaidan(a);
	}
}

void dengluyonghu(yonghu &d)//登录/ALL
{
	string a,e;
	char c[6],b[6];
	cout<<"如需返回主菜单，请输入不存在的账号"<<endl; 
	cout<<"用户名：";
	cin>>a;
	d.name=a;
	fstream fs(adddat(a).c_str());
	if(access(adddat(a).c_str(),0))
	{
		cout<<"该用户不存在，请重新登录或注册新账号"<<endl;//存在0，不存在1  
		getch();
		system("cls"); 
		zhucaidan(d);
		exit(0);
	}
	fs.close();
	ifstream fin(adddat(a).c_str());//寻找并判断
	cout<<"密码：";
	for(int i=0;i<=5;i++)
	{
		b[i]=getch();
	    cout<<'*'; 
	    if(i==5) 
		    cout<<"\n";  
	}
	e=b;
	fin.get(c,7);
	d.mima=c;
	if(e!=d.mima)
	{
		cout<<"密码错误，请重新登录或注册新账号" <<endl;
		getch();
		system("cls"); 
		zhucaidan(d);
		exit(0);
	}//判断密码是否正确 
	else
	{
		cout<<"登录成功。。。。"<<endl;
		cout<<"请按任意键继续。。。"<<endl;
		getch();
		system("cls"); 
		yhcz(d);//用户操作 
	}
	fin.close(); 
}

void lzh()//显示李振华ALL
{
	cout<<"    *          *         ****************            *           *"<<endl;
	Sleep(100);
	cout<<"    *          *         **                        ****************"<<endl;
	Sleep(100);
	cout<<" *******     *****       ****************              *       *"<<endl;
	Sleep(100);
	cout<<"  * * *        * *       **                        ****************"<<endl;
	Sleep(100);
	cout<<" *  *  *       **        ****************                  *"<<endl;
	Sleep(100);
	cout<<"*   *   *      *         **    **      *           ****************"<<endl;
	Sleep(100);
	cout<<" ******       **         **    **     *               *    *    *"<<endl;
	Sleep(100);
	cout<<"      *      * *        **     ** *  *             ****************"<<endl;
	Sleep(100);
	cout<<"     *      *  *       **      **   *                  *   *  *"<<endl;
	Sleep(100);
	cout<<" *******   *   *      **       **  * *              ****************"<<endl;
	Sleep(100);
	cout<<"    *          *     **        **     *                    *"<<endl;
	Sleep(100);
	cout<<"  * *        * *    **         ** *    *                   *"<<endl;
	Sleep(100);
	cout<<"    *          *   **          **       *                  *"<<endl;
	Sleep(100);
	cout<<" \n               欢迎使用由华哥制造的通讯录"<<endl;
	Sleep(100);
	cout<<"   \n                   请按任意键进入"<<endl;
	getch(); 
	system("cls");
}

void zhucaidan(yonghu &b)//主菜单ALL
{                        
	char a;
	cout<<"登陆账号请按 1"<<endl;
	cout<<"创建用户请按 2"<<endl;
	cout<<"忘记密码请按 3"<<endl;
	cout<<"意见反馈请按 4"<<endl;
	cout<<"在线更新请按 5"<<endl;
	cout<<"退出程序请按 e"<<endl; 
	a=getch();
	system("cls");
	switch(a)
	{
		case '1':
		{
			dengluyonghu(b); 
			break;
		}
		case '2':
		{
			zcxz();
			foundyonghu(b);
			break;
		}
		case '3':
		{
			cout<<"请把D盘中的通讯录文件夹压缩,并发送至Q号"<<M<<"，等待华哥的在线服务~~~~"<<endl; 
			getch();
			system("cls");
			zhucaidan(b);
			break;
		}
		case '4':
		{
			cout<<"把你的意见发送至Q号"<<M<<"，华哥将为你尽力改善~~~~"<<endl; 
			getch();
			system("cls");
			zhucaidan(b);
			break;
		}
		case '5':
		{
			cout<<"你所用的版本为最新版~~~~"<<endl;  
			getch();
			system("cls");
			zhucaidan(b);
			break;
		}
		case 'e':
		{
			tch(); 
			break;
		}
		default:
		{
			cout<<"输入错误,请重新输入"<<endl;
		    zhucaidan(b);
		}
	} 
}
							
void yhcz(yonghu &a)//用户操作ALL
{                            
	char b;
	cout<<"通讯录选项请按   1"<<endl;
	cout<<"修改账号密码请按 2"<<endl;
	cout<<"退出登录请按     w"<<endl; 
	cout<<"退出程序请按     e"<<endl; 
	b=getch();
	system("cls");
	switch(b)
	{
		case '1':
		{
			txlcz(a);
			break;
		}
		case '2':
		{
			xgmm(a);
			break;
		}
		case 'w':
		{
			zx(a);
			break;
		}
		case 'e':
		{
			tch();
			break;
		}
		default:
		{
		    cout<<"输入错误,请重新输入"<<endl;
		    yhcz(a);
		}
	}
}
							
void txlcz(yonghu &a)//通讯录操作 ALL
{
	char b;
	cout<<"查看通讯录请按   1"<<endl;
	cout<<"修改通讯录请按   2"<<endl;
	cout<<"返回上一级请按   q"<<endl;
	cout<<"退出登录请按     w"<<endl; 
	cout<<"退出程序请按     e"<<endl; 
	b=getch();
	system("cls");
	switch(b)
	{
		case '1':
		{
			cktxl(a);
			break;
		}
		case '2':
		{
			xgtxl(a);
			break;
		}
		case 'q':
		{
			yhcz(a);
			break;
		}
		case 'w':
		{
			zx(a);
			break;
		}
		case 'e':
		{
			tch();
			break;
		}
		default:
		{
		    cout<<"输入错误,请重新输入"<<endl;
		    txlcz(a);
		}
	}
} 

void cktxl(yonghu &a)//查看通讯录 ALL
{
	char b;
	cout<<"查看全部请按     1"<<endl;
	cout<<"查询个人请按     2(由于技术问题，查询完毕后将退出软件)"<<endl;
	cout<<"返回上一级请按   q"<<endl;
	cout<<"退出登录请按     w"<<endl; 
	cout<<"退出程序请按     e"<<endl; 
	b=getch();
	system("cls");
	switch(b)
	{
		case '1':
		{
			ckqb(a);
			break;
		}
		case '2':
		{
			search(a,creat(a));
			break;
		}
		case 'q':
		{
			txlcz(a);
			break;
		}
		case 'w':
		{
			zx(a); 
			break;
		}
		case 'e':
		{
			tch();
			break;
		}
		default:
		{
		    cout<<"输入错误,请重新输入"<<endl;
		    cktxl(a);
		}
	}
}

void xgtxl(yonghu &a)//修改通讯录 ALL
{
	char b;
	cout<<"加人请按         1"<<endl;
	cout<<"删人请按         2"<<endl;
	cout<<"改人请按         3"<<endl;
	cout<<"返回上一级请按   q"<<endl;
	cout<<"退出登录请按     w"<<endl; 
	cout<<"退出程序请按     e"<<endl; 
	b=getch();
	system("cls");
	switch(b)
	{
		case '1':
		{
			jiaren(a);
			break;
		}
		case '2':
		{
			shanren(a);
			break;
		}
		case '3':
		{
			gairen(a); 
			break;
		}
		case 'q':
		{
			txlcz(a);
			break;
		}
		case 'w':
		{
			zx(a);
			break;
		}
		case 'e':
		{
			tch();
			break;
		}
		default:
		{
		    cout<<"输入错误,请重新输入"<<endl;
		    xgtxl(a);
		}
	}
}
 
void gairen(yonghu &a)//修改个人信息 ALL
{
	char b;
	txl *c,*d;
	d=creat(a);
	cout<<"修改名字请按         1"<<endl;
	cout<<"修改地址请按         2"<<endl;
	cout<<"修改手机请按         3"<<endl;
	cout<<"修改qq请按           4"<<endl;
	cout<<"修改微博请按         5"<<endl;
	cout<<"修改人人请按         6"<<endl;
	cout<<"修改电子邮箱请按     7"<<endl;
	cout<<"修改备注请按         8"<<endl;
	cout<<"返回上一级请按       q"<<endl;
	cout<<"退出登录请按         w"<<endl; 
	cout<<"退出程序请按         e"<<endl; 
	b=getch();
	system("cls");
	switch(b)
	{
		case '1':
		{
			gainame(a,search(a,d),d);
			break;
		}
		case '2':
		{
			gaiaddress(a,search(a,d),d);
			break;
		}
		case '3':
		{
			gaimobile(a,search(a,d),d);
			
			break;
		}
		case '4':
		{
			gaiqq(a,search(a,d),d);
			break;
		}
		case '5':
		{
			gaiweibo(a,search(a,d),d);
			break;
		}
		case '6':
		{
			gairenren(a,search(a,d),d);
			break;
		}
		case '7':
		{
			 gaiemail(a,search(a,d),d);
			break;
		}
		case '8':
		{
			 gaiothers(a,search(a,d),d);
			break;
		}
		case 'q':
		{
			xgtxl(a);
			break;
		}
		case 'w':
		{
			zx(a);
			break;
		}
		case 'e':
		{
			tch();
			break;
		}
		default:
		{
		    cout<<"输入错误,请重新输入"<<endl;
		    gairen(a);
		}
	}
}

void tch()//退出程序 ALL
{
	cout<<"欢迎再次使用华哥的新编软件~~~~~"<<endl;
	system("pause >-nul"); 
} 

void zx(yonghu &a)//注销用户 ALL
{
	cout<<"正在注销。。。。。"<<endl;
	cout<<"请按任意键继续......"<<endl;
	getch();
	system("cls");
	zhucaidan(a); 
}

void xgmm(yonghu &a)//修改密码 ALL
{
	char b[6];
	string c;     
	ifstream fin;
	fin.open(adddat(a.name).c_str());
	cout<<"旧密码(6位)：   ";
	for(int i=0;i<=5;i++)
	{
		b[i]=getch();
	    cout<<'*'; 
	    if(i==5) 
		    cout<<"\n";  
	}
	c=b;
	fin.get(b,7);
	a.mima=b;
	if(c!=a.mima)
	{
		cout<<"密码错误,请重新输入" <<endl;
		getch();
		system("cls"); 
		yhcz(a);
		exit(0);
	}//判断密码是否正确 
	fin.close();
	cout<<"新密码：        "; 
	for(int i=0;i<=5;i++)
	{
		b[i]=getch();
	    cout<<'*'; 
	    if(i==5) 
		    cout<<"\n";
	}
	a.mima=b;
	cout<<"再输一次新密码：";
	for(int i=0;i<=5;i++)
	{
		b[i]=getch();
	    cout<<'*'; 
	    if(i==5) 
		    cout<<"\n";  
	}
	c=b;
	if(c==a.mima)
	{
		fstream fout2(adddat(a.name).c_str());
		fout2.seekp(ios::beg);
		fout2<<a.mima<<endl;//写入文件 
		cout<<"成功修改密码！"<<endl; 
		cout<<"请按任意键回主菜单重新登录...."<<endl; 
		getch();
		system("cls"); 
		zhucaidan(a);
		fout2.close();  
	} 
	else
	{
		cout<<"密码不一致，请重输入密码"<<endl;
		getch();
		system("cls"); 
		yhcz(a);
		exit(0); 
	}
}

void jiaren(yonghu &a)//加人   ALL
{
	txl b;
	char c;
	ofstream fs(adddat(a.name).c_str(),ios::app);
	b.name=(char*)malloc(sizeof(char)*100);
    b.address=(char*)malloc(sizeof(char)*1000);
    b.mobile=(char*)malloc(sizeof(char)*100);
    b.qq=(char*)malloc(sizeof(char)*100);
    b.weibo=(char*)malloc(sizeof(char)*100);
    b.renren=(char*)malloc(sizeof(char)*100);
    b.email=(char*)malloc(sizeof(char)*100);
    b.others=(char*)malloc(sizeof(char)*1000);
	cout<<"姓名：";
	cin>>b.name;
	cout<<"地址：";
	cin>>b.address;
	cout<<"手机：";
	cin>>b.mobile;
	cout<<"qq：  ";
	cin>>b.qq;
	cout<<"微博：";
	cin>>b.weibo;
	cout<<"人人：";
	cin>>b.renren;
	cout<<"email:";
	cin>>b.email;
	cout<<"备注：";
	cin>>b.others; 
	system("cls");
	cout<<"你输入的 "<<b.name<<" 信息为："<<endl;
	cout<<"姓名："<<b.name<<'\n'<<"地址："<<b.address<<'\n'<<"手机："<<b.mobile<<'\n'<<"qq：  "<<b.qq<<'\n'
	    <<"微博："<<b.weibo<<'\n'<<"人人："<<b.renren<<'\n'<<"email:"<<b.email<<'\n'<<"备注："<<b.others<<endl; 
	cout<<"确定保存？"<<endl;
	cout<<"y       n"<<endl;
	c=getch();
	switch(c)
	{
		case 'y':
		{
			fs<<b.name<<'\t'<<b.address<<'\t'<<b.mobile<<'\t'<<b.qq<<'\t'<<b.weibo<<'\t'
			  <<b.renren<<'\t'<<b.email<<'\t'<<b.others<<endl;
		    cout<<"添加成功！"<<endl;
		    cout<<"请按任意键继续。。。。"<<endl;
		    getch();
		    system("cls"); 
		    xgtxl(a);
		    break;
		}
		case 'n':
		{
			system("cls");
		    cout<<"请重新输入"<<endl; 
		    jiaren(a);
		    break;
		}
		default:
		{
			system("cls");
		    cout<<"输入错误，请关闭大写锁定"<<endl; 
		    jiaren(a);
		}
	}
	fs.close();
} 

void ckqb(yonghu &a)//查看全部 ALL
{
	 txl *p;
     p=creat(a);
     while(p!=NULL)
     {
         printf("%s\n",p->name);
         printf("地址： %s\n", p->address);
		 printf("手机： %s\n",p->mobile);
		 printf("qq ：  %s\n", p->qq);
		 printf("微博 ：%s\n",p->weibo);
		 printf("人人 ：%s\n",p->renren);
		 printf("email：%s\n",p->email);
		 printf("备注 ：%s\n\n",p->others);
         p=p->next;
     }
	cout<<"\n按任意键回上一步"<<endl;
	getch();
	system("cls");
	cktxl(a); 
}

txl *creat(yonghu &a)//创造动态类  all
{
	txl *head;
    txl *p1,*p2;                    
    FILE*fp;
    if((fp=fopen(adddat(a.name).c_str(),"r"))==NULL)
    {
        printf("不能打开%s",adddat(a.name).c_str());
        getch();
	    system("cls");
	    cktxl(a); 
    } 
    fseek(fp,8,0);
    head=NULL;
    p1=p2=(txl*)malloc(sizeof(txl));
    while(!feof(fp))
    {
        if(head==NULL)
        {
        	head=p1;
        	p1->bfor=NULL;
        }
        else 
        {
        	p2->next=p1;
        	p1->bfor=NULL;
        }
        p2=p1;
        p1=(txl*)malloc(sizeof(txl));
        p1->name=(char*)malloc(sizeof(char)*100);
        p1->address=(char*)malloc(sizeof(char)*1000);
        p1->mobile=(char*)malloc(sizeof(char)*100);
        p1->qq=(char*)malloc(sizeof(char)*100);
        p1->weibo=(char*)malloc(sizeof(char)*100);
        p1->renren=(char*)malloc(sizeof(char)*100);
        p1->email=(char*)malloc(sizeof(char)*1000);
        p1->others=(char*)malloc(sizeof(char)*1000);
        fscanf(fp,"%s%s%s%s%s%s%s%s",p1->name, p1->address,p1->mobile,p1->qq,p1->weibo,p1->renren,p1->email,p1->others);
    }
    p2->next=NULL;
    fclose(fp);
    return head->next;//点解要甘样?
}

void shanren(yonghu &a)//删人  ALL
{
	txl *p1,*p2;
	char b;
	p1=creat(a); 
	p2=search(a,p1);
	cout<<"是否删除："<<endl;
	cout<<p2->name<<'\n'<<"地址："<<p2->address<<'\n'<<"手机："<<p2->mobile<<'\n'<<"qq：  "<<p2->qq<<'\n'
	           <<"微博："<<p2->weibo<<'\n'<<"人人："<<p2->renren<<'\n'<<"email:"<<p2->email<<'\n'<<"备注："<<p2->others<<endl;
	cout<<"是否删除?"<<endl; 
	cout<<"y        n"<<endl; 
	b=getch();
	switch(b)
	{
		case 'y':
			{
				txl *head=NULL;
				while(p1!=NULL)
				{
				    if(head==NULL)
				    {
				    	head=p1;
				    }
				    else
				    {
				    	p2->next=p1;
				    }
				    p2=p1;
				    p1=p1->next;
				    if(p1->bfor!=NULL)
				    {
				    	p1->next=p1->next->next;
				    	break;
				    }
				}
				ofstream fs(adddat(a.name).c_str());
	            fs<<a.mima<<'\n';
	            p1=head;
				while(p1!=NULL)
				{
					fs<<p1->name<<'\t'<<p1->address<<'\t'<<p1->mobile<<'\t'<<p1->qq<<'\t'<<p1->weibo<<'\t'
			          <<p1->renren<<'\t'<<p1->email<<'\t'<<p1->others<<endl;
			        p1=p1->next;
				}
				fs.close();
				cout<<"删除成功！"<<endl;
		        cout<<"请按任意键继续。。。。"<<endl;
		        getch();
		        system("cls"); 
		        xgtxl(a);
				break;
			}
		case 'n':
			{
				cout<<"请重新输入："<<endl;
				getch();
				system("cls"); 
				shanren(a);
				break;
			}
			default:
				{
					cout<<"输入错误，请关闭大写！！"<<endl;
					getch();
			    	system("cls");
					shanren(a); 
				}
	}
	
}

txl *search(yonghu &a,txl *c)//查看个人    ALL
{
    char b;
    printf("查找方式：\n");
    cout<<"通过 名字  寻找请按         1"<<endl;
	cout<<"通过 地址  寻找请按         2"<<endl;
	cout<<"通过 手机  寻找请按         3"<<endl;
	cout<<"通过 qq    寻找请按         4"<<endl;
	cout<<"通过 微博  寻找请按         5"<<endl;
	cout<<"通过 人人  寻找请按         6"<<endl;
	cout<<"通过 email 寻找请按         7"<<endl;
	cout<<"通过 备注  寻找请按         8"<<endl;
	cout<<"返回上一级请按              q"<<endl;
	cout<<"退出登录请按                w"<<endl; 
	cout<<"退出程序请按                e"<<endl; 
	b=getch();
	system("cls");
	switch(b)
	{
		case '1':
		{
			return searchname(a,c); 
			break;
		}
		case '2':
		{
			return searchaddress(a,c); 
			break;
		}
		case '3':
		{
			return searchmobile(a,c); 
			break;
		}
		case '4':
		{
			return searchqq(a,c); 
			break;
		}
		case '5':
		{
			return searchweibo(a,c); 
			break;
		}
		case '6':
		{
			return searchrenren(a,c); 
			break;
		}
		case '7':
		{
			 return searchemail(a,c); 
			break;
		}
		case '8':
		{
			return searchothers(a,c);  
			break;
		}
		case 'q':
		{
			cktxl(a);
			break;
		}
		case 'w':
		{
			zx(a);
			break;
		}
		case 'e':
		{
			tch();
			break;
		}
		default:
		{
		    cout<<"输入错误,请重新输入"<<endl;
		    return search(a,c);
		}
	}
} 

txl *jieguo(int n,txl *p1,txl *head,yonghu &a)//搜索结果   ALL
{
	cout<<"共搜索到"<<n<<"个结果\n"<<endl;
	if(n==0)
   {
   	    cout<<"没有找到该人"<<endl;
		cout<<"按任意键返回"<<endl;
		getch();
		system("cls") ;
		return search(a,creat(a));
   }
   else
   {
   	   p1=head;
   	   int i=1;
       while(p1!=NULL)
       {
           cout<<"第 "<< i<<" 个结果为:"<<endl; 
		   cout<<p1->name<<'\n'<<"地址："<<p1->address<<'\n'<<"手机："<<p1->mobile<<'\n'<<"qq：  "<<p1->qq<<'\n'
	           <<"微博："<<p1->weibo<<'\n'<<"人人："<<p1->renren<<'\n'<<"email:"<<p1->email<<'\n'<<"备注："<<p1->others<<'\n'<<endl; 
	       p1=p1->bfor; 
		   i++;   
       }
       if(n!=1)
       {
           cout<<"你所需要的结果为:（输入标号）"<<endl; 
           int x;
           cin>>x;
	        if(cin.fail()||x<1||x>n)
	        {
	    	    cin.clear();
    	    	cin.ignore();
	    		cout<<"输入错误，请重新输入"<<endl;
	        	cin>>x;
	        }
	        txl *p2;
	        p2=p1=head;
	        for(int d=1;d<x;d++) 
	        {
	        	p2=p1;
				p1=p1->bfor;
				p2->bfor=NULL;
	        }
	        head=p1;
	        cout<<"\n你所选的人为："<<endl; 
	        cout<<p1->name<<'\n'<<"地址："<<p1->address<<'\n'<<"手机："<<p1->mobile<<'\n'<<"qq：  "<<p1->qq<<'\n'
	           <<"微博："<<p1->weibo<<'\n'<<"人人："<<p1->renren<<'\n'<<"email:"<<p1->email<<'\n'<<"备注："<<p1->others<<'\n'<<endl; 
	   }
	   cout<<"\n请按任意键继续。。。"<<endl;
	   getch();
	   system("cls"); 
       return head;
   }
} 

txl *searchname(yonghu &a,txl *c)//名字搜索ALL
{
	txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("输入你想查询的名字：");
    num=(char*)malloc(sizeof(char)*1000);
    scanf("%s",num);
    system("cls");
    head=NULL;
    p1=p2=(txl*)malloc(sizeof(txl));
    do
    {
        if(strcmp(c->name,num)==0)
        {
            if(head==NULL)
            {
            	head=c;
            }
            else
            {
            	p2->bfor=c;
            }
            p2=c;
            n++;
        }
	   c=c->next;
   }
   while(c!=NULL);
   free(num);
   p2->bfor=NULL;
   return  jieguo(n,c,head,a);
}

txl *searchaddress(yonghu &a,txl *c)//地址搜索ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("输入你想查询的地址：");
    num=(char*)malloc(sizeof(char)*1000);
    scanf("%s",num);
    system("cls");
    head=NULL;
    p1=p2=(txl*)malloc(sizeof(txl));
    do
    {
        if(strcmp(c->address,num)==0)
        {
            if(head==NULL)
            {
            	head=c;
            }
            else
            {
            	p2->bfor=c;
            }
            p2=c;
            n++;
        }
	   c=c->next;
   }
   while(c!=NULL);
   free(num);
   p2->bfor=NULL;
   return  jieguo(n,c,head,a);
}

txl *searchmobile(yonghu &a,txl *c)//手机搜索ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("输入你想查询的手机号码：");
    num=(char*)malloc(sizeof(char)*1000);
    scanf("%s",num);
    system("cls");
    head=NULL;
    p1=p2=(txl*)malloc(sizeof(txl));
    do
    {
        if(strcmp(c->mobile,num)==0)
        {
            if(head==NULL)
            {
            	head=c;
            }
            else
            {
            	p2->bfor=c;
            }
            p2=c;
            n++;
        }
	   c=c->next;
   }
   while(c!=NULL);
   free(num);
   p2->bfor=NULL;
   return  jieguo(n,c,head,a);
}

txl *searchqq(yonghu &a,txl *c)//qq搜索ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("输入你想查询的qq：");
    num=(char*)malloc(sizeof(char)*1000);
    scanf("%s",num);
    system("cls");
    head=NULL;
    p1=p2=(txl*)malloc(sizeof(txl));
    do
    {
        if(strcmp(c->qq,num)==0)
        {
            if(head==NULL)
            {
            	head=c;
            }
            else
            {
            	p2->bfor=c;
            }
            p2=c;
            n++;
        }
	   c=c->next;
   }
   while(c!=NULL);
   free(num);
   p2->bfor=NULL;
   return  jieguo(n,c,head,a);
}

txl *searchweibo(yonghu &a,txl *c)//微博搜索ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("输入你想查询的微博：");
    num=(char*)malloc(sizeof(char)*1000);
    scanf("%s",num);
    system("cls");
    head=NULL;
    p1=p2=(txl*)malloc(sizeof(txl));
    do
    {
        if(strcmp(c->weibo,num)==0)
        {
            if(head==NULL)
            {
            	head=c;
            }
            else
            {
            	p2->bfor=c;
            }
            p2=c;
            n++;
        }
	   c=c->next;
   }
   while(c!=NULL);
   free(num);
   p2->bfor=NULL;
   return  jieguo(n,c,head,a);
}

txl *searchrenren(yonghu &a,txl *c)//人人搜索ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("输入你想查询的renren：");
    num=(char*)malloc(sizeof(char)*1000);
    scanf("%s",num);
    system("cls");
    head=NULL;
    p1=p2=(txl*)malloc(sizeof(txl));
    do
    {
        if(strcmp(c->renren,num)==0)
        {
            if(head==NULL)
            {
            	head=c;
            }
            else
            {
            	p2->bfor=c;
            }
            p2=c;
            n++;
        }
	   c=c->next;
   }
   while(c!=NULL);
   free(num);
   p2->bfor=NULL;
   return  jieguo(n,c,head,a);
}

txl *searchemail(yonghu &a,txl *c)//email搜索ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("输入你想查询的email：");
    num=(char*)malloc(sizeof(char)*1000);
    scanf("%s",num);
    system("cls");
    head=NULL;
    p1=p2=(txl*)malloc(sizeof(txl));
    do
    {
        if(strcmp(c->email,num)==0)
        {
            if(head==NULL)
            {
            	head=c;
            }
            else
            {
            	p2->bfor=c;
            }
            p2=c;
            n++;
        }
	   c=c->next;
   }
   while(c!=NULL);
   free(num);
   p2->bfor=NULL;
   return  jieguo(n,c,head,a);
}

txl *searchothers(yonghu &a,txl *c)//备注搜索ALL
{
    txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("输入你想查询的备注：");
    num=(char*)malloc(sizeof(char)*1000);
    scanf("%s",num);
    system("cls");
    head=NULL;
    p1=p2=(txl*)malloc(sizeof(txl));
    do
    {
        if(strcmp(c->others,num)==0)
        {
            if(head==NULL)
            {
            	head=c;
            }
            else
            {
            	p2->bfor=c;
            }
            p2=c;
            n++;
        }
	   c=c->next;
   }
   while(c!=NULL);
   free(num);
   p2->bfor=NULL;
   return  jieguo(n,c,head,a);
}

void jieguo(yonghu &a,txl *b,txl *d)//修改结果 ALL
{
	char c;
	cout<<"\n改后信息:"<<endl; 
	cout<<"姓名："<<b->name<<'\n'<<"地址："<<b->address<<'\n'<<"手机："<<b->mobile<<'\n'<<"qq：  "<<b->qq<<'\n'
	    <<"微博："<<b->weibo<<'\n'<<"人人："<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"备注："<<b->others<<endl;  
	    cout<<"确定保存？"<<endl;
	cout<<"y       n"<<endl;
	c=getch();
	switch(c)
	{
		case 'y':
		{
			txl *p;
			ofstream fs(adddat(a.name).c_str());
	        fs<<a.mima<<'\n';
	        p=d;
            while(p!=NULL)
            {
            	fs<<p->name<<'\t'<<p->address<<'\t'<<p->mobile<<'\t'<<p->qq<<'\t'<<p->weibo<<'\t'
			      <<p->renren<<'\t'<<p->email<<'\t'<<p->others<<endl;
			    p=p->next;
            }
		    cout<<"添加成功！"<<endl;
		    cout<<"请按任意键继续。。。。"<<endl;
		    fs.close();
		    getch();
		    system("cls"); 
		    xgtxl(a);
		    break;
		}
		case 'n':
		{
			system("cls");
		    cout<<"请重新输入"<<endl; 
		    gainame(a,b,creat(a));
		    break;
		}
		default:
		{
			system("cls");
		    cout<<"输入错误，请关闭大写锁定"<<endl; 
		    gainame(a,b,creat(a));
		}
	}
} 

void gainame(yonghu &a,txl *b,txl *d)//修改名字 ALL
{
	cout<<"原本信息:"<<endl;
	cout<<"姓名："<<b->name<<'\n'<<"地址："<<b->address<<'\n'<<"手机："<<b->mobile<<'\n'<<"qq：  "<<b->qq<<'\n'
	    <<"微博："<<b->weibo<<'\n'<<"人人："<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"备注："<<b->others<<endl;  
	cout<<"\n输入改后的名字:";
	cin>>b->name;
	jieguo(a,b,d);
}

void gaiaddress(yonghu &a,txl *b,txl *d)//修改地址 ALL
{
	cout<<"原本信息:"<<endl;
	cout<<"姓名："<<b->name<<'\n'<<"地址："<<b->address<<'\n'<<"手机："<<b->mobile<<'\n'<<"qq：  "<<b->qq<<'\n'
	    <<"微博："<<b->weibo<<'\n'<<"人人："<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"备注："<<b->others<<endl;  
	cout<<"\n输入改后的地址:";
	cin>>b->address;
	jieguo(a,b,d);
}

void gaimobile(yonghu &a,txl *b,txl *d)//修改手机 ALL
{
	cout<<"原本信息:"<<endl;
	cout<<"姓名："<<b->name<<'\n'<<"地址："<<b->address<<'\n'<<"手机："<<b->mobile<<'\n'<<"qq：  "<<b->qq<<'\n'
	    <<"微博："<<b->weibo<<'\n'<<"人人："<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"备注："<<b->others<<endl;  
	cout<<"\n输入改后的手机:";
	cin>>b->mobile;
	jieguo(a,b,d);
}

void gaiqq(yonghu &a,txl *b,txl *d)//修改qq ALL
{
	cout<<"原本信息:"<<endl;
	cout<<"姓名："<<b->name<<'\n'<<"地址："<<b->address<<'\n'<<"手机："<<b->mobile<<'\n'<<"qq：  "<<b->qq<<'\n'
	    <<"微博："<<b->weibo<<'\n'<<"人人："<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"备注："<<b->others<<endl;  
	cout<<"\n输入改后的qq:";
	cin>>b->qq;
	jieguo(a,b,d);
}

void gaiweibo(yonghu &a,txl *b,txl *d)//修改微博 ALL
{
	cout<<"原本信息:"<<endl;
	cout<<"姓名："<<b->name<<'\n'<<"地址："<<b->address<<'\n'<<"手机："<<b->mobile<<'\n'<<"qq：  "<<b->qq<<'\n'
	    <<"微博："<<b->weibo<<'\n'<<"人人："<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"备注："<<b->others<<endl;  
	cout<<"\n输入改后的微博:";
	cin>>b->weibo;
	jieguo(a,b,d);
}

void gairenren(yonghu &a,txl *b,txl *d)//修改人人 ALL
{
	cout<<"原本信息:"<<endl;
	cout<<"姓名："<<b->name<<'\n'<<"地址："<<b->address<<'\n'<<"手机："<<b->mobile<<'\n'<<"qq：  "<<b->qq<<'\n'
	    <<"微博："<<b->weibo<<'\n'<<"人人："<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"备注："<<b->others<<endl;  
	cout<<"\n输入改后的人人:";
	cin>>b->renren;
	jieguo(a,b,d);
}

void gaiemail(yonghu &a,txl *b,txl *d)//修改email ALL
{
	cout<<"原本信息:"<<endl;
	cout<<"姓名："<<b->name<<'\n'<<"地址："<<b->address<<'\n'<<"手机："<<b->mobile<<'\n'<<"qq：  "<<b->qq<<'\n'
	    <<"微博："<<b->weibo<<'\n'<<"人人："<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"备注："<<b->others<<endl;  
	cout<<"\n输入改后的电子邮件:";
	cin>>b->email;
	jieguo(a,b,d);
}

void gaiothers(yonghu &a,txl *b,txl *d)//修改备注 ALL
{
	cout<<"原本信息:"<<endl;
	cout<<"姓名："<<b->name<<'\n'<<"地址："<<b->address<<'\n'<<"手机："<<b->mobile<<'\n'<<"qq：  "<<b->qq<<'\n'
	    <<"微博："<<b->weibo<<'\n'<<"人人："<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"备注："<<b->others<<endl;  
	cout<<"\n输入改后的备注:";
	cin>>b->others;
	jieguo(a,b,d);
}

int main()
{
	system("title 你的华哥");
	yonghu yh;
	lzh(); 
	zhucaidan(yh);
	system("pause >nul");
	return 0;
} 
