/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MATLAB0.c
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

#include "MATLAB0.h"
#include "MATLAB0_private.h"

/* Exported block states */
real32_T INITV_RS;                     /* '<Root>/_DataStoreBlk_1' */
real32_T INITV_NDD;                    /* '<Root>/_DataStoreBlk_2' */
real32_T INITV_NDQ;                    /* '<Root>/_DataStoreBlk_3' */
real32_T INITV_NQQ;                    /* '<Root>/_DataStoreBlk_4' */
real32_T INITV_PSI;                    /* '<Root>/_DataStoreBlk_5' */

/* Block states (default storage) */
DW_MATLAB0_T MATLAB0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_MATLAB0_T MATLAB0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_MATLAB0_T MATLAB0_Y;

/* Real-time model */
RT_MODEL_MATLAB0_T MATLAB0_M_;
RT_MODEL_MATLAB0_T *const MATLAB0_M = &MATLAB0_M_;

/* Forward declaration for local functions */
static void MATLAB0_mpower(const real32_T a[4], real32_T c[4]);

/* Function for MATLAB Function: '<Root>/MATLAB Function7' */
static void MATLAB0_mpower(const real32_T a[4], real32_T c[4])
{
  real32_T r;
  real32_T t;
  if (fabsf(a[1]) > fabsf(a[0])) {
    r = a[0] / a[1];
    t = 1.0F / (r * a[3] - a[2]);
    c[0] = a[3] / a[1] * t;
    c[1] = -t;
    c[2] = -a[2] / a[1] * t;
    c[3] = r * t;
  } else {
    r = a[1] / a[0];
    t = 1.0F / (a[3] - r * a[2]);
    c[0] = a[3] / a[0] * t;
    c[1] = -r * t;
    c[2] = -a[2] / a[0] * t;
    c[3] = t;
  }
}

/* Model step function */
void MATLAB0_step(void)
{
  real32_T R[4];
  real32_T P_param_PE[25];
  real_T we;
  real32_T N[4];
  real32_T A[4];
  real32_T tilde_theta;
  real32_T P_x_PE[4];
  real32_T K_xk[4];
  real32_T TempA;
  real32_T TempCOS;
  real32_T TempSIN;
  real32_T difG_difparam[10];
  real32_T K_pk[10];
  real_T d[25];
  real_T v[5];
  int8_T b_I[4];
  int32_T i;
  real32_T N_0[4];
  real32_T A_0[4];
  real32_T A_1[4];
  real32_T b_I_0[4];
  real32_T A_2[10];
  real32_T N_1[10];
  real32_T P_param_PE_0[10];
  real32_T d_0[25];
  real32_T x_PE_idx_0;
  real32_T x_PE_idx_1;
  real32_T A_tmp;
  int32_T N_tmp;
  int32_T K_xk_tmp_tmp;
  real32_T tilde_theta_tmp_tmp;
  int32_T K_pk_tmp_tmp;
  real32_T x_PE_tmp_tmp;

  /* MATLAB Function: '<Root>/MATLAB Function7' incorporates:
   *  Inport: '<Root>/DEKF_CLEAR'
   *  Inport: '<Root>/DEKF_PSI'
   *  Inport: '<Root>/DEKF_QpNdd'
   *  Inport: '<Root>/DEKF_QpNdq'
   *  Inport: '<Root>/DEKF_QpNqq'
   *  Inport: '<Root>/DEKF_QpRs'
   *  Inport: '<Root>/DEKF_Qx'
   *  Inport: '<Root>/DEKF_R'
   *  Inport: '<Root>/idelta'
   *  Inport: '<Root>/igamma'
   *  Inport: '<Root>/udelta'
   *  Inport: '<Root>/ugamma'
   *  Inport: '<Root>/we0'
   *  Inport: '<Root>/weh'
   */
  if (!MATLAB0_DW.hat_x_not_empty) {
    MATLAB0_DW.hat_x_not_empty = true;
    MATLAB0_DW.hat_param[0] = INITV_RS;
    MATLAB0_DW.hat_param[1] = INITV_NDD;
    MATLAB0_DW.hat_param[2] = INITV_NDQ;
    MATLAB0_DW.hat_param[3] = INITV_NQQ;
    MATLAB0_DW.hat_param[4] = INITV_PSI;
  }

  v[0] = MATLAB0_U.DEKF_QpRs;
  v[1] = MATLAB0_U.DEKF_QpNdd;
  v[2] = MATLAB0_U.DEKF_QpNdq;
  v[3] = MATLAB0_U.DEKF_QpNqq;
  v[4] = MATLAB0_U.DEKF_PSI;
  memset(&d[0], 0, 25U * sizeof(real_T));
  for (i = 0; i < 5; i++) {
    d[i + 5 * i] = v[i];
  }

  R[0] = (real32_T)MATLAB0_U.DEKF_R;
  R[2] = 0.0F;
  R[1] = 0.0F;
  R[3] = (real32_T)MATLAB0_U.DEKF_R;
  for (i = 0; i < 25; i++) {
    P_param_PE[i] = MATLAB0_DW.P_hat_param[i] + (real32_T)d[i];
  }

  we = MATLAB0_U.we0 + MATLAB0_U.weh;
  N[0] = MATLAB0_DW.hat_param[1];
  N[2] = MATLAB0_DW.hat_param[2];
  N[1] = MATLAB0_DW.hat_param[2];
  N[3] = MATLAB0_DW.hat_param[3];
  TempA = (real32_T)we * 0.0F;
  A[0] = MATLAB0_DW.hat_param[0] * MATLAB0_DW.hat_param[1] + TempA;
  A_tmp = MATLAB0_DW.hat_param[0] * MATLAB0_DW.hat_param[2];
  A[1] = A_tmp + (real32_T)we;
  A[2] = A_tmp + -(real32_T)we;
  A[3] = MATLAB0_DW.hat_param[0] * MATLAB0_DW.hat_param[3] + TempA;
  tilde_theta_tmp_tmp = MATLAB0_DW.hat_param[3] - MATLAB0_DW.hat_param[1];
  TempCOS = -2.0F * MATLAB0_DW.hat_param[2] / tilde_theta_tmp_tmp;
  tilde_theta = atanf(TempCOS) * 0.5F;
  x_PE_tmp_tmp = cosf(tilde_theta);
  tilde_theta = sinf(tilde_theta);
  x_PE_idx_0 = (((real32_T)MATLAB0_U.ugamma - (A[0] * MATLAB0_DW.hat_x[0] + A[2]
    * MATLAB0_DW.hat_x[1])) - (TempA * MATLAB0_DW.hat_param[4] * x_PE_tmp_tmp +
    -(real32_T)we * MATLAB0_DW.hat_param[4] * tilde_theta)) * 0.0001F +
    MATLAB0_DW.hat_x[0];
  TempSIN = (real32_T)we * MATLAB0_DW.hat_param[4];
  x_PE_idx_1 = (((real32_T)MATLAB0_U.udelta - (A[1] * MATLAB0_DW.hat_x[0] + A[3]
    * MATLAB0_DW.hat_x[1])) - (TempSIN * x_PE_tmp_tmp + TempA *
    MATLAB0_DW.hat_param[4] * tilde_theta)) * 0.0001F + MATLAB0_DW.hat_x[1];
  A[0] = 1.0F - A[0] * 0.0001F;
  A[1] = 0.0F - A[1] * 0.0001F;
  A[2] = 0.0F - A[2] * 0.0001F;
  A[3] = 1.0F - A[3] * 0.0001F;
  for (i = 0; i < 2; i++) {
    A_0[i] = 0.0F;
    A_0[i] += A[i] * MATLAB0_DW.P_hat_x[0];
    A_tmp = A[i + 2];
    A_0[i] += A_tmp * MATLAB0_DW.P_hat_x[1];
    A_0[i + 2] = 0.0F;
    A_0[i + 2] += A[i] * MATLAB0_DW.P_hat_x[2];
    A_0[i + 2] += A_tmp * MATLAB0_DW.P_hat_x[3];
    A_1[i] = 0.0F;
    A_1[i] += A_0[i] * A[0];
    A_1[i] += A_0[i + 2] * A[2];
    A_1[i + 2] = 0.0F;
    A_1[i + 2] += A_0[i] * A[1];
    A_1[i + 2] += A_0[i + 2] * A[3];
  }

  P_x_PE[0] = A_1[0] + (real32_T)MATLAB0_U.DEKF_Qx;
  P_x_PE[1] = A_1[1];
  P_x_PE[2] = A_1[2];
  P_x_PE[3] = A_1[3] + (real32_T)MATLAB0_U.DEKF_Qx;
  for (i = 0; i < 2; i++) {
    K_xk_tmp_tmp = i << 1;
    A_0[K_xk_tmp_tmp] = N[i];
    A_1[i] = 0.0F;
    A_1[i] += N[i] * P_x_PE[0];
    TempA = N[i + 2];
    A_1[i] += TempA * P_x_PE[1];
    A_0[K_xk_tmp_tmp + 1] = TempA;
    A_1[i + 2] = 0.0F;
    A_1[i + 2] += N[i] * P_x_PE[2];
    A_1[i + 2] += TempA * P_x_PE[3];
  }

  for (i = 0; i < 2; i++) {
    K_xk_tmp_tmp = i << 1;
    N_tmp = K_xk_tmp_tmp + 1;
    N_0[K_xk_tmp_tmp] = (A_0[N_tmp] * A_1[2] + A_0[K_xk_tmp_tmp] * A_1[0]) +
      R[K_xk_tmp_tmp];
    N_0[N_tmp] = (A_0[N_tmp] * A_1[3] + A_0[K_xk_tmp_tmp] * A_1[1]) + R[N_tmp];
  }

  MATLAB0_mpower(N_0, A_1);
  b_I[1] = 0;
  b_I[2] = 0;
  b_I[0] = 1;
  b_I[3] = 1;
  TempA = TempSIN / 2.0F / (TempCOS * TempCOS + 1.0F) / (tilde_theta_tmp_tmp *
    tilde_theta_tmp_tmp);
  TempCOS = TempA * x_PE_tmp_tmp;
  TempSIN = TempA * tilde_theta;
  for (i = 0; i < 2; i++) {
    N_0[i] = 0.0F;
    N_0[i] += P_x_PE[i] * A_0[0];
    TempA = P_x_PE[i + 2];
    N_0[i] += TempA * A_0[1];
    N_0[i + 2] = 0.0F;
    N_0[i + 2] += P_x_PE[i] * A_0[2];
    N_0[i + 2] += TempA * A_0[3];
    K_xk[i] = 0.0F;
    K_xk[i] += N_0[i] * A_1[0];
    K_xk[i] += N_0[i + 2] * A_1[1];
    K_xk[i + 2] = 0.0F;
    K_xk[i + 2] += N_0[i] * A_1[2];
    K_xk[i + 2] += N_0[i + 2] * A_1[3];
    b_I_0[i] = (real32_T)b_I[i] - (K_xk[i + 2] * N[1] + K_xk[i] * N[0]);
    b_I_0[i + 2] = (real32_T)b_I[i + 2] - (K_xk[i + 2] * N[3] + K_xk[i] * N[2]);
    MATLAB0_DW.P_hat_x[i] = 0.0F;
    MATLAB0_DW.P_hat_x[i] += b_I_0[i] * P_x_PE[0];
    TempA = b_I_0[i + 2];
    MATLAB0_DW.P_hat_x[i] += TempA * P_x_PE[1];
    MATLAB0_DW.P_hat_x[i + 2] = 0.0F;
    MATLAB0_DW.P_hat_x[i + 2] += b_I_0[i] * P_x_PE[2];
    MATLAB0_DW.P_hat_x[i + 2] += TempA * P_x_PE[3];
    for (K_xk_tmp_tmp = 0; K_xk_tmp_tmp < 5; K_xk_tmp_tmp++) {
      N_tmp = K_xk_tmp_tmp << 1;
      K_pk_tmp_tmp = N_tmp + i;
      P_param_PE_0[K_pk_tmp_tmp] = MATLAB0_DW.difx_difparam[K_pk_tmp_tmp] -
        (MATLAB0_DW.difH_difparam[N_tmp + 1] * MATLAB0_DW.K_xk_1[i + 2] +
         MATLAB0_DW.difH_difparam[N_tmp] * MATLAB0_DW.K_xk_1[i]);
    }
  }

  N_1[0] = (MATLAB0_DW.hat_param[1] * MATLAB0_DW.hat_x[0] +
            MATLAB0_DW.hat_param[2] * MATLAB0_DW.hat_x[1]) * -0.0001F;
  TempA = MATLAB0_DW.hat_param[0] * MATLAB0_DW.hat_x[0];
  N_1[2] = (TempA + -TempCOS) * -0.0001F;
  A_tmp = MATLAB0_DW.hat_param[0] * MATLAB0_DW.hat_x[1];
  N_1[4] = (TempCOS * 2.0F * tilde_theta_tmp_tmp + A_tmp) * -0.0001F;
  N_1[6] = -0.0001F * TempCOS;
  N_1[8] = (real32_T)-we * tilde_theta * -0.0001F;
  N_1[1] = (MATLAB0_DW.hat_param[2] * MATLAB0_DW.hat_x[0] +
            MATLAB0_DW.hat_param[3] * MATLAB0_DW.hat_x[1]) * -0.0001F;
  N_1[3] = -0.0001F * -TempSIN;
  N_1[5] = (TempSIN * 2.0F * tilde_theta_tmp_tmp + TempA) * -0.0001F;
  N_1[7] = (A_tmp + TempSIN) * -0.0001F;
  N_1[9] = (real32_T)we * x_PE_tmp_tmp * -0.0001F;
  for (i = 0; i < 5; i++) {
    K_xk_tmp_tmp = i << 1;
    A_2[K_xk_tmp_tmp] = 0.0F;
    A_2[K_xk_tmp_tmp] += P_param_PE_0[K_xk_tmp_tmp] * A[0];
    N_tmp = K_xk_tmp_tmp + 1;
    A_2[K_xk_tmp_tmp] += P_param_PE_0[N_tmp] * A[2];
    A_2[N_tmp] = 0.0F;
    A_2[N_tmp] += P_param_PE_0[K_xk_tmp_tmp] * A[1];
    A_2[N_tmp] += P_param_PE_0[N_tmp] * A[3];
  }

  for (i = 0; i < 10; i++) {
    difG_difparam[i] = N_1[i] + A_2[i];
  }

  P_param_PE_0[0] = 0.0F;
  P_param_PE_0[2] = MATLAB0_DW.hat_x[0];
  P_param_PE_0[4] = MATLAB0_DW.hat_x[1];
  P_param_PE_0[6] = 0.0F;
  P_param_PE_0[8] = 0.0F;
  P_param_PE_0[1] = 0.0F;
  P_param_PE_0[3] = 0.0F;
  P_param_PE_0[5] = MATLAB0_DW.hat_x[0];
  P_param_PE_0[7] = MATLAB0_DW.hat_x[1];
  P_param_PE_0[9] = 0.0F;
  for (i = 0; i < 5; i++) {
    K_xk_tmp_tmp = i << 1;
    N_1[K_xk_tmp_tmp] = 0.0F;
    N_1[K_xk_tmp_tmp] += difG_difparam[K_xk_tmp_tmp] * N[0];
    N_tmp = K_xk_tmp_tmp + 1;
    N_1[K_xk_tmp_tmp] += difG_difparam[N_tmp] * N[2];
    N_1[N_tmp] = 0.0F;
    N_1[N_tmp] += difG_difparam[K_xk_tmp_tmp] * N[1];
    N_1[N_tmp] += difG_difparam[N_tmp] * N[3];
  }

  for (i = 0; i < 10; i++) {
    MATLAB0_DW.difH_difparam[i] = P_param_PE_0[i] + N_1[i];
  }

  for (i = 0; i < 2; i++) {
    for (K_xk_tmp_tmp = 0; K_xk_tmp_tmp < 5; K_xk_tmp_tmp++) {
      K_pk_tmp_tmp = (K_xk_tmp_tmp << 1) + i;
      N_1[K_xk_tmp_tmp + 5 * i] = MATLAB0_DW.difH_difparam[K_pk_tmp_tmp];
      P_param_PE_0[K_pk_tmp_tmp] = 0.0F;
      for (N_tmp = 0; N_tmp < 5; N_tmp++) {
        P_param_PE_0[K_pk_tmp_tmp] += MATLAB0_DW.difH_difparam[(N_tmp << 1) + i]
          * P_param_PE[5 * K_xk_tmp_tmp + N_tmp];
      }
    }
  }

  for (i = 0; i < 2; i++) {
    for (K_xk_tmp_tmp = 0; K_xk_tmp_tmp < 2; K_xk_tmp_tmp++) {
      TempA = 0.0F;
      for (N_tmp = 0; N_tmp < 5; N_tmp++) {
        TempA += P_param_PE_0[(N_tmp << 1) + K_xk_tmp_tmp] * N_1[5 * i + N_tmp];
      }

      N_tmp = (i << 1) + K_xk_tmp_tmp;
      A_1[N_tmp] = R[N_tmp] + TempA;
    }
  }

  MATLAB0_mpower(A_1, N);
  for (i = 0; i < 5; i++) {
    for (K_xk_tmp_tmp = 0; K_xk_tmp_tmp < 2; K_xk_tmp_tmp++) {
      K_pk_tmp_tmp = i + 5 * K_xk_tmp_tmp;
      P_param_PE_0[K_pk_tmp_tmp] = 0.0F;
      for (N_tmp = 0; N_tmp < 5; N_tmp++) {
        P_param_PE_0[K_pk_tmp_tmp] += P_param_PE[5 * N_tmp + i] * N_1[5 *
          K_xk_tmp_tmp + N_tmp];
      }
    }

    K_pk[i] = 0.0F;
    K_pk[i] += P_param_PE_0[i] * N[0];
    tilde_theta_tmp_tmp = P_param_PE_0[i + 5];
    K_pk[i] += tilde_theta_tmp_tmp * N[1];
    K_pk[i + 5] = 0.0F;
    K_pk[i + 5] += P_param_PE_0[i] * N[2];
    K_pk[i + 5] += tilde_theta_tmp_tmp * N[3];
  }

  memset(&d[0], 0, 25U * sizeof(real_T));
  for (i = 0; i < 5; i++) {
    d[i + 5 * i] = 1.0;
  }

  tilde_theta_tmp_tmp = (real32_T)MATLAB0_U.igamma - (MATLAB0_DW.hat_param[1] *
    x_PE_idx_0 + MATLAB0_DW.hat_param[2] * x_PE_idx_1);
  TempA = (real32_T)MATLAB0_U.idelta - (MATLAB0_DW.hat_param[2] * x_PE_idx_0 +
    MATLAB0_DW.hat_param[3] * x_PE_idx_1);
  MATLAB0_DW.hat_x[0] = (K_xk[0] * tilde_theta_tmp_tmp + K_xk[2] * TempA) +
    x_PE_idx_0;
  MATLAB0_DW.hat_x[1] = (K_xk[1] * tilde_theta_tmp_tmp + K_xk[3] * TempA) +
    x_PE_idx_1;
  for (i = 0; i < 5; i++) {
    for (K_xk_tmp_tmp = 0; K_xk_tmp_tmp < 5; K_xk_tmp_tmp++) {
      N_tmp = K_xk_tmp_tmp << 1;
      K_pk_tmp_tmp = 5 * K_xk_tmp_tmp + i;
      d_0[K_pk_tmp_tmp] = (real32_T)d[K_pk_tmp_tmp] -
        (MATLAB0_DW.difH_difparam[N_tmp + 1] * K_pk[i + 5] +
         MATLAB0_DW.difH_difparam[N_tmp] * K_pk[i]);
    }

    for (K_xk_tmp_tmp = 0; K_xk_tmp_tmp < 5; K_xk_tmp_tmp++) {
      K_pk_tmp_tmp = i + 5 * K_xk_tmp_tmp;
      MATLAB0_DW.P_hat_param[K_pk_tmp_tmp] = 0.0F;
      for (N_tmp = 0; N_tmp < 5; N_tmp++) {
        MATLAB0_DW.P_hat_param[K_pk_tmp_tmp] += d_0[5 * N_tmp + i] * P_param_PE
          [5 * K_xk_tmp_tmp + N_tmp];
      }
    }

    MATLAB0_DW.hat_param[i] += K_pk[i + 5] * TempA + K_pk[i] *
      tilde_theta_tmp_tmp;
  }

  if (MATLAB0_DW.hat_param[0] > 2.0F) {
    MATLAB0_DW.hat_param[0] = 2.0F;
  } else {
    if (MATLAB0_DW.hat_param[0] < 0.2F) {
      MATLAB0_DW.hat_param[0] = 0.2F;
    }
  }

  if (MATLAB0_DW.hat_param[1] > 3700.0F) {
    MATLAB0_DW.hat_param[1] = 3700.0F;
  } else {
    if (MATLAB0_DW.hat_param[1] < 37.0F) {
      MATLAB0_DW.hat_param[1] = 37.0F;
    }
  }

  if (MATLAB0_DW.hat_param[2] > 370.0F) {
    MATLAB0_DW.hat_param[2] = 370.0F;
  } else {
    if (MATLAB0_DW.hat_param[2] < -370.0F) {
      MATLAB0_DW.hat_param[2] = -370.0F;
    }
  }

  if (MATLAB0_DW.hat_param[3] > 2000.0F) {
    MATLAB0_DW.hat_param[3] = 2000.0F;
  } else {
    if (MATLAB0_DW.hat_param[3] < 20.0F) {
      MATLAB0_DW.hat_param[3] = 20.0F;
    }
  }

  if (MATLAB0_DW.hat_param[4] > 0.1F) {
    MATLAB0_DW.hat_param[4] = 0.1F;
  } else {
    if (MATLAB0_DW.hat_param[4] < 0.24F) {
      MATLAB0_DW.hat_param[4] = 0.24F;
    }
  }

  for (i = 0; i < 10; i++) {
    MATLAB0_DW.difx_difparam[i] = difG_difparam[i];
  }

  MATLAB0_DW.K_xk_1[0] = K_xk[0];
  MATLAB0_DW.K_xk_1[1] = K_xk[1];
  MATLAB0_DW.K_xk_1[2] = K_xk[2];
  MATLAB0_DW.K_xk_1[3] = K_xk[3];
  if (MATLAB0_U.DEKF_CLEAR == 1.0) {
    MATLAB0_DW.hat_x[0] = 0.0F;
    MATLAB0_DW.hat_x[1] = 0.0F;
    MATLAB0_DW.hat_param[0] = INITV_RS;
    MATLAB0_DW.hat_param[1] = INITV_NDD;
    MATLAB0_DW.hat_param[2] = INITV_NDQ;
    MATLAB0_DW.hat_param[3] = INITV_NQQ;
    MATLAB0_DW.hat_param[4] = INITV_PSI;
    MATLAB0_DW.P_hat_x[0] = 0.0F;
    MATLAB0_DW.P_hat_x[1] = 0.0F;
    MATLAB0_DW.P_hat_x[2] = 0.0F;
    MATLAB0_DW.P_hat_x[3] = 0.0F;
    memset(&MATLAB0_DW.P_hat_param[0], 0, 25U * sizeof(real32_T));
    MATLAB0_DW.K_xk_1[0] = 0.0F;
    MATLAB0_DW.K_xk_1[1] = 0.0F;
    MATLAB0_DW.K_xk_1[2] = 0.0F;
    MATLAB0_DW.K_xk_1[3] = 0.0F;
    for (i = 0; i < 10; i++) {
      MATLAB0_DW.difx_difparam[i] = 0.0F;
      MATLAB0_DW.difH_difparam[i] = 0.0F;
    }
  }

  A_1[0] = MATLAB0_DW.hat_param[1];
  A_1[2] = MATLAB0_DW.hat_param[2];
  A_1[1] = MATLAB0_DW.hat_param[2];
  A_1[3] = MATLAB0_DW.hat_param[3];
  MATLAB0_mpower(A_1, N);
  K_xk[0] = x_PE_tmp_tmp;
  K_xk[2] = -tilde_theta;
  K_xk[1] = tilde_theta;
  K_xk[3] = x_PE_tmp_tmp;
  for (i = 0; i < 2; i++) {
    A[i] = 0.0F;
    A[i] += K_xk[i] * N[0];
    x_PE_idx_0 = K_xk[i + 2];
    A[i] += x_PE_idx_0 * N[1];
    A[i + 2] = 0.0F;
    A[i + 2] += K_xk[i] * N[2];
    A[i + 2] += x_PE_idx_0 * N[3];
    R[i] = 0.0F;
    R[i] += A[i] * x_PE_tmp_tmp;
    R[i] += A[i + 2] * -tilde_theta;
    R[i + 2] = 0.0F;
    R[i + 2] += A[i] * tilde_theta;
    R[i + 2] += A[i + 2] * x_PE_tmp_tmp;
  }

  /* Outport: '<Root>/RsOut' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function7'
   */
  MATLAB0_Y.RsOut = MATLAB0_DW.hat_param[0];

  /* Outport: '<Root>/LdOut' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function7'
   */
  MATLAB0_Y.LdOut = R[0];

  /* Outport: '<Root>/LqOut' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function7'
   */
  MATLAB0_Y.LqOut = R[3];

  /* Outport: '<Root>/PsidmOut' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function7'
   */
  MATLAB0_Y.PsidmOut = MATLAB0_DW.hat_param[4];
}

/* Model initialize function */
void MATLAB0_initialize(void)
{
  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_1' */
  INITV_RS = 0.93F;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_2' */
  INITV_NDD = 370.370361F;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_4' */
  INITV_NQQ = 204.081635F;

  /* Start for DataStoreMemory: '<Root>/_DataStoreBlk_5' */
  INITV_PSI = 0.047F;
}

/* Model terminate function */
void MATLAB0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
