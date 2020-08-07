/*
 *  lzw.h - LZW decompression from memory to memory
 *
 *  Copyright (C) 2002  Marc Winterrowd
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef LZW_H
#define LZW_H

long lzw_get_decompressed_size(unsigned char* compressed_mem, long compressed_size);
long lzw_decompress(unsigned char* compressed_mem, unsigned char* decompressed_mem, long compressed_size);

#endif /* LZW_H */
