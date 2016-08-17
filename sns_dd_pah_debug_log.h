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
* when       who       what, where, why
* ---------- ---       -----------------------------------------------------------
* 2016-04-12 bell      Add license information and revision information
* 2016-04-07 bell      Initial revision.
==============================================================================*/

#ifndef __sns_dd_debug_log_h__
#define __sns_dd_debug_log_h__


/*============================================================================
debug log
============================================================================*/
// Enable the following macro to see debug out 
#define DD_VENDOR_DEBUG

#if defined(DD_VENDOR_DEBUG)

#   include "qurt_elite_diag.h" /* for mini-dm debug */
#   define DBG_MEDIUM_PRIO DBG_MED_PRIO
#   define VENDOR_DD_MSG_0(level,msg)          MSG(MSG_SSID_QDSP6,DBG_##level##_PRIO, " - " msg)
#   define VENDOR_DD_MSG_1(level,msg,p1)       MSG_1(MSG_SSID_QDSP6,DBG_##level##_PRIO, " - " msg,p1)
#   define VENDOR_DD_MSG_2(level,msg,p1,p2)    MSG_2(MSG_SSID_QDSP6,DBG_##level##_PRIO, " - " msg,p1,p2)
#   define VENDOR_DD_MSG_3(level,msg,p1,p2,p3) MSG_3(MSG_SSID_QDSP6,DBG_##level##_PRIO, " - " msg,p1,p2,p3)
#   define VENDOR_DD_MSG_4(level,msg,p1,p2,p3,p4) MSG_4(MSG_SSID_QDSP6,DBG_##level##_PRIO, " - " msg,p1,p2,p3,p4)
// LOW      => white
// MED      => teal
// HIGH     => yellow
// ERROR    => purple
// FATAL    => red

#else

#   define VENDOR_DD_MSG_0(level,msg)
#   define VENDOR_DD_MSG_1(level,msg,p1)
#   define VENDOR_DD_MSG_2(level,msg,p1,p2)
#   define VENDOR_DD_MSG_3(level,msg,p1,p2,p3)
#   define VENDOR_DD_MSG_4(level,msg,p1,p2,p3,p4)

#endif  // DD_VENDOR_DEBUG


#   define debug_log(msg)                       VENDOR_DD_MSG_0(ERROR, msg)
#   define debug_log_1(msg, p1)                 VENDOR_DD_MSG_1(ERROR, msg, p1)
#   define debug_log_2(msg, p1, p2)             VENDOR_DD_MSG_2(ERROR, msg, p1, p2)
#   define debug_log_3(msg, p1, p2, p3)         VENDOR_DD_MSG_3(ERROR, msg, p1, p2, p3)
#   define debug_log_4(msg, p1, p2, p3, p4)     VENDOR_DD_MSG_4(ERROR, msg, p1, p2, p3, p4)

#   define debug_printf(msg)                    VENDOR_DD_MSG_0(ERROR, msg)
#   define debug_printf_1(msg, p1)              VENDOR_DD_MSG_1(ERROR, msg, p1)
#   define debug_printf_2(msg, p1, p2)          VENDOR_DD_MSG_2(ERROR, msg, p1, p2)
#   define debug_printf_3(msg, p1, p2, p3)      VENDOR_DD_MSG_3(ERROR, msg, p1, p2, p3)
#   define debug_printf_4(msg, p1, p2, p3, p4)  VENDOR_DD_MSG_4(ERROR, msg, p1, p2, p3, p4)

#endif /* End include guard  __DD_VENDOR_DEBUG_H__ */

