/*----------------------------------------------------------------------------*/
/* Define Characters                                                          */
/*----------------------------------------------------------------------------*/
// 7-segment arragment :
//       a
//     -----
//    |     |
//   f|     |b
//    |  g  |
//     -----
//    |     |
//   e|     |c
//    |  d  |
//     -----  . h

//#define  seg_h 0x01
//#define  seg_c 0x02
//#define  seg_b 0x04
//#define  seg_a 0x08
//#define  seg_d 0x10
//#define  seg_e 0x20
//#define  seg_g 0x40
//#define  seg_f 0x80

#define  seg_h 0x08
#define  seg_c 0x04
#define  seg_b 0x02
#define  seg_a 0x01
#define  seg_d 0x80
#define  seg_e 0x40
#define  seg_g 0x20
#define  seg_f 0x10

unsigned char seg[]={
         seg_a+seg_b+seg_c+seg_d+seg_e+seg_f, // char "0"
         seg_b+seg_c,                         // char "1"
         seg_a+seg_b+seg_d+seg_e+seg_g,       // char "2"
         seg_a+seg_b+seg_c+seg_d+seg_g,       // char "3"
         seg_b+seg_c+seg_f+seg_g,             // char "4"
         seg_a+seg_c+seg_d+seg_f+seg_g,       // char "5"
         seg_a+seg_c+seg_d+seg_e+seg_f+seg_g, // char "6"
         seg_a+seg_b+seg_c,                   // char "7"
         seg_a+seg_b+seg_c+seg_d+seg_e+seg_f+seg_g,  // char "8"
         seg_a+seg_b+seg_c+seg_d+seg_f+seg_g, // char "9"
         seg_a+seg_b+seg_c+seg_e+seg_f+seg_g, // char "A"
         seg_c+seg_d+seg_e+seg_f+seg_g,       // char "b"
         seg_a+seg_d+seg_e+seg_f,             // char "C"
         seg_b+seg_c+seg_d+seg_e+seg_g,       // char "d"
         seg_a+seg_d+seg_e+seg_f+seg_g,       // char "E"
         seg_a+seg_e+seg_f+seg_g};            // char "F"

/*----------------------------------------------------------------------------*/
/* Define Symbols                                                             */
/*----------------------------------------------------------------------------*/
#define  S_g     0x04 //S17(g)

#define  S_m1    0x08 //S8(m)
#define  S_Zero  0x04 //S7(Zero)
#define  S_Tare  0x02 //S6(Tare)
#define  S_Minus 0x01 //S5(Minus)
#define  S_Bat4  0x80 //S4(Bat4)
#define  S_Bat3  0x40 //S3(Bat3)
#define  S_Bat2  0x20 //S2(Bat2)
#define  S_Bat1  0x10 //S1(Bat1)

#define  S_V     0x08 //S16(V)
#define  S_Ohm   0x04 //S15(Ohm)
#define  S_A     0x02 //S14(A)
#define  S9	     0x01 //S9
#define  S13     0x80 //S13
#define  S12     0x40 //S12
#define  S11     0x20 //S11
#define  S_M2    0x10 //S10(M)

#define  S21     0x80 //S21
#define  S20     0x40 //S20
#define  S19     0x20 //S19
#define  S18     0x10 //S18

#define  Char_H  seg_b+seg_c+seg_e+seg_f+seg_g
#define  Char_Y  seg_b+seg_c+seg_d+seg_f+seg_g
#define  Char_c  seg_d+seg_e+seg_g
#define  Char_o  seg_c+seg_d+seg_e+seg_g
#define  Char_n  seg_c+seg_e+seg_g

#define  Char_P  seg_a+seg_b+seg_e+seg_f+seg_g
#define  Char_A  seg_a+seg_b+seg_c+seg_e+seg_f+seg_g
#define  Char_S  seg_a+seg_c+seg_d+seg_f+seg_g
