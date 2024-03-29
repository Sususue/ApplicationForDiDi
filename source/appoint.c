#include "common.h"
#include "appoint.h"



/**************************
点击预约，弹出预约选择弹框
时间换算：
	waitime = 0 = 即时
    waitime = 30min = 15s
	waitime = 60min = 30s
	waitime = 90min = 45s
**************************/
int pre_appoint(int *x,int *y)
{
    int waitime=0;//用于判断预约时间
	int button=0;
    int mx=0;
    int my=0;
    
    mousehide(*x,*y);

    save_image(83,109,683,659,"preappoint");
	
	
	//即时按钮颜色发生改变
	bar_round(847,468,90,52,10,1,64384);
    bar_round(847,468,84,47,8,1,65535);
    fdhz(830,460,1,1,"即时",64384);
	
	
	//预约按钮颜色发生改变
	bar_round(945,468,90,52,10,1,44373);
    bar_round(945,468,84,47,8,1,65535);
    fdhz(928,460,1,1,"预约",44373);

	
    //画图
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(210,135,3,3,"预约上车时间",44373);
    bar(88,200,678,230,63422);
    linelevel(88,348,678,348,5,63422);
    linelevel(88,490,678,490,5,63422);
	outtextxy(150,265,"30",2,2,30,44373);
    fdhz(230,265,2,2,"分钟后",44373);
	outtextxy(150,403,"60",2,2,30,44373);
    fdhz(230,403,2,2,"分钟后",44373);
	outtextxy(150,535,"90",2,2,30,44373);
    fdhz(230,535,2,2,"分钟后",44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉
    
	bar_round(383,610,100,50,15,1,64384);
	bar_round(383,610,96,46,15,1,65535);
	fdhz(350,595,2,2,"确认",64384);//确认框
    
    reset_mouse(x,y);
    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=88 && mx<=678 && my>=230 && my<=348 &&button)//点击“30分钟”按键
		{
			waitime=15;
			mousehide(*x,*y);
			
			//标亮
			bar(88,230,678,348,65535);
			outtextxy(150,265,"30",2,2,30,64384);
			fdhz(230,265,2,2,"分钟后",64384);
			//变灰
			bar(88,353,678,490,65535);
			outtextxy(150,403,"60",2,2,30,44373);
			fdhz(230,403,2,2,"分钟后",44373);
			bar(88,495,678,580,65535);
			outtextxy(150,535,"90",2,2,30,44373);
			fdhz(230,535,2,2,"分钟后",44373);
			//打钩
			lean_line_thick(500,280,15,45,3,64384);
			lean_line_thick(500+11,280+8,40,-45,3,64384);
			
			reset_mouse(x,y);
		}
		if(mx>=88 && mx<=678 && my>=353 && my<=490 &&button)//点击“60分钟”按键
		{
			waitime=30;
			mousehide(*x,*y);
			
			//标亮
			bar(88,353,678,490,65535);
			outtextxy(150,403,"60",2,2,30,64384);
			fdhz(230,403,2,2,"分钟后",64384);
			//变灰
			bar(88,230,678,348,65535);
			outtextxy(150,265,"30",2,2,30,44373);
			fdhz(230,265,2,2,"分钟后",44373);
			bar(88,495,678,580,65535);
			outtextxy(150,535,"90",2,2,30,44373);
			fdhz(230,535,2,2,"分钟后",44373);
			//打钩
			lean_line_thick(500,422,15,45,3,64384);
			lean_line_thick(500+11,422+8,40,-45,3,64384);
			reset_mouse(x,y);
			
		}
		if(mx>=88 && mx<=678 && my>=495 && my<=580 &&button)//点击“90分钟”按键
		{
			waitime=45;
			mousehide(*x,*y);
			
			//标亮
			bar(88,495,678,580,65535);
			outtextxy(150,535,"90",2,2,30,64384);
			fdhz(230,535,2,2,"分钟后",64384);
			//变灰
			bar(88,230,678,348,65535);
			outtextxy(150,265,"30",2,2,30,44373);
			fdhz(230,265,2,2,"分钟后",44373);
			bar(88,353,678,490,65535);
			outtextxy(150,403,"60",2,2,30,44373);
			fdhz(230,403,2,2,"分钟后",44373);
			//打钩
			lean_line_thick(500,554,15,45,3,64384);
			lean_line_thick(500+11,554+8,40,-45,3,64384);
			
			reset_mouse(x,y);
		}
		if(mx>=333 && mx<=433 && my>=585 && my<=635 && button)//点击确认框
		{
			if (waitime == 0)
			{
				mousehide(*x,*y);

                save_image(383-210,384-140,512+210,384+140,"unchoose");
                bar_round(383,384,416,270,50,1,64384);
                bar_round(383,384,410,265,48,1,65535);
                fdhz(240,360,2,2,"您还未选择时间",64384);
                fdhz(320,420,1,1,"按任意键继续",44373);
                getch();
                printf_image(383-210,384-140,512+210,384+140,"unchoose");
                reset_mouse(x,y);
			}
			else
			{
				mousehide(*x,*y);

                save_image(383-210,384-140,512+210,384+140,"unchoose");
                bar_round(383,384,416,270,50,1,64384);
                bar_round(383,384,410,265,48,1,65535);
                fdhz(310,360,2,2,"预约成功",64384);
                fdhz(320,420,1,1,"按任意键继续",44373);
                getch();
                printf_image(383-210,384-140,512+210,384+140,"unchoose");
				reset_mouse(x,y);
				break;
			}
		
			
		
		}
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            break;
        }
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//点击红叉返回
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        {
            exit(0);
        }
		
    }

    
    mousehide(*x,*y);  //隐藏鼠标
    printf_image(83,109,683,659,"preappoint");
    
    reset_mouse(x,y);   //避免留下鼠标所在位置的背景
   
    return waitime;
}


/**************************
返回即时状态函数
***************************/
void immediate(int *x,int *y)
{
	int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);
	
	//save_image(802,442,990,494,"immediate");
	
	//即时按钮颜色发生改变
	bar_round(847,468,90,52,10,1,44373);
    bar_round(847,468,84,47,8,1,65535);
    fdhz(830,460,1,1,"即时",44373);
	
	
	//预约按钮颜色发生改变
	bar_round(945,468,90,52,10,1,64384);
    bar_round(945,468,84,47,8,1,65535);
    fdhz(928,460,1,1,"预约",64384);
	
	if (mx>=900  && mx<=990 && my>=442 && my<=494 && button)//点击预约，弹出预约选择弹框
    {
		pre_appoint(x,y);
    }
	
    //mousehide(*x,*y);  //隐藏鼠标
	//printf_image(802,442,990,494,"immediate");
  
    reset_mouse(x,y);   //避免留下鼠标所在位置的背景
   
}
