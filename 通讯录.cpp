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
class txl;//ͨѶ¼    51 
class yonghu;//�û�     112 
string adddat(string );//���ϵ�ַ    145 
void zcxz();//ע����֪=    150 
void foundyonghu(yonghu &);//ע��    167 
void dengluyonghu(yonghu &);//��¼     224 
void lzh();//��ʾ����    273 
void zhucaidan(yonghu &);//���˵�    308 
void yhcz(yonghu &);//�û�����     342
void txlcz(yonghu &);//ͨѶ¼����    381 
void cktxl(yonghu &);//�鰸ͨѶ¼    426 
void xgtxl(yonghu &);//�޸�ͨѶ¼    471 
void gairen(yonghu &);//�޸ĸ�����Ϣ    522 
void tch();//�˳�    604
void zx(yonghu &);//ע��     610 
void xgmm(yonghu &);//�޸�����     619 
void jiaren(yonghu &);//����    685
void ckqb(yonghu &);//�鿴ȫ��     751
txl *creat(yonghu &);//���춯̬��    773
void shanren(yonghu &);//ɾ��    818
txl *search(yonghu &,txl *);//�鿴����     857
txl *jieguo(int ,txl *,txl *,yonghu &);//�������    939
txl *searchname(yonghu &,txl *);//��������    991
txl *searchaddress(yonghu &,txl *);//��ַ����    1025
txl *searchmobile(yonghu &,txl *);//�ֻ�����    1059
txl *searchqq(yonghu &,txl *);//qq����    1093
txl *searchweibo(yonghu &,txl *);//΢������    1127
txl *searchrenren(yonghu &,txl *);//��������    1161
txl *searchemail(yonghu &,txl *);//email����    1095
txl *searchothers(yonghu &,txl *);//��ע����    1229
void jieguo(yonghu &,txl *,txl *);//�޸Ľ��    1263
void gainame(yonghu &,txl *,txl *);//�޸�����    1309
void gaiaddress(yonghu &,txl *,txl *);//�޸ĵ�ַ 1319
void gaimobile(yonghu &,txl *,txl *);//�޸��ֻ�   1329
void gaiqq(yonghu &,txl *,txl *);//�޸�qq       1339
void gaiweibo(yonghu &,txl *,txl *);//�޸�΢��   1349 
void gairenren(yonghu &,txl *,txl *);//�޸�����   1359
void gaiemail(yonghu &,txl *,txl *);//�޸�email   1369
void gaiothers(yonghu &,txl *,txl *);//�޸ı�ע  1379

class txl//ͨѶ¼ALL
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
		friend class yonghu;//��ʵû�ã��������ӿ��� 
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
		}//������ʡ�԰ɣ�����Ҳû�ã�����������������ô�þͿ����� 
		~txl()
		{
		}
};

class yonghu//�û�ALL
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

string adddat(string a)//���ϵ�ַALL
{
	return ("d:\\ͨѶ¼\\"+a); /*�ļ�\\���\\C++\\���ֱ��\\*/
} 

void zcxz()//ע����֪ALL
{
	cout<<"�������л���֧�������������״ο�����Ӧ�����ǱȽϴ��͵������~~~~"<<endl;
	cout<<"Ȼ��͸�ע���ˣ�������ע����֪��"<<endl;
	cout<<"1��������֮���ע��س����˸�Ҳ�����ȥ��"<<endl;
	cout<<"2���û�����ȻûҪ����ĸ�����֡����š�����֮��ģ�����þ���ֻ�����ֺ���ĸ��ɰ�"<<endl; 
	cout<<"3���û�����ȻҲ��Ҫ̫����"<<endl;
	cout<<"4�������6λ�������ĸ�����֡����š����Ķ����ޣ����ִ�СдŶ~~~"<<endl;
	cout<<"5�����Իس�����������"<<endl;
	cout<<"6����Ҫ�Ķ����ɵ��ļ�������������ݴ���"<<endl; 
	cout<<"7��ע��ѡ��ʱҪ�رմ�д\n\a"<<endl; 
	cout<<"	******�ر�ע�⣺��D���½�һ����Ϊ��ͨѶ¼�����ļ��У���!!!\n"<<endl; 
	cout<<"����֮�󣬾Ϳ�ʼ���ǵ�ע��ɣ�"<<endl;
	getch();
	system("cls");  
}

void foundyonghu(yonghu &a)//ע��ALL
{
	char b[6];
	string c;
	cout<<"���践�����˵��������������˺�"<<endl; 
	cout<<"�û�����";
	cin>>a.name;     
	fstream fs;
	fs.open(adddat(a.name).c_str());
    if(fs)
    {        
    	cerr<<"���û��Ѵ��ڣ�������ע��"<<endl;//����0��������1 
		cout<<"���������˻����˵�����������"<<endl; 
		getch();                                                              
		system("cls"); 
		zhucaidan(a); 
		return;     
    }//�ж��û��ɲ����� 
	fs.close();
	cout<<"����(6λ)��   ";
	for(int i=0;i<=5;i++)
	{
		b[i]=getch();
	    cout<<'*'; 
	    if(i==5) 
		    cout<<"\n";
	}
	a.mima=b;
	cout<<"����һ�����룺";
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
		fout<<a.mima<<endl;//д���ļ� 
		cout<<"�ɹ�ע�ᣡ"<<endl; 
		cout<<"�밴����������˵�...."<<endl; 
		getch();
		system("cls"); 
		zhucaidan(a);
		fout.close();  
	} 
	else
	{
		cout<<"���벻һ�£�������ע��"<<endl;
		getch();
		system("cls"); 
		zhucaidan(a);
	}
}

void dengluyonghu(yonghu &d)//��¼/ALL
{
	string a,e;
	char c[6],b[6];
	cout<<"���践�����˵��������벻���ڵ��˺�"<<endl; 
	cout<<"�û�����";
	cin>>a;
	d.name=a;
	fstream fs(adddat(a).c_str());
	if(access(adddat(a).c_str(),0))
	{
		cout<<"���û������ڣ������µ�¼��ע�����˺�"<<endl;//����0��������1  
		getch();
		system("cls"); 
		zhucaidan(d);
		exit(0);
	}
	fs.close();
	ifstream fin(adddat(a).c_str());//Ѱ�Ҳ��ж�
	cout<<"���룺";
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
		cout<<"������������µ�¼��ע�����˺�" <<endl;
		getch();
		system("cls"); 
		zhucaidan(d);
		exit(0);
	}//�ж������Ƿ���ȷ 
	else
	{
		cout<<"��¼�ɹ���������"<<endl;
		cout<<"�밴���������������"<<endl;
		getch();
		system("cls"); 
		yhcz(d);//�û����� 
	}
	fin.close(); 
}

void lzh()//��ʾ����ALL
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
	cout<<" \n               ��ӭʹ���ɻ��������ͨѶ¼"<<endl;
	Sleep(100);
	cout<<"   \n                   �밴���������"<<endl;
	getch(); 
	system("cls");
}

void zhucaidan(yonghu &b)//���˵�ALL
{                        
	char a;
	cout<<"��½�˺��밴 1"<<endl;
	cout<<"�����û��밴 2"<<endl;
	cout<<"���������밴 3"<<endl;
	cout<<"��������밴 4"<<endl;
	cout<<"���߸����밴 5"<<endl;
	cout<<"�˳������밴 e"<<endl; 
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
			cout<<"���D���е�ͨѶ¼�ļ���ѹ��,��������Q��"<<M<<"���ȴ���������߷���~~~~"<<endl; 
			getch();
			system("cls");
			zhucaidan(b);
			break;
		}
		case '4':
		{
			cout<<"��������������Q��"<<M<<"�����罫Ϊ�㾡������~~~~"<<endl; 
			getch();
			system("cls");
			zhucaidan(b);
			break;
		}
		case '5':
		{
			cout<<"�����õİ汾Ϊ���°�~~~~"<<endl;  
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
			cout<<"�������,����������"<<endl;
		    zhucaidan(b);
		}
	} 
}
							
void yhcz(yonghu &a)//�û�����ALL
{                            
	char b;
	cout<<"ͨѶ¼ѡ���밴   1"<<endl;
	cout<<"�޸��˺������밴 2"<<endl;
	cout<<"�˳���¼�밴     w"<<endl; 
	cout<<"�˳������밴     e"<<endl; 
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
		    cout<<"�������,����������"<<endl;
		    yhcz(a);
		}
	}
}
							
void txlcz(yonghu &a)//ͨѶ¼���� ALL
{
	char b;
	cout<<"�鿴ͨѶ¼�밴   1"<<endl;
	cout<<"�޸�ͨѶ¼�밴   2"<<endl;
	cout<<"������һ���밴   q"<<endl;
	cout<<"�˳���¼�밴     w"<<endl; 
	cout<<"�˳������밴     e"<<endl; 
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
		    cout<<"�������,����������"<<endl;
		    txlcz(a);
		}
	}
} 

void cktxl(yonghu &a)//�鿴ͨѶ¼ ALL
{
	char b;
	cout<<"�鿴ȫ���밴     1"<<endl;
	cout<<"��ѯ�����밴     2(���ڼ������⣬��ѯ��Ϻ��˳����)"<<endl;
	cout<<"������һ���밴   q"<<endl;
	cout<<"�˳���¼�밴     w"<<endl; 
	cout<<"�˳������밴     e"<<endl; 
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
		    cout<<"�������,����������"<<endl;
		    cktxl(a);
		}
	}
}

void xgtxl(yonghu &a)//�޸�ͨѶ¼ ALL
{
	char b;
	cout<<"�����밴         1"<<endl;
	cout<<"ɾ���밴         2"<<endl;
	cout<<"�����밴         3"<<endl;
	cout<<"������һ���밴   q"<<endl;
	cout<<"�˳���¼�밴     w"<<endl; 
	cout<<"�˳������밴     e"<<endl; 
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
		    cout<<"�������,����������"<<endl;
		    xgtxl(a);
		}
	}
}
 
void gairen(yonghu &a)//�޸ĸ�����Ϣ ALL
{
	char b;
	txl *c,*d;
	d=creat(a);
	cout<<"�޸������밴         1"<<endl;
	cout<<"�޸ĵ�ַ�밴         2"<<endl;
	cout<<"�޸��ֻ��밴         3"<<endl;
	cout<<"�޸�qq�밴           4"<<endl;
	cout<<"�޸�΢���밴         5"<<endl;
	cout<<"�޸������밴         6"<<endl;
	cout<<"�޸ĵ��������밴     7"<<endl;
	cout<<"�޸ı�ע�밴         8"<<endl;
	cout<<"������һ���밴       q"<<endl;
	cout<<"�˳���¼�밴         w"<<endl; 
	cout<<"�˳������밴         e"<<endl; 
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
		    cout<<"�������,����������"<<endl;
		    gairen(a);
		}
	}
}

void tch()//�˳����� ALL
{
	cout<<"��ӭ�ٴ�ʹ�û�����±����~~~~~"<<endl;
	system("pause >-nul"); 
} 

void zx(yonghu &a)//ע���û� ALL
{
	cout<<"����ע������������"<<endl;
	cout<<"�밴���������......"<<endl;
	getch();
	system("cls");
	zhucaidan(a); 
}

void xgmm(yonghu &a)//�޸����� ALL
{
	char b[6];
	string c;     
	ifstream fin;
	fin.open(adddat(a.name).c_str());
	cout<<"������(6λ)��   ";
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
		cout<<"�������,����������" <<endl;
		getch();
		system("cls"); 
		yhcz(a);
		exit(0);
	}//�ж������Ƿ���ȷ 
	fin.close();
	cout<<"�����룺        "; 
	for(int i=0;i<=5;i++)
	{
		b[i]=getch();
	    cout<<'*'; 
	    if(i==5) 
		    cout<<"\n";
	}
	a.mima=b;
	cout<<"����һ�������룺";
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
		fout2<<a.mima<<endl;//д���ļ� 
		cout<<"�ɹ��޸����룡"<<endl; 
		cout<<"�밴����������˵����µ�¼...."<<endl; 
		getch();
		system("cls"); 
		zhucaidan(a);
		fout2.close();  
	} 
	else
	{
		cout<<"���벻һ�£�������������"<<endl;
		getch();
		system("cls"); 
		yhcz(a);
		exit(0); 
	}
}

void jiaren(yonghu &a)//����   ALL
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
	cout<<"������";
	cin>>b.name;
	cout<<"��ַ��";
	cin>>b.address;
	cout<<"�ֻ���";
	cin>>b.mobile;
	cout<<"qq��  ";
	cin>>b.qq;
	cout<<"΢����";
	cin>>b.weibo;
	cout<<"���ˣ�";
	cin>>b.renren;
	cout<<"email:";
	cin>>b.email;
	cout<<"��ע��";
	cin>>b.others; 
	system("cls");
	cout<<"������� "<<b.name<<" ��ϢΪ��"<<endl;
	cout<<"������"<<b.name<<'\n'<<"��ַ��"<<b.address<<'\n'<<"�ֻ���"<<b.mobile<<'\n'<<"qq��  "<<b.qq<<'\n'
	    <<"΢����"<<b.weibo<<'\n'<<"���ˣ�"<<b.renren<<'\n'<<"email:"<<b.email<<'\n'<<"��ע��"<<b.others<<endl; 
	cout<<"ȷ�����棿"<<endl;
	cout<<"y       n"<<endl;
	c=getch();
	switch(c)
	{
		case 'y':
		{
			fs<<b.name<<'\t'<<b.address<<'\t'<<b.mobile<<'\t'<<b.qq<<'\t'<<b.weibo<<'\t'
			  <<b.renren<<'\t'<<b.email<<'\t'<<b.others<<endl;
		    cout<<"��ӳɹ���"<<endl;
		    cout<<"�밴�����������������"<<endl;
		    getch();
		    system("cls"); 
		    xgtxl(a);
		    break;
		}
		case 'n':
		{
			system("cls");
		    cout<<"����������"<<endl; 
		    jiaren(a);
		    break;
		}
		default:
		{
			system("cls");
		    cout<<"���������رմ�д����"<<endl; 
		    jiaren(a);
		}
	}
	fs.close();
} 

void ckqb(yonghu &a)//�鿴ȫ�� ALL
{
	 txl *p;
     p=creat(a);
     while(p!=NULL)
     {
         printf("%s\n",p->name);
         printf("��ַ�� %s\n", p->address);
		 printf("�ֻ��� %s\n",p->mobile);
		 printf("qq ��  %s\n", p->qq);
		 printf("΢�� ��%s\n",p->weibo);
		 printf("���� ��%s\n",p->renren);
		 printf("email��%s\n",p->email);
		 printf("��ע ��%s\n\n",p->others);
         p=p->next;
     }
	cout<<"\n�����������һ��"<<endl;
	getch();
	system("cls");
	cktxl(a); 
}

txl *creat(yonghu &a)//���춯̬��  all
{
	txl *head;
    txl *p1,*p2;                    
    FILE*fp;
    if((fp=fopen(adddat(a.name).c_str(),"r"))==NULL)
    {
        printf("���ܴ�%s",adddat(a.name).c_str());
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
    return head->next;//���Ҫ����?
}

void shanren(yonghu &a)//ɾ��  ALL
{
	txl *p1,*p2;
	char b;
	p1=creat(a); 
	p2=search(a,p1);
	cout<<"�Ƿ�ɾ����"<<endl;
	cout<<p2->name<<'\n'<<"��ַ��"<<p2->address<<'\n'<<"�ֻ���"<<p2->mobile<<'\n'<<"qq��  "<<p2->qq<<'\n'
	           <<"΢����"<<p2->weibo<<'\n'<<"���ˣ�"<<p2->renren<<'\n'<<"email:"<<p2->email<<'\n'<<"��ע��"<<p2->others<<endl;
	cout<<"�Ƿ�ɾ��?"<<endl; 
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
				cout<<"ɾ���ɹ���"<<endl;
		        cout<<"�밴�����������������"<<endl;
		        getch();
		        system("cls"); 
		        xgtxl(a);
				break;
			}
		case 'n':
			{
				cout<<"���������룺"<<endl;
				getch();
				system("cls"); 
				shanren(a);
				break;
			}
			default:
				{
					cout<<"���������رմ�д����"<<endl;
					getch();
			    	system("cls");
					shanren(a); 
				}
	}
	
}

txl *search(yonghu &a,txl *c)//�鿴����    ALL
{
    char b;
    printf("���ҷ�ʽ��\n");
    cout<<"ͨ�� ����  Ѱ���밴         1"<<endl;
	cout<<"ͨ�� ��ַ  Ѱ���밴         2"<<endl;
	cout<<"ͨ�� �ֻ�  Ѱ���밴         3"<<endl;
	cout<<"ͨ�� qq    Ѱ���밴         4"<<endl;
	cout<<"ͨ�� ΢��  Ѱ���밴         5"<<endl;
	cout<<"ͨ�� ����  Ѱ���밴         6"<<endl;
	cout<<"ͨ�� email Ѱ���밴         7"<<endl;
	cout<<"ͨ�� ��ע  Ѱ���밴         8"<<endl;
	cout<<"������һ���밴              q"<<endl;
	cout<<"�˳���¼�밴                w"<<endl; 
	cout<<"�˳������밴                e"<<endl; 
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
		    cout<<"�������,����������"<<endl;
		    return search(a,c);
		}
	}
} 

txl *jieguo(int n,txl *p1,txl *head,yonghu &a)//�������   ALL
{
	cout<<"��������"<<n<<"�����\n"<<endl;
	if(n==0)
   {
   	    cout<<"û���ҵ�����"<<endl;
		cout<<"�����������"<<endl;
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
           cout<<"�� "<< i<<" �����Ϊ:"<<endl; 
		   cout<<p1->name<<'\n'<<"��ַ��"<<p1->address<<'\n'<<"�ֻ���"<<p1->mobile<<'\n'<<"qq��  "<<p1->qq<<'\n'
	           <<"΢����"<<p1->weibo<<'\n'<<"���ˣ�"<<p1->renren<<'\n'<<"email:"<<p1->email<<'\n'<<"��ע��"<<p1->others<<'\n'<<endl; 
	       p1=p1->bfor; 
		   i++;   
       }
       if(n!=1)
       {
           cout<<"������Ҫ�Ľ��Ϊ:�������ţ�"<<endl; 
           int x;
           cin>>x;
	        if(cin.fail()||x<1||x>n)
	        {
	    	    cin.clear();
    	    	cin.ignore();
	    		cout<<"�����������������"<<endl;
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
	        cout<<"\n����ѡ����Ϊ��"<<endl; 
	        cout<<p1->name<<'\n'<<"��ַ��"<<p1->address<<'\n'<<"�ֻ���"<<p1->mobile<<'\n'<<"qq��  "<<p1->qq<<'\n'
	           <<"΢����"<<p1->weibo<<'\n'<<"���ˣ�"<<p1->renren<<'\n'<<"email:"<<p1->email<<'\n'<<"��ע��"<<p1->others<<'\n'<<endl; 
	   }
	   cout<<"\n�밴���������������"<<endl;
	   getch();
	   system("cls"); 
       return head;
   }
} 

txl *searchname(yonghu &a,txl *c)//��������ALL
{
	txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("���������ѯ�����֣�");
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

txl *searchaddress(yonghu &a,txl *c)//��ַ����ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("���������ѯ�ĵ�ַ��");
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

txl *searchmobile(yonghu &a,txl *c)//�ֻ�����ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("���������ѯ���ֻ����룺");
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

txl *searchqq(yonghu &a,txl *c)//qq����ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("���������ѯ��qq��");
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

txl *searchweibo(yonghu &a,txl *c)//΢������ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("���������ѯ��΢����");
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

txl *searchrenren(yonghu &a,txl *c)//��������ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("���������ѯ��renren��");
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

txl *searchemail(yonghu &a,txl *c)//email����ALL
{
txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("���������ѯ��email��");
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

txl *searchothers(yonghu &a,txl *c)//��ע����ALL
{
    txl *p1,*p2,*head;
	int n=0;
    char *num;
    printf("���������ѯ�ı�ע��");
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

void jieguo(yonghu &a,txl *b,txl *d)//�޸Ľ�� ALL
{
	char c;
	cout<<"\n�ĺ���Ϣ:"<<endl; 
	cout<<"������"<<b->name<<'\n'<<"��ַ��"<<b->address<<'\n'<<"�ֻ���"<<b->mobile<<'\n'<<"qq��  "<<b->qq<<'\n'
	    <<"΢����"<<b->weibo<<'\n'<<"���ˣ�"<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"��ע��"<<b->others<<endl;  
	    cout<<"ȷ�����棿"<<endl;
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
		    cout<<"��ӳɹ���"<<endl;
		    cout<<"�밴�����������������"<<endl;
		    fs.close();
		    getch();
		    system("cls"); 
		    xgtxl(a);
		    break;
		}
		case 'n':
		{
			system("cls");
		    cout<<"����������"<<endl; 
		    gainame(a,b,creat(a));
		    break;
		}
		default:
		{
			system("cls");
		    cout<<"���������رմ�д����"<<endl; 
		    gainame(a,b,creat(a));
		}
	}
} 

void gainame(yonghu &a,txl *b,txl *d)//�޸����� ALL
{
	cout<<"ԭ����Ϣ:"<<endl;
	cout<<"������"<<b->name<<'\n'<<"��ַ��"<<b->address<<'\n'<<"�ֻ���"<<b->mobile<<'\n'<<"qq��  "<<b->qq<<'\n'
	    <<"΢����"<<b->weibo<<'\n'<<"���ˣ�"<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"��ע��"<<b->others<<endl;  
	cout<<"\n����ĺ������:";
	cin>>b->name;
	jieguo(a,b,d);
}

void gaiaddress(yonghu &a,txl *b,txl *d)//�޸ĵ�ַ ALL
{
	cout<<"ԭ����Ϣ:"<<endl;
	cout<<"������"<<b->name<<'\n'<<"��ַ��"<<b->address<<'\n'<<"�ֻ���"<<b->mobile<<'\n'<<"qq��  "<<b->qq<<'\n'
	    <<"΢����"<<b->weibo<<'\n'<<"���ˣ�"<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"��ע��"<<b->others<<endl;  
	cout<<"\n����ĺ�ĵ�ַ:";
	cin>>b->address;
	jieguo(a,b,d);
}

void gaimobile(yonghu &a,txl *b,txl *d)//�޸��ֻ� ALL
{
	cout<<"ԭ����Ϣ:"<<endl;
	cout<<"������"<<b->name<<'\n'<<"��ַ��"<<b->address<<'\n'<<"�ֻ���"<<b->mobile<<'\n'<<"qq��  "<<b->qq<<'\n'
	    <<"΢����"<<b->weibo<<'\n'<<"���ˣ�"<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"��ע��"<<b->others<<endl;  
	cout<<"\n����ĺ���ֻ�:";
	cin>>b->mobile;
	jieguo(a,b,d);
}

void gaiqq(yonghu &a,txl *b,txl *d)//�޸�qq ALL
{
	cout<<"ԭ����Ϣ:"<<endl;
	cout<<"������"<<b->name<<'\n'<<"��ַ��"<<b->address<<'\n'<<"�ֻ���"<<b->mobile<<'\n'<<"qq��  "<<b->qq<<'\n'
	    <<"΢����"<<b->weibo<<'\n'<<"���ˣ�"<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"��ע��"<<b->others<<endl;  
	cout<<"\n����ĺ��qq:";
	cin>>b->qq;
	jieguo(a,b,d);
}

void gaiweibo(yonghu &a,txl *b,txl *d)//�޸�΢�� ALL
{
	cout<<"ԭ����Ϣ:"<<endl;
	cout<<"������"<<b->name<<'\n'<<"��ַ��"<<b->address<<'\n'<<"�ֻ���"<<b->mobile<<'\n'<<"qq��  "<<b->qq<<'\n'
	    <<"΢����"<<b->weibo<<'\n'<<"���ˣ�"<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"��ע��"<<b->others<<endl;  
	cout<<"\n����ĺ��΢��:";
	cin>>b->weibo;
	jieguo(a,b,d);
}

void gairenren(yonghu &a,txl *b,txl *d)//�޸����� ALL
{
	cout<<"ԭ����Ϣ:"<<endl;
	cout<<"������"<<b->name<<'\n'<<"��ַ��"<<b->address<<'\n'<<"�ֻ���"<<b->mobile<<'\n'<<"qq��  "<<b->qq<<'\n'
	    <<"΢����"<<b->weibo<<'\n'<<"���ˣ�"<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"��ע��"<<b->others<<endl;  
	cout<<"\n����ĺ������:";
	cin>>b->renren;
	jieguo(a,b,d);
}

void gaiemail(yonghu &a,txl *b,txl *d)//�޸�email ALL
{
	cout<<"ԭ����Ϣ:"<<endl;
	cout<<"������"<<b->name<<'\n'<<"��ַ��"<<b->address<<'\n'<<"�ֻ���"<<b->mobile<<'\n'<<"qq��  "<<b->qq<<'\n'
	    <<"΢����"<<b->weibo<<'\n'<<"���ˣ�"<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"��ע��"<<b->others<<endl;  
	cout<<"\n����ĺ�ĵ����ʼ�:";
	cin>>b->email;
	jieguo(a,b,d);
}

void gaiothers(yonghu &a,txl *b,txl *d)//�޸ı�ע ALL
{
	cout<<"ԭ����Ϣ:"<<endl;
	cout<<"������"<<b->name<<'\n'<<"��ַ��"<<b->address<<'\n'<<"�ֻ���"<<b->mobile<<'\n'<<"qq��  "<<b->qq<<'\n'
	    <<"΢����"<<b->weibo<<'\n'<<"���ˣ�"<<b->renren<<'\n'<<"email:"<<b->email<<'\n'<<"��ע��"<<b->others<<endl;  
	cout<<"\n����ĺ�ı�ע:";
	cin>>b->others;
	jieguo(a,b,d);
}

int main()
{
	system("title ��Ļ���");
	yonghu yh;
	lzh(); 
	zhucaidan(yh);
	system("pause >nul");
	return 0;
} 
