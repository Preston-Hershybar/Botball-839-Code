#include <kipr/wombat.h>
#include <mecanumlib.h>

int main()
{
    //making sure the servos are in position (remember to remove this)
    enable_servos();
    ssp(0,1000);
    ssp(1,1500);
    disable_servos();
    wait_for_light(5);
    shut_down_in(120);
    
    //go to the potato
    clear_motors();
    left(3000,800);
    wait(250);
    forward(12500,900);
    
    //set up for potato grab
    wait(250);
    left_90();
    wait(250);
    backward(1250,800);
	  right(500,900);
    wait(1000);
    
    //grab potato
    enable_servos();
    ssp(0,1900);
    wait(250);
    downslow(1,1450,250,35);
    wait(250);
    
    //put potato in fryer (downslow is misleading; the arm is actually going up)
    downslow(0,1900,1300,25);
    turn_180();
    forward(400,500);
    right(400,800);
    wait(250);
    ssp(1,1500);
    wait(1000);
    
    //putting the servo back into the original position (remember to remove this section!)
    ssp(0,1000);
    disable_servos();
    clear_motors();
    ao();
    return 0;
}
