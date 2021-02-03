#ifndef _SETTINGSMENU_H_
#define _SETTINGSMENU_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "Settings.h"

typedef struct
{
  int16_t prints;
  int16_t finished;
  int16_t failed;
  uint8_t total_time[21];
  uint8_t longest_job[21];
  uint8_t filament_used[21];
  uint8_t service1[21];
  uint8_t service2[21];
  uint8_t service3[21];
}PRINTSTATS;

extern PRINTSTATS printCounter;

extern uint8_t machine_type[64];
extern bool m78_waiting;

void menuInfo(void);
void menuSettings(void);
void infoSetFirmwareName(uint8_t *name, uint8_t name_len);
void infoSetMachineType(uint8_t *machine, uint8_t type_len);
void counterSet(uint8_t *param, uint8_t stat[], uint8_t len);

#ifdef __cplusplus
}
#endif

#endif
