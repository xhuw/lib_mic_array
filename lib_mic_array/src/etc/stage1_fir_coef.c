// Copyright 2022 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.

#include <stdint.h>

#include "mic_array/etc/filters_default.h"


// Each coefficient is 16 bits and the number of coefficients must be a multiple of 256.
// int32_t type so that it's word-aligned. So this is 512 16-bit coefficients.
const uint32_t stage1_coef[STAGE1_WORDS] = {

  0x44160F8F, 0x728624D0, 0xC78D773F, 0xD11A533B, 0xB994B117, 0xF9DD63C6, 0x1648C29D, 0xE3E0D044, 
  0x0685DE8B, 0x99B31247, 0xE76AE975, 0x9DCDBB9E, 0xF3BB6773, 0x5D2EADCF, 0xC4919B33, 0xA2F742C1, 
  0x072C158D, 0xF1F90E3B, 0xFE621D09, 0xE85DAF9A, 0xB3EB742F, 0x21708CFF, 0xB8E13F1F, 0x635069C0, 
  0xAD63E6DB, 0x5F1BCD30, 0xF3AE33AA, 0x93600FB8, 0x3BE00D92, 0xAB98EB9E, 0x1967B1F5, 0xB6CF8D6A, 
  0x631FF8EC, 0x9F59D21F, 0xF8F1D3AB, 0xCBD3E860, 0x0C2F97A7, 0xAB971E3F, 0xF09735F2, 0x6E3FF18C, 
  0x1F0000F1, 0xE0CDCBF5, 0xFDD98188, 0x206187EE, 0xEFC30C08, 0x2303377F, 0x5FA7660F, 0x1E0001F0, 
  0x00FFFF01, 0x556E3958, 0x541693FA, 0x887F1328, 0x2991FC22, 0xBF92D054, 0x3538ED55, 0x01FFFE00, 
  0x00000001, 0x998FF8CA, 0x33E59825, 0xD87F5E0A, 0xA0F5FC37, 0x48334F98, 0xA63FE333, 0x00000000, 
  0x00000001, 0xE1F007C6, 0xA5539D61, 0xED2A6148, 0x250CA96F, 0x0D73954A, 0xC7C01F0F, 0x00000000, 
  0x00000001, 0xFE00003E, 0x6CCF9E4B, 0xF1B380DC, 0x76039B1F, 0xA4F3E66C, 0xF80000FF, 0x00000000, 
  0x00000001, 0xFFFFFFFE, 0x1C3F9F8D, 0x5496AA90, 0x12AAD255, 0x63F3F870, 0xFFFFFFFF, 0x00000000, 
  0x00000001, 0xFFFFFFFE, 0x03FF9FF1, 0x9924CCE0, 0x0E664933, 0x1FF3FF80, 0xFFFFFFFF, 0x00000000, 
  0x00000001, 0xFFFFFFFE, 0x00006001, 0xE1C70F00, 0x01E1C70F, 0x000C0000, 0xFFFFFFFF, 0x00000000, 
  0x00000001, 0xFFFFFFFE, 0x00000001, 0xFE07F000, 0x001FC0FF, 0x00000000, 0xFFFFFFFF, 0x00000000, 
  0x00000001, 0xFFFFFFFE, 0x00000001, 0xFFF80000, 0x00003FFF, 0x00000000, 0xFFFFFFFF, 0x00000000, 
  0xFFFFFFFE, 0x00000001, 0xFFFFFFFE, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 

};