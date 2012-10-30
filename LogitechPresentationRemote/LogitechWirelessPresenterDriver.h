//
//  LogitechWirelessPresenterDriver.h
//  LogitechWirelessPresenter
//
//  Created by Ake Koomsin on 10/31/12.
//  Copyright (c) 2012 Ake Koomsin. All rights reserved.
//

#include <IOKit/hidevent/IOHIDEventDriver.h>


class LogitechWirelessPresenterDriver : public IOHIDEventDriver
{
    OSDeclareDefaultStructors(LogitechWirelessPresenterDriver)

public:
    virtual bool start(IOService *provider);
    virtual void stop(IOService *provider);

    virtual void dispatchKeyboardEvent(AbsoluteTime  timeStamp,
                                       UInt32        usagePage,
                                       UInt32        usage,
                                       UInt32        value,
                                       IOOptionBits  options = 0);

};
