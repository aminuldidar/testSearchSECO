#include<graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#define ARROW_UP    0x48
#define ARROW_LEFT  0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN  0x50
#define ARROW_NONE  0x00
#define ESC_KEY     0x1B
 // Global variables to control modules & thread //
 long arrowx,arrowy,x,y,radius=20,my,counter=0,dhonukx,dhonuky,factor,del;

unsigned char getArrow();

int throwarrow(long xx, long yy, long kx,long ky,long cx,long cy,long  cr)
{

    setfillstyle(0, getmaxcolor());
    bar(50, 5, 200, 470);
    arrowx=xx;
    arrowy=yy;

   line(arrowx+95, arrowy, kx+95,ky+90);
   line(arrowx+95, arrowy, kx+95, ky-90);
   arc(dhonukx,dhonuky, 315, 45, 130);
	x=cx;
	y=cy;
	radius=cr;
       long  varx,vary;
   //////// move arrow after trigger  ///
   for(int i=95;i<=500;i++)
   {
       if(i<=150)
       {
	  line(arrowx+95, arrowy, kx+95,ky+90);
	  line(arrowx+95, arrowy, kx+95, ky-90);
	  arc(dhonukx,dhonuky, 315, 45, 130);

	}
       if((i-5)%factor==0)
       {
	 bar(520, 50, 650, 470);
	 if(my==1)
	   y=y-1;
	 else
	   y=y+1;
	   if(y>370)
	   my=1;
	  if(y<100)
	   my=0;
	 setcolor(5);
	 circle(x, y, radius);
	 setcolor(2);
	}
     setcolor(7);
     line(arrowx+i, arrowy, kx+100+i, ky);
     line(kx+100+i, ky, kx+95+i, ky-5);
     line(kx+100+i, ky, kx+95+i, ky+5);
     line(arrowx+i+3, arrowy,arrowx+i-5, arrowy-5);
     line(arrowx+i+3, arrowy, arrowx+i-5, arrowy+5);
     setcolor(2);
      delay(2);
     bar(kx+90+i, ky-6,arrowx+i-6, arrowy+5);

      varx=kx+100+i;
      vary=ky;
      if((varx-x)*(varx-x)+(vary-y)*(vary-y)<=radius*radius)
       {
	  counter++;
	  setcolor(7);
	  line(arrowx+i, arrowy, kx+100+i, ky);
	  line(kx+100+i, ky, kx+95+i, ky-5);
	  line(kx+100+i, ky, kx+95+i, ky+5);
	  line(arrowx+i+3, arrowy,arrowx+i-5, arrowy-5);
	  line(arrowx+i+3, arrowy, arrowx+i-5, arrowy+5);

	  setcolor(4);
	  circle(x, y, radius);
	  delay(500);
	  setcolor(2);
	  bar(kx+90+i, ky-6,arrowx+i-6, arrowy+5);
	  break;
	}
   }
   ////////
   setfillstyle(0, getmaxcolor());
   bar(50, 5, 200, 470);
    arrowx=xx;
    arrowy=yy;

   line(arrowx+95, arrowy, kx+95,ky+90);
   line(arrowx+95, arrowy, kx+95, ky-90);


 return counter;
}
     /// arc and arrow for up and down move ///
int dhonuk(int xx, int yy, int kx,int ky)
{
   bar(50, 5, 200, 470);
     arrowx=xx;
     arrowy=yy;
      if(arrowx<-40)
      arrowx=-40;
     if(arrowy<100)
	arrowy=100;
     if(arrowy>370)
	arrowy=370;
   // line(x+95, y, x+95, y+90);
   line(arrowx+95, arrowy, kx+95,ky+90);
   line(arrowx+95, arrowy, kx+95, ky-90);
    /// for arrow //
   line(arrowx+95, arrowy, kx+195, ky);
   line(kx+195, ky, kx+190, ky-5);
   line(kx+195, ky, kx+190, ky+5);
   line(arrowx+98, arrowy,arrowx+90, arrowy-5);
   line(arrowx+98, arrowy, arrowx+90, arrowy+5);
    /////////
 return 0;
}
int main()
{
       clrscr();
      int gdriver = DETECT, gmode, errorcode;

	/* initialize graphics and local variables */
		initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

	/* read result of initialization */
       errorcode = graphresult();
  if (errorcode != grOk)  /* an error occurred */
      {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1);
      } /* terminate with an error code */
	   unsigned char arrow;
     dhonukx=5,dhonuky=100;
      int key,left;
      long shoot=0;
	 y=70;
	 x = getmaxx() -50;
	 my=0;
	arrowx=5;
	arrowy=100;
	gotoxy(30,1);
	factor=5;
	del=25;
       //	clrscr();
       //	textcolor(5);
	//textbackground(4);
       //	outtextxy(225, 3, "You Heated..");
       //	printf("%ld/%d",counter,shoot);
      //	outtextxy(355, 3, "Boll Movement: Press 's'");

	 printf("You Heated..%ld/%ld		Boll Movement: Press 's'",counter,shoot);
	//textcolor(3);
	//gotoxy(30,25);
       //	printf("Press 's' to change boll move");
    while ((arrow = getArrow()) != ESC_KEY)
    {

	 if(my==1)
	   y=y-2;
	 else
	   y=y+2;
	 if(y>370)
	   my=1;
	  if(y<100)
	   my=0;

	setfillstyle(0, getmaxcolor());

      /* draw the bar */

	if (arrow != ARROW_NONE)
	 {
		if(dhonuky<100)
		  dhonuky=100;
	       if(dhonuky>370)
		  dhonuky=370;

	    switch(arrow)
	    {
		case ARROW_UP:
		     dhonuky=dhonuky-2;
		     arrowy = arrowy-2;
		     dhonuk(arrowx, arrowy,dhonukx,dhonuky);
		     arc(dhonukx,dhonuky, 315, 45, 130);
		     break;
		case ARROW_LEFT:
		      left=1;
		     dhonuk(arrowx-2,arrowy,dhonukx,dhonuky);
		     arc(dhonukx+2,dhonuky,315, 45, 130);
		     break;
		case ARROW_RIGHT:
		     if(left)
		     {
		       left=0;
		       shoot++;
		       throwarrow(dhonukx,dhonuky,dhonukx,dhonuky,x,y,radius);
		       arc(dhonukx,dhonuky,315, 45, 130);
			gotoxy(30,1);
		      // if(counter)
			 printf("You Heated..%ld/%ld",counter,shoot);
		     }
		     break;
		case ARROW_DOWN:
		    dhonuky=dhonuky+2;
		    arrowy = arrowy+2;
		    dhonuk(arrowx,arrowy,dhonukx,dhonuky);
		    arc(dhonukx,dhonuky,315, 45, 130);
		    break;
	       case 's':
			// printf("hello");
			  if(factor==5)
			  {
			    del=50;
			    factor=10;
			   }
			   else
			   {
			     del=25;
			     factor=5;

			     }
		    break;
	    }

	}

	 // */ draw the bar for clear selected area*/
	bar(520, 50, 650, 470);
	 setcolor(14);
	 circle(x, y, radius);
	 setcolor(2);
	   delay(del);

    }
    closegraph();
    return 0;
}
     // a function for detecting key press///
unsigned char getArrow() {
    if (kbhit()) {
	unsigned char ch = getch();
	if (ch == 0x00)
	{
	    //first char is a zero so lets look at the next char....
	    ch = getch();
	    switch(ch) {
		case ARROW_UP:
		    return ch;
		case ARROW_LEFT:
		    return ch;
		case ARROW_RIGHT:
		    return ch;
		case ARROW_DOWN:
		    return ch;
		case 's':
		    return ch;
		default:
		    return ARROW_NONE;
	    }
	}
	return ch;
    }
    return ARROW_NONE;
}
