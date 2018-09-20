#pragma config(Sensor, S1,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Motor,  motorA,           ,             tmotorEV3_Large, openLoop)
#pragma config(Motor,  motorB,          motorL,        tmotorEV3_Large, openLoop, driveRight, encoder)
#pragma config(Motor,  motorC,          motorR,        tmotorEV3_Large, openLoop, driveLeft, encoder)
#pragma config(Motor,  motorD,          motorG,        tmotorEV3_Large, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////

//##Test variables
	int hej = 0; // test
	int test_light = 0;
	int  tra = 0;
//###############################################

//##Location
	//Used to keep track of if mindstorm, black==1, grey==2, white==3,
	int whereU = 0;

	//Used to track which section the mindstorm is in
	int sect = 0 + 2; // add for offset start
	int oldSect = 0;
//###############################################

//##Light
	//Stores the light reflexion percentage from sensor
	int light;

	//Circa light reflextion from board
	int white = 80;
	int grey 	=	56;
	const int black = 20;

	//Used to make a buffer between the mesured light
	int buff = 10;
//###############################################

//##Speed
	const int StdDriveSpeed =  -40; //Inverse standard drive speed.
    int driveSpeed =  StdDriveSpeed; //Inverse standard drive speed.
	//Max and min speed
	int speedMax = 100;
	int speedMin = -100;
//###############################################

//##Gains for PID
	//Error gain
	const float Kp =        0.5;		//Turn amplitude

	//Derivative gain
	const float Kd =        0.0005;		//Movement smoothness

	//Ki Default
	const float KiDef = 0.0010;			//Tendency to go towards the grey line
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
    hej = 0;
  } else if (light > white - buff) {
    //White area
    driveLine();
    whereU = 3;
    hej = 0;
  } else if (light < black + buff && whereU != 1) {
    //Black area
    hej++;
    if (hej >= 50) {
      sect++;
    playTone(440, 20); 	//Sector detection tone
      motor[motorR] = driveSpeed;
      motor[motorL] = driveSpeed;
      displayBigTextLine(3, "round: %i", sect);
      whereU = 1;
      hej = 0;
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

void printDis() {
int afstand = getUSDistance(S1);

  displayBigTextLine(1, "Sect: %i", sect);
  displayBigTextLine(3, "Lys: %i", getColorReflected(S3));
  displayBigTextLine(5, "Gray: %i", grey);
  displayBigTextLine(7, "White: %i", white);
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

    sleep(1000);

 turnOnPoint(-181, -5); //turn
 waitUntilMotorStop(motorL);
 waitUntilMotorStop(motorR);
 setMotorSyncEncoder(motorL, motorR, 0, 500, driveSpeed);
 waitUntilMotorStop(motorL);
 waitUntilMotorStop(motorR);
 turnOnPoint(322, 5); //turn
 waitUntilMotorStop(motorL);
 waitUntilMotorStop(motorR);

 sleep(1000);
        driveSpeed =  -20;
 //syncTurn(20,200); //If manual turning is needed use this.
 while (getColorReflected(S3) > white - buff) {
        setMotorSyncEncoder(motorL, motorR, 0, 10, driveSpeed);
        }
        while (getUSDistance(S1) > 3) {
        oldSect = sect;		//Prevention of repeat sector actions
		light = getColorReflected(S3); //Get colour from sensor
		test_light++;		//Debug: Counting coloursensor usage
		whereIsIt();		//Determine colour
		chooseSect();		//Choose sector
		printDis();			//Debug: display
        }
    resetMotorEncoder(motorR);
    resetMotorEncoder(motorL);
    resetMotorEncoder(motorG);
    int timeval1 = time1[T1];
    int timeval2 = time1[T1];
    /*while (timeval2-timeval1 < 2000 ) {
	setMotorSyncTime(motorR, motorL, 0, 10, -5);
	timeval2 = time1[T1];
  }*/
        float dist;
        float oldDist;
        float probeDist;
        char cent = 1;
        dist = getUSDistance(S1);

        int grabdist=3333;

        playTone(700, 20); 	//Sector detection tone
    	setMotorSyncEncoder(motorR, motorL, 0, 10, 0);
    	playTone(1200, 20); 	//Sector detection tone
        resetMotorEncoder(motorR);
        resetMotorEncoder(motorL);
        resetMotorEncoder(motorG);
    	setMotorTarget(motorG, grabdist, 100);
    	waitUntilMotorStop(motorG);

       /* while (dist > 4) {
        oldDist = dist;
            dist = getUSDistance(S1);
            driveSpeed =  -20;
            //setMotorSyncTime(motorL, motorR, 0, 300, -15);
            //waitUntilMotorStop(motorL);
            //waitUntilMotorStop(motorR);
            //}
        }
        while (dist > 2.2) {
            driveSpeed =  10/(5.0-dist);
            //setMotorSyncTime(motorL, motorR, 0, 500, -10/(5.0-dist));
            }
            moveMotorTarget(motorG, 2000, 100);*/

        while (getColorReflected(S3) > white - buff) {
            setMotorSyncTime(motorL, motorR, 0, 500, -10);
             }
             driveSpeed =  StdDriveSpeed;


      break;
    case 4:

      moveMotorTarget(motorG, -grabdist, -100);
      waitUntilMotorStop(motorG);
      sleep(100);
      turnOnPoint(20, 20); //180 grader
      waitUntilMotorStop(motorL);
      waitUntilMotorStop(motorR);
      sleep(400);
      moveMotorTarget(motorG, grabdist, 100);
      waitUntilMotorStop(motorG);
      turnOnPoint(300, 20); //180 grader 320=180
      waitUntilMotorStop(motorL);
      waitUntilMotorStop(motorR);
      while (getColorReflected(S3) > white - buff) {
        //syncTurn(-20,10);
        setMotorSyncEncoder(motorL, motorR, 0, 10, driveSpeed);
      }
      break;

    case 5:

      int ok = 0;
      while (ok == 0) {
        syncTurn(-40, 40);
        setMotorSyncEncoder(motorL, motorR, -20, 10, driveSpeed);
        while (getColorReflected(S3) > white - buff)
          int hej = 1;
        while (getColorReflected(S3) > grey - buff)
          int hej = 1;
        while (getColorReflected(S3) > white - buff)
          int hej = 1;
        ok = 1;
        //  setMotorSyncEncoder(motorL, motorR, -20, 10, driveSpeed);
      }

      break;
    case 6:

      break;
    case 7:

      break;
    case 8:

      break;
    case 9:

      break;
    case 10:

      break;
    case 11:

      break;
    case 12:

      break;
    case 13:
	    clearTimer(T1);
			while (getUSDistance(S1) > 10 ) {

			  oldSect = sect;		//Prevention of repeat sector actions
			  light = getColorReflected(S3); //Get colour from sensor
			  test_light++;		//Debug: Counting coloursensor usage
			  whereIsIt();		//Determine colour
			  chooseSect();		//Choose sector
			  printDis();			//Debug: display

			}

			while (getUSDistance(S1) > 3) {
				setMotorSyncEncoder(motorB, motorC, 0, 10, -5);

			}
			playTone(700, 20); 	//Sector detection tone
			setMotorSyncEncoder(motorB, motorC, 0, 10, 0);
			playTone(1200, 20); 	//Sector detection tone
			moveMotorTarget(motorD, 2000, 100);

			while(1){
				motor[motorL] = 0;
				motor[motorR] = 0;

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
