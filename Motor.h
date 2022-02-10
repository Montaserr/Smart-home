/* 
 * File:   Motor.h
 * Author: MaH MeD
 *
 * Created on November 25, 2021, 7:25 PM
 */

#ifndef MOTOR_H
#define	MOTOR_H

#define Motor1 0
#define Motor2 1

#define H_A1  PD2
#define H_A2  PD3
#define H_A3  PC5
#define H_A4  PC6
#define H_EN1 PD4
#define H_EN2 PD5

void init_Motor(int Motor_No);

void Motor_Forward(int Motor_No);
void Motor_Reverse(int Motor_No);


void Motor_Stop(int Motor_No);


#endif	/* MOTOR_H */

