//
//  device.h
//  md-util
//
//  Created by staturnz on 3/10/23.
//

#ifndef device_h
#define device_h

#include <stdio.h>
#include <Foundation/Foundation.h>
#include "mobiledevice.h"

#define DEVICE_DEFAULT_TIMEOUT 1

#define ASSERT_OR_EXIT(_cnd_, ...)       \
  do                                     \
  {                                      \
    if (!(_cnd_))                        \
    {                                    \
      fprintf(stderr, __VA_ARGS__);      \
      device_unregister();              \
    }                                    \
  } while (0)

extern int device_delayed_unregister_status;
extern bool device_delayed_unregister_aborted;
extern void device_register(void (*func)(struct am_device *), int64_t timeout);
extern void device_unregister(int status);
extern void device_connect(struct am_device *device);
extern NSString* device_udid(struct am_device *device);
extern bool device_matches(struct am_device *device, const char *udid);
bool md_register(void);
extern NSMutableDictionary *device_info;
void md_unregister(void);
void md_enter_rec(void);
static void on_recovery_connected(struct am_recovery_device *device);
void md_fetch_info(void);
void md_exit_rec(void);
uint md_send_cmd(CFStringRef cmd);
void test_cmd(void);

extern struct am_device *current_device ;
extern struct am_recovery_device *current_rec_device;

#endif /* device_h */
