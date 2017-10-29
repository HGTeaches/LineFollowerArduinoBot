/* Megan's line following robot with code borrowed from the Ardumoto Sample Sketch
  by: Megan Hayes-Golding
  date: October 2017
  license: Public domain. Please use, reuse, and modify this 
  sketch!

  Three useful functions are defined:
    setupArdumoto() -- Setup the Ardumoto Shield pins
    driveArdumoto([motor], [direction], [speed]) -- Drive [motor] 
      (0 for A, 1 for B) in [direction] (0 or 1) at a [speed]
      between 0 and 255. It will spin until told to stop.
    stopArdumoto([motor]) -- Stop driving [motor] (0 or 1).

  setupArdumoto() is called in the setup().
  The loop() demonstrates use of the motor driving functions.
*/

// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
#define FORWARD  1
#define REVERSE 0

// Motor definitions to make life easier:
#define MOTOR_A 0
#define MOTOR_B 1

// Pin Assignments //
//Default pins:
#define DIRA 2 // Direction control for motor A
#define PWMA 3  // PWM control (speed) for motor A
#define DIRB 4 // Direction control for motor B
#define PWMB 11 // PWM control (speed) for motor B

////Alternate pins:
//#define DIRA 8 // Direction control for motor A
//#define PWMA 9 // PWM control (speed) for motor A
//#define DIRB 7 // Direction control for motor B
//#define PWMB 10 // PWM control (speed) for motor B

//Light sensor reading variable declarations
int leftPinRdg = 0;
int centerPinRdg = 0;
int rightPinRdg = 0;

//Create an array for storing the light sensor values
int lineFollower[3] = {0, 0, 0}; // note: 1=dark and 0=light


void setup()
{
  setupArdumoto(); // Set all pins as outputs
  Serial.begin(9600);
}

void loop()
{
  //Read in the light sensor values and store them in an array
//  for (int i=0; i<3; i++){
//  lineFollower[i] = analogRead(i);
//  Serial.println(lineFollower[i]);
//  }
  lineFollower[0] = analogRead(0);
  Serial.println(lineFollower[0]);
  lineFollower[1] = analogRead(1);
  Serial.println(lineFollower[1]);
  lineFollower[2] = analogRead(2);
  Serial.println(lineFollower[2]);
  delay(250);
  Serial.println();

  //driveArdumoto(MOTOR_A, FORWARD, 100);
  //driveArdumoto(MOTOR_B, FORWARD, 100);
}
// driveArdumoto drives 'motor' in 'dir' direction at 'spd' speed
void driveArdumoto(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }  
}

// stopArdumoto makes a motor stop
void stopArdumoto(byte motor)
{
  driveArdumoto(motor, 0, 0);
}

// setupArdumoto initialize all pins
void setupArdumoto()
{
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}
