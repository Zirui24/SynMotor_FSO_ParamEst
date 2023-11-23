#ifndef __c28_canblocks_extras_h__
#define __c28_canblocks_extras_h__

/* Type Definitions */
#ifndef typedef_SFc28_canblocks_extrasInstanceStruct
#define typedef_SFc28_canblocks_extrasInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c28_sfEvent;
  boolean_T c28_doneDoubleBufferReInit;
  uint8_T c28_is_active_c28_canblocks_extras;
  uint8_T c28_is_c28_canblocks_extras;
  uint8_T c28_JITStateAnimation[3];
  uint8_T c28_command_counter;
  uint8_T c28_TEMPORARY_DISCONNECT;
  uint8_T c28_PERMANENT_DISCONNECT;
  boolean_T c28_GET_CCP_VERSIONenabled;
  boolean_T c28_EXCHANGE_IDenabled;
  boolean_T c28_SET_MTAenabled;
  boolean_T c28_DNLOADenabled;
  boolean_T c28_UPLOADenabled;
  boolean_T c28_SHORT_UPenabled;
  boolean_T c28_GET_DAQ_SIZEenabled;
  boolean_T c28_SET_DAQ_PTRenabled;
  boolean_T c28_WRITE_DAQenabled;
  boolean_T c28_START_STOPenabled;
  boolean_T c28_SET_S_STATUSenabled;
  boolean_T c28_GET_S_STATUSenabled;
  boolean_T c28_START_STOP_ALLenabled;
  uint16_T c28_CCP_STATION_ID;
  boolean_T c28_DNLOAD_6enabled;
  uint8_T c28_SLAVE_ID_LENGTH_NOT_USED;
  uint8_T c28_SLAVE_ID_DATA_TYPE_NOT_USED;
  uint8_T c28_RESOURCE_AVAILABILITY_MASK;
  uint8_T c28_RESOURCE_PROTECTION_MASK;
  uint8_T c28_MTA_ADDRESS_EXTENSION;
  uint8_T c28_S_STATUS_QUALIFIER;
  uint8_T c28_JITTransitionAnimation[101];
  void *c28_RuntimeVar;
  uint8_T c28_doSetSimStateSideEffects;
  const mxArray *c28_setSimStateSideEffectsInfo;
  uint32_T c28_mlFcnLineNumber;
  void *c28_fcnDataPtrs[2];
  char_T *c28_dataNames[2];
  uint32_T c28_numFcnVars;
  uint32_T c28_ssIds[2];
  uint32_T c28_statuses[2];
  void *c28_outMexFcns[2];
  void *c28_inMexFcns[2];
  CovrtStateflowInstance *c28_covrtInstance;
  void *c28_fEmlrtCtx;
  uint8_T *c28_rx_comm_type;
  uint8_T *c28_rx_count;
  uint8_T (*c28_rx_data)[6];
} SFc28_canblocks_extrasInstanceStruct;

#endif                                 /*typedef_SFc28_canblocks_extrasInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c28_canblocks_extras_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c28_canblocks_extras_get_check_sum(mxArray *plhs[]);
extern void c28_canblocks_extras_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
