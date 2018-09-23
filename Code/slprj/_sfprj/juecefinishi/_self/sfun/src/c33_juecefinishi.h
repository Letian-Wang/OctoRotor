#ifndef __c33_juecefinishi_h__
#define __c33_juecefinishi_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc33_juecefinishiInstanceStruct
#define typedef_SFc33_juecefinishiInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c33_sfEvent;
  boolean_T c33_isStable;
  boolean_T c33_doneDoubleBufferReInit;
  uint8_T c33_is_active_c33_juecefinishi;
  real_T c33_Xt[3];
  boolean_T c33_Xt_not_empty;
  real_T c33_Vt[3];
  boolean_T c33_Vt_not_empty;
  real_T c33_Mt[36];
  boolean_T c33_Mt_not_empty;
  real_T c33_a_last[3];
  boolean_T c33_a_last_not_empty;
} SFc33_juecefinishiInstanceStruct;

#endif                                 /*typedef_SFc33_juecefinishiInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c33_juecefinishi_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c33_juecefinishi_get_check_sum(mxArray *plhs[]);
extern void c33_juecefinishi_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
