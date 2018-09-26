#pragma config(Sensor, S1,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Motor,  motorA,           ,             tmotorEV3_Large, openLoop)
#pragma config(Motor,  motorB,          motorL,        tmotorEV3_Large, openLoop, driveRight, encoder)
#pragma config(Motor,  motorC,          motorR,        tmotorEV3_Large, openLoop, driveLeft, encoder)
#pragma config(Motor,  motorD,          motorG,        tmotorEV3_Large, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//���
int whitesensor = 0;

//##Grab distance
int grabdist=4000;

//##Test variables
	int sortcounter = 0; // test
	int test_light = 0;
	int  tra = 0;
	int whileloop = 0;
//###############################################

//##Location
	//Used to keep track of if mindstorm, black==1, grey==2, white==3,
	int whereU = 0;

	//Used to track which section the mindstorm is in
	int sect = 0; // add for offset start
	int oldSect = 0;
//###############################################

//##Light
	//Stores the light reflexion percentage from sensor
	int light;

	//Circa light reflextion from board
	int white = 80;
	int grey 	=	56;
	const int black = 25;

	//Used to make a buffer between the mesured light
	int buff = 10;
//###############################################

//##Speed
	const int StdDriveSpeed =  -40; //Inverse standard drive speed.
    int driveSpeed =  StdDriveSpeed; //Inverse standard drive speed.

    int driveSlow = -25; //Slow drive speed
	//Max and min speed
	int speedMax = 100;
	int speedMin = -100;
//###############################################

//##Gains for PID
	//Error gain
	const float Kp =        0.6;		//Turn amplitude

	//Derivative gain
	const float Kd =        0.002;		//Movement smoothness

	//Ki Default
	const float KiDef = 0.0007;			//Tendency to go towards the grey line
	float Ki = KiDef;
//###############################################

//##PID

	//saturation control
	int saturation = 3;

	//Sign control
	int sign = 3;

	//Averege light reflextion
	int target = round(((white-grey)/2)+grey);

	//error = target - light
	int error = 0;

	//integral = integral + error;
	int integral = 0;

	//derivative = error - lastError
	int derivative;

	//Stores last error, too compare whit current error
	int lastError;

	//Stores (e = error * Kp)
	float e;
	float i;
	float d;
	int correction;
//###############################################

//correction = (error * Kp) + (integral * Ki) + (derevative * Kd)
//Hjul omkreds = 22.5cm
//Afstand mellem daek = 13.5cm
//omkreds mellem hjul = 13.5cm * pi = 42,411500823462208719245685674273 cm
// halv omgang = 180 grader = 42,411500823462208719245685674273 cm / 2 = 21,205750411731104359622842837137 cm
// Omdregning paa hjul til halv omgang = 21,205750411731104359622842837137 cm / 22.5cm = 0,94247779607693797153879301498387 gange
// Og det er i grader = 360 * 0,94247779607693797153879301498387 = 339,29200658769766975396548539419
//For Debugin


/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

//Stops intregral from acumulating beyond saturation

	task PlayMario(){
	setSoundVolume(100);
	string Mortendone;


while (1){

//for (int tal = 1; tal < 34; tal++)
//{
//	sprintf(Mortendone,"/home/root/lms2012/prjs/rc-data/Morten%i", tal);
//playSoundFile(Mortendone); //Robot --> LEGO Brick --> File Managment Utility
//}
	//	playSoundFile("/home/root/lms2012/prjs/rc-data/Morten1"); //Robot --> LEGO Brick --> File Managment Utility
			playSoundFile("/home/root/lms2012/prjs/rc-data/Morten2"); //Robot --> LEGO Brick --> File Managment Utility
				playSoundFile("/home/root/lms2012/prjs/rc-data/Morten3"); //Robot --> LEGO Brick --> File Managment Utility
						playSoundFile("/home/root/lms2012/prjs/rc-data/Morten4"); //Robot --> LEGO Brick --> File Managment Utility
							playSoundFile("/home/root/lms2012/prjs/rc-data/Morten5"); //Robot --> LEGO Brick --> File Managment Utility
								playSoundFile("/home/root/lms2012/prjs/rc-data/Morten6"); //Robot --> LEGO Brick --> File Managment Utility
									playSoundFile("/home/root/lms2012/prjs/rc-data/Morten7"); //Robot --> LEGO Brick --> File Managment Utility
										playSoundFile("/home/root/lms2012/prjs/rc-data/Morten8"); //Robot --> LEGO Brick --> File Managment Utility
											playSoundFile("/home/root/lms2012/prjs/rc-data/Morten9"); //Robot --> LEGO Brick --> File Managment Utility
												playSoundFile("/home/root/lms2012/prjs/rc-data/Morten10"); //Robot --> LEGO Brick --> File Managment Utility
													playSoundFile("/home/root/lms2012/prjs/rc-data/Morten11"); //Robot --> LEGO Brick --> File Managment Utility
														playSoundFile("/home/root/lms2012/prjs/rc-data/Morten12"); //Robot --> LEGO Brick --> File Managment Utility
															playSoundFile("/home/root/lms2012/prjs/rc-data/Morten13"); //Robot --> LEGO Brick --> File Managment Utility
																playSoundFile("/home/root/lms2012/prjs/rc-data/Morten14"); //Robot --> LEGO Brick --> File Managment Utility
																	playSoundFile("/home/root/lms2012/prjs/rc-data/Morten15"); //Robot --> LEGO Brick --> File Managment Utility
																		playSoundFile("/home/root/lms2012/prjs/rc-data/Morten16"); //Robot --> LEGO Brick --> File Managment Utility
																			playSoundFile("/home/root/lms2012/prjs/rc-data/Morten17"); //Robot --> LEGO Brick --> File Managment Utility
																				playSoundFile("/home/root/lms2012/prjs/rc-data/Morten18"); //Robot --> LEGO Brick --> File Managment Utility
																					playSoundFile("/home/root/lms2012/prjs/rc-data/Morten19"); //Robot --> LEGO Brick --> File Managment Utility
																						playSoundFile("/home/root/lms2012/prjs/rc-data/Morten20"); //Robot --> LEGO Brick --> File Managment Utility
																							playSoundFile("/home/root/lms2012/prjs/rc-data/Morten21"); //Robot --> LEGO Brick --> File Managment Utility
																								playSoundFile("/home/root/lms2012/prjs/rc-data/Morten22"); //Robot --> LEGO Brick --> File Managment Utility
																									playSoundFile("/home/root/lms2012/prjs/rc-data/Morten23"); //Robot --> LEGO Brick --> File Managment Utility
																										playSoundFile("/home/root/lms2012/prjs/rc-data/Morten24"); //Robot --> LEGO Brick --> File Managment Utility
																											playSoundFile("/home/root/lms2012/prjs/rc-data/Morten5"); //Robot --> LEGO Brick --> File Managment Utility
																												playSoundFile("/home/root/lms2012/prjs/rc-data/Morten26"); //Robot --> LEGO Brick --> File Managment Utility
																													playSoundFile("/home/root/lms2012/prjs/rc-data/Morten27"); //Robot --> LEGO Brick --> File Managment Utility
																														playSoundFile("/home/root/lms2012/prjs/rc-data/Morten28"); //Robot --> LEGO Brick --> File Managment Utility
																															playSoundFile("/home/root/lms2012/prjs/rc-data/Morten29"); //Robot --> LEGO Brick --> File Managment Utility
																																playSoundFile("/home/root/lms2012/prjs/rc-data/Morten30"); //Robot --> LEGO Brick --> File Managment Utility
																																	playSoundFile("/home/root/lms2012/prjs/rc-data/Morten31"); //Robot --> LEGO Brick --> File Managment Utility
																																		playSoundFile("/home/root/lms2012/prjs/rc-data/Morten32"); //Robot --> LEGO Brick --> File Managment Utility
																																			playSoundFile("/home/root/lms2012/prjs/rc-data/Morten33"); //Robot --> LEGO Brick --> File Managment Utility



}
}

void clamping() {

  //Comtrolles if the motors are saturating
  if (correction < speedMin || correction > speedMax) {
    saturation = 1;
  } else {
    saturation = 0;
  }

  //Controlles the sign of correction and the error.
  if (correction < 0 && error < 0) {
    sign = 1;
  } else if (correction > 0 && error > 0) {
    sign = 1;
  } else {
    sign = 0;
  }

  if (sign == 1 && saturation == 1) {
    Ki = 0;
  } else {
    Ki = KiDef;
    integral = integral + error;
  }
}

//PID calculation
void PID() {
  clamping();
  error = target - light;
  derivative = error - lastError;
  e = error * Kp;
  i = integral * Ki;
  d = derivative * Kd;
  correction = e + i + d;
}

//Does the generel driving
void driveLine() {
  PID();
  motor[motorR] = driveSpeed - (correction); //*factor
  motor[motorL] = driveSpeed + (correction);
  lastError = error;
}





/////////////////////////////////////////////////////////////////////////////////////////////////////
//On which color is it / Determine colour
void whereIsIt() {
  //Graa paa hvid
  if (light > grey - buff && light < grey + buff) {
    //grey area
    driveLine();
    whereU = 2;
    sortcounter = 0;
    whitesensor = 0; // Bruges til case 7
  } else if (light > white - buff) {
    //White area
    driveLine();
    whereU = 3;
    sortcounter = 0;
    whitesensor++;
  } else if (light < black + buff && whereU != 1) {
    //Black area
    sortcounter++;
    whitesensor = 0;
    if (sortcounter >= 20) {
      sect++;
    	playTone(440, 20); 	//Sector detection tone
      motor[motorR] = driveSpeed;
      motor[motorL] = driveSpeed;
      whereU = 1;
      sortcounter = 0;
    }
  } else {
    driveLine();
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//Takes one input, how many degrees it has to turn inverse on eache wheel
void turnOnPoint(int motorRatio, int speed) {

  motor[motorR] = 0;
  motor[motorL] = 0;
  //Delay the program until both motors complete their movements.
  waitUntilMotorStop(motorL);
  waitUntilMotorStop(motorR);
  moveMotorTarget(motorL, motorRatio, speed);
  moveMotorTarget(motorR, motorRatio, -speed);
  waitUntilMotorStop(motorL);
  waitUntilMotorStop(motorR);

}

/*
 *Takes two inputs, motorRatio and deg, motorRatio is percentage distribution of power(-100 All left, 100 all right),
 *and deg is encode count(degrees).
 */
void syncTurn(int motorRatio, int deg) {

  //Delay the program until both motors complete their movements.
  waitUntilMotorStop(motorL);
  waitUntilMotorStop(motorR);

  resetMotorEncoder(motorL);
  resetMotorEncoder(motorR);

  setMotorSyncEncoder(motorL, motorR, motorRatio, deg, driveSpeed);

  //Delay the program until both motors complete their movements
  waitUntilMotorStop(motorL);
  waitUntilMotorStop(motorR);

}

//Function to grap or let bottle go
//x = 1 grabs bottle;
//x = 2 lets go of bottle
void grabBottle(int x){
	motor[motorL] = 0;
	motor[motorR] = 0;
	switch(x){
		case 1:
			moveMotorTarget(motorG, grabdist, 100);
  		waitUntilMotorStop(motorG);
		break;

		case 2:
			moveMotorTarget(motorG, -grabdist, -100);
  		waitUntilMotorStop(motorG);
		break;

		default:

		break;
	}

}

void printDis() {
int afstand = getUSDistance(S1);

  displayBigTextLine(1, "Sect: %i", sect);
  displayBigTextLine(3, "Lys: %i", getColorReflected(S3));
  displayBigTextLine(5, "Gray: %i", grey);
  displayBigTextLine(7, "White: %i", white);
  displayBigTextLine(9, "Loop: %i", whileloop);
  //displayBigTextLine(3, "Ultralyd: %i", afstand );
  //displayBigTextLine(5, "Stadig i l�kken %i", tra );
  /*##Calibrering af line k?rsel
  displayBigTextLine(1, "correction: %i", correction);
  displayBigTextLine(3, "e:%f", e);
  displayBigTextLine(5, "i:%f", i);
  displayBigTextLine(7, "d:%f", d);
  displayBigTextLine(9, "l:%i", light);
  displayBigTextLine(11, "L:%i", motor[motorL]);
  displayBigTextLine(13, "R:%i", motor[motorR]);*/

}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void chooseSect() {
  if (sect != oldSect) {
    switch (sect) {
    case 1:

     	syncTurn(-20, 200);

     	sleep(1000);

      /*while (getColorReflected(S3) > white - buff) {
        setMotorSyncEncoder(motorL, motorR, -20, 10, driveSpeed);
      }*/

      do {
      	printDis();
      	setMotorSyncEncoder(motorL, motorR, -20, 10, driveSpeed);
      	waitUntilMotorStop(motorL);
      	waitUntilMotorStop(motorR);
      } while (getColorReflected(S3) > white - buff);

      printDis();
      sleep(1000);



      //waitUntilMotorStop(motorL);
 			//waitUntilMotorStop(motorR);

 			//while(1){}
 			syncTurn(20, 180);
 			printDis();

 			sleep(1000);

    	break;

    case 2:

    	sleep(1000);

    	printDis();
    	syncTurn(20, 200);

    	sleep(1000);

    	do {
    		printDis();
      	setMotorSyncEncoder(motorL, motorR, 20, -10, driveSpeed);
      	waitUntilMotorStop(motorL);
      	waitUntilMotorStop(motorR);
      } while (getColorReflected(S3) > white - buff);

      sleep(1000);
      printDis();
      syncTurn(-30, 200);

    	sleep(1000);

      break;

    case 3:
/*
		resetMotorEncoder(motorL);

		//Drives a bit forward after the black line
		setMotorSyncEncoder(motorL, motorR, 0, 250, driveSlow);
		waitUntilMotorStop(motorL);


		turnOnPoint(70, -driveSlow);
		while(getColorReflected(S3) > white-buff){
			turnOnPoint(10, -driveSlow);
		}
		turnOnPoint(30, -driveSlow);

		integral = 0;
		//Follows line until bottle is whitin 3 cm.
		while(getUSDistance(S1) > 3){
			light = getColorReflected(S3);
			driveLine();
		}

		//Lifts bottle
		grabBottle(1);

		//Passes blue dot
		resetMotorEncoder(motorL);
		setMotorSyncEncoder(motorL, motorR, -8, 170, driveSlow);
		waitUntilMotorStop(motorL);

		//Drive forward until black line
		while(getColorReflected(S3) > white - buff){
			setMotorSyncEncoder(motorL, motorR, 0, 0, driveSlow);
		}

		//Set bottle down behind black line
		grabBottle(2);

		//Lets go of bottle
		turnOnPoint(20, driveSlow);

		//Grabs bottle again
		grabBottle(1);


		//Turn counterclock wise 100 degrees
		turnOnPoint(100, driveSlow);

		//Turn counterclock wise until tuching gray
		while(getColorReflected(S3) > white - buff){
			motor[motorL]=-driveSlow;
			motor[motorR]=driveSlow;
		}
		motor[motorL]=0;
		motor[motorR]=0;

		//Frees of gray line
		turnOnPoint(10, -driveSlow);

		//Drives forward until gray
		while(getColorReflected(S3) > white - buff){
			motor[motorL]=driveSlow;
			motor[motorR]=driveSlow;
		}
		sleep(100);

		//Drives forward until white
		while(getColorReflected(S3) < grey + buff){
			motor[motorL]=driveSlow;
			motor[motorR]=driveSlow;
		}

		sleep(100);
		resetMotorEncoder(motorL);
		setMotorSyncEncoder(motorL, motorR, 0, 50, -driveSlow);


		while(getColorReflected(S3) < grey + buff){
			motor[motorL]=driveSlow;
			motor[motorR]=-driveSlow;
		}
		motor[motorL]=0;
		motor[motorR]=0;
*/

      break;
    case 4:

    sect++;

      break;

    case 5:

      break;
    case 6:

		printDis();			//Debug: display
		int ok = 0;
		moveMotorTarget(motorR,400,-30); // K�rer lidt frem s� vi er v�k fra den sorte streg.
		moveMotorTarget(motorL,400,-30);
		waitUntilMotorStop(motorR);
		waitUntilMotorStop(motorL);
		while (ok == 0) {

			turnOnPoint(25,-5); // Drejer s� vi er sikker p� at den ikke er p� det hvide
			while (getColorReflected(S3) < white - buff) // Drejer stille og rolig mens den er p� det gr�, indtil den er p� det hvide.
			{
				turnOnPoint(10,-5);
			}

			while (getColorReflected(S3) > white - buff)  // Mens den er p� det hvide k�rer den ligeud
			{
				whileloop = 1; // Brugt til test
				printDis();			//Debug: display
				setMotorSyncEncoder(motorB, motorC, 0, 0, driveSlow);
			}
			delay(100);
			while (getColorReflected(S3) < grey + buff) // Mens den er p� det gr� k�rer den ligeud.
			{
				whileloop = 2;
				printDis();			//Debug: display
				setMotorSyncEncoder(motorB, motorC, 0, 0, driveSlow);
			}
			delay(100);
			while (getColorReflected(S3) > white - buff) // Men den er p� det gr� k�rer den ligeud.
			{
				whileloop = 3;
				printDis();			//Debug: display
				setMotorSyncEncoder(motorB, motorC, 0, 0, driveSlow);
			}
			ok = 1;
			whileloop = 0;

  		}

      break;
    case 7:

    resetMotorEncoder(motorB);
    resetMotorEncoder(motorC);
   	turnOnPoint(10, driveSlow);
  	setMotorSyncEncoder(motorB, motorC, 0, 350, driveSlow);
    	waitUntilMotorStop(motorR);
			waitUntilMotorStop(motorL);
			while (getColorReflected(S3) < grey + buff)
			{
				turnOnPoint(10, driveSlow);
			}
				turnOnPoint(10, driveSlow);
			waitUntilMotorStop(motorR);
			waitUntilMotorStop(motorL);
			while (getColorReflected(S3) > white - buff)
			{
				turnOnPoint(10, driveSlow);
			}
			turnOnPoint(10, driveSlow);

			driveSpeed = -15;

      break;
    case 8:
    			driveSpeed = StdDriveSpeed;
			turnOnPoint(10, -10);
    	setMotorSyncTime(motorB, motorC, 0, 2800, driveSlow);
    	waitUntilMotorStop(motorL);
    	waitUntilMotorStop(motorR);
     moveMotorTarget(motorG, -grabdist, -100);
      waitUntilMotorStop(motorG);
      sleep(100);
    	while (getColorReflected(S3) > black + buff)
      {
    	setMotorSyncEncoder(motorB, motorC, 0, 0, -driveSlow);
    	}
    	turnOnPoint(-200, -5);
    	while (getColorReflected(S3) > white - buff) {
        turnOnPoint(-10, -5);
        }

        driveSpeed = -20;

       	while (whitesensor < 650 && getColorReflected(S3) > black)
       {
			  oldSect = sect;		//Prevention of repeat sector actions
			  light = getColorReflected(S3); //Get colour from sensor
			  test_light++;		//Debug: Counting coloursensor usage
			  whereIsIt();		//Determine colour
			  chooseSect();		//Choose sector
			  printDis();			//Debug: display
			}

		resetMotorEncoder(motorB);
    resetMotorEncoder(motorC);
  	setMotorSyncEncoder(motorB, motorC, 0, 50, driveSlow);

		    	while (getColorReflected(S3) > white - buff) {
        turnOnPoint(-10, -5);
        }

        driveSpeed = StdDriveSpeed;
   	    grabBottle(1);
   	    grabBottle(1);

      break;
    case 9:
	turnOnPoint(-80, -driveSlow); // Drejer til h�jre
			setMotorSyncEncoder(motorB, motorC, 0, 700, driveSlow);
			waitUntilMotorStop(motorR);
			waitUntilMotorStop(motorL);
			turnOnPoint(-100,driveSlow); // Drejer tilbage mod stregen
			waitUntilMotorStop(motorR);
			waitUntilMotorStop(motorL);
			while(getColorReflected(S3) > (white - buff)){ // Mens den er p� det hvide k�rer den ligeud
				setMotorSyncEncoder(motorB, motorC, 0, 0, driveSlow);
			}
			setMotorSpeed(motorL,0);
			setMotorSpeed(motorR,0);

			integral = 0; // S�tter noget i PID til 0, s� den ikke reagere s� kraftigt.
			delay(100);
			while (getColorReflected(S3) < grey + buff)
			{
							setMotorSyncEncoder(motorB, motorC, 0, 0, driveSlow);
			}
			delay(100);
			setMotorSyncEncoder(motorB, motorC, 0, 150, driveSlow);
			waitUntilMotorStop(motorR);
			waitUntilMotorStop(motorL);
			while (getColorReflected(S3) > white - buff)
			{
				turnOnPoint(10, -driveSlow);
			}
			turnOnPoint(10, -driveSlow);
			turnOnPoint(10, -driveSlow);

			clearTimer(T1);

			while (time1[T1] < 5000)
			{
		light = getColorReflected(S3);
		driveLine();

		}


			driveSpeed = -15;
      break;
    case 10:


    	resetMotorEncoder(motorL);
      resetMotorEncoder(motorR);

    	setMotorSyncEncoder(motorL, motorR, 0, 770, driveSlow);

    	waitUntilMotorStop(motorR);
			waitUntilMotorStop(motorL);

    	turnOnPoint(95, driveSlow);


			while (getUSDistance(S1) > 7) {
				setMotorSyncEncoder(motorB, motorC, 0, 0, driveSlow);
			}

			motor[motorL]=0;
			motor[motorR]=0;



			syncTurn(-50, 240);

			resetMotorEncoder(motorL);
      resetMotorEncoder(motorR);

    	setMotorSyncEncoder(motorL, motorR, 0, 800, driveSlow);

    	waitUntilMotorStop(motorR);
			waitUntilMotorStop(motorL);

    	while (getColorReflected(S3) > white - buff) {
        turnOnPoint(-10, -5);
        }
        delay(100);
        while (getColorReflected(S3) < grey + buff) {
            	setMotorSyncEncoder(motorL, motorR, 0, 0, -15);
        }
        delay(100);
          turnOnPoint(10, 5);
          turnOnPoint(10, 5);
          turnOnPoint(10, 5);

      break;
    case 11: // Det modsatte af case 9
			turnOnPoint(80, driveSlow);
			setMotorSyncEncoder(motorB, motorC, 0, 800, driveSlow);
			waitUntilMotorStop(motorR);
			waitUntilMotorStop(motorL);
			turnOnPoint(100,-driveSlow);
			waitUntilMotorStop(motorR);
			waitUntilMotorStop(motorL);
			while(getColorReflected(S3) > (white - buff)){
				setMotorSyncEncoder(motorB, motorC, 0, 0, driveSlow);
			}
			setMotorSpeed(motorL,0);
			setMotorSpeed(motorR,0);

			integral = 0;
			delay(100);
			  while (getColorReflected(S3) < grey + buff)
        {
					setMotorSyncEncoder(motorB, motorC, 0, 0, driveSlow);
				}
			delay(100);
			setMotorSyncEncoder(motorB, motorC, 0, 150, driveSlow);
			waitUntilMotorStop(motorR);
			waitUntilMotorStop(motorL);
			while (getColorReflected(S3) > white - buff)
			{
				turnOnPoint(10, driveSlow);
			}
driveSpeed =StdDriveSpeed;
      break;
    case 12:

  setMotorSyncEncoder(motorB, motorC, 20, 400, driveSlow);
 			waitUntilMotorStop(motorB);
			while (getColorReflected(S3) > white - buff)
			{
				setMotorSyncEncoder(motorB, motorC, 0, 0, driveSlow);
			}

			delay(100);
			while (getColorReflected(S3) < grey + buff)
			{
				setMotorSyncEncoder(motorB, motorC, 0, 0, driveSlow);
			}
			turnOnPoint(30, -driveSlow);


			clearTimer(T1);

			while (getUSDistance(S1) > 150 || time1[T1] < 5000) {
			  light = getColorReflected(S3); //Get colour from sensor
			  driveLine();
			}


		while (true)
		{
		setMotorSpeed(motorB, 0);
    setMotorSpeed(motorC, 0);
		}

			break;
    default:

      break;
}

  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////


void reference() {
  //	sleep(200);
  grey = getColorReflected(S3);
  while (getColorReflected(S3) < grey + buff) {
    turnOnPoint(20, -10);

  }
  white = getColorReflected(S3);

  while (getColorReflected(S3) > white - buff) {

    turnOnPoint(-20, 10);

  }

  target = round(((white - grey) / 2) + grey);

}


/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
task main() {
//	startTask(PlayMario); //startermusik
  reference();
  resetMotorEncoder(motorL);
  resetMotorEncoder(motorR);
  while (1) {
    oldSect = sect;		//Prevention of repeat sector actions
    light = getColorReflected(S3); //Get colour from sensor
    test_light++;		//Debug: Counting coloursensor usage
    whereIsIt();		//Determine colour
    chooseSect();		//Choose sector
    printDis();			//Debug: display
  }



}
