#pragma once

#define MAX_MOTORS  12
#define MAX_SERVOS  8
#define MAX_INPUTS  8

typedef struct drv_pwm_config_t {
    bool enableInput;
    bool usePPM;
    bool useUART;
    bool useServos;
    bool extraServos;    // configure additional 4 channels in PPM mode as servos, not motors
    bool airplane;       // fixed wing hardware config, lots of servos etc
    uint16_t motorPwmRate;
    uint16_t servoPwmRate;
} drv_pwm_config_t;

// This indexes into the read-only hardware definition structure in drv_pwm.c, as well as into pwmPorts[] structure with dynamic data.
enum {
    PWM1 = 0,
    PWM2,
    PWM3,
    PWM4,
    PWM5,
    PWM6,
    PWM7,
    PWM8,
    PWM9,
    PWM10,
    PWM11,
    PWM12,
    PWM13,
    PWM14,
    MAX_PORTS
};

typedef struct {
    TIM_TypeDef *tim;
    GPIO_TypeDef *gpio;
    uint32_t pin;
    uint8_t channel;
    uint8_t irq;
    uint8_t outputEnable;
} pwmHardware_t;

bool pwmInit(drv_pwm_config_t *init); // returns whether driver is asking to calibrate throttle or not
void pwmWriteMotor(uint8_t index, uint16_t value);
void pwmWriteServo(uint8_t index, uint16_t value);
uint16_t pwmRead(uint8_t channel);
