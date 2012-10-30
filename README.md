Logitech Wireless Presenter R400/R800 OS X Kernel Extension
==========================================================

Motivation
----------

Logitech Wireless Presenter R400/R800 is initially designed for Microsoft PowerPoint on Windows. As one of Apple Keynote user, it is annoying that this device is not fully compatible; Play Slide button and Blank button don't work. This kernel extension aims to make Logitech Wireless Presenter R400/R800 compatible with Apple Keynote.

Installation
------------

- You can download the installation package (Restart is required). This is recommended if you want to use only.
- You can compile from the source code, put LogitechWirelessPresenter.kext to /System/Library/Extensions and run 'sudo kextutil /System/Library/Extensions/LogitechWirelessPresenter.kext'

How does it work?
-----------------

Actually, Logitech Wireless Presenter R400/R800 is just a keyboard. The main idea is to capture the character sent from this device and replace when necessary.

LogitechWirelessPresenterDriver simply overrides dispatchKeyboardEvent() to replace an appropriate keys.

LogitechWirelessPresenterDriver is a subclass of IOHIDEventDriver which is a subclass of IOHIDEventService where dispatchKeyboardEvent() resides.

License
-------

This source code is under MIT License.
