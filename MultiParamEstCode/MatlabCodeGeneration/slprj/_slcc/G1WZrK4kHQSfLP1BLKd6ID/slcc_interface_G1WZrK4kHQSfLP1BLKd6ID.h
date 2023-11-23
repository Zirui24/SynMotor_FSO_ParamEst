#include "customcode_G1WZrK4kHQSfLP1BLKd6ID.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern const char_T *get_dll_checksum_G1WZrK4kHQSfLP1BLKd6ID(void);
DLL_EXPORT_CC extern uint8_T getUINT8arg_G1WZrK4kHQSfLP1BLKd6ID(const struct mxArray_tag *in0[], int32_T in1);
DLL_EXPORT_CC extern uint32_T getUINT32arg_G1WZrK4kHQSfLP1BLKd6ID(const struct mxArray_tag *in0[], int32_T in1);
DLL_EXPORT_CC extern uint64_T getUINT64arg_G1WZrK4kHQSfLP1BLKd6ID(const struct mxArray_tag *in0[], int32_T in1);
DLL_EXPORT_CC extern void setUINT8arg_G1WZrK4kHQSfLP1BLKd6ID(struct mxArray_tag *in0[], int32_T in1, uint8_T in2);
DLL_EXPORT_CC extern void setUINT32arg_G1WZrK4kHQSfLP1BLKd6ID(struct mxArray_tag *in0[], int32_T in1, uint32_T in2);
DLL_EXPORT_CC extern void setUINT64arg_G1WZrK4kHQSfLP1BLKd6ID(struct mxArray_tag *in0[], int32_T in1, uint64_T in2);
DLL_EXPORT_CC extern void setMTA_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index, uint32_T data);
DLL_EXPORT_CC extern void setStation_Address_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index, uint8_T address);
DLL_EXPORT_CC extern void setSlave_Version_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index, uint8_T version);
DLL_EXPORT_CC extern void setMaster_Version_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index, uint8_T version);
DLL_EXPORT_CC extern void setS_Status_G1WZrK4kHQSfLP1BLKd6ID(uint8_T status);
DLL_EXPORT_CC extern void setData_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index, uint8_T data);
DLL_EXPORT_CC extern void setHandled_G1WZrK4kHQSfLP1BLKd6ID(uint8_T handled);
DLL_EXPORT_CC extern void setCurrent_State_G1WZrK4kHQSfLP1BLKd6ID(uint8_T state);
DLL_EXPORT_CC extern uint32_T getMTA_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index);
DLL_EXPORT_CC extern uint8_T getStation_Address_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index);
DLL_EXPORT_CC extern uint8_T getSlave_Version_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index);
DLL_EXPORT_CC extern uint8_T getMaster_Version_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index);
DLL_EXPORT_CC extern uint8_T getS_Status_G1WZrK4kHQSfLP1BLKd6ID(void);
DLL_EXPORT_CC extern uint8_T getData_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index);
DLL_EXPORT_CC extern uint8_T getHandled_G1WZrK4kHQSfLP1BLKd6ID(void);
DLL_EXPORT_CC extern uint8_T getCurrent_State_G1WZrK4kHQSfLP1BLKd6ID(void);
DLL_EXPORT_CC extern uint32_T *getMTAPtr_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index);
DLL_EXPORT_CC extern uint8_T *getDataPtr_G1WZrK4kHQSfLP1BLKd6ID(uint8_T index);
DLL_EXPORT_CC extern void c_read_uint8s_G1WZrK4kHQSfLP1BLKd6ID(uint8_T *dest, uint8_T length, uint32_T *address);
DLL_EXPORT_CC extern void c_write_uint8s_G1WZrK4kHQSfLP1BLKd6ID(const uint8_T *source, uint8_T length, uint32_T *address);
DLL_EXPORT_CC extern uint8_T c_move_G1WZrK4kHQSfLP1BLKd6ID(uint32_T st_addr, uint32_T end_addr, uint32_T to_move);
DLL_EXPORT_CC extern void c_init_daq_list_G1WZrK4kHQSfLP1BLKd6ID(uint8_T in0);
DLL_EXPORT_CC extern void c_set_element_pointer_G1WZrK4kHQSfLP1BLKd6ID(uint8_T in0, uint8_T in1, uint8_T in2);
DLL_EXPORT_CC extern void c_write_daq_G1WZrK4kHQSfLP1BLKd6ID(uint8_T in0, uint32_T in1);
DLL_EXPORT_CC extern void c_start_stop_G1WZrK4kHQSfLP1BLKd6ID(uint8_T in0, uint8_T in1, uint8_T in2, uint8_T in3, uint16_T in4);
DLL_EXPORT_CC extern void c_fire_DAQs_G1WZrK4kHQSfLP1BLKd6ID(uint8_T in0);
DLL_EXPORT_CC extern void c_start_stop_all_G1WZrK4kHQSfLP1BLKd6ID(uint8_T in0);
DLL_EXPORT_CC extern void c_reset_all_DAQ_lists_G1WZrK4kHQSfLP1BLKd6ID(void);
DLL_EXPORT_CC extern void c_reset_single_DAQ_list_G1WZrK4kHQSfLP1BLKd6ID(uint8_T in0);
DLL_EXPORT_CC extern uint64_T getPointerArg_G1WZrK4kHQSfLP1BLKd6ID(const struct mxArray_tag *in0[], int32_T in1);
DLL_EXPORT_CC extern void setPointerArg_G1WZrK4kHQSfLP1BLKd6ID(struct mxArray_tag *in0[], int32_T in1, uint64_T in2);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

