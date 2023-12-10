/*
    C-Dogs SDL
    A port of the legendary (and fun) action/arcade cdogs.
    Copyright (c) 2013-2015, Cong Xu
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/
#include "palette.h"

#include "pic_manager.h"
#include "utils.h"

#define GAMMA 4
static color_t palette[] =
{
	{0, 15, 20, 255},
	{0, 0, 0, 255},
	{56, 32, 24, 255},
	{51, 27, 19, 255},
	{46, 22, 14, 255},
	{41, 17, 9, 255},
	{31, 12, 1, 255},
	{23, 7, 1, 255},
	{20, 6, 0, 255},
	{15, 3, 1, 255},
	{0, 43, 0, 255},
	{0, 63, 0, 255},
	{0, 48, 48, 255},
	{48, 63, 63, 255},
	{0, 63, 63, 255},
	{63, 63, 63, 255},
	{63, 56, 0, 255},
	{63, 46, 0, 255},
	{63, 36, 0, 255},
	{63, 26, 0, 255},
	{63, 16, 0, 255},
	{63, 6, 0, 255},
	{63, 0, 0, 255},
	{56, 0, 0, 255},
	{48, 0, 0, 255},
	{40, 0, 0, 255},
	{34, 0, 0, 255},
	{28, 0, 0, 255},
	{23, 0, 0, 255},
	{13, 0, 0, 255},
	{8, 0, 0, 255},
	{48, 0, 48, 255},
	{63, 63, 63, 255},
	{58, 58, 58, 255},
	{53, 53, 53, 255},
	{48, 48, 48, 255},
	{43, 43, 43, 255},
	{38, 38, 38, 255},
	{33, 33, 33, 255},
	{28, 28, 28, 255},
	{23, 23, 23, 255},
	{18, 18, 18, 255},
	{15, 15, 15, 255},
	{12, 12, 12, 255},
	{10, 10, 10, 255},
	{8, 8, 8, 255},
	{5, 5, 5, 255},
	{0, 0, 0, 255},
	{21, 17, 1, 255},
	{15, 11, 0, 255},
	{10, 8, 1, 255},
	{18, 12, 1, 255},
	{33, 33, 43, 255},
	{28, 28, 38, 255},
	{23, 23, 33, 255},
	{18, 18, 28, 255},
	{13, 13, 23, 255},
	{10, 10, 18, 255},
	{8, 8, 15, 255},
	{7, 7, 12, 255},
	{5, 5, 10, 255},
	{3, 3, 8, 255},
	{3, 3, 5, 255},
	{48, 0, 48, 255},
	{0, 53, 0, 255},
	{0, 41, 0, 255},
	{0, 30, 0, 255},
	{0, 18, 0, 255},
	{43, 33, 33, 255},
	{38, 28, 28, 255},
	{33, 23, 23, 255},
	{28, 18, 18, 255},
	{23, 13, 13, 255},
	{18, 10, 10, 255},
	{15, 8, 8, 255},
	{12, 7, 7, 255},
	{10, 5, 5, 255},
	{8, 3, 3, 255},
	{5, 3, 3, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{33, 43, 33, 255},
	{18, 38, 18, 255},
	{13, 33, 13, 255},
	{8, 28, 8, 255},
	{3, 23, 3, 255},
	{0, 18, 0, 255},
	{0, 15, 0, 255},
	{0, 12, 0, 255},
	{0, 10, 0, 255},
	{0, 8, 0, 255},
	{0, 5, 0, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 43, 15, 255},
	{43, 38, 13, 255},
	{37, 32, 11, 255},
	{32, 27, 9, 255},
	{27, 22, 8, 255},
	{22, 17, 6, 255},
	{16, 11, 4, 255},
	{11, 6, 2, 255},
	{13, 13, 23, 255},
	{12, 12, 21, 255},
	{10, 10, 19, 255},
	{9, 9, 17, 255},
	{7, 7, 14, 255},
	{6, 6, 12, 255},
	{4, 4, 10, 255},
	{3, 3, 8, 255},
	{43, 33, 43, 255},
	{38, 28, 38, 255},
	{33, 23, 33, 255},
	{28, 18, 28, 255},
	{23, 13, 23, 255},
	{18, 10, 18, 255},
	{15, 8, 15, 255},
	{12, 7, 12, 255},
	{10, 5, 10, 255},
	{8, 3, 8, 255},
	{5, 3, 5, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{43, 0, 0, 255},
	{38, 0, 0, 255},
	{33, 0, 0, 255},
	{28, 0, 0, 255},
	{23, 0, 0, 255},
	{18, 0, 0, 255},
	{15, 0, 0, 255},
	{12, 0, 0, 255},
	{10, 0, 0, 255},
	{8, 0, 0, 255},
	{5, 0, 0, 255},
	{48, 0, 48, 255},
	{61, 37, 19, 255},
	{55, 32, 16, 255},
	{49, 28, 14, 255},
	{43, 23, 11, 255},
	{38, 19, 8, 255},
	{32, 14, 5, 255},
	{26, 10, 3, 255},
	{20, 5, 0, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{43, 21, 0, 255},
	{39, 19, 0, 255},
	{35, 17, 0, 255},
	{32, 16, 0, 255},
	{28, 14, 0, 255},
	{24, 12, 0, 255},
	{20, 10, 0, 255},
	{16, 8, 0, 255},
	{13, 7, 0, 255},
	{9, 5, 0, 255},
	{5, 3, 0, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{0, 18, 28, 255},
	{0, 17, 25, 255},
	{0, 15, 22, 255},
	{0, 14, 20, 255},
	{0, 13, 17, 255},
	{0, 12, 14, 255},
	{0, 10, 11, 255},
	{0, 9, 8, 255},
	{0, 8, 6, 255},
	{0, 6, 3, 255},
	{0, 5, 0, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{38, 0, 0, 255},
	{34, 0, 0, 255},
	{30, 0, 0, 255},
	{26, 0, 0, 255},
	{22, 0, 0, 255},
	{18, 0, 0, 255},
	{14, 0, 0, 255},
	{10, 0, 0, 255},
	{33, 33, 33, 255},
	{29, 29, 29, 255},
	{26, 26, 26, 255},
	{22, 22, 22, 255},
	{19, 19, 19, 255},
	{15, 15, 15, 255},
	{12, 12, 12, 255},
	{8, 8, 8, 255},
	{38, 38, 0, 255},
	{34, 34, 0, 255},
	{30, 30, 0, 255},
	{26, 26, 0, 255},
	{22, 22, 0, 255},
	{18, 18, 0, 255},
	{14, 14, 0, 255},
	{10, 10, 0, 255},
	{39, 19, 0, 255},
	{35, 17, 0, 255},
	{32, 16, 0, 255},
	{28, 14, 0, 255},
	{24, 12, 0, 255},
	{20, 10, 0, 255},
	{17, 9, 0, 255},
	{13, 7, 0, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{48, 0, 48, 255},
	{63, 56, 0, 255},
	{63, 63, 63, 255}
};
color_t PaletteToColor(unsigned char idx)
{
	color_t color = palette[idx];
	color.r = (uint8_t)CLAMP(color.r * GAMMA, 0, 255);
	color.g = (uint8_t)CLAMP(color.g * GAMMA, 0, 255);
	color.b = (uint8_t)CLAMP(color.b * GAMMA, 0, 255);
	color.a = 255;
	return color;
}
Uint32 LookupPalette(unsigned char idx)
{
	return COLOR2PIXEL(PaletteToColor(idx));
}
