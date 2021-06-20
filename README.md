# Servo Library
Servo Motor library for stm32 series

## Release
### Version : 1.0.0

- #### Type : Embedded Software

- #### Support :  
     ```diff  
     + ARM STM32 Series   
     ```

- #### Program Language : C++

- #### Properties :

- #### Changes :  

- #### Required Library/Driver :


## Overview 
### Initialization and de-initialization functions:
```c++
void Init(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t minPPMPulseWidth, uint16_t maxPPMPulseWidth, float maxAngle);
``` 

### Operation functions:
```c++
void SetPPMPulseWidth(uint16_t Width);
void SetAngle(float ang);
``` 

### Macros:

## Guide

#### This library can be used as follows:
#### 1.  Add .h and source file in project.      
#### 2.  Create Servo object and initialize it, for example:  
- #### Mode 1 (constructor):  
   * Initializer:
      ```c++
      Servo(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t minPPMPulseWidth, uint16_t maxPPMPulseWidth, float maxAngle);
      ``` 
   * Parameters:  
      * htim : pointer to hal timer object  
      * channel : PWM channel of pulse pin 
      * minPPMPulseWidth : minimum pulse width of pwm signal for servo  
      * maxPPMPulseWidth : maximum pulse width of pwm signal for servo  
      * maxAngle : maximum supported angle of sevo  
          
          
   * Example:
      ```c++  
      Servo myMotor(&htim1, TIM_CHANNEL_4, 400, 2000, 180.0f);
      ``` 
- #### Mode 2 (initializer function):  
   * Initializer:
      ```c++
      Servo::Init(TIM_HandleTypeDef *htim, uint32_t channel, uint16_t minPPMPulseWidth, uint16_t maxPPMPulseWidth, float maxAngle);
      ``` 
   * Parameters:  
      * htim : pointer to hal timer object  
      * channel : PWM channel of pulse pin 
      * minPPMPulseWidth : minimum pulse width of pwm signal for servo  
      * maxPPMPulseWidth : maximum pulse width of pwm signal for servo  
      * maxAngle : maximum supported angle of sevo  
          
          
   * Example:
      ```c++  
      Servo myMotor;
      
      myMotor.Init(&htim1, TIM_CHANNEL_4, 400, 2000, 180.0f);
      ``` 
     

#### 3.  Using operation methods, for example: 
        
```c++
myMotor.SetAngle(20);
myMotor.SetPPMPulseWidth(400);
```  
          
## Examples  

#### Example 1: 
   ```c++
   int main()
   {
      //Your codes
      Timer_Init(); // Initialize your timer with 1MHz frequency and 10~20ms period
      
      Servo myMotor;
      myMotor.Init(&htim1, TIM_CHANNEL_4, 400, 2000, 180.0f);
      
      while(1)
      {
         if (myMotor.Angle < myMotor.MaxAngle)
         {
            myMotor.SetAngle(myMotor.Angle + 5);
            HAL_Delay(100);
         }
      }
   }
   ```
    
## Tests performed:
- [x] Run on STM32 Fx cores();

## Developers: 
- ### Majid Derhambakhsh
