#pragma once

namespace Pins
{
#ifdef LILYGO_BOARD
    // Pin connections for LilyGo T-Can485:
    // ESP32 GPIO16 -> RS485 RX
    // ESP32 GPIO17 -> RS485 TX  
    // ESP32 GPIO4  -> RS485 EN
    constexpr uint8_t PinRX = GPIO_NUM_16;
    constexpr uint8_t PinTX = GPIO_NUM_17;
    constexpr uint8_t PinRTS = GPIO_NUM_4;
    
#ifdef RELAY_LOCK_ENABLED
    // GPIO2 available for relay control on LilyGo
    constexpr uint8_t PinRelayLock = GPIO_NUM_2;
#endif

#else
    // Pin connections for ESP32 with MAX485:
    // ESP32 GPIO18 -> MAXRS485 RO (Receiver Output)
    // ESP32 GPIO19 -> MAXRS485 DI (Driver Input)
    // ESP32 GPIO21 -> MAXRS485 DE+RE
    constexpr uint8_t PinRX = GPIO_NUM_18;
    constexpr uint8_t PinTX = GPIO_NUM_19;
    constexpr uint8_t PinRTS = GPIO_NUM_21;

#ifdef RELAY_LOCK_ENABLED
    // GPIO4 available for relay control on standard ESP32
    constexpr uint8_t PinRelayLock = GPIO_NUM_4;
#endif

#endif
}