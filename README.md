# Granular Throttle Project

This project implements a granular throttle mechanism for handling pin callbacks on an Arduino-based system. The main components of the project is the `GranularPinThrottle` class.

## GranularPinThrottle Class

The `GranularPinThrottle` class manages multiple pin callbacks with different modes and delays. It allows you to register pins with specific read types (digital or analog), callback modes (on timer, on change, etc.), and delay times. The class processes the pins and executes the callbacks based on the specified conditions.

### Key Methods

- `registerPinCallback`: Registers a pin with its callback and configuration.
- `processPins`: Processes all registered pins and executes callbacks if conditions are met.

### Example Usage

```cpp
GranularPinThrottle throttleManager;

void setup() {
    throttleManager.registerPinCallback(2, DIGITAL, ON_CHANGE, 0, [](int value) {
        Serial.println("Pin 2 changed: " + String(value));
    });
}

void loop() {
    throttleManager.processPins();
}
```
Following callback modes are supported:

- `ON_CHANGE`: This mode triggers an action whenever a change is detected. Delay parameter is ignored in this case.
- `ON_TIMER`: This mode triggers an action at regular time intervals.
- `ON_TIMER_OR_CHANGE`: This mode triggers an action either when a change is detected or at regular time intervals, whichever comes first.
- `ON_TIMER_AND_CHANGE`: This mode triggers an action only when both a change is detected and the regular time interval has passed.

Delay times are in milliseconds.


## Plans
- [ ] Add support for unregistering callbacks
- [ ] Variable sized structure for storing pin callbacks