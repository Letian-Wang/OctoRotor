#ifndef __c32_juecefinishi_h__
#define __c32_juecefinishi_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc32_juecefinishiInstanceStruct
#define typedef_SFc32_juecefinishiInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c32_sfEvent;
  boolean_T c32_isStable;
  boolean_T c32_doneDoubleBufferReInit;
  uint8_T c32_is_active_c32_juecefinishi;
} SFc32_juecefinishiInstanceStruct;

#endif                                 /*typedef_SFc32_juecefinishiInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c32_juecefinishi_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c32_juecefinishi_get_check_sum(mxArray *plhs[]);
extern void c32_juecefinishi_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
