/********************************************************************************
* Copyright (c) 2016, PixArt Imaging Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
* 3. Neither the name of the PixArt Imaging Inc. nor the
* names of its contributors may be used to endorse or promote products
* derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/*==============================================================================
* Edit History
*
* This section contains comments describing changes made to the module. Notice
* that changes are listed in reverse chronological order. Please use ISO format
* for dates.
*
* when        version  who       what, where, why
* ----------  ------   ---       -----------------------------------------------------------
* 2016-04-07           bell      Initial revision.
==============================================================================*/

#ifndef __sns_dd_pah_api_8011_h__
#define __sns_dd_pah_api_8011_h__

#include "fixed_point.h"
#include "sns_ddf_util.h"
#include "sns_ddf_attrib.h"
#include "sns_ddf_common.h"
#include "sns_ddf_comm.h"
#include "sns_ddf_driver_if.h"
#include "sns_ddf_smgr_if.h"
#include "sns_ddf_memhandler.h"
#include "sns_ddf_signal.h"



sns_ddf_status_e sns_dd_pah_init(
  sns_ddf_handle_t*        dd_handle_ptr,
  sns_ddf_handle_t         smgr_handle,
  sns_ddf_nv_params_s*     nv_params,
  sns_ddf_device_access_s  device_info[],
  uint32_t                 num_devices,
  sns_ddf_memhandler_s*    memhandler,
  sns_ddf_sensor_e*        sensors[],
  uint32_t*                num_sensors
  );

sns_ddf_status_e sns_dd_pah_get_data(
  sns_ddf_handle_t        dd_handle,
  sns_ddf_sensor_e        sensors[],
  uint32_t                num_sensors,
  sns_ddf_memhandler_s*   memhandler,
  sns_ddf_sensor_data_s*  data[] /* ignored by this async driver */
  );

sns_ddf_status_e sns_dd_pah_set_attrib(
  sns_ddf_handle_t     dd_handle,
  sns_ddf_sensor_e     sensor,
  sns_ddf_attribute_e  attrib,
  void*                value
  );

sns_ddf_status_e sns_dd_pah_get_attrib(
  sns_ddf_handle_t      dd_handle,
  sns_ddf_sensor_e      sensor,
  sns_ddf_attribute_e   attrib,
  sns_ddf_memhandler_s* memhandler,
  void**                value,
  uint32_t*             num_elems
  );

void sns_dd_pah_handle_timer(
  sns_ddf_handle_t  dd_handle,
  void*             arg
  );

void sns_dd_pah_handle_irq(
  sns_ddf_handle_t  dd_handle,
  uint32_t          gpio_num,
  sns_ddf_time_t    timestamp
  );

sns_ddf_status_e sns_dd_pah_reset(
  sns_ddf_handle_t dd_handle
  );

sns_ddf_status_e sns_dd_pah_enable_sched_data(
  sns_ddf_handle_t  handle,
  sns_ddf_sensor_e  sensor,
  bool              enable
  );

sns_ddf_status_e sns_dd_pah_run_test(
  sns_ddf_handle_t  dd_handle,
  sns_ddf_sensor_e  sensor,
  sns_ddf_test_e    test,
  uint32_t*         err
  );

sns_ddf_status_e sns_dd_pah_probe(
  sns_ddf_device_access_s* device_info,
  sns_ddf_memhandler_s*    memhandler,
  uint32_t*                num_sensors,
  sns_ddf_sensor_e**       sensors
  );

sns_ddf_status_e sns_dd_pah_trigger_fifo_data(
  sns_ddf_handle_t         dd_handle,
  sns_ddf_sensor_e         sensor,
  uint16_t                 num_samples,
  bool                     trigger_now
  );


#endif /* End include guard  _DD_VENDOR_1_H */

