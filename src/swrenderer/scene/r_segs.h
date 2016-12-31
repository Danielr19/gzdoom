// Emacs style mode select	 -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// DESCRIPTION:
//		Refresh module, drawing LineSegs from BSP.
//
//-----------------------------------------------------------------------------


#ifndef __R_SEGS_H__
#define __R_SEGS_H__

namespace swrenderer
{

struct drawseg_t;

bool R_StoreWallRange(int start, int stop);
void R_RenderMaskedSegRange (drawseg_t *ds, int x1, int x2);

int R_CreateWallSegmentY (short *outbuf, double z1, double z2, const FWallCoords *wallc);
int R_CreateWallSegmentYSloped (short *outbuf, const secplane_t &plane, const FWallCoords *wallc);
inline int R_CreateWallSegmentY(short *outbuf, double z, const FWallCoords *wallc)
{
	return R_CreateWallSegmentY(outbuf, z, z, wallc);
}

void PrepWall (float *swall, fixed_t *lwall, double walxrepeat, int x1, int x2);
void PrepLWall (fixed_t *lwall, double walxrepeat, int x1, int x2);

void R_RenderSegLoop ();

extern short	walltop[MAXWIDTH];	// [RH] record max extents of wall
extern short	wallbottom[MAXWIDTH];
extern short	wallupper[MAXWIDTH];
extern short	walllower[MAXWIDTH];
extern float	swall[MAXWIDTH];
extern fixed_t	lwall[MAXWIDTH];
extern double	lwallscale;
extern float	rw_light;		// [RH] Scale lights with viewsize adjustments
extern float	rw_lightstep;
extern float	rw_lightleft;
extern fixed_t	rw_offset;
extern FTexture *rw_pic;

}

#endif
