/**************************************************************
 *  Create by Coolnaut, All Rights Reserved.
 *  Description:
 *
 *  @author: https://github.com/coolnaut
 *  @time:
 **************************************************************/
#pragma once

#define __DS_DEBUG 1

// log
#ifdef __DS_DEBUG
#define DSLog(format, ...) printf("[%s:%d->%s] "format, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#else
#define DSLog(format, ...)
#endif
