/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "noise_suppression.h"

#include <stdlib.h>
#include <string.h>

#include "signal_processing_library.h"
#include "defines.h"
#include "ns_core.h"
/*******************/
/*
/*创建WebRTV降噪处理句柄
/*
/***************************/
int WebRtcNs_Create(NsHandle** NS_inst) {
  *NS_inst = (NsHandle*) malloc(sizeof(NSinst_t));
  if (*NS_inst != NULL) {
    (*(NSinst_t**)NS_inst)->initFlag = 0;
    return 0;
  } else {
    return -1;
  }

}
// 
int WebRtcNs_Free(NsHandle* NS_inst) {
  free(NS_inst);
  return 0;
}

//初始化WebRtc降噪处理句柄
int WebRtcNs_Init(NsHandle* NS_inst, uint32_t fs) {
  return WebRtcNs_InitCore((NSinst_t*) NS_inst, fs);
}

//设置WebRTC降噪处理策略
int WebRtcNs_set_policy(NsHandle* NS_inst, int mode) {
  return WebRtcNs_set_policy_core((NSinst_t*) NS_inst, mode);
}

//降噪处理
int WebRtcNs_Process(NsHandle* NS_inst, short* spframe, short* spframe_H,
                     short* outframe, short* outframe_H) {
  return WebRtcNs_ProcessCore(
      (NSinst_t*) NS_inst, spframe, spframe_H, outframe, outframe_H);
}

float WebRtcNs_prior_speech_probability(NsHandle* handle) {
  NSinst_t* self = (NSinst_t*) handle;
  if (handle == NULL) {
    return -1;
  }
  if (self->initFlag == 0) {
    return -1;
  }
  return self->priorSpeechProb;
}
