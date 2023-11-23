/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MATLAB0.h
 *
 * Code generated for Simulink model 'MATLAB0'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 23 19:46:52 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MATLAB0_h_
#define RTW_HEADER_MATLAB0_h_
#include <math.h>
#include <string.h>
#ifndef MATLAB0_COMMON_INCLUDES_
# define MATLAB0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* MATLAB0_COMMON_INCLUDES_ */

#include "MATLAB0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T hat_x[2];                   /* '<Root>/MATLAB Function7' */
  real32_T hat_param[5];               /* '<Root>/MATLAB Function7' */
  real32_T P_hat_x[4];                 /* '<Root>/MATLAB Function7' */
  real32_T P_hat_param[25];            /* '<Root>/MATLAB Function7' */
  real32_T difx_difparam[10];          /* '<Root>/MATLAB Function7' */
  real32_T K_xk_1[4];                  /* '<Root>/MATLAB Function7' */
  real32_T difH_difparam[10];          /* '<Root>/MATLAB Function7' */
  boolean_T hat_x_not_empty;           /* '<Root>/MATLAB Function7' */
} DW_MATLAB0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T igamma;                       /* '<Root>/igamma' */
  real_T idelta;                       /* '<Root>/idelta' */
  real_T ugamma;                       /* '<Root>/ugamma' */
  real_T udelta;                       /* '<Root>/udelta' */
  real_T we0;                          /* '<Root>/we0' */
  real_T weh;                          /* '<Root>/weh' */
  real_T DEKF_R;                       /* '<Root>/DEKF_R' */
  real_T DEKF_Qx;                      /* '<Root>/DEKF_Qx' */
  real_T DEKF_QpRs;                    /* '<Root>/DEKF_QpRs' */
  real_T DEKF_QpNdd;                   /* '<Root>/DEKF_QpNdd' */
  real_T DEKF_QpNdq;                   /* '<Root>/DEKF_QpNdq' */
  real_T DEKF_QpNqq;                   /* '<Root>/DEKF_QpNqq' */
  real_T DEKF_PSI;                     /* '<Root>/DEKF_PSI' */
  real_T DEKF_CLEAR;                   /* '<Root>/DEKF_CLEAR' */
} ExtU_MATLAB0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T RsOut;                      /* '<Root>/RsOut' */
  real32_T LdOut;                      /* '<Root>/LdOut' */
  real32_T LqOut;                      /* '<Root>/LqOut' */
  real32_T PsidmOut;                   /* '<Root>/PsidmOut' */
} ExtY_MATLAB0_T;

/* Real-time Model Data Structure */
struct tag_RTM_MATLAB0_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_MATLAB0_T MATLAB0_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_MATLAB0_T MATLAB0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_MATLAB0_T MATLAB0_Y;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real32_T INITV_RS;              /* '<Root>/_DataStoreBlk_1' */
extern real32_T INITV_NDD;             /* '<Root>/_DataStoreBlk_2' */
extern real32_T INITV_NDQ;             /* '<Root>/_DataStoreBlk_3' */
extern real32_T INITV_NQQ;             /* '<Root>/_DataStoreBlk_4' */
extern real32_T INITV_PSI;             /* '<Root>/_DataStoreBlk_5' */

/* Model entry point functions */
extern void MATLAB0_initialize(void);
extern void MATLAB0_step(void);
extern void MATLAB0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MATLAB0_T *const MATLAB0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('MultiParamEst/MATLAB Function7')    - opens subsystem MultiParamEst/MATLAB Function7
 * hilite_system('MultiParamEst/MATLAB Function7/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MultiParamEst'
 * '<S1>'   : 'MultiParamEst/MATLAB Function7'
 */
#endif                                 /* RTW_HEADER_MATLAB0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
