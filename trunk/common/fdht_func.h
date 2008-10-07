/**
* Copyright (C) 2008 Happy Fish / YuQing
*
* FastDFS may be copied only under the terms of the GNU General
* Public License V3, which may be found in the FastDFS source kit.
* Please visit the FastDFS Home Page http://www.csource.org/ for more detail.
**/

//fdht_func.h

#ifndef _FDHT_FUNC_H_
#define _FDHT_FUNC_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

int load_group_ids(IniItemInfo *items, const int nItemCount, \
		const char *item_name, int **group_ids, int *group_count);

int fdht_load_groups(IniItemInfo *items, const int nItemCount, \
		GroupArray *pGroupArray);

#ifdef __cplusplus
}
#endif

#endif
