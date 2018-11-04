This is a simple implementation of Pong I wrote for the GameBoy Advance (GBA) as a proof-of-concept in preparation for more-complicated games.

![Screenshot of the game](screenshot.png)

It follows [this introduction](https://www.reinterpretcast.com/writing-a-game-boy-advance-game) for the basic approach to developing the code.

#Dependencies

Compiling this C code into a GBA module requires [the ARM module of devkitPro](http://devkitpro.org/wiki/Getting_Started/devkitARM)

Once installed, ensure `devkitpro/devkitARM/bin` is in your `PATH`

#Compilation

The following commands will turn `main.c` into a GBA ROM `main.gba`:

    arm-none-eabi-gcc -c main.c -mthumb-interwork -mthumb -O2 -o main.o
    arm-none-eabi-gcc main.o -mthumb-interwork -mthumb -specs=gba.specs -o main.elf
    arm-none-eabi-objcopy -v -O binary main.elf main.gba
    gbafix main.gba

I've compiled these commands into a Makefile. Please note that `make clean` does not work on Windows.

#Running Games

The generated ROM can be loaded onto a GBA cartridge, or run through an emulator. For Windows on x86, I recommend [VisualBoyEmulator](http://www.emuparadise.me/Nintendo_Gameboy_Advance_Emulators/Windows/VisualBoyAdvance/86). For OSx, I recommend [Boycott Advance](http://www.bannister.org/software/ba.htm).

#Reference

For more detail on the specifications of the GBA, see [akkit.org](http://www.akkit.org/info/gbatek.htm#lcdobjoamattributes)

#Contributing

As this is a test space for code, I will not be accepting any contributions.

#License

This code is subject to the [GNU General Public License](https://www.gnu.org/copyleft/gpl.html).
