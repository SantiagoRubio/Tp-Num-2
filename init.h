// Inclusion de librerias
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "lcd_i2c.h"
#include <math.h>

#include "control.h"

// Variable para guardar el valor de temperatura
extern float temperatura;
// Variable para guardar el valor del setpoint
extern float setpoint;

// GPIOs de I2C
#define SDA_GPIO    4
#define SCL_GPIO    5
// GPIOs analogicos
#define NTC_GPIO    0
#define SP_GPIO     1
// GPIOs para PWM
#define CALOR_GPIO  15
#define FRIO_GPIO   14

// Constantes de configuracion de PWM
#define CLK_DIV     1
#define PWM_WRAP    1

// Constantes para I2C
#define SCL_FREQ    100 * 1000

// Tiempo de refresco para el siete segmentos
#define SLEEP_MS 10
// Tiempo entre conversiones
#define ADC_DELAY_MS  100

// Prototipos de funciones
void init(void);
bool muestreo_periodico(struct repeating_timer *t);
