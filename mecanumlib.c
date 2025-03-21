/*
~Made by Taha & added to by Liam :)
Last Updated: 8 Feb 2025
*/

#include <kipr/wombat.h>
#include <stdlib.h>

int back_r = 0; // red wire up
int front_r = 1; // red wire up 
int front_l = 2; // black wire up 
int back_l = 3; // black wire up
// "up" means closer to the screen

void move(int vel0, int vel1, int vel2, int vel3){
	mav(back_r, vel0);
    mav(front_r, vel1);
    mav(front_l, vel2);
	mav(back_l, vel3);
}

void forward(int dist, int speed){
    cmpc(back_r);
    while (gmpc(back_r) < dist){
        mav(back_r, speed);
    	mav(front_r, speed);
    	mav(front_l, speed);
    	mav(back_l, speed);
    }
}

void backward(int dist, int speed){
    cmpc(back_r);
    while (abs(gmpc(back_r)) < dist){
        mav(back_r, -speed);
    	mav(front_r,-speed);
    	mav(front_l,-speed);
    	mav(back_l,-speed);
    }
}

void right(int dist, int speed){
    cmpc(back_r);
    while (abs(gmpc(back_r)) < dist){
        mav(back_r,speed);
    	mav(front_r,-speed);
    	mav(front_l,speed);
    	mav(back_l,-speed);
    }
}

void left(int dist, int speed){
    cmpc(back_r);
    while (abs(gmpc(back_r)) < dist){
        mav(back_r,-speed);
    	mav(front_r,speed);
    	mav(front_l,-speed);
    	mav(back_l,speed);
    }
}

void turn_right(int dist, int speed){
    cmpc(back_r);
	while (abs(gmpc(back_r)) < dist){
        mav(back_r,-speed);
    	mav(front_r,-speed);
    	mav(front_l,speed);
    	mav(back_l,speed);
    }
}

void turn_left(int dist, int speed){
    cmpc(back_r);
	while (abs(gmpc(back_r)) < dist){
        mav(back_r,speed);
    	mav(front_r,speed);
    	mav(front_l,-speed);
    	mav(back_l,-speed);
    }
}

void diag_r_forw(int dist, int speed){
    cmpc(back_r);
	while (abs(gmpc(back_r)) < dist){
        mav(back_r,speed);
    	mav(front_r,0);
    	mav(front_l,speed);
    	mav(back_l,0);
    }
}

void diag_l_forw(int dist, int speed){
    cmpc(front_r);
	while (abs(gmpc(front_r)) < dist){
        mav(back_r,0);
    	mav(front_r,speed);
    	mav(front_l,0);
    	mav(back_l,speed);
    }
}

void diag_l_back(int dist, int speed){
    cmpc(back_r);
	while (abs(gmpc(back_r)) < dist){
        mav(back_r,-speed);
    	mav(front_r,0);
    	mav(front_l,-speed);
    	mav(back_l,0);
    }
}

void diag_r_back(int dist, int speed){
    cmpc(front_r);
	while (abs(gmpc(front_r)) < dist){
        mav(back_r,0);
    	mav(front_r,-speed);
    	mav(front_l,0);
    	mav(back_l,-speed);
    }
}
void right_90(){
    turn_right(2100,800);
}
void left_90(){
    turn_left(2100,800);
}
void wait(int time)
{
    mav(back_r,0);
    mav(front_r,0);
    mav(front_l,0);
    mav(back_l,0);
    msleep(time);
}
void ssp(int servo, int position)
{
    set_servo_position(servo,position);
    msleep(250);
}
//square up on the black line - going forward
void forwsquare ()
{
while ((analog(0) < 900) || (analog(1) < 900))
        {
            if ((analog(0) > 900) && (analog(1) < 900))
            {
                mav(back_r,-300);
    	        mav(front_r,-300);
    	        mav(front_l,300);
    	        mav(back_l,300);
            }
            else if ((analog(0) < 900) && (analog(1) > 900))
            {
                mav(back_r,300);
    	        mav(front_r,300);
    	        mav(front_l,-300);
    	        mav(back_l,-300);
            }
            else
            {
                mav(back_r,400);
    	        mav(front_r,400);
    	        mav(front_l,400);
    	        mav(back_l,400);
            }
        }
        ao();
        msleep(200);
}

//square up on the black line - going backwards
void backsquare ()
{
while ((analog(0) < 900) || (analog(1) < 900))
        {
            if ((analog(0) > 900) && (analog(1) < 900))
            {
                mav(back_r,300);
    	        mav(front_r,300);
    	        mav(front_l,-300);
    	        mav(back_l,-300);
            }
            else if ((analog(0) < 900) && (analog(1) > 900))
            {
                mav(back_r,-300);
    	        mav(front_r,-300);
    	        mav(front_l,300);
    	        mav(back_l,300);
            }
            else
            {
                mav(back_r,-400);
    	        mav(front_r,-400);
    	        mav(front_l,-400);
    	        mav(back_l,-400);
            }
        }
        ao();
        msleep(200);
}

//follow the line
void follow (int distance)
{
	int counter = 0;
	while (counter < distance)
	{
		if (analog(1) > 1000)
		{
			mav(back_r,600);
    	    mav(front_r,600);
    	    mav(front_l,0);
    	    mav(back_l,0);
			counter += 1;
		}
		else
		{
			mav(back_r,0);
    	    mav(front_r,0);
    	    mav(front_l,600);
    	    mav(back_l,600);
			counter += 1;
		}
	}
}
//move servo up slowly
void upslow (int arm, int initial, int final, int speed)
{	
	set_servo_position(arm, initial);
    msleep(500);
    int counter = initial;
    while (get_servo_position(arm) < final) 
    {
        set_servo_position(arm, counter);
        counter = counter + speed;
        msleep(20);
    }
}

//move servo down slowly
void downslow (int arm, int initial, int final, int speed)
{	
	set_servo_position(arm, initial);
    msleep(500);
    int counter = initial;
    while (get_servo_position(arm) > final) 
    {
        set_servo_position(arm, counter);
        counter = counter - speed;
        msleep(20);
    }
}
void digital_square()
{
while ((digital(0) < 1) || (digital(7) < 1))
        {
            if ((digital(0) >= 1) && (digital(7) < 1))
            {
                mav(back_r,300);
    	        mav(front_r,300);
    	        mav(front_l,-300);
    	        mav(back_l,-300);
            }
            else if ((digital(0) < 1) && (digital(7) >= 1))
            {
                mav(back_r,-300);
    	        mav(front_r,-300);
    	        mav(front_l,300);
    	        mav(back_l,300);
            }
            else
            {
                mav(back_r,-400);
    	        mav(front_r,-400);
    	        mav(front_l,-400);
    	        mav(back_l,-400);
            }
        }
        ao();
        msleep(200);
}

void clear_motors(){
	cmpc(0);
	cmpc(1);
	cmpc(2);
	cmpc(3);
}
void turn_180(){
    turn_right(4200,800);
}
