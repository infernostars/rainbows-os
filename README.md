# Rainbows
## Version 0001
Welcome to Rainbows. Rainbows is a Work in Progress. It will not run as described. This is only the planned functionality.

## Planned functionality
Rainbows is a mix of command line and GUI. 
Commands operate in the command line, and programs can be executed in in the command line, then command line is hidden and program can be used. 
Exiting the program is also possible with a selected keybind.

## How to use
To use Rainbows, you need to flash a storage medium, such as an USB stick or CD drive, and then insert it into your computer.
Then, restart your computer.
Before your previous operating system starts booting up, press the key that opens the boot-device selection menu for you, such as Esc, F10 or F12.
Select USB stick or CD drive as main boot device.
The subsequent reboot should detect operating system.
When limine bootloader pops up, just press enter.
Rainbows is ready to use now.

## How to install on a virtual machine (for beginners)
* VirtualBox
To install Rainbows on VirtualBox, create a new machine by clicking New at the top.
Name your machine whatever you want.
Set type to other and version Other/Unknown (64-bit).
Any memory size should be sufficient for this current version of Rainbows.

Then, click on Create a virtual hard disk now in the tab Hard Disk and click on Create.
If you already have a virtual hard disk file that you want to use, click on Use an existing virtual hard disk file and select one.
Then, change file size to a minimum of 100MB.

Select prefered hard disk file type and way of storage on physical hard disk to your liking.
We recommend Fixed Size for performance, but Dynamically allocated is better if long waiting times for creating a fixed size hard disk are unfavorable.
Once you decided, click on Create.

Now, click Settings at the top. 
Go to Storage.
Click on Controller: IDE.

Click on the disk symbol.
Click on Add. Insert your Rainbows .iso file. 
Now, click Start at the top.

You're done. 
If you encur errors, ask Infernostars for help.

## Current functionality
* Currently, Rainbows only has a bootup message. 

## (Future) Commands
* `/help` shows all available commands and programs
