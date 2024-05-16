#include <util/delay.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <avr/interrupt.h>
#include "usart.h"
#include "bit.h"
#include "timer.h"
#include "twi.h"

#define SLA_W (0x22 << 1)
#define SLA_R ((0x22 << 1) | 0x01)

void twi_print_twsr()
{
  usart_tx_reg(TWSR);
  usart_transmit('\n');
}
int main(void)
{
  unsigned char data = 0;
  usart_init(103);
  twi_print_twsr();
  twi_init_master();
  twi_print_twsr();
  twi_start();
  twi_print_twsr();
  twi_write(SLA_W);
  twi_print_twsr();
  twi_write(data++);
  twi_stop();

  twi_start();
  twi_write(SLA_R);
  uint8_t received_data = twi_read_nack();
  twi_stop();
  usart_tx_float(received_data, 3, 2);
 
}