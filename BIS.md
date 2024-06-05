# BIS

We use this dualpanto-testing repo for assignment, and uploading dualpanto firmware too.

If you have issue about installing all requirements and this testing tool, **please first ask on discord #general channel.**
Often other students have already solved issue you have. (with 60 students in 2024, there's a good chance they have solved it)


## Requirements
This is same as [READEM.md](./Readme.md) of dualpanto-testing.

### Install the ESP32 driver
- [Download](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads) the latest installer for your OS-Version.
- Run the installer.

### Setup C++ environment

#### macOS
 - Go to Appstore and install Xcode
 - Run `xcode-select –install` to install the compilers
 - Run `sudo xcode-select -s /Applications/Xcode.app/Contents/Developer`

#### windows
 - Install Visual Studio 2019 or 2017
 - Select at least the workload “Desktopentwicklung mit C++”

### Install IDE
We highly recommend to use PyCharm to run this test flow.
#### PyCharm
1. download [PyCharm](https://www.jetbrains.com/community/education/#students)
2. clone this repo and open it with pycharm
3. [create vertial environment (we use python 3.7)](https://www.jetbrains.com/help/pycharm/creating-virtual-environment.html)and [install package using requirements.txt](https://www.jetbrains.com/help/pycharm/managing-dependencies.html)
4. install [Mermaid](https://plugins.jetbrains.com/plugin/20146-mermaid) plugin for flowchart vis
5. follow Test Flow section

you can run  unittest from Markdown preview 
![markdown](./resources/execute.jpg)

or [execute unittest from scripts](https://www.jetbrains.com/help/pycharm/testing-your-first-python-application.html#create-test)
#### VScode
1. download [VScode](https://code.visualstudio.com/)
2. clone this repo and open it with VScode
3. [set venv and install package using requirements.txt](https://code.visualstudio.com/docs/python/environments)
4. follow Test Flow section ([Test flow in VSCode](https://code.visualstudio.com/docs/python/testing))

#### Command Line
you can also run all unittest from command line interface if struggle with setting up IDE. Install python library in requirements.txt, then execute script.


## Assignment Week7: kinematics and rendering wall
Assignment for Week7 is to write code of god object and kinematics partially, and (mainly) get familiar with uploading firmware and this testing workflow since we use the test flow a lot from this week.

We have two coding assignments this week. First, open `config.py` and set your COM port to connect dualpanto before beginning.

### #1 kinematics
If you properly code it, IT handle follow Me handle

1. make sure install ESP32 driver, IDE, and all python library on requirements.txt
2. go to `dualpant-testing/firmware/haptics/BIS week7 Kinematics/firmware/src/hardware/panto.cpp`,find `TODO BIS` and write code
3. `python -m unittest test_firmware.Kinematics.test_BIS_week7_kinematics`
4. if you feel the device has issue, follow [test flow (Mechanics and Hardware)](Readme.md)
5. take the video that linkage is synced when you intearct with ME handle.
6. and upload to dokuwiki project page

### #2 rendering wall
If you properly code it, you will find a thin wall in the midle of dualpanto intearcitve region.

1. make sure install ESP32 driver, IDE, and all python library on requirements.txt
2. go to `dualpant-testing/firmware/haptics/BIS week7 God Object/firmware/src/physics/godObject.cpp`,find `TODO BIS` and write code
3. `python -m unittest test_firmware.Haptics.test_BIS_week7_go`
4. if you feel the device has issue, follow [test flow (Mechanics and Hardware)](Readme.md)
5. take the video that you interacts with rendered wall
6. and upload to dokuwiki project page

## Assignment Week8: 
1. upload the original firmware to your DualPanto, for this
   - checkout feature/encoder-driver branch
   - you want to have all submodules cloned (run `git submodule init`, then `git submodule update`)
   - then copy `firmware/haptics/line wall/firmware/src/config/config.cpp` to `firmware/dualpantoframework/firmware/src/config/config.cpp`
     and copy `firmware/haptics/line wall/firmware/include/config/config.hpp` to `firmware/dualpantoframework/firmware/ include /config/config.hpp`
   - then change `util.compile_framework(...)` to `util.upload_framework(...)` in `UploadDualPantoFramework.test_upload_dp_firmware` in `test_firmware.py`
   - now just as before, run `python -m unittest test_firmware.UploadDualPantoFramework`
3. checkout master branch at https://github.com/HassoPlattnerInstituteHCI/PantoDraw-Web
4. search for the TODO BIS and fill them in with the things you learned today
5. run dualdraw and draw a nice picture (see readme.md for instructions)
6. upload a video of your drawing to dokuwiki

## Uploading DualpantoFramework
From Week9, we will develop dualpanto app. sometimes you want to upload dualpanto famework again and again when...

1. you update dualpanto framework (e.g. you tune PID)
2. you plug dualpanto device into different PC
    - we observe dualpanto has some wall rendering issue when you connect dualpanto to other PC. e.g, you uplaod firmware from mac and connect to windows pc.
    - this is not always happend. but You need to keep this in mind.
    - We haven't known why so. Welcome you to contribute here!

`python -m unittest test_firmware.UploadDualpantoFrameowrk.test_upload_dp_firmware`
