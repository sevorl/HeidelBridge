#ifdef RELAY_LOCK_ENABLED

#include <Arduino.h>
#include "../Logger/Logger.h"
#include "../../Configuration/Pins.h"
#include "../../Configuration/Constants.h"
#include "RelayManager.h"

namespace RelayManager
{
    static bool gIsLocked = false;
    static uint32_t gLastStateChange = 0;

    // Initializes the relay manager
    void Init()
    {
        Logger::Info("Initializing Relay Lock Manager");
        
        // Configure relay pin as output
        pinMode(Pins::PinRelayLock, OUTPUT);
        
        // Set initial state (unlocked)
        SetLocked(false);
        
        Logger::Info("Relay Lock Manager initialized on pin %d", Pins::PinRelayLock);
    }

    // Sets the lock state (true = locked, false = unlocked)
    void SetLocked(bool locked)
    {
        uint32_t now = millis();
        
        // Debounce protection
        if (now - gLastStateChange < Constants::RelayLock::DebounceMs)
        {
            Logger::Debug("Relay state change ignored (debounce)");
            return;
        }
        
        if (gIsLocked != locked)
        {
            gIsLocked = locked;
            gLastStateChange = now;
            
            // Set relay state based on configuration
            bool pinState = Constants::RelayLock::RelayActiveHigh ? locked : !locked;
            digitalWrite(Pins::PinRelayLock, pinState ? HIGH : LOW);
            
            Logger::Info("Relay lock %s (pin state: %s)", 
                locked ? "ENGAGED" : "RELEASED",
                pinState ? "HIGH" : "LOW");
        }
    }

    // Gets the current relay lock state
    bool IsLocked()
    {
        return gIsLocked;
    }
}

#endif // RELAY_LOCK_ENABLED