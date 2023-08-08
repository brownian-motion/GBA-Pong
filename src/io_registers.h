#pragma once
#include "memory_types.h"

// Register                      Mem Addr    Bytes Access  Register      Description
// --------                      --------    ----- ------  --------      -----------
#define MEM_ADDR_REG_DISPCNT     4000000h  //2     R/W     DISPCNT       LCD Control
//      -                        4000002h  //2     R/W     -             Undocumented - Green Swap
#define MEM_ADDR_REG_DISPSTAT    4000004h  //2     R/W     DISPSTAT      General LCD Status (STAT,LYC)
#define MEM_ADDR_REG_VCOUNT      4000006h  //2     R       VCOUNT        Vertical Counter (LY)
#define MEM_ADDR_REG_BG0CNT      4000008h  //2     R/W     BG0CNT        BG0 Control
#define MEM_ADDR_REG_BG1CNT      400000Ah  //2     R/W     BG1CNT        BG1 Control
#define MEM_ADDR_REG_BG2CNT      400000Ch  //2     R/W     BG2CNT        BG2 Control
#define MEM_ADDR_REG_BG3CNT      400000Eh  //2     R/W     BG3CNT        BG3 Control
#define MEM_ADDR_REG_BG0HOFS     4000010h  //2     W       BG0HOFS       BG0 X-Offset
#define MEM_ADDR_REG_BG0VOFS     4000012h  //2     W       BG0VOFS       BG0 Y-Offset
#define MEM_ADDR_REG_BG1HOFS     4000014h  //2     W       BG1HOFS       BG1 X-Offset
#define MEM_ADDR_REG_BG1VOFS     4000016h  //2     W       BG1VOFS       BG1 Y-Offset
#define MEM_ADDR_REG_BG2HOFS     4000018h  //2     W       BG2HOFS       BG2 X-Offset
#define MEM_ADDR_REG_BG2VOFS     400001Ah  //2     W       BG2VOFS       BG2 Y-Offset
#define MEM_ADDR_REG_BG3HOFS     400001Ch  //2     W       BG3HOFS       BG3 X-Offset
#define MEM_ADDR_REG_BG3VOFS     400001Eh  //2     W       BG3VOFS       BG3 Y-Offset
#define MEM_ADDR_REG_BG2PA       4000020h  //2     W       BG2PA         BG2 Rotation/Scaling Parameter A (dx)
#define MEM_ADDR_REG_BG2PB       4000022h  //2     W       BG2PB         BG2 Rotation/Scaling Parameter B (dmx)
#define MEM_ADDR_REG_BG2PC       4000024h  //2     W       BG2PC         BG2 Rotation/Scaling Parameter C (dy)
#define MEM_ADDR_REG_BG2PD       4000026h  //2     W       BG2PD         BG2 Rotation/Scaling Parameter D (dmy)
#define MEM_ADDR_REG_BG2X        4000028h  //4     W       BG2X          BG2 Reference Point X-Coordinate
#define MEM_ADDR_REG_BG2Y        400002Ch  //4     W       BG2Y          BG2 Reference Point Y-Coordinate
#define MEM_ADDR_REG_BG3PA       4000030h  //2     W       BG3PA         BG3 Rotation/Scaling Parameter A (dx)
#define MEM_ADDR_REG_BG3PB       4000032h  //2     W       BG3PB         BG3 Rotation/Scaling Parameter B (dmx)
#define MEM_ADDR_REG_BG3PC       4000034h  //2     W       BG3PC         BG3 Rotation/Scaling Parameter C (dy)
#define MEM_ADDR_REG_BG3PD       4000036h  //2     W       BG3PD         BG3 Rotation/Scaling Parameter D (dmy)
#define MEM_ADDR_REG_BG3X        4000038h  //4     W       BG3X          BG3 Reference Point X-Coordinate
#define MEM_ADDR_REG_BG3Y        400003Ch  //4     W       BG3Y          BG3 Reference Point Y-Coordinate
#define MEM_ADDR_REG_WIN0H       4000040h  //2     W       WIN0H         Window 0 Horizontal Dimensions
#define MEM_ADDR_REG_WIN1H       4000042h  //2     W       WIN1H         Window 1 Horizontal Dimensions
#define MEM_ADDR_REG_WIN0V       4000044h  //2     W       WIN0V         Window 0 Vertical Dimensions
#define MEM_ADDR_REG_WIN1V       4000046h  //2     W       WIN1V         Window 1 Vertical Dimensions
#define MEM_ADDR_REG_WININ       4000048h  //2     R/W     WININ         Inside of Window 0 and 1
#define MEM_ADDR_REG_WINOUT      400004Ah  //2     R/W     WINOUT        Inside of OBJ Window & Outside of Windows
#define MEM_ADDR_REG_MOSAIC      400004Ch  //2     W       MOSAIC        Mosaic Size
//      -                        400004Eh  //      -       -             Not used
#define MEM_ADDR_REG_BLDCNT      4000050h  //2     R/W     BLDCNT        Color Special Effects Selection
#define MEM_ADDR_REG_BLDALPHA    4000052h  //2     W       BLDALPHA      Alpha Blending Coefficients
#define MEM_ADDR_REG_BLDY        4000054h  //2     W       BLDY          Brightness (Fade-In/Out) Coefficient
//      -                        4000056h  //      -       -             Not used

//// Sound Registers
#define MEM_ADDR_REG_SOUND1CNT_L 4000060h  //2     R/W     SOUND1CNT_L   Channel 1 Sweep register       (NR10)
#define MEM_ADDR_REG_SOUND1CNT_H 4000062h  //2     R/W     SOUND1CNT_H   Channel 1 Duty/Length/Envelope (NR11, NR12)
#define MEM_ADDR_REG_SOUND1CNT_X 4000064h  //2     R/W     SOUND1CNT_X   Channel 1 Frequency/Control    (NR13, NR14)
//      -                        4000066h  //      -       -             Not used
#define MEM_ADDR_REG_SOUND2CNT_L 4000068h  //2     R/W     SOUND2CNT_L   Channel 2 Duty/Length/Envelope (NR21, NR22)
//      -                        400006Ah  //      -       -             Not used
#define MEM_ADDR_REG_SOUND2CNT_H 400006Ch  //2     R/W     SOUND2CNT_H   Channel 2 Frequency/Control    (NR23, NR24)
//      -                        400006Eh  //      -       -             Not used
#define MEM_ADDR_REG_SOUND3CNT_L 4000070h  //2     R/W     SOUND3CNT_L   Channel 3 Stop/Wave RAM select (NR30)
#define MEM_ADDR_REG_SOUND3CNT_H 4000072h  //2     R/W     SOUND3CNT_H   Channel 3 Length/Volume        (NR31, NR32)
#define MEM_ADDR_REG_SOUND3CNT_X 4000074h  //2     R/W     SOUND3CNT_X   Channel 3 Frequency/Control    (NR33, NR34)
//      -                        4000076h  //      -       -             Not used
#define MEM_ADDR_REG_SOUND4CNT_L 4000078h  //2     R/W     SOUND4CNT_L   Channel 4 Length/Envelope      (NR41, NR42)
//      -                        400007Ah  //      -       -             Not used
#define MEM_ADDR_REG_SOUND4CNT_H 400007Ch  //2     R/W     SOUND4CNT_H   Channel 4 Frequency/Control    (NR43, NR44)
//      -                        400007Eh  //      -       -             Not used
#define MEM_ADDR_REG_SOUNDCNT_L  4000080h  //2     R/W     SOUNDCNT_L    Control Stereo/Volume/Enable   (NR50, NR51)
#define MEM_ADDR_REG_SOUNDCNT_H  4000082h  //2     R/W     SOUNDCNT_H    Control Mixing/DMA Control
#define MEM_ADDR_REG_SOUNDCNT_X  4000084h  //2     R/W     SOUNDCNT_X    Control Sound on/off           (NR52)
//      -                        4000086h  //      -       -             Not used
#define MEM_ADDR_REG_SOUNDBIAS   4000088h  //2     BIOS    SOUNDBIAS     Sound PWM Control
//      -                        400008Ah  //..    -       -             Not used
#define MEM_ADDR_REG_WAVE_RAM    4000090h  //2x10h R/W     WAVE_RAM      Channel 3 Wave Pattern RAM (2 banks!!)
#define MEM_ADDR_REG_FIFO_A      40000A0h  //4     W       FIFO_A        Channel A FIFO, Data 0-3
#define MEM_ADDR_REG_FIFO_B      40000A4h  //4     W       FIFO_B        Channel B FIFO, Data 0-3
//      -                        40000A8h  //      -       -             Not used

//// DMA Transfer Channels
#define MEM_ADDR_REG_DMA0SAD     40000B0h  //4     W       DMA0SAD       DMA 0 Source Address
#define MEM_ADDR_REG_DMA0DAD     40000B4h  //4     W       DMA0DAD       DMA 0 Destination Address
#define MEM_ADDR_REG_DMA0CNT_L   40000B8h  //2     W       DMA0CNT_L     DMA 0 Word Count
#define MEM_ADDR_REG_DMA0CNT_H   40000BAh  //2     R   /W  DMA0CNT_H     DMA 0 Control
#define MEM_ADDR_REG_DMA1SAD     40000BCh  //4     W       DMA1SAD       DMA 1 Source Address
#define MEM_ADDR_REG_DMA1DAD     40000C0h  //4     W       DMA1DAD       DMA 1 Destination Address
#define MEM_ADDR_REG_DMA1CNT_L   40000C4h  //2     W       DMA1CNT_L     DMA 1 Word Count
#define MEM_ADDR_REG_DMA1CNT_H   40000C6h  //2     R   /W  DMA1CNT_H     DMA 1 Control
#define MEM_ADDR_REG_DMA2SAD     40000C8h  //4     W       DMA2SAD       DMA 2 Source Address
#define MEM_ADDR_REG_DMA2DAD     40000CCh  //4     W       DMA2DAD       DMA 2 Destination Address
#define MEM_ADDR_REG_DMA2CNT_L   40000D0h  //2     W       DMA2CNT_L     DMA 2 Word Count
#define MEM_ADDR_REG_DMA2CNT_H   40000D2h  //2     R   /W  DMA2CNT_H     DMA 2 Control
#define MEM_ADDR_REG_DMA3SAD     40000D4h  //4     W       DMA3SAD       DMA 3 Source Address
#define MEM_ADDR_REG_DMA3DAD     40000D8h  //4     W       DMA3DAD       DMA 3 Destination Address
#define MEM_ADDR_REG_DMA3CNT_L   40000DCh  //2     W       DMA3CNT_L     DMA 3 Word Count
#define MEM_ADDR_REG_DMA3CNT_H   40000DEh  //2     R   /W  DMA3CNT_H     DMA 3 Control
//      -                        40000E0h  //      -       -             Not used

//// Timer Registers
#define MEM_ADDR_REG_TM0CNT_L    4000100h  //2     R/W     TM0CNT_L      Timer 0 Counter/Reload
#define MEM_ADDR_REG_TM0CNT_H    4000102h  //2     R/W     TM0CNT_H      Timer 0 Control
#define MEM_ADDR_REG_TM1CNT_L    4000104h  //2     R/W     TM1CNT_L      Timer 1 Counter/Reload
#define MEM_ADDR_REG_TM1CNT_H    4000106h  //2     R/W     TM1CNT_H      Timer 1 Control
#define MEM_ADDR_REG_TM2CNT_L    4000108h  //2     R/W     TM2CNT_L      Timer 2 Counter/Reload
#define MEM_ADDR_REG_TM2CNT_H    400010Ah  //2     R/W     TM2CNT_H      Timer 2 Control
#define MEM_ADDR_REG_TM3CNT_L    400010Ch  //2     R/W     TM3CNT_L      Timer 3 Counter/Reload
#define MEM_ADDR_REG_TM3CNT_H    400010Eh  //2     R/W     TM3CNT_H      Timer 3 Control
//      -                        4000110h  //      -       -             Not used

//// Serial Communication (1)
#define MEM_ADDR_REG_SIODATA32   4000120h  //4     R/W     SIODATA32     SIO Data (Normal-32bit Mode) (shared with below!)
#define MEM_ADDR_REG_SIOMULTI0   4000120h  //2     R/W     SIOMULTI0     SIO Data 0 (Parent)    (Multi-Player Mode)
#define MEM_ADDR_REG_SIOMULTI1   4000122h  //2     R/W     SIOMULTI1     SIO Data 1 (1st Child) (Multi-Player Mode)
#define MEM_ADDR_REG_SIOMULTI2   4000124h  //2     R/W     SIOMULTI2     SIO Data 2 (2nd Child) (Multi-Player Mode)
#define MEM_ADDR_REG_SIOMULTI3   4000126h  //2     R/W     SIOMULTI3     SIO Data 3 (3rd Child) (Multi-Player Mode)
#define MEM_ADDR_REG_SIOCNT      4000128h  //2     R/W     SIOCNT        SIO Control Register
#define MEM_ADDR_REG_SIOMLT_SEN  400012Ah  //2     R/W     SIOMLT_SEND   SIO Data (Local of Multi-Player) (shared below)
#define MEM_ADDR_REG_SIODATA8    400012Ah  //2     R/W     SIODATA8      SIO Data (Normal-8bit and UART Mode)
//      -                        400012Ch  //      -       -             Not used

//// Keypad Input
#define MEM_ADDR_REG_KEYINPUT    4000130h  //2     R       KEYINPUT      Key Status
#define MEM_ADDR_REG_KEYCNT      4000132h  //2     R/W     KEYCNT        Key Interrupt Control

//// Serial Communication (2)
#define MEM_ADDR_REG_RCNT        4000134h  //2     R/W     RCNT          SIO Mode Select/General Purpose Data
#define MEM_ADDR_REG_IR          4000136h  //-     -       IR            Ancient - Infrared Register (Prototypes only)
//      -                        4000138h  //      -       -             Not used
#define MEM_ADDR_REG_JOYCNT      4000140h  //2     R/W     JOYCNT        SIO JOY Bus Control
//      -                        4000142h  //      -       -             Not used
#define MEM_ADDR_REG_JOY_RECV    4000150h  //4     R/W     JOY_RECV      SIO JOY Bus Receive Data
#define MEM_ADDR_REG_JOY_TRANS   4000154h  //4     R/W     JOY_TRANS     SIO JOY Bus Transmit Data
#define MEM_ADDR_REG_JOYSTAT     4000158h  //2     R/?     JOYSTAT       SIO JOY Bus Receive Status
//      -                        400015Ah  //      -       -             Not used

//// Interrupt, Waitstate, and Power-Down Control
#define MEM_ADDR_REG_IE          4000200h  //2     R/W     IE            Interrupt Enable Register
#define MEM_ADDR_REG_IF          4000202h  //2     R/W     IF            Interrupt Request Flags / IRQ Acknowledge
#define MEM_ADDR_REG_WAITCNT     4000204h  //2     R/W     WAITCNT       Game Pak Waitstate Control
//      -                        4000206h  //      -       -             Not used
#define MEM_ADDR_REG_IME         4000208h  //2     R/W     IME           Interrupt Master Enable Register
//      -                        400020Ah  //      -       -             Not used
#define MEM_ADDR_REG_POSTFLG     4000300h  //1     R/W     POSTFLG       Undocumented - Post Boot Flag
#define MEM_ADDR_REG_HALTCNT     4000301h  //1     W       HALTCNT       Undocumented - Power Down Control
//      -                        4000302h  //      -       -             Not used
//?                              4000410h  //?     ?       ?             Undocumented - Purpose Unknown / Bug ??? 0FFh
//      -                        4000411h  //      -       -             Not used
//?                              4000800h  //4     R/W     ?             Undocumented - Internal Memory Control (R/W)
//      -                        4000804h  //      -       -             Not used
//?                              4xx0800h  //4     R/W     ?             Mirrors of 4000800h (repeated each 64K)






// 		Register                      								      Mem Addr    Bytes Access  Register      Description
// 		--------                      								      --------    ----- ------  --------      -----------
#define REG_DISPCNT     ((volatile uint16 *)  MEM_ADDR_REG_DISPCNT    ) //4000000h  //2     R/W     DISPCNT       LCD Control
#define REG_DISPSTAT    ((volatile uint16 *)  MEM_ADDR_REG_DISPSTAT   ) //4000004h  //2     R/W     DISPSTAT      General LCD Status (STAT,LYC)
#define REG_VCOUNT      ((volatile uint16 *)  MEM_ADDR_REG_VCOUNT     ) //4000006h  //2     R       VCOUNT        Vertical Counter (LY)
#define REG_BG0CNT      ((volatile uint16 *)  MEM_ADDR_REG_BG0CNT     ) //4000008h  //2     R/W     BG0CNT        BG0 Control
#define REG_BG1CNT      ((volatile uint16 *)  MEM_ADDR_REG_BG1CNT     ) //400000Ah  //2     R/W     BG1CNT        BG1 Control
#define REG_BG2CNT      ((volatile uint16 *)  MEM_ADDR_REG_BG2CNT     ) //400000Ch  //2     R/W     BG2CNT        BG2 Control
#define REG_BG3CNT      ((volatile uint16 *)  MEM_ADDR_REG_BG3CNT     ) //400000Eh  //2     R/W     BG3CNT        BG3 Control
#define REG_BG0HOFS     ((volatile uint16 *)  MEM_ADDR_REG_BG0HOFS    ) //4000010h  //2     W       BG0HOFS       BG0 X-Offset
#define REG_BG0VOFS     ((volatile uint16 *)  MEM_ADDR_REG_BG0VOFS    ) //4000012h  //2     W       BG0VOFS       BG0 Y-Offset
#define REG_BG1HOFS     ((volatile uint16 *)  MEM_ADDR_REG_BG1HOFS    ) //4000014h  //2     W       BG1HOFS       BG1 X-Offset
#define REG_BG1VOFS     ((volatile uint16 *)  MEM_ADDR_REG_BG1VOFS    ) //4000016h  //2     W       BG1VOFS       BG1 Y-Offset
#define REG_BG2HOFS     ((volatile uint16 *)  MEM_ADDR_REG_BG2HOFS    ) //4000018h  //2     W       BG2HOFS       BG2 X-Offset
#define REG_BG2VOFS     ((volatile uint16 *)  MEM_ADDR_REG_BG2VOFS    ) //400001Ah  //2     W       BG2VOFS       BG2 Y-Offset
#define REG_BG3HOFS     ((volatile uint16 *)  MEM_ADDR_REG_BG3HOFS    ) //400001Ch  //2     W       BG3HOFS       BG3 X-Offset
#define REG_BG3VOFS     ((volatile uint16 *)  MEM_ADDR_REG_BG3VOFS    ) //400001Eh  //2     W       BG3VOFS       BG3 Y-Offset
#define REG_BG2PA       ((volatile uint16 *)  MEM_ADDR_REG_BG2PA      ) //4000020h  //2     W       BG2PA         BG2 Rotation/Scaling Parameter A (dx)
#define REG_BG2PB       ((volatile uint16 *)  MEM_ADDR_REG_BG2PB      ) //4000022h  //2     W       BG2PB         BG2 Rotation/Scaling Parameter B (dmx)
#define REG_BG2PC       ((volatile uint16 *)  MEM_ADDR_REG_BG2PC      ) //4000024h  //2     W       BG2PC         BG2 Rotation/Scaling Parameter C (dy)
#define REG_BG2PD       ((volatile uint16 *)  MEM_ADDR_REG_BG2PD      ) //4000026h  //2     W       BG2PD         BG2 Rotation/Scaling Parameter D (dmy)
#define REG_BG2X        ((volatile uint32 *)  MEM_ADDR_REG_BG2X       ) //4000028h  //4     W       BG2X          BG2 Reference Point X-Coordinate
#define REG_BG2Y        ((volatile uint32 *)  MEM_ADDR_REG_BG2Y       ) //400002Ch  //4     W       BG2Y          BG2 Reference Point Y-Coordinate
#define REG_BG3PA       ((volatile uint16 *)  MEM_ADDR_REG_BG3PA      ) //4000030h  //2     W       BG3PA         BG3 Rotation/Scaling Parameter A (dx)
#define REG_BG3PB       ((volatile uint16 *)  MEM_ADDR_REG_BG3PB      ) //4000032h  //2     W       BG3PB         BG3 Rotation/Scaling Parameter B (dmx)
#define REG_BG3PC       ((volatile uint16 *)  MEM_ADDR_REG_BG3PC      ) //4000034h  //2     W       BG3PC         BG3 Rotation/Scaling Parameter C (dy)
#define REG_BG3PD       ((volatile uint16 *)  MEM_ADDR_REG_BG3PD      ) //4000036h  //2     W       BG3PD         BG3 Rotation/Scaling Parameter D (dmy)
#define REG_BG3X        ((volatile uint32 *)  MEM_ADDR_REG_BG3X       ) //4000038h  //4     W       BG3X          BG3 Reference Point X-Coordinate
#define REG_BG3Y        ((volatile uint32 *)  MEM_ADDR_REG_BG3Y       ) //400003Ch  //4     W       BG3Y          BG3 Reference Point Y-Coordinate
#define REG_WIN0H       ((volatile uint16 *)  MEM_ADDR_REG_WIN0H      ) //4000040h  //2     W       WIN0H         Window 0 Horizontal Dimensions
#define REG_WIN1H       ((volatile uint16 *)  MEM_ADDR_REG_WIN1H      ) //4000042h  //2     W       WIN1H         Window 1 Horizontal Dimensions
#define REG_WIN0V       ((volatile uint16 *)  MEM_ADDR_REG_WIN0V      ) //4000044h  //2     W       WIN0V         Window 0 Vertical Dimensions
#define REG_WIN1V       ((volatile uint16 *)  MEM_ADDR_REG_WIN1V      ) //4000046h  //2     W       WIN1V         Window 1 Vertical Dimensions
#define REG_WININ       ((volatile uint16 *)  MEM_ADDR_REG_WININ      ) //4000048h  //2     R/W     WININ         Inside of Window 0 and 1
#define REG_WINOUT      ((volatile uint16 *)  MEM_ADDR_REG_WINOUT     ) //400004Ah  //2     R/W     WINOUT        Inside of OBJ Window & Outside of Windows
#define REG_MOSAIC      ((volatile uint16 *)  MEM_ADDR_REG_MOSAIC     ) //400004Ch  //2     W       MOSAIC        Mosaic Size
#define REG_BLDCNT      ((volatile uint16 *)  MEM_ADDR_REG_BLDCNT     ) //4000050h  //2     R/W     BLDCNT        Color Special Effects Selection
#define REG_BLDALPHA    ((volatile uint16 *)  MEM_ADDR_REG_BLDALPHA   ) //4000052h  //2     W       BLDALPHA      Alpha Blending Coefficients
#define REG_BLDY        ((volatile uint16 *)  MEM_ADDR_REG_BLDY       ) //4000054h  //2     W       BLDY          Brightness (Fade-In/Out) Coefficient

//// Sound Registers
#define REG_SOUND1CNT_L ((volatile uint16 *)  MEM_ADDR_REG_SOUND1CNT_L) //4000060h  //2     R/W     SOUND1CNT_L   Channel 1 Sweep register       (NR10)
#define REG_SOUND1CNT_H ((volatile uint16 *)  MEM_ADDR_REG_SOUND1CNT_H) //4000062h  //2     R/W     SOUND1CNT_H   Channel 1 Duty/Length/Envelope (NR11, NR12)
#define REG_SOUND1CNT_X ((volatile uint16 *)  MEM_ADDR_REG_SOUND1CNT_X) //4000064h  //2     R/W     SOUND1CNT_X   Channel 1 Frequency/Control    (NR13, NR14)
#define REG_SOUND2CNT_L ((volatile uint16 *)  MEM_ADDR_REG_SOUND2CNT_L) //4000068h  //2     R/W     SOUND2CNT_L   Channel 2 Duty/Length/Envelope (NR21, NR22)
#define REG_SOUND2CNT_H ((volatile uint16 *)  MEM_ADDR_REG_SOUND2CNT_H) //400006Ch  //2     R/W     SOUND2CNT_H   Channel 2 Frequency/Control    (NR23, NR24)
#define REG_SOUND3CNT_L ((volatile uint16 *)  MEM_ADDR_REG_SOUND3CNT_L) //4000070h  //2     R/W     SOUND3CNT_L   Channel 3 Stop/Wave RAM select (NR30)
#define REG_SOUND3CNT_H ((volatile uint16 *)  MEM_ADDR_REG_SOUND3CNT_H) //4000072h  //2     R/W     SOUND3CNT_H   Channel 3 Length/Volume        (NR31, NR32)
#define REG_SOUND3CNT_X ((volatile uint16 *)  MEM_ADDR_REG_SOUND3CNT_X) //4000074h  //2     R/W     SOUND3CNT_X   Channel 3 Frequency/Control    (NR33, NR34)
#define REG_SOUND4CNT_L ((volatile uint16 *)  MEM_ADDR_REG_SOUND4CNT_L) //4000078h  //2     R/W     SOUND4CNT_L   Channel 4 Length/Envelope      (NR41, NR42)
#define REG_SOUND4CNT_H ((volatile uint16 *)  MEM_ADDR_REG_SOUND4CNT_H) //400007Ch  //2     R/W     SOUND4CNT_H   Channel 4 Frequency/Control    (NR43, NR44)
#define REG_SOUNDCNT_L  ((volatile uint16 *)  MEM_ADDR_REG_SOUNDCNT_L ) //4000080h  //2     R/W     SOUNDCNT_L    Control Stereo/Volume/Enable   (NR50, NR51)
#define REG_SOUNDCNT_H  ((volatile uint16 *)  MEM_ADDR_REG_SOUNDCNT_H ) //4000082h  //2     R/W     SOUNDCNT_H    Control Mixing/DMA Control
#define REG_SOUNDCNT_X  ((volatile uint16 *)  MEM_ADDR_REG_SOUNDCNT_X ) //4000084h  //2     R/W     SOUNDCNT_X    Control Sound on/off           (NR52)
#define REG_SOUNDBIAS   ((volatile uint16 *)  MEM_ADDR_REG_SOUNDBIAS  ) //4000088h  //2     BIOS    SOUNDBIAS     Sound PWM Control
#define REG_WAVE_RAM    ((volatile uint16 *)  MEM_ADDR_REG_WAVE_RAM   ) //4000090h  //2x10h R/W     WAVE_RAM      Channel 3 Wave Pattern RAM (2 banks!!)
#define REG_FIFO_A      ((volatile uint32 *)  MEM_ADDR_REG_FIFO_A     ) //40000A0h  //4     W       FIFO_A        Channel A FIFO, Data 0-3
#define REG_FIFO_B      ((volatile uint32 *)  MEM_ADDR_REG_FIFO_B     ) //40000A4h  //4     W       FIFO_B        Channel B FIFO, Data 0-3

//// DMA Transfer Channels
#define REG_DMA0SAD     ((volatile uint32 *)  MEM_ADDR_REG_DMA0SAD    ) //40000B0h  //4     W       DMA0SAD       DMA 0 Source Address
#define REG_DMA0DAD     ((volatile uint32 *)  MEM_ADDR_REG_DMA0DAD    ) //40000B4h  //4     W       DMA0DAD       DMA 0 Destination Address
#define REG_DMA0CNT_L   ((volatile uint16 *)  MEM_ADDR_REG_DMA0CNT_L  ) //40000B8h  //2     W       DMA0CNT_L     DMA 0 Word Count
#define REG_DMA0CNT_H   ((volatile uint16 *)  MEM_ADDR_REG_DMA0CNT_H  ) //40000BAh  //2     R   /W  DMA0CNT_H     DMA 0 Control
#define REG_DMA1SAD     ((volatile uint32 *)  MEM_ADDR_REG_DMA1SAD    ) //40000BCh  //4     W       DMA1SAD       DMA 1 Source Address
#define REG_DMA1DAD     ((volatile uint32 *)  MEM_ADDR_REG_DMA1DAD    ) //40000C0h  //4     W       DMA1DAD       DMA 1 Destination Address
#define REG_DMA1CNT_L   ((volatile uint16 *)  MEM_ADDR_REG_DMA1CNT_L  ) //40000C4h  //2     W       DMA1CNT_L     DMA 1 Word Count
#define REG_DMA1CNT_H   ((volatile uint16 *)  MEM_ADDR_REG_DMA1CNT_H  ) //40000C6h  //2     R   /W  DMA1CNT_H     DMA 1 Control
#define REG_DMA2SAD     ((volatile uint32 *)  MEM_ADDR_REG_DMA2SAD    ) //40000C8h  //4     W       DMA2SAD       DMA 2 Source Address
#define REG_DMA2DAD     ((volatile uint32 *)  MEM_ADDR_REG_DMA2DAD    ) //40000CCh  //4     W       DMA2DAD       DMA 2 Destination Address
#define REG_DMA2CNT_L   ((volatile uint16 *)  MEM_ADDR_REG_DMA2CNT_L  ) //40000D0h  //2     W       DMA2CNT_L     DMA 2 Word Count
#define REG_DMA2CNT_H   ((volatile uint16 *)  MEM_ADDR_REG_DMA2CNT_H  ) //40000D2h  //2     R   /W  DMA2CNT_H     DMA 2 Control
#define REG_DMA3SAD     ((volatile uint32 *)  MEM_ADDR_REG_DMA3SAD    ) //40000D4h  //4     W       DMA3SAD       DMA 3 Source Address
#define REG_DMA3DAD     ((volatile uint32 *)  MEM_ADDR_REG_DMA3DAD    ) //40000D8h  //4     W       DMA3DAD       DMA 3 Destination Address
#define REG_DMA3CNT_L   ((volatile uint16 *)  MEM_ADDR_REG_DMA3CNT_L  ) //40000DCh  //2     W       DMA3CNT_L     DMA 3 Word Count
#define REG_DMA3CNT_H   ((volatile uint16 *)  MEM_ADDR_REG_DMA3CNT_H  ) //40000DEh  //2     R   /W  DMA3CNT_H     DMA 3 Control

//// Timer Registers
#define REG_TM0CNT_L    ((volatile uint16 *)  MEM_ADDR_REG_TM0CNT_L   ) //4000100h  //2     R/W     TM0CNT_L      Timer 0 Counter/Reload
#define REG_TM0CNT_H    ((volatile uint16 *)  MEM_ADDR_REG_TM0CNT_H   ) //4000102h  //2     R/W     TM0CNT_H      Timer 0 Control
#define REG_TM1CNT_L    ((volatile uint16 *)  MEM_ADDR_REG_TM1CNT_L   ) //4000104h  //2     R/W     TM1CNT_L      Timer 1 Counter/Reload
#define REG_TM1CNT_H    ((volatile uint16 *)  MEM_ADDR_REG_TM1CNT_H   ) //4000106h  //2     R/W     TM1CNT_H      Timer 1 Control
#define REG_TM2CNT_L    ((volatile uint16 *)  MEM_ADDR_REG_TM2CNT_L   ) //4000108h  //2     R/W     TM2CNT_L      Timer 2 Counter/Reload
#define REG_TM2CNT_H    ((volatile uint16 *)  MEM_ADDR_REG_TM2CNT_H   ) //400010Ah  //2     R/W     TM2CNT_H      Timer 2 Control
#define REG_TM3CNT_L    ((volatile uint16 *)  MEM_ADDR_REG_TM3CNT_L   ) //400010Ch  //2     R/W     TM3CNT_L      Timer 3 Counter/Reload
#define REG_TM3CNT_H    ((volatile uint16 *)  MEM_ADDR_REG_TM3CNT_H   ) //400010Eh  //2     R/W     TM3CNT_H      Timer 3 Control

//// Serial Communication (1)
#define REG_SIODATA32   ((volatile uint32 *)  MEM_ADDR_REG_SIODATA32  ) //4000120h  //4     R/W     SIODATA32     SIO Data (Normal-32bit Mode) (shared with below!)
#define REG_SIOMULTI0   ((volatile uint16 *)  MEM_ADDR_REG_SIOMULTI0  ) //4000120h  //2     R/W     SIOMULTI0     SIO Data 0 (Parent)    (Multi-Player Mode)
#define REG_SIOMULTI1   ((volatile uint16 *)  MEM_ADDR_REG_SIOMULTI1  ) //4000122h  //2     R/W     SIOMULTI1     SIO Data 1 (1st Child) (Multi-Player Mode)
#define REG_SIOMULTI2   ((volatile uint16 *)  MEM_ADDR_REG_SIOMULTI2  ) //4000124h  //2     R/W     SIOMULTI2     SIO Data 2 (2nd Child) (Multi-Player Mode)
#define REG_SIOMULTI3   ((volatile uint16 *)  MEM_ADDR_REG_SIOMULTI3  ) //4000126h  //2     R/W     SIOMULTI3     SIO Data 3 (3rd Child) (Multi-Player Mode)
#define REG_SIOCNT      ((volatile uint16 *)  MEM_ADDR_REG_SIOCNT     ) //4000128h  //2     R/W     SIOCNT        SIO Control Register
#define REG_SIOMLT_SEN  ((volatile uint16 *)  MEM_ADDR_REG_SIOMLT_SEN ) //400012Ah  //2     R/W     SIOMLT_SEND   SIO Data (Local of Multi-Player) (shared below)
#define REG_SIODATA8    ((volatile uint16 *)  MEM_ADDR_REG_SIODATA8   ) //400012Ah  //2     R/W     SIODATA8      SIO Data (Normal-8bit and UART Mode)

//// Keypad Input
#define REG_KEYINPUT    ((volatile uint16 *)  MEM_ADDR_REG_KEYINPUT   ) //4000130h  //2     R       KEYINPUT      Key Status
#define REG_KEYCNT      ((volatile uint16 *)  MEM_ADDR_REG_KEYCNT     ) //4000132h  //2     R/W     KEYCNT        Key Interrupt Control

//// Serial Communication (2)
#define REG_RCNT        ((volatile uint16 *)  MEM_ADDR_REG_RCNT       ) //4000134h  //2     R/W     RCNT          SIO Mode Select/General Purpose Data
#define REG_JOYCNT      ((volatile uint16 *)  MEM_ADDR_REG_JOYCNT     ) //4000140h  //2     R/W     JOYCNT        SIO JOY Bus Control
#define REG_JOY_RECV    ((volatile uint32 *)  MEM_ADDR_REG_JOY_RECV   ) //4000150h  //4     R/W     JOY_RECV      SIO JOY Bus Receive Data
#define REG_JOY_TRANS   ((volatile uint32 *)  MEM_ADDR_REG_JOY_TRANS  ) //4000154h  //4     R/W     JOY_TRANS     SIO JOY Bus Transmit Data
#define REG_JOYSTAT     ((volatile uint16 *)  MEM_ADDR_REG_JOYSTAT    ) //4000158h  //2     R/?     JOYSTAT       SIO JOY Bus Receive Status

//// Interrupt, Waitstate, and Power-Down Control
#define REG_IE          ((volatile uint16 *)  MEM_ADDR_REG_IE         ) //4000200h  //2     R/W     IE            Interrupt Enable Register
#define REG_IF          ((volatile uint16 *)  MEM_ADDR_REG_IF         ) //4000202h  //2     R/W     IF            Interrupt Request Flags / IRQ Acknowledge
#define REG_WAITCNT     ((volatile uint16 *)  MEM_ADDR_REG_WAITCNT    ) //4000204h  //2     R/W     WAITCNT       Game Pak Waitstate Control
#define REG_IME         ((volatile uint16 *)  MEM_ADDR_REG_IME        ) //4000208h  //2     R/W     IME           Interrupt Master Enable Register
#define REG_POSTFLG     ((volatile uint8 *)   MEM_ADDR_REG_POSTFLG    ) //4000300h  //1     R/W     POSTFLG       Undocumented - Post Boot Flag
#define REG_HALTCNT     ((volatile uint8 *)   MEM_ADDR_REG_HALTCNT    ) //4000301h  //1     W       HALTCNT       Undocumented - Power Down Control