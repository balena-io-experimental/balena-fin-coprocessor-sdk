
#include "power.h"

/******************************************************************************
 * @brief Power Class
 *
 * Manage Compute Module Power Rail and EMF Power Modes
 *
 *****************************************************************************/

PowerClass::PowerClass()
{
    timer.sleep_delay = NULL;
    timer.sleep_period = NULL;
    timer.sleep_mode = EM0;
    timer.wake_mode = EM0;
    timer.cm3_state = POWER_ON;
}

PowerClass::PowerClass(uint32_t delay, uint32_t period, CoprocessorEnergyMode cp_sleep_mode, CoprocessorEnergyMode cp_wake_mode){
    timer.sleep_delay = delay;
    timer.sleep_period = period;
    timer.sleep_mode = cp_sleep_mode;
    timer.wake_mode = cp_wake_mode;
};

void PowerClass::Init(uint32_t delay, uint32_t period, CoprocessorEnergyMode cp_sleep_mode, CoprocessorEnergyMode cp_wake_mode){
    timer.sleep_delay = delay;
    timer.sleep_period = period;
    timer.sleep_mode = cp_sleep_mode;
    timer.wake_mode = cp_wake_mode;
};

void PowerClass::PowerDown(){
    if((timer.sleep_period) != (0 | NULL)){
        switch (timer.sleep_delay > 0 ? 0 : 1){
                case (0):
                    timer.cm3_state = POWER_OFF_DELAY;
                    RTCDRV_StartTimer(id, rtcdrvTimerTypeOneshot, timer.sleep_delay, WakeEvent, this);
                    break;
                case (1):
                    timer.cm3_state = POWER_OFF;
                    RTCDRV_StartTimer(id, rtcdrvTimerTypeOneshot, timer.sleep_period, WakeEvent, this);
                    break;
                default:
                    timer.cm3_state = POWER_ON;
                    break;
            }
    }
    else {
        throw "Invalid sleep period";
    }
}

/******************************************************************************
 * @brief Power Wake Event Callback
 *
 * Wake Event Callback that triggers when the timeout for the RTC expires, waking up the compute module
 *
 *****************************************************************************/

static void WakeEvent(RTCDRV_TimerID_t id, void * user)
{
    PowerClass* power = (PowerClass*) user;
    if(power->timer.cm3_state == POWER_OFF_DELAY){
        digitalWrite(SLEEP_PIN, 0);
        power->timer.cm3_state = POWER_OFF;
        RTCDRV_StartTimer(id, rtcdrvTimerTypeOneshot, power->timer.sleep_period, WakeEvent, power);
    }
    else {
        digitalWrite(SLEEP_PIN, 1);
    }
}
