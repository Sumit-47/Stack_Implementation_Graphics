//Implement STACK using STRUCTURE & GRAPHICS
#include<stdio.h> 
#include<graphics.h>
#include<string.h> 
struct data
{
	char num[20];
};
struct stack 
{  
	struct data y[5];	    
	int top; 
}; 
int x=-1; 
void start_screen(); 
void disp_top();
void startscreen(int x,int y); 
static int i=7; 
void push(struct stack *s, char n[]); 
void display(struct stack *s);                 
void pop(struct stack *s); 
void peek(struct stack *s); 
int gd=DETECT,gm; 
 
int main() 
{  
 	struct stack s;  
	int i,no,j,m,k;  
	start_screen();    
	s.top=-1;
	rectangle(100,150,400,400);  
	setcolor(BLACK);  
	line(100,150,400,100);  
	//setfillstyle(0,BLUE);  
	//bar(1,1,getmaxx(),getmaxy());  
	char n[20];  
	do  
	{   
	 	printf("Press\n1->push\n2->pop\n3->display\n4->peek\n");   
		scanf("%d",&k); 
  		switch(k)   
		{    
			case 1: printf("How many elements to enter\n");      
					scanf("%d",&no);            
					for(i=1;i<=no;i++)      
					{       
						if((s.top)!=5-1)       
						{               
							printf("Enter an element to push in stack\n");        
							scanf("%s",n);        
							push(&s,n);       
						}       
						else       
						{        
							kbhit();        
							settextstyle(4,0,5);        
							outtextxy(100,100,"STACK FULL");        
							delay(2000);        
							setfillstyle(2,BLACK);        
							bar(100,100,1000,150);        
							printf("Stack is full");        
							delay(2000);                
							goto END;       
						}      
					}      
					END:      
					break;     
			case 2: printf("Enter no. of elements to be poped\n");      
					scanf("%d",&i);      
					for(m=1;m<=i;m++)       
					{
						if(s.top!=-1)       
							pop(&s);      
						else      
						{
							settextstyle(4,0,5);        
							outtextxy(100,100,"STACK Empty");        
							delay(2000);        
							setfillstyle(2,BLACK);        
							bar(100,100,1000,150);        
      						printf("Stack is Empty\n No element to diaplay");      
							delay(2000);             
							goto END2;      
						}
					}
					disp_top();
			     	END2:      
					break;    
			case 3: if(s.top>=-1)       
						display(&s);      
					else        
						printf("no element to display");      
					break;    		
			case 4: peek(&s);      
					break;   
		}   
		printf("\nPress 1->\tto do some other operation\n OR press any key to exit\n");    
		scanf("%d",&j);  
	}while(j==1);  
	getch();  
	return 0; 
} 


void push(struct stack *s, char n[]) 
{  
	if(s->top!=5-1)  
	{   
		setfillstyle(1,BLACK);   
		s->top++;   
		strcpy(s->y[s->top].num,n);   
		bar(102,50*i,400,(50*i)+50);   
		setcolor(3);   
		line(100,50*i,400,50*i);   
		settextstyle(2,0,7);   
		outtextxy(450,i*50+25,"<-TOP");   
		delay(1000);   
		outtextxy(200,i*50+25,s->y[s->top].num);   
		bar(401,i*50,650,i*50+50);   
		settextstyle(2,0,7);   
		i--;  
	}  
	else 
  	printf("STACK FULL");   
} 

void display(struct stack *s) 
{  
	int i=(s->top);  
	printf("Elements in stack are:\n");  
	while(i!=-1)  
	{   
		printf("%s\n",s->y[i].num);   
		i--;  
	} 
} 

void peek(struct stack *s) 
{  
	if(s->top==-1)   
	printf("Stack is empty");  
	else   
	printf("Topmost element of the stack is %s\n",s->y[s->top].num); 
} 

void pop(struct stack *s) 
{    
	char n[20];  
	if(s->top==-1)  
	{   
	  
	printf("All elements are removed stack is empty\n");  
	}  
	else  
	{   
		i++;
		bar(101,50*i,400,(50*i)+50);   
		settextstyle(2,0,7);   
		outtextxy(550,i*50+25,"<-TOP");   
		delay(1000);   
		bar(401,i*50,650,i*50+50); 
      	strcpy(n,s->y[s->top].num);  
		s->top--;      
	} 
} 
 
 
void start_screen() 
{  
	int mx, my;   
	int gd= DETECT, gm;  
	initgraph(&gd,&gm," ");  
	mx = (getmaxx() / 2);  
	my = (getmaxy() / 2);   
	setfillstyle(9, 1);  
	bar(0,0,getmaxx(),getmaxy()); 
	setfillstyle(1,7); 
	setcolor(15);  
	line(50,20,600,20);  
	line(51,21,599,21);  
	line(50,20,50,400);  
	line(51,21,51,399);   
	setcolor(8);  
	line(600,20,600,400);  
	line(599,21,599,400);  
	line(50,400,600,400);  
	line(51,399,600,399);  
	setfillstyle(9,8);  
	bar(70,40,100,380);  
	bar(70,40,550,70);  
	bar(70,350,550,379);
	bar(545,40,575,380); 
 	settextstyle(1, 0, 4);  
	settextjustify(1,1);  
	setcolor(LIGHTGREEN);  
	outtextxy(mx+2, my - 150, "!...Wel Come...!");  
	settextstyle(4,0,2);  
	setcolor(GREEN);  
	outtextxy(mx + 2, my - 100, "STACK IMPLEMENTATION"); 
	settextstyle(4,0,3);  
	setcolor(WHITE);  outtextxy(mx, my-50, "BY");  
	setcolor(WHITE);  outtextxy(mx, my + 5, "ABHISHEK");  
	setcolor(WHITE);  outtextxy(mx + 1, my + 30, "SUMIT");  
	setcolor(WHITE);  outtextxy(mx+1, my + 55, "KASHYAP");  
	setcolor(WHITE);  outtextxy(mx+1, my + 80, "KABIR");    
	settextstyle(4,0,1);  
	setcolor(WHITE);  outtextxy(mx-1,my+140,"Press ANY KEY to continue"); 
 	getch();   
	closegraph();  
	initgraph(&gd,&gm," ");  
	startscreen(getmaxx(),getmaxy()); 
} 
 
 

void startscreen(int x,int y) 
{  
	int i; 
	setbkcolor(0);  
	setlinestyle(5,0,2);  
	rectangle(0,0,x,y);  
	rectangle(2,2,x-2,y-2);  
	settextstyle(10,HORIZ_DIR,3);  
	setcolor(YELLOW);  
	outtextxy(x/10,y/3,"\t\t\tLoading ....... \n\t\tPlease Wait......");  
	setcolor(LIGHTGRAY);  
	rectangle(x/8,2*y/3,7*x/8,2*y/3+20);  
	setcolor(WHITE);  
	bar(x/8+1,2*y/3+1,7*x/8-1,2*y/3+20-1);  
	setfillstyle(1,LIGHTBLUE);  
	delay(1000);  
	for(i=4;i>=1;i--)  
	{   
		bar(x/8+1,2*y/3+1,7*x/8/i-1,2*y/3+20-1);   
		delay(1000);  
	}    
	delay(500);  
	setcolor(WHITE);  
	outtextxy(100,y-50,"PRESS ANY KEY TO CONTINUE" );  
	getch();  
	closegraph();  
	initgraph(&gd,&gm," "); 
}

void disp_top()
{
	int j=i;
	j++;  
	settextstyle(2,0,7);   
	outtextxy(550,j*50+25,"<-TOP");   
	delay(1000);   
	bar(401,j*50,650,j*50+50); 
	
}
