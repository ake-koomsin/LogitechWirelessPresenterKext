//
//  LogitechWirelessPresenterDriver.cpp
//  LogitechWirelessPresenter
//
//  Created by Ake Koomsin on 10/31/12.
//  Copyright (c) 2012 Ake Koomsin. All rights reserved.
//

#include <IOKit/IOLib.h>
#include <IOKit/hid/IOHIDUsageTables.h>

#include "LogitechWirelessPresenterDriver.h"

#define super IOHIDEventDriver

OSDefineMetaClassAndStructors(LogitechWirelessPresenterDriver, IOHIDEventDriver)

bool LogitechWirelessPresenterDriver::start(IOService *provider)
{
    IOLog("LogitechWirelessPresenterDriver start\n");
    return super::start(provider);
}

void LogitechWirelessPresenterDriver::stop(IOService *provider)
{
    IOLog("LogitechWirelessPresenterDriver stop\n");
    return super::stop(provider);
}

void LogitechWirelessPresenterDriver::dispatchKeyboardEvent(AbsoluteTime  timeStamp,
                                                             UInt32        usagePage,
                                                             UInt32        usage,
                                                             UInt32        value,
                                                             IOOptionBits  options)
{
    /* 
     This condition seems to be always true.
     Logitech Wireless Presenter R400/R800 is basically a keyboard.
     */
    if (usagePage == kHIDPage_KeyboardOrKeypad) {
        if (usage == kHIDUsage_KeyboardPeriod) {
            usage = kHIDUsage_KeyboardB;
        } else if (usage == kHIDUsage_KeyboardF5) {
            usage = kHIDUsage_KeyboardP;
            /* Introduce a little delay between modifier and P key */
            super::dispatchKeyboardEvent(timeStamp,
                                         usagePage,
                                         kHIDUsage_KeyboardLeftGUI,
                                         value,
                                         options);
            super::dispatchKeyboardEvent(timeStamp + 1,
                                         usagePage,
                                         kHIDUsage_KeyboardLeftAlt,
                                         value,
                                         options);
            timeStamp += 2;
        }
    }

    super::dispatchKeyboardEvent(timeStamp,
                                 usagePage,
                                 usage,
                                 value,
                                 options);

}
