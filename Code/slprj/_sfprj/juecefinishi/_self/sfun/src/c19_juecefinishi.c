/* Include files */

#include <stddef.h>
#include "blas.h"
#include "juecefinishi_sfun.h"
#include "c19_juecefinishi.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "juecefinishi_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c19_debug_family_names[15] = { "a11_x", "a11_y", "a11_z",
  "tau_x", "tau_y", "tau_z", "tau_dx", "tau_dy", "tau_dz", "nargin", "nargout",
  "u1", "u2", "u3", "y" };

static const char * c19_b_debug_family_names[6] = { "jieguo", "nargin",
  "nargout", "x", "a", "y" };

/* Function Declarations */
static void initialize_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance);
static void initialize_params_c19_juecefinishi(SFc19_juecefinishiInstanceStruct *
  chartInstance);
static void enable_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance);
static void disable_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance);
static void c19_update_debugger_state_c19_juecefinishi
  (SFc19_juecefinishiInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c19_juecefinishi
  (SFc19_juecefinishiInstanceStruct *chartInstance);
static void set_sim_state_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_st);
static void finalize_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance);
static void sf_gateway_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance);
static void initSimStructsc19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance);
static real_T c19_sat(SFc19_juecefinishiInstanceStruct *chartInstance, real_T
                      c19_x, real_T c19_a);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c19_y, const char_T *c19_identifier, real_T c19_b_y[3]);
static void c19_b_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId,
  real_T c19_y[3]);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_c_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static void c19_info_helper(const mxArray **c19_info);
static const mxArray *c19_emlrt_marshallOut(const char * c19_u);
static const mxArray *c19_b_emlrt_marshallOut(const uint32_T c19_u);
static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_d_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static uint8_T c19_e_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_b_is_active_c19_juecefinishi, const char_T *
  c19_identifier);
static uint8_T c19_f_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void init_dsm_address_info(SFc19_juecefinishiInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance)
{
  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_is_active_c19_juecefinishi = 0U;
}

static void initialize_params_c19_juecefinishi(SFc19_juecefinishiInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c19_update_debugger_state_c19_juecefinishi
  (SFc19_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c19_juecefinishi
  (SFc19_juecefinishiInstanceStruct *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  int32_T c19_i0;
  real_T c19_u[3];
  const mxArray *c19_b_y = NULL;
  uint8_T c19_hoistedGlobal;
  uint8_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  real_T (*c19_d_y)[3];
  c19_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellmatrix(2, 1), false);
  for (c19_i0 = 0; c19_i0 < 3; c19_i0++) {
    c19_u[c19_i0] = (*c19_d_y)[c19_i0];
  }

  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_hoistedGlobal = chartInstance->c19_is_active_c19_juecefinishi;
  c19_b_u = c19_hoistedGlobal;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 1, c19_c_y);
  sf_mex_assign(&c19_st, c19_y, false);
  return c19_st;
}

static void set_sim_state_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_st)
{
  const mxArray *c19_u;
  real_T c19_dv0[3];
  int32_T c19_i1;
  real_T (*c19_y)[3];
  c19_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c19_doneDoubleBufferReInit = true;
  c19_u = sf_mex_dup(c19_st);
  c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 0)), "y",
                       c19_dv0);
  for (c19_i1 = 0; c19_i1 < 3; c19_i1++) {
    (*c19_y)[c19_i1] = c19_dv0[c19_i1];
  }

  chartInstance->c19_is_active_c19_juecefinishi = c19_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 1)),
     "is_active_c19_juecefinishi");
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_juecefinishi(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance)
{
  real_T c19_hoistedGlobal;
  real_T c19_b_hoistedGlobal;
  real_T c19_c_hoistedGlobal;
  real_T c19_u1;
  real_T c19_u2;
  real_T c19_u3;
  uint32_T c19_debug_family_var_map[15];
  real_T c19_a11_x;
  real_T c19_a11_y;
  real_T c19_a11_z;
  real_T c19_tau_x;
  real_T c19_tau_y;
  real_T c19_tau_z;
  real_T c19_tau_dx;
  real_T c19_tau_dy;
  real_T c19_tau_dz;
  real_T c19_nargin = 3.0;
  real_T c19_nargout = 1.0;
  real_T c19_y[3];
  real_T c19_b_tau_dx[3];
  int32_T c19_i2;
  int32_T c19_i3;
  int32_T c19_i4;
  real_T *c19_b_u1;
  real_T *c19_b_u2;
  real_T *c19_b_u3;
  real_T (*c19_b_y)[3];
  c19_b_u3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c19_b_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c19_b_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c19_b_u1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 18U, chartInstance->c19_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c19_b_u1, 0U);
  chartInstance->c19_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c19_sfEvent);
  c19_hoistedGlobal = *c19_b_u1;
  c19_b_hoistedGlobal = *c19_b_u2;
  c19_c_hoistedGlobal = *c19_b_u3;
  c19_u1 = c19_hoistedGlobal;
  c19_u2 = c19_b_hoistedGlobal;
  c19_u3 = c19_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c19_debug_family_names,
    c19_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_a11_x, 0U, c19_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_a11_y, 1U, c19_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_a11_z, 2U, c19_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_tau_x, 3U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_tau_y, 4U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_tau_z, 5U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_tau_dx, 6U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_tau_dy, 7U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_tau_dz, 8U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 9U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 10U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_u1, 11U, c19_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_u2, 12U, c19_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_u3, 13U, c19_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_y, 14U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 9);
  c19_a11_x = 60.0;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 10);
  c19_a11_y = 60.0;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 11);
  c19_a11_z = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 15);
  c19_tau_x = -c19_u1;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 16);
  c19_tau_y = -c19_u2;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 17);
  c19_tau_z = -c19_u3;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 22);
  c19_tau_dx = c19_sat(chartInstance, c19_tau_x, 60.0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 23);
  c19_tau_dy = c19_sat(chartInstance, c19_tau_y, 60.0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 24);
  c19_tau_dz = c19_sat(chartInstance, c19_tau_z, 10.0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 25);
  c19_b_tau_dx[0] = c19_tau_dx;
  c19_b_tau_dx[1] = c19_tau_dy;
  c19_b_tau_dx[2] = c19_tau_dz;
  for (c19_i2 = 0; c19_i2 < 3; c19_i2++) {
    c19_y[c19_i2] = c19_b_tau_dx[c19_i2];
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, -25);
  _SFD_SYMBOL_SCOPE_POP();
  for (c19_i3 = 0; c19_i3 < 3; c19_i3++) {
    (*c19_b_y)[c19_i3] = c19_y[c19_i3];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c19_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_juecefinishiMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c19_i4 = 0; c19_i4 < 3; c19_i4++) {
    _SFD_DATA_RANGE_CHECK((*c19_b_y)[c19_i4], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c19_b_u2, 2U);
  _SFD_DATA_RANGE_CHECK(*c19_b_u3, 3U);
}

static void initSimStructsc19_juecefinishi(SFc19_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c19_sat(SFc19_juecefinishiInstanceStruct *chartInstance, real_T
                      c19_x, real_T c19_a)
{
  real_T c19_y;
  uint32_T c19_debug_family_var_map[6];
  real_T c19_jieguo;
  real_T c19_nargin = 2.0;
  real_T c19_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c19_b_debug_family_names,
    c19_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_jieguo, 0U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 1U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 2U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_x, 3U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_a, 4U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_y, 5U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c19_sfEvent, 5);
  if (CV_SCRIPT_IF(0, 0, c19_x > c19_a)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c19_sfEvent, 6);
    c19_jieguo = c19_a;
  } else {
    _SFD_SCRIPT_CALL(0U, chartInstance->c19_sfEvent, 7);
    if (CV_SCRIPT_IF(0, 1, c19_x < -c19_a)) {
      _SFD_SCRIPT_CALL(0U, chartInstance->c19_sfEvent, 8);
      c19_jieguo = -c19_a;
    } else {
      _SFD_SCRIPT_CALL(0U, chartInstance->c19_sfEvent, 10);
      c19_jieguo = c19_x;
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c19_sfEvent, 14);
  c19_y = c19_jieguo;
  _SFD_SCRIPT_CALL(0U, chartInstance->c19_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  return c19_y;
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber)
{
  (void)c19_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c19_chartNumber, c19_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\\\Users\\\\StarFly\\\\Desktop\\\\\xb6\xe0\xd0\xfd\xd2\xed\xb7\xc9\xd0\xd0\xc6\xf7\xc9\xe8\xbc\xc6\xd3\xeb\xbf\xd8\xd6\xc6\\\\\xcc\xe1\xbd\xbb\\\\\xb3\xcc\xd0\xf2\\\\sat.m"));
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i5;
  real_T c19_b_inData[3];
  int32_T c19_i6;
  real_T c19_u[3];
  const mxArray *c19_y = NULL;
  SFc19_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc19_juecefinishiInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i5 = 0; c19_i5 < 3; c19_i5++) {
    c19_b_inData[c19_i5] = (*(real_T (*)[3])c19_inData)[c19_i5];
  }

  for (c19_i6 = 0; c19_i6 < 3; c19_i6++) {
    c19_u[c19_i6] = c19_b_inData[c19_i6];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c19_y, const char_T *c19_identifier, real_T c19_b_y[3])
{
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_y), &c19_thisId, c19_b_y);
  sf_mex_destroy(&c19_y);
}

static void c19_b_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId,
  real_T c19_y[3])
{
  real_T c19_dv1[3];
  int32_T c19_i7;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), c19_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c19_i7 = 0; c19_i7 < 3; c19_i7++) {
    c19_y[c19_i7] = c19_dv1[c19_i7];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_y;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_b_y[3];
  int32_T c19_i8;
  SFc19_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc19_juecefinishiInstanceStruct *)chartInstanceVoid;
  c19_y = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_y), &c19_thisId, c19_b_y);
  sf_mex_destroy(&c19_y);
  for (c19_i8 = 0; c19_i8 < 3; c19_i8++) {
    (*(real_T (*)[3])c19_outData)[c19_i8] = c19_b_y[c19_i8];
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc19_juecefinishiInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_c_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d0, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_nargout;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc19_juecefinishiInstanceStruct *)chartInstanceVoid;
  c19_nargout = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_nargout),
    &c19_thisId);
  sf_mex_destroy(&c19_nargout);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

const mxArray *sf_c19_juecefinishi_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  sf_mex_assign(&c19_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c19_info_helper(&c19_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c19_nameCaptureInfo);
  return c19_nameCaptureInfo;
}

static void c19_info_helper(const mxArray **c19_info)
{
  const mxArray *c19_rhs0 = NULL;
  const mxArray *c19_lhs0 = NULL;
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("sat"), "name", "name", 0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[EW]C:/Users/StarFly/Desktop/\\xe5\\xa4\\x9a\\xe6\\x97\\x8b\\xe7\\xbf\\xbc\\xe9\\xa3\\x9e\\xe8\\xa1\\x8c\\xe5\\x99\\xa8\\xe8\\xae\\xbe\\xe8\\xae\\xa1\\xe"
    "4\\xb8\\x8e\\xe6\\x8e\\xa7\\xe5\\x88\\xb6/\\xe6\\x8f\\x90\\xe4\\xba\\xa4/\\xe7\\xa8\\x8b\\xe5\\xba\\x8f/sat.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1530546328U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c19_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs0), "lhs", "lhs",
                  0);
  sf_mex_destroy(&c19_rhs0);
  sf_mex_destroy(&c19_lhs0);
}

static const mxArray *c19_emlrt_marshallOut(const char * c19_u)
{
  const mxArray *c19_y = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c19_u)), false);
  return c19_y;
}

static const mxArray *c19_b_emlrt_marshallOut(const uint32_T c19_u)
{
  const mxArray *c19_y = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 7, 0U, 0U, 0U, 0), false);
  return c19_y;
}

static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc19_juecefinishiInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static int32_T c19_d_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i9;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i9, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i9;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc19_juecefinishiInstanceStruct *)chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static uint8_T c19_e_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_b_is_active_c19_juecefinishi, const char_T *
  c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_is_active_c19_juecefinishi), &c19_thisId);
  sf_mex_destroy(&c19_b_is_active_c19_juecefinishi);
  return c19_y;
}

static uint8_T c19_f_emlrt_marshallIn(SFc19_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void init_dsm_address_info(SFc19_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
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

void sf_c19_juecefinishi_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3593875493U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2229811934U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(445836505U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(48012335U);
}

mxArray *sf_c19_juecefinishi_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("LHuk9MuT7alnF2sIOz8oiG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c19_juecefinishi_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c19_juecefinishi_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c19_juecefinishi(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c19_juecefinishi\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_juecefinishi_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_juecefinishiInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc19_juecefinishiInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _juecefinishiMachineNumber_,
           19,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_juecefinishiMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_juecefinishiMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _juecefinishiMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"u2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"u3");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,358);
        _SFD_CV_INIT_SCRIPT(0,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"sat",0,-1,184);
        _SFD_CV_INIT_SCRIPT_IF(0,0,79,85,100,162);
        _SFD_CV_INIT_SCRIPT_IF(0,1,105,112,132,158);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)
            c19_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c19_u1;
          real_T *c19_u2;
          real_T *c19_u3;
          real_T (*c19_y)[3];
          c19_u3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c19_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c19_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c19_u1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c19_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c19_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c19_u2);
          _SFD_SET_DATA_VALUE_PTR(3U, c19_u3);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _juecefinishiMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "SGiUJpZMjrJqYLRN0EYNJC";
}

static void sf_opaque_initialize_c19_juecefinishi(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc19_juecefinishiInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c19_juecefinishi((SFc19_juecefinishiInstanceStruct*)
    chartInstanceVar);
  initialize_c19_juecefinishi((SFc19_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c19_juecefinishi(void *chartInstanceVar)
{
  enable_c19_juecefinishi((SFc19_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c19_juecefinishi(void *chartInstanceVar)
{
  disable_c19_juecefinishi((SFc19_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c19_juecefinishi(void *chartInstanceVar)
{
  sf_gateway_c19_juecefinishi((SFc19_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c19_juecefinishi(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c19_juecefinishi
    ((SFc19_juecefinishiInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_juecefinishi();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c19_juecefinishi(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c19_juecefinishi();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c19_juecefinishi((SFc19_juecefinishiInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c19_juecefinishi(SimStruct* S)
{
  return sf_internal_get_sim_state_c19_juecefinishi(S);
}

static void sf_opaque_set_sim_state_c19_juecefinishi(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c19_juecefinishi(S, st);
}

static void sf_opaque_terminate_c19_juecefinishi(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_juecefinishiInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_juecefinishi_optimization_info();
    }

    finalize_c19_juecefinishi((SFc19_juecefinishiInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_juecefinishi((SFc19_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_juecefinishi(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c19_juecefinishi((SFc19_juecefinishiInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_juecefinishi_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,19,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,19);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,19,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(121770368U));
  ssSetChecksum1(S,(1960557667U));
  ssSetChecksum2(S,(3129942020U));
  ssSetChecksum3(S,(2790619775U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c19_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_juecefinishi(SimStruct *S)
{
  SFc19_juecefinishiInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc19_juecefinishiInstanceStruct *)utMalloc(sizeof
    (SFc19_juecefinishiInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc19_juecefinishiInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c19_juecefinishi;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c19_juecefinishi;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c19_juecefinishi;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c19_juecefinishi;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c19_juecefinishi;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_juecefinishi;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_juecefinishi;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_juecefinishi;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_juecefinishi;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_juecefinishi;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c19_juecefinishi;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c19_juecefinishi_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_juecefinishi(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_juecefinishi(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_juecefinishi(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_juecefinishi_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
