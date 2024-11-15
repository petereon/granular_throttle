#ifndef GRANULAR_THROTTLE_HPP
#define GRANULAR_THROTTLE_HPP

#include <Arduino.h>
#include <functional>

enum ReadType { DIGITAL, ANALOG };
enum CallbackMode { ON_TIMER, ON_CHANGE, ON_TIMER_AND_CHANGE, ON_TIMER_OR_CHANGE };

struct SinglePinThrottle {
  uint8_t                  pin;
  ReadType                 readType;
  CallbackMode             callbackMode;
  unsigned long            delayTime;
  std::function<void(int)> callback;
  unsigned long            lastTime;
  int                      lastValue;
};

class GranularPinThrottle {
private:
  uint lastIndex = 0;

public:
  SinglePinThrottle *throttles[100];
  GranularPinThrottle();
  void registerPinCallback(uint8_t pin, ReadType readType, CallbackMode callbackMode, unsigned long delayTime,
                           std::function<void(int)> callback);
  void processPins();
};

#endif // GRANULAR_THROTTLE_HPP