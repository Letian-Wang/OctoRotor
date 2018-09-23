/* Include files */

#include <stddef.h>
#include "blas.h"
#include "juecefinishi_sfun.h"
#include "c16_juecefinishi.h"
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
static const char * c16_debug_family_names[26] = { "Kph_x", "a1_x", "Kph_y",
  "a1_y", "Kpz", "a4", "Phd_x", "Phd_y", "Pzd", "Ph_x", "Vh_x", "Ph_y", "Vh_y",
  "Pz", "Vz", "Vhd_x", "evh_x", "Vhd_y", "evh_y", "Vzd", "evz", "nargin",
  "nargout", "u1", "u2", "y" };

static const char * c16_b_debug_family_names[6] = { "jieguo", "nargin",
  "nargout", "x", "a", "y" };

/* Function Declarations */
static void initialize_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance);
static void initialize_params_c16_juecefinishi(SFc16_juecefinishiInstanceStruct *
  chartInstance);
static void enable_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance);
static void disable_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance);
static void c16_update_debugger_state_c16_juecefinishi
  (SFc16_juecefinishiInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c16_juecefinishi
  (SFc16_juecefinishiInstanceStruct *chartInstance);
static void set_sim_state_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_st);
static void finalize_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance);
static void sf_gateway_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance);
static void initSimStructsc16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance);
static real_T c16_sat(SFc16_juecefinishiInstanceStruct *chartInstance, real_T
                      c16_x, real_T c16_a);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c16_y, const char_T *c16_identifier, real_T c16_b_y[3]);
static void c16_b_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[3]);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_c_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static void c16_info_helper(const mxArray **c16_info);
static const mxArray *c16_emlrt_marshallOut(const char * c16_u);
static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u);
static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_d_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static uint8_T c16_e_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_juecefinishi, const char_T *
  c16_identifier);
static uint8_T c16_f_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void init_dsm_address_info(SFc16_juecefinishiInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c16_is_active_c16_juecefinishi = 0U;
}

static void initialize_params_c16_juecefinishi(SFc16_juecefinishiInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c16_update_debugger_state_c16_juecefinishi
  (SFc16_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c16_juecefinishi
  (SFc16_juecefinishiInstanceStruct *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  int32_T c16_i0;
  real_T c16_u[3];
  const mxArray *c16_b_y = NULL;
  uint8_T c16_hoistedGlobal;
  uint8_T c16_b_u;
  const mxArray *c16_c_y = NULL;
  real_T (*c16_d_y)[3];
  c16_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellmatrix(2, 1), false);
  for (c16_i0 = 0; c16_i0 < 3; c16_i0++) {
    c16_u[c16_i0] = (*c16_d_y)[c16_i0];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_hoistedGlobal = chartInstance->c16_is_active_c16_juecefinishi;
  c16_b_u = c16_hoistedGlobal;
  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 1, c16_c_y);
  sf_mex_assign(&c16_st, c16_y, false);
  return c16_st;
}

static void set_sim_state_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_st)
{
  const mxArray *c16_u;
  real_T c16_dv0[3];
  int32_T c16_i1;
  real_T (*c16_y)[3];
  c16_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c16_doneDoubleBufferReInit = true;
  c16_u = sf_mex_dup(c16_st);
  c16_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 0)), "y",
                       c16_dv0);
  for (c16_i1 = 0; c16_i1 < 3; c16_i1++) {
    (*c16_y)[c16_i1] = c16_dv0[c16_i1];
  }

  chartInstance->c16_is_active_c16_juecefinishi = c16_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 1)),
     "is_active_c16_juecefinishi");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_juecefinishi(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance)
{
  int32_T c16_i2;
  int32_T c16_i3;
  real_T c16_u1[3];
  int32_T c16_i4;
  real_T c16_u2[12];
  uint32_T c16_debug_family_var_map[26];
  real_T c16_Kph_x;
  real_T c16_a1_x;
  real_T c16_Kph_y;
  real_T c16_a1_y;
  real_T c16_Kpz;
  real_T c16_a4;
  real_T c16_Phd_x;
  real_T c16_Phd_y;
  real_T c16_Pzd;
  real_T c16_Ph_x;
  real_T c16_Vh_x;
  real_T c16_Ph_y;
  real_T c16_Vh_y;
  real_T c16_Pz;
  real_T c16_Vz;
  real_T c16_Vhd_x;
  real_T c16_evh_x;
  real_T c16_Vhd_y;
  real_T c16_evh_y;
  real_T c16_Vzd;
  real_T c16_evz;
  real_T c16_nargin = 2.0;
  real_T c16_nargout = 1.0;
  real_T c16_y[3];
  real_T c16_b_evh_x[3];
  int32_T c16_i5;
  int32_T c16_i6;
  int32_T c16_i7;
  int32_T c16_i8;
  real_T (*c16_b_y)[3];
  real_T (*c16_b_u2)[12];
  real_T (*c16_b_u1)[3];
  c16_b_u2 = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 1);
  c16_b_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_b_u1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  for (c16_i2 = 0; c16_i2 < 3; c16_i2++) {
    _SFD_DATA_RANGE_CHECK((*c16_b_u1)[c16_i2], 0U);
  }

  chartInstance->c16_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  for (c16_i3 = 0; c16_i3 < 3; c16_i3++) {
    c16_u1[c16_i3] = (*c16_b_u1)[c16_i3];
  }

  for (c16_i4 = 0; c16_i4 < 12; c16_i4++) {
    c16_u2[c16_i4] = (*c16_b_u2)[c16_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 26U, 26U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_Kph_x, 0U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_a1_x, 1U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_Kph_y, 2U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_a1_y, 3U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_Kpz, 4U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_a4, 5U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Phd_x, 6U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Phd_y, 7U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Pzd, 8U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Ph_x, 9U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Vh_x, 10U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Ph_y, 11U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Vh_y, 12U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Pz, 13U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Vz, 14U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Vhd_x, 15U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_evh_x, 16U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Vhd_y, 17U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_evh_y, 18U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_Vzd, 19U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_evz, 20U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 21U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 22U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_u1, 23U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_u2, 24U, c16_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_y, 25U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 7);
  c16_Kph_x = 1.55;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 8);
  c16_a1_x = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 9);
  c16_Kph_y = 1.55;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 10);
  c16_a1_y = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 11);
  c16_Kpz = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 12);
  c16_a4 = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 16);
  c16_Phd_x = c16_u1[0];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 17);
  c16_Phd_y = c16_u1[1];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 18);
  c16_Pzd = c16_u1[2];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 22);
  c16_Ph_x = c16_u2[0];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 23);
  c16_Vh_x = c16_u2[3];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 24);
  c16_Ph_y = c16_u2[1];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 25);
  c16_Vh_y = c16_u2[4];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 26);
  c16_Pz = c16_u2[2];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 27);
  c16_Vz = c16_u2[5];
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 31);
  c16_Vhd_x = 1.55 * (c16_Phd_x - c16_Ph_x);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 32);
  c16_evh_x = c16_sat(chartInstance, c16_Vh_x - c16_Vhd_x, 10.0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 34);
  c16_Vhd_y = 1.55 * (c16_Phd_y - c16_Ph_y);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 35);
  c16_evh_y = c16_sat(chartInstance, c16_Vh_y - c16_Vhd_y, 10.0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 38);
  c16_Vzd = -4.0 * (c16_Pz - c16_Pzd);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 39);
  c16_evz = c16_sat(chartInstance, c16_Vz - c16_Vzd, 10.0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 42);
  c16_b_evh_x[0] = c16_evh_x;
  c16_b_evh_x[1] = c16_evh_y;
  c16_b_evh_x[2] = c16_evz;
  for (c16_i5 = 0; c16_i5 < 3; c16_i5++) {
    c16_y[c16_i5] = c16_b_evh_x[c16_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -42);
  _SFD_SYMBOL_SCOPE_POP();
  for (c16_i6 = 0; c16_i6 < 3; c16_i6++) {
    (*c16_b_y)[c16_i6] = c16_y[c16_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_juecefinishiMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c16_i7 = 0; c16_i7 < 3; c16_i7++) {
    _SFD_DATA_RANGE_CHECK((*c16_b_y)[c16_i7], 1U);
  }

  for (c16_i8 = 0; c16_i8 < 12; c16_i8++) {
    _SFD_DATA_RANGE_CHECK((*c16_b_u2)[c16_i8], 2U);
  }
}

static void initSimStructsc16_juecefinishi(SFc16_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c16_sat(SFc16_juecefinishiInstanceStruct *chartInstance, real_T
                      c16_x, real_T c16_a)
{
  real_T c16_y;
  uint32_T c16_debug_family_var_map[6];
  real_T c16_jieguo;
  real_T c16_nargin = 2.0;
  real_T c16_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c16_b_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_jieguo, 0U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 1U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 2U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_x, 3U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_a, 4U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_y, 5U, c16_c_sf_marshallOut,
    c16_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 5);
  if (CV_SCRIPT_IF(0, 0, c16_x > c16_a)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 6);
    c16_jieguo = c16_a;
  } else {
    _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 7);
    if (CV_SCRIPT_IF(0, 1, c16_x < -c16_a)) {
      _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 8);
      c16_jieguo = -c16_a;
    } else {
      _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 10);
      c16_jieguo = c16_x;
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, 14);
  c16_y = c16_jieguo;
  _SFD_SCRIPT_CALL(0U, chartInstance->c16_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  return c16_y;
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber)
{
  (void)c16_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c16_chartNumber, c16_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\\\Users\\\\StarFly\\\\Desktop\\\\\xb6\xe0\xd0\xfd\xd2\xed\xb7\xc9\xd0\xd0\xc6\xf7\xc9\xe8\xbc\xc6\xd3\xeb\xbf\xd8\xd6\xc6\\\\\xcc\xe1\xbd\xbb\\\\\xb3\xcc\xd0\xf2\\\\sat.m"));
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i9;
  real_T c16_b_inData[3];
  int32_T c16_i10;
  real_T c16_u[3];
  const mxArray *c16_y = NULL;
  SFc16_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc16_juecefinishiInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  for (c16_i9 = 0; c16_i9 < 3; c16_i9++) {
    c16_b_inData[c16_i9] = (*(real_T (*)[3])c16_inData)[c16_i9];
  }

  for (c16_i10 = 0; c16_i10 < 3; c16_i10++) {
    c16_u[c16_i10] = c16_b_inData[c16_i10];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static void c16_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c16_y, const char_T *c16_identifier, real_T c16_b_y[3])
{
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_y), &c16_thisId, c16_b_y);
  sf_mex_destroy(&c16_y);
}

static void c16_b_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[3])
{
  real_T c16_dv1[3];
  int32_T c16_i11;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c16_i11 = 0; c16_i11 < 3; c16_i11++) {
    c16_y[c16_i11] = c16_dv1[c16_i11];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_y;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_b_y[3];
  int32_T c16_i12;
  SFc16_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc16_juecefinishiInstanceStruct *)chartInstanceVoid;
  c16_y = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_y), &c16_thisId, c16_b_y);
  sf_mex_destroy(&c16_y);
  for (c16_i12 = 0; c16_i12 < 3; c16_i12++) {
    (*(real_T (*)[3])c16_outData)[c16_i12] = c16_b_y[c16_i12];
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i13;
  real_T c16_b_inData[12];
  int32_T c16_i14;
  real_T c16_u[12];
  const mxArray *c16_y = NULL;
  SFc16_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc16_juecefinishiInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  for (c16_i13 = 0; c16_i13 < 12; c16_i13++) {
    c16_b_inData[c16_i13] = (*(real_T (*)[12])c16_inData)[c16_i13];
  }

  for (c16_i14 = 0; c16_i14 < 12; c16_i14++) {
    c16_u[c16_i14] = c16_b_inData[c16_i14];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc16_juecefinishiInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static real_T c16_c_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d0;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d0, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_nargout;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc16_juecefinishiInstanceStruct *)chartInstanceVoid;
  c16_nargout = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_nargout),
    &c16_thisId);
  sf_mex_destroy(&c16_nargout);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray *sf_c16_juecefinishi_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  sf_mex_assign(&c16_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c16_info_helper(&c16_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c16_nameCaptureInfo);
  return c16_nameCaptureInfo;
}

static void c16_info_helper(const mxArray **c16_info)
{
  const mxArray *c16_rhs0 = NULL;
  const mxArray *c16_lhs0 = NULL;
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("sat"), "name", "name", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[EW]C:/Users/StarFly/Desktop/\\xe5\\xa4\\x9a\\xe6\\x97\\x8b\\xe7\\xbf\\xbc\\xe9\\xa3\\x9e\\xe8\\xa1\\x8c\\xe5\\x99\\xa8\\xe8\\xae\\xbe\\xe8\\xae\\xa1\\xe"
    "4\\xb8\\x8e\\xe6\\x8e\\xa7\\xe5\\x88\\xb6/\\xe6\\x8f\\x90\\xe4\\xba\\xa4/\\xe7\\xa8\\x8b\\xe5\\xba\\x8f/sat.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1530546328U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c16_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs0), "lhs", "lhs",
                  0);
  sf_mex_destroy(&c16_rhs0);
  sf_mex_destroy(&c16_lhs0);
}

static const mxArray *c16_emlrt_marshallOut(const char * c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c16_u)), false);
  return c16_y;
}

static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 7, 0U, 0U, 0U, 0), false);
  return c16_y;
}

static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc16_juecefinishiInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static int32_T c16_d_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i15;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i15, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i15;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc16_juecefinishiInstanceStruct *)chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static uint8_T c16_e_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_juecefinishi, const char_T *
  c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_juecefinishi), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_juecefinishi);
  return c16_y;
}

static uint8_T c16_f_emlrt_marshallIn(SFc16_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void init_dsm_address_info(SFc16_juecefinishiInstanceStruct
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

void sf_c16_juecefinishi_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(458333824U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3042570086U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1965077517U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3899408091U);
}

mxArray *sf_c16_juecefinishi_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("AYXjCjEETRuuLKaSyMl9sD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
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

mxArray *sf_c16_juecefinishi_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c16_juecefinishi_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c16_juecefinishi(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c16_juecefinishi\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_juecefinishi_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_juecefinishiInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc16_juecefinishiInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _juecefinishiMachineNumber_,
           16,
           1,
           1,
           0,
           3,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,829);
        _SFD_CV_INIT_SCRIPT(0,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"sat",0,-1,184);
        _SFD_CV_INIT_SCRIPT_IF(0,0,79,85,100,162);
        _SFD_CV_INIT_SCRIPT_IF(0,1,105,112,132,158);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)
            c16_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c16_u1)[3];
          real_T (*c16_y)[3];
          real_T (*c16_u2)[12];
          c16_u2 = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 1);
          c16_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c16_u1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c16_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c16_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c16_u2);
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
  return "OrA0losDDo6chpAJ1rtHLE";
}

static void sf_opaque_initialize_c16_juecefinishi(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_juecefinishiInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c16_juecefinishi((SFc16_juecefinishiInstanceStruct*)
    chartInstanceVar);
  initialize_c16_juecefinishi((SFc16_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c16_juecefinishi(void *chartInstanceVar)
{
  enable_c16_juecefinishi((SFc16_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c16_juecefinishi(void *chartInstanceVar)
{
  disable_c16_juecefinishi((SFc16_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c16_juecefinishi(void *chartInstanceVar)
{
  sf_gateway_c16_juecefinishi((SFc16_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c16_juecefinishi(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c16_juecefinishi
    ((SFc16_juecefinishiInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_juecefinishi();/* state var info */
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

extern void sf_internal_set_sim_state_c16_juecefinishi(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c16_juecefinishi();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c16_juecefinishi((SFc16_juecefinishiInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c16_juecefinishi(SimStruct* S)
{
  return sf_internal_get_sim_state_c16_juecefinishi(S);
}

static void sf_opaque_set_sim_state_c16_juecefinishi(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c16_juecefinishi(S, st);
}

static void sf_opaque_terminate_c16_juecefinishi(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_juecefinishiInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_juecefinishi_optimization_info();
    }

    finalize_c16_juecefinishi((SFc16_juecefinishiInstanceStruct*)
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
  initSimStructsc16_juecefinishi((SFc16_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_juecefinishi(SimStruct *S)
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
    initialize_params_c16_juecefinishi((SFc16_juecefinishiInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_juecefinishi_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,16,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1441461458U));
  ssSetChecksum1(S,(272429170U));
  ssSetChecksum2(S,(3181322360U));
  ssSetChecksum3(S,(3894998111U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c16_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_juecefinishi(SimStruct *S)
{
  SFc16_juecefinishiInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc16_juecefinishiInstanceStruct *)utMalloc(sizeof
    (SFc16_juecefinishiInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_juecefinishiInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c16_juecefinishi;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c16_juecefinishi;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c16_juecefinishi;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c16_juecefinishi;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c16_juecefinishi;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_juecefinishi;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_juecefinishi;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_juecefinishi;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_juecefinishi;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_juecefinishi;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c16_juecefinishi;
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

void c16_juecefinishi_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_juecefinishi(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_juecefinishi(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_juecefinishi(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_juecefinishi_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
