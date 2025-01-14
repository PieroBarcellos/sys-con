# sys-con

#### A Nintendo Switch custom sysmodule for third-party controller support. No man-in-the-middle required! 
###### \[Switch FW 5.0.0+\] [Atmosphère only]

## UPDATE
Logitech Steering Wheels (G920), when connected on Switch dock (USB), are recognized with a XboxOne Controller. In this fork, I tried add some Logiteck SDK files, but I can't compile (problems with DevKitPro and Atmosphere Lib in my PC - something I did wrong). If you can compile the files, call me.
More about this here: https://github.com/cathery/sys-con/issues/308




## Description
This sysmodule aims to provide complete functionality for most popular game controllers not supported by Nintendo Switch.
At the current moment, **only USB connection** is supported.

This app is missing a lot of features. For more information, see the [issues page](https://github.com/cathery/sys-con/issues).

### ⚠ I can't support your generic 3rd party HID controller yet.
It is a limitation of the firmware and I'm looking to work around it.


## Install

Grab the latest zip from the [releases page](https://github.com/cathery/sys-con/releases). Extract it in your SD card and boot/reboot your switch.

## Config

sys-con comes with a config folder located at `sdmc:/config/sys-con/`. It contains options for adjusting stick/trigger deadzone, as well as remapping inputs. For more information, see `example.ini` in the same folder. All changes to the files will be updated in real time.

## Progress roadmap
- [x] **~~Docked USB Support~~**
- [x] **~~\[5.0.0-7.0.0\] FW Version Support~~**
- [x] **~~Xbox 360 Controller Support~~**
- [x] **~~Xbox One X/S Controller Support~~**
- [x] **~~Dualshock 3 Support~~**
- [x] **~~Undocked USB Support~~** Works with a USB-C OTG adapter. Some knock-off brands may not support OTG.
- [x] **~~Xbox 360 Wireless adapter~~**
- [x] **~~Dualshock 4 Support~~**
- [ ] **[Rumble Support](https://github.com/cathery/sys-con/issues/1)**
- [ ] **~~[Bluetooth Support]~~** See ndeadly's [MissionControl](https://github.com/ndeadly/MissionControl)
- [ ] **[Motion Controls Support](https://github.com/cathery/sys-con/issues/9)**
- [ ] **Config application**

## Building (For developers)

Don't download the project as ZIP. It doesn't copy the submodules correctly and you will be left with empty folders.

Instead, clone the repository **recursively** using any git client you have. (Git Bash, Git GUI, Github Desktop, etc.)

Like all other switch projects, you need to have [devkitA64](https://switchbrew.org/wiki/Setting_up_Development_Environment) set up on your system.

For compatibility with the Atmosphere-libs dependency, this project currently uses a version of libnx at commit **[b35d42f](https://github.com/switchbrew/libnx/commit/b35d42faaa60b02662aaaf0702614f6e4afcbbbc)**. Clone the repository, checkout to that commit, and run `make install` to set it up.

If you have **Visual Studio Code**, you can open the project as a folder and run the build tasks from inside the program. It also has Intellisense configured for switch development, if you have DEVKITPRO correctly defined in your environment variables. Handy!

Otherwise, you can open the console inside the project directory and use one of the following commands:

`make -j8`: Builds the project and its dependencies (libstratosphere) and places the resulting files in the output folder (out/). The -j8 means it will create 8 separate threads to speed up the building process. Make it lower if it freezes up your system.

`make clean`: Cleans the project files (but not the dependencies).

`make mrproper`: Cleans the project files and the dependencies.

For an in-depth explanation of how sys-con works, see [here](source).

[![ko-fi](https://www.ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/H2H316ZQV)
