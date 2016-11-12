
#pragma config(Sensor, S1,     touchsensorR,        sensorTouch)
#pragma config(Sensor, S2,     threshold,           sensorSONAR)
#pragma config(Sensor, S3,     light,               sensorLightActive)
#pragma config(Sensor, S4,     touchsensorL,        sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// VS program Ver.A (VS Sophia's Team) just avoid first front collision
task main(){
    long lite;
    long thres;
    int touchL;
    int touchR;
    bool pressedL = false;
    bool pressedR = false;
    bool lift = false;
    nVolume = 4;
    // a three second delay with sound effect
    wait1Msec(500);
    PlaySoundFile("kissMyAss.rso");
    wait1Msec(2500);
    // back & wait six sec & turn to avoid first collision
    motor[motorA] = -30;
    motor[motorC] = -30;
    wait1Msec(1000);
    motor[motorA] = 0;
    motor[motorC] = 0;
    wait1Msec(6000);
    motor[motorA] = 30;
    motor[motorC] = -30;
    wait1Msec(450);
    
    while(true){
        thres = SensorValue(threshold);
        lite = SensorValue(light);
        touchL = SensorValue(touchsensorL);
        touchR = SensorValue(touchsensorR);
        int nLR = random(3);
        int nWait = random(1000);
        
        if((lite < 30) && (thres < 30) && (lift == true)){ // down the lift //LITE MUST BE LOW BECAUSE OF ABSENT OF LIFT
            nMotorEncoder[motorB] = 0;
            nMotorEncoderTarget[motorB] = 30;
            motor[motorB] = 50;
            lift = false;
        }
        
        else{
        }
        
        if ((lite < 30) && (thres < 30)){ // close to enemy & on safe ground
            motor[motorA] = 100;
            motor[motorC] = 100;
        }
        
        else{ // default
            motor[motorA] = 70;
            motor[motorC] = 70;
        }
        //PROB LITE DIFFER WHEN LIFT IS UP
        if ((lite < 30) && (thres < 15) && (lift == false)){ // lift over enemy //LITE MUST BE HIGH NUMBER BECAUSE OF COLOUR OF LIFT
            nMotorEncoder[motorB] = 0;
            nMotorEncoderTarget[motorB] = -30;
            motor[motorB] = -100;
            lift = true;
        }
        
        else {
        }
        
        if(touchL == 1){ // if touch LEFT, return pressedL TRUE & try to unpress touchL
            pressedL = true;
            motor[motorA] = 100;
            motor[motorC] = 100;
        }
        
        else{
        }
        
        if(touchR == 1){ // if touch RIGHT, return pressedR TRUE & try to unpress touchR
            pressedR = true;
            motor[motorA] = 100;
            motor[motorC] = 100;
        }
        
        else{
        }
        
        if ((touchL == 0) && (pressedL == true)){ // when the enemy bump LEFT, turn its side
            nMotorEncoder[motorA] = 0;
            nMotorEncoder[motorC] = 0;
            nMotorEncoderTarget[motorA] = 1620;
            nMotorEncoderTarget[motorC] = 720;
            motor[motorA] = 100;
            motor[motorC] = -50;
            if((lite < 30) && (thres < 30)){ // on safe ground & close to enemy, return FALSE
                pressedL = false;
            }
            else{
            }
            if(lite > 30){ // on dangerous ground, return FALSE
                pressedL = false;
            }
            else{
            }
        }
        
        else{
        }
        
        if((touchR == 0) && (pressedR == true)){ // when the enemy bump RIGHT, turn its side
            nMotorEncoder[motorA] = 0;
            nMotorEncoder[motorC] = 0;
            nMotorEncoderTarget[motorA] = 720;
            nMotorEncoderTarget[motorC] = 1620;
            motor[motorA] = -50;
            motor[motorC] = 100;
            if((lite < 30) && (thres < 30)){ // on safe ground & close to enemy, return FALSE
                pressedR = false;
            }
            else{
            }
            if(lite > 30){ // on dangerous ground, return FALSE
                pressedR = false;
            }
            else{
            }
        }
        
        else{
        }
        
        if((lite > 30) && (nLR == 1) && (nWait > 500) && (nWait < 1000)){ // on dangerous ground LEFT
            nVolume = 4;
            PlaySoundFile("turnOffTheLight.rso");
            motor[motorA] = -100;
            motor[motorC] = -100;
            wait1Msec(500);
            motor[motorA] = 70;
            motor[motorC] = -70;
            // srand(450);
            wait1Msec(nWait);
        }
        
        else{
        }
        
        if((lite > 30) && (nLR == 2)&& (nWait > 500) && (nWait < 1000)){ // on dangerous ground RIGHT
            nVolume = 4;
            PlaySoundFile("Woops.rso");
            motor[motorA] = -100;
            motor[motorC] = -100;
            wait1Msec(500);
            motor[motorA] = -70;
            motor[motorC] = 70;
            // srand(450);
            wait1Msec(nWait);
        }
        
        else{
        }
        
    }}
