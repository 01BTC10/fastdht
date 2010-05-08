/**
* Copyright (C) 2008 Happy Fish / YuQing
*
* FastDFS may be copied only under the terms of the GNU General
* Public License V3, which may be found in the FastDFS source kit.
* Please visit the FastDFS Home Page http://www.csource.org/ for more detail.
**/

//base64.h

#ifndef _BASE64_H
#define _BASE64_H

#include "common_define.h"

struct base64_context
{
	char line_separator[16];
	int line_sep_len;

	/**
	 * max chars per line, excluding line_separator.  A multiple of 4.
	 */
	int line_length;

	/**
	 * letter of the alphabet used to encode binary values 0..63
	 */
	unsigned char valueToChar[64];

	/**
	 * binary value encoded by a given letter of the alphabet 0..63
	 */
	int charToValue[256];
	int pad_ch;
};

#ifdef __cplusplus
extern "C" {
#endif

#define base64_init(context, nLineLength) \
        base64_init_ex(context, nLineLength, '+', '/', '=')
#define base64_encode(context, src, nSrcLen, dest, dest_len) \
        base64_encode_ex(context, src, nSrcLen, dest, dest_len, true)

void base64_init_ex(struct base64_context *context, const int nLineLength, \
		const unsigned char chPlus, const unsigned char chSplash, \
		const unsigned char chPad);

int base64_get_encode_length(struct base64_context *context, const int nSrcLen);

char *base64_encode_ex(struct base64_context *context, char *src, \
		const int nSrcLen, char *dest, int *dest_len, const bool bPad);
char *base64_decode(struct base64_context *context, char *src, \
		const int nSrcLen, char *dest, int *dest_len);
char *base64_decode_auto(struct base64_context *context, char *src, \
		const int nSrcLen, char *dest, int *dest_len);

void base64_set_line_separator(struct base64_context *context, \
		const char *pLineSeparator);
void base64_set_line_length(struct base64_context *context, const int length);

#ifdef __cplusplus
}
#endif

#endif


