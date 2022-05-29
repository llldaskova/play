#pragma once 
#include <iostream>
#include <time.h>
#include "windows.h"
using namespace std;

class creature
{
	private:
		float hungry;
		int lifeSpan;
		int lS_count;
		int sleep;
		int count;
		int on_sleep;
		int move;
	public:
	virtual void sleep_zero() 
	{
	}
	virtual void h_move() 
	{	
	}	
	virtual void h_eat() 
	{	
	}
	virtual void h_birth() 
	{	
	}
	virtual int Get_move() 
	{
	}
	virtual void Set_move(int a) 
	{
	}
	virtual int Get_ONsleep() 
	{

	}
	virtual void Set_ONsleep(int a) 
	{	
	}
	virtual void Sleep() 
	{
	}
	virtual int Get_sleep() 
	{
		
	}
	virtual void del()
	{
	}
	virtual void lS_cycle()
	{
	}
	virtual int Get_lS_count()
	{
	}
	virtual float Get_hungry()
	{
	}
	virtual int Get_lifeSpan()
	{
	}
	virtual int call()
	{
	}
};

class plant: public creature
{
	private:
		int lifeSpan;
		int lS_count=0;
	public:	
	plant():lifeSpan(10)
	{
		lS_count++;
	}
	plant(int a):lifeSpan(11)
	{
		lS_count++;
	}
	void lS_cycle() override
	{
		lS_count++;
	}
	int Get_lS_count() override
	{
		return lS_count;
	}
	int Get_lifeSpan() override
	{
		return lifeSpan;
	}
	int call() override
	{
		return 1;
	}
};

class herbivore: public creature
{
	private:
		int move=0;
		float hungry;
	public:	
	herbivore():hungry(0.5)
	{
	}
	herbivore(creature *herb):
	hungry(herb->Get_hungry())
	{
	}
	void h_birth() override
	{
		hungry-=0.4;	
	}
	int Get_move() override
	{
		return move;
	}
	void Set_move(int a) override
	{	
		move=a;
	}
	void h_eat() override
	{	
		hungry=hungry+0.2;
	}
	void h_move() override
	{	
		hungry-=0.2;
	}
	float Get_hungry() override
	{
		return hungry;
	}
	int call() override
	{
		return 2;
	}
};

class predator: public creature
{
	private:
		static int count;
		float hungry;
		int lifeSpan;
		int sleep=0;
		int on_sleep=0;
		int move=0;
	public:
		
	predator():hungry(3),lifeSpan(3)
	{
		count++;
	}
	predator(int a)
	{
	}
	predator(creature *Snake):
	hungry(Snake->Get_hungry()),lifeSpan(3)
	{
	}
	void sleep_zero() override
	{
		sleep=0;
	}
	void h_move() override
	{	
		hungry-=0.2;
	}	
	void h_eat() override
	{	
		hungry=hungry+0.2;
	}
	int Get_move() override
	{
		return move;
	}
	void Set_move(int a) override
	{	
		move=a;
	}
	static int Get_count() 
	{
		return count;
	}
	void Sleep() override
	{
		if(on_sleep==1)
		sleep++;
	}
	void Set_ONsleep(int a) override
	{
		on_sleep=a;	
	}
	int Get_ONsleep() override
	{
		return on_sleep;
	}
	int Get_sleep() override
	{
		return sleep;
	}
	void del() override
	{
		count--;
	}
	float Get_hungry() override
	{
		return hungry;
	}
	int Get_lifeSpan() override
	{
		return lifeSpan;
	}
	int call() override
	{
		return 3;
	}
};
int predator::count=0;

class egg: public creature
{
	private:
		int lifeSpan;
		int lS_count=0;
	public:
	egg():lifeSpan(2)
	{
		lS_count++;
	}
	void lS_cycle() override
	{
		lS_count++;
	}
	int Get_lS_count() override
	{
		return lS_count;
	}
	int Get_lifeSpan() override
	{
		return lifeSpan;
	}
	int call() override
	{
		return 4;
	}
};
class empty: public creature
{
	private:
	public:	
	int call() override
	{
		return 0;
	}
};

class field
{
	private:
		int n=10;
		creature*** F;
	public:	
	field()
	{
		F=new creature**[n];
		for(int i=0;i<n;i++)
			F[i]=new creature*[n];
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			F[i][j]=new empty;
		}
	}
	}

	
	void print();
	void life();
	void rand_plant(int a);
	void rand_herbivore();
	void rand_predator();
	void rand_egg();
	void death_and_aging();
	void snake_check();
	void eat_movement();
	void check_move(int &m,int &n);
	void set_move_zero();
	int check_hunting(int &m,int &k,int p);
	int birthday();
	void nut();
};
void field::rand_plant(int a=0)
{
	int x,y;
	int r=0;
	while(r<500)
	{
		r++;
		x=rand()%10;
		y=rand()%10;
		if(F[x][y]->call()==0)
		{
			if(a==0)
			F[x][y]=new plant();
			if(a==1)
			F[x][y]=new plant(1);
			return;
		}
	}
}
void field::rand_herbivore()
{
	int x,y;
	int r=0;
	while(r<500)
	{
		x=rand()%10;
		y=rand()%10;
		r++;
		if(F[x][y]->call()==0)
		{
			F[x][y]=new herbivore();
			return;
		}
	}
}
void field::rand_predator()
{
	int x,y;
	int r=0;
	while(r<500)
	{
		x=rand()%10;
		y=rand()%10;
		r++;
		if(F[x][y]->call()==0)
		{
			F[x][y]=new predator();
			return;
		}
	}
}
void field::rand_egg()
{
	int x,y;
	int r=0;
	while(r<500)
	{
		x=rand()%10;
		y=rand()%10;
		r++;
		if(F[x][y]->call()==0)
		{
			F[x][y]=new egg();
			return;
		}
	}
}

void field:: print()
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int a=F[i][j]->call();
				switch (a)
				{
					case 1:
						cout<<'+';
						break;
					case 2:
						cout<<'b';
						break;
					case 3:
						cout<<'S';
						break;
					case 4:
						cout<<'O';
						break;
					default:
						cout<<".";
				}
				/*if (a>0&&a<4)
					cout<<a;
				else 
					cout<<" ";*/
				cout<<" ";
		
			}
			cout<<endl;
		}
	}
	
void field::snake_check ()//хватает ли змей
{
	predator z(1);
	if(z.Get_count()==1)
	{
		rand_egg();
	}
	else if (z.Get_count()==0)
	{
		rand_egg();
		rand_egg();
	}
}
void field::death_and_aging()
{
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(F[i][j]->call()==1||F[i][j]->call()==4)//обновление цикла жизни
				{
					F[i][j]->lS_cycle();
				}
				else if(F[i][j]->call()==3)//обновление цикла сна
				{
					F[i][j]->Sleep();
					if(F[i][j]->Get_sleep()>F[i][j]->Get_lifeSpan())//змея проснулась
					{
						F[i][j]->Set_ONsleep(0);
						F[i][j]->sleep_zero();
					}
				}
				
				
				if(F[i][j]->call()==2&&F[i][j]->Get_hungry()<0)//бурундук умер от голода
					F[i][j]=new empty();
				else if(F[i][j]->call()==3&&F[i][j]->Get_hungry()<0)//змея умерла от голода и оставила яйцо
				{
					F[i][j]->del();
					F[i][j]=new egg();
				}	
				else if(F[i][j]->call()==4&&F[i][j]->Get_lifeSpan()<F[i][j]->Get_lS_count())
					F[i][j]=new predator();
				else if(F[i][j]->call()==1&&F[i][j]->Get_lifeSpan()<F[i][j]->Get_lS_count())
					F[i][j]=new empty();
			}
		}  
}
void field::set_move_zero()
{
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{	
				if(F[i][j]->Get_move()==1)
				{
					F[i][j]->Set_move(0);
				}
			}
		}
	
}
void field::check_move(int &m,int &k)//для ходьбы змеи 
{
	int a=rand()%4+1;
	int m1,k1;
	int r=0;
	while(r<100)
	{
		if(a==1)
		{
			m1=m-1; 
			if(m==0)
			{
				if(F[n-1][k]->call()==0)
				{
					m=n-1; 
					return;
				}
			}
			else
			{
				if(F[m1][k]->call()==0)
				{
					m=m1; 
					return;
				}
			}
			r++;
		}
		if(a==2)
		{
			k1=k+1;
			if(k==n-1)
			{
				if(F[m][0]->call()==0)
				{
					k=0; 
					return;
				}
			}
			else
			{
				if(F[m][k1]->call()==0)
				{
					k=k1; 
					return;
				}
			}	
			r++;
		}
		if(a==3)
		{
			m1=m+1;
			if(m==n-1)
			{
				if(F[0][k]->call()==0)
				{
					m=0; 
					return;
				}
			}
			else
			{
				if(F[m1][k]->call()==0)
				{
					m=m1; 
					return;
				}
			}	
			r++;
		}
		if(a==4)
		{
			k1=k-1;
			if(k==0)
			{
				if(F[m][n-1]->call()==0)
				{
					k=n-1; 
					return;
				}
			}
			else
			{
				if(F[m][k1]->call()==0)
				{
					k=k1; 
					return;
				}
			}
			r++;	
		}
	a=rand()%4+1;
//	cout<<"Застряли в цикле простой ходьбы для змеи"<<cout;
	}
	
}
int field::birthday()
{
	int a=rand()%4+1;
	if(a==1)
		return 2;
}
int field::check_hunting(int &m,int &k,int p)//для охоты змеи или бурундука
{
	int a=rand()%4+1;
	int m1,k1;
	int r=0;
	while(r<100)
	{
		if(a==1)
		{
			m1=m-1; 
			if(m==0)
			{
				if(F[n-1][k]->call()==0)
				{
					m=n-1; 
					return 0;
				}
				else if(F[n-1][k]->call()==p)
				{
					m=n-1; 
					return 1;
				}
			}
			else
			{
				if(F[m1][k]->call()==0)
				{
					m=m1; 
					return 0;
				}
				else if(F[m1][k]->call()==p)
				{
					m=m1;
					return 1;
				}
			}
			r++;
		}
		if(a==2)
		{
			k1=k+1;
			if(k==n-1)
			{
				if(F[m][0]->call()==0)
				{
					k=0; 
					return 0;
				}
				else if(F[m][0]->call()==p)
				{
					k=0; 
					return 1;
				}
			}
			else
			{
				if(F[m][k1]->call()==0)
				{
					k=k1; 
					return 0;
				}
				else if(F[m][k1]->call()==p)
				{
					k=k1; 
					return 1;
				}
			}	
			r++;
		}
		if(a==3)
		{
			m1=m+1;
			if(m==n-1)
			{
				if(F[0][k]->call()==0)
				{
					m=0; 
					return 0;
				}
				else if(F[0][k]->call()==p)
				{
					m=0; 
					return 1;
				}
			}
			else
			{
				if(F[m1][k]->call()==0)
				{
					m=m1; 
					return 0;
				}
				else if(F[m1][k]->call()==p)
				{
					m=m1; 
					return 1;
				}
			}	
			r++;
		}
		if(a==4)
		{
			k1=k-1;
			if(k==0)
			{
				if(F[m][n-1]->call()==0)
				{
					k=n-1; 
					return 0;
				}
				else if(F[m][n-1]->call()==p)
				{
					k=n-1; 
					return 1;
				}
			}
			else
			{
				if(F[m][k1]->call()==0)
				{
					k=k1; 
					return 0;
				}
				if(F[m][k1]->call()==p)
				{
					k=k1;
					return 1;
				}
			}
			r++;	
		}
	a=rand()%4+1;
	//cout<<"Застряли в цикле охоты  для змеи"<<cout;
	}	
}
void field::eat_movement()
{
	int m,k,s=0;
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{	
			s=0;
				if(F[i][j]->Get_move()==0)
				{
					
				if(F[i][j]->call()==3&&F[i][j]->Get_ONsleep()==0)//змея 
				{
					m=i;k=j;
					if(F[i][j]->Get_hungry()>1.5)//не голодная
					{
						check_move(m,k);
					}
					else//очень голодная...страшно
					{
						s=check_hunting(m,k,2);
					}
					
					if(m!=i||k!=j)
					{
					F[m][k]=new predator(F[i][j]);
					F[i][j]=new empty;
					F[m][k]->h_move();
					}
					if(s==1)
					{
						F[m][k]->h_eat();
						F[m][k]->Set_ONsleep(1);
						F[m][k]->Sleep();
					}
					F[m][k]->Set_move(1);
				}
				
				
				/////////////// бурундук
				if(F[i][j]->call()==2)
				{
					m=i; k=j;
					s=check_hunting(m,k,1);
					if(m!=i||k!=j)
					{
						F[m][k]=new herbivore(F[i][j]);
						F[i][j]=new empty;
						F[m][k]->h_move();
					}
					if(s==1)
					{
						F[m][k]->h_eat();
					}
					F[m][k]->Set_move(1);
					s=birthday();
					if(s==2)
					{
						F[i][j]=new herbivore;
						F[i][j]->Set_move(1);
						F[m][k]->h_birth();
					}
				}
				
				
				}
			/*	else if(F[i][j]->call()==3&&F[i][j]->Get_hungry()<0)//змея умерла от голода и оставила яйцо
				{
					F[i][j]=new egg();
					F[i][j]->del();
				}	
				else if(F[i][j]->call()==4&&F[i][j]->Get_lifeSpan()<F[i][j]->Get_lS_count())
					F[i][j]=new predator();
				else if(F[i][j]->call()==1&&F[i][j]->Get_lifeSpan()<F[i][j]->Get_lS_count())
					F[i][j]=new empty();*/
					
			}
		}  
		set_move_zero();
}
void field::life()
{
	int a=rand()%9+5;
	for(int i=0;i<a;i++)
		rand_plant(1);//специальные условия для первого запуска растения
	a=rand()%6+3;
	//a=50;
	for(int i=0;i<a;i++)
		rand_herbivore();
	a=rand()%8+2;
	//a=1;
	for(int i=0;i<a;i++)
		rand_predator();
	//rand_egg();
	while(1)
	{
		//system("cls");
		print();
	/*	for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(F[i][j]->call()==1)
				{
					cout<<"plant"<<" "<<i<<" "<<j<<"  "<<F[i][j]->Get_lS_count()<<" "<<F[i][j]->Get_lifeSpan()<<endl;
				}
				else if(F[i][j]->call()==2)
				{
					cout<<"b"<<" "<<i<<" "<<j<<"  "<<F[i][j]->Get_hungry()<<" "<<endl;
				}
				else if(F[i][j]->call()==3)
				{
					//cout<<"zmeya"<<i<<" "<<j<<"  "<<"  "<<F[i][j]->Get_sleep()<<"  "<<F[i][j]->Get_ONsleep()<<" "<<F[i][j]->Get_hungry()<<" "<<endl;
				}
				else if(F[i][j]->call()==4)
				{
					//cout<<"egg"<<i<<" "<<j<<"  "<<F[i][j]->Get_lS_count()<<" "<<F[i][j]->Get_lifeSpan()<<endl;
				}
			}*/
		death_and_aging();
		snake_check();
		eat_movement();
		nut();
		system("pause");
	}
}
void field::nut()
{
	int a=rand()%5+1;
	int b=rand()%7+1;
	if(a==2)
	{
		for(int i=0;i<b;i++)
			rand_plant();
	}
	
}
