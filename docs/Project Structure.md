# Project Structure

At a high level, this repository is split into two major folders:

- `software/` for develop the code to be ran on the robot
- `pcb/` for designing the pcb schematic and laying our the board

## software/

In the software folder is the following directory structure:

    ├── include/
    │   ├── error.h
    │   └── errors.h
    ├── src/
    │   ├── algorithms/
    │   ├── ASF/
    │   ├── config/
    │   ├── drivers/
    │   ├── types/
    │   ├── asf.h
    │   ├── error.c
    │   ├── main.c
    │   ├── Makefile
    │   ├── settings.h
    │   └── testing.h
    ├── jlink.config
    ├── jlink.log
    ├── micromouse.atsln
    ├── micromouse.componentinfo.xml
    └── micromouse.cproj


### Here are a few highlights

| Item             | Descripition                                                                                                                                            |
|------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| error.h          | We have an error reporting framework that can easily be included to any file as <error.h>                                                               |
| algorihms/       | Directory of navigation guidance and control algorithms to use in the robot                                                                             |
| ASF/             | The Advanced Software Framework from Atmel. This consists of low-level drivers that can be used by including <asf.h> into a file.                       |
| config/          | An ASF specific folder of hardware configuration such as clocks and drivers                                                                             |
| drivers/         | Drivers to control hardware.                                                                                                                            |
| types/           | Project types. include the types.h file to include all types.                                                                                           |
| main.c           | The main entry point to the program when running on the microcontroller                                                                                 |
| Makefile         | When we don't want to run code on the microcontroller but would rather test it running on a PC we used this file by running `make test` in a bash shell |
| testing.h        | Part of the testing framework. Include this file in *_test.c files.                                                                                     |
| micromouse.atsln | The Atmel Studio solution. Double click this open the project in Atmel Studio.                                                                          |

## pcb/
// TODO