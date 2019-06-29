#ifndef __POWER_H__
#define __POWER_H__

#include "em_emu.h"
#include "em_ramfunc.h"
#include "balena.h"
// #include "balena.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__cplusplus) && !defined(ARDUINO)
  #include <cstddef>
  #include <cstdint>
#else
  #include <stddef.h>
  #include <stdint.h>
#endif

enum CoprocessorEnergyMode {EM0, EM1, EM2, EM3, EM4};
enum CM3PowerState {POWER_ON, POWER_OFF_DELAY, POWER_OFF};

static void WakeEvent(RTCDRV_TimerID_t id, void * user); // RTC callback

class PowerClass {
    public:
        struct PowerTimer
        {
          uint32_t sleep_delay;
          uint32_t sleep_period;
          CoprocessorEnergyMode sleep_mode;
          CoprocessorEnergyMode wake_mode;
          CM3PowerState cm3_state;
        } timer;

        PowerClass();
        PowerClass(uint32_t delay, uint32_t period, CoprocessorEnergyMode cp_sleep_mode, CoprocessorEnergyMode cp_wake_mode);    
        void Init(uint32_t delay, uint32_t period, CoprocessorEnergyMode cp_sleep_mode, CoprocessorEnergyMode cp_wake_mode);
        void PowerDown();
};

#ifdef __cplusplus
}
#endif
#endif