/*
 * Copyright (c) 2020, NVIDIA CORPORATION. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef __CUDA_DRAW_H__
#define __CUDA_DRAW_H__


#include "cudaUtility.h"
#include "imageFormat.h"


// TODO for rect/fill/line
//    - make versions that only accept image (as both input/output)
//    - add line width/line color
//    - add overloads for single shape/multiple shapes
//    - benchmarking of copy vs alternate kernel when input != output
//    - overloads using int2 for coordinates
//    - add a template parameter for alpha blending


/**
 * cudaDrawCircle
 * @ingroup drawing
 */
cudaError_t cudaDrawCircle( void* input, void* output, size_t width, size_t height, imageFormat format, 
					   int cx, int cy, float radius, const float4& color );
	
/**
 * cudaDrawCircle
 * @ingroup drawing
 */
template<typename T> 
cudaError_t cudaDrawCircle( T* input, T* output, size_t width, size_t height, 
				 	   int cx, int cy, float radius, const float4& color )	
{ 
	return cudaDrawCircle(input, output, width, height, imageFormatFromType<T>(), cx, cy, radius, color); 
}	


/**
 * cudaDrawLine
 * @ingroup drawing
 */
cudaError_t cudaDrawLine( void* input, void* output, size_t width, size_t height, imageFormat format, 
					 int x1, int y1, int x2, int y2, const float4& color, float line_width=1.0 );
	
/**
 * cudaDrawLine
 * @ingroup drawing
 */
template<typename T> 
cudaError_t cudaDrawLine( T* input, T* output, size_t width, size_t height, 
				 	 int x1, int y1, int x2, int y2, const float4& color, float line_width=1.0 )	
{ 
	return cudaDrawLine(input, output, width, height, imageFormatFromType<T>(), x1, y1, x2, y2, color, line_width); 
}	

#endif

