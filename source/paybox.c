#include "common.h"
#include "paybox.h"

#define YES 1
#define NOT 0
#define REMAIN 1
#define PAYMETHOD 2

//钱包弹出框
void pay_box(int* x, int* y,USEINFOR *infor)
{
    int button=0;
    int mx=0;
    int my=0;
    char ch[15];//用于暂时存储余额转换的字符串
    mousehide(*x,*y);

    save_image(83,109,683,659,"pay");

    //画图
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(340,135,3,3,"钱包",44373);
    bar(88,200,678,230,63422);
    linelevel(88,368,678,368,5,63422);
    linelevel(88,510,678,510,5,63422);

    fdhz(200,285,2,2,"余额",44373);
    sprintf(ch,"%.2f",infor->money);
    outtextxy(360,285,ch,2,2,20,44373);
    fdhz(200,423,2,2,"充值",44373);
    fdhz(200,565,2,2,"支付方式",44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉
    
    reset_mouse(x,y);
    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        {
            exit(0);
        }
        else if(mx>=88 && mx<=678 && my>=369 && my<=509 && button)//充值
        {
            top_up (x,y,infor);
            // 、更新余额
            bar(300,280,650,320,65535);
            sprintf(ch,"%.2f",infor->money);
            outtextxy(360,285,ch,2,2,20,44373);
        }
        else if(mx>=88 && mx<=678 && my>=511 && my<=657 && button)//支付方式
        {
            pay_way(x,y,infor);
        }
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//点击红叉返回
        {
            break;
        }
        
    }

    
    mousehide(*x,*y);  //隐藏鼠标
    printf_image(83,109,683,659,"pay");
    
    reset_mouse(x,y);   //避免留下鼠标所在位置的背景
   
}

//充值
void top_up(int *x,int *y,USEINFOR *infor)
{
    int button = 0;
    int mx = 0;
    int my = 0;
    int topmoney = 0;//充入的金额
    char flag1 = NOT;//判断是否选择金额
    char flag2 = NOT;//判断是否选择充值方式
    // char ch[15];//暂时存金额
    mousehide(*x,*y);

    //保存背景
    save_image(83,109,683,659,"topup");
    //画图
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(340,135,3,3,"钱包",44373);
    bar(88,200,678,230,63422);
    linelevel(88,368,678,368,5,63422);
    linelevel(88,510,678,510,5,63422);
    //遮盖
    bar(88,231,678,580,65535);
    bar(98,580,670,630,65535);
    
    linelevel(88,270,335,270,3,63422);
    linelevel(431,270,678,270,3,63422);
    fdhz(345,265,1,1,"充值金额",44373);

    bar(135,300-2,135+134,300+84,44373);
    bar(135+2,300,135+132,300+80,65535);
    outtextxy(137+20,325,"20",2,2,20,44373);
    fdhz(137+85,325,2,2,"元",44373);

    bar(316,300-2,316+134,300+84,44373);
    bar(316+2,300,316+132,300+80,65535);
    outtextxy(318+20,325,"50",2,2,20,44373);
    fdhz(318+85,325,2,2,"元",44373);
    
    bar(497,300-2,497+134,300+84,44373);
    bar(497+2,300,497+132,300+80,65535);
    outtextxy(499+10,325,"100",2,2,20,44373);
    fdhz(499+85,325,2,2,"元",44373);

    linelevel(88,410,335,410,3,63422);
    linelevel(431,410,678,410,3,63422);
    fdhz(345,405,1,1,"充值方式",44373);

    // 画微信
    bar_round(255-30,480,70,70,22,1,2016);//微信绿
    FillCircle(221,480,20,65535);
    FillCircle(241,490,15,2016);
    FillCircle(241,490,13,65535);
    FillCircle(241-6,490-2,2,2016);
    FillCircle(241+6,490-2,2,2016);
    FillCircle(221-9,480-3,2,2016);
    FillCircle(221+9,480-3,2,2016);
    //画支付宝
    bar_round(510-30,480,70,70,22,1,1535);//支付宝蓝
    fdhz(455,450,4,4,"支",65535);


    bar_round(383,600,196,52,20,1,44373);
    bar_round(383,600,190,47,18,1,65535);
    fdhz(337,586,2,2,"确",44373);
    fdhz(397,586,2,2,"定",44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉
    //显示鼠标
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        {
            exit(0);
        }
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//点击红叉返回
        {
            break;
        }
        else if (mx>=135  && mx<=269 && my>=298 && my<=384 && button)//点击20元
        {
            mousehide(*x,*y);
            //标亮
            bar(135,300-2,135+134,300+84,64384);
            bar(135+2,300,135+132,300+80,65535);
            outtextxy(137+20,325,"20",2,2,20,64384);
            fdhz(137+85,325,2,2,"元",64384);
            //变灰
            bar(316,300-2,316+134,300+84,44373);
            bar(316+2,300,316+132,300+80,65535);
            outtextxy(318+20,325,"50",2,2,20,44373);
            fdhz(318+85,325,2,2,"元",44373);

            
            bar(497,300-2,497+134,300+84,44373);
            bar(497+2,300,497+132,300+80,65535);
            outtextxy(499+10,325,"100",2,2,20,44373);
            fdhz(499+85,325,2,2,"元",44373);

            reset_mouse(x,y);

            topmoney = 20;
            flag1 = YES;

        }
        else if (mx>=316  && mx<=450 && my>=298 && my<=384 && button)//点击50元
        {
            mousehide(*x,*y);
            //标亮
            bar(316,300-2,316+134,300+84,64384);
            bar(316+2,300,316+132,300+80,65535);
            outtextxy(318+20,325,"50",2,2,20,64384);
            fdhz(318+85,325,2,2,"元",64384);
            //变灰
            bar(135,300-2,135+134,300+84,44373);
            bar(135+2,300,135+132,300+80,65535);
            outtextxy(137+20,325,"20",2,2,20,44373);
            fdhz(137+85,325,2,2,"元",44373);

            bar(497,300-2,497+134,300+84,44373);
            bar(497+2,300,497+132,300+80,65535);
            outtextxy(499+10,325,"100",2,2,20,44373);
            fdhz(499+85,325,2,2,"元",44373);

            reset_mouse(x,y);

            topmoney = 50;
            flag1 = YES;
        }
        else if (mx>=497  && mx<=631 && my>=298 && my<=384 && button)//点击100元
        {
            mousehide(*x,*y);
            //标亮
            bar(497,300-2,497+134,300+84,64384);
            bar(497+2,300,497+132,300+80,65535);
            outtextxy(499+10,325,"100",2,2,20,64384);
            fdhz(499+85,325,2,2,"元",64384);
        
            //变灰
            bar(135,300-2,135+134,300+84,44373);
            bar(135+2,300,135+132,300+80,65535);
            outtextxy(137+20,325,"20",2,2,20,44373);
            fdhz(137+85,325,2,2,"元",44373);

            bar(316,300-2,316+134,300+84,44373);
            bar(316+2,300,316+132,300+80,65535);
            outtextxy(318+20,325,"50",2,2,20,44373);
            fdhz(318+85,325,2,2,"元",44373);

            reset_mouse(x,y);

            topmoney = 100;
            flag1 = YES;
        }
        else if (mx>=190  && mx<=260 && my>=445 && my<=515 && button)//点击微信
        {
            mousehide(*x,*y);
            
            //遮支付宝的钩
            bar(525,490-22,525+60,490+13,65535);//遮支付宝的钩

            lean_line_thick(280,490,15,45,3,64384);//打钩(微信)
	        lean_line_thick(280+11,490+8,40,-45,3,64384);

            // changePay(infor,2,1);
            reset_mouse(x,y);
            flag2 = YES;
        }
        else if (mx>=445  && mx<=515 && my>=445 && my<=515 && button)//点击支付宝
        {
            mousehide(*x,*y);

            bar(270,490-22,270+60,490+13,65535);//遮微信的钩

            lean_line_thick(535,490,15,45,3,64384);//打钩(支付宝)
	        lean_line_thick(535+11,490+8,40,-45,3,64384);

            reset_mouse(x,y);
            flag2 = YES;
        }
        else if (mx>=285  && mx<=481 && my>=573 && my<=627 && button)//点击确定
        {
            if (flag1 == YES && flag2 == YES)
            {
                mousehide(*x,*y);
                bar_round(383,600,196,52,20,1,64384);
                bar_round(383,600,190,47,18,1,65535);
                fdhz(337,586,2,2,"确",64384);
                fdhz(397,586,2,2,"定",64384);

                bar_round(383,384,416,270,50,1,64384);
                bar_round(383,384,410,265,48,1,65535);
                fdhz(311,360,2,2,"充值成功",64384);
                fdhz(331,420,1,1,"按任意键继续",44373);
                getch();
                reset_mouse(x,y);
                changePay(infor,REMAIN,topmoney);
                break;
            }
            else
            {
                mousehide(*x,*y);
                save_image(383-210,384-140,383+210,384+140,"notchose");
                bar_round(383,384,416,270,50,1,64384);
                bar_round(383,384,410,265,48,1,65535);
                fdhz(241,340,2,2,"请选择充值金额",64384);
                fdhz(286,380,2,2,"与充值方式",64384);
                
                fdhz(331,430,1,1,"按任意键继续",44373);
                getch();
                printf_image(383-210,384-140,383+210,384+140,"notchose");
                reset_mouse(x,y);
            } 
        }
        
    }

    //显示背景
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"topup");

    // bar(300,280,650,320,65535);

    // sprintf(ch,"%.2f",infor->money);
    // outtextxy(360,285,ch,2,2,20,44373);
    reset_mouse(x,y);
}
//支付方式
void pay_way(int *x,int *y, USEINFOR *infor)
{
    int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);
    //保存背景
    save_image(83,109,683,659,"payway");
    //画图
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(340,135,3,3,"钱包",44373);
    bar(88,200,678,230,63422);
    linelevel(88,368,678,368,5,63422);
    linelevel(88,510,678,510,5,63422);

    bar(88,231,678,580,65535);
    bar(98,580,670,630,65535);
    
    linelevel(88,270,335,270,3,63422);
    linelevel(431,270,678,270,3,63422);
    fdhz(345,265,1,1,"支付方式",44373);

    linelevel(88,397,678,397,3,63422);
    linelevel(88,524,678,524,3,63422);

    // bar(135-5,333-3,135+80,333+22,0);
    // bar(135+90,333-20,135+140,333+13,0);
    fdhz(135,333,1,1,"余额支付",44373);
    fdhz(400,333,1,1,"可享九折优惠",64384);
    fdhz(135,460,1,1,"微信支付",44373);
    fdhz(135,587,1,1,"支付宝支付",44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉

    if (infor->payway == 1)
    {
        // bar(125,290,170,350,65535);
        fdhz(135,333,1,1,"余额支付",64384);
        lean_line_thick(230,333,15,45,3,64384);//打钩
	    lean_line_thick(230+11,333+8,40,-45,3,64384);
    }
    else if(infor->payway == 2)
    {
        fdhz(135,460,1,1,"微信支付",64384);
        lean_line_thick(230,460,15,45,3,64384);//打钩
	    lean_line_thick(230+11,460+8,40,-45,3,64384);
    }
    else if (infor->payway == 3)
    {
        fdhz(135,587,1,1,"支付宝支付",64384);
        lean_line_thick(250,587,15,45,3,64384);//打钩
	    lean_line_thick(250+11,587+8,40,-45,3,64384);
    }
    
    //返回键
    bar_round(976,664,76,44,15,1,64384);
    bar_round(976,664,70,39,13,1,65535);
    outtextxy(938,645,"Back",2,2,15,64384);
    //显示鼠标
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        {
            exit(0);
        }
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//点击红叉返回
        {
            break;
        }
        else if (mx>=88 && mx<=678 && my>=270 && my<=397 && button)//选余额
        {
            mousehide(*x,*y);
            bar(135-5,460-3,135+80,460+22,65535);//遮微信
            bar(135+90,460-22,135+140,460+13,65535);
            bar(135-5,587-3,135+100,587+22,65535);//遮支付宝
            bar(135+110,587-22,135+160,587+13,65535);
            
            fdhz(135,460,1,1,"微信支付",44373);
            fdhz(135,587,1,1,"支付宝支付",44373);

            fdhz(135,333,1,1,"余额支付",64384);
            lean_line_thick(230,333,15,45,3,64384);//打钩
	        lean_line_thick(230+11,333+8,40,-45,3,64384);
            changePay(infor,PAYMETHOD,1);
            reset_mouse(x,y);
        }
        else if (mx>=88 && mx<=678 && my>=397 && my<=524 && button)//选微信
        {
            mousehide(*x,*y);
            bar(135-5,333-3,135+80,333+22,65535);//遮余额
            bar(135+90,333-22,135+140,333+13,65535);
            bar(135-5,587-3,135+100,587+22,65535);//遮支付宝
            bar(135+110,587-22,135+160,587+13,65535);

            fdhz(135,333,1,1,"余额支付",44373);
            fdhz(135,587,1,1,"支付宝支付",44373);

            fdhz(135,460,1,1,"微信支付",64384);
            lean_line_thick(230,460,15,45,3,64384);//打钩
	        lean_line_thick(230+11,460+8,40,-45,3,64384);
            changePay(infor,PAYMETHOD,2);
            reset_mouse(x,y);
        }
        else if (mx>=88 && mx<=678 && my>=524 && my<=655 && button)//选支付宝
        {
            mousehide(*x,*y);
            bar(135-5,333-3,135+80,333+22,65535);//遮余额
            bar(135+90,333-22,135+140,333+13,65535);
            bar(135-5,460-3,135+80,460+22,65535);//遮微信
            bar(135+90,460-22,135+140,460+13,65535);

            fdhz(135,333,1,1,"余额支付",44373);
            fdhz(135,460,1,1,"微信支付",44373);

            fdhz(135,587,1,1,"支付宝支付",64384);
            lean_line_thick(250,587,15,45,3,64384);//打钩
	        lean_line_thick(250+11,587+8,40,-45,3,64384);
            changePay(infor,PAYMETHOD,3);
            reset_mouse(x,y);
        }
        
    }

    //显示背景
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"payway");
    // //对BACK键进行遮挡
    // bar_round(976,664,76,44,15,1,65523);
    reset_mouse(x,y);
}

