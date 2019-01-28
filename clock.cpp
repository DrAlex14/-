#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <math.h>

//游戏画面尺寸
#define Height 480
#define Width 640
#define Pi 3.1415926

int main()
{
  initgraph(Width,Height);
  int center_x,center_y;//中心坐标
  center_x=Width/2;
  center_y=Height/2;

  int secondLength;     //秒针长度
  secondLength=Width/5;

  int secondEnd_x,secondEnd_y;   //秒针终点坐标
  secondEnd_x=center_x+secondLength;
  secondEnd_y=center_y;
  
  float secondAngle=0;    //秒针转动角度
  
  int minuteLength=Width/4;     //分针长度
  int minuteEnd_x,minuteEnd_y;  //分针终点坐标
  minuteEnd_x=center_x+minuteLength;
  minuteEnd_y=center_y;
  
  float minuteAngle=0;
  
  int hourLength=Width/6;     //时针长度
  int hourEnd_x,hourEnd_y;  //时针终点坐标
  hourEnd_x=center_x+hourLength;
  hourEnd_y=center_y;
  
  float hourAngle=0;
  SYSTEMTIME ti;      //定义变量存储系统时间
  
  BeginBatchDraw();
  while(1)
  {
  //绘制表盘
  setlinestyle(PS_SOLID,1);
  setlinecolor(WHITE);
  circle(center_x,center_y,Width/3.5);
  outtextxy(center_x-25, center_y+Width/6,"实时时钟");
  // 画刻度
  int x,y,i;
  for (i=0; i<60; i++)
  {
	x=center_x+int(Width/3.8*sin(Pi*2*i/60));
	y=center_y+int(Width/3.8*cos(Pi*2*i/60));
			
	if (i%15==0)
		bar(x-5, y-5, x+5, y+5);
		else if (i%5==0)
		circle(x,y,3);
		else
		putpixel(x,y,WHITE);
  }
		
  

  GetLocalTime(&ti);     //得到当前时间
  secondAngle=ti.wSecond*2*Pi/60;
  secondEnd_x=center_x+secondLength*sin(secondAngle);
  secondEnd_y=center_y-secondLength*cos(secondAngle);
  
  minuteAngle=ti.wMinute*2*Pi/60;
  minuteEnd_x=center_x+minuteLength*sin(minuteAngle);
  minuteEnd_y=center_y-minuteLength*cos(minuteAngle);
  
  hourAngle=ti.wHour*2*Pi/60;
  hourEnd_x=center_x+hourLength*sin(hourAngle);
  hourEnd_y=center_y-hourLength*cos(hourAngle);
  //画秒针
  setlinestyle(PS_SOLID,2);
  setcolor(WHITE);
  line(center_x,center_y,secondEnd_x,secondEnd_y);
  
  //画分针
  setlinestyle(PS_SOLID,2);
  setcolor(YELLOW);
  line(center_x,center_y,minuteEnd_x,minuteEnd_y);
  
  //画时针
  setlinestyle(PS_SOLID,2);
  setcolor(RED);
  line(center_x,center_y,hourEnd_x,hourEnd_y);
  FlushBatchDraw();
  Sleep(50);
  //隐藏前面一帧的秒针
  setcolor(BLACK);
  line(center_x,center_y,secondEnd_x,secondEnd_y);

  //隐藏前面一帧的分针
  setcolor(BLACK);
  line(center_x,center_y,minuteEnd_x,minuteEnd_y);

  //隐藏前面一帧的时针
  setcolor(BLACK);
  line(center_x,center_y,minuteEnd_x,minuteEnd_y);
  }
  EndBatchDraw();
  getch();
  closegraph();

  return 0;
}
