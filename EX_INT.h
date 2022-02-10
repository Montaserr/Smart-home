/* 
 * File:   EX_INT.h
 * Author: MaH MeD
 *
 * Created on October 9, 2021, 4:06 PM
 */

#ifndef EX_INT_H
#define	EX_INT_H


#define Low_Level          0
#define Any_Change         1
#define Falling            2
#define Rising             3

#define INT2_Falling       0
#define INT2_Rising        1


void init_INT(int _IntNum,int mode);


#endif	/* EX_INT_H */

