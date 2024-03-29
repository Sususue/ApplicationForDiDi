#include "common.h"
#include "cartake.h"
#define NOW -1
#define AIM 1
#define FASTNUM 5
#define PLACENUM 6
#define UNCHOOSE -1
#define CCT 8

void car_take_box(int* x, int* y, USEINFOR *infor)
{
	int button=0;
    int mx=0;
    int my=0;
    int waitime=0;//用于判断预约时间
    int mincar=0;//用于记录最近的那辆车
    int aimplace=UNCHOOSE;//记录目标位置
    // CARFAST car[FASTNUM];//车辆群数组
    PLACE fastplace[FASTNUM];//几个车的位置
    // CARFA car[FASTNUM];//车辆群数组
    CARFA car;
    

    PLACE location[PLACENUM];//几个地点
    char *placename[PLACENUM]={NULL};//几个地点对应的名字

    //初始化车辆位置
    fastplace[0].x=240;
    fastplace[0].y=465;
    fastplace[1].x=130;
    fastplace[1].y=25;
    fastplace[2].x=310;
    fastplace[2].y=719;
    fastplace[3].x=590;
    fastplace[3].y=269;
    fastplace[4].x=715;
    fastplace[4].y=680;
    //初始化几个地点
    location[0].x=130;//大学
    location[0].y=440;
    location[1].x=212;//小区
    location[1].y=695;
    location[2].x=395;//东湖
    location[2].y=25;
    location[3].x=370;//商场
    location[3].y=490;
    location[4].x=686;//图书馆
    location[4].y=560;
    location[5].x=450;//游泳馆
    location[5].y=243;

    //初始化地点名字
    placename[0]="大学";
    placename[1]="小区";
    placename[2]="东湖";
    placename[3]="商场";
    placename[4]="图书馆"; 
    placename[5]="游泳馆";

    // newfastcar(car);//初始化车辆

    mousehide(*x,*y);
    //保存背景
    save_image(771,2,996,612,"cartake");
    save_image(location[0].x-13,location[0].y-34,location[0].x+13,location[0].y+5,"school");
    save_image(location[1].x-13,location[1].y-34,location[1].x+13,location[1].y+5,"xiaoqu");
    save_image(location[2].x-13,location[2].y-34,location[2].x+13,location[2].y+5,"lake");
    save_image(location[3].x-13,location[3].y-34,location[3].x+13,location[3].y+5,"market");
    save_image(location[4].x-13,location[4].y-34,location[4].x+13,location[4].y+5,"labrary");
    save_image(location[5].x-13,location[5].y-34,location[5].x+13,location[5].y+5,"pool");
	
    //画图
	//底色
    bar(771,2,996,612,65523);
	
	//快车
	bar_round(896,90,196,96,25,1,64384);
    bar_round(896,90,190,91,23,1,65535);
    fdhz(840,67,3,3,"快",64384);
    fdhz(900,67,3,3,"车",64384);
	
	//当前位置
    bar_round(896,198,196,52,10,1,64384);
    bar_round(896,198,190,47,8,1,65535);
    fdhz(810,190,1,1,"当前位置",64384);
	outtextxy(885,188,":",1,1,40,64384);
    //显示当前位置
    showplace(infor->nowplace,NOW,location,placename);
   
    //选择目的地
	bar_round(896,288,196,52,10,1,64384);
    bar_round(896,288,190,47,8,1,65535);
    fdhz(820,280,1,1,"选",64384);
    fdhz(855,280,1,1,"择",64384);
    fdhz(890,280,1,1,"目",64384);
    fdhz(925,280,1,1,"的",64384);
	fdhz(960,280,1,1,"地",64384);
	
	//预计价格
	bar_round(896,378,196,52,10,1,64384);
    bar_round(896,378,190,47,8,1,65535);
    fdhz(810,370,1,1,"预计价格",64384);
	fdhz(970,370,1,1,"元",64384);
	outtextxy(885,368,":",1,1,40,64384);
	
	//即时
	bar_round(847,468,90,52,10,1,44373);
    bar_round(847,468,84,47,8,1,65535);
    fdhz(830,460,1,1,"即时",44373);
	
	//预约
	bar_round(945,468,90,52,10,1,64384);
    bar_round(945,468,84,47,8,1,65535);
    fdhz(928,460,1,1,"预约",64384);
	
	//呼叫快车
	bar_round(896,558,196,52,10,1,64384);
    bar_round(896,558,190,47,8,1,65535);
    fdhz(825,550,1,1,"呼",64384);
    fdhz(865,550,1,1,"叫",64384);
    fdhz(905,550,1,1,"快",64384);
    fdhz(945,550,1,1,"车",64384);
	
	//小车初始位置
	// car_draw_right1(car[0].fastcar.x,car [0].fastcar.y);//学校和商场之间
	// car_draw_right1(car[1].fastcar.x,car [1].fastcar.y);//东湖
	// car_draw_left1(car[2].fastcar.x,car [2].fastcar.y);//小区
	// car_draw_left1(car[3].fastcar.x,car [3].fastcar.y);//游泳馆
	// car_draw_on1(car[4].fastcar.x,car [4].fastcar.y);//图书馆
    car_draw_right1(fastplace[0].x,fastplace[0].y);//学校和商场之间
	car_draw_right1(fastplace[1].x,fastplace[1].y);//东湖
	car_draw_left1(fastplace[2].x,fastplace[2].y);//小区
	car_draw_left1(fastplace[3].x,fastplace[3].y);//游泳馆
	car_draw_on1(fastplace[4].x,fastplace[4].y);//图书馆
	
    //存图
    save_image(1,1,1023,767,"drivinfo");
	//显示鼠标
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            if (aimplace!=UNCHOOSE)
            {
                starttoendroad(infor->nowplace,aimplace,65535);
            }
            
            //对地图上原有的小车进行遮挡
            // bar_round(car[0].fastcar.x,car [0].fastcar.y,42,22,2,1,65535);
            // bar_round(car[1].fastcar.x,car [1].fastcar.y,42,22,2,1,65535);
            // bar_round(car[2].fastcar.x,car [2].fastcar.y,42,22,2,1,65535);
            // bar_round(car[3].fastcar.x,car [3].fastcar.y,42,22,2,1,65535);
            // bar_round(car[4].fastcar.x,car [4].fastcar.y,22,42,2,1,65535);
            bar_round(fastplace[0].x,fastplace[0].y,42,22,2,1,65535);
            bar_round(fastplace[1].x,fastplace[1].y,42,22,2,1,65535);
            bar_round(fastplace[2].x,fastplace[2].y,42,22,2,1,65535);
            bar_round(fastplace[3].x,fastplace[3].y,42,22,2,1,65535);
            bar_round(fastplace[4].x,fastplace[4].y,22,42,2,1,65535);
            break;
        }
        // else if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
        // {
        //     safe_box(x,y);
        // }
		else if (mx>=798  && mx<=994 && my>=265 && my<=311 && button)//点击选择目的地，进入目的地选择进程
        {
            bar_round(fastplace[0].x,fastplace[0].y,42,22,2,1,65535);
            bar_round(fastplace[1].x,fastplace[1].y,42,22,2,1,65535);
            bar_round(fastplace[2].x,fastplace[2].y,42,22,2,1,65535);
            bar_round(fastplace[3].x,fastplace[3].y,42,22,2,1,65535);
            bar_round(fastplace[4].x,fastplace[4].y,22,42,2,1,65535);
            choose_aimplace(x,y,&aimplace,location,infor,placename);
            changecar(&car,fastplace[aimplace].x,fastplace[aimplace].y);
        }
		else if (mx>=798  && mx<=994 && my>=532 && my<=584 && button)//点击呼叫快车，弹出司机信息框
        {
            if(aimplace == UNCHOOSE) //避免不选目的地就直接点击呼叫快车
            {
                mousehide(*x,*y);

                save_image(512-210,384-140,512+210,384+140,"unchoose");
                bar_round(512,384,416,270,50,1,64384);
                bar_round(512,384,410,265,48,1,65535);
                fdhz(400,360,2,2,"请选择目的地",64384);
                
                fdhz(450,420,1,1,"按任意键继续",44373);
                getch();
                printf_image(512-210,384-140,512+210,384+140,"unchoose");
                reset_mouse(x,y);
            }
            else
            {
                mincar=desidecar(infor->nowplace,fastplace,location);//判断哪辆车来接送
			    driver_info(x,y,infor,&car,location,placename,&aimplace,mincar,waitime);
            }
		}
		else if (mx>=900  && mx<=990 && my>=442 && my<=494 && button)//点击预约，弹出预约选择弹框
        {
			waitime=pre_appoint(x,y);
		}
		else if (mx>=802  && mx<=892 && my>=442 && my<=494 && button)//点击即时，返回为即时的状态
        {
			immediate(x,y);
            waitime=0;
		}
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        {
            exit(0);
        }
    }

    //显示背景
    mousehide(*x,*y); 

    printf_image(771,2,996,612,"cartake");
    printf_image(location[0].x-13,location[0].y-34,location[0].x+13,location[0].y+5,"school");
    printf_image(location[1].x-13,location[1].y-34,location[1].x+13,location[1].y+5,"xiaoqu");
    printf_image(location[2].x-13,location[2].y-34,location[2].x+13,location[2].y+5,"lake");
    printf_image(location[3].x-13,location[3].y-34,location[3].x+13,location[3].y+5,"market");
    printf_image(location[4].x-13,location[4].y-34,location[4].x+13,location[4].y+5,"labrary");
    printf_image(location[5].x-13,location[5].y-34,location[5].x+13,location[5].y+5,"pool");
    // bar(location[0].x-3,location[0].y-3,location[0].x+3,location[0].y+3,57083);
    // bar(location[1].x-3,location[1].y-3,location[1].x+3,location[1].y+3,57083);
    // bar(location[2].x-3,location[2].y-3,location[2].x+3,location[2].y+3,57083);
    // bar(location[3].x-3,location[3].y-3,location[3].x+3,location[3].y+3,57083);
    // bar(location[4].x-3,location[4].y-3,location[4].x+3,location[4].y+3,57083);
    // bar(location[5].x-3,location[5].y-3,location[5].x+3,location[5].y+3,57083);

    reset_mouse(x,y);
}


/***************************
点击呼叫快车，产生司机信息框
****************************/
void driver_info(int *x,int *y, USEINFOR *infor, CARFA *car, const PLACE *location,/*  const  */char **placename, int *aimplace, int mincar,int waitime)
{
	int button=0;
    int mx=0;
    int my=0;
    int flag=1;//判断退出
    int sigle=0;//用于接力退出的判断
    // int place;//暂存
    float price;
    int callstyle;
    struct tm *info;//用于点击立即上车时的时间
	char buffer[80];//格式化输出时间字符串的数组
	time_t rawtime1;//用于获取进入呼叫快车进程的时间
	time_t rawtime2;//用于预约时间的判断
	time_t rawtime3;//用于获取当前时间
	time_t rawtime4;//用于时间价格计算
	int time_gap;//用于预约中时间间隔的判断
	int time_gap1;//用于时间价格计算
	int nowtime_hour;//获取进入呼叫快车进程时的时间
	// int nowtime_min;
	// int nowtime_sec;
	// //用于判断的时间
	// int judgetime_hour;
	// int judgetime_min;
	// int judgetime_sec;

    time(&rawtime1);//获取GMT时间
    info = gmtime(&rawtime1);//根据当前的time_t获得对应的结构体
    nowtime_hour=info->tm_hour;
	// nowtime_min=info->tm_min;
	// nowtime_sec=info->tm_sec;
    
    mousehide(*x,*y);
	
    
	//保存背景
    // save_image(771,2,996,612,"drivinfo");
    // save_image(1,1,1023,767,"drivinfo");
	bar(location[0].x-3,location[0].y-3,location[0].x+3,location[0].y+3,57083);
    bar(location[1].x-3,location[1].y-3,location[1].x+3,location[1].y+3,57083);
    bar(location[2].x-3,location[2].y-3,location[2].x+3,location[2].y+3,57083);
    bar(location[3].x-3,location[3].y-3,location[3].x+3,location[3].y+3,57083);
    bar(location[4].x-3,location[4].y-3,location[4].x+3,location[4].y+3,57083);
    bar(location[5].x-3,location[5].y-3,location[5].x+3,location[5].y+3,57083);
	// printf_image(location[0].x-13,location[0].y-34,location[0].x+13,location[0].y+5,"school");
    // printf_image(location[1].x-13,location[1].y-34,location[1].x+13,location[1].y+5,"xiaoqu");
    // printf_image(location[2].x-13,location[2].y-34,location[2].x+13,location[2].y+5,"lake");
    // printf_image(location[3].x-13,location[3].y-34,location[3].x+13,location[3].y+5,"market");
    // printf_image(location[4].x-13,location[4].y-34,location[4].x+13,location[4].y+5,"labrary");
    // printf_image(location[5].x-13,location[5].y-34,location[5].x+13,location[5].y+5,"pool");
    
    showplace(infor->nowplace,NOW,location,placename);
    showplace(*aimplace,AIM,location,placename);

	//底色
    bar(771,2,996,612,65523);
	
	
	//司机的姓
	bar_round(896,90,196,96,25,1,64384);
    bar_round(896,90,190,91,23,1,65535);
    fdhz(817,67,3,3,car->name,64384);
    fdhz(877,67,3,3,"师",64384);
	fdhz(937,67,3,3,"傅",64384);
	
	//车牌号码
    bar_round(896,198,196,52,10,1,64384);
    bar_round(896,198,190,47,8,1,65535);
    fdhz(810,190,1,1,"车牌",64384);
	outtextxy(847,188,":",1,1,40,64384);
    fdhz(862,190,1,1,"鄂",64384);
    outtextxy(878,190,"A-",1,1,15,64384);

    outtextxy(910,190,car->fastcar.carname,1,1,15,64384);
   
    //车型
	bar_round(896,288,196,52,10,1,64384);
    bar_round(896,288,190,47,8,1,65535);
	fdhz(810,280,1,1,"车型",64384);
    outtextxy(847,278,":",1,1,40,64384);
    // outtextxy(862,278,car[0].fastcar.type,1,1,40,64384);
    fdhz(870,280,1,1,car->fastcar.type,64384);
   
	//取消订单
	bar_round(896,378,196,52,10,1,64384);
    bar_round(896,378,190,47,8,1,65535);
    fdhz(825,370,1,1,"取",64384);
    fdhz(865,370,1,1,"消",64384);
    fdhz(905,370,1,1,"订",64384);
    fdhz(945,370,1,1,"单",64384);
	
	//等待上车
	bar_round(896,468,196,52,10,1,64384);
    bar_round(896,468,190,47,8,1,65535);
    fdhz(825,460,1,1,"等",64384);
    fdhz(865,460,1,1,"待",64384);
    fdhz(905,460,1,1,"上",64384);
    fdhz(945,460,1,1,"车",64384);
	
	//进度条
	bar_round(896,558,196,52,10,1,64384);
    bar_round(896,558,190,47,8,1,65535);
    fdhz(825,550,1,1,"进",64384);
    fdhz(865,550,1,1,"度",64384);
    fdhz(905,550,1,1,"显",64384);
    fdhz(945,550,1,1,"示",64384);
	
    // //对地图上原有的小车进行遮挡
	// bar_round(car[0].fastcar.x,car [0].fastcar.y,42,22,2,1,65535);
	// bar_round(car[1].fastcar.x,car [1].fastcar.y,42,22,2,1,65535);
	// bar_round(car[2].fastcar.x,car [2].fastcar.y,42,22,2,1,65535);
	// bar_round(car[3].fastcar.x,car [3].fastcar.y,42,22,2,1,65535);
	// bar_round(car[4].fastcar.x,car [4].fastcar.y,22,42,2,1,65535);
	
	//对BACK键进行遮挡
    bar_round(976,664,76,44,15,1,65523);

	
	//显示鼠标
    reset_mouse(x,y);
    switch(waitime)
	{
	    case 15:
			mousehide(*x,*y);
		
		    save_image(512-210,384-140,512+210,384+140,"pre11");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
			outtextxy(380,360,"30",2,2,30,64384);
            fdhz(450,360,2,2,"分钟后发车",64384);
            fdhz(450,420,1,1,"按任意键继续",44373);
            getch();
            printf_image(512-210,384-140,512+210,384+140,"pre11");
			reset_mouse(x,y);
			
		break;
		
		case 30:
			mousehide(*x,*y);
			
		    save_image(512-210,384-140,512+210,384+140,"pre12");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
			outtextxy(380,360,"60",2,2,30,64384);
            fdhz(450,360,2,2,"分钟后发车",64384);
			fdhz(450,420,1,1,"按任意键继续",44373);
            getch();
            printf_image(512-210,384-140,512+210,384+140,"pre12");
			reset_mouse(x,y);
		break;
		
		case 45:
			mousehide(*x,*y);
			
		    save_image(512-210,384-140,512+210,384+140,"pre13");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
			outtextxy(380,360,"90",2,2,30,64384);
            fdhz(450,360,2,2,"分钟后发车",64384);
			fdhz(450,420,1,1,"按任意键继续",44373);
            getch();
            printf_image(512-210,384-140,512+210,384+140,"pre13");
			reset_mouse(x,y);
		break;
	}
    while(waitime!=0)
	{
		newxy(x,y,&button);
		mx = *x;
		my = *y;
		
		 if(mx>=798  && mx<=994 && my>=352 && my<=404 && button)//点击取消订单返回
        {
            flag=cancelorder(x,y,infor);
            if (flag==0)
            {
                *aimplace = UNCHOOSE;
                waitime=0;
                break;
            }
        }
		
		time(&rawtime2);//获取GMT时间
		//info = gmtime(&rawtime2);//根据当前的time_t获得对应的结构体
		time_gap=difftime(rawtime2,rawtime1);
		if(time_gap>=waitime)
		{
            mousehide(*x,*y);
            save_image(512-210,384-140,512+210,384+140,"notice");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            fdhz(410,360,2,2,"预约时间到了",64384);
			fdhz(450,420,1,1,"按任意键继续",44373);
            getch();
            printf_image(512-210,384-140,512+210,384+140,"notice");
            reset_mouse(x,y);
			break;
		}
	}
	// 显示过来的动画
    if (flag==1)
    {
        cartostart(infor->nowplace,mincar,x,y);
        
        time(&rawtime3);//获取上车GMT时间
        // info = gmtime(&rawtime3);
        info = localtime(&rawtime3);
		sprintf(buffer,"%d.%02d.%02d",(info->tm_year+1900),(info->tm_mon+1),info->tm_mday);

        //等待上车变成立即上车，且标亮(灰色)
        mousehide(*x,*y);
        bar_round(896,468,196,52,10,1,44373);
        bar_round(896,468,190,47,8,1,65535);
        fdhz(825,460,1,1,"立",44373);
        fdhz(865,460,1,1,"刻",44373);
        fdhz(905,460,1,1,"上",44373);
        fdhz(945,460,1,1,"车",44373);

        // 安全
        bar_round(862,693,120,92,25,1,64384);
        bar_round(862,693,114,85,23,1,65535);
        fdhz(815,668,3,3,"安",64384);
        fdhz(860,668,3,3,"全",64384);
        reset_mouse(x,y);
    }
    
    
            /*time(&rawtime);//获取GMT时间
			info = gmtime(&rawtime);//根据当前的time_t获得对应的结构体
			sprintf(judgetime_year,"%d",(info->tm_year+1900));
			sprintf(judgetime_mon,"%d",(info->tm_mon+1));
			sprintf(judgetime_mday,"%d",info->tm_mday);
			sprintf(judgetime_hour,"%d",(info->tm_hour+CCT)%24+12);
			sprintf(judgetime_min,"%d",(info->tm_min+1));
			sprintf(judgetime_sec,"%d",(info->tm_sec+1));
			
			outtextxy(350,150,judgetime_year,2,2,30,64384);
			outtextxy(350,180,judgetime_mon,2,2,30,64384);
			outtextxy(350,210,judgetime_mday,2,2,30,64384);
			outtextxy(350,240,judgetime_hour,2,2,30,64384);
			outtextxy(350,270,judgetime_min,2,2,30,64384);
			outtextxy(350,300,judgetime_sec,2,2,30,64384);*/
	while (flag==1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=798  && mx<=994 && my>=352 && my<=404 && button)//点击取消订单返回
        {
			flag=cancelorder(x,y,infor);
            if (flag==0)
            {
                // changecar(&car[*aimplace]);
                *aimplace = UNCHOOSE;
                waitime=0;
                break;
            }
        }
        // else if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
        // {
        //     safe_box(x,y);
        // }
        // else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        // {
        //     exit(0);
        // }
		else if (mx>=798  && mx<=994 && my>=416 && my<=520 && button)//点击立刻/等待上车显示车行动画
		{	
            mousehide(*x,*y);
            //“进度显示”消失，开始显示百分比
			bar_round(896,558,196,52,10,1,64384);
			bar_round(896,558,190,47,8,1,65535);
			fdhz(825,550,1,1,"进度",64384);
			outtextxy(960,550,"%",1,1,10,64384);

            //重新变橙
            bar_round(896,468,196,52,10,1,64384);
            bar_round(896,468,190,47,8,1,65535);
            fdhz(825,460,1,1,"立",64384);
            fdhz(865,460,1,1,"刻",64384);
            fdhz(905,460,1,1,"上",64384);
            fdhz(945,460,1,1,"车",64384);
            reset_mouse(x,y);
            //确定动画
            sigle=starttoend(infor->nowplace,*aimplace,x,y);
            if(sigle!=0)//用于安全报警后的接力退出
			{
                callstyle= catchBox(x,y);
                changecall(car,callstyle);
                // changecar(&car[*aimplace]);
                *aimplace = UNCHOOSE;
                waitime=0;
				break;
			}
            else
            {
                time(&rawtime4);//获取GMT时间
				time_gap1=difftime(rawtime4,rawtime3);
                //计算价格并扣费
                costmoney(&price,infor,aimplace,nowtime_hour,time_gap1,x,y,waitime);
                
                //生成订单并截图保存
                neworder(x,y,infor,car,placename,aimplace,/* mincar, */buffer,price);
                evaluate(x,y,car);
                //若成功到达目的地的，则修改当前位置
                changeNowplace(infor,*aimplace);
                *aimplace = UNCHOOSE; 
                waitime=0;
                break;
            }
		}
    }
	
	//显示背景
    mousehide(*x,*y); 

    // printf_image(771,2,996,612,"drivinfo");
    printf_image(1,1,1023,767,"drivinfo");
    //小车初始位置
	// car_draw_right1(car[0].fastcar.x,car [0].fastcar.y);//学校和商场之间
    // car_draw_right1(car[1].fastcar.x,car [1].fastcar.y);//东湖
    // car_draw_left1(car[2].fastcar.x,car [2].fastcar.y);//小区
    // car_draw_left1(car[3].fastcar.x,car [3].fastcar.y);//游泳馆
    // car_draw_on1(car[4].fastcar.x,car [4].fastcar.y);//图书馆
    // //返回键
    // bar_round(976,664,76,44,15,1,64384);
    // bar_round(976,664,70,39,13,1,65535);
	// outtextxy(938,645,"Back",2,2,15,64384);

    //遮掉所有点
    printf_image(location[0].x-13,location[0].y-34,location[0].x+13,location[0].y+5,"school");
    printf_image(location[1].x-13,location[1].y-34,location[1].x+13,location[1].y+5,"xiaoqu");
    printf_image(location[2].x-13,location[2].y-34,location[2].x+13,location[2].y+5,"lake");
    printf_image(location[3].x-13,location[3].y-34,location[3].x+13,location[3].y+5,"market");
    printf_image(location[4].x-13,location[4].y-34,location[4].x+13,location[4].y+5,"labrary");
    printf_image(location[5].x-13,location[5].y-34,location[5].x+13,location[5].y+5,"pool");

    //遮挡之前的目的地
    bar_round(896,288,196,52,10,1,64384);
    bar_round(896,288,190,47,8,1,65535);
    fdhz(820,280,1,1,"选",64384);
    fdhz(855,280,1,1,"择",64384);
    fdhz(890,280,1,1,"目",64384);
    fdhz(925,280,1,1,"的",64384);
    fdhz(960,280,1,1,"地",64384);

    //返回为即时状态
	bar_round(847,468,90,52,10,1,44373);
    bar_round(847,468,84,47,8,1,65535);
    fdhz(830,460,1,1,"即时",44373);
	
	bar_round(945,468,90,52,10,1,64384);
    bar_round(945,468,84,47,8,1,65535);
    fdhz(928,460,1,1,"预约",64384);
    //显示现在所在位置
    showplace(infor->nowplace,NOW,location,placename);

    reset_mouse(x,y);

	
}




//初始化快车车辆信息
// void newfastcar(CARFAST *car)
// void newfastcar(CARFA *car)
// {
//     int i;//用于计数
//     int n;//用于记录随机数
//     PLACE fastplace[FASTNUM];
//     FILE *fp = NULL;
//     // char carcard[10][6];//车牌号集
//     // char driver[10][3];//司机的姓
//     // char cartpye[6][7];//车辆类型
//     //初始化车的位置
//     fastplace[0].x=240;
//     fastplace[0].y=465;
//     fastplace[1].x=130;
//     fastplace[1].y=25;
//     fastplace[2].x=310;
//     fastplace[2].y=719;
//     fastplace[3].x=590;
//     fastplace[3].y=269;
//     fastplace[4].x=715;
//     fastplace[4].y=680;

    


//     srand((unsigned int)time(NULL));

//     if ((fp = fopen("driver\\usecar.txt", "rb+")) == NULL)
//   	{
// 	  	null_box(500,500);
// 	  	getch();
// 	  	exit(1);
//   	} 

//     for ( i = 0; i < FASTNUM; i++, car++)
//     {
//         n=rand()%10;
//         fseek(fp,sizeof(CARFA)*n,SEEK_SET);
//         fread(car,sizeof(CARFA),1,fp);
//         if (car->call == 1)
//         {
//             car->fastcar.x=fastplace[i].x;
//             car->fastcar.y=fastplace[i].y;
//             i++;
//             car++;
//         }
//     }
//     fclose(fp);
    
// }

// 更改司机
void changecar(CARFA *thiscar,int x, int y)
{
    
    int n;
    FILE *fp;

    if ((fp = fopen("driver\\usecar.txt", "rb+")) == NULL)
  	{
	  	null_box(500,500);
	  	getch();
	  	exit(1);
  	} 
    srand((unsigned int)time(NULL));
    while (1)
    {
        n=rand()%10;
        fseek(fp,sizeof(CARFA)*n,SEEK_SET);
        fread(thiscar,sizeof(CARFA),1,fp);
        if (thiscar->call==1)
        {
            thiscar->fastcar.x = x;
            thiscar->fastcar.y = y;
            break;
        }
        
    }
    fclose(fp);
}


int cancelorder(int *x, int *y, USEINFOR *infor)
{
    int mx;
    int my;
    int button;//确认鼠标是否点击
    int flag =1;
    mousehide(*x,*y);
    save_image(512-210,384-140,512+210,384+140,"cancel");
    bar_round(512,384,416,270,50,1,64384);
    bar_round(512,384,410,265,48,1,65535);
    fdhz(390,320,2,2,"司机已经接单",64384);
	fdhz(380,390,1,1,"现在取消需支付费用",64384);
    outtextxy(550,390,":",1,1,40,64384);
    outtextxy(565,390,"2.00",1,1,10,64384);
    fdhz(620,390,1,1,"元",64384);

    bar_round(423,460,130,52,20,1,64384);
    bar_round(423,460,124,47,18,1,65535);
    fdhz(385,455,1,1,"确认取消",64384);

    bar_round(601,460,130,52,20,1,64384);
    bar_round(601,460,124,47,18,1,65535);
    fdhz(580,455,1,1,"返回",64384);
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if (mx>=358  && mx<=488 && my>=434 && my<=486 && button)//确认取消
        {
            changeMoney(infor,3.00);
            flag = 0;
            break;
        }
        else if (mx>=536  && mx<=666 && my>=434 && my<=486 && button)//返回
        {
            break;
        }
        
        
    }
    mousehide(*x,*y);    
    printf_image(512-210,384-140,512+210,384+140,"cancel");
    reset_mouse(x,y);

    return flag;
}

// //初始化快车车辆信息
// void newfastcar(CARFAST *car)
// {
//     int i;//用于计数
//     int n;//用于记录随机数
//     PLACE fastplace[FASTNUM];
//     char carcard[10][6];//车牌号集
//     char driver[10][3];//司机的姓
//     char cartpye[6][7];//车辆类型
//     //初始化车的位置
//     fastplace[0].x=240;
//     fastplace[0].y=465;
//     fastplace[1].x=130;
//     fastplace[1].y=25;
//     fastplace[2].x=310;
//     fastplace[2].y=719;
//     fastplace[3].x=590;
//     fastplace[3].y=269;
//     fastplace[4].x=715;
//     fastplace[4].y=680;

//     //初始化车牌号集
    
//     strcpy(carcard[0],"7A128");
//     strcpy(carcard[1],"S116W");
//     strcpy(carcard[2],"0D789");
//     strcpy(carcard[3],"3D816");
//     strcpy(carcard[4],"QE722");
//     strcpy(carcard[5],"E289Q");
//     strcpy(carcard[6],"U0207");
//     strcpy(carcard[7],"02151");
//     strcpy(carcard[8],"L8553");
//     strcpy(carcard[9],"7L27D");

//     //初始化司机
//     strcpy(driver[0],"张");
//     strcpy(driver[1],"李");
//     strcpy(driver[2],"赵");
//     strcpy(driver[3],"王");
//     strcpy(driver[4],"孙");
//     strcpy(driver[5],"唐");
//     strcpy(driver[6],"马");
//     strcpy(driver[7],"刘");
//     strcpy(driver[8],"周");
//     strcpy(driver[9],"杨");

//     //初始化车辆类型
//     strcpy(cartpye[0],"朗逸");
//     strcpy(cartpye[1],"轩逸");
//     strcpy(cartpye[2],"卡罗拉");
//     strcpy(cartpye[3],"景逸");
//     strcpy(cartpye[4],"众泰");
//     strcpy(cartpye[5],"丰田");


//     srand((unsigned int)time(NULL));


//     for ( i = 0; i < FASTNUM; i++, car++)
//     {
//         n=rand()%10;
//         strcpy(car->name,driver[n]);
//         car->fastcar.x=fastplace[i].x;
//         car->fastcar.y=fastplace[i].y;
//         strcpy(car->fastcar.type,cartpye[n%6]);
//         strcpy(car->fastcar.carname,carcard[n]);
//     }
// }


// void initialize()