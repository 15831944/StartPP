// GLRenderer.cpp: implementation of the CGLRenderer class.
//
//////////////////////////////////////////////////////////////////////
// Copyright (C) 1998,1999,2000,2003,2004,2005,2006  Dmitry Tcvetkov aka TCHV
//
// All Rights Reserved
//
// Disclaimer : this text is under authority of goverment laws, US and Russian Federation
// Unauthorizing compilation, modification and re-engineering is strictly prohibited

#include "stdafx.h"
#ifdef __WXMAC__
#include <gl.h>
#else
#include <GL/gl.h>
#endif
#include <FTGL/ftgl.h>
#include "GLRenderer.h"

//#define USE_FONT_BITMAPS

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGLRenderer::CGLRenderer(): m_hWnd(nullptr), m_hMemDC(nullptr), m_hMemRC(nullptr)
{
	memset(m_fontBases, 0, sizeof(m_fontBases));
	memset(m_fonts, 0, sizeof(m_fonts));
	memset(m_arrLogFonts, 0, sizeof(m_arrLogFonts));
}

CGLRenderer::~CGLRenderer()
{
	ReleaseAllFonts();
}

//***********************************************************************
// Function:	CreateRGBPalette
//
// Purpose:		Creates a logical palette
//
// Parameters:
//	  void
//
// Returns:
//	  void
//
//**********************************************************************
#ifdef STATIC_PALETTE
static struct
{
	WORD			palVersion;
	WORD			palNumEntries;
	PALETTEENTRY	palPalEntries[256];
}
rgb8palette =
{
	0x300,
	256,
	{
		{
			0, 0, 0, 0
		},

/* 0 - Exact match with default 0 */
		{
			63, 0, 0, 0
		},

/* 1 */
		{
			104, 0, 0, 0
		},

/* 2 */
		{
			128, 0, 0, 0
		},

/* 3 - Changed to match default 1 */
		{
			171, 0, 0, 0
		},

/* 4 */
		{
			200, 0, 0, 0
		},

/* 5 */
		{
			229, 0, 0, 0
		},

/* 6 */
		{
			255, 0, 0, 0
		},

/* 7 - Exact match with default 13 */
		{
			0, 63, 0, 0
		},

/* 8 */
		{
			63, 63, 0, 0
		},

/* 9 */
		{
			104, 63, 0, 0
		},

/* 10 */
		{
			139, 63, 0, 0
		},

/* 11 */
		{
			171, 63, 0, 0
		},

/* 12 */
		{
			200, 63, 0, 0
		},

/* 13 */
		{
			229, 63, 0, 0
		},

/* 14 */
		{
			255, 63, 0, 0
		},

/* 15 */
		{
			0, 104, 0, 0
		},

/* 16 */
		{
			63, 104, 0, 0
		},

/* 17 */
		{
			104, 104, 0, 0
		},

/* 18 */
		{
			139, 104, 0, 0
		},

/* 19 */
		{
			171, 104, 0, 0
		},

/* 20 */
		{
			200, 104, 0, 0
		},

/* 21 */
		{
			229, 104, 0, 0
		},

/* 22 */
		{
			255, 104, 0, 0
		},

/* 23 */
		{
			0, 128, 0, 0
		},

/* 24 - Changed to match default 2 */
		{
			63, 139, 0, 0
		},

/* 25 */
		{
			104, 139, 0, 0
		},

/* 26 */
		{
			128, 128, 0, 0
		},

/* 27 - Changed to match default 3 */
		{
			171, 139, 0, 0
		},

/* 28 */
		{
			200, 139, 0, 0
		},

/* 29 */
		{
			229, 139, 0, 0
		},

/* 30 */
		{
			255, 139, 0, 0
		},

/* 31 */
		{
			0, 171, 0, 0
		},

/* 32 */
		{
			63, 171, 0, 0
		},

/* 33 */
		{
			104, 171, 0, 0
		},

/* 34 */
		{
			139, 171, 0, 0
		},

/* 35 */
		{
			171, 171, 0, 0
		},

/* 36 */
		{
			200, 171, 0, 0
		},

/* 37 */
		{
			229, 171, 0, 0
		},

/* 38 */
		{
			255, 171, 0, 0
		},

/* 39 */
		{
			0, 200, 0, 0
		},

/* 40 */
		{
			63, 200, 0, 0
		},

/* 41 */
		{
			104, 200, 0, 0
		},

/* 42 */
		{
			139, 200, 0, 0
		},

/* 43 */
		{
			171, 200, 0, 0
		},

/* 44 */
		{
			200, 200, 0, 0
		},

/* 45 */
		{
			229, 200, 0, 0
		},

/* 46 */
		{
			255, 200, 0, 0
		},

/* 47 */
		{
			0, 229, 0, 0
		},

/* 48 */
		{
			63, 229, 0, 0
		},

/* 49 */
		{
			104, 229, 0, 0
		},

/* 50 */
		{
			139, 229, 0, 0
		},

/* 51 */
		{
			171, 229, 0, 0
		},

/* 52 */
		{
			200, 229, 0, 0
		},

/* 53 */
		{
			229, 229, 0, 0
		},

/* 54 */
		{
			255, 229, 0, 0
		},

/* 55 */
		{
			0, 255, 0, 0
		},

/* 56 - Exact match with default 14 */
		{
			63, 255, 0, 0
		},

/* 57 */
		{
			104, 255, 0, 0
		},

/* 58 */
		{
			139, 255, 0, 0
		},

/* 59 */
		{
			171, 255, 0, 0
		},

/* 60 */
		{
			200, 255, 0, 0
		},

/* 61 */
		{
			229, 255, 0, 0
		},

/* 62 */
		{
			255, 255, 0, 0
		},

/* 63 - Exact match with default 15 */
		{
			0, 0, 128, 0
		},

/* 64 - Changed to match default 4 */
		{
			63, 0, 116, 0
		},

/* 65 */
		{
			104, 0, 116, 0
		},

/* 66 */
		{
			128, 0, 128, 0
		},

/* 67 - Changed to match default 5 */
		{
			171, 0, 116, 0
		},

/* 68 */
		{
			200, 0, 116, 0
		},

/* 69 */
		{
			229, 0, 116, 0
		},

/* 70 */
		{
			255, 0, 116, 0
		},

/* 71 */
		{
			0, 63, 116, 0
		},

/* 72 */
		{
			63, 63, 116, 0
		},

/* 73 */
		{
			104, 63, 116, 0
		},

/* 74 */
		{
			139, 63, 116, 0
		},

/* 75 */
		{
			171, 63, 116, 0
		},

/* 76 */
		{
			200, 63, 116, 0
		},

/* 77 */
		{
			229, 63, 116, 0
		},

/* 78 */
		{
			255, 63, 116, 0
		},

/* 79 */
		{
			0, 104, 116, 0
		},

/* 80 */
		{
			63, 104, 116, 0
		},

/* 81 */
		{
			104, 104, 116, 0
		},

/* 82 */
		{
			139, 104, 116, 0
		},

/* 83 */
		{
			171, 104, 116, 0
		},

/* 84 */
		{
			200, 104, 116, 0
		},

/* 85 */
		{
			229, 104, 116, 0
		},

/* 86 */
		{
			255, 104, 116, 0
		},

/* 87 */
		{
			0, 128, 128, 0
		},

/* 88 - Changed to match default 6 */
		{
			63, 139, 116, 0
		},

/* 89 */
		{
			104, 139, 116, 0
		},

/* 90 */
		{
			128, 128, 128, 0
		},

/* 91 - Changed to match default 12 */
		{
			171, 139, 116, 0
		},

/* 92 */
		{
			200, 139, 116, 0
		},

/* 93 */
		{
			229, 139, 116, 0
		},

/* 94 */
		{
			255, 139, 116, 0
		},

/* 95 */
		{
			0, 171, 116, 0
		},

/* 96 */
		{
			63, 171, 116, 0
		},

/* 97 */
		{
			104, 171, 116, 0
		},

/* 98 */
		{
			139, 171, 116, 0
		},

/* 99 */
		{
			171, 171, 116, 0
		},

/* 100 */
		{
			200, 171, 116, 0
		},

/* 101 */
		{
			229, 171, 116, 0
		},

/* 102 */
		{
			255, 171, 116, 0
		},

/* 103 */
		{
			0, 200, 116, 0
		},

/* 104 */
		{
			63, 200, 116, 0
		},

/* 105 */
		{
			104, 200, 116, 0
		},

/* 106 */
		{
			139, 200, 116, 0
		},

/* 107 */
		{
			171, 200, 116, 0
		},

/* 108 */
		{
			200, 200, 116, 0
		},

/* 109 */
		{
			229, 200, 116, 0
		},

/* 110 */
		{
			255, 200, 116, 0
		},

/* 111 */
		{
			0, 229, 116, 0
		},

/* 112 */
		{
			63, 229, 116, 0
		},

/* 113 */
		{
			104, 229, 116, 0
		},

/* 114 */
		{
			139, 229, 116, 0
		},

/* 115 */
		{
			171, 229, 116, 0
		},

/* 116 */
		{
			200, 229, 116, 0
		},

/* 117 */
		{
			229, 229, 116, 0
		},

/* 118 */
		{
			255, 229, 116, 0
		},

/* 119 */
		{
			0, 255, 116, 0
		},

/* 120 */
		{
			63, 255, 116, 0
		},

/* 121 */
		{
			104, 255, 116, 0
		},

/* 122 */
		{
			139, 255, 116, 0
		},

/* 123 */
		{
			171, 255, 116, 0
		},

/* 124 */
		{
			200, 255, 116, 0
		},

/* 125 */
		{
			229, 255, 116, 0
		},

/* 126 */
		{
			255, 255, 116, 0
		},

/* 127 */
		{
			0, 0, 191, 0
		},

/* 128 */
		{
			63, 0, 191, 0
		},

/* 129 */
		{
			104, 0, 191, 0
		},

/* 130 */
		{
			139, 0, 191, 0
		},

/* 131 */
		{
			171, 0, 191, 0
		},

/* 132 */
		{
			200, 0, 191, 0
		},

/* 133 */
		{
			229, 0, 191, 0
		},

/* 134 */
		{
			255, 0, 191, 0
		},

/* 135 */
		{
			0, 63, 191, 0
		},

/* 136 */
		{
			63, 63, 191, 0
		},

/* 137 */
		{
			104, 63, 191, 0
		},

/* 138 */
		{
			139, 63, 191, 0
		},

/* 139 */
		{
			171, 63, 191, 0
		},

/* 140 */
		{
			200, 63, 191, 0
		},

/* 141 */
		{
			229, 63, 191, 0
		},

/* 142 */
		{
			255, 63, 191, 0
		},

/* 143 */
		{
			0, 104, 191, 0
		},

/* 144 */
		{
			63, 104, 191, 0
		},

/* 145 */
		{
			104, 104, 191, 0
		},

/* 146 */
		{
			139, 104, 191, 0
		},

/* 147 */
		{
			171, 104, 191, 0
		},

/* 148 */
		{
			200, 104, 191, 0
		},

/* 149 */
		{
			229, 104, 191, 0
		},

/* 150 */
		{
			255, 104, 191, 0
		},

/* 151 */
		{
			0, 139, 191, 0
		},

/* 152 */
		{
			63, 139, 191, 0
		},

/* 153 */
		{
			104, 139, 191, 0
		},

/* 154 */
		{
			139, 139, 191, 0
		},

/* 155 */
		{
			171, 139, 191, 0
		},

/* 156 */
		{
			200, 139, 191, 0
		},

/* 157 */
		{
			229, 139, 191, 0
		},

/* 158 */
		{
			255, 139, 191, 0
		},

/* 159 */
		{
			0, 171, 191, 0
		},

/* 160 */
		{
			63, 171, 191, 0
		},

/* 161 */
		{
			104, 171, 191, 0
		},

/* 162 */
		{
			139, 171, 191, 0
		},

/* 163 */
		{
			160, 160, 164, 0
		},

/* 164 - Changed to match default 11 */
		{
			200, 171, 191, 0
		},

/* 165 */
		{
			229, 171, 191, 0
		},

/* 166 */
		{
			255, 171, 191, 0
		},

/* 167 */
		{
			0, 200, 191, 0
		},

/* 168 */
		{
			63, 200, 191, 0
		},

/* 169 */
		{
			104, 200, 191, 0
		},

/* 170 */
		{
			139, 200, 191, 0
		},

/* 171 */
		{
			171, 200, 191, 0
		},

/* 172 */
		{
			192, 192, 192, 0
		},

/* 173 - Changed to match default 7 */
		{
			229, 200, 191, 0
		},

/* 174 */
		{
			255, 200, 191, 0
		},

/* 175 */
		{
			0, 229, 191, 0
		},

/* 176 */
		{
			63, 229, 191, 0
		},

/* 177 */
		{
			104, 229, 191, 0
		},

/* 178 */
		{
			139, 229, 191, 0
		},

/* 179 */
		{
			171, 229, 191, 0
		},

/* 180 */
		{
			192, 220, 192, 0
		},

/* 181 - Changed to match default 8 */
		{
			229, 229, 191, 0
		},

/* 182 */
		{
			255, 229, 191, 0
		},

/* 183 */
		{
			0, 255, 191, 0
		},

/* 184 */
		{
			63, 255, 191, 0
		},

/* 185 */
		{
			104, 255, 191, 0
		},

/* 186 */
		{
			139, 255, 191, 0
		},

/* 187 */
		{
			171, 255, 191, 0
		},

/* 188 */
		{
			200, 255, 191, 0
		},

/* 189 */
		{
			229, 255, 191, 0
		},

/* 190 */
		{
			255, 255, 191, 0
		},

/* 191 */
		{
			0, 0, 255, 0
		},

/* 192 - Exact match with default 16 */
		{
			63, 0, 255, 0
		},

/* 193 */
		{
			104, 0, 255, 0
		},

/* 194 */
		{
			139, 0, 255, 0
		},

/* 195 */
		{
			171, 0, 255, 0
		},

/* 196 */
		{
			200, 0, 255, 0
		},

/* 197 */
		{
			229, 0, 255, 0
		},

/* 198 */
		{
			255, 0, 255, 0
		},

/* 199 - Exact match with default 17 */
		{
			0, 63, 255, 0
		},

/* 200 */
		{
			63, 63, 255, 0
		},

/* 201 */
		{
			104, 63, 255, 0
		},

/* 202 */
		{
			139, 63, 255, 0
		},

/* 203 */
		{
			171, 63, 255, 0
		},

/* 204 */
		{
			200, 63, 255, 0
		},

/* 205 */
		{
			229, 63, 255, 0
		},

/* 206 */
		{
			255, 63, 255, 0
		},

/* 207 */
		{
			0, 104, 255, 0
		},

/* 208 */
		{
			63, 104, 255, 0
		},

/* 209 */
		{
			104, 104, 255, 0
		},

/* 210 */
		{
			139, 104, 255, 0
		},

/* 211 */
		{
			171, 104, 255, 0
		},

/* 212 */
		{
			200, 104, 255, 0
		},

/* 213 */
		{
			229, 104, 255, 0
		},

/* 214 */
		{
			255, 104, 255, 0
		},

/* 215 */
		{
			0, 139, 255, 0
		},

/* 216 */
		{
			63, 139, 255, 0
		},

/* 217 */
		{
			104, 139, 255, 0
		},

/* 218 */
		{
			139, 139, 255, 0
		},

/* 219 */
		{
			171, 139, 255, 0
		},

/* 220 */
		{
			200, 139, 255, 0
		},

/* 221 */
		{
			229, 139, 255, 0
		},

/* 222 */
		{
			255, 139, 255, 0
		},

/* 223 */
		{
			0, 171, 255, 0
		},

/* 224 */
		{
			63, 171, 255, 0
		},

/* 225 */
		{
			104, 171, 255, 0
		},

/* 226 */
		{
			139, 171, 255, 0
		},

/* 227 */
		{
			171, 171, 255, 0
		},

/* 228 */
		{
			200, 171, 255, 0
		},

/* 229 */
		{
			229, 171, 255, 0
		},

/* 230 */
		{
			255, 171, 255, 0
		},

/* 231 */
		{
			0, 200, 255, 0
		},

/* 232 */
		{
			63, 200, 255, 0
		},

/* 233 */
		{
			104, 200, 255, 0
		},

/* 234 */
		{
			139, 200, 255, 0
		},

/* 235 */
		{
			166, 202, 240, 0
		},

/* 236 - Changed to match default 9 */
		{
			200, 200, 255, 0
		},

/* 237 */
		{
			229, 200, 255, 0
		},

/* 238 */
		{
			255, 200, 255, 0
		},

/* 239 */
		{
			0, 229, 255, 0
		},

/* 240 */
		{
			63, 229, 255, 0
		},

/* 241 */
		{
			104, 229, 255, 0
		},

/* 242 */
		{
			139, 229, 255, 0
		},

/* 243 */
		{
			171, 229, 255, 0
		},

/* 244 */
		{
			200, 229, 255, 0
		},

/* 245 */
		{
			229, 229, 255, 0
		},

/* 246 */
		{
			255, 251, 240, 0
		},

/* 247 - Changed to match default 10 */
		{
			0, 255, 255, 0
		},

/* 248 - Exact match with default 18 */
		{
			63, 255, 255, 0
		},

/* 249 */
		{
			104, 255, 255, 0
		},

/* 250 */
		{
			139, 255, 255, 0
		},

/* 251 */
		{
			171, 255, 255, 0
		},

/* 252 */
		{
			200, 255, 255, 0
		},

/* 253 */
		{
			229, 255, 255, 0
		},

/* 254 */
		{
			255, 255, 255, 0
		},

/* 255 - Exact match with default 19 */
	}
};
#endif

void CGLRenderer::CreateRGBPalette(HDC DC, PIXELFORMATDESCRIPTOR& pfd)
{
/*	LOGPALETTE* pPal;
	int n, i;
	BYTE byRedMask, byGreenMask, byBlueMask;
	if (pfd.dwFlags & PFD_NEED_PALETTE)
	{
#ifndef STATIC_PALETTE
		n = 1 << pfd.cColorBits;
		pPal = PLOGPALETTE(VirtualAlloc
			(
				nullptr,
				sizeof(LOGPALETTE) + n * sizeof(PALETTEENTRY),
				MEM_RESERVE | MEM_COMMIT,
				PAGE_READWRITE
			));
		if (!pPal)
			return;
		pPal->palVersion = 0x300;
		pPal->palNumEntries = n;
		byRedMask = (1 << pfd.cRedBits) - 1;
		byGreenMask = (1 << pfd.cGreenBits) - 1;
		byBlueMask = (1 << pfd.cBlueBits) - 1;
		for (i = 0; i < n; i++)
		{
			pPal->palPalEntry[i].peRed =
				(
					((i >> pfd.cRedShift) & byRedMask) *
					255
				) /
				byRedMask;
			pPal->palPalEntry[i].peGreen =
				(
					((i >> pfd.cGreenShift) & byGreenMask) *
					255
				) /
				byGreenMask;
			pPal->palPalEntry[i].peBlue =
				(
					((i >> pfd.cBlueShift) & byBlueMask) *
					255
				) /
				byBlueMask;
			pPal->palPalEntry[i].peFlags = 0;
		}

		//SetDIBColorTable(m_hMemDC, 0, n, pbi->bmiColors);
		HPALETTE hPal = CreatePalette(pPal);
		VirtualFree(pPal, 0, MEM_RELEASE);
#else
		HPALETTE	hPal = CreatePalette((LOGPALETTE *) &rgb8palette);
#endif
		SelectPalette(DC, hPal, FALSE);
		RealizePalette(DC);

		//SelectPalette(m_hMemDC, hPalOld, FALSE);
	}*/
}

int CGLRenderer::ChoosePixelFormatEx
(
	HDC hdc,
	int* pnColorBits,
	int* pnDepthBits,
	int* pnWantDoubleBuffer,
	int* pnWantAcceleration
)
{
/*	int nWishBytesPerPixel = pnColorBits ? *pnColorBits : -1;
	int nWishDepth = pnDepthBits ? *pnDepthBits : 16;
	int nWishDoubleBuffer = (pnWantDoubleBuffer) ? *pnWantDoubleBuffer : -1;
	int nWishAcceleration = (pnWantAcceleration) ? *pnWantAcceleration : 1;

	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(pfd));
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;

	int nPixelFormat = DescribePixelFormat(hdc, 1, sizeof(pfd), &pfd);
	if (nPixelFormat == 0)
		return 0;

	unsigned int maxqual = 0;
	int maxindex = 0;
	int max_bpp = 0;
	int max_depth = 0;
	int max_dbl = 0;
	int max_acc = 0;
	for (int i = 1; i <= nPixelFormat; i++)
	{
		ZeroMemory(&pfd, sizeof(pfd));
		pfd.nSize = sizeof(pfd);
		pfd.nVersion = 1;
		DescribePixelFormat(hdc, i, sizeof(pfd), &pfd);

		int bpp = pfd.cColorBits;
		int nDepthBits = pfd.cDepthBits;
		bool pal = (pfd.iPixelType == PFD_TYPE_COLORINDEX) != 0;
		bool mcd =
			(
				(pfd.dwFlags & PFD_GENERIC_FORMAT) != 0 &&
				(pfd.dwFlags & PFD_GENERIC_ACCELERATED) != 0
			);
		bool soft =
			(
				(pfd.dwFlags & PFD_GENERIC_FORMAT) != 0 &&
				!(pfd.dwFlags & PFD_GENERIC_ACCELERATED) != 0
			);
		bool icd =
			(
				!(pfd.dwFlags & PFD_GENERIC_FORMAT) != 0 &&
				!(pfd.dwFlags & PFD_GENERIC_ACCELERATED) != 0
			);
		bool bSupportOpenGL =
			(pfd.dwFlags & PFD_SUPPORT_OPENGL) != 0;
		bool bDrawToWindow = (pfd.dwFlags & PFD_DRAW_TO_WINDOW) != 0;
		bool bDrawToBitmap = (pfd.dwFlags & PFD_DRAW_TO_BITMAP) != 0;
		bool bDoubleBuffer = (pfd.dwFlags & PFD_DOUBLEBUFFER) != 0;

		//
		unsigned int q = 0;
		if (bSupportOpenGL && bDrawToWindow)
			q |= 0x8000;
		if (nWishDepth == -1 || (nWishDepth > 0 && nDepthBits > 0))
			q |= 0x4000;
		if
		(
			nWishDoubleBuffer == -1 ||
			(nWishDoubleBuffer == 0 && !bDoubleBuffer) ||
			(nWishDoubleBuffer == 1 && bDoubleBuffer)
		)
			q |= 0x2000;
		if
		(
			nWishAcceleration == -1 ||
			(nWishAcceleration == 0 && soft) ||
			(nWishAcceleration == 1 && (mcd || icd))
		)
			q |= 0x1000;
		if (mcd || icd)
			q |= 0x0040;
		if (icd)
			q |= 0x0002;
		if (nWishBytesPerPixel == -1 || (nWishBytesPerPixel == bpp))
			q |= 0x0800;
		if (bpp >= 16)
			q |= 0x0020;
		if (bpp == 16)
			q |= 0x0008;
		if (nWishDepth == -1 || (nWishDepth == nDepthBits))
			q |= 0x0400;
		if (nDepthBits >= 16)
			q |= 0x0010;
		if (nDepthBits == 16)
			q |= 0x0004;
		if (!pal)
			q |= 0x0080;
		if (bDrawToBitmap)
			q |= 0x0001;
		if (q > maxqual)
		{
			maxqual = q;
			maxindex = i;
			max_bpp = bpp;
			max_depth = nDepthBits;
			max_dbl = bDoubleBuffer ? 1 : 0;
			max_acc = soft ? 0 : 1;
		}
	}

	if (maxindex == 0)
		return maxindex;
	if (pnColorBits != nullptr)
		*pnColorBits = max_bpp;
	if (pnDepthBits != nullptr)
		*pnDepthBits = max_depth;
	if (pnWantDoubleBuffer != nullptr)
		*pnWantDoubleBuffer = max_dbl;
	if (pnWantAcceleration != nullptr)
		*pnWantAcceleration = max_acc;
	return maxindex;*/
	return 0;
}

bool CGLRenderer::bSetupPixelFormat(DWORD dwFlags, bool Soft)
{
/*	byte s_bpp = byte(GetDeviceCaps(m_hMemDC, BITSPIXEL));
	int pixelformat;
	PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR),
			1,
			dwFlags,
			PFD_TYPE_RGBA,
			s_bpp,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			32, // 16-bit depth buffer
			0, // no stencil buffer
			0, // no aux buffers
			PFD_MAIN_PLANE, // main layer
			0,
			0,
			0,
			0
		};
	pfd.cColorBits = GetDeviceCaps(m_hMemDC, PLANES) * GetDeviceCaps
		(
			m_hMemDC,
			BITSPIXEL
		);

	//   pfd.cAccumBits=pfd.cColorBits;
#if 0
	pixelformat = ChoosePixelFormat(m_hMemDC, &pfd);
#else
	int bpp = -1; // don't care. (or a positive integer)
	int depth = -1; // don't care. (or a positive integer)
	int dbl = 1; // we want dbl-buffer. (or -1 for 'don't care', 0 for 'none')
	int acc = Soft ? 0 : -1; // we want acceleration. (or -1 or 0)
	pixelformat = ChoosePixelFormatEx(m_hMemDC, &bpp, &depth, &dbl, &acc);
#endif
	if (pixelformat == 0)
	{
		::MessageBox(nullptr, _T("ChoosePixelFormat failed"), _T("Error"), MB_OK);
		return FALSE;
	}

	DescribePixelFormat(m_hMemDC, pixelformat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
	if (SetPixelFormat(m_hMemDC, pixelformat, &pfd) == FALSE)
	{
		::MessageBox(nullptr, _T("SetPixelFormat failed"), _T("Error"), MB_OK);
		return FALSE;
	}

	if (pfd.dwFlags & PFD_NEED_PALETTE)
		CreateRGBPalette(m_hMemDC, pfd);*/

	return TRUE;
}

#ifndef __WXMSW__
#define S_OK 0
#endif


HRESULT CGLRenderer::ReleaseWindow(void)
{
	//wglMakeCurrent(nullptr, nullptr);
/*	if (m_hMemDC)
		::ReleaseDC(m_hWnd, m_hMemDC);
	if (m_hMemRC)
		wglDeleteContext(m_hMemRC);*/
	ReleaseAllFonts();
	return S_OK;
}

HRESULT CGLRenderer::BindWindow(HWND hBindWnd, bool bSoftOGL, const SLogFont arrLogFonts[])
{
	m_hWnd = hBindWnd;
	return BindDc(/*::GetDC(m_hWnd)*/NULL, bSoftOGL);
}

HRESULT CGLRenderer::BindDc(HDC hDc, bool bSoftOGL)
{
/*	m_hMemDC = hDc;
	if
	(
		!bSetupPixelFormat
		(
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
			                  bSoftOGL
		)
	)
		return E_FAIL;
	m_hMemRC = wglCreateContext(m_hMemDC);
	if (m_hMemRC == nullptr)
	{
		if (!bSoftOGL)
		{
			if
			(
				!bSetupPixelFormat
				(
					PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
					                  false
				)
			)
				return E_FAIL;
			m_hMemRC = wglCreateContext(m_hMemDC);
			if (m_hMemRC == nullptr)
			{
				::MessageBox(nullptr,_T("3D Graphics is not initialized"),_T(""),MB_OK);
				return E_FAIL;
			}
		}

		return E_FAIL;
	}
	if (wglMakeCurrent(m_hMemDC, m_hMemRC) == false)
	{
		::MessageBox(nullptr,_T("Could not MakeCurrent"),_T(""),MB_OK);
		return E_FAIL;
	}*/
	BuildAllFonts(m_arrLogFonts);
	return S_OK;
}


bool CGLRenderer::SetDCPixelFormat(HDC hDC, DWORD dwFlags)
{
/*	PIXELFORMATDESCRIPTOR pixelDesc;

	pixelDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelDesc.nVersion = 1;

	pixelDesc.dwFlags = dwFlags;
	pixelDesc.iPixelType = PFD_TYPE_RGBA;
	pixelDesc.cColorBits = 24;
	pixelDesc.cRedBits = 8;
	pixelDesc.cRedShift = 16;
	pixelDesc.cGreenBits = 8;
	pixelDesc.cGreenShift = 8;
	pixelDesc.cBlueBits = 8;
	pixelDesc.cBlueShift = 0;
	pixelDesc.cAlphaBits = 0;
	pixelDesc.cAlphaShift = 0;
	pixelDesc.cAccumBits = 64;
	pixelDesc.cAccumRedBits = 16;
	pixelDesc.cAccumGreenBits = 16;
	pixelDesc.cAccumBlueBits = 16;
	pixelDesc.cAccumAlphaBits = 0;
	pixelDesc.cDepthBits = 32;
	pixelDesc.cStencilBits = 8;
	pixelDesc.cAuxBuffers = 0;
	pixelDesc.iLayerType = PFD_MAIN_PLANE;
	pixelDesc.bReserved = 0;
	pixelDesc.dwLayerMask = 0;
	pixelDesc.dwVisibleMask = 0;
	pixelDesc.dwDamageMask = 0;

	int nPixelIndex = ::ChoosePixelFormat(hDC, &pixelDesc);
	if (nPixelIndex == 0) // Choose default
	{
		nPixelIndex = 1;
		if (::DescribePixelFormat(hDC, nPixelIndex,
		                          sizeof(PIXELFORMATDESCRIPTOR), &pixelDesc) == 0)
			return false;
	}

	if (!::SetPixelFormat(hDC, nPixelIndex, &pixelDesc))
		return false;*/

	return true;
}
#ifndef __WXMSW__
typedef const char * LPCSTR;
typedef long LONG;
#endif

CString CGLRenderer::GetRenderString()
{
	CString str;
	str += LPCSTR(glGetString(GL_RENDERER));
	str += _T(" ");
	str += LPCSTR(glGetString(GL_VENDOR));
	str += _T(" ");
	str += LPCSTR(glGetString(GL_VERSION));
	return str;
}


void CGLRenderer::BuildFont(ESvFont fontNo, const LOGFONT* pLogFont)
{
	const char *szFile = "LiberationMono-BoldItalic.ttf";

	m_fonts[fontNo]= new FTGLPolygonFont(szFile);

	if (fontNo==SVF_VALUES || fontNo == SVF_RUS)
	{
		m_fonts[fontNo]->FaceSize(16);
	}
	else
		m_fonts[fontNo]->FaceSize(10);
		
/*	//char *pLocale = setlocale(LC_ALL, "");
	if (m_fontBases[fontNo])
		ReleaseFont(fontNo);
	m_fontBases[fontNo] = glGenLists(256); // Storage For 256 Characters

	m_fontSizes[fontNo] = (fontNo == SVF_AXES) ? -15.0f * 5 : -20.0f;// float(-pLogFont->lfHeight); //15*fScale;
	glColor3b(0, 0, 0);
	//m_fonts[fontNo] = CreateFontIndirect(pLogFont);
	m_fonts[fontNo] = CreateFont(int(m_fontSizes[fontNo]), // Height Of Font
	                             (fontNo == SVF_AXES) ? 0 : LONG((-m_fontSizes[fontNo]) / 3.5), // Width Of Font
	                             0, // Angle Of Escapement
	                             0, // Orientation Angle
	                             400, // Font Weight
	                             FALSE, // Italic
	                             FALSE, // Underline
	                             FALSE, // Strikeout
	                             RUSSIAN_CHARSET, // Character Set Identifier
	                             OUT_DEFAULT_PRECIS, // Output Precision
	                             CLIP_DEFAULT_PRECIS, // Clipping Precision
	                             PROOF_QUALITY, // Output Quality
	                             FF_DONTCARE | DEFAULT_PITCH, // Family And Pitch
	                             _T("Tahoma")); // Font Name

	HGDIOBJ old = ::SelectObject(m_hMemDC, m_fonts[fontNo]); // Selects The Font We Created
	if (fontNo == SVF_AXES)

	wglUseFontOutlines(m_hMemDC, // Select The Current DC
	                   0, // Starting Character
	                   256, // Number Of Display Lists To Build
	                   m_fontBases[fontNo], // Starting Display Lists
	                   0.0f, // Deviation From The True Outlines
	                   0.0f, // Font Thickness In The Z Direction
	                   WGL_FONT_POLYGONS, // Use Polygons, Not Lines
	                   m_gmfs[fontNo]); // Address Of Buffer To Recieve Data
	else
	{
		if (fontNo == SVF_RUS)
		wglUseFontBitmaps(m_hMemDC, 0x400, 256, m_fontBases[fontNo]);
		else
		wglUseFontBitmaps(m_hMemDC, 0, 256, m_fontBases[fontNo]);
	}
	::SelectObject(m_hMemDC, old);*/
}

void CGLRenderer::ReleaseFont(ESvFont fontNo)
{
	delete m_fonts[fontNo];
	glDeleteLists(m_fontBases[fontNo], 256); // Delete All 256 Characters
	m_fontBases[fontNo] = 0;
	//::DeleteObject(m_fonts[fontNo]);
	m_fonts[fontNo] = nullptr;
}

CSize CGLRenderer::GetFontExtent(ESvFont fontNo, LPCTSTR pszText, TEXTMETRIC* ptm)
{
	FTBBox box = m_fonts[fontNo]->BBox(pszText);
	return CSize(box.Upper().X()-box.Lower().X(), box.Upper().Y()-box.Lower().Y());
//	CSize sz(0, 0);
//	if (fontNo == SVF_AXES)
//	{
//		LPCTSTR p = pszText;
////		for (; *p; p++)
////		{
////			sz.x += LONG(m_gmfs[fontNo][*p].gmfCellIncX * -m_fontSizes[fontNo]);
////		}
////		sz.y = LONG(m_gmfs[fontNo][48].gmfBlackBoxY * -m_fontSizes[fontNo]);
//	}
//	else
//	{
//		//HGDIOBJ old = ::SelectObject(m_hMemDC, m_fonts[fontNo]); // Selects The Font We Created
//#ifdef _WXMSW_
//		SIZE sz1;
//		::GetTextExtentPoint(m_hMemDC, pszText, int(_tcslen(pszText)), &sz1);
//		sz.x = sz1.cx; sz.y = sz1.cy;
//
//#endif // !_WX_MS
//		//if (ptm) GetTextMetrics(m_hMemDC, ptm);
//		//::SelectObject(m_hMemDC, old);
//	}
//	return sz;
}

void CGLRenderer::BuildAllFonts(const SLogFont arrLogFonts[], float fScale)
{
	if (arrLogFonts != nullptr)
	{
		memcpy(m_arrLogFonts, arrLogFonts, sizeof(m_arrLogFonts));
	}
	for (int i = 0; i < SVF_SIZE; i++)
	{
		m_arrLogFonts[i].lfHeight = long(m_arrLogFonts[i].lfHeight * fScale);
		BuildFont(ESvFont(i), m_arrLogFonts + i);
	}
}

void CGLRenderer::ReleaseAllFonts()
{
	for (int i = 0; i < SVF_SIZE; i++)
		ReleaseFont(ESvFont(i));
}

void CGLRenderer::DrawText(LPCTSTR txt, ESvFont fontNo )
{
/*	glPushAttrib(GL_LIST_BIT); // Pushes The Display List Bits
	glListBase(m_fontBases[SVF_AXES]); // Sets The Base Character to 0
	glCallLists(wcslen(txt), GL_UNSIGNED_SHORT, LPCTSTR(txt)); // Draws The Display List Text
	glPopAttrib(); // Pops The Display List Bits*/
	m_fonts[fontNo]->Render(txt, wcslen(txt));
}

float CGLRenderer::GetFontSize(ESvFont fontNo)
{
	return 14;//m_fontSizes[fontNo];
}
