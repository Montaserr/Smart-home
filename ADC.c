#include "Config.h"


void init_ADC(int selectChannel,int Ref,int LA,int PS){
    
    
    ADMUX =0x00;
    ADMUX =selectChannel;
    ADMUX |= (Ref<<6);
    ADMUX |=(LA<<ADLAR);
    
    ADCSRA =0x00;
    ADCSRA |=PS;
    
    ADCSRA |=(1<<ADEN);
}
void Start_Conversion(){
    ADCSRA |=(1<<ADSC);
    
}
int ADC_READ_Right(){
    while(!(ADCSRA &(1<<ADIF)) );
    
    unsigned int Data =ADCL;
    Data |=(ADCH<<8);
    
    return Data;

}
int ADC_READ_Left(){
    while(!(ADCSRA &(1<<ADIF)) );
    
    int Data =(ADCL>>6);
    Data |=(ADCH<<2);
    
    return Data;

}
void ADC_Int_Enable(){
    
    ADCSRA |=(1<<ADIE);
}
