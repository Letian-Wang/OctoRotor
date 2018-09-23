/* Include files */

#include <stddef.h>
#include "blas.h"
#include "juecefinishi_sfun.h"
#include "c17_juecefinishi.h"
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
static const char * c17_debug_family_names[30] = { "K_phi", "a10_x", "K_theta",
  "a10_y", "K_psi", "a10_z", "phi", "psi", "theta", "W_x", "W_y", "W_z", "phi_d",
  "theta_d", "psi_d", "e_phi", "Wd_x", "eW_x", "e_theta", "Wd_y", "eW_y",
  "e_psi", "Wd_z", "eW_z", "nargin", "nargout", "u1", "u2", "u3", "y" };

static const char * c17_b_debug_family_names[6] = { "jieguo", "nargin",
  "nargout", "x", "a", "y" };

/* Function Declarations */
static void initialize_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance);
static void initialize_params_c17_juecefinishi(SFc17_juecefinishiInstanceStruct *
  chartInstance);
static void enable_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance);
static void disable_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance);
static void c17_update_debugger_state_c17_juecefinishi
  (SFc17_juecefinishiInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_juecefinishi
  (SFc17_juecefinishiInstanceStruct *chartInstance);
static void set_sim_state_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_st);
static void finalize_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance);
static void sf_gateway_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance);
static void initSimStructsc17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance);
static real_T c17_sat(SFc17_juecefinishiInstanceStruct *chartInstance, real_T
                      c17_x, real_T c17_a);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber);
static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c17_y, const char_T *c17_identifier, real_T c17_b_y[3]);
static void c17_b_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[3]);
static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static real_T c17_c_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static void c17_info_helper(const mxArray **c17_info);
static const mxArray *c17_emlrt_marshallOut(const char * c17_u);
static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u);
static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static int32_T c17_d_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static uint8_T c17_e_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_juecefinishi, const char_T *
  c17_identifier);
static uint8_T c17_f_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void init_dsm_address_info(SFc17_juecefinishiInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance)
{
  chartInstance->c17_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c17_is_active_c17_juecefinishi = 0U;
}

static void initialize_params_c17_juecefinishi(SFc17_juecefinishiInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c17_update_debugger_state_c17_juecefinishi
  (SFc17_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c17_juecefinishi
  (SFc17_juecefinishiInstanceStruct *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  int32_T c17_i0;
  real_T c17_u[3];
  const mxArray *c17_b_y = NULL;
  uint8_T c17_hoistedGlobal;
  uint8_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  real_T (*c17_d_y)[3];
  c17_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellmatrix(2, 1), false);
  for (c17_i0 = 0; c17_i0 < 3; c17_i0++) {
    c17_u[c17_i0] = (*c17_d_y)[c17_i0];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_hoistedGlobal = chartInstance->c17_is_active_c17_juecefinishi;
  c17_b_u = c17_hoistedGlobal;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 1, c17_c_y);
  sf_mex_assign(&c17_st, c17_y, false);
  return c17_st;
}

static void set_sim_state_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_st)
{
  const mxArray *c17_u;
  real_T c17_dv0[3];
  int32_T c17_i1;
  real_T (*c17_y)[3];
  c17_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c17_doneDoubleBufferReInit = true;
  c17_u = sf_mex_dup(c17_st);
  c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 0)), "y",
                       c17_dv0);
  for (c17_i1 = 0; c17_i1 < 3; c17_i1++) {
    (*c17_y)[c17_i1] = c17_dv0[c17_i1];
  }

  chartInstance->c17_is_active_c17_juecefinishi = c17_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 1)),
     "is_active_c17_juecefinishi");
  sf_mex_destroy(&c17_u);
  c17_update_debugger_state_c17_juecefinishi(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance)
{
  int32_T c17_i2;
  real_T c17_hoistedGlobal;
  int32_T c17_i3;
  real_T c17_u1[3];
  real_T c17_u2;
  int32_T c17_i4;
  real_T c17_u3[12];
  uint32_T c17_debug_family_var_map[30];
  real_T c17_K_phi;
  real_T c17_a10_x;
  real_T c17_K_theta;
  real_T c17_a10_y;
  real_T c17_K_psi;
  real_T c17_a10_z;
  real_T c17_phi;
  real_T c17_psi;
  real_T c17_theta;
  real_T c17_W_x;
  real_T c17_W_y;
  real_T c17_W_z;
  real_T c17_phi_d;
  real_T c17_theta_d;
  real_T c17_psi_d;
  real_T c17_e_phi;
  real_T c17_Wd_x;
  real_T c17_eW_x;
  real_T c17_e_theta;
  real_T c17_Wd_y;
  real_T c17_eW_y;
  real_T c17_e_psi;
  real_T c17_Wd_z;
  real_T c17_eW_z;
  real_T c17_nargin = 3.0;
  real_T c17_nargout = 1.0;
  real_T c17_y[3];
  real_T c17_b_eW_x[3];
  int32_T c17_i5;
  int32_T c17_i6;
  int32_T c17_i7;
  int32_T c17_i8;
  real_T *c17_b_u2;
  real_T (*c17_b_y)[3];
  real_T (*c17_b_u3)[12];
  real_T (*c17_b_u1)[3];
  c17_b_u3 = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 2);
  c17_b_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c17_b_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_b_u1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
  for (c17_i2 = 0; c17_i2 < 3; c17_i2++) {
    _SFD_DATA_RANGE_CHECK((*c17_b_u1)[c17_i2], 0U);
  }

  chartInstance->c17_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
  c17_hoistedGlobal = *c17_b_u2;
  for (c17_i3 = 0; c17_i3 < 3; c17_i3++) {
    c17_u1[c17_i3] = (*c17_b_u1)[c17_i3];
  }

  c17_u2 = c17_hoistedGlobal;
  for (c17_i4 = 0; c17_i4 < 12; c17_i4++) {
    c17_u3[c17_i4] = (*c17_b_u3)[c17_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 30U, 30U, c17_debug_family_names,
    c17_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_K_phi, 0U, c17_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_a10_x, 1U, c17_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_K_theta, 2U, c17_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_a10_y, 3U, c17_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_K_psi, 4U, c17_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_a10_z, 5U, c17_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_phi, 6U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_psi, 7U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_theta, 8U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_W_x, 9U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_W_y, 10U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_W_z, 11U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_phi_d, 12U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_theta_d, 13U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_psi_d, 14U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_e_phi, 15U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_Wd_x, 16U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_eW_x, 17U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_e_theta, 18U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_Wd_y, 19U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_eW_y, 20U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_e_psi, 21U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_Wd_z, 22U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_eW_z, 23U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 24U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 25U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c17_u1, 26U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_u2, 27U, c17_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c17_u3, 28U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_y, 29U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 9);
  c17_K_phi = 8.0;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 10);
  c17_a10_x = 20.0;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 13);
  c17_K_theta = 8.0;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 14);
  c17_a10_y = 20.0;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 17);
  c17_K_psi = 2.6;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 18);
  c17_a10_z = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 25);
  c17_phi = c17_u3[6];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 26);
  c17_psi = c17_u3[8];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 27);
  c17_theta = c17_u3[7];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 29);
  c17_W_x = c17_u3[9];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 30);
  c17_W_y = c17_u3[10];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 31);
  c17_W_z = c17_u3[11];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 34);
  c17_phi_d = c17_u1[0];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 35);
  c17_theta_d = c17_u1[1];
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 36);
  c17_psi_d = c17_u2;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 39);
  c17_e_phi = c17_phi - c17_phi_d;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 40);
  c17_Wd_x = -8.0 * c17_e_phi;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 41);
  c17_eW_x = c17_sat(chartInstance, c17_W_x - c17_Wd_x, 20.0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 44);
  c17_e_theta = c17_theta - c17_theta_d;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 45);
  c17_Wd_y = -8.0 * c17_e_theta;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 46);
  c17_eW_y = c17_sat(chartInstance, c17_W_y - c17_Wd_y, 20.0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 49);
  c17_e_psi = c17_psi - c17_psi_d;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 51);
  c17_Wd_z = -2.6 * c17_e_psi;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 52);
  c17_eW_z = c17_sat(chartInstance, c17_W_z - c17_Wd_z, 10.0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 55);
  c17_b_eW_x[0] = c17_eW_x;
  c17_b_eW_x[1] = c17_eW_y;
  c17_b_eW_x[2] = c17_eW_z;
  for (c17_i5 = 0; c17_i5 < 3; c17_i5++) {
    c17_y[c17_i5] = c17_b_eW_x[c17_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, -55);
  _SFD_SYMBOL_SCOPE_POP();
  for (c17_i6 = 0; c17_i6 < 3; c17_i6++) {
    (*c17_b_y)[c17_i6] = c17_y[c17_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_juecefinishiMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c17_i7 = 0; c17_i7 < 3; c17_i7++) {
    _SFD_DATA_RANGE_CHECK((*c17_b_y)[c17_i7], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c17_b_u2, 2U);
  for (c17_i8 = 0; c17_i8 < 12; c17_i8++) {
    _SFD_DATA_RANGE_CHECK((*c17_b_u3)[c17_i8], 3U);
  }
}

static void initSimStructsc17_juecefinishi(SFc17_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c17_sat(SFc17_juecefinishiInstanceStruct *chartInstance, real_T
                      c17_x, real_T c17_a)
{
  real_T c17_y;
  uint32_T c17_debug_family_var_map[6];
  real_T c17_jieguo;
  real_T c17_nargin = 2.0;
  real_T c17_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c17_b_debug_family_names,
    c17_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_jieguo, 0U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 1U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 2U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_x, 3U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_a, 4U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_y, 5U, c17_c_sf_marshallOut,
    c17_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c17_sfEvent, 5);
  if (CV_SCRIPT_IF(0, 0, c17_x > c17_a)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c17_sfEvent, 6);
    c17_jieguo = c17_a;
  } else {
    _SFD_SCRIPT_CALL(0U, chartInstance->c17_sfEvent, 7);
    if (CV_SCRIPT_IF(0, 1, c17_x < -c17_a)) {
      _SFD_SCRIPT_CALL(0U, chartInstance->c17_sfEvent, 8);
      c17_jieguo = -c17_a;
    } else {
      _SFD_SCRIPT_CALL(0U, chartInstance->c17_sfEvent, 10);
      c17_jieguo = c17_x;
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c17_sfEvent, 14);
  c17_y = c17_jieguo;
  _SFD_SCRIPT_CALL(0U, chartInstance->c17_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  return c17_y;
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber)
{
  (void)c17_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c17_chartNumber, c17_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\\\Users\\\\StarFly\\\\Desktop\\\\\xb6\xe0\xd0\xfd\xd2\xed\xb7\xc9\xd0\xd0\xc6\xf7\xc9\xe8\xbc\xc6\xd3\xeb\xbf\xd8\xd6\xc6\\\\\xcc\xe1\xbd\xbb\\\\\xb3\xcc\xd0\xf2\\\\sat.m"));
}

static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i9;
  real_T c17_b_inData[3];
  int32_T c17_i10;
  real_T c17_u[3];
  const mxArray *c17_y = NULL;
  SFc17_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc17_juecefinishiInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i9 = 0; c17_i9 < 3; c17_i9++) {
    c17_b_inData[c17_i9] = (*(real_T (*)[3])c17_inData)[c17_i9];
  }

  for (c17_i10 = 0; c17_i10 < 3; c17_i10++) {
    c17_u[c17_i10] = c17_b_inData[c17_i10];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c17_y, const char_T *c17_identifier, real_T c17_b_y[3])
{
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_y), &c17_thisId, c17_b_y);
  sf_mex_destroy(&c17_y);
}

static void c17_b_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[3])
{
  real_T c17_dv1[3];
  int32_T c17_i11;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c17_i11 = 0; c17_i11 < 3; c17_i11++) {
    c17_y[c17_i11] = c17_dv1[c17_i11];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_y;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_b_y[3];
  int32_T c17_i12;
  SFc17_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc17_juecefinishiInstanceStruct *)chartInstanceVoid;
  c17_y = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_y), &c17_thisId, c17_b_y);
  sf_mex_destroy(&c17_y);
  for (c17_i12 = 0; c17_i12 < 3; c17_i12++) {
    (*(real_T (*)[3])c17_outData)[c17_i12] = c17_b_y[c17_i12];
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i13;
  real_T c17_b_inData[12];
  int32_T c17_i14;
  real_T c17_u[12];
  const mxArray *c17_y = NULL;
  SFc17_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc17_juecefinishiInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i13 = 0; c17_i13 < 12; c17_i13++) {
    c17_b_inData[c17_i13] = (*(real_T (*)[12])c17_inData)[c17_i13];
  }

  for (c17_i14 = 0; c17_i14 < 12; c17_i14++) {
    c17_u[c17_i14] = c17_b_inData[c17_i14];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  real_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc17_juecefinishiInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(real_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static real_T c17_c_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  real_T c17_y;
  real_T c17_d0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_d0, 1, 0, 0U, 0, 0U, 0);
  c17_y = c17_d0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_nargout;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y;
  SFc17_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc17_juecefinishiInstanceStruct *)chartInstanceVoid;
  c17_nargout = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_nargout),
    &c17_thisId);
  sf_mex_destroy(&c17_nargout);
  *(real_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

const mxArray *sf_c17_juecefinishi_get_eml_resolved_functions_info(void)
{
  const mxArray *c17_nameCaptureInfo = NULL;
  c17_nameCaptureInfo = NULL;
  sf_mex_assign(&c17_nameCaptureInfo, sf_mex_createstruct("structure", 2, 1, 1),
                false);
  c17_info_helper(&c17_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c17_nameCaptureInfo);
  return c17_nameCaptureInfo;
}

static void c17_info_helper(const mxArray **c17_info)
{
  const mxArray *c17_rhs0 = NULL;
  const mxArray *c17_lhs0 = NULL;
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("sat"), "name", "name", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[EW]C:/Users/StarFly/Desktop/\\xe5\\xa4\\x9a\\xe6\\x97\\x8b\\xe7\\xbf\\xbc\\xe9\\xa3\\x9e\\xe8\\xa1\\x8c\\xe5\\x99\\xa8\\xe8\\xae\\xbe\\xe8\\xae\\xa1\\xe"
    "4\\xb8\\x8e\\xe6\\x8e\\xa7\\xe5\\x88\\xb6/\\xe6\\x8f\\x90\\xe4\\xba\\xa4/\\xe7\\xa8\\x8b\\xe5\\xba\\x8f/sat.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1530546328U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c17_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs0), "lhs", "lhs",
                  0);
  sf_mex_destroy(&c17_rhs0);
  sf_mex_destroy(&c17_lhs0);
}

static const mxArray *c17_emlrt_marshallOut(const char * c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c17_u)), false);
  return c17_y;
}

static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 7, 0U, 0U, 0U, 0), false);
  return c17_y;
}

static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc17_juecefinishiInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(int32_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static int32_T c17_d_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  int32_T c17_y;
  int32_T c17_i15;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_i15, 1, 6, 0U, 0, 0U, 0);
  c17_y = c17_i15;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_sfEvent;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  int32_T c17_y;
  SFc17_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc17_juecefinishiInstanceStruct *)chartInstanceVoid;
  c17_b_sfEvent = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_sfEvent),
    &c17_thisId);
  sf_mex_destroy(&c17_b_sfEvent);
  *(int32_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static uint8_T c17_e_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_juecefinishi, const char_T *
  c17_identifier)
{
  uint8_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_b_is_active_c17_juecefinishi), &c17_thisId);
  sf_mex_destroy(&c17_b_is_active_c17_juecefinishi);
  return c17_y;
}

static uint8_T c17_f_emlrt_marshallIn(SFc17_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_u0, 1, 3, 0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void init_dsm_address_info(SFc17_juecefinishiInstanceStruct
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

void sf_c17_juecefinishi_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2789797855U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1490511303U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1660772742U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4218914065U);
}

mxArray *sf_c17_juecefinishi_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("jZCFsUgmyO7mPNZvRNNX7F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      pr[0] = (double)(12);
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

mxArray *sf_c17_juecefinishi_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c17_juecefinishi_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c17_juecefinishi(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c17_juecefinishi\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_juecefinishi_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_juecefinishiInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc17_juecefinishiInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _juecefinishiMachineNumber_,
           17,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,787);
        _SFD_CV_INIT_SCRIPT(0,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"sat",0,-1,184);
        _SFD_CV_INIT_SCRIPT_IF(0,0,79,85,100,162);
        _SFD_CV_INIT_SCRIPT_IF(0,1,105,112,132,158);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)
            c17_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c17_u2;
          real_T (*c17_u1)[3];
          real_T (*c17_y)[3];
          real_T (*c17_u3)[12];
          c17_u3 = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 2);
          c17_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c17_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c17_u1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c17_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c17_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c17_u2);
          _SFD_SET_DATA_VALUE_PTR(3U, *c17_u3);
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
  return "4slKUJnAiFGNC70qa4eUrH";
}

static void sf_opaque_initialize_c17_juecefinishi(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_juecefinishiInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c17_juecefinishi((SFc17_juecefinishiInstanceStruct*)
    chartInstanceVar);
  initialize_c17_juecefinishi((SFc17_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c17_juecefinishi(void *chartInstanceVar)
{
  enable_c17_juecefinishi((SFc17_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c17_juecefinishi(void *chartInstanceVar)
{
  disable_c17_juecefinishi((SFc17_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c17_juecefinishi(void *chartInstanceVar)
{
  sf_gateway_c17_juecefinishi((SFc17_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c17_juecefinishi(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c17_juecefinishi
    ((SFc17_juecefinishiInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_juecefinishi();/* state var info */
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

extern void sf_internal_set_sim_state_c17_juecefinishi(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c17_juecefinishi();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c17_juecefinishi((SFc17_juecefinishiInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c17_juecefinishi(SimStruct* S)
{
  return sf_internal_get_sim_state_c17_juecefinishi(S);
}

static void sf_opaque_set_sim_state_c17_juecefinishi(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c17_juecefinishi(S, st);
}

static void sf_opaque_terminate_c17_juecefinishi(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_juecefinishiInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_juecefinishi_optimization_info();
    }

    finalize_c17_juecefinishi((SFc17_juecefinishiInstanceStruct*)
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
  initSimStructsc17_juecefinishi((SFc17_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_juecefinishi(SimStruct *S)
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
    initialize_params_c17_juecefinishi((SFc17_juecefinishiInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_juecefinishi_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,17,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,17,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,17);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,17,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,17,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1418273907U));
  ssSetChecksum1(S,(4114664020U));
  ssSetChecksum2(S,(1952810885U));
  ssSetChecksum3(S,(4284743860U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c17_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_juecefinishi(SimStruct *S)
{
  SFc17_juecefinishiInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc17_juecefinishiInstanceStruct *)utMalloc(sizeof
    (SFc17_juecefinishiInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_juecefinishiInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c17_juecefinishi;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_juecefinishi;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c17_juecefinishi;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c17_juecefinishi;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c17_juecefinishi;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c17_juecefinishi;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c17_juecefinishi;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_juecefinishi;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_juecefinishi;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_juecefinishi;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c17_juecefinishi;
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

void c17_juecefinishi_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_juecefinishi(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_juecefinishi(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_juecefinishi(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_juecefinishi_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
