#pragma once

#ifdef RELAY_LOCK_ENABLED

namespace RelayManager
{
    // Initializes the relay manager
    void Init();

    // Sets the lock state (true = locked, false = unlocked)
    void SetLocked(bool locked);

    // Gets the current relay lock state
    bool IsLocked();
}

#endif // RELAY_LOCK_ENABLED