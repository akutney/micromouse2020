# Environment Setup

## Software Development Requirements

- Download and install [Atmel Studio 7](https://www.microchip.com/mplab/avr-support/atmel-studio-7) (Required)
- Enable and install [Windows Subsystem for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10) (WSL)
    - Download and install [Git for Windows](https://git-scm.com/downloads) if you don't want to use WSL, or if you want it in addition to WSL
- Download and install [Visual Studio Code](https://code.visualstudio.com/download) (can be any text editor)

## PCB Design Requirements (only if working on PCB)

- Download and install [Eagle](https://www.autodesk.com/products/eagle/free-download)

## Clone the Repo

Run the following command in either a bash prompt if you are using WSL or in the regular old command prompt if you install Git for Windows

    $ git clone https://github.com/ksurct/micromouse2020.git

## Opening the Software Project

- Double click the solution file located at `software/micromouse.atsln`

## Opening the PCB Project

- Use Eagle to open `pcb/eagle.epf`