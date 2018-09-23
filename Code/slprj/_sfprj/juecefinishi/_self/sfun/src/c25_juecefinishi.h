#ifndef __c25_juecefinishi_h__
#define __c25_juecefinishi_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc25_juecefinishiInstanceStruct
#define typedef_SFc25_juecefinishiInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c25_sfEvent;
  boolean_T c25_isStable;
  boolean_T c25_doneDoubleBufferReInit;
  uint8_T c25_is_active_c25_juecefinishi;
  real_T c25_k;
  boolean_T c25_k_not_empty;
  real_T c25_j;
  boolean_T c25_j_not_empty;
  real_T c25_i;
  boolean_T c25_i_not_empty;
  real_T c25_P_home[3];
  boolean_T c25_P_home_not_empty;
  real_T c25_P_wp_cur[3];
  boolean_T c25_P_wp_cur_not_empty;
  real_T c25_t_home;
  boolean_T c25_t_home_not_empty;
} SFc25_juecefinishiInstanceStruct;

#endif                                 /*typedef_SFc25_juecefinishiInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c25_juecefinishi_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c25_juecefinishi_get_check_sum(mxArray *plhs[]);
extern void c25_juecefinishi_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
