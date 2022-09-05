#include<iostream>
#include<func.h>
#include<conio.h>

using namespace std;

int snkx[50],snky[50];
char board[30][40];
int life=4;
char direction='d';
int row=5;
int colm=5;
int ran_a,ran_b;
int speed;
int score;

void randm()
{
	ra:
	ran_a=rand()%29;
	ran_b=rand()%39;
	if(board[ran_a][ran_b]=='Û'||board[ran_a][ran_b]=='o')
	{	
		goto ra;
	}
}

void scor()
{
	if(row == ran_a && colm == ran_b)
		{
			life+=1;
			gotoxy(82,6);
			cout<<"****+100****";
			score+=100;
			gotoxy(82,6);
			cout<<"            ";
			randm();
		}
			gotoxy(82,6);
			cout<<"SCORE="<<score;
			
		
}

void assNdiss()
{
	int i,j,k;
	k=2;
	for(i=0;i<30;i++)
	{
		
		for(j=0;j<40;j++)
		{
			if(i==0||i==29||j==0||j==39)
			{
				board[i][j]='Û';
			}
			else
			{
				board[i][j]=' ';
			}
		}
	}

	board[snkx[1]][snky[1]]='O';
	for(k=2;k<=life;k++)
	{
		board[snkx[k]][snky[k]]='o';
	}
	board[ran_a][ran_b] = 'Q';
	
	gotoxy(0,0);
	for(i=0;i<30;i++)
	{	
		gotoxy(0,i);
		for(j=0;j<40;j++)
		{
			cout<<" "<<board[i][j];
		}
	}
}

void cord()
{
	int x,y,j=1;
	int k=0;
	
	redirected:
	switch(direction)
	{
		case 'd':
			{
				while(!kbhit())
				{
					x=y=life;
					colm+=1;
					if(board[row][colm]=='Û'||board[row][colm]=='o')
					{
						system("cls");
						gotoxy(45,5);
						cout<<"snake crashed!";
						delay(1000);
						goto over;
					}
					else
					k++;
					for(;x>1&&y>1;x--&&y--)
					{
						snkx[x]=snkx[x-1];
						snky[y]=snky[y-1];
					}
					snkx[1]=row;
					snky[1]=colm;
					
					if(k>3)
					{
						delay(speed);
						gotoxy(0,0);
						assNdiss();
						scor();
					}
				}
				direction=getch();
				goto redirected;
			}
		case 's':
			{
				while(!kbhit())
				{
					x=y=life;
					row+=1;
					if(board[row][colm]=='Û'||board[row][colm]=='o')
					{
						system("cls");
						gotoxy(45,5);
						cout<<"snake crashed!";
						delay(1000);
						goto over;
					}
					else
					for(;x>1&&y>1;x--&&y--)
					{
						snkx[x]=snkx[x-1];
						snky[y]=snky[y-1];
					}
					snkx[1]=row;
					snky[1]=colm;
					
					delay(speed);
					gotoxy(0,0);
					assNdiss();
					scor();
				}
				direction=getch();
				goto redirected;
			}
		case 'a':
			{
				while(!kbhit())
				{
					x=y=life;
					colm-=1;
					if(board[row][colm]=='Û'||board[row][colm]=='o')
					{
						system("cls");
						gotoxy(45,5);
						cout<<"snake crashed!";
						delay(1000);
						goto over;
					}
					else
					for(;x>1&&y>1;x--&&y--)
					{
						snkx[x]=snkx[x-1];
						snky[y]=snky[y-1];
					}
					snkx[1]=row;
					snky[1]=colm;
					
					delay(speed);
					gotoxy(0,0);
					assNdiss();	
					scor();
				}
				direction=getch();
				goto redirected;
			}
		case 'w':
			{
				while(!kbhit())
				{
					x=y=life;
					row-=1;
					if(board[row][colm]=='Û'||board[row][colm]=='o')
					{
						system("cls");
						gotoxy(45,5);
						cout<<"snake crashed!";
						delay(1000);
						goto over;
					}
					else
					for(;x>1&&y>1;x--&&y--)
					{
						snkx[x]=snkx[x-1];
						snky[y]=snky[y-1];
					}
					snkx[1]=row;
					snky[1]=colm;
					
					delay(speed);
					gotoxy(0,0);
					assNdiss();
					scor();
				}
				direction=getch();
				goto redirected;	
			}
			default:
				{
					cout<<"wrong Direction input!";
				}
						
	}
	over:
	system("cls");
	gotoxy(55,5);
	cout<<"GAME OVER"<<endl;
	gotoxy(55,6);
	cout<<"YOUR SCORE:  "<<score<<endl;
	system("pause");
}

int main()
{
	int ch,dif;
	main:
	gotoxy(45,2);
	cout<<"Type the numbers to select options!";
	gotoxy(45,3);
	cout<<"START GAME   ---------------------   1";
	gotoxy(45,4);
	cout<<"CONTROLS     ---------------------   2";
	gotoxy(45,5);
	cout<<"EXIT         ---------------------   3";
	gotoxy(45,6);
	cin>>ch;
	system("cls");
	if(ch==1)
	{
		diff:
		gotoxy(45,2);
		cout<<"Select Difficulty";
		gotoxy(45,3);
		cout<<"EASY     ---------------------   1";
		gotoxy(45,4);
		cout<<"NORMAL   ---------------------   2";
		gotoxy(45,5);
		cout<<"HARD     ---------------------   3";
		gotoxy(45,6);
		cin>>dif;
		system("cls");
		switch(dif)
		{
			case 1:
				{
					speed=130;
					break;
				}
			case 2:
				{
					speed=70;
					break;
				}
			case 3:
				{
					speed=40;
					break;
				}
			default:
				goto diff;
		}
	}
	else if(ch==2)
	{
		gotoxy(45,2);
		cout<<"Controls";
		gotoxy(45,3);
		cout<<"UP     ------------------ w";
		gotoxy(45,4);
		cout<<"DOWN   ------------------ s";
		gotoxy(45,5);
		cout<<"LEFT   ------------------ a";
		gotoxy(45,6);
		cout<<"RIGHT  ------------------ d";
		getch();
		system("cls");
		goto main;
	}	
	else if(ch==3)
	{
		goto ovr;
	}
	else
	{
		goto main;
	}
	randm();
	cord();
	ovr:
	return 0;
}
