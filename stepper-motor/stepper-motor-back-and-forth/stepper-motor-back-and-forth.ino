// https://arduino-info.wikispaces.com/SmallSteppers

/* YourDuino.com Example Software Sketch
   Small Stepper Motor and Driver V1.5 06/21/2017
  http://www.yourduino.com/sunshop/index.php?l=product_detail&p=126
   Steps one revolution of output shaft, then back
   terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <Stepper.h>

/*-----( Declare Constants, Pin Numbers )-----*/
//---( Number of steps per revolution of INTERNAL motor in 4-step mode )---
#define STEPS_PER_MOTOR_REVOLUTION 32   

//---( Steps per OUTPUT SHAFT of gear reduction )---
#define STEPS_PER_OUTPUT_REVOLUTION 32 * 64  //2048  

#define SPEED 700
 

/*-----( Declare objects )-----*/
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
//-------------------------------------------------------------
//The pin connections need to be pins 8,9,10,11 connected
// to Motor Driver In1, In2, In3, In4 
//-------------------------------------------------------------

// Then the pins are entered here in the sequence 1-3-2-4 for proper sequencing
Stepper small_stepper(STEPS_PER_MOTOR_REVOLUTION, 8, 10, 9, 11);

/*-----( Declare Variables )-----*/
int  stepsToTake;

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
// Nothing  (Stepper Library sets pins as outputs)
}/*--(end setup )---*/

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  moveStepperOne(1);
  delay(1000);
  
  moveStepperOne(-1);
  delay(2000);

}

void moveStepperOne(int dir) {
  // if dir is positive, will rotate CW
  // if dir is negative, will rotate CCW
  int x = 5;
  stepsToTake  =  dir * STEPS_PER_OUTPUT_REVOLUTION / x;  // Rotate CW 1/x turn
  small_stepper.setSpeed(SPEED);   
  small_stepper.step(stepsToTake);
}
/* --(end main loop )-- */

/* ( THE END ) */
