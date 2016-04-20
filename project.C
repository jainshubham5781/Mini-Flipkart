#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
union REGS i,o;
struct price
{       int add;
	long int rate;
	struct price*down1;
};
struct product
{
	char pname[30];
	struct product*down2;
};
struct level2           //struct for sub category
{
	int name22;
	struct level2 *next22;
};
struct level1           //struct for main category
{
	int name11;
	struct level1 *down11;
	struct level2 *link11;
	struct level1 *right11;
}*start11=NULL,*temp11,*end11;
struct level1 *create1(int);
struct level2 *create2(int);
struct level1 *elec1=NULL,*men1=NULL,*women1=NULL,*books1=NULL,*games1=NULL;
struct level1 *traverse1=NULL;
struct level2 *traverse2=NULL;
struct price*start1=NULL,*temp1=NULL,*tempm1=NULL;
struct product*start2=NULL,*temp2=NULL,*tempm2=NULL;
void ppush();
void prpush();
void ppop();
void prpop();
long int total=0;
int d;
 void ppush()
{
     temp1->down1=start1;
     start1=temp1;                   //add and rate push
}
void ppop()
{

textcolor(YELLOW);
printf("\n\n");
printf("\t\t");
cprintf("%d",start1->add);
prpop();                                           //pop of above
printf("\t");
cprintf("INR %ld",start1->rate);
 total=total+start1->rate;
	tempm1=start1;
	start1=start1->down1;
	free(tempm1);
}
void prpush()
{

	temp2->down2=start2;                //push of name
	start2=temp2;
//return start2;
}
void prpop()
{
   textcolor(YELLOW);
  printf("\t");
   cprintf("%s",start2->pname);
	tempm2=start2;                                    //pop of name
	start2=start2->down2;
	free(tempm2);
//return start2;
}

void thanku()
{
int gdriver=DETECT,gmode,col=400,row=600,font=4,direction=2,size=8,color=15;
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
cleardevice();
while(!kbhit())
{
    settextstyle(random(font),random(direction),random(size));
    setcolor(random(color));
    outtextxy(random(col),random(row),"!! THANK YOU :)");
    delay(250);
}
closegraph();
}


void bill()
{
cleardevice();
closegraph();
textcolor(RED);
printf("\n\t\t\t\t");
cprintf("YOUR BILL IS");
tempm1=start1;
tempm2=start2;
while(start1!=NULL&&start2!=NULL)
{
ppop();
}
printf("\n\n\n\t\t\t");
cprintf(" YOUR TOTAL BILL IS " );
printf("\t");
cprintf("INR %ld",total);
getch();
thanku();
}
//************linking code***********
void creation()
{
	int n=1;
	elec1=create1(10*n);
	n++;
	men1=create1(10*n);
	n++;
	women1=create1(10*n);
	n++;
	books1=create1(10*n);
	n++;
	games1=create1(10*n);
	elec1->right11=men1;
	men1->right11=women1;
	women1->right11=books1;
	books1->right11=games1;

}
struct level1 *create1(int n)
{
	int i;
	start11=NULL;
	for(i=0;i<3;i++)
	{
		n++;
		temp11=(struct level1 *)malloc(sizeof(struct level1));
		temp11->name11=n;
		temp11->down11=NULL;
		temp11->right11=NULL;
		temp11->link11=create2(10*n);
		if(start11==NULL)
		{
			start11=temp11;
			end11=temp11;
		}
		else
		{
			end11->down11=temp11;
			end11=temp11;
		}
	}
return start11;
}
struct level2 *create2(int n)
{
	int i;
	struct level2 *start22=NULL,*end22,*temp22;
	for(i=0;i<3;i++)
	{
		n++;
		temp22=(struct level2 *)malloc(sizeof(struct level2));
		temp22->name22=n;
		temp22->next22=NULL;
		if(start22==NULL)
		{
			start22=temp22;
			end22=temp22;
		}
		else
		{
			end22->next22=temp22;
			end22=temp22;
		}
	}
return start22;
}

int initmouse()
{
	i.x.ax = 0;
	int86(0X33,&i,&o);
	return(o.x.ax);
}
void showmouseptr()
{
	i.x.ax = 1;
	int86(0X33,&i,&o);
}
void hidemouseptr()
{
	i.x.ax = 2;
	int86(0X33,&i,&o);
}
void category();
void clothes();
void electronics();
void women();
void tablets();
void laptops();
void speakers();
void books();
void bookoptions();
void academic();
void literature();
void children();
void men();
void tshirt();
void trouser();
void tie();
void jeans();
void kurti();
void bag();
void board();
void video();
void gameoptions();
void games();
void load()
{
int j,k;
	textcolor(YELLOW);
																																																																			textcolor(YELLOW);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t");


	cprintf(" LOADING PLEASE WAIT ");
	for(k=0;k<3; k++)
	{	for(j=0;j<5; j++)
		{	cprintf(".");
			cprintf(" ");
			delay(200);
		}
		printf("\b\b\b\b\b\b\b\b\b\b");
		printf("          ");
		printf("\b\b\b\b\b\b\b\b\b\b");
	}
	printf("\n\n\t\t   ");
	sound(1000);
	delay(500);
	nosound();
	cprintf("       FLIPKART IS READY");
	printf("\n\n\n\t\t\t\t\t\t");
	cprintf("Press any key to continue...");
	getch();

}
void welcome()
{        cleardevice();
	setcolor(RED);
	setfillstyle(XHATCH_FILL,WHITE);
	setfillstyle(WIDE_DOT_FILL,BLUE);
	rectangle(75,175,585,300);
	floodfill(76,178,RED);

	rectangle(75,175,585,300);
	setcolor(RED);
	settextstyle(8,0,4);
	outtextxy(80,220,"WELCOME TO MINI FLIPKART..");
	setcolor(WHITE);
	settextstyle(3,0,2);
	outtextxy(400,400,"PRESS ENTER");
	getch();
}




//*************main category********

void category()
{
	char choice;

	clearviewport();
	setbkcolor(BLACK);
	setcolor(YELLOW);
	settextstyle(6,0,4);
	outtextxy(22,50,"__________________");
	outtextxy(25,50,"SELECT THE CATEGORY");
	setcolor(WHITE);
	settextstyle(5,0,3);
	outtextxy(25,150,"1.ELECTRONICS");
	outtextxy(25,200,"2.MEN");
	outtextxy(25,250,"3.WOMEN");
	outtextxy(25,300,"4.BOOKS");
	outtextxy(25,350,"5.GAMES");
	initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		if(o.x.cx>=24&&o.x.cx<=200)
		{

			if(o.x.dx>=150&&o.x.dx<=190)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					electronics();
			       }
			   }
		   }

		   if(o.x.cx>=21&&o.x.cx<=200)
		{

			if(o.x.dx>=200&&o.x.dx<=235)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					   men();
			       }
			   }
		   }
	       if(o.x.cx>=21&&o.x.cx<=200)
		{

			if(o.x.dx>=240&&o.x.dx<=285)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					  women();
			       }
			   }
		   }
		   if(o.x.cx>=21&&o.x.cx<=200)
		{

			if(o.x.dx>=300&&o.x.dx<=340)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					books();
			       }
			   }
		   }
		if(o.x.cx>=25&&o.x.cx<=200)
		{
			if(o.x.dx>=345&&o.x.dx<=390)
			{
			      if(o.x.bx==1)
			      {
				hidemouseptr();
				games();
			     }
		       }
		}

	 }
}


//**************electronics*********


void electronics()
{
	int choice,c;
	clearviewport();
	setbkcolor(BLACK);
	setcolor(MAGENTA);
	 setfillstyle(SOLID_FILL,BROWN);
	 settextstyle(4,0,8);
	 outtextxy(48,50,"____________");
	 outtextxy(50,50,"ELECTRONICS");
	 setcolor(BROWN);
	 settextstyle(3,0,4);
	outtextxy(25,150,"1.TABLETS");
	outtextxy(25,200,"2.LAPTOPS");
	outtextxy(25,250,"3.SPEAKERS");
	outtextxy(0,440,"BACK");
	outtextxy(500,440,"EXIT");
	traverse1=elec1;
	initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		if(o.x.cx>=20&&o.x.cx<=200)
		{

			if(o.x.dx>=50&&o.x.dx<=190)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					tablets();
				}
		       }
	      }
		if(o.x.cx>=15&&o.x.cx<=200)
		{

			if(o.x.dx>=200&&o.x.dx<=240)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					traverse1=traverse1->down11;
					laptops();
				}
		       }
	      }
	     if(o.x.cx>=0&&o.x.cx<=50)
		{

			if(o.x.dx>=440&&o.x.dx<=480)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					category();
				}
		       }
		 }
	       if(o.x.cx>=25&&o.x.cx<=200)
		{

			if(o.x.dx>=250&&o.x.dx<=280)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					traverse1=traverse1->down11->down11;
					speakers();
				}
		       }
		 }

	    if(o.x.cx>=500&&o.x.cx<=550)
		{

			if(o.x.dx>=440&&o.x.dx<=480)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
		 }


}

}


void tablets()
{

	int choice;
	clearviewport();
	setcolor(BLUE);
	 setfillstyle(0,BROWN);
	 settextstyle(1,0,8);
	 outtextxy(90,35,"________");
	 outtextxy(90,35,"TABLETS");
	 setcolor(RED);
	 settextstyle(3,0,4);
	outtextxy(25,150,"1.SONY");
	//showmouseptr for coordinates above and if clicked call bill
	setcolor(WHITE);
	bar3d(220,150,270,220,5,1);
	rectangle(225,159,265,215);
	settextstyle(2,0,3);
	outtextxy(222,150,"    SONY");
	setcolor(YELLOW);
	settextstyle(1,0,1);
	outtextxy(360,150,"PRICE :INR 33,990(25% off)");
	settextstyle(2,0,4);
	outtextxy(360,170,"32 GB,1GHz Snapdragon Processor");
	outtextxy(360,180,"Kitkat");
	setcolor(RED);
	settextstyle(3,0,4);
	outtextxy(25,230,"2.SAMSUNG");
	//showmouseptr for coordinates above and if clicked call bill
	setcolor(WHITE);
	bar3d(220,240,270,310,5,1);
	rectangle(225,248,265,305);
	settextstyle(2,0,3);
	outtextxy(222,240,"Samsung");
	setcolor(YELLOW);
	settextstyle(1,0,1);
	outtextxy(360,240,"PRICE :INR 29,990(20% off)");
	settextstyle(2,0,4);
	outtextxy(360,260,"32 GB,1GHz Snapdragon Processor");
	outtextxy(360,270,"Kitkat");

	setcolor(RED);
	settextstyle(3,0,4);
	outtextxy(25,320,"3.APPLE");
	//showmouseptr for coordinates above and if clicked call bill
	setcolor(WHITE);
	bar3d(220,330,270,400,5,1);
	rectangle(225,338,265,390);
	settextstyle(2,0,3);
	outtextxy(222,330,"   Apple");
	circle(245,395,2);
	setcolor(YELLOW);
       settextstyle(1,0,1);
	outtextxy(360,330,"PRICE :INR 59,999(10% off)");
	settextstyle(2,0,4);
	outtextxy(360,350,"32 GB,2GHz Snapdragon Processor");
	outtextxy(360,360,"IOS 7");
	settextstyle(1,0,4);
	outtextxy(0,420,"BACK");
	outtextxy(500,420,"EXIT");

	traverse2=traverse1->link11;
		initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		if(o.x.cx>=0&&o.x.cx<=60)
		{

			if(o.x.dx>=415&&o.x.dx<=450)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					 electronics();
				}
		       }
	      }
	      if(o.x.cx>=500&&o.x.cx<=560)
		{

	      if(o.x.dx>=420&&o.x.dx<=440)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					 bill();
				}
		       }
	      }

		if(o.x.cx>=25&&o.x.cx<=120)
		{

			if(o.x.dx>=150&&o.x.dx<=200)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=25493;
				    strcpy(temp2->pname,"SONY TABLETS");
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				   ppush();
				   prpush();
				  delay(1000);
				  tablets();
				   }
		       }
	      }

	      if(o.x.cx>=100&&o.x.cx<=300)
		{

			if(o.x.dx>=240&&o.x.dx<=290)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				   temp1->add=traverse2->next22->name22;
				   temp1->rate=23992;
				   strcpy(temp2->pname,"SAMSUNG TABLETS");
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  tablets();
				   }
		       }
	      }

	      if(o.x.cx>=25&&o.x.cx<=120)
		{

			if(o.x.dx>=320&&o.x.dx<=360)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->next22->name22;
				    temp1->rate=54000;
				    strcpy(temp2->pname,"APPLE TABLETS");
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  tablets();
				   }
		       }
	      }
	 }


}
void laptops()
{          int j,m;
	int p[]={180,210,130,240,40,240,90,210,180,210};
	int p1[]={40,240,40,245,132,245,182,215,180,210};
	int q[]={180,360,130,390,40,390,90,360,180,360};
	int q1[]={40,390,40,395,132,395,182,365,180,360};
	int choice;
       //	int gd=DETECT,gm;
	clearviewport();
	// initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	 setbkcolor(13);
       setfillstyle(0,BLUE);
       settextstyle(7,0,8);
       setcolor(4);
       outtextxy(70,20,"LAPTOPS");
       settextstyle(1,0,3);
       setcolor(YELLOW);
       for(j=0;j<30;j++)
       {
       line(250,150+j,350,150+j);
       delay(30);
       }
       setcolor(BLUE);
       outtextxy(250,150," DELL ");
       //showmouseptr for coordinates above and if clicked call bill
       settextstyle(1,0,2);
       outtextxy(370,150,"PRICE: INR 42,999");
       settextstyle(2,0,4);
       outtextxy(370,180,"I5-3rd GEN,4 GB RAM,1 TB HD");
       outtextxy(370,190,"2 GB ATI Radeon 8670 M");
       settextstyle(3,0,5);
       outtextxy(0,420,"BACK");

       outtextxy(500,420,"EXIT");
       setcolor(WHITE);
       bar3d(90,150,180,210,5,1);
       drawpoly(4,p);
       drawpoly(5,p1);
				 //// changes strtd in laptp////
       for(m=0;m<=80;m=m+5)
       line(95+m,210,45+m,240);

       line(80,215,170,215);
       line(72,220,162,220);
       line(64,225,152,225);
       line(56,230,144,230);
       line(48,235,135,235);
			   ///   changes end         ///

       setcolor(YELLOW);
	for(j=0;j<30;j++)
       {
       line(250,300+j,350,300+j);
       delay(25);
       }
       settextstyle(1,0,3);
       setcolor(BLUE);
       outtextxy(250,300," APPLE ");
	 //showmouseptr for coordinates above and if clicked call bill
	 settextstyle(1,0,2);
       outtextxy(370,290,"PRICE: INR 86,999");
       settextstyle(2,0,4);
       outtextxy(370,320,"I7-3rd GEN,6 GB RAM,1 TB HD");
       outtextxy(370,330,"2 GB NVIDIA GetForce 660");
       setcolor(8);
       bar3d(90,300,180,360,5,1);
       drawpoly(4,q);
       drawpoly(5,q1);

       //// changes started///
	for(m=0;m<=80;m=m+5)
       line(95+m,360,45+m,390);

       line(80,365,170,365);
       line(72,370,162,370);
       line(64,375,152,375);
       line(56,380,144,380);
       line(48,385,135,385);
			      ////changes end ////

       traverse2=traverse1->link11;

	initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		if(o.x.cx>=0&&o.x.cx<=60)
		{

			if(o.x.dx>=415&&o.x.dx<=450)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					electronics();
				}
		       }
	      }

	      if(o.x.cx>=500&&o.x.cx<=570)
		{

			if(o.x.dx>=420&&o.x.dx<=470)
			{


				if(o.x.bx==1)
				{
				      hidemouseptr();
					bill();
				}
		       }
	      }

		if(o.x.cx>=250&&o.x.cx<=300)
		{

			if(o.x.dx>=150&&o.x.dx<=200)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=42199;
				    strcpy(temp2->pname,"DELL LAPTOP");
				     settextstyle(1,0,3);
				    setcolor(BLUE);

				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
					ppush();
				  prpush();
				  delay(1000);
				  laptops();
				   }
		       }
	      }


	      if(o.x.cx>=250&&o.x.cx<=310)
		{

			if(o.x.dx>=300&&o.x.dx<=350)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=86999;
				    strcpy(temp2->pname,"APPLE LAPTOP");
				    settextstyle(1,0,3);
				    setcolor(BLUE);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  laptops();
				   }
		       }
	      }
	 }





}


void speakers()
{
	clearviewport();
	  setbkcolor(BROWN);
       setfillstyle(0,BLUE);
       settextstyle(7,0,8);
       setcolor(1);
       outtextxy(30,20,"SPEAKERS");
       settextstyle(1,0,3);
       setcolor(YELLOW);
      //1st speaker
       bar3d(30,150,90,250,15,1);
       bar3d(90,200,150,250,15,1);
       bar3d(150,150,210,250,15,1);
       circle(60,170,10);
       circle(45,180,4);
       circle(75,180,4);
       circle(60,220,7);
       circle(60,240,4);
       rectangle(95,220,145,225);

       circle(180,170,10);
       circle(165,180,4);
       circle(195,180,4);
       circle(180,220,7);
       circle(180,240,4);
	setcolor(BLUE);
      settextstyle(1,0,1);
      outtextxy(50,270,"PANASONIC A-5300 ");
      //showmouseptr for coordinates above and if clicked call bill
      outtextxy(45,290,"Home Theatre System");
      settextstyle(2,0,5);
      outtextxy(50,330,"Rs.5799(21% off)");
      outtextxy(50,330,"   ----");
      outtextxy(50,350,"Price: Rs.4675");
      outtextxy(50,370," Instaback ");
      outtextxy(50,380," Rs. 100 ");


       // 2nd speakr
       setcolor(YELLOW);
       bar3d(300,150,360,250,15,1);
       bar3d(370,170,430,250,20,1);
       circle(330,180,20);
       circle(330,230,15);
 circle(400,200,20);
       circle(380,240,3);
       circle(390,240,3);
       circle(400,240,3);
       circle(410,240,3);
      circle(420,240,3);
       setcolor(BLUE);
      settextstyle(1,0,1);
      outtextxy(300,270,"Intex IT-2000");
      //showmouseptr for coordinates above and if clicked call bill
      outtextxy(300,290,"Multimedia speakers");
      settextstyle(2,0,5);
      outtextxy(300,330,"Rs.1630(29% off)");
      outtextxy(300,330,"   ----");
      outtextxy(300,350,"Price: Rs.1159");
      outtextxy(300,370," Instaback ");
      outtextxy(300,380," Rs. 150 ");


		// 3rd speaker
      setcolor(YELLOW);
      bar3d(520,140,590,250,20,1);
      rectangle(545,140,565,200);
      circle(555,150,2);
      circle(555,160,2);
      circle(555,180,5);
      circle(555,225,15);
      setcolor(BLUE);
      settextstyle(1,0,1);
      outtextxy(515,270,"iBall Q9-2.1");
      //showmouseptr for coordinates above and if clicked call bill
      outtextxy(515,290,"speakers");
      settextstyle(2,0,5);
      outtextxy(515,330,"Rs.1599(26% off)");
      outtextxy(515,330,"   ----");
      outtextxy(515,350,"Price: Rs.1199");
      outtextxy(515,370," Instaback ");
      outtextxy(515,380," Rs. 100 ");

      settextstyle(1,0,1);
      setcolor(15);
      outtextxy(30,450,"Back");
      outtextxy(560,450,"EXIT" );
      traverse2=traverse1->link11;
       initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		if(o.x.cx>=30&&o.x.cx<=200)
		{

			if(o.x.dx>=450&&o.x.dx<=490)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					electronics();
				}
		       }
	      }
		if(o.x.cx>=560&&o.x.cx<=600)
		{

			if(o.x.dx>=450&&o.x.dx<=510)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
	      }


		if(o.x.cx>=50&&o.x.cx<=220)
		{

			if(o.x.dx>=270&&o.x.dx<=350)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=4675;
				    strcpy(temp2->pname,"PANASONIC HOME THEATRE");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  speakers();
				   }
		       }
	      }

	      if(o.x.cx>=300&&o.x.cx<=480)
		{

			if(o.x.dx>=270&&o.x.dx<=370)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=1159;
				    strcpy(temp2->pname,"INTEX IT SPEAKERS");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  speakers();
				   }
		       }
	      }

	      if(o.x.cx>=515&&o.x.cx<=600)
		{

			if(o.x.dx>=270&&o.x.dx<=330)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->next22->name22;
				    temp1->rate=1199;
				    strcpy(temp2->pname,"IBALL Q SPEAKERS");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  speakers();
				   }
		       }
	      }

       }
 }


 //********men************
//front
void men()
{
	int g;
	cleardevice();
	setbkcolor(6);
	settextstyle(10,0,5);
	outtextxy(100,50,"MEN'S SECTION");
	setfillstyle(8,3);
	bar(70,40,615,180);
	outtextxy(80,80,"______________");
	settextstyle(7,0,3);
	outtextxy(170,250,"1. Trousers");
	outtextxy(170,290,"2. T-Shirts");
	outtextxy(170,330,"3. Neckties & Belts");
	for(g=0;g<15;g=g+2)
	{
		settextstyle(10,0,5);
		setcolor(g);
		outtextxy(100,50,"MEN'S SECTION");
		delay(200);
	}

	settextstyle(1,0,1);
	setcolor(RED);
	outtextxy(550,450,"EXIT");
	outtextxy(70,450,"BACK");
	setcolor(RED);
	setfillstyle(1,15);
	circle(92,480,50);
	floodfill(92,460,RED);
	setfillstyle(1,15);
	circle(571,480,50);
	floodfill(613,460,RED);
	traverse1=men1;
	 initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		if(o.x.cx>=170&&o.x.cx<=250)
		{

			if(o.x.dx>=250&&o.x.dx<=280)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					trouser();
				}
		       }
	      }
		if(o.x.cx>=170&&o.x.cx<=350)
		{

			if(o.x.dx>=330&&o.x.dx<=360)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					traverse1=traverse1->down11->down11;
					tie();
				}
		       }
	      }
	     if(o.x.cx>=170&&o.x.cx<=300)
		{

			if(o.x.dx>=290&&o.x.dx<=335)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					traverse1=traverse1->down11;
					tshirt();
				}
		       }
		 }

		if(o.x.cx>=70&&o.x.cx<=100)
		{


			if(o.x.dx>=450&&o.x.dx<=500)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					category();
				}
		       }
		 }

		 if(o.x.cx>=550&&o.x.cx<=600)
		{

			if(o.x.dx>=450&&o.x.dx<=490)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
		 }

	}
}



void trouser()
{
	int g=0,j=0,x,y,w,k;
	int points[]={38,50,35,200,60,200,75,78,90,200,115,200,112,50,35,50};
	int p2[]={38+127,50+230,35+127,200+230,60+127,200+230,75+127,78+230,90+127,200+230,115+127,200+230,112+127,50+230,35+127,50+230};
	int p1[]={38+250,50,35+250,200,60+250,200,75+250,78,90+250,200,115+250,200,112+250,50,35+250,50};
	 cleardevice();
	g=0;j=0;
	setfillstyle(9,BROWN);
	fillpoly(8,points);
	setfillstyle(11,BROWN);
	rectangle(g+73,g+50,g+77,g+75);
	bar(g+38,g+40,g+112,g+50);
	rectangle(g+38,j+40,g+112,j+50);
	setbkcolor(BLACK);
	circle(g+78,j+43,2);
	line(g+38,j+50,g+38,j+70);
	line(g+38,j+70,g+45,j+50);
	line(g+45,j+50,g+38,j+50);
	line(g+112,j+50,g+112,j+70);
	line(g+112,j+70,g+105,j+50);
	line(g+105,j+50,g+112,j+50);
	g=250,j=0;
	setfillstyle(1,8);
	fillpoly(8,p1);
	setfillstyle(2,6);
	rectangle(g+73,j+50,g+77,j+75);
	bar(g+38,j+40,g+112,j+50);
	rectangle(g+38,j+40,g+112,j+50);
	circle(g+78,j+43,2);
	line(g+38,j+50,g+38,j+70);
	line(g+38,j+70,g+45,j+50);
	line(g+45,j+50,g+38,j+50);
	line(g+112,j+50,g+112,j+70);
	line(g+112,j+70,g+105,j+50);
	line(g+105,j+50,g+112,j+50);
	g=127,j=230;
	setfillstyle(1,15);
	fillpoly(8,p2);
	setfillstyle(2,3);
	rectangle(g+73,j+50,g+77,j+75);
	bar(g+38,j+40,g+112,j+50);
	rectangle(g+38,j+40,g+112,j+50);
	circle(g+78,j+43,2);
	line(g+38,j+50,g+38,j+70);
	line(g+38,j+70,g+45,j+50);
	line(g+45,j+50,g+38,j+50);
	line(g+112,j+50,g+112,j+70);
	line(g+112,j+70,g+105,j+50);
	line(g+105,j+50,g+112,j+50);
	settextstyle(7,3,2);
	setcolor(3);
	outtextxy(610,10,"M  E  N ' S   -   S  E  C  T  I  O  N");
	line(603,0,603,540);
	line(600,0,600,540);
	setcolor(4);
	settextstyle(1,0,1);
	outtextxy(135,120,"PRICE");
	line(135,140,200,140);
	outtextxy(400,120,"PRICE");
	line(400,140,465,140);
	outtextxy(310,340,"PRICE");
	line(310,360,375,360);
	settextstyle(2,0,5);
	outtextxy(135,150,"Rs. 715");
	outtextxy(400,150,"Rs. 1199");
	outtextxy(310,375,"Rs. 905");
	setcolor(5);
	outtextxy(135,170,"(Rs. 1429)-49%OFF");
	line(135,175,210,180);
	outtextxy(400,170,"(NO DISCOUNT)");
	outtextxy(310,395,"(Rs. 1509)-40% OFF");
	line(310,400,380,405);
	setcolor(2);
	settextstyle(11,0,1);
	outtextxy(135,80,"SLIM FIT");
	//showmuseptr for coordinate above and if clicked call bill
	outtextxy(310,300,"REGULAR FIT MEN'S TROUSERS");
	//showmuseptr for coordinate above and if clicked call bill
	outtextxy(400,80,"NARROW BOTTOM TROUSER");
	//showmuseptr for coordinate above and if clicked call bill
	for(g=11;g>0;g--)
	{
		settextstyle(7,3,1);
		setcolor(g);
		outtextxy(570,10,"           T   R   O   U   S   E   R   S    ");
		delay(50);
	}
	setcolor(5);
	setfillstyle(1,15);
	circle(92,480,50);
	floodfill(92,460,5);
	setcolor(5);
	setfillstyle(1,15);
	circle(613-80,480,50);
	floodfill(613-80,460,5);
	settextstyle(1,0,1);
	outtextxy(505,450,"EXIT");
	outtextxy(70,450,"BACK");
	traverse2=traverse1->link11;
	   initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);

	if(o.x.cx>=70&&o.x.cx<=150)
		{

			if(o.x.dx>=445&&o.x.dx<=485)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					men();
				}
		       }
		 }
	     if(o.x.cx>=505&&o.x.cx<=545)
		{

			if(o.x.dx>=445&&o.x.dx<=485)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
		 }

		if(o.x.cx>=135&&o.x.cx<=220)
		{

			if(o.x.dx>=80&&o.x.dx<=105)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=715;
				    strcpy(temp2->pname,"SLIM FIT TROUSER");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  trouser();
				   }
		       }
	      }

	      if(o.x.cx>=310&&o.x.cx<=390)
		{

			if(o.x.dx>=300&&o.x.dx<=330)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=1199;
				    strcpy(temp2->pname,"REGULAR FIT");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  trouser();
				   }
		       }
	      }

	      if(o.x.cx>=400&&o.x.cx<=520);
		{

			if(o.x.dx>=80&&o.x.dx<=110)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->next22->name22;
				    temp1->rate=905;
				    strcpy(temp2->pname,"NARROW BOTTOM TROUSER");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  trouser();
				   }
		       }
	      }


	    }

}


void tshirt()            //tee
{
	int z[]={85,100,50,106,29,140,54,145,62,130,62,250,142,250,142,130,147,145,170,140,150,106,115,100};
	int s[]={85+230,100,50+230,106,29+230,140,54+230,145,62+230,130,62+230,250,142+230,250,142+230,130,147+230,145,170+230,140,150+230,106,115+230,100};
	int w[]={85+430,100,50+430,106,29+430,140,54+430,145,62+430,130,62+430,250,142+430,250,142+430,130,147+430,145,170+430,140,150+430,106,115+430,100};
	int y=125,g;
	cleardevice();
	setfillstyle(1,3);
	fillpoly(12,z);
	setfillstyle(1,WHITE);
	fillellipse(100,105,15,12);
	ellipse(100,105,0,360,17,14);
	setfillstyle(1,5);
	bar(80,145,124,165);
	settextstyle(3,0,1);
	outtextxy(82,140," Lee");
	settextstyle(2,0,4);
	outtextxy(30,260,"Lee men's round neck T-shirt");
	//showmuseptr for coordinate above and if clicked call bill
	setcolor(4);
	settextstyle(1,0,1);
	outtextxy(60,300,"PRICE");
	line(60,320,130,320);
	setcolor(WHITE);
	settextstyle(1,0,2);
	outtextxy(65,340,"Rs. 359");
	setcolor(6);
	settextstyle(2,0,6);
	outtextxy(55,380,"(Rs. 399)-10% OFF");
	line(70,380,150,400);

	g=230;
	setfillstyle(6,4);
	fillpoly(12,s);
	setfillstyle(1,WHITE);
	fillellipse(100+g,105,15,12);
	ellipse(100+g,105,0,360,17,14);
	setcolor(3);
	line(100+g,120,100+g,170);
	for(g=0;g<4;g++,y=y+15)
		circle(105+230,y,2);
	setbkcolor(1);
	setcolor(4);
	settextstyle(1,0,1);
	outtextxy(300,300,"PRICE");
	line(300,320,370,320);
	setcolor(WHITE);
	settextstyle(2,0,4);
	outtextxy(260,260,"Men's polo neck T-shirt");
	//showmuseptr for coordinate above and if clicked call bill
	setcolor(WHITE);
	settextstyle(1,0,2);
	outtextxy(300,340,"Rs. 749");
	setcolor(6);
	settextstyle(2,0,6);
	outtextxy(290,380,"(Rs. 999)-25% OFF");
	line(310,380,370,400);

	g=430;
	setfillstyle(9,7);
	fillpoly(12,w);
	setfillstyle(1,WHITE);
	fillellipse(100+g,105,15,12);
	ellipse(100+g,105,0,360,17,14);
	setcolor(6);
	settextstyle(1,0,1);
	outtextxy(82+g,140,"KEEP");
	outtextxy(82+g,160,"CALM");
	outtextxy(80+g,180,"----");
	outtextxy(80+g,185,"----");
	setcolor(4);
	settextstyle(1,0,1);
	outtextxy(500,300,"PRICE");
	line(500,320,570,320);
	setcolor(WHITE);
	settextstyle(2,0,4);
	outtextxy(440,260,"Printed Men's round neck T-shirt");
	//showmuseptr for coordinate above and if clicked call bill
	setcolor(WHITE);
	settextstyle(1,0,2);
	outtextxy(500,340,"Rs. 349");

	settextstyle(5,0,2);
	setcolor(3);
	outtextxy(70,5,"M  E  N ' S   -   S  E  C  T  I  O  N");
	setcolor(WHITE);
	line(0,35,640,35);
	line(0,440,640,440);
	line(0,435,640,435);
	for(g=10;g>3;g--)
	{
		settextstyle(7,0,1);
		setcolor(g);
		outtextxy(70,440,"           T   -   S   H   I   R   T   S    ");
		delay(50);
	}

	settextstyle(1,0,1);
	setcolor(WHITE);
	outtextxy(550,450,"EXIT");
	outtextxy(70,450,"BACK");
	setcolor(RED);
	setfillstyle(1,15);
	circle(92,480,50);
	//floodfill(92,460,5);
	setfillstyle(1,15);
	circle(573,480,50);
	traverse2=traverse1->link11;
	initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);

	if(o.x.cx>=70&&o.x.cx<=150)
		{

			if(o.x.dx>=445&&o.x.dx<=485)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					men();
				}
		       }
		 }
	     if(o.x.cx>=545&&o.x.cx<=585)
		{

			if(o.x.dx>=445&&o.x.dx<=485)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
		 }


		if(o.x.cx>=30&&o.x.cx<=170)
		{

			if(o.x.dx>=260&&o.x.dx<=295)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=359;
				    strcpy(temp2->pname,"LEE TSHIRT");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  tshirt();
				   }
		       }
	      }

	      if(o.x.cx>=260&&o.x.cx<=400)
		{

			if(o.x.dx>=260&&o.x.dx<=295)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=749;
				    strcpy(temp2->pname,"POLO TSHIRT");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
					prpush();
				  delay(1000);
				  tshirt();
				   }
		       }
	      }

	      if(o.x.cx>=440&&o.x.cx<=580);
		{

			if(o.x.dx>=260&&o.x.dx<=295)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->next22->name22;
				    temp1->rate=349;
				    strcpy(temp2->pname,"ROUND NECK TSHIRT");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
					prpush();
				  delay(1000);
				  tshirt();
				   }
		       }
	      }



	    }

}

//tie
void tie()
{
	int points[]={123,57,106,155,123,185,138,155,123,57};
	int y,g,p[]={110,50,138,50,123,71,110,50};
	int points1[]={300+123,57,300+106,155,300+123,185,300+138,155,300+123,57};
	int p1[]={300+110,50,300+138,50,300+123,71,300+110,50};
	cleardevice();
	setcolor(WHITE);
	settextstyle(1,3,1);
	setfillstyle(1,9);
	bar3d(90,35,160,200,10,1);
	setfillstyle(6,BLUE);
	fillpoly(5,points);
	fillpoly(4,p);
	line(110,140,135,130);
	line(110,145,135,135);
	setbkcolor(3);
	settextstyle(2,0,5);
	outtextxy(190,60,"ALLEN SOLLY");
	//showmuseptr for coordinate above and if clicked call bill
	outtextxy(190,80,"STRIPES MEN'S TIE");
	//showmuseptr for coordinate above and if clicked call bill
	outtextxy(480,60,"THE VATICAN POLKA");
	//showmuseptr for coordinate above and if clicked call bill
	outtextxy(480,80,"DOTS MEN'S TIE");
	//showmuseptr for coordinate above and if clicked call bill
	setcolor(RED);
	settextstyle(1,0,1);
	outtextxy(190,100,"PRICE");
	line(185,120,250,120);
	setcolor(WHITE);
	outtextxy(190,130,"Rs. 795");
	setcolor(6);
	rectangle(185,100,280,160);

	setcolor(WHITE);

	setfillstyle(1,8);
	bar3d(300+90,35,300+160,200,10,1);
	setfillstyle(1,WHITE);
	setfillstyle(11,RED);
	fillpoly(5,points1);
	fillpoly(4,p1);
	line(300+110,140,300+135,130);
	line(300+110,145,300+135,135);
	settextstyle(2,0,5);
	setcolor(RED);
	settextstyle(1,0,1);
	outtextxy(480,100,"PRICE");
	line(475,120,530,120);
	setcolor(WHITE);
	outtextxy(480,130,"Rs. 399");
	setcolor(6);
	rectangle(475,100,634,185);
	outtextxy(475,150,"Rs. 499 -20%OFF");
	setcolor(WHITE);
	line(500,155,550,170);
	setfillstyle(1,8);
	rectangle(248-50,260,268-50,280);
	rectangle(246-50,258,270-50,282);
	rectangle(255-50,270,260-50,280);
	bar(250-50,280,266-50,470);
	  y=400;
	for(g=0;g<4;g++,y=y+15)
		circle(260-50,y,2);
	setfillstyle(1,8);
	rectangle(248,260,268,280);
	rectangle(246,258,270,282);
	rectangle(255,270,260,280);
	bar(250,280,266,470);
	y=400;
	for(g=0;g<4;g++,y=y+15)
		circle(260,y,2);
	setfillstyle(9,4);
	rectangle(50+248,260,50+268,280);
	rectangle(50+246,258,50+270,282);
	rectangle(50+255,270,50+260,280);
	bar(50+250,280,50+266,470);
	y=400;
	for(g=0;g<4;g++,y=y+15)
		circle(50+260,y,2);
	settextstyle(1,0,1);
	setcolor(RED);
	outtextxy(350,300,"HEAVY DISCOUNT");
	outtextxy(343,320,"--------------");
	settextstyle(2,0,5);
	setcolor(WHITE);
	outtextxy(370,340,"WOODLAND BELTS");
	settextstyle(1,0,1);
	setcolor(RED);
	outtextxy(370,360,"PRICE");
	line(367,380,440,380);
	setcolor(6);
	outtextxy(365,420,"(BUY 2 GET 1 FREE)");
	settextstyle(1,0,3);
	setcolor(WHITE);
	outtextxy(367,400,"Rs. 499");
	rectangle(363,363,560,450);
	for(g=10;g>4;g--)
	{
		settextstyle(7,1,2);
		setcolor(g);
		outtextxy(5,50,"A  C  C  E  S  S  O  R  I  E  S");
		delay(200);
	}
	settextstyle(1,0,1);
	outtextxy(585,450,"EXIT");
	outtextxy(70,450,"BACK");
	setfillstyle(1,15);
	circle(92,480,50);
	floodfill(92,460,5);
	setfillstyle(1,15);
	circle(613,480,50);
	floodfill(613,460,5);
	traverse2=traverse1->link11;
	initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);

	if(o.x.cx>=70&&o.x.cx<=150)
		{

			if(o.x.dx>=445&&o.x.dx<=485)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					men();
				}
		       }
		 }
	     if(o.x.cx>=580&&o.x.cx<=630)
		{

			if(o.x.dx>=445&&o.x.dx<=485)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
		 }

		if(o.x.cx>=190&&o.x.cx<=270)
		{

			if(o.x.dx>=60&&o.x.dx<=100)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=795;				    strcpy(temp2->pname,"LEE TSHIRT");
				     strcpy(temp2->pname,"ALLEN SOLLY TIE");
				    settextstyle(1,0,3);

				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  tie();
				   }
		       }
	      }

	      if(o.x.cx>=480&&o.x.cx<=570)
		{

			if(o.x.dx>=60&&o.x.dx<=115)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=399;
				    strcpy(temp2->pname,"VATICAN POLKADOT TIE");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  tie();
				   }
		       }
	      }

	      if(o.x.cx>=370&&o.x.cx<=480);
		{

			if(o.x.dx>=340&&o.x.dx<=385)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->next22->name22;
				    temp1->rate=499;
				    strcpy(temp2->pname,"WOODLAND BELTS");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  tie();
				   }
		       }
	      }



	    }

}


//********women********
 void women()
{
	char ch;
	int j;

	clearviewport();
	setbkcolor(LIGHTMAGENTA);
    //	settextstyle(7,0,8);
	for(j=1;j<13;j++)
	{       setcolor(j%5);
		delay(100);
		settextstyle(7,0,8);
		outtextxy(48,100,"~~~~~~");
		outtextxy(50,50,"WOMEN");
	}
	setcolor(RED);
	settextstyle(8,0,4);
	for(j=0;j<5;j++)
	{
		delay(200);
		outtextxy(j+1,195,"1.Jeans");
		outtextxy(j+1,250,"2.Kurti");
		outtextxy(j+1,305,"3.Accessories");
	}
	delay(800);
	setcolor(BLUE);
	settextstyle(1,0,3);
	outtextxy(5,380,"Click any and get the availing offers...hurry!");
	setcolor(GREEN);
	delay(800);
	outtextxy(6,450,"BACK");
	outtextxy(550,450,"EXIT");
	traverse1=women1;
		initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);

		if(o.x.cx>=5&&o.x.cx<=100)
		{

			if(o.x.dx>=195&&o.x.dx<230)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					 jeans();
				}
		       }
	      }
	      if(o.x.cx>=3&&o.x.cx<=200)
		{

			if(o.x.dx>=250&&o.x.dx<285)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					traverse1=traverse1->down11;
					 kurti();
				}
		       }
	      }
	      if(o.x.cx>=5&&o.x.cx<=200)
		{

			if(o.x.dx>=305&&o.x.dx<345)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					traverse1=traverse1->down11->down11;
					bag();
				}
		       }
	      }
		if(o.x.cx>=6&&o.x.cx<=100)
		{

			if(o.x.dx>=450&&o.x.dx<490)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					 category();
				}
		       }
	      }
	      if(o.x.cx>=550&&o.x.cx<=590)
		{

			if(o.x.dx>=450&&o.x.dx<=490)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
	      }
	 }

}
void jeans()
{
	char choice;
	int l=0,j=0,x,y,w,k;
	int points[]={38,50,43,200,60,200,75,78,90,200,107,200,112,50,38,50};
	int p2[]={38+127,50+230,43+127,200+230,60+127,200+230,75+127,78+230,90+127,200+230,107+127,200+230,112+127,50+230,35+127,50+230};
	int p1[]={38+250,50,43+250,200,60+250,200,75+250,78,90+250,200,107+250,200,112+250,50,35+250,50};

	clearviewport();
	setcolor(BROWN);
	settextstyle(5,0,4);
	outtextxy(530,40,"HURRY!");
	outtextxy(530,100,"Limited");
	outtextxy(530,140,"Stock");
	outtextxy(530,180,"Only...");
	setcolor(YELLOW);
	settextstyle(3,0,3);
	outtextxy(10,400,"BACK");
	outtextxy(540,400,"EXIT");
	setcolor(MAGENTA);
	setfillstyle(1,12);
	fillpoly(8,points);
	setfillstyle(11,BROWN);
	rectangle(l+73,j+50,l+77,j+75);
	bar(l+38,j+40,l+112,j+50);
	rectangle(l+38,j+40,l+112,j+50);
	setbkcolor(BLACK);
	circle(l+78,j+43,2);
	line(l+38,j+50,l+38,j+70);
	line(l+38,j+70,l+45,j+50);
	line(l+45,j+50,l+38,j+50);
	line(l+112,j+50,l+112,j+70);
	line(l+112,j+70,l+105,j+50);
	line(l+105,j+50,l+112,j+50);
	l=250,j=0;
	setfillstyle(1,9);
	fillpoly(8,p1);
	setfillstyle(2,10);
	rectangle(l+73,j+50,l+77,j+75);
	bar(l+38,j+40,l+112,j+50);
	rectangle(l+38,j+40,l+112,j+50);
	circle(l+78,j+43,2);
	line(l+38,j+50,l+38,j+70);
	line(l+38,j+70,l+45,j+50);
	line(l+45,j+50,l+38,j+50);
	line(l+112,j+50,l+112,j+70);
	line(l+112,j+70,l+105,j+50);
	line(l+105,j+50,l+112,j+50);
	l=127,j=230;
	setfillstyle(1,10);
	fillpoly(8,p2);
	setfillstyle(2,3);
	rectangle(l+73,j+50,l+77,j+75);
	bar(l+38,j+40,l+112,j+50);
	rectangle(l+38,j+40,l+112,j+50);
	circle(l+78,j+43,2);
	line(l+38,j+50,l+38,j+70);
	line(l+38,j+70,l+45,j+50);
	line(l+45,j+50,l+38,j+50);
	line(l+112,j+50,l+112,j+70);
	line(l+112,j+70,l+105,j+50);
	line(l+105,j+50,l+112,j+50);
	settextstyle(7,3,2);
	setcolor(3);

	line(525,0,525,540);
	line(527,0,527,540);
	for(l=11;l>0;l--)
	{
		settextstyle(7,3,1);
		setcolor(l);
		outtextxy(2,10,"           J   E   A   N   S       ");
		delay(50);
	}
	setcolor(4);
	settextstyle(1,0,1);
	outtextxy(135,120,"PRICE");
	line(135,140,200,140);
	outtextxy(400,120,"PRICE");
	line(400,140,465,140);
	outtextxy(310,340,"PRICE");
	line(310,360,375,360);
	settextstyle(2,0,5);
	outtextxy(135,150,"Rs. 500");
	outtextxy(400,150,"Rs. 1199");
	outtextxy(310,375,"Rs. 905");
	setcolor(5);
	outtextxy(135,170,"(Rs. 1000)-50%OFF");
	line(135,175,210,180);
	outtextxy(400,170,"(NO DISCOUNT)");
	outtextxy(310,395,"(Rs. 1509)-40% OFF");
	line(310,400,380,405);
	setcolor(2);
	settextstyle(11,0,1);
	outtextxy(135,80,"SLIM FIT JEANS");
	//showmouseptr for coordinates above and if clicked call bill
	outtextxy(310,300,"MOSSMIO REGULAR FIT JEANS");
	//showmouseptr for coordinates above and if clicked call bill
	outtextxy(400,80,"SKINNY JEANS");
	//showmouseptr for coordinates above and if clicked call bill
	traverse2=traverse1->link11;
	initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);

		if(o.x.cx>=10&&o.x.cx<=60)
		{

			if(o.x.dx>=400&&o.x.dx<440)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					 women();
				}
		       }
	      }
	      if(o.x.cx>=540&&o.x.cx<=590)
		{

			if(o.x.dx>=400&&o.x.dx<440)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					 bill();
				}
		       }
	      }

		if(o.x.cx>=135&&o.x.cx<=210)
		{

			if(o.x.dx>=80&&o.x.dx<=130)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=500;				    strcpy(temp2->pname,"LEE TSHIRT");
				     strcpy(temp2->pname,"SLIM FIT JEANS");
				    settextstyle(1,0,3);

				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  jeans();
				   }
		       }
	      }

	      if(o.x.cx>=400&&o.x.cx<=490)
		{

			if(o.x.dx>=80&&o.x.dx<=125)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=1199;
				    strcpy(temp2->pname,"SKINNY JEANS");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  jeans();
				   }
		       }
	      }

	      if(o.x.cx>=300&&o.x.cx<=400);
		{

			if(o.x.dx>=300&&o.x.dx<=345)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->next22->name22;
				    temp1->rate=499;
				    strcpy(temp2->pname,"MOSSMIO FIT JEANS");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  jeans();
				   }
		       }
	      }

	}
}
void kurti()
{
	char choice;
	int j;
	clearviewport();
	setbkcolor(LIGHTRED);
	setfillstyle(5,1);
	setcolor(GREEN);
	ellipse(50,60,270,90,10,30);
	line(50,90,20,300);
	line(20,300,180,300);
	line(180,300,150,90);
	ellipse(150,60,90,270,10,30);
	line(50,30,80,30);
	line(150,30,120,30);
	arc(100,30,180,360,20);
	//select any coordinate say(20,300) and (150,30) and showmouseptr and if clicked call bill
	floodfill(56,100,GREEN);
	for(j=1;j<10;j++)
	{
		delay(50);
		setcolor(j%5);
	settextstyle(8,0,5);
	outtextxy(300,40,"K");
	outtextxy(300,100,"U");
	outtextxy(300,160,"R");
	outtextxy(300,220,"T");
	outtextxy(300,280,"I");
	}
	setcolor(LIGHTMAGENTA);
	setfillstyle(8,8);
	ellipse(50+400,60,270,90,10,30);
	line(50+400,90,20+400,300);
	line(20+400,300,180+400,300);
	line(180+400,300,150+400,90);
	ellipse(150+400,60,90,270,10,30);
	line(50+400,30,80+400,30);
	line(150+400,30,120+400,30);
	line(480,30,500,70);
	line(520,30,500,70);
	//select any coordinate say(20,300) and (150,30) and showmouseptr and if clicked call bill
	floodfill(460,100,LIGHTMAGENTA);
	setcolor(6);
	settextstyle(5,0,3);
	outtextxy(40,320,"COTTON KURTI");
	delay(50);
	setcolor(9);
	settextstyle(5,0,3);
	outtextxy(40,340,"Rs.499 only");
	setcolor(6);
	settextstyle(2,0,5);
	delay(50);
	setcolor(6);
	settextstyle(5,0,3);
	outtextxy(400,320,"SILK KURTI");
	outtextxy(400,380,"Rs.800 only");
	setcolor(RED);
	settextstyle(5,0,3);
	outtextxy(6,420,"BACK");
	outtextxy(500,420,"EXIT");
	traverse2=traverse1->link11;
	initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);

		if(o.x.cx>=6&&o.x.cx<=60)
		{

			if(o.x.dx>=420&&o.x.dx<450)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					 women();
				}
		       }
	      }
	      if(o.x.cx>=500&&o.x.cx<=560)
		{

			if(o.x.dx>=420&&o.x.dx<=450)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
	      }


		if(o.x.cx>=40&&o.x.cx<=210)
		{

			if(o.x.dx>=320&&o.x.dx<=370)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=499;				    strcpy(temp2->pname,"LEE TSHIRT");
				     strcpy(temp2->pname,"COTTON KURTI");
				    settextstyle(1,0,3);

				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
					prpush();
				  delay(1000);
				  kurti();
				   }
		       }
	      }

	      if(o.x.cx>=400&&o.x.cx<=560)
		{

			if(o.x.dx>=340&&o.x.dx<=375)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=800;
				    strcpy(temp2->pname,"SILK KURTI");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  kurti();
				   }
		       }
	      }



      }

}
void bag()

{

	int h;
	int p1[]={20+300,100,40+300,180,150+300,180,170+300,100};
      clearviewport();
	setbkcolor(12);
	setcolor(RED);
	setfillstyle(1,6);
	ellipse(120,90,180,0,60,20);
	line(60,90,60,180);
	line(180,90,180,180);
	ellipse(120,180,180,0,60,20);
	ellipse(120,105,0,180,35,60);
	ellipse(120,102,0,180,45,70);
	ellipse(120,110,180,0,60,20);
	ellipse(120,115,180,0,60,20);
	//showmouseptr for coordinates :(ellipse(120,90,180,0,60,20) and ellipse(120,115,180,0,60,20); and if clicked then call bill
	floodfill(63,100,RED);
	floodfill(70,170,RED);
	setfillstyle(7,5);
	bar(62,140,178,184);
	bar(90,150,150,180);
	fillellipse(120,165,7,7);
	line(360,100,365,50);
	line(365,50,425,50);
	line(425,50,430,100);
	line(350,100,360,40);
	line(360,40,430,40);
	line(430,40,440,100);
	setfillstyle(2,5);
	fillpoly(4,p1);
	settextstyle(4,0,3);
	setcolor(RED);
	outtextxy(4,20,"B");
	outtextxy(4,60,"A");
	outtextxy(4,100,"G");
	outtextxy(4,140,"S");
	settextstyle(7,0,3);
	setcolor(7);
	outtextxy(600,215,"W");
	outtextxy(600,255,"A");
	outtextxy(600,295,"T");
	outtextxy(600,335,"C");
	outtextxy(600,375,"H");
	outtextxy(600,415,"E");
	outtextxy(600,455,"S");
	setcolor(GREEN);
	settextstyle(7,0,2);
	delay(500);
	outtextxy(300,200,"GUCCI");
	outtextxy(350,230,"Rs 1499 only");
	outtextxy(20,200,"PRADA");
	outtextxy(70,230,"Rs 1799 only");
	setcolor(MAGENTA);
	delay(1000);
	outtextxy(380,300,"Titan offer!!");
	delay(1000);
	setcolor(BLUE);
	outtextxy(380,345,"ONE ON ONE");
	outtextxy(400,387,"''PURCHASE''");
	outtextxy(450,410,"Rs 2999 only");
	setcolor(WHITE);
	setfillstyle(1,1);
	circle(180,350,30);
	circle(180,350,35);
	floodfill(180-20,350-20,WHITE);
	circle(180,350,4);
	setfillstyle(8,6);
	rectangle(70,350-20,180-35,350+24);
	floodfill(75,350-20+10,WHITE);
	rectangle(180+35,350-20,350,350+24);
	floodfill(180+38,350-20+10,WHITE);
	rectangle(180-150,350-24,72,350+28);
	rectangle(180-150-3,350-24-3,72+3,350+28+3);
	rectangle(180-150+20,350-24+30,72,350+28-30);
	rectangle(180-150+60,350-24,72+24,350+28);
	rectangle(180-150+60+10,350-24,72+24+10,350+28);
	line(180,350,182,350-28);
	line(180,350,182+5,350-14);
	//showmouseptr for the coordinates shown rectangle(180+35,350-20,350,350+24) and rectangle(180-150,350-24,72,350+28); if clicked call bill.
	for(h=0;h<60;h=h+13)
		circle(280+h,352,3);
	outtextxy(178,350-28-13,"*");
	outtextxy(178,348+24-13,"*");
	outtextxy(178-24,348-13,"*");
	outtextxy(178+22,348-13,"*");

	setfillstyle(1,RED);
	rectangle(180+60-33,350+80-35,180+60+33,350+80+35);
	rectangle(180+60-30,350+80-32,180+60+30,350+80+32);
	floodfill(180+60-30+10,350+80-32+10 ,WHITE);
	circle(180+60,350+80,4);
	setfillstyle(9,YELLOW);
	rectangle(70+60,350-20+80,180-35+60,350+24+80);
	floodfill(75+60,350-20+10+80,WHITE);
	rectangle(180+35+60,350-20+80,350+60,350+24+80);
	floodfill(180+38+60,350-20+10+80,WHITE);
	rectangle(180-150+60,350-24+80,72+60,350+28+80);
	rectangle(180-150-3+60,350-24-3+80,72+3+60,350+28+3+80);
	rectangle(180-150+20+60,350-24+30+80,72+60,350+28-30+80);
	rectangle(180-150+60+60,350-24+80,72+24+60,350+28+80);
	line(180+60,350+80,182+60,350-28+80);
	line(180+60,350+80,182+5+60,350+14+80);
	//showmouseptr for coordinates rectangle(180+60-30,350+80-32,180+60+30,350+80+32) and rectangle(180-150+60,350-24+80,72+60,350+28+80);
	//..ifclicked call bill.
	for(h=0;h<60;h=h+13)
		circle(280+h+60,352+80,3);
	outtextxy(178+60,350-28+80-13,"*");
	outtextxy(178+60,348+24+80-13,"*");
	outtextxy(178-24+60,348+80-13,"*");
	outtextxy(178+22+60,348+80-13,"*");
	setcolor(YELLOW);
	outtextxy(5,455,"BACK");
	outtextxy(500,455,"EXIT");
	traverse2=traverse1->link11;
		initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		if(o.x.cx>=5&&o.x.cx<=70)
		{

			if(o.x.dx>=455&&o.x.dx<=488)
			{

				if(o.x.bx==1)
				{
					hidemouseptr();
					 women();
				}
		       }
	      }
	      if(o.x.cx>=500&&o.x.cx<=560)
		{

			if(o.x.dx>=455&&o.x.dx<=488)
			{

				if(o.x.bx==1)
				{
				      hidemouseptr();
					bill();
				}
		       }
	      }


		if(o.x.cx>=20&&o.x.cx<=100)
		{

			if(o.x.dx>=200&&o.x.dx<=240)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=1799;				    strcpy(temp2->pname,"LEE TSHIRT");
				     strcpy(temp2->pname,"PRADA BAG");
				    settextstyle(1,0,3);

				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
					ppush();
				  prpush();
				  delay(1000);
				  bag();
				   }
		       }
	      }

	      if(o.x.cx>=300&&o.x.cx<=380)
		{

			if(o.x.dx>=200&&o.x.dx<=250)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=1499;
				    strcpy(temp2->pname,"GUCCI BAG");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  bag();
				   }
		       }
	      }

	      if(o.x.cx>=400&&o.x.cx<=460);
		{

			if(o.x.dx>=387&&o.x.dx<=415)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->next22->name22;
				    temp1->rate=2999;
				    strcpy(temp2->pname,"TITAN WATCHES");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
					ppush();
				  prpush();
				  delay(1000);
				  bag();
				   }
		       }
	      }


	 }

}






//***********books************


void books()
{
	int i;
	for(i=0;i<4;i++)
	{
	cleardevice();
	setbkcolor(BLACK);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,i+1);
	outtextxy(140,130,"welcome!!!");
	delay(200);
	}
	for(i=0;i<4;i++)
	{
		cleardevice();
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,i+1);
		outtextxy(160,150,"to");
		delay(200);
	}
	for(i=0;i<4;i++)
	{
		cleardevice();
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,i+1);
		outtextxy(180,170,"the");
		delay(200);
	}
	for(i=0;i<4;i++)
	{
		cleardevice();
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,i+1);
		outtextxy(200,190,"books");
		delay(200);
	}
	for(i=0;i<4;i++)
	{
		cleardevice();
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,i+1);
		outtextxy(220,210,"section");
		delay(200);
	}
	cleardevice();

       delay(800);
       bookoptions();
}
void bookoptions()
{
	int j;
	setbkcolor(BLACK);
	//changed the movement of the options in this entire loop
	for(j=0;j<100;j++)
	{
		cleardevice();
		setcolor(j%15);
		outtextxy(90+j,50,"BOOKS!!");
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		setcolor(2);
		outtextxy(199,100,"Academic");
		//delay(2);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		setcolor(4);
		outtextxy(199,200,"Literature");
		//delay(2);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		setcolor(6);
		outtextxy(199,300,"Children");
	}

	outtextxy(0,420,"BACK");
	outtextxy(520,420,"EXIT");
	traverse1=books1;
	initmouse();
	showmouseptr();
	while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		if(o.x.cx>=180&&o.x.cx<=320)
		{
			if(o.x.dx>=80&&o.x.dx<=150)
			{
				if(o.x.bx==1)
				{
					hidemouseptr();
					academic();
				}
			}
		}
		if(o.x.cx>=180&&o.x.cx<=320)
		{
			if(o.x.dx>=180&&o.x.dx<=250)
			{
				if(o.x.bx==1)
				{
					hidemouseptr();
					traverse1=books1->down11;
					literature();
				}
			}
		}
		if(o.x.cx>=180&&o.x.cx<=320)
		{
			if(o.x.dx>=280&&o.x.dx<=350)
			{
				if(o.x.bx==1)
				{
					hidemouseptr();
					traverse1=books1->down11->down11;
					children();
				}
			}
		}
		if(o.x.cx>=0&&o.x.cx<=60)
		{
			if(o.x.dx>=420&&o.x.dx<=465)
			{
				if(o.x.bx==1)
				{
					hidemouseptr();
					category();
				}
			}
		}

		if(o.x.cx>=520&&o.x.cx<=570)
		{
			if(o.x.dx>=420&&o.x.dx<=460)
			{
				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
			}
		}


	}





}



void academic()
{       int j;
settextstyle(TRIPLEX_FONT,0,2);
	cleardevice();
	line(227,0,227,550);
	line(430,0,430,550);
	outtextxy(15,40,"Data structures");
	//SHOWMOUSEPTR FOR ABOVE CLICKED D.S. COORDINATES AND IF CLICKED CALL BILL.
	setbkcolor(GREEN);
	setcolor(YELLOW);
	line(40,90,40,170);
	line(110,155,180,90);
	line(40,90,110,155);
	line(110,155,110,245);
	line(40,170,110,245);
	line(180,170,110,245);
	line(180,90,180,170);
	line(40,90,55,80);
	line(55,80,110,155);
	line(165,80,110,155);
	line(165,80,180,90);
	outtextxy(65,145,"c. ");
	outtextxy(130,145,"s.");
	outtextxy(0,392,"PRICE:Rs.400 Rs.320");
	outtextxy(0,422,"(discount:20% off)");
	line(80,408,135,408);
	//changed the coordinates for exit
	outtextxy(535,0,"exit");
	outtextxy(70,255,"DETAILS");
	for(j=0;j<100;j++)
	{
		line(70,280+j,205,280+j);
		delay(15);
	}
	//settextstyle(1,1,4);
	//outtextxy(20,245,"purchase");
	setcolor(RED);
	//settextstyle(1,0,3);
	outtextxy(70,300,"Publications:");
	outtextxy(70,325,"Schaum's");
	outtextxy(70,350,"Outline");
	outtextxy(215,40,"\t     Physics");
	//SHOW,OUSEPTR HERE AND IF CLICKED ON THIS PHYSICS(ABOVE COORDINATES) CALL BILL.
	setbkcolor(BLUE);
	setcolor(YELLOW);
	line(240,90,240,170);
	line(310,155,380,90);
	line(240,90,310,155);
	line(310,155,310,245);
	line(240,170,310,245);
	line(380,170,310,245);
	line(380,90,380,170);
	line(240,90,255,80);
	line(255,80,310,155);
	line(365,80,310,155);
	line(365,80,380,90);
		outtextxy(265,145,"p.");
		outtextxy(230,392,"PRICE:Rs.500Rs.400");
		outtextxy(230,422,"(Discount:20% off)");
		line(290,408,350,408);
		outtextxy(270,255,"DETAILS");
		for(j=0;j<100;j++)
		{
			line(270,280+j,405,280+j);
			delay(15);
		}

		setcolor(RED);
		outtextxy(270,300,"Publications:");
		outtextxy(270,325,"McGRAW hill");
		outtextxy(270,350,"5th edition");
		outtextxy(435,40,"   mathematics");
		//SHOWMOUSEPTR ON ABOVE MATHS COORDINATES AND CALL BILL IF CLICKED
		setbkcolor(DARKGRAY);
		setcolor(YELLOW);
		line(450,90,450,170);
		line(520,155,590,90);
		line(450,90,520,155);
		line(520,155,520,245);
		line(450,170,520,245);
		line(590,170,520,245);
		line(590,90,590,170);
		line(450,90,465,80);
		line(465,80,520,155);
		line(575,80,520,155);
		line(575,80,590,90);
		outtextxy(475,145,"m.");
		outtextxy(435,392,"PRICE:Rs.600 Rs.480");
		line(495,408,570,408);
		outtextxy(430,422,"(discount:20% off)");
		line(280,355,350,355);
		outtextxy(0,450,"Back");
		outtextxy(500,255,"DETAILS");
		for(j=0;j<100;j++)
		{
			line(450,280+j,575,280+j);
			delay(15);
		}

		setcolor(RED);
		outtextxy(450,300,"Publications:");
		outtextxy(450,325,"S.K. JAIN");
		outtextxy(450,350,"6th edition");
		traverse2=traverse1->link11;
		initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		//changed the coordinates for both x and y
		if(o.x.cx>=0&&o.x.cx<=60);
		{

			if(o.x.dx>=450&&o.x.dx<=470)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					  bookoptions();
				}
		       }
	      }
	      //changed the coordinates for both x and y
		if(o.x.cx>=535&&o.x.cx<=550);
		{

			if(o.x.dx>=0&&o.x.dx<=30)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
	      }

	       //changed the coordinates for both x and y
			if(o.x.cx>=40&&o.x.cx<=180)
		{

			if(o.x.dx>=80&&o.x.dx<=245)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=320;
				     strcpy(temp2->pname,"DATA STRUCTURES");
				    settextstyle(1,0,3);

				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  academic();
				   }
		       }
	      }
	      //changed the coordinates for both x and y
	      if(o.x.cx>=240&&o.x.cx<=380)
		{

			if(o.x.dx>=80&&o.x.dx<=245)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=400;
				    strcpy(temp2->pname,"PHYSICS");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  academic();
				   }
		       }
	      }
	      //changed the coordinates for both x and y
	      if(o.x.cx>=450&&o.x.cx<=590);
		{

			if(o.x.dx>=80&&o.x.dx<=245)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->next22->name22;
				    temp1->rate=480;
				    strcpy(temp2->pname,"MATHEMATICS");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  academic();

				   }
		       }
	      }


	 }



}
void literature()
{      int j;
	settextstyle(TRIPLEX_FONT,0,2);
	cleardevice();
	line(227,0,227,550);
	line(430,0,430,550);
	outtextxy(0,40,"William Shakespeare");
	//SHOWMOUSEPTR FOR ABOVE W.S. COORDINATES AND IF CLCIKED CALL BILL.
	setbkcolor(GREEN);
	//setcolor(YELLOW);
	//line(70,135,70,200);
	setcolor(YELLOW);
	line(40,90,40,170);
	line(110,155,180,90);
	line(40,90,110,155);
	line(110,155,110,245);
	line(40,170,110,245);
	line(180,170,110,245);
	line(180,90,180,170);
	line(40,90,55,80);
	line(55,80,110,155);
	line(165,80,110,155);
	line(165,80,180,90);
	outtextxy(65,145,"w");
	outtextxy(130,145,"s");
	outtextxy(0,392,"PRICE:Rs.400 Rs.320");
	outtextxy(0,422,"(Discount:20% off)");
	line(80,408,135,408);
	outtextxy(0,450,"Back");
	outtextxy(70,255,"DETAILS");
	for(j=0;j<100;j++)
	{
		line(70,280+j,205,280+j);
		delay(15);
	}

	setcolor(RED);
	outtextxy(70,300,"Includes:");
	outtextxy(70,325,"Macbeth");
	outtextxy(70,350,"R&J");
		outtextxy(215,40,"\t    Sir Arthur");
		//SHOWMOUSE FOR ABOVE COORDINATES AND IF CLICKED CALL BILL.
		setbkcolor(BLUE);
		setcolor(YELLOW);
		line(240,90,240,170);
		line(310,155,380,90);
		line(240,90,310,155);
		line(310,155,310,245);
		line(240,170,310,245);
		line(380,170,310,245);
		line(380,90,380,170);
		line(240,90,255,80);
		line(255,80,310,155);
		line(365,80,310,155);
		line(365,80,380,90);
		outtextxy(265,145,"Sa");
		outtextxy(230,392,"PRICE:Rs.500 Rs.400");
		outtextxy(230,422,"(Discount:20% off)");
		line(290,408,350,408);
		outtextxy(270,255,"DETAILS");
		for(j=0;j<100;j++)
		{
			line(270,280+j,405,280+j);
			delay(15);
		}

		setcolor(RED);
		outtextxy(270,300,"BEST SELLING");
		outtextxy(270,325,"SHERLOCK");
		outtextxy(270,350,"HOLMES");
		outtextxy(435,40,"\t Mario Puzo");
		setbkcolor(DARKGRAY);
		setcolor(YELLOW);
		line(450,90,450,170);
		line(520,155,590,90);
		line(450,90,520,155);
		line(520,155,520,245);
		line(450,170,520,245);
		line(590,170,520,245);
		line(590,90,590,170);
		line(450,90,465,80);
		line(465,80,520,155);
		line(575,80,520,155);
		line(575,80,590,90);
		outtextxy(465,145,"MARIO PUZO");//SHOWMOUSEPTR FOR THESE COORDINATES AND IF CLICKED CALL BILL.
		outtextxy(435,392,"PRICE:Rs.600 Rs.480");
		outtextxy(430,422,"(discount:20% off)");
		line(495,408,570,408);
		//changed the coordinates for exit
		outtextxy(535,0,"Exit");
		outtextxy(500,255,"DETAILS");
		for(j=0;j<100;j++)
		{
			line(450,280+j,575,280+j);
			delay(15);
		}

		setcolor(RED);
		outtextxy(450,300,"BEST SELLING");
		outtextxy(450,325,"THE");
		outtextxy(450,350,"GODFATHER");

		traverse2=traverse1->link11;
			initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		//changed the coordinates for both x and y
		if(o.x.cx>=535&&o.x.cx<=550);
		{

			if(o.x.dx>=0&&o.x.dx<=30)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
				       bill	();
				}
		       }
	      }
	      //changed the coordinates for both x and y
		if(o.x.cx>=0&&o.x.cx<=60);
		{

			if(o.x.dx>=450&&o.x.dx<=470)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					bookoptions();
				}
		       }
	      }

	      //changed the coordinates for both x and y
		if(o.x.cx>=40&&o.x.cx<=180)
		{

			if(o.x.dx>=80&&o.x.dx<=245)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;;
				    temp1->rate=320;				    strcpy(temp2->pname,"LEE TSHIRT");
				     strcpy(temp2->pname,"WILLIAM SHAKESPEARE");
				    settextstyle(1,0,3);

				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  literature();
				   }
		       }
	      }
	      //changed the coordinates for both x and y
	      if(o.x.cx>=240&&o.x.cx<=380)
		{

			if(o.x.dx>=80&&o.x.dx<=245)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=400;
				    strcpy(temp2->pname,"SIR ARTHUR");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  literature();
				   }
		       }
	      }
	      //changed the coordinates for both x and y
	      if(o.x.cx>=450&&o.x.cx<=590);
		{

			if(o.x.dx>=80&&o.x.dx<=245)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->next22->name22;
				    temp1->rate=480;
				    strcpy(temp2->pname,"MARIO PUZO");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  literature();
				   }
		       }
	      }

	 }



}

void children()
{        int j;
settextstyle(TRIPLEX_FONT,0,2);
	cleardevice();
	line(227,0,227,550);
	line(430,0,430,550);
	outtextxy(0,40,"\t  Agatha Christie");//SHOW MOUSE FOR THESE COORDINATES AND IF CLCIKED CALL BILL.
	setbkcolor(GREEN);
	setcolor(YELLOW);
	line(40,90,40,170);
	line(110,155,180,90);
	line(40,90,110,155);
	line(110,155,110,245);
	line(40,170,110,245);
	line(180,170,110,245);
	line(180,90,180,170);
	line(40,90,55,80);
	line(55,80,110,155);
	line(165,80,110,155);
	line(165,80,180,90);
	outtextxy(65,145,"a");
	outtextxy(130,145,"c");
	outtextxy(0,392,"PRICE:Rs.400 Rs.320");
	outtextxy(0,422,"(Discount:20% off)");
	line(80,408,135,408);
	outtextxy(0,440,"Back");
	outtextxy(70,255,"DETAILS");
	for(j=0;j<100;j++)
	{
		line(70,280+j,205,280+j);
		delay(15);
	}
	setcolor(RED);
	outtextxy(70,300,"Publications:");
	outtextxy(70,325,"Barney &");
	outtextxy(70,350,"Nobles");
		outtextxy(215,40,"\t  Nancy Drew");
		//SHOW MOUSE FOR ABOVE COORDINATES IF CLCIKED CALL BILL.
		setbkcolor(BLUE);
		setcolor(YELLOW);
		line(240,90,240,170);
		line(310,155,380,90);
		line(240,90,310,155);
		line(310,155,310,245);
		line(240,170,310,245);
		line(380,170,310,245);
		line(380,90,380,170);
		line(240,90,255,80);
		line(255,80,310,155);
		line(365,80,310,155);
		line(365,80,380,90);
		outtextxy(265,145,"nd");
		outtextxy(230,392,"PRICE:Rs.500 Rs.400");
		outtextxy(230,422,"(Discount:20% off)");
		line(290,408,350,408);
		outtextxy(270,255,"DETAILS");
		for(j=0;j<100;j++)
		{
			line(270,280+j,405,280+j);
			delay(15);
		}

		setcolor(RED);
		outtextxy(270,300,"Publications:");
		outtextxy(270,325,"Barney's &");
		outtextxy(270,350,"Nobles");
		outtextxy(430,40,"THE SECRET SEVEN");
		//SHOW MOUSE FOR ABOVE COORDINATES AND IF CLICKED CALL BILL.
		setbkcolor(DARKGRAY);
		setcolor(YELLOW);
		line(450,90,450,170);
		line(520,155,590,90);
		line(450,90,520,155);
		line(520,155,520,245);
		line(450,170,520,245);
		line(590,170,520,245);
		line(590,90,590,170);
		line(450,90,465,80);
		line(465,80,520,155);
		line(575,80,520,155);
		line(575,80,590,90);
		outtextxy(465,145,"ss");
		outtextxy(435,392,"PRICE:Rs.600 Rs.480");
		outtextxy(430,422,"(discount:20% off)");
		line(495,408,570,408);
		//changed the coordinates for exit
		outtextxy(535,0,"Exit");
		outtextxy(500,255,"DETAILS");
		for(j=0;j<100;j++)
		{
			line(450,280+j,575,280+j);
			delay(25);
		}
		setcolor(RED);
		outtextxy(450,300,"Publications:");
		outtextxy(450,325,"Enid");
		outtextxy(450,350,"Blyton");

		traverse2=traverse1->link11;
			initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		//changed the coordinates for both x and y
		if(o.x.cx>=535&&o.x.cx<=550);
		{

			if(o.x.dx>=0&&o.x.dx<=30)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
				       bill	();
				}
		       }
	      }
	      //changed the coordinates for both x and y
		if(o.x.cx>=0&&o.x.cx<=60);
		{

			if(o.x.dx>=450&&o.x.dx<=470)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					bookoptions();
				}
		       }
	      }
	      //changed the coordinates for both x and y
		if(o.x.cx>=40&&o.x.cx<=180)
		{

			if(o.x.dx>=180&&o.x.dx<=245)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=320;
				     strcpy(temp2->pname,"AGATHA CHRISTIE");
				    settextstyle(1,0,3);

				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  children();
				   }
		       }
	      }
	      //changed the coordinates for both x and y
	      if(o.x.cx>=240&&o.x.cx<=380)
		{

			if(o.x.dx>=80&&o.x.dx<=245)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=400;
				    strcpy(temp2->pname,"NANCY DREW");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  children();
				   }
		       }
	      }
	      //changed the coordinates for both x and y
	      if(o.x.cx>=450&&o.x.cx<=570);
		{

			if(o.x.dx>=80&&o.x.dx<=245)
			{

				if(o.x.bx==1)
				{  hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->next22->name22;
				    temp1->rate=499;
				    strcpy(temp2->pname,"THE SECRET SEVEN");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  children();
				   }
		       }
	      }


	 }



}

//***************games*************
void games()
{
	int ch;
	int j=0,k;

	for(k=0;k<500;k+=10)
	{
		line(10,220,60,220);
		line(10,220,10,270);
		line(10,270,35,270);
		line(35,270,35,235);
		line(60,235,60,220);
		line(60,225,75,225);
		line(75,225,75,230);
		line(60,230,75,230);
		line(35,235,60,235);
		settextstyle(TRIPLEX_FONT,0,1);
		outtextxy(75+k,220,"G");
		if(k<100)
		delay(150);
		else
		delay(1);
		j++;
		cleardevice();
	}j=0;
	for(k=0;k<490;k+=10)
	{
		outtextxy(574,220,"G");
		line(10,220,60,220);
		line(10,220,10,270);
		line(10,270,35,270);
		line(35,270,35,235);
		line(60,235,60,220);
		line(60,225,75,225);
		line(75,225,75,230);
		line(60,230,75,230);
		line(35,235,60,235);
		settextstyle(TRIPLEX_FONT,0,1);
		outtextxy(75+k,220,"A");
		if(k<100)
		delay(150);
		else
		delay(1);
		j++;
		cleardevice();
	}    j=0;
	for(k=0;k<480;k+=10)
	{
		outtextxy(574,220,"G");
		outtextxy(564,220,"A");
		line(10,220,60,220);
		line(10,220,10,270);
		line(10,270,35,270);
		line(35,270,35,235);
		line(60,235,60,220);
		line(60,225,75,225);
		line(75,225,75,230);
		line(60,230,75,230);
		line(35,235,60,235);
		settextstyle(TRIPLEX_FONT,0,1);
		outtextxy(75+k,220,"M");
		if(k<100)
		delay(150);
		else
		delay(1);
		j++;
		cleardevice();
	}                                          j=0;
	for(k=0;k<470;k+=10)
	{
		outtextxy(574,220,"G");
		outtextxy(564,220,"A");
		outtextxy(554,220,"M");
		line(10,220,60,220);
		line(10,220,10,270);
		line(10,270,35,270);
		line(35,270,35,235);
		line(60,235,60,220);
		line(60,225,75,225);
		line(75,225,75,230);
		line(60,230,75,230);
		line(35,235,60,235);
		settextstyle(TRIPLEX_FONT,0,1);
		outtextxy(75+k,220,"E");
		j++;
		if(k<100)
		delay(150);
		else
		delay(1);
		cleardevice();
	}            j=0;
	for(k=0;k<460;k+=10)
	{
		cleardevice();
		outtextxy(574,220,"G");
		outtextxy(564,220,"A");
		outtextxy(554,220,"M");
		outtextxy(544,220,"E");
		line(10,220,60,220);
		line(10,220,10,270);
		line(10,270,35,270);
		line(35,270,35,235);
		line(60,235,60,220);
		line(60,225,75,225);
		line(75,225,75,230);
		line(60,230,75,230);
		line(35,235,60,235);
		settextstyle(TRIPLEX_FONT,0,1);
		outtextxy(75+k,220,"S");
		j++;
		if(k<100)
		delay(150);
		else
		delay(1);
	}
	cleardevice();
	outtextxy(574,220,"G");
	outtextxy(564,220,"A");
	outtextxy(554,220,"M");
	outtextxy(544,220,"E");
	outtextxy(534,220,"S");
	j=1;
	for(k=1;k<275,j<40;k++,j++)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		outtextxy(564,220,"A");
		outtextxy(554,220,"M");
		outtextxy(544,220,"E");
		outtextxy(534,220,"S");
		settextstyle(TRIPLEX_FONT,0,k+1);
		outtextxy(574-k,220+j,"G");
		delay(5);
		cleardevice();
	}
	j=1;
	for(k=1;k<460,j<50;k++,j++)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		outtextxy(554,220,"M");
		outtextxy(544,220,"E");
		outtextxy(534,220,"S");
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
		setcolor(RED);
		outtextxy(100,249,"G");
		settextstyle(TRIPLEX_FONT,0,k+1);
		outtextxy(564-k,220+j,"A");
		delay(5);
		cleardevice();
	}   j=1;
	for(k=1;k<440,j<60;k++,j++)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		//outtextxy(554,220,"M");
		outtextxy(544,220,"E");
		outtextxy(534,220,"S");
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
		setcolor(RED);
		outtextxy(100,249,"G");
		setcolor(GREEN);
		outtextxy(115,269,"A");
		settextstyle(TRIPLEX_FONT,0,k+1);
		outtextxy(554-k,220+j,"M");
		delay(5);
		cleardevice();
	}j=1;
	for(k=1;k<420,j<70;k++,j++)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		//outtextxy(544,220,"E");
		outtextxy(534,220,"S");
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
		setcolor(RED);
		outtextxy(100,249,"G");
		setcolor(GREEN);
		outtextxy(115,269,"A");
		setcolor(BLUE);
		outtextxy(125,289,"M");
		settextstyle(TRIPLEX_FONT,0,k+1);
		outtextxy(544-k,220+j,"E");
		delay(5);
		cleardevice();
	}j=1;
	for(k=1;k<400,k<80;k++,j++)
	{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
		setcolor(RED);
		outtextxy(100,249,"G");
		setcolor(GREEN);
		outtextxy(110,269,"A");
		setcolor(BLUE);
		outtextxy(120,289,"M");
		setcolor(MAGENTA);
		outtextxy(130,309,"E");
		settextstyle(TRIPLEX_FONT,0,k+1);
		outtextxy(534-k,220+j,"S");
		delay(5);
		cleardevice();
	}
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setcolor(RED);
	outtextxy(100,249,"G");
	setcolor(GREEN);
	outtextxy(110,269,"A");
	setcolor(BLUE);
	outtextxy(120,289,"M");
	setcolor(MAGENTA);
	outtextxy(130,309,"E");
	setcolor(CYAN);
	outtextxy(140,329,"S");
	setcolor(YELLOW);
	delay(1000);
	//outtextxy(0,350,"click here to continue");

	//outtextxy(0,425,"<-----");
       gameoptions();

}
void gameoptions()
{
	char ch1;
	int k;
     //	cleardevice();
	for(k=0;k<100;k++)
	{       setcolor(YELLOW);
		cleardevice();
		//setfillstyle(LTBKSLASH_FILL,GREEN);
		//setfillstyle(WIDE_DOT_FILL,BLUE);
		//floodfill(0,0,BLUE);
		outtextxy(199,50,"We have the following varieties :");
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		outtextxy(k,100,"Board Games");
		delay(2);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		//setcolor(i%15);
		outtextxy(500-k,200,"Video Games");
		delay(2);
	}
	outtextxy(20,390,"BACK");
	outtextxy(590,410,"EXIT");
	traverse1=games1;
	initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		if(o.x.cx>=95&&o.x.cx<=240)
		{

			if(o.x.dx>=100&&o.x.dx<=130)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					board();
				}
		       }
	      }

	       if(o.x.cx>=20&&o.x.cx<=70)
		{

			if(o.x.dx>=390&&o.x.dx<=420)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					category();
				}
		       }
	      }


		 if(o.x.cx>=590&&o.x.cx<=625)
		{

			if(o.x.dx>=410&&o.x.dx<=430)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
	      }

		if(o.x.cx>=397&&o.x.cx<=550)
		{

			if(o.x.dx>=200&&o.x.dx<=220)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					traverse1=traverse1->down11;
					video();
				}
		       }
	      }
	 }


}
void board()
{        cleardevice();
	line(320,0,320,550);
	setfillstyle(WIDE_DOT_FILL,BLUE);
	bar3d(110,50,270,150,10,1);
	//SHOWMOUSE PTR FOR ABOVE BAR COORDINATES AND IF CLICKED CALL BILL.
	settextstyle(TRIPLEX_FONT,0,1);
	setcolor(RED);
	outtextxy(160,85,"L");
	setcolor(BLUE);
	outtextxy(170,85,"I");
	setcolor(GREEN);
	outtextxy(180,85,"F");
	setcolor(MAGENTA);
	outtextxy(190,85,"E");
	setcolor(RED);
	outtextxy(120,65,"FUNSKOOL");
	setcolor(YELLOW);
	outtextxy(120,150,"''PURCHASE''");
	setcolor(RED);
	outtextxy(70,200,"~ 9 years");
	outtextxy(70,220,"~2-8 players");
	outtextxy(70,240,"~enhances mental skills");
	outtextxy(70,260,"~3D board game");
	outtextxy(70,280,"Rs. 594  10% off");
	line(70,290,140,290);
	outtextxy(70,305,"Rs.534");
	setfillstyle(BKSLASH_FILL,GREEN);
	bar3d(420,50,550,150,10,1);
	//SHOWMOUSE PTR FOR ABOVE BAR COORDINATES AND IF CLICKED CALL BILL.
	settextstyle(TRIPLEX_FONT,0,1);
	setcolor(BLUE);
	outtextxy(440,85,"MONOPOLY");
	setcolor(RED);
	outtextxy(425,65,"FUNSKOOL");
	setcolor(YELLOW);
	outtextxy(380,150,"''PURCHASE''");
	setcolor(RED);
	outtextxy(330,200,"~improve strategy skill");
	outtextxy(330,220,"~learn money management");
	outtextxy(330,240,"~helps focus");
	outtextxy(330,260,"~8 years+");
	outtextxy(330,280,"Rs.725  10% off");
	line(330,290,400,290);
	outtextxy(330,300,"Rs.652");
	outtextxy(20,390,"BACK");
	outtextxy(590,400,"EXIT");
	traverse2=traverse1->link11;
	initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		if(o.x.cx>=20&&o.x.cx<=70)
			{

				if(o.x.dx>=390&&o.x.dx<=420)
				{


					if(o.x.bx==1)
					{
						hidemouseptr();
						gameoptions();
					}
				  }
			}


		 if(o.x.cx>=590&&o.x.cx<=625)
		{

			if(o.x.dx>=410&&o.x.dx<=430)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
	      }


		if(o.x.cx>=120&&o.x.cx<=200)
		{

			if(o.x.dx>=150&&o.x.dx<=200)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=534;				    strcpy(temp2->pname,"LEE TSHIRT");
				     strcpy(temp2->pname,"FUNSKOOL LIFE");
				    settextstyle(1,0,3);

				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  board();
				   }
		       }
	      }

	      if(o.x.cx>=380&&o.x.cx<=470)
		{

			if(o.x.dx>=150&&o.x.dx<=200)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=399;
				    strcpy(temp2->pname,"MONOPOLY");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  board();
				   }
		       }
	      }


	 }
}
void video()
{        cleardevice();
	line(320,0,320,550);
	setfillstyle(LINE_FILL,BLUE);
	bar3d(110,50,240,150,10,1);
	//SHOWMOUSE PTR FOR ABOVE BAR COORDINATES AND IF CLICKED CALL BILL.
	settextstyle(TRIPLEX_FONT,0,1);
	setcolor(CYAN);
	outtextxy(160,85,"GRAND");
	setcolor(YELLOW);
	outtextxy(170,105,"THEFT");
	setcolor(GREEN);
	outtextxy(180,125,"AUTO");
	setcolor(MAGENTA);
	//outtextxy(190,130,"IV");
	//setcolor(RED);
	setcolor(LIGHTCYAN);
	outtextxy(110,50,"GAMES");
	outtextxy(110,65,"for windows");
	setcolor(YELLOW);
	outtextxy(70,150,"''PURCHASE''");
	setcolor(LIGHTCYAN);
	outtextxy(70,200,"~ PEGI RATING");
	outtextxy(70,220,"~-->18");
	outtextxy(70,240,"~PLATFORM");
	outtextxy(70,260,"~-->PC");
	outtextxy(70,280,"Rs. 699 ");
	//line(70,290,140,290);
	//outtextxy(70,305,"Rs.494");
	setcolor(BROWN);
	setfillstyle(SOLID_FILL,GREEN);
	bar3d(420,50,525,150,10,1);
	//SHOWMOUSE PTR FOR ABOVE BAR COORDINATES AND IF CLICKED CALL BILL.
	settextstyle(TRIPLEX_FONT,0,1);
	setcolor(BLUE);
	outtextxy(420,85,"ASSASIN'S");
	outtextxy(420,105,"CREED");
	setcolor(RED);
	outtextxy(380,150,"''PURCHASE''");
	setcolor(YELLOW);
	outtextxy(425,65,"PC DVD-ROM");
	outtextxy(330,200,"~PEGI RATING");
	outtextxy(330,220,"~-->18");
	outtextxy(330,240,"~PLATFORM");
	outtextxy(330,260,"~-->PC");
	outtextxy(330,280,"Rs.999  10% off");
	line(330,290,400,290);
	outtextxy(330,300,"Rs.900");
	setcolor(RED);
	outtextxy(20,390,"BACK");
	outtextxy(590,400,"EXIT");
	traverse2=traverse1->link11;
	initmouse();
	showmouseptr();
		while(!kbhit())
	{
		i.x.ax=3;
		int86(0X33,&i,&o);
		if(o.x.cx>=20&&o.x.cx<=70)
		{

			if(o.x.dx>=390&&o.x.dx<=420)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					gameoptions();
				}
		       }
	      }


		 if(o.x.cx>=590&&o.x.cx<=625)
		{

			if(o.x.dx>=410&&o.x.dx<=430)
			{


				if(o.x.bx==1)
				{
					hidemouseptr();
					bill();
				}
		       }
	      }
		if(o.x.cx>=70&&o.x.cx<=150)
		{

			if(o.x.dx>=150&&o.x.dx<=200)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->name22;
				    temp1->rate=699;				    strcpy(temp2->pname,"LEE TSHIRT");
				     strcpy(temp2->pname,"GTA GAME");
				    settextstyle(1,0,3);

				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  video();
				   }
		       }
	      }

	      if(o.x.cx>=380&&o.x.cx<=470)
		{

			if(o.x.dx>=150&&o.x.dx<=200)
			{

				if(o.x.bx==1)
				{   hidemouseptr();
				   temp1=(struct price*)malloc(sizeof(struct price));
				   temp2=(struct product*)malloc(sizeof(struct product));
				    temp1->add=traverse2->next22->name22;
				    temp1->rate=900;
				    strcpy(temp2->pname,"ASSASIN CREED");
				    settextstyle(1,0,3);
				   outtextxy(0,0,"SUCCESSFULLY PURCHASED");
				  ppush();
				  prpush();
				  delay(1000);
				  video();
				   }
		       }

	      }
	 }

}

void main()
{

   int gd=DETECT, gm;
     clrscr();
     load();
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

     welcome();
     creation();
     category();
}