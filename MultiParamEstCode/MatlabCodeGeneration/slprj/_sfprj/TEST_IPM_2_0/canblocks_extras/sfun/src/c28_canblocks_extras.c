/* Include files */

#include "canblocks_extras_sfun.h"
#include "c28_canblocks_extras.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c28_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c28_IN_Connected               ((uint8_T)1U)
#define c28_IN_Disconnected            ((uint8_T)2U)
#define c28_IN_Temporarily_Disconnected ((uint8_T)3U)
#define c28_const_TEMPORARY_DISCONNECT ((uint8_T)0U)
#define c28_const_PERMANENT_DISCONNECT ((uint8_T)1U)
#define c28_const_SLAVE_ID_LENGTH_NOT_USED ((uint8_T)0U)
#define c28_const_SLAVE_ID_DATA_TYPE_NOT_USED ((uint8_T)0U)
#define c28_const_RESOURCE_AVAILABILITY_MASK ((uint8_T)66U)
#define c28_const_RESOURCE_PROTECTION_MASK ((uint8_T)0U)
#define c28_const_MTA_ADDRESS_EXTENSION ((uint8_T)0U)
#define c28_const_S_STATUS_QUALIFIER   ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct
  *chartInstance);
static void initialize_params_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance);
static void enable_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct
  *chartInstance);
static void disable_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct
  *chartInstance);
static void c28_update_jit_animation_state_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance);
static void c28_do_animation_call_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance);
static void ext_mode_exec_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance);
static void set_sim_state_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, const mxArray *c28_st);
static void c28_set_sim_state_side_effects_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance);
static void finalize_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct
  *chartInstance);
static void sf_gateway_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct
  *chartInstance);
static void mdl_start_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct *
  chartInstance);
static void initSimStructsc28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance);
static void c28_Connected(SFc28_canblocks_extrasInstanceStruct *chartInstance);
static void c28_tx_dto(SFc28_canblocks_extrasInstanceStruct *chartInstance,
  uint8_T c28_tx_comm_type);
static uint8_T c28_emlrt_marshallIn(SFc28_canblocks_extrasInstanceStruct
  *chartInstance, const mxArray *c28_b_command_counter, const char_T
  *c28_identifier);
static uint8_T c28_b_emlrt_marshallIn(SFc28_canblocks_extrasInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static const mxArray *c28_c_emlrt_marshallIn
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, const mxArray
   *c28_b_setSimStateSideEffectsInfo, const char_T *c28_identifier);
static const mxArray *c28_d_emlrt_marshallIn
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, const mxArray *c28_u,
   const emlrtMsgIdentifier *c28_parentId);
static void c28_slStringInitializeDynamicBuffers
  (SFc28_canblocks_extrasInstanceStruct *chartInstance);
static void c28_init_sf_message_store_memory
  (SFc28_canblocks_extrasInstanceStruct *chartInstance);
static const mxArray *c28_chart_data_browse_helper
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, int32_T c28_ssIdNumber);
static void c28_slcc_cov_call_setSlave_Version_G1WZrK4kHQSfLP1BLKd6ID_by_sim
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index,
   uint8_T c28_version);
static void c28_slcc_cov_call_setStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index,
   uint8_T c28_address);
static void c28_slcc_cov_call_setCurrent_State_G1WZrK4kHQSfLP1BLKd6ID_by_sim
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_state);
static void c28_slcc_cov_call_c_reset_all_DAQ_lists_G1WZrK4kHQSfLP1BLKd6ID_b
  (SFc28_canblocks_extrasInstanceStruct *chartInstance);
static uint8_T c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index);
static void c28_slcc_cov_call_setHandled_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_handled);
static void c28_slcc_cov_call_setMaster_Version_G1WZrK4kHQSfLP1BLKd6ID_by_si
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index,
   uint8_T c28_version);
static uint32_T *c28_slcc_cov_call_getMTAPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index);
static void c28_slcc_cov_call_c_write_uint8s_G1WZrK4kHQSfLP1BLKd6ID_by_simst
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, const uint8_T
   *c28_source, uint8_T c28_length, uint32_T *c28_address);
static void c28_slcc_cov_call_c_set_element_pointer_G1WZrK4kHQSfLP1BLKd6ID_b
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_in0, uint8_T
   c28_in1, uint8_T c28_in2);
static void c28_slcc_cov_call_c_start_stop_all_G1WZrK4kHQSfLP1BLKd6ID_by_sim
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_in0);
static void c28_slcc_cov_call_c_start_stop_G1WZrK4kHQSfLP1BLKd6ID_by_simstru
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_in0, uint8_T
   c28_in1, uint8_T c28_in2, uint8_T c28_in3, uint16_T c28_in4);
static void c28_slcc_cov_call_setS_Status_G1WZrK4kHQSfLP1BLKd6ID_by_simstruc
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_status);
static void c28_slcc_cov_call_c_write_daq_G1WZrK4kHQSfLP1BLKd6ID_by_simstruc
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_in0,
   uint32_T c28_in1);
static void c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index,
   uint8_T c28_data);
static uint8_T c28_slcc_cov_call_getSlave_Version_G1WZrK4kHQSfLP1BLKd6ID_by_sim
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index);
static uint8_T *c28_slcc_cov_call_getDataPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index);
static void c28_slcc_cov_call_c_read_uint8s_G1WZrK4kHQSfLP1BLKd6ID_by_simstr
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T *c28_dest,
   uint8_T c28_length, uint32_T *c28_address);
static void c28_slcc_cov_call_c_init_daq_list_G1WZrK4kHQSfLP1BLKd6ID_by_sims
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_in0);
static uint8_T c28_slcc_cov_call_getS_Status_G1WZrK4kHQSfLP1BLKd6ID_by_simstruc
  (SFc28_canblocks_extrasInstanceStruct *chartInstance);
static uint8_T c28__u8_u16_(SFc28_canblocks_extrasInstanceStruct *chartInstance,
  uint16_T c28_b, int32_T c28_EMLOvCount_src_loc, uint32_T c28_ssid_src_loc,
  int32_T c28_offset_src_loc, int32_T c28_length_src_loc);
static void init_dsm_address_info(SFc28_canblocks_extrasInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc28_canblocks_extrasInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
  chartInstance->c28_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c28_doSetSimStateSideEffects = 0U;
  chartInstance->c28_setSimStateSideEffectsInfo = NULL;
  chartInstance->c28_is_active_c28_canblocks_extras = 0U;
  chartInstance->c28_is_c28_canblocks_extras = c28_IN_NO_ACTIVE_CHILD;
  chartInstance->c28_command_counter = 0U;
  chartInstance->c28_TEMPORARY_DISCONNECT = 0U;
  chartInstance->c28_PERMANENT_DISCONNECT = 1U;
  chartInstance->c28_SLAVE_ID_LENGTH_NOT_USED = 0U;
  chartInstance->c28_SLAVE_ID_DATA_TYPE_NOT_USED = 0U;
  chartInstance->c28_RESOURCE_AVAILABILITY_MASK = 66U;
  chartInstance->c28_RESOURCE_PROTECTION_MASK = 0U;
  chartInstance->c28_MTA_ADDRESS_EXTENSION = 0U;
  chartInstance->c28_S_STATUS_QUALIFIER = 0U;
  chartInstance->c28_is_active_c28_canblocks_extras = 1U;
  chartInstance->c28_JITTransitionAnimation[45U] = 1U;
  sf_force_animation_for_chart_exec_at_init(chartInstance->S);
  chartInstance->c28_JITTransitionAnimation[46U] = 1U;
  c28_slcc_cov_call_setSlave_Version_G1WZrK4kHQSfLP1BLKd6ID_by_sim(chartInstance,
    0U, 2U);
  c28_slcc_cov_call_setSlave_Version_G1WZrK4kHQSfLP1BLKd6ID_by_sim(chartInstance,
    1U, 1U);
  c28_slcc_cov_call_setStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s(chartInstance,
    0U, c28__u8_u16_(chartInstance, (uint16_T)(chartInstance->c28_CCP_STATION_ID
    & (uint16_T)0xFF), 0, 95U, 68, 5));
  c28_slcc_cov_call_setStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s(chartInstance,
    1U, c28__u8_u16_(chartInstance, (uint16_T)((uint32_T)
    chartInstance->c28_CCP_STATION_ID >> 8), 0, 95U, 120, 5));
  chartInstance->c28_is_c28_canblocks_extras = c28_IN_Disconnected;
  c28_slcc_cov_call_setCurrent_State_G1WZrK4kHQSfLP1BLKd6ID_by_sim(chartInstance,
    (uint8_T)CCP_DISCONNECTED_STATE);
  c28_slcc_cov_call_c_reset_all_DAQ_lists_G1WZrK4kHQSfLP1BLKd6ID_b(chartInstance);
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 0U, (real_T)
                    chartInstance->c28_command_counter);
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 13U, (real_T)
                    chartInstance->c28_TEMPORARY_DISCONNECT);
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 12U, (real_T)
                    chartInstance->c28_PERMANENT_DISCONNECT);
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 10U, (real_T)
                    chartInstance->c28_SLAVE_ID_LENGTH_NOT_USED);
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 9U, (real_T)
                    chartInstance->c28_SLAVE_ID_DATA_TYPE_NOT_USED);
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 7U, (real_T)
                    chartInstance->c28_RESOURCE_AVAILABILITY_MASK);
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 8U, (real_T)
                    chartInstance->c28_RESOURCE_PROTECTION_MASK);
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 6U, (real_T)
                    chartInstance->c28_MTA_ADDRESS_EXTENSION);
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 11U, (real_T)
                    chartInstance->c28_S_STATUS_QUALIFIER);
}

static void initialize_params_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  real_T c28_d;
  real_T c28_d1;
  real_T c28_d2;
  real_T c28_d3;
  real_T c28_d4;
  real_T c28_d5;
  real_T c28_d6;
  real_T c28_d7;
  real_T c28_d8;
  real_T c28_d9;
  real_T c28_d10;
  real_T c28_d11;
  real_T c28_d12;
  real_T c28_d13;
  real_T c28_d14;
  uint16_T c28_u;
  real_T c28_d15;
  sf_mex_import_named("GET_CCP_VERSIONenabled", sf_mex_get_sfun_param
                      (chartInstance->S, 4U, 0U), &c28_d, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_GET_CCP_VERSIONenabled = (c28_d != 0.0);
  sf_mex_import_named("EXCHANGE_IDenabled", sf_mex_get_sfun_param
                      (chartInstance->S, 3U, 0U), &c28_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_EXCHANGE_IDenabled = (c28_d1 != 0.0);
  sf_mex_import_named("SET_MTAenabled", sf_mex_get_sfun_param(chartInstance->S,
    8U, 0U), &c28_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_SET_MTAenabled = (c28_d2 != 0.0);
  sf_mex_import_named("DNLOADenabled", sf_mex_get_sfun_param(chartInstance->S,
    2U, 0U), &c28_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_DNLOADenabled = (c28_d3 != 0.0);
  sf_mex_import_named("UPLOADenabled", sf_mex_get_sfun_param(chartInstance->S,
    13U, 0U), &c28_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_UPLOADenabled = (c28_d4 != 0.0);
  sf_mex_import_named("SHORT_UPenabled", sf_mex_get_sfun_param(chartInstance->S,
    10U, 0U), &c28_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_SHORT_UPenabled = (c28_d5 != 0.0);
  sf_mex_import_named("GET_DAQ_SIZEenabled", sf_mex_get_sfun_param
                      (chartInstance->S, 5U, 0U), &c28_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_GET_DAQ_SIZEenabled = (c28_d6 != 0.0);
  sf_mex_import_named("SET_DAQ_PTRenabled", sf_mex_get_sfun_param
                      (chartInstance->S, 7U, 0U), &c28_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_SET_DAQ_PTRenabled = (c28_d7 != 0.0);
  sf_mex_import_named("WRITE_DAQenabled", sf_mex_get_sfun_param(chartInstance->S,
    14U, 0U), &c28_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_WRITE_DAQenabled = (c28_d8 != 0.0);
  sf_mex_import_named("START_STOPenabled", sf_mex_get_sfun_param
                      (chartInstance->S, 12U, 0U), &c28_d9, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_START_STOPenabled = (c28_d9 != 0.0);
  sf_mex_import_named("SET_S_STATUSenabled", sf_mex_get_sfun_param
                      (chartInstance->S, 9U, 0U), &c28_d10, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_SET_S_STATUSenabled = (c28_d10 != 0.0);
  sf_mex_import_named("GET_S_STATUSenabled", sf_mex_get_sfun_param
                      (chartInstance->S, 6U, 0U), &c28_d11, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_GET_S_STATUSenabled = (c28_d11 != 0.0);
  sf_mex_import_named("START_STOP_ALLenabled", sf_mex_get_sfun_param
                      (chartInstance->S, 11U, 0U), &c28_d12, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_START_STOP_ALLenabled = (c28_d12 != 0.0);
  sf_mex_import_named("CCP_STATION_ID", sf_mex_get_sfun_param(chartInstance->S,
    0U, 0U), &c28_d13, 0, 0, 0U, 0, 0U, 0);
  c28_d14 = c28_d13;
  if (c28_d14 < 65536.0) {
    if (c28_d14 >= 0.0) {
      c28_u = (uint16_T)c28_d14;
    } else {
      c28_u = 0U;
    }
  } else if (c28_d14 >= 65536.0) {
    c28_u = MAX_uint16_T;
  } else {
    c28_u = 0U;
  }

  chartInstance->c28_CCP_STATION_ID = c28_u;
  sf_mex_import_named("DNLOAD_6enabled", sf_mex_get_sfun_param(chartInstance->S,
    1U, 0U), &c28_d15, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c28_DNLOAD_6enabled = (c28_d15 != 0.0);
}

static void enable_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c28_update_jit_animation_state_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  chartInstance->c28_JITStateAnimation[0U] = (uint8_T)
    (chartInstance->c28_is_c28_canblocks_extras == c28_IN_Disconnected);
  chartInstance->c28_JITStateAnimation[1U] = (uint8_T)
    (chartInstance->c28_is_c28_canblocks_extras ==
     c28_IN_Temporarily_Disconnected);
  chartInstance->c28_JITStateAnimation[2U] = (uint8_T)
    (chartInstance->c28_is_c28_canblocks_extras == c28_IN_Connected);
}

static void c28_do_animation_call_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  sfDoAnimationWrapper(chartInstance->S, false, true);
  sfDoAnimationWrapper(chartInstance->S, false, false);
}

static void ext_mode_exec_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  const mxArray *c28_st;
  const mxArray *c28_y = NULL;
  const mxArray *c28_b_y = NULL;
  const mxArray *c28_c_y = NULL;
  const mxArray *c28_d_y = NULL;
  c28_st = NULL;
  c28_st = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_createcellmatrix(3, 1), false);
  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", &chartInstance->c28_command_counter,
    3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c28_y, 0, c28_b_y);
  c28_c_y = NULL;
  sf_mex_assign(&c28_c_y, sf_mex_create("y",
    &chartInstance->c28_is_active_c28_canblocks_extras, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c28_y, 1, c28_c_y);
  c28_d_y = NULL;
  sf_mex_assign(&c28_d_y, sf_mex_create("y",
    &chartInstance->c28_is_c28_canblocks_extras, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c28_y, 2, c28_d_y);
  sf_mex_assign(&c28_st, c28_y, false);
  return c28_st;
}

static void set_sim_state_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, const mxArray *c28_st)
{
  const mxArray *c28_u;
  chartInstance->c28_doneDoubleBufferReInit = true;
  c28_u = sf_mex_dup(c28_st);
  chartInstance->c28_command_counter = c28_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c28_u, 0)), "command_counter");
  chartInstance->c28_is_active_c28_canblocks_extras = c28_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c28_u, 1)),
     "is_active_c28_canblocks_extras");
  chartInstance->c28_is_c28_canblocks_extras = c28_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c28_u, 2)),
     "is_c28_canblocks_extras");
  sf_mex_assign(&chartInstance->c28_setSimStateSideEffectsInfo,
                c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c28_u, 3)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c28_u);
  chartInstance->c28_doSetSimStateSideEffects = 1U;
  c28_update_jit_animation_state_c28_canblocks_extras(chartInstance);
  sf_mex_destroy(&c28_st);
}

static void c28_set_sim_state_side_effects_c28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  if (chartInstance->c28_doSetSimStateSideEffects != 0) {
    chartInstance->c28_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct
  *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c28_RuntimeVar);
  sf_mex_destroy(&chartInstance->c28_setSimStateSideEffectsInfo);
  covrtDeleteStateflowInstanceData(chartInstance->c28_covrtInstance);
}

static void sf_gateway_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct
  *chartInstance)
{
  int32_T c28_i;
  boolean_T c28_temp;
  boolean_T c28_b_temp;
  uint8_T c28_u;
  boolean_T c28_c_temp;
  uint8_T c28_u1;
  boolean_T c28_d_temp;
  uint8_T c28_u2;
  boolean_T c28_out;
  uint8_T c28_u3;
  boolean_T c28_b_out;
  boolean_T c28_e_temp;
  uint8_T c28_u4;
  boolean_T c28_f_temp;
  boolean_T c28_g_temp;
  uint8_T c28_u5;
  uint8_T c28_u6;
  boolean_T c28_h_temp;
  boolean_T c28_c_out;
  uint8_T c28_u7;
  boolean_T c28_d_out;
  c28_set_sim_state_side_effects_c28_canblocks_extras(chartInstance);
  chartInstance->c28_JITTransitionAnimation[0] = 0U;
  chartInstance->c28_JITTransitionAnimation[1] = 0U;
  chartInstance->c28_JITTransitionAnimation[2] = 0U;
  chartInstance->c28_JITTransitionAnimation[3] = 0U;
  chartInstance->c28_JITTransitionAnimation[4] = 0U;
  chartInstance->c28_JITTransitionAnimation[5] = 0U;
  chartInstance->c28_JITTransitionAnimation[6] = 0U;
  chartInstance->c28_JITTransitionAnimation[7] = 0U;
  chartInstance->c28_JITTransitionAnimation[8] = 0U;
  chartInstance->c28_JITTransitionAnimation[9] = 0U;
  chartInstance->c28_JITTransitionAnimation[10] = 0U;
  chartInstance->c28_JITTransitionAnimation[11] = 0U;
  chartInstance->c28_JITTransitionAnimation[12] = 0U;
  chartInstance->c28_JITTransitionAnimation[13] = 0U;
  chartInstance->c28_JITTransitionAnimation[14] = 0U;
  chartInstance->c28_JITTransitionAnimation[15] = 0U;
  chartInstance->c28_JITTransitionAnimation[16] = 0U;
  chartInstance->c28_JITTransitionAnimation[17] = 0U;
  chartInstance->c28_JITTransitionAnimation[18] = 0U;
  chartInstance->c28_JITTransitionAnimation[19] = 0U;
  chartInstance->c28_JITTransitionAnimation[20] = 0U;
  chartInstance->c28_JITTransitionAnimation[21] = 0U;
  chartInstance->c28_JITTransitionAnimation[22] = 0U;
  chartInstance->c28_JITTransitionAnimation[23] = 0U;
  chartInstance->c28_JITTransitionAnimation[24] = 0U;
  chartInstance->c28_JITTransitionAnimation[25] = 0U;
  chartInstance->c28_JITTransitionAnimation[26] = 0U;
  chartInstance->c28_JITTransitionAnimation[27] = 0U;
  chartInstance->c28_JITTransitionAnimation[28] = 0U;
  chartInstance->c28_JITTransitionAnimation[29] = 0U;
  chartInstance->c28_JITTransitionAnimation[30] = 0U;
  chartInstance->c28_JITTransitionAnimation[31] = 0U;
  chartInstance->c28_JITTransitionAnimation[32] = 0U;
  chartInstance->c28_JITTransitionAnimation[33] = 0U;
  chartInstance->c28_JITTransitionAnimation[34] = 0U;
  chartInstance->c28_JITTransitionAnimation[35] = 0U;
  chartInstance->c28_JITTransitionAnimation[36] = 0U;
  chartInstance->c28_JITTransitionAnimation[37] = 0U;
  chartInstance->c28_JITTransitionAnimation[38] = 0U;
  chartInstance->c28_JITTransitionAnimation[39] = 0U;
  chartInstance->c28_JITTransitionAnimation[40] = 0U;
  chartInstance->c28_JITTransitionAnimation[41] = 0U;
  chartInstance->c28_JITTransitionAnimation[42] = 0U;
  chartInstance->c28_JITTransitionAnimation[43] = 0U;
  chartInstance->c28_JITTransitionAnimation[44] = 0U;
  chartInstance->c28_JITTransitionAnimation[45] = 0U;
  chartInstance->c28_JITTransitionAnimation[46] = 0U;
  chartInstance->c28_JITTransitionAnimation[47] = 0U;
  chartInstance->c28_JITTransitionAnimation[48] = 0U;
  chartInstance->c28_JITTransitionAnimation[49] = 0U;
  chartInstance->c28_JITTransitionAnimation[50] = 0U;
  chartInstance->c28_JITTransitionAnimation[51] = 0U;
  chartInstance->c28_JITTransitionAnimation[52] = 0U;
  chartInstance->c28_JITTransitionAnimation[53] = 0U;
  chartInstance->c28_JITTransitionAnimation[54] = 0U;
  chartInstance->c28_JITTransitionAnimation[55] = 0U;
  chartInstance->c28_JITTransitionAnimation[56] = 0U;
  chartInstance->c28_JITTransitionAnimation[57] = 0U;
  chartInstance->c28_JITTransitionAnimation[58] = 0U;
  chartInstance->c28_JITTransitionAnimation[59] = 0U;
  chartInstance->c28_JITTransitionAnimation[60] = 0U;
  chartInstance->c28_JITTransitionAnimation[61] = 0U;
  chartInstance->c28_JITTransitionAnimation[62] = 0U;
  chartInstance->c28_JITTransitionAnimation[63] = 0U;
  chartInstance->c28_JITTransitionAnimation[64] = 0U;
  chartInstance->c28_JITTransitionAnimation[65] = 0U;
  chartInstance->c28_JITTransitionAnimation[66] = 0U;
  chartInstance->c28_JITTransitionAnimation[67] = 0U;
  chartInstance->c28_JITTransitionAnimation[68] = 0U;
  chartInstance->c28_JITTransitionAnimation[69] = 0U;
  chartInstance->c28_JITTransitionAnimation[70] = 0U;
  chartInstance->c28_JITTransitionAnimation[71] = 0U;
  chartInstance->c28_JITTransitionAnimation[72] = 0U;
  chartInstance->c28_JITTransitionAnimation[73] = 0U;
  chartInstance->c28_JITTransitionAnimation[74] = 0U;
  chartInstance->c28_JITTransitionAnimation[75] = 0U;
  chartInstance->c28_JITTransitionAnimation[76] = 0U;
  chartInstance->c28_JITTransitionAnimation[77] = 0U;
  chartInstance->c28_JITTransitionAnimation[78] = 0U;
  chartInstance->c28_JITTransitionAnimation[79] = 0U;
  chartInstance->c28_JITTransitionAnimation[80] = 0U;
  chartInstance->c28_JITTransitionAnimation[81] = 0U;
  chartInstance->c28_JITTransitionAnimation[82] = 0U;
  chartInstance->c28_JITTransitionAnimation[83] = 0U;
  chartInstance->c28_JITTransitionAnimation[84] = 0U;
  chartInstance->c28_JITTransitionAnimation[85] = 0U;
  chartInstance->c28_JITTransitionAnimation[86] = 0U;
  chartInstance->c28_JITTransitionAnimation[87] = 0U;
  chartInstance->c28_JITTransitionAnimation[88] = 0U;
  chartInstance->c28_JITTransitionAnimation[89] = 0U;
  chartInstance->c28_JITTransitionAnimation[90] = 0U;
  chartInstance->c28_JITTransitionAnimation[91] = 0U;
  chartInstance->c28_JITTransitionAnimation[92] = 0U;
  chartInstance->c28_JITTransitionAnimation[93] = 0U;
  chartInstance->c28_JITTransitionAnimation[94] = 0U;
  chartInstance->c28_JITTransitionAnimation[95] = 0U;
  chartInstance->c28_JITTransitionAnimation[96] = 0U;
  chartInstance->c28_JITTransitionAnimation[97] = 0U;
  chartInstance->c28_JITTransitionAnimation[98] = 0U;
  chartInstance->c28_JITTransitionAnimation[99] = 0U;
  chartInstance->c28_JITTransitionAnimation[100] = 0U;
  _sfTime_ = sf_get_time(chartInstance->S);
  for (c28_i = 0; c28_i < 6; c28_i++) {
    covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 3U, (real_T)
                      (*chartInstance->c28_rx_data)[c28_i]);
  }

  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 2U, (real_T)
                    *chartInstance->c28_rx_count);
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 1U, (real_T)
                    *chartInstance->c28_rx_comm_type);
  chartInstance->c28_sfEvent = CALL_EVENT;
  switch (chartInstance->c28_is_c28_canblocks_extras) {
   case c28_IN_Connected:
    covrtDecUpdateFcn(chartInstance->c28_covrtInstance, 1U, 0, 0,
                      c28_IN_Connected);
    c28_Connected(chartInstance);
    break;

   case c28_IN_Disconnected:
    covrtDecUpdateFcn(chartInstance->c28_covrtInstance, 1U, 0, 0,
                      c28_IN_Disconnected);
    chartInstance->c28_JITTransitionAnimation[48U] = 1U;
    chartInstance->c28_command_counter = *chartInstance->c28_rx_count;
    covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 0U, (real_T)
                      chartInstance->c28_command_counter);
    c28_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 49U, 0,
      (*chartInstance->c28_rx_comm_type == CCP_CONNECT) != 0U);
    if (c28_temp) {
      c28_u = c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
        (chartInstance, 0U);
      c28_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 49U, 1,
        (boolean_T)covrtRelationalopUpdateFcn(chartInstance->c28_covrtInstance,
        5U, 49U, 0U, (real_T)(*chartInstance->c28_rx_data)[0], (real_T)c28_u, 0,
        0U, (*chartInstance->c28_rx_data)[0] == c28_u) != 0U);
    }

    c28_c_temp = c28_temp;
    if (c28_c_temp) {
      c28_u2 = c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
        (chartInstance, 1U);
      c28_c_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 49U,
        2, (boolean_T)covrtRelationalopUpdateFcn
        (chartInstance->c28_covrtInstance, 5U, 49U, 1U, (real_T)
         (*chartInstance->c28_rx_data)[1], (real_T)c28_u2, 0, 0U,
         (*chartInstance->c28_rx_data)[1] == c28_u2) != 0U);
    }

    c28_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance, 5U,
      49U, 0U, c28_c_temp != 0U);
    if (c28_out) {
      chartInstance->c28_JITTransitionAnimation[49U] = 1U;
      chartInstance->c28_is_c28_canblocks_extras = c28_IN_NO_ACTIVE_CHILD;
      c28_tx_dto(chartInstance, (uint8_T)CCP_CONNECT);
      chartInstance->c28_is_c28_canblocks_extras = c28_IN_Connected;
      c28_slcc_cov_call_setCurrent_State_G1WZrK4kHQSfLP1BLKd6ID_by_sim
        (chartInstance, (uint8_T)CCP_CONNECTED_STATE);
    } else {
      c28_e_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 51U,
        0, (*chartInstance->c28_rx_comm_type == CCP_TEST) != 0U);
      if (c28_e_temp) {
        c28_u4 =
          c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
          (chartInstance, 0U);
        c28_e_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
          51U, 1, (boolean_T)covrtRelationalopUpdateFcn
          (chartInstance->c28_covrtInstance, 5U, 51U, 0U, (real_T)
           (*chartInstance->c28_rx_data)[0], (real_T)c28_u4, 0, 0U,
           (*chartInstance->c28_rx_data)[0] == c28_u4) != 0U);
      }

      c28_g_temp = c28_e_temp;
      if (c28_g_temp) {
        c28_u6 =
          c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
          (chartInstance, 1U);
        c28_g_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
          51U, 2, (boolean_T)covrtRelationalopUpdateFcn
          (chartInstance->c28_covrtInstance, 5U, 51U, 1U, (real_T)
           (*chartInstance->c28_rx_data)[1], (real_T)c28_u6, 0, 0U,
           (*chartInstance->c28_rx_data)[1] == c28_u6) != 0U);
      }

      c28_c_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance,
        5U, 51U, 0U, c28_g_temp != 0U);
      if (c28_c_out) {
        chartInstance->c28_JITTransitionAnimation[51U] = 1U;
        c28_tx_dto(chartInstance, (uint8_T)CCP_TEST);
      } else {
        chartInstance->c28_JITTransitionAnimation[50U] = 1U;
        c28_slcc_cov_call_setHandled_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
          (chartInstance, 0U);
      }
    }
    break;

   case c28_IN_Temporarily_Disconnected:
    covrtDecUpdateFcn(chartInstance->c28_covrtInstance, 1U, 0, 0,
                      c28_IN_Temporarily_Disconnected);
    chartInstance->c28_JITTransitionAnimation[53U] = 1U;
    chartInstance->c28_command_counter = *chartInstance->c28_rx_count;
    covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 0U, (real_T)
                      chartInstance->c28_command_counter);
    chartInstance->c28_JITTransitionAnimation[54U] = 1U;
    c28_b_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 55U, 0,
      (*chartInstance->c28_rx_comm_type == CCP_TEST) != 0U);
    if (c28_b_temp) {
      c28_u1 = c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
        (chartInstance, 0U);
      c28_b_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 55U,
        1, (boolean_T)covrtRelationalopUpdateFcn
        (chartInstance->c28_covrtInstance, 5U, 55U, 0U, (real_T)
         (*chartInstance->c28_rx_data)[0], (real_T)c28_u1, 0, 0U,
         (*chartInstance->c28_rx_data)[0] == c28_u1) != 0U);
    }

    c28_d_temp = c28_b_temp;
    if (c28_d_temp) {
      c28_u3 = c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
        (chartInstance, 1U);
      c28_d_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 55U,
        2, (boolean_T)covrtRelationalopUpdateFcn
        (chartInstance->c28_covrtInstance, 5U, 55U, 1U, (real_T)
         (*chartInstance->c28_rx_data)[1], (real_T)c28_u3, 0, 0U,
         (*chartInstance->c28_rx_data)[1] == c28_u3) != 0U);
    }

    c28_b_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance, 5U,
      55U, 0U, c28_d_temp != 0U);
    if (c28_b_out) {
      chartInstance->c28_JITTransitionAnimation[55U] = 1U;
      c28_tx_dto(chartInstance, (uint8_T)CCP_TEST);
    } else {
      chartInstance->c28_JITTransitionAnimation[56U] = 1U;
      c28_f_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 52U,
        0, (*chartInstance->c28_rx_comm_type == CCP_CONNECT) != 0U);
      if (c28_f_temp) {
        c28_u5 =
          c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
          (chartInstance, 0U);
        c28_f_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
          52U, 1, (boolean_T)covrtRelationalopUpdateFcn
          (chartInstance->c28_covrtInstance, 5U, 52U, 0U, (real_T)
           (*chartInstance->c28_rx_data)[0], (real_T)c28_u5, 0, 0U,
           (*chartInstance->c28_rx_data)[0] == c28_u5) != 0U);
      }

      c28_h_temp = c28_f_temp;
      if (c28_h_temp) {
        c28_u7 =
          c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
          (chartInstance, 1U);
        c28_h_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
          52U, 2, (boolean_T)covrtRelationalopUpdateFcn
          (chartInstance->c28_covrtInstance, 5U, 52U, 1U, (real_T)
           (*chartInstance->c28_rx_data)[1], (real_T)c28_u7, 0, 0U,
           (*chartInstance->c28_rx_data)[1] == c28_u7) != 0U);
      }

      c28_d_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance,
        5U, 52U, 0U, c28_h_temp != 0U);
      if (c28_d_out) {
        chartInstance->c28_JITTransitionAnimation[52U] = 1U;
        c28_tx_dto(chartInstance, (uint8_T)CCP_CONNECT);
        chartInstance->c28_is_c28_canblocks_extras = c28_IN_NO_ACTIVE_CHILD;
        chartInstance->c28_is_c28_canblocks_extras = c28_IN_Connected;
        c28_slcc_cov_call_setCurrent_State_G1WZrK4kHQSfLP1BLKd6ID_by_sim
          (chartInstance, (uint8_T)CCP_CONNECTED_STATE);
      } else {
        chartInstance->c28_JITTransitionAnimation[57U] = 1U;
        c28_slcc_cov_call_setHandled_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
          (chartInstance, 0U);
      }
    }
    break;

   default:
    covrtDecUpdateFcn(chartInstance->c28_covrtInstance, 1U, 0, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c28_is_c28_canblocks_extras = c28_IN_NO_ACTIVE_CHILD;
    break;
  }

  c28_update_jit_animation_state_c28_canblocks_extras(chartInstance);
  c28_do_animation_call_c28_canblocks_extras(chartInstance);
}

static void mdl_start_c28_canblocks_extras(SFc28_canblocks_extrasInstanceStruct *
  chartInstance)
{
  static const uint32_T c28_decisionTxtStartIdx = 0U;
  static const uint32_T c28_decisionTxtEndIdx = 0U;
  static const uint32_T c28_b_decisionTxtStartIdx = 0U;
  static const uint32_T c28_b_decisionTxtEndIdx = 0U;
  static const uint32_T c28_c_decisionTxtStartIdx = 0U;
  static const uint32_T c28_c_decisionTxtEndIdx = 0U;
  static const uint32_T c28_d_decisionTxtStartIdx = 0U;
  static const uint32_T c28_d_decisionTxtEndIdx = 0U;
  static const uint32_T c28_e_decisionTxtStartIdx = 0U;
  static const uint32_T c28_e_decisionTxtEndIdx = 0U;
  static const uint32_T c28_f_decisionTxtStartIdx = 0U;
  static const uint32_T c28_f_decisionTxtEndIdx = 0U;
  static const uint32_T c28_g_decisionTxtStartIdx = 0U;
  static const uint32_T c28_g_decisionTxtEndIdx = 0U;
  static const uint32_T c28_h_decisionTxtStartIdx = 0U;
  static const uint32_T c28_h_decisionTxtEndIdx = 0U;
  static const uint32_T c28_i_decisionTxtStartIdx = 0U;
  static const uint32_T c28_i_decisionTxtEndIdx = 0U;
  static const uint32_T c28_transitionTxtStartIdx[3] = { 1U, 33U, 73U };

  static const uint32_T c28_transitionTxtEndIdx[3] = { 26U, 66U, 106U };

  static const int32_T c28_postfixPredicateTree[5] = { 0, 1, -3, 2, -3 };

  static const int32_T c28_relopTxtStartIdx[2] = { 33, 73 };

  static const int32_T c28_relopTxtEndIdx[2] = { 66, 106 };

  static const int32_T c28_relationalopEps[2] = { 0, 0 };

  static const int32_T c28_relationalopType[2] = { 0, 0 };

  static const uint32_T c28_b_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_b_transitionTxtEndIdx[1] = { 33U };

  static const int32_T c28_b_postfixPredicateTree[1] = { 0 };

  static const int32_T c28_b_relopTxtStartIdx[1] = { 1 };

  static const int32_T c28_b_relopTxtEndIdx[1] = { 33 };

  static const int32_T c28_b_relationalopEps[1] = { 0 };

  static const int32_T c28_b_relationalopType[1] = { 0 };

  static const uint32_T c28_c_transitionTxtStartIdx[3] = { 1U, 33U, 73U };

  static const uint32_T c28_c_transitionTxtEndIdx[3] = { 26U, 66U, 106U };

  static const int32_T c28_c_postfixPredicateTree[5] = { 0, 1, -3, 2, -3 };

  static const int32_T c28_c_relopTxtStartIdx[2] = { 33, 73 };

  static const int32_T c28_c_relopTxtEndIdx[2] = { 66, 106 };

  static const int32_T c28_c_relationalopEps[2] = { 0, 0 };

  static const int32_T c28_c_relationalopType[2] = { 0, 0 };

  static const uint32_T c28_d_transitionTxtStartIdx[2] = { 1U, 28U };

  static const uint32_T c28_d_transitionTxtEndIdx[2] = { 23U, 61U };

  static const int32_T c28_d_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_e_transitionTxtStartIdx[2] = { 1U, 24U };

  static const uint32_T c28_e_transitionTxtEndIdx[2] = { 19U, 53U };

  static const int32_T c28_e_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_f_transitionTxtStartIdx[2] = { 1U, 20U };

  static const uint32_T c28_f_transitionTxtEndIdx[2] = { 15U, 45U };

  static const int32_T c28_f_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_g_transitionTxtStartIdx[2] = { 1U, 19U };

  static const uint32_T c28_g_transitionTxtEndIdx[2] = { 14U, 43U };

  static const int32_T c28_g_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_h_transitionTxtStartIdx[2] = { 1U, 21U };

  static const uint32_T c28_h_transitionTxtEndIdx[2] = { 16U, 47U };

  static const int32_T c28_h_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_i_transitionTxtStartIdx[2] = { 1U, 21U };

  static const uint32_T c28_i_transitionTxtEndIdx[2] = { 16U, 51U };

  static const int32_T c28_i_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_j_transitionTxtStartIdx[2] = { 1U, 19U };

  static const uint32_T c28_j_transitionTxtEndIdx[2] = { 14U, 43U };

  static const int32_T c28_j_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_k_transitionTxtStartIdx[2] = { 1U, 25U };

  static const uint32_T c28_k_transitionTxtEndIdx[2] = { 20U, 55U };

  static const int32_T c28_k_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_l_transitionTxtStartIdx[2] = { 1U, 24U };

  static const uint32_T c28_l_transitionTxtEndIdx[2] = { 19U, 53U };

  static const int32_T c28_l_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_m_transitionTxtStartIdx[2] = { 1U, 22U };

  static const uint32_T c28_m_transitionTxtEndIdx[2] = { 17U, 49U };

  static const int32_T c28_m_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_n_transitionTxtStartIdx[2] = { 1U, 27U };

  static const uint32_T c28_n_transitionTxtEndIdx[2] = { 22U, 59U };

  static const int32_T c28_n_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_o_transitionTxtStartIdx[2] = { 1U, 23U };

  static const uint32_T c28_o_transitionTxtEndIdx[2] = { 18U, 51U };

  static const int32_T c28_o_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_p_transitionTxtStartIdx[2] = { 1U, 25U };

  static const uint32_T c28_p_transitionTxtEndIdx[2] = { 20U, 55U };

  static const int32_T c28_p_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_q_transitionTxtStartIdx[2] = { 1U, 25U };

  static const uint32_T c28_q_transitionTxtEndIdx[2] = { 20U, 55U };

  static const int32_T c28_q_postfixPredicateTree[3] = { 0, 1, -3 };

  static const uint32_T c28_r_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_r_transitionTxtEndIdx[1] = { 23U };

  static const int32_T c28_r_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_s_transitionTxtStartIdx[2] = { 1U, 41U };

  static const uint32_T c28_s_transitionTxtEndIdx[2] = { 34U, 74U };

  static const int32_T c28_s_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c28_d_relopTxtStartIdx[2] = { 1, 41 };

  static const int32_T c28_d_relopTxtEndIdx[2] = { 34, 74 };

  static const int32_T c28_d_relationalopEps[2] = { 0, 0 };

  static const int32_T c28_d_relationalopType[2] = { 0, 0 };

  static const uint32_T c28_t_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_t_transitionTxtEndIdx[1] = { 26U };

  static const int32_T c28_t_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_u_transitionTxtStartIdx[2] = { 1U, 41U };

  static const uint32_T c28_u_transitionTxtEndIdx[2] = { 34U, 74U };

  static const int32_T c28_u_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c28_e_relopTxtStartIdx[2] = { 1, 41 };

  static const int32_T c28_e_relopTxtEndIdx[2] = { 34, 74 };

  static const int32_T c28_e_relationalopEps[2] = { 0, 0 };

  static const int32_T c28_e_relationalopType[2] = { 0, 0 };

  static const uint32_T c28_v_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_v_transitionTxtEndIdx[1] = { 29U };

  static const int32_T c28_v_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_w_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_w_transitionTxtEndIdx[1] = { 33U };

  static const int32_T c28_w_postfixPredicateTree[1] = { 0 };

  static const int32_T c28_f_relopTxtStartIdx[1] = { 1 };

  static const int32_T c28_f_relopTxtEndIdx[1] = { 33 };

  static const int32_T c28_f_relationalopEps[1] = { 0 };

  static const int32_T c28_f_relationalopType[1] = { 0 };

  static const uint32_T c28_x_transitionTxtStartIdx[3] = { 1U, 29U, 68U };

  static const uint32_T c28_x_transitionTxtEndIdx[3] = { 23U, 62U, 101U };

  static const int32_T c28_x_postfixPredicateTree[5] = { 0, 1, -3, 2, -3 };

  static const int32_T c28_g_relopTxtStartIdx[2] = { 29, 68 };

  static const int32_T c28_g_relopTxtEndIdx[2] = { 62, 101 };

  static const int32_T c28_g_relationalopEps[2] = { 0, 0 };

  static const int32_T c28_g_relationalopType[2] = { 0, 0 };

  static const uint32_T c28_y_transitionTxtStartIdx[3] = { 1U, 30U, 70U };

  static const uint32_T c28_y_transitionTxtEndIdx[3] = { 23U, 63U, 103U };

  static const int32_T c28_y_postfixPredicateTree[5] = { 0, 1, -3, 2, -3 };

  static const int32_T c28_h_relopTxtStartIdx[2] = { 30, 70 };

  static const int32_T c28_h_relopTxtEndIdx[2] = { 63, 103 };

  static const int32_T c28_h_relationalopEps[2] = { 0, 0 };

  static const int32_T c28_h_relationalopType[2] = { 0, 0 };

  static const uint32_T c28_ab_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_ab_transitionTxtEndIdx[1] = { 23U };

  static const int32_T c28_ab_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_bb_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_bb_transitionTxtEndIdx[1] = { 29U };

  static const int32_T c28_bb_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_cb_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_cb_transitionTxtEndIdx[1] = { 26U };

  static const int32_T c28_cb_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_db_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_db_transitionTxtEndIdx[1] = { 26U };

  static const int32_T c28_db_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_eb_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_eb_transitionTxtEndIdx[1] = { 30U };

  static const int32_T c28_eb_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_fb_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_fb_transitionTxtEndIdx[1] = { 28U };

  static const int32_T c28_fb_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_gb_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_gb_transitionTxtEndIdx[1] = { 29U };

  static const int32_T c28_gb_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_hb_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_hb_transitionTxtEndIdx[1] = { 33U };

  static const int32_T c28_hb_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_ib_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_ib_transitionTxtEndIdx[1] = { 31U };

  static const int32_T c28_ib_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_jb_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_jb_transitionTxtEndIdx[1] = { 34U };

  static const int32_T c28_jb_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_kb_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_kb_transitionTxtEndIdx[1] = { 30U };

  static const int32_T c28_kb_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_lb_transitionTxtStartIdx[2] = { 2U, 32U };

  static const uint32_T c28_lb_transitionTxtEndIdx[2] = { 26U, 58U };

  static const int32_T c28_lb_postfixPredicateTree[3] = { 0, 1, -2 };

  static const uint32_T c28_mb_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_mb_transitionTxtEndIdx[1] = { 31U };

  static const int32_T c28_mb_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_nb_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_nb_transitionTxtEndIdx[1] = { 25U };

  static const int32_T c28_nb_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_ob_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_ob_transitionTxtEndIdx[1] = { 31U };

  static const int32_T c28_ob_postfixPredicateTree[1] = { 0 };

  static const uint32_T c28_pb_transitionTxtStartIdx[1] = { 1U };

  static const uint32_T c28_pb_transitionTxtEndIdx[1] = { 31U };

  static const int32_T c28_pb_postfixPredicateTree[1] = { 0 };

  setLegacyDebuggerFlag(chartInstance->S, false);
  setDebuggerFlag(chartInstance->S, true);
  setDataBrowseFcn(chartInstance->S, (void *)c28_chart_data_browse_helper);
  chartInstance->c28_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
  covrtCreateStateflowInstanceData(chartInstance->c28_covrtInstance, 9U, 0U,
    101U, 62U);
  covrtChartInitFcn(chartInstance->c28_covrtInstance, 3U, true, false, false);
  covrtStateInitFcn(chartInstance->c28_covrtInstance, 0U, 0U, false, false,
                    false, 0U, &c28_decisionTxtStartIdx, &c28_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c28_covrtInstance, 1U, 0U, false, false,
                    false, 0U, &c28_b_decisionTxtStartIdx,
                    &c28_b_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c28_covrtInstance, 2U, 0U, false, false,
                    false, 0U, &c28_c_decisionTxtStartIdx,
                    &c28_c_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c28_covrtInstance, 3U, 0U, false, false,
                    false, 0U, &c28_d_decisionTxtStartIdx,
                    &c28_d_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c28_covrtInstance, 4U, 0U, false, false,
                    false, 0U, &c28_e_decisionTxtStartIdx,
                    &c28_e_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c28_covrtInstance, 5U, 0U, false, false,
                    false, 0U, &c28_f_decisionTxtStartIdx,
                    &c28_f_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c28_covrtInstance, 6U, 0U, false, false,
                    false, 0U, &c28_g_decisionTxtStartIdx,
                    &c28_g_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c28_covrtInstance, 7U, 0U, false, false,
                    false, 0U, &c28_h_decisionTxtStartIdx,
                    &c28_h_decisionTxtEndIdx);
  covrtStateInitFcn(chartInstance->c28_covrtInstance, 8U, 0U, false, false,
                    false, 0U, &c28_i_decisionTxtStartIdx,
                    &c28_i_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 52U, 3,
                    c28_transitionTxtStartIdx, c28_transitionTxtEndIdx, 5U,
                    c28_postfixPredicateTree);
  covrtRelationalopInitFcn(chartInstance->c28_covrtInstance, 52U, 2,
    c28_relopTxtStartIdx, c28_relopTxtEndIdx, c28_relationalopEps,
    c28_relationalopType);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 95U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 100U, 1,
                    c28_b_transitionTxtStartIdx, c28_b_transitionTxtEndIdx, 1U,
                    c28_b_postfixPredicateTree);
  covrtRelationalopInitFcn(chartInstance->c28_covrtInstance, 100U, 1,
    c28_b_relopTxtStartIdx, c28_b_relopTxtEndIdx, c28_b_relationalopEps,
    c28_b_relationalopType);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 49U, 3,
                    c28_c_transitionTxtStartIdx, c28_c_transitionTxtEndIdx, 5U,
                    c28_c_postfixPredicateTree);
  covrtRelationalopInitFcn(chartInstance->c28_covrtInstance, 49U, 2,
    c28_c_relopTxtStartIdx, c28_c_relopTxtEndIdx, c28_c_relationalopEps,
    c28_c_relationalopType);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 45U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 58U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 59U, 2,
                    c28_d_transitionTxtStartIdx, c28_d_transitionTxtEndIdx, 3U,
                    c28_d_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 60U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 61U, 2,
                    c28_e_transitionTxtStartIdx, c28_e_transitionTxtEndIdx, 3U,
                    c28_e_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 62U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 63U, 2,
                    c28_f_transitionTxtStartIdx, c28_f_transitionTxtEndIdx, 3U,
                    c28_f_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 64U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 65U, 2,
                    c28_g_transitionTxtStartIdx, c28_g_transitionTxtEndIdx, 3U,
                    c28_g_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 66U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 67U, 2,
                    c28_h_transitionTxtStartIdx, c28_h_transitionTxtEndIdx, 3U,
                    c28_h_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 68U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 69U, 2,
                    c28_i_transitionTxtStartIdx, c28_i_transitionTxtEndIdx, 3U,
                    c28_i_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 70U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 71U, 2,
                    c28_j_transitionTxtStartIdx, c28_j_transitionTxtEndIdx, 3U,
                    c28_j_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 72U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 73U, 2,
                    c28_k_transitionTxtStartIdx, c28_k_transitionTxtEndIdx, 3U,
                    c28_k_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 74U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 75U, 2,
                    c28_l_transitionTxtStartIdx, c28_l_transitionTxtEndIdx, 3U,
                    c28_l_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 76U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 77U, 2,
                    c28_m_transitionTxtStartIdx, c28_m_transitionTxtEndIdx, 3U,
                    c28_m_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 78U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 79U, 2,
                    c28_n_transitionTxtStartIdx, c28_n_transitionTxtEndIdx, 3U,
                    c28_n_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 80U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 81U, 2,
                    c28_o_transitionTxtStartIdx, c28_o_transitionTxtEndIdx, 3U,
                    c28_o_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 82U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 83U, 2,
                    c28_p_transitionTxtStartIdx, c28_p_transitionTxtEndIdx, 3U,
                    c28_p_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 84U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 85U, 2,
                    c28_q_transitionTxtStartIdx, c28_q_transitionTxtEndIdx, 3U,
                    c28_q_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 86U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 87U, 1,
                    c28_r_transitionTxtStartIdx, c28_r_transitionTxtEndIdx, 1U,
                    c28_r_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 88U, 2,
                    c28_s_transitionTxtStartIdx, c28_s_transitionTxtEndIdx, 3U,
                    c28_s_postfixPredicateTree);
  covrtRelationalopInitFcn(chartInstance->c28_covrtInstance, 88U, 2,
    c28_d_relopTxtStartIdx, c28_d_relopTxtEndIdx, c28_d_relationalopEps,
    c28_d_relationalopType);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 89U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 90U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 91U, 1,
                    c28_t_transitionTxtStartIdx, c28_t_transitionTxtEndIdx, 1U,
                    c28_t_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 92U, 2,
                    c28_u_transitionTxtStartIdx, c28_u_transitionTxtEndIdx, 3U,
                    c28_u_postfixPredicateTree);
  covrtRelationalopInitFcn(chartInstance->c28_covrtInstance, 92U, 2,
    c28_e_relopTxtStartIdx, c28_e_relopTxtEndIdx, c28_e_relationalopEps,
    c28_e_relationalopType);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 93U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 94U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 96U, 1,
                    c28_v_transitionTxtStartIdx, c28_v_transitionTxtEndIdx, 1U,
                    c28_v_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 97U, 1,
                    c28_w_transitionTxtStartIdx, c28_w_transitionTxtEndIdx, 1U,
                    c28_w_postfixPredicateTree);
  covrtRelationalopInitFcn(chartInstance->c28_covrtInstance, 97U, 1,
    c28_f_relopTxtStartIdx, c28_f_relopTxtEndIdx, c28_f_relationalopEps,
    c28_f_relationalopType);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 98U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 99U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 53U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 54U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 55U, 3,
                    c28_x_transitionTxtStartIdx, c28_x_transitionTxtEndIdx, 5U,
                    c28_x_postfixPredicateTree);
  covrtRelationalopInitFcn(chartInstance->c28_covrtInstance, 55U, 2,
    c28_g_relopTxtStartIdx, c28_g_relopTxtEndIdx, c28_g_relationalopEps,
    c28_g_relationalopType);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 56U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 57U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 48U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 50U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 51U, 3,
                    c28_y_transitionTxtStartIdx, c28_y_transitionTxtEndIdx, 5U,
                    c28_y_postfixPredicateTree);
  covrtRelationalopInitFcn(chartInstance->c28_covrtInstance, 51U, 2,
    c28_h_relopTxtStartIdx, c28_h_relopTxtEndIdx, c28_h_relationalopEps,
    c28_h_relationalopType);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 47U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 46U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 42U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 0U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 1U, 1,
                    c28_ab_transitionTxtStartIdx, c28_ab_transitionTxtEndIdx, 1U,
                    c28_ab_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 2U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 3U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 4U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 5U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 6U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 7U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 8U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 9U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 10U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 11U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 12U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 13U, 1,
                    c28_bb_transitionTxtStartIdx, c28_bb_transitionTxtEndIdx, 1U,
                    c28_bb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 14U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 15U, 1,
                    c28_cb_transitionTxtStartIdx, c28_cb_transitionTxtEndIdx, 1U,
                    c28_cb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 16U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 17U, 1,
                    c28_db_transitionTxtStartIdx, c28_db_transitionTxtEndIdx, 1U,
                    c28_db_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 18U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 19U, 1,
                    c28_eb_transitionTxtStartIdx, c28_eb_transitionTxtEndIdx, 1U,
                    c28_eb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 20U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 21U, 1,
                    c28_fb_transitionTxtStartIdx, c28_fb_transitionTxtEndIdx, 1U,
                    c28_fb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 22U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 23U, 1,
                    c28_gb_transitionTxtStartIdx, c28_gb_transitionTxtEndIdx, 1U,
                    c28_gb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 24U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 25U, 1,
                    c28_hb_transitionTxtStartIdx, c28_hb_transitionTxtEndIdx, 1U,
                    c28_hb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 26U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 27U, 1,
                    c28_ib_transitionTxtStartIdx, c28_ib_transitionTxtEndIdx, 1U,
                    c28_ib_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 28U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 29U, 1,
                    c28_jb_transitionTxtStartIdx, c28_jb_transitionTxtEndIdx, 1U,
                    c28_jb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 30U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 31U, 1,
                    c28_kb_transitionTxtStartIdx, c28_kb_transitionTxtEndIdx, 1U,
                    c28_kb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 32U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 33U, 2,
                    c28_lb_transitionTxtStartIdx, c28_lb_transitionTxtEndIdx, 3U,
                    c28_lb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 34U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 35U, 1,
                    c28_mb_transitionTxtStartIdx, c28_mb_transitionTxtEndIdx, 1U,
                    c28_mb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 36U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 37U, 1,
                    c28_nb_transitionTxtStartIdx, c28_nb_transitionTxtEndIdx, 1U,
                    c28_nb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 38U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 39U, 1,
                    c28_ob_transitionTxtStartIdx, c28_ob_transitionTxtEndIdx, 1U,
                    c28_ob_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 40U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 41U, 1,
                    c28_pb_transitionTxtStartIdx, c28_pb_transitionTxtEndIdx, 1U,
                    c28_pb_postfixPredicateTree);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 43U, 0, NULL, NULL, 0U,
                    NULL);
  covrtTransInitFcn(chartInstance->c28_covrtInstance, 44U, 0, NULL, NULL, 0U,
                    NULL);
}

static void initSimStructsc28_canblocks_extras
  (SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c28_Connected(SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  boolean_T c28_temp;
  boolean_T c28_out;
  boolean_T c28_b_temp;
  boolean_T c28_b_out;
  boolean_T c28_c_temp;
  boolean_T c28_c_out;
  boolean_T c28_d_temp;
  boolean_T c28_d_out;
  boolean_T c28_e_temp;
  boolean_T c28_e_out;
  boolean_T c28_f_temp;
  boolean_T c28_f_out;
  boolean_T c28_g_temp;
  boolean_T c28_g_out;
  boolean_T c28_h_temp;
  boolean_T c28_h_out;
  boolean_T c28_i_temp;
  boolean_T c28_i_out;
  boolean_T c28_j_temp;
  boolean_T c28_j_out;
  boolean_T c28_k_temp;
  uint32_T c28_address;
  boolean_T c28_k_out;
  boolean_T c28_l_temp;
  boolean_T c28_l_out;
  boolean_T c28_m_temp;
  boolean_T c28_m_out;
  boolean_T c28_n_temp;
  boolean_T c28_n_out;
  boolean_T c28_o_out;
  boolean_T c28_guard1 = false;
  boolean_T c28_guard2 = false;
  boolean_T c28_guard3 = false;
  boolean_T c28_p_out;
  uint8_T c28_u;
  boolean_T c28_o_temp;
  boolean_T c28_q_out;
  uint8_T c28_u1;
  uint8_T c28_u2;
  boolean_T c28_p_temp;
  boolean_T c28_r_out;
  boolean_T c28_s_out;
  uint8_T c28_u3;
  boolean_T c28_t_out;
  boolean_T c28_u_out;
  chartInstance->c28_JITTransitionAnimation[58U] = 1U;
  chartInstance->c28_command_counter = *chartInstance->c28_rx_count;
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 0U, (real_T)
                    chartInstance->c28_command_counter);
  c28_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 59U, 0,
    chartInstance->c28_GET_CCP_VERSIONenabled != 0U);
  if (c28_temp) {
    c28_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 59U, 1,
      (*chartInstance->c28_rx_comm_type == CCP_GET_CCP_VERSION) != 0U);
  }

  c28_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance, 5U,
    59U, 0U, c28_temp != 0U);
  if (c28_out) {
    chartInstance->c28_JITTransitionAnimation[59U] = 1U;
    c28_slcc_cov_call_setMaster_Version_G1WZrK4kHQSfLP1BLKd6ID_by_si
      (chartInstance, 0U, (*chartInstance->c28_rx_data)[0]);
    c28_slcc_cov_call_setMaster_Version_G1WZrK4kHQSfLP1BLKd6ID_by_si
      (chartInstance, 1U, (*chartInstance->c28_rx_data)[1]);
    c28_tx_dto(chartInstance, (uint8_T)CCP_GET_CCP_VERSION);
  } else {
    chartInstance->c28_JITTransitionAnimation[60U] = 1U;
    c28_b_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 61U, 0,
      chartInstance->c28_EXCHANGE_IDenabled != 0U);
    if (c28_b_temp) {
      c28_b_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 61U,
        1, (*chartInstance->c28_rx_comm_type == CCP_EXCHANGE_ID) != 0U);
    }

    c28_b_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance, 5U,
      61U, 0U, c28_b_temp != 0U);
    if (c28_b_out) {
      chartInstance->c28_JITTransitionAnimation[61U] = 1U;
      c28_tx_dto(chartInstance, (uint8_T)CCP_EXCHANGE_ID);
    } else {
      chartInstance->c28_JITTransitionAnimation[62U] = 1U;
      c28_c_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 63U,
        0, chartInstance->c28_SET_MTAenabled != 0U);
      if (c28_c_temp) {
        c28_c_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
          63U, 1, (*chartInstance->c28_rx_comm_type == CCP_SET_MTA) != 0U);
      }

      c28_c_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance,
        5U, 63U, 0U, c28_c_temp != 0U);
      if (c28_c_out) {
        chartInstance->c28_JITTransitionAnimation[63U] = 1U;
        chartInstance->c28_JITTransitionAnimation[44U] = 1U;
        c_setUINT32bytes
          (c28_slcc_cov_call_getMTAPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
           (chartInstance, (*chartInstance->c28_rx_data)[0]),
           &(*chartInstance->c28_rx_data)[2]);
        c28_tx_dto(chartInstance, (uint8_T)CCP_SET_MTA);
      } else {
        chartInstance->c28_JITTransitionAnimation[64U] = 1U;
        c28_d_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
          65U, 0, chartInstance->c28_DNLOADenabled != 0U);
        if (c28_d_temp) {
          c28_d_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
            65U, 1, (*chartInstance->c28_rx_comm_type == CCP_DNLOAD) != 0U);
        }

        c28_d_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance,
          5U, 65U, 0U, c28_d_temp != 0U);
        if (c28_d_out) {
          chartInstance->c28_JITTransitionAnimation[65U] = 1U;
          c28_slcc_cov_call_c_write_uint8s_G1WZrK4kHQSfLP1BLKd6ID_by_simst
            (chartInstance, (const uint8_T *)&(*chartInstance->c28_rx_data)[1],
             (*chartInstance->c28_rx_data)[0],
             c28_slcc_cov_call_getMTAPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
             (chartInstance, 0U));
          c28_tx_dto(chartInstance, (uint8_T)CCP_DNLOAD);
        } else {
          chartInstance->c28_JITTransitionAnimation[66U] = 1U;
          c28_e_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
            67U, 0, chartInstance->c28_DNLOAD_6enabled != 0U);
          if (c28_e_temp) {
            c28_e_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
              67U, 1, (*chartInstance->c28_rx_comm_type == CCP_DNLOAD_6) != 0U);
          }

          c28_e_out = covrtTransitionDecUpdateFcn
            (chartInstance->c28_covrtInstance, 5U, 67U, 0U, c28_e_temp != 0U);
          if (c28_e_out) {
            chartInstance->c28_JITTransitionAnimation[67U] = 1U;
            c28_slcc_cov_call_c_write_uint8s_G1WZrK4kHQSfLP1BLKd6ID_by_simst
              (chartInstance, (const uint8_T *)&(*chartInstance->c28_rx_data)[0],
               6U,
               c28_slcc_cov_call_getMTAPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
               (chartInstance, 0U));
            c28_tx_dto(chartInstance, (uint8_T)CCP_DNLOAD_6);
          } else {
            chartInstance->c28_JITTransitionAnimation[68U] = 1U;
            c28_f_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
              69U, 0, chartInstance->c28_SHORT_UPenabled != 0U);
            if (c28_f_temp) {
              c28_f_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance,
                5U, 69U, 1, (*chartInstance->c28_rx_comm_type ==
                             CCP_SHORT_UPLOAD) != 0U);
            }

            c28_f_out = covrtTransitionDecUpdateFcn
              (chartInstance->c28_covrtInstance, 5U, 69U, 0U, c28_f_temp != 0U);
            if (c28_f_out) {
              chartInstance->c28_JITTransitionAnimation[69U] = 1U;
              c28_tx_dto(chartInstance, (uint8_T)CCP_SHORT_UPLOAD);
            } else {
              chartInstance->c28_JITTransitionAnimation[70U] = 1U;
              c28_g_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance,
                5U, 71U, 0, chartInstance->c28_UPLOADenabled != 0U);
              if (c28_g_temp) {
                c28_g_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance,
                  5U, 71U, 1, (*chartInstance->c28_rx_comm_type == CCP_UPLOAD)
                  != 0U);
              }

              c28_g_out = covrtTransitionDecUpdateFcn
                (chartInstance->c28_covrtInstance, 5U, 71U, 0U, c28_g_temp != 0U);
              if (c28_g_out) {
                chartInstance->c28_JITTransitionAnimation[71U] = 1U;
                c28_tx_dto(chartInstance, (uint8_T)CCP_UPLOAD);
              } else {
                chartInstance->c28_JITTransitionAnimation[72U] = 1U;
                c28_h_temp = covrtCondUpdateFcn(chartInstance->c28_covrtInstance,
                  5U, 73U, 0, chartInstance->c28_GET_DAQ_SIZEenabled != 0U);
                if (c28_h_temp) {
                  c28_h_temp = covrtCondUpdateFcn
                    (chartInstance->c28_covrtInstance, 5U, 73U, 1,
                     (*chartInstance->c28_rx_comm_type == CCP_GET_DAQ_SIZE) !=
                     0U);
                }

                c28_h_out = covrtTransitionDecUpdateFcn
                  (chartInstance->c28_covrtInstance, 5U, 73U, 0U, c28_h_temp !=
                   0U);
                if (c28_h_out) {
                  chartInstance->c28_JITTransitionAnimation[73U] = 1U;
                  c28_tx_dto(chartInstance, (uint8_T)CCP_GET_DAQ_SIZE);
                } else {
                  chartInstance->c28_JITTransitionAnimation[74U] = 1U;
                  c28_i_temp = covrtCondUpdateFcn
                    (chartInstance->c28_covrtInstance, 5U, 75U, 0,
                     chartInstance->c28_SET_DAQ_PTRenabled != 0U);
                  if (c28_i_temp) {
                    c28_i_temp = covrtCondUpdateFcn
                      (chartInstance->c28_covrtInstance, 5U, 75U, 1,
                       (*chartInstance->c28_rx_comm_type == CCP_SET_DAQ_PTR) !=
                       0U);
                  }

                  c28_i_out = covrtTransitionDecUpdateFcn
                    (chartInstance->c28_covrtInstance, 5U, 75U, 0U, c28_i_temp
                     != 0U);
                  if (c28_i_out) {
                    chartInstance->c28_JITTransitionAnimation[75U] = 1U;
                    c28_slcc_cov_call_c_set_element_pointer_G1WZrK4kHQSfLP1BLKd6ID_b
                      (chartInstance, (*chartInstance->c28_rx_data)[0],
                       (*chartInstance->c28_rx_data)[1],
                       (*chartInstance->c28_rx_data)[2]);
                    c28_tx_dto(chartInstance, (uint8_T)CCP_SET_DAQ_PTR);
                  } else {
                    chartInstance->c28_JITTransitionAnimation[76U] = 1U;
                    c28_j_temp = covrtCondUpdateFcn
                      (chartInstance->c28_covrtInstance, 5U, 77U, 0,
                       chartInstance->c28_WRITE_DAQenabled != 0U);
                    if (c28_j_temp) {
                      c28_j_temp = covrtCondUpdateFcn
                        (chartInstance->c28_covrtInstance, 5U, 77U, 1,
                         (*chartInstance->c28_rx_comm_type == CCP_WRITE_DAQ) !=
                         0U);
                    }

                    c28_j_out = covrtTransitionDecUpdateFcn
                      (chartInstance->c28_covrtInstance, 5U, 77U, 0U, c28_j_temp
                       != 0U);
                    if (c28_j_out) {
                      chartInstance->c28_JITTransitionAnimation[77U] = 1U;
                      c28_address = 0U;
                      covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 5U,
                                        (real_T)c28_address);
                      chartInstance->c28_JITTransitionAnimation[43U] = 1U;
                      c_setUINT32bytes(&c28_address,
                                       &(*chartInstance->c28_rx_data)[2]);
                      c28_slcc_cov_call_c_write_daq_G1WZrK4kHQSfLP1BLKd6ID_by_simstruc
                        (chartInstance, (*chartInstance->c28_rx_data)[0],
                         c28_address);
                      c28_tx_dto(chartInstance, (uint8_T)CCP_WRITE_DAQ);
                    } else {
                      chartInstance->c28_JITTransitionAnimation[78U] = 1U;
                      c28_k_temp = covrtCondUpdateFcn
                        (chartInstance->c28_covrtInstance, 5U, 79U, 0,
                         chartInstance->c28_START_STOP_ALLenabled != 0U);
                      if (c28_k_temp) {
                        c28_k_temp = covrtCondUpdateFcn
                          (chartInstance->c28_covrtInstance, 5U, 79U, 1,
                           (*chartInstance->c28_rx_comm_type ==
                            CCP_START_STOP_ALL) != 0U);
                      }

                      c28_k_out = covrtTransitionDecUpdateFcn
                        (chartInstance->c28_covrtInstance, 5U, 79U, 0U,
                         c28_k_temp != 0U);
                      if (c28_k_out) {
                        chartInstance->c28_JITTransitionAnimation[79U] = 1U;
                        c28_slcc_cov_call_c_start_stop_all_G1WZrK4kHQSfLP1BLKd6ID_by_sim
                          (chartInstance, (*chartInstance->c28_rx_data)[0]);
                        c28_tx_dto(chartInstance, (uint8_T)CCP_START_STOP_ALL);
                      } else {
                        chartInstance->c28_JITTransitionAnimation[80U] = 1U;
                        c28_l_temp = covrtCondUpdateFcn
                          (chartInstance->c28_covrtInstance, 5U, 81U, 0,
                           chartInstance->c28_START_STOPenabled != 0U);
                        if (c28_l_temp) {
                          c28_l_temp = covrtCondUpdateFcn
                            (chartInstance->c28_covrtInstance, 5U, 81U, 1,
                             (*chartInstance->c28_rx_comm_type == CCP_START_STOP)
                             != 0U);
                        }

                        c28_l_out = covrtTransitionDecUpdateFcn
                          (chartInstance->c28_covrtInstance, 5U, 81U, 0U,
                           c28_l_temp != 0U);
                        if (c28_l_out) {
                          chartInstance->c28_JITTransitionAnimation[81U] = 1U;
                          c28_slcc_cov_call_c_start_stop_G1WZrK4kHQSfLP1BLKd6ID_by_simstru
                            (chartInstance, (*chartInstance->c28_rx_data)[0],
                             (*chartInstance->c28_rx_data)[1],
                             (*chartInstance->c28_rx_data)[2],
                             (*chartInstance->c28_rx_data)[3], 1U);
                          c28_tx_dto(chartInstance, (uint8_T)CCP_START_STOP);
                        } else {
                          chartInstance->c28_JITTransitionAnimation[82U] = 1U;
                          c28_m_temp = covrtCondUpdateFcn
                            (chartInstance->c28_covrtInstance, 5U, 83U, 0,
                             chartInstance->c28_SET_S_STATUSenabled != 0U);
                          if (c28_m_temp) {
                            c28_m_temp = covrtCondUpdateFcn
                              (chartInstance->c28_covrtInstance, 5U, 83U, 1,
                               (*chartInstance->c28_rx_comm_type ==
                                CCP_SET_S_STATUS) != 0U);
                          }

                          c28_m_out = covrtTransitionDecUpdateFcn
                            (chartInstance->c28_covrtInstance, 5U, 83U, 0U,
                             c28_m_temp != 0U);
                          if (c28_m_out) {
                            chartInstance->c28_JITTransitionAnimation[83U] = 1U;
                            c28_slcc_cov_call_setS_Status_G1WZrK4kHQSfLP1BLKd6ID_by_simstruc
                              (chartInstance, (*chartInstance->c28_rx_data)[0]);
                            c28_tx_dto(chartInstance, (uint8_T)CCP_SET_S_STATUS);
                          } else {
                            chartInstance->c28_JITTransitionAnimation[84U] = 1U;
                            c28_n_temp = covrtCondUpdateFcn
                              (chartInstance->c28_covrtInstance, 5U, 85U, 0,
                               chartInstance->c28_GET_S_STATUSenabled != 0U);
                            if (c28_n_temp) {
                              c28_n_temp = covrtCondUpdateFcn
                                (chartInstance->c28_covrtInstance, 5U, 85U, 1, (*
                                  chartInstance->c28_rx_comm_type ==
                                  CCP_GET_S_STATUS) != 0U);
                            }

                            c28_n_out = covrtTransitionDecUpdateFcn
                              (chartInstance->c28_covrtInstance, 5U, 85U, 0U,
                               c28_n_temp != 0U);
                            if (c28_n_out) {
                              chartInstance->c28_JITTransitionAnimation[85U] =
                                1U;
                              c28_tx_dto(chartInstance, (uint8_T)
                                         CCP_GET_S_STATUS);
                            } else {
                              chartInstance->c28_JITTransitionAnimation[86U] =
                                1U;
                              c28_o_out = covrtTransitionDecUpdateFcn
                                (chartInstance->c28_covrtInstance, 5U, 87U, 0U,
                                 covrtCondUpdateFcn
                                 (chartInstance->c28_covrtInstance, 5U, 87U, 0,
                                  (*chartInstance->c28_rx_comm_type == CCP_TEST)
                                  != 0U) != 0U);
                              c28_guard1 = false;
                              c28_guard2 = false;
                              c28_guard3 = false;
                              if (c28_o_out) {
                                chartInstance->c28_JITTransitionAnimation[87U] =
                                  1U;
                                c28_u =
                                  c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
                                  (chartInstance, 0U);
                                c28_o_temp = covrtCondUpdateFcn
                                  (chartInstance->c28_covrtInstance, 5U, 88U, 0,
                                   (boolean_T)covrtRelationalopUpdateFcn
                                   (chartInstance->c28_covrtInstance, 5U, 88U,
                                    0U, (real_T)(*chartInstance->c28_rx_data)[0],
                                    (real_T)c28_u, 0, 0U,
                                    (*chartInstance->c28_rx_data)[0] == c28_u)
                                   != 0U);
                                if (c28_o_temp) {
                                  c28_u2 =
                                    c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
                                    (chartInstance, 1U);
                                  c28_o_temp = covrtCondUpdateFcn
                                    (chartInstance->c28_covrtInstance, 5U, 88U,
                                     1, (boolean_T)covrtRelationalopUpdateFcn
                                     (chartInstance->c28_covrtInstance, 5U, 88U,
                                      1U, (real_T)(*chartInstance->c28_rx_data)
                                      [1], (real_T)c28_u2, 0, 0U,
                                      (*chartInstance->c28_rx_data)[1] == c28_u2)
                                     != 0U);
                                }

                                c28_r_out = covrtTransitionDecUpdateFcn
                                  (chartInstance->c28_covrtInstance, 5U, 88U, 0U,
                                   c28_o_temp != 0U);
                                if (c28_r_out) {
                                  chartInstance->c28_JITTransitionAnimation[88U]
                                    = 1U;
                                  c28_tx_dto(chartInstance, (uint8_T)CCP_TEST);
                                } else {
                                  chartInstance->c28_JITTransitionAnimation[90U]
                                    = 1U;
                                  c28_slcc_cov_call_setHandled_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                    (chartInstance, 0U);
                                  c28_guard2 = true;
                                }
                              } else {
                                chartInstance->c28_JITTransitionAnimation[89U] =
                                  1U;
                                c28_p_out = covrtTransitionDecUpdateFcn
                                  (chartInstance->c28_covrtInstance, 5U, 91U, 0U,
                                   covrtCondUpdateFcn
                                   (chartInstance->c28_covrtInstance, 5U, 91U, 0,
                                    (*chartInstance->c28_rx_comm_type ==
                                     CCP_CONNECT) != 0U) != 0U);
                                if (c28_p_out) {
                                  chartInstance->c28_JITTransitionAnimation[91U]
                                    = 1U;
                                  c28_u1 =
                                    c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
                                    (chartInstance, 0U);
                                  c28_p_temp = covrtCondUpdateFcn
                                    (chartInstance->c28_covrtInstance, 5U, 92U,
                                     0, (boolean_T)covrtRelationalopUpdateFcn
                                     (chartInstance->c28_covrtInstance, 5U, 92U,
                                      0U, (real_T)(*chartInstance->c28_rx_data)
                                      [0], (real_T)c28_u1, 0, 0U,
                                      (*chartInstance->c28_rx_data)[0] == c28_u1)
                                     != 0U);
                                  if (c28_p_temp) {
                                    c28_u3 =
                                      c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
                                      (chartInstance, 1U);
                                    c28_p_temp = covrtCondUpdateFcn
                                      (chartInstance->c28_covrtInstance, 5U, 92U,
                                       1, (boolean_T)covrtRelationalopUpdateFcn
                                       (chartInstance->c28_covrtInstance, 5U,
                                        92U, 1U, (real_T)
                                        (*chartInstance->c28_rx_data)[1],
                                        (real_T)c28_u3, 0, 0U,
                                        (*chartInstance->c28_rx_data)[1] ==
                                        c28_u3) != 0U);
                                  }

                                  c28_t_out = covrtTransitionDecUpdateFcn
                                    (chartInstance->c28_covrtInstance, 5U, 92U,
                                     0U, c28_p_temp != 0U);
                                  if (c28_t_out) {
                                    chartInstance->c28_JITTransitionAnimation
                                      [92U] = 1U;
                                    c28_tx_dto(chartInstance, (uint8_T)
                                               CCP_CONNECT);
                                  } else {
                                    chartInstance->c28_JITTransitionAnimation
                                      [94U] = 1U;
                                    c28_slcc_cov_call_setHandled_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                      (chartInstance, 0U);
                                    c28_guard3 = true;
                                  }
                                } else {
                                  chartInstance->c28_JITTransitionAnimation[93U]
                                    = 1U;
                                  c28_q_out = covrtTransitionDecUpdateFcn
                                    (chartInstance->c28_covrtInstance, 5U, 96U,
                                     0U, covrtCondUpdateFcn
                                     (chartInstance->c28_covrtInstance, 5U, 96U,
                                      0, (*chartInstance->c28_rx_comm_type ==
                                          CCP_DISCONNECT) != 0U) != 0U);
                                  if (c28_q_out) {
                                    chartInstance->c28_JITTransitionAnimation
                                      [96U] = 1U;
                                    c28_s_out = covrtTransitionDecUpdateFcn
                                      (chartInstance->c28_covrtInstance, 5U,
                                       100U, 0U, covrtCondUpdateFcn
                                       (chartInstance->c28_covrtInstance, 5U,
                                        100U, 0, (boolean_T)
                                        covrtRelationalopUpdateFcn
                                        (chartInstance->c28_covrtInstance, 5U,
                                         100U, 0U, (real_T)
                                         (*chartInstance->c28_rx_data)[0],
                                         (real_T)c28_const_PERMANENT_DISCONNECT,
                                         0, 0U, (*chartInstance->c28_rx_data)[0]
                                         == c28_const_PERMANENT_DISCONNECT) !=
                                        0U) != 0U);
                                    if (c28_s_out) {
                                      chartInstance->c28_JITTransitionAnimation
                                        [100U] = 1U;
                                      c28_tx_dto(chartInstance, (uint8_T)
                                                 CCP_DISCONNECT);
                                      chartInstance->c28_is_c28_canblocks_extras
                                        = c28_IN_NO_ACTIVE_CHILD;
                                      chartInstance->c28_is_c28_canblocks_extras
                                        = c28_IN_Disconnected;
                                      c28_slcc_cov_call_setCurrent_State_G1WZrK4kHQSfLP1BLKd6ID_by_sim
                                        (chartInstance, (uint8_T)
                                         CCP_DISCONNECTED_STATE);
                                      c28_slcc_cov_call_c_reset_all_DAQ_lists_G1WZrK4kHQSfLP1BLKd6ID_b
                                        (chartInstance);
                                    } else {
                                      c28_u_out = covrtTransitionDecUpdateFcn
                                        (chartInstance->c28_covrtInstance, 5U,
                                         97U, 0U, covrtCondUpdateFcn
                                         (chartInstance->c28_covrtInstance, 5U,
                                          97U, 0, (boolean_T)
                                          covrtRelationalopUpdateFcn
                                          (chartInstance->c28_covrtInstance, 5U,
                                           97U, 0U, (real_T)
                                           (*chartInstance->c28_rx_data)[0],
                                           (real_T)
                                           c28_const_TEMPORARY_DISCONNECT, 0, 0U,
                                           (*chartInstance->c28_rx_data)[0] ==
                                           c28_const_TEMPORARY_DISCONNECT) != 0U)
                                         != 0U);
                                      if (c28_u_out) {
                                        chartInstance->c28_JITTransitionAnimation
                                          [97U] = 1U;
                                        c28_tx_dto(chartInstance, (uint8_T)
                                                   CCP_DISCONNECT);
                                        c28_guard3 = true;
                                      } else {
                                        c28_guard1 = true;
                                      }
                                    }
                                  } else {
                                    c28_guard1 = true;
                                  }
                                }
                              }

                              if (c28_guard3) {
                                chartInstance->c28_JITTransitionAnimation[98U] =
                                  1U;
                                c28_guard2 = true;
                              }

                              if (c28_guard2) {
                                chartInstance->c28_JITTransitionAnimation[95U] =
                                  1U;
                                chartInstance->c28_is_c28_canblocks_extras =
                                  c28_IN_NO_ACTIVE_CHILD;
                                chartInstance->c28_is_c28_canblocks_extras =
                                  c28_IN_Temporarily_Disconnected;
                                c28_slcc_cov_call_setCurrent_State_G1WZrK4kHQSfLP1BLKd6ID_by_sim
                                  (chartInstance, (uint8_T)
                                   CCP_TEMPORARILY_DISCONNECTED_STATE);
                              }

                              if (c28_guard1) {
                                chartInstance->c28_JITTransitionAnimation[99U] =
                                  1U;
                                chartInstance->c28_JITTransitionAnimation[47U] =
                                  1U;
                                c28_slcc_cov_call_setHandled_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 0U);
                                c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 0U,
                                   *chartInstance->c28_rx_comm_type);
                                c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 1U,
                                   *chartInstance->c28_rx_count);
                                c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 2U,
                                   (*chartInstance->c28_rx_data)[0]);
                                c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 3U,
                                   (*chartInstance->c28_rx_data)[1]);
                                c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 4U,
                                   (*chartInstance->c28_rx_data)[2]);
                                c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 5U,
                                   (*chartInstance->c28_rx_data)[3]);
                                c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 6U,
                                   (*chartInstance->c28_rx_data)[4]);
                                c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 7U,
                                   (*chartInstance->c28_rx_data)[5]);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

const mxArray *sf_c28_canblocks_extras_get_eml_resolved_functions_info(void)
{
  const mxArray *c28_nameCaptureInfo = NULL;
  c28_nameCaptureInfo = NULL;
  sf_mex_assign(&c28_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c28_nameCaptureInfo;
}

static void c28_tx_dto(SFc28_canblocks_extrasInstanceStruct *chartInstance,
  uint8_T c28_tx_comm_type)
{
  uint32_T c28_memptr;
  boolean_T c28_out;
  boolean_T c28_guard1 = false;
  boolean_T c28_b_out;
  boolean_T c28_c_out;
  boolean_T c28_d_out;
  boolean_T c28_e_out;
  boolean_T c28_f_out;
  boolean_T c28_g_out;
  boolean_T c28_h_out;
  boolean_T c28_i_out;
  boolean_T c28_j_out;
  boolean_T c28_k_out;
  boolean_T c28_temp;
  boolean_T c28_l_out;
  boolean_T c28_m_out;
  boolean_T c28_n_out;
  boolean_T c28_o_out;
  boolean_T c28_p_out;
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 14U, (real_T)
                    c28_tx_comm_type);
  c28_memptr = 0U;
  covrtSigUpdateFcn(chartInstance->c28_covrtInstance, 4U, (real_T)c28_memptr);
  chartInstance->c28_JITTransitionAnimation[0U] = 1U;
  c28_slcc_cov_call_setHandled_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct(chartInstance,
    1U);
  c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct(chartInstance,
    0U, (uint8_T)CCP_DTO_ID);
  c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct(chartInstance,
    1U, (uint8_T)CCP_CRC_OK);
  c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct(chartInstance,
    2U, chartInstance->c28_command_counter);
  c28_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance, 5U, 1U,
    0U, covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 1U, 0,
    (c28_tx_comm_type == CCP_TEST) != 0U) != 0U);
  c28_guard1 = false;
  if (c28_out) {
    chartInstance->c28_JITTransitionAnimation[1U] = 1U;
    chartInstance->c28_JITTransitionAnimation[2U] = 1U;
    c28_guard1 = true;
  } else {
    chartInstance->c28_JITTransitionAnimation[3U] = 1U;
    c28_b_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance, 5U,
      13U, 0U, covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 13U, 0,
      (c28_tx_comm_type == CCP_DISCONNECT) != 0U) != 0U);
    if (c28_b_out) {
      chartInstance->c28_JITTransitionAnimation[13U] = 1U;
      chartInstance->c28_JITTransitionAnimation[5U] = 1U;
      c28_guard1 = true;
    } else {
      chartInstance->c28_JITTransitionAnimation[14U] = 1U;
      c28_c_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance,
        5U, 15U, 0U, covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
        15U, 0, (c28_tx_comm_type == CCP_CONNECT) != 0U) != 0U);
      if (c28_c_out) {
        chartInstance->c28_JITTransitionAnimation[15U] = 1U;
        chartInstance->c28_JITTransitionAnimation[6U] = 1U;
        c28_guard1 = true;
      } else {
        chartInstance->c28_JITTransitionAnimation[16U] = 1U;
        c28_d_out = covrtTransitionDecUpdateFcn(chartInstance->c28_covrtInstance,
          5U, 17U, 0U, covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
          17U, 0, (c28_tx_comm_type == CCP_SET_MTA) != 0U) != 0U);
        if (c28_d_out) {
          chartInstance->c28_JITTransitionAnimation[17U] = 1U;
          chartInstance->c28_JITTransitionAnimation[7U] = 1U;
          c28_guard1 = true;
        } else {
          chartInstance->c28_JITTransitionAnimation[18U] = 1U;
          c28_e_out = covrtTransitionDecUpdateFcn
            (chartInstance->c28_covrtInstance, 5U, 19U, 0U, covrtCondUpdateFcn
             (chartInstance->c28_covrtInstance, 5U, 19U, 0, (c28_tx_comm_type ==
               CCP_SET_DAQ_PTR) != 0U) != 0U);
          if (c28_e_out) {
            chartInstance->c28_JITTransitionAnimation[19U] = 1U;
            chartInstance->c28_JITTransitionAnimation[8U] = 1U;
            c28_guard1 = true;
          } else {
            chartInstance->c28_JITTransitionAnimation[20U] = 1U;
            c28_f_out = covrtTransitionDecUpdateFcn
              (chartInstance->c28_covrtInstance, 5U, 21U, 0U, covrtCondUpdateFcn
               (chartInstance->c28_covrtInstance, 5U, 21U, 0, (c28_tx_comm_type ==
                 CCP_WRITE_DAQ) != 0U) != 0U);
            if (c28_f_out) {
              chartInstance->c28_JITTransitionAnimation[21U] = 1U;
              chartInstance->c28_JITTransitionAnimation[9U] = 1U;
              c28_guard1 = true;
            } else {
              chartInstance->c28_JITTransitionAnimation[22U] = 1U;
              c28_g_out = covrtTransitionDecUpdateFcn
                (chartInstance->c28_covrtInstance, 5U, 23U, 0U,
                 covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 23U, 0,
                                    (c28_tx_comm_type == CCP_START_STOP) != 0U)
                 != 0U);
              if (c28_g_out) {
                chartInstance->c28_JITTransitionAnimation[23U] = 1U;
                chartInstance->c28_JITTransitionAnimation[10U] = 1U;
                c28_guard1 = true;
              } else {
                chartInstance->c28_JITTransitionAnimation[24U] = 1U;
                c28_h_out = covrtTransitionDecUpdateFcn
                  (chartInstance->c28_covrtInstance, 5U, 25U, 0U,
                   covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U, 25U,
                                      0, (c28_tx_comm_type == CCP_START_STOP_ALL)
                                      != 0U) != 0U);
                if (c28_h_out) {
                  chartInstance->c28_JITTransitionAnimation[25U] = 1U;
                  chartInstance->c28_JITTransitionAnimation[11U] = 1U;
                  c28_guard1 = true;
                } else {
                  chartInstance->c28_JITTransitionAnimation[26U] = 1U;
                  c28_i_out = covrtTransitionDecUpdateFcn
                    (chartInstance->c28_covrtInstance, 5U, 27U, 0U,
                     covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
                                        27U, 0, (c28_tx_comm_type ==
                       CCP_SET_S_STATUS) != 0U) != 0U);
                  if (c28_i_out) {
                    chartInstance->c28_JITTransitionAnimation[27U] = 1U;
                    chartInstance->c28_JITTransitionAnimation[12U] = 1U;
                    c28_guard1 = true;
                  } else {
                    chartInstance->c28_JITTransitionAnimation[28U] = 1U;
                    c28_j_out = covrtTransitionDecUpdateFcn
                      (chartInstance->c28_covrtInstance, 5U, 29U, 0U,
                       covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
                                          29U, 0, (c28_tx_comm_type ==
                         CCP_GET_CCP_VERSION) != 0U) != 0U);
                    if (c28_j_out) {
                      chartInstance->c28_JITTransitionAnimation[29U] = 1U;
                      c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                        (chartInstance, 3U,
                         c28_slcc_cov_call_getSlave_Version_G1WZrK4kHQSfLP1BLKd6ID_by_sim
                         (chartInstance, 0U));
                      c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                        (chartInstance, 4U,
                         c28_slcc_cov_call_getSlave_Version_G1WZrK4kHQSfLP1BLKd6ID_by_sim
                         (chartInstance, 1U));
                    } else {
                      chartInstance->c28_JITTransitionAnimation[30U] = 1U;
                      c28_k_out = covrtTransitionDecUpdateFcn
                        (chartInstance->c28_covrtInstance, 5U, 31U, 0U,
                         covrtCondUpdateFcn(chartInstance->c28_covrtInstance, 5U,
                                            31U, 0, (c28_tx_comm_type ==
                           CCP_EXCHANGE_ID) != 0U) != 0U);
                      if (c28_k_out) {
                        chartInstance->c28_JITTransitionAnimation[31U] = 1U;
                        c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                          (chartInstance, 3U, c28_const_SLAVE_ID_LENGTH_NOT_USED);
                        c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                          (chartInstance, 4U,
                           c28_const_SLAVE_ID_DATA_TYPE_NOT_USED);
                        c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                          (chartInstance, 5U,
                           c28_const_RESOURCE_AVAILABILITY_MASK);
                        c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                          (chartInstance, 6U, c28_const_RESOURCE_PROTECTION_MASK);
                      } else {
                        chartInstance->c28_JITTransitionAnimation[32U] = 1U;
                        c28_temp = covrtCondUpdateFcn
                          (chartInstance->c28_covrtInstance, 5U, 33U, 0,
                           (c28_tx_comm_type == CCP_DNLOAD) != 0U);
                        if (!c28_temp) {
                          c28_temp = covrtCondUpdateFcn
                            (chartInstance->c28_covrtInstance, 5U, 33U, 1,
                             (c28_tx_comm_type == CCP_DNLOAD_6) != 0U);
                        }

                        c28_l_out = covrtTransitionDecUpdateFcn
                          (chartInstance->c28_covrtInstance, 5U, 33U, 0U,
                           c28_temp != 0U);
                        if (c28_l_out) {
                          chartInstance->c28_JITTransitionAnimation[33U] = 1U;
                          c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                            (chartInstance, 3U, c28_const_MTA_ADDRESS_EXTENSION);
                          covrtSigUpdateFcn(chartInstance->c28_covrtInstance,
                                            15U, 4.0);
                          chartInstance->c28_JITTransitionAnimation[42U] = 1U;
                          c_getUINT32bytes
                            (c28_slcc_cov_call_getMTAPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                             (chartInstance, 0U),
                             c28_slcc_cov_call_getDataPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                             (chartInstance, 4U));
                        } else {
                          chartInstance->c28_JITTransitionAnimation[34U] = 1U;
                          c28_m_out = covrtTransitionDecUpdateFcn
                            (chartInstance->c28_covrtInstance, 5U, 35U, 0U,
                             covrtCondUpdateFcn(chartInstance->c28_covrtInstance,
                                                5U, 35U, 0, (c28_tx_comm_type ==
                               CCP_SHORT_UPLOAD) != 0U) != 0U);
                          if (c28_m_out) {
                            chartInstance->c28_JITTransitionAnimation[35U] = 1U;
                            c_setUINT32bytes(&c28_memptr,
                                             &(*chartInstance->c28_rx_data)[2]);
                            c28_slcc_cov_call_c_read_uint8s_G1WZrK4kHQSfLP1BLKd6ID_by_simstr
                              (chartInstance,
                               c28_slcc_cov_call_getDataPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                               (chartInstance, 3U), (*chartInstance->c28_rx_data)
                               [0], &c28_memptr);
                          } else {
                            chartInstance->c28_JITTransitionAnimation[36U] = 1U;
                            c28_n_out = covrtTransitionDecUpdateFcn
                              (chartInstance->c28_covrtInstance, 5U, 37U, 0U,
                               covrtCondUpdateFcn
                               (chartInstance->c28_covrtInstance, 5U, 37U, 0,
                                (c28_tx_comm_type == CCP_UPLOAD) != 0U) != 0U);
                            if (c28_n_out) {
                              chartInstance->c28_JITTransitionAnimation[37U] =
                                1U;
                              c28_slcc_cov_call_c_read_uint8s_G1WZrK4kHQSfLP1BLKd6ID_by_simstr
                                (chartInstance,
                                 c28_slcc_cov_call_getDataPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                 (chartInstance, 3U),
                                 (*chartInstance->c28_rx_data)[0],
                                 c28_slcc_cov_call_getMTAPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                 (chartInstance, 0U));
                            } else {
                              chartInstance->c28_JITTransitionAnimation[38U] =
                                1U;
                              c28_o_out = covrtTransitionDecUpdateFcn
                                (chartInstance->c28_covrtInstance, 5U, 39U, 0U,
                                 covrtCondUpdateFcn
                                 (chartInstance->c28_covrtInstance, 5U, 39U, 0,
                                  (c28_tx_comm_type == CCP_GET_DAQ_SIZE) != 0U)
                                 != 0U);
                              if (c28_o_out) {
                                chartInstance->c28_JITTransitionAnimation[39U] =
                                  1U;
                                c28_slcc_cov_call_c_init_daq_list_G1WZrK4kHQSfLP1BLKd6ID_by_sims
                                  (chartInstance, (*chartInstance->c28_rx_data)
                                   [0]);
                                c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 5U, 0U);
                                c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 6U, 0U);
                                c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                  (chartInstance, 7U, 0U);
                              } else {
                                chartInstance->c28_JITTransitionAnimation[40U] =
                                  1U;
                                c28_p_out = covrtTransitionDecUpdateFcn
                                  (chartInstance->c28_covrtInstance, 5U, 41U, 0U,
                                   covrtCondUpdateFcn
                                   (chartInstance->c28_covrtInstance, 5U, 41U, 0,
                                    (c28_tx_comm_type == CCP_GET_S_STATUS) != 0U)
                                   != 0U);
                                if (c28_p_out) {
                                  chartInstance->c28_JITTransitionAnimation[41U]
                                    = 1U;
                                  c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                    (chartInstance, 3U,
                                     c28_slcc_cov_call_getS_Status_G1WZrK4kHQSfLP1BLKd6ID_by_simstruc
                                     (chartInstance));
                                  c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
                                    (chartInstance, 4U,
                                     c28_const_S_STATUS_QUALIFIER);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  if (c28_guard1) {
    chartInstance->c28_JITTransitionAnimation[4U] = 1U;
    c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct(chartInstance,
      3U, 0U);
    c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct(chartInstance,
      4U, 0U);
    c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct(chartInstance,
      5U, 0U);
    c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct(chartInstance,
      6U, 0U);
    c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct(chartInstance,
      7U, 0U);
  }
}

static uint8_T c28_emlrt_marshallIn(SFc28_canblocks_extrasInstanceStruct
  *chartInstance, const mxArray *c28_b_command_counter, const char_T
  *c28_identifier)
{
  uint8_T c28_y;
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = (const char *)c28_identifier;
  c28_thisId.fParent = NULL;
  c28_thisId.bParentIsCell = false;
  c28_y = c28_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_b_command_counter),
    &c28_thisId);
  sf_mex_destroy(&c28_b_command_counter);
  return c28_y;
}

static uint8_T c28_b_emlrt_marshallIn(SFc28_canblocks_extrasInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  uint8_T c28_y;
  uint8_T c28_b_u;
  (void)chartInstance;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_b_u, 1, 3, 0U, 0, 0U, 0);
  c28_y = c28_b_u;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static const mxArray *c28_c_emlrt_marshallIn
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, const mxArray
   *c28_b_setSimStateSideEffectsInfo, const char_T *c28_identifier)
{
  const mxArray *c28_y = NULL;
  emlrtMsgIdentifier c28_thisId;
  c28_y = NULL;
  c28_thisId.fIdentifier = (const char *)c28_identifier;
  c28_thisId.fParent = NULL;
  c28_thisId.bParentIsCell = false;
  sf_mex_assign(&c28_y, c28_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c28_b_setSimStateSideEffectsInfo), &c28_thisId), false);
  sf_mex_destroy(&c28_b_setSimStateSideEffectsInfo);
  return c28_y;
}

static const mxArray *c28_d_emlrt_marshallIn
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, const mxArray *c28_u,
   const emlrtMsgIdentifier *c28_parentId)
{
  const mxArray *c28_y = NULL;
  (void)chartInstance;
  (void)c28_parentId;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_duplicatearraysafe(&c28_u), false);
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_slStringInitializeDynamicBuffers
  (SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c28_init_sf_message_store_memory
  (SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c28_chart_data_browse_helper
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, int32_T c28_ssIdNumber)
{
  const mxArray *c28_mxData = NULL;
  uint8_T c28_u;
  uint8_T c28_u1;
  int32_T c28_i;
  uint8_T c28_uv[6];
  c28_mxData = NULL;
  switch (c28_ssIdNumber) {
   case 244U:
    c28_u = *chartInstance->c28_rx_comm_type;
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData", &c28_u, 3, 0U, 0U, 0U, 0),
                  false);
    break;

   case 245U:
    c28_u1 = *chartInstance->c28_rx_count;
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData", &c28_u1, 3, 0U, 0U, 0U, 0),
                  false);
    break;

   case 246U:
    for (c28_i = 0; c28_i < 6; c28_i++) {
      c28_uv[c28_i] = (*chartInstance->c28_rx_data)[c28_i];
    }

    sf_mex_assign(&c28_mxData, sf_mex_create("mxData", c28_uv, 3, 0U, 1U, 0U, 1,
      6), false);
    break;

   case 247U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_command_counter, 3, 0U, 0U, 0U, 0), false);
    break;

   case 248U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_TEMPORARY_DISCONNECT, 3, 0U, 0U, 0U, 0), false);
    break;

   case 249U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_PERMANENT_DISCONNECT, 3, 0U, 0U, 0U, 0), false);
    break;

   case 250U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_GET_CCP_VERSIONenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 251U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_EXCHANGE_IDenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 252U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_SET_MTAenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 253U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_DNLOADenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 254U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_UPLOADenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 255U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_SHORT_UPenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 256U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_GET_DAQ_SIZEenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 257U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_SET_DAQ_PTRenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 258U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_WRITE_DAQenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 259U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_START_STOPenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 260U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_SET_S_STATUSenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 261U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_GET_S_STATUSenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 262U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_START_STOP_ALLenabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 263U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_CCP_STATION_ID, 5, 0U, 0U, 0U, 0), false);
    break;

   case 264U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_DNLOAD_6enabled, 11, 0U, 0U, 0U, 0), false);
    break;

   case 267U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_SLAVE_ID_LENGTH_NOT_USED, 3, 0U, 0U, 0U, 0), false);
    break;

   case 268U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_SLAVE_ID_DATA_TYPE_NOT_USED, 3, 0U, 0U, 0U, 0), false);
    break;

   case 269U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_RESOURCE_AVAILABILITY_MASK, 3, 0U, 0U, 0U, 0), false);
    break;

   case 270U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_RESOURCE_PROTECTION_MASK, 3, 0U, 0U, 0U, 0), false);
    break;

   case 271U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_MTA_ADDRESS_EXTENSION, 3, 0U, 0U, 0U, 0), false);
    break;

   case 272U:
    sf_mex_assign(&c28_mxData, sf_mex_create("mxData",
      &chartInstance->c28_S_STATUS_QUALIFIER, 3, 0U, 0U, 0U, 0), false);
    break;
  }

  return c28_mxData;
}

static void c28_slcc_cov_call_setSlave_Version_G1WZrK4kHQSfLP1BLKd6ID_by_sim
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index,
   uint8_T c28_version)
{
  setSlave_Version_G1WZrK4kHQSfLP1BLKd6ID(c28_index, c28_version);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static void c28_slcc_cov_call_setStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index,
   uint8_T c28_address)
{
  setStation_Address_G1WZrK4kHQSfLP1BLKd6ID(c28_index, c28_address);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static void c28_slcc_cov_call_setCurrent_State_G1WZrK4kHQSfLP1BLKd6ID_by_sim
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_state)
{
  setCurrent_State_G1WZrK4kHQSfLP1BLKd6ID(c28_state);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static void c28_slcc_cov_call_c_reset_all_DAQ_lists_G1WZrK4kHQSfLP1BLKd6ID_b
  (SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  c_reset_all_DAQ_lists_G1WZrK4kHQSfLP1BLKd6ID();
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static uint8_T c28_slcc_cov_call_getStation_Address_G1WZrK4kHQSfLP1BLKd6ID_by_s
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index)
{
  uint8_T c28_out;
  c28_out = getStation_Address_G1WZrK4kHQSfLP1BLKd6ID(c28_index);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
  return c28_out;
}

static void c28_slcc_cov_call_setHandled_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_handled)
{
  setHandled_G1WZrK4kHQSfLP1BLKd6ID(c28_handled);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static void c28_slcc_cov_call_setMaster_Version_G1WZrK4kHQSfLP1BLKd6ID_by_si
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index,
   uint8_T c28_version)
{
  setMaster_Version_G1WZrK4kHQSfLP1BLKd6ID(c28_index, c28_version);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static uint32_T *c28_slcc_cov_call_getMTAPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index)
{
  uint32_T *c28_out;
  c28_out = getMTAPtr_G1WZrK4kHQSfLP1BLKd6ID(c28_index);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
  return c28_out;
}

static void c28_slcc_cov_call_c_write_uint8s_G1WZrK4kHQSfLP1BLKd6ID_by_simst
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, const uint8_T
   *c28_source, uint8_T c28_length, uint32_T *c28_address)
{
  c_write_uint8s_G1WZrK4kHQSfLP1BLKd6ID(c28_source, c28_length, c28_address);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static void c28_slcc_cov_call_c_set_element_pointer_G1WZrK4kHQSfLP1BLKd6ID_b
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_in0, uint8_T
   c28_in1, uint8_T c28_in2)
{
  c_set_element_pointer_G1WZrK4kHQSfLP1BLKd6ID(c28_in0, c28_in1, c28_in2);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static void c28_slcc_cov_call_c_start_stop_all_G1WZrK4kHQSfLP1BLKd6ID_by_sim
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_in0)
{
  c_start_stop_all_G1WZrK4kHQSfLP1BLKd6ID(c28_in0);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static void c28_slcc_cov_call_c_start_stop_G1WZrK4kHQSfLP1BLKd6ID_by_simstru
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_in0, uint8_T
   c28_in1, uint8_T c28_in2, uint8_T c28_in3, uint16_T c28_in4)
{
  c_start_stop_G1WZrK4kHQSfLP1BLKd6ID(c28_in0, c28_in1, c28_in2, c28_in3,
    c28_in4);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static void c28_slcc_cov_call_setS_Status_G1WZrK4kHQSfLP1BLKd6ID_by_simstruc
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_status)
{
  setS_Status_G1WZrK4kHQSfLP1BLKd6ID(c28_status);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static void c28_slcc_cov_call_c_write_daq_G1WZrK4kHQSfLP1BLKd6ID_by_simstruc
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_in0,
   uint32_T c28_in1)
{
  c_write_daq_G1WZrK4kHQSfLP1BLKd6ID(c28_in0, c28_in1);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static void c28_slcc_cov_call_setData_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index,
   uint8_T c28_data)
{
  setData_G1WZrK4kHQSfLP1BLKd6ID(c28_index, c28_data);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static uint8_T c28_slcc_cov_call_getSlave_Version_G1WZrK4kHQSfLP1BLKd6ID_by_sim
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index)
{
  uint8_T c28_out;
  c28_out = getSlave_Version_G1WZrK4kHQSfLP1BLKd6ID(c28_index);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
  return c28_out;
}

static uint8_T *c28_slcc_cov_call_getDataPtr_G1WZrK4kHQSfLP1BLKd6ID_by_simstruct
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_index)
{
  uint8_T *c28_out;
  c28_out = getDataPtr_G1WZrK4kHQSfLP1BLKd6ID(c28_index);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
  return c28_out;
}

static void c28_slcc_cov_call_c_read_uint8s_G1WZrK4kHQSfLP1BLKd6ID_by_simstr
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T *c28_dest,
   uint8_T c28_length, uint32_T *c28_address)
{
  c_read_uint8s_G1WZrK4kHQSfLP1BLKd6ID(c28_dest, c28_length, c28_address);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static void c28_slcc_cov_call_c_init_daq_list_G1WZrK4kHQSfLP1BLKd6ID_by_sims
  (SFc28_canblocks_extrasInstanceStruct *chartInstance, uint8_T c28_in0)
{
  c_init_daq_list_G1WZrK4kHQSfLP1BLKd6ID(c28_in0);
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
}

static uint8_T c28_slcc_cov_call_getS_Status_G1WZrK4kHQSfLP1BLKd6ID_by_simstruc
  (SFc28_canblocks_extrasInstanceStruct *chartInstance)
{
  uint8_T c28_out;
  c28_out = getS_Status_G1WZrK4kHQSfLP1BLKd6ID();
  slcovUploadCoverageSynthesisBySimstruct(chartInstance->S);
  return c28_out;
}

static uint8_T c28__u8_u16_(SFc28_canblocks_extrasInstanceStruct *chartInstance,
  uint16_T c28_b, int32_T c28_EMLOvCount_src_loc, uint32_T c28_ssid_src_loc,
  int32_T c28_offset_src_loc, int32_T c28_length_src_loc)
{
  uint8_T c28_a;
  (void)c28_EMLOvCount_src_loc;
  c28_a = (uint8_T)c28_b;
  if ((uint16_T)c28_a != c28_b) {
    sf_data_overflow_error(chartInstance->S, c28_ssid_src_loc,
      c28_offset_src_loc, c28_length_src_loc);
  }

  return c28_a;
}

static void init_dsm_address_info(SFc28_canblocks_extrasInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc28_canblocks_extrasInstanceStruct
  *chartInstance)
{
  chartInstance->c28_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c28_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c28_rx_comm_type = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c28_rx_count = (uint8_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c28_rx_data = (uint8_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c28_canblocks_extras_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2564724966U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1993380573U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1068266726U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4014728443U);
}

mxArray *sf_c28_canblocks_extras_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c28_canblocks_extras_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("custom_code");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c28_canblocks_extras_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c28_canblocks_extras(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiB+wMTAwAakOYCYiQECWKF8RiBmhtIQcRa4uAIQl1QWpILEi4uSPVOAdF5iLpi"
    "fWFrhmZeWDzbfggFhPhsW8xmRzOeEikMAhwNF+h/kgfU7IOlnwaKfH0m/AJSfnJ+bm5iXEp+cX5"
    "pXkloE9gcsvMj3jwJl/oHaH0DAP3Jo/gHxM4vjE5NLMstS45ONLOKTE/OScvKTs4vjUytKihKLG"
    "ajkPyWq+M+DgP/E0fwnDvEfVo/B/AUAH8EtAg=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c28_canblocks_extras_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sFnFE54lwY6ArGgtAUi46BC";
}

static void sf_opaque_initialize_c28_canblocks_extras(void *chartInstanceVar)
{
  initialize_params_c28_canblocks_extras((SFc28_canblocks_extrasInstanceStruct*)
    chartInstanceVar);
  initialize_c28_canblocks_extras((SFc28_canblocks_extrasInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c28_canblocks_extras(void *chartInstanceVar)
{
  enable_c28_canblocks_extras((SFc28_canblocks_extrasInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c28_canblocks_extras(void *chartInstanceVar)
{
  disable_c28_canblocks_extras((SFc28_canblocks_extrasInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c28_canblocks_extras(void *chartInstanceVar)
{
  sf_gateway_c28_canblocks_extras((SFc28_canblocks_extrasInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c28_canblocks_extras(SimStruct* S)
{
  return get_sim_state_c28_canblocks_extras
    ((SFc28_canblocks_extrasInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c28_canblocks_extras(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c28_canblocks_extras((SFc28_canblocks_extrasInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c28_canblocks_extras(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc28_canblocks_extrasInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_canblocks_extras_optimization_info();
    }

    finalize_c28_canblocks_extras((SFc28_canblocks_extrasInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc28_canblocks_extras((SFc28_canblocks_extrasInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c28_canblocks_extras(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  sf_warn_if_symbolic_dimension_param_changed(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c28_canblocks_extras((SFc28_canblocks_extrasInstanceStruct*)
      sf_get_chart_instance_ptr(S));
    initSimStructsc28_canblocks_extras((SFc28_canblocks_extrasInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c28_canblocks_extras_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [28] = {
    "eNrtXE9PG0cUXwNJgQAhUapeqijKpT2mCUX0VMDGjVUINDZEvXQ17A72yLOzm5lZQ75B1VM+QA+",
    "V+iF6bD9Cv0ClqKcee2irHvtmvf7DsGsDxhDSt9J6GfP+zHvzm3lv3u7aKVS2HDgW4Py36jg34T",
    "oN54TTPm6k7ULf2f5+yvkobf8IRCIOdogkgXIGHoIE9DlVIY81C0VFHISZZEwcUEmFB7RRKHWeN",
    "MWCmDPRLMfCM/LUiwbzGtVGGHN/HXiJvy34K5AWxXoH5JSYpJ4uU+rrhgzjeqPMSb3bY6kPiw3q",
    "NVUcDDJBUV2NI9MttRVzzSJON46oVxFKE+ix6vWtqommRX2Ua6axVFU7hGEQcUZEprUNoqo0Agd",
    "ruhv58LkdazDKJvMaROp12iAtqjZZM5EZCmrLZAr+sc8E0aFkhG8EvGgYT/Zth0N/tkKf8gEOgb",
    "6tS0qaUciEzh//ahks3RBkn9MS3Y/r+dKq9GVsBn+P0UMqc/12UAxbVJI63Ra5ShOHbBwlo9VFy",
    "UkyzQK6R+SaB+OnqJ+LXkCOqhIYJ1oDjjwymhhZUTXJWuDeXGlxUDHIHDZl4qA92GoYWSJto0UH",
    "jUJXWtkTRcK5yiWrhdEmbVGeSC0RTQaTtaVm00UyjEgdUOuDkw3Ei6Hw2Ymx8GKlw6AIcCttbj6",
    "DlSK7cz2yitBUHhCPZs1b5TWoH3MKhsLKpBN1GUJ9psxoDaFKx3QYlaMOYlE6DGUTDB0w7XsmmD",
    "HIJQxUHbwP2N1VAPNBZMb7Q+k66/wjp7fOz51inb+d8jnW9eM+OYUMOU7f1dY7M3GcftLSOwHfF",
    "AqFhG+1j2/e0jNl8Rm6RTh///vF9z9989uvfzW/++fhZ388H6a/cEJ/Ifnb8L2ePFtcXEjbH3YW",
    "oC48WydQYWif9vVrKkP+B33yF9O2KovyxqdL/PDr5TX5RV2v7bKl5fViIu/NxOD+Tlr97Xz/wKy",
    "Er6JkXVPSq/hpwDZtErfDmJG/0tffm0P8MZN+3z6mV0fifyNWbTxk+eu25S/T9sIgIMJ3vTA2i8",
    "YxHJ/fngej2ZPq3xliz33LnvtJ/HMJRLMWdb3HK65HxD4PAWMuPdKSKOeC7Ht4IfadB99gX6ZhC",
    "6dcTwbN57PyOcj3VvAV/of2nSY+T56Tz7kmfKPad9Y8ZZS8xl7fHIt+cQQ946bvXF8Xz5bvzKbt",
    "e3D2NllJqg85s+rKnR4g916G3Pm0vdQn12TdTlJpoBDGjexqpdRz8zN7s3SafGHRGp/FdJfPYRv",
    "t7oEW0JvURwbkVRMZ/e/INfH9SyaObStraZ7VOUx5oiJ8epS2S+x4KaVrclVLJuon4nqWXdOWXa",
    "a9rRtUwtCchv89i9+0Y9jjr7i1EfOKP38ekf/zUeYd+u18frsIf48jf7xr6b2bzl9NzIrhrvm+p",
    "Er15OE8xnmM8/jy5/E543AxlpIK7SZVciPnl8LZ8hOcv4jDs8ST9y29pu25EEOodgnnbmntK5cz",
    "leSYRt63Tj4enSvA43WK0/UBcRrnOc7zccabWUvvbDvePCXC552bgIhDxOG418U7lt47bRxuEQX",
    "j3ilAOLh/wf0L+u1tjiczlt6Zdn6zVVvb0dLBeII4vBwcLlh6F5L9y6FkmrqJ39P7w4+m8nE4iT",
    "jEOIJ+G8lvWfzGb08euzVc9y6rbmOqNpTTwJQQk0dUk0dKcf3DeYx+Q7+96/dPYP3TRGr4DCNTv",
    "Mb9B+Jw3Dics/TOWTjsyPnhZj4ObyAOMY6g39Bv6Ldrv9/9ZBn3u+OIs7csvbfS596SJ2VihfVm",
    "zPeuDIederNPXuJ9S4wjWDe9wvl7HpxCHEne5cZ5i/MW4+71qffVM95bwvwPcXjZz1HW2/Gj++A",
    "L4hBxOG4czlt65532c/vE7z72gvd9MZ9Bv+H+7Z1a9zJ/78ZlgmlTfkleVcL4i/H3SuqA9Yx6NL",
    "4vN/z3OWw/jPv3P/4DM4LHaA==",
    ""
  };

  static char newstr [1977] = "";
  newstr[0] = '\0';
  for (i = 0; i < 28; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c28_canblocks_extras(SimStruct *S)
{
  const char* newstr = sf_c28_canblocks_extras_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2623010274U));
  ssSetChecksum1(S,(3504168631U));
  ssSetChecksum2(S,(4136266740U));
  ssSetChecksum3(S,(1390950690U));
}

static void mdlRTW_c28_canblocks_extras(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c28_canblocks_extras(SimStruct *S)
{
  SFc28_canblocks_extrasInstanceStruct *chartInstance;
  chartInstance = (SFc28_canblocks_extrasInstanceStruct *)utMalloc(sizeof
    (SFc28_canblocks_extrasInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc28_canblocks_extrasInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c28_canblocks_extras;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c28_canblocks_extras;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c28_canblocks_extras;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c28_canblocks_extras;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c28_canblocks_extras;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c28_canblocks_extras;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c28_canblocks_extras;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c28_canblocks_extras;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c28_canblocks_extras;
  chartInstance->chartInfo.mdlStart = mdlStart_c28_canblocks_extras;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c28_canblocks_extras;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0,
    chartInstance->c28_JITStateAnimation,
    chartInstance->c28_JITTransitionAnimation);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_start_c28_canblocks_extras(chartInstance);
}

void c28_canblocks_extras_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c28_canblocks_extras(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c28_canblocks_extras(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c28_canblocks_extras(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c28_canblocks_extras_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
