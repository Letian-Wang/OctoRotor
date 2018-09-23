/* Include files */

#include <stddef.h>
#include "blas.h"
#include "juecefinishi_sfun.h"
#include "c25_juecefinishi.h"
#include "mwmathutil.h"
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
static const char * c25_debug_family_names[20] = { "P", "t", "P_wp", "ipsilong",
  "t_meidianhuijia", "t_chongdianhuiyuanlu", "t_chongdian", "t_wanchengrenwu",
  "P_wp_cur_xiao", "nargin", "nargout", "u1", "u2", "y", "k", "j", "i", "P_home",
  "P_wp_cur", "t_home" };

/* Function Declarations */
static void initialize_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance);
static void initialize_params_c25_juecefinishi(SFc25_juecefinishiInstanceStruct *
  chartInstance);
static void enable_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance);
static void disable_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance);
static void c25_update_debugger_state_c25_juecefinishi
  (SFc25_juecefinishiInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c25_juecefinishi
  (SFc25_juecefinishiInstanceStruct *chartInstance);
static void set_sim_state_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_st);
static void finalize_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance);
static void sf_gateway_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance);
static void c25_chartstep_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance);
static void initSimStructsc25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber, uint32_T c25_instanceNumber);
static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static real_T c25_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_t_home, const char_T *c25_identifier);
static real_T c25_b_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static void c25_c_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_P_wp_cur, const char_T *c25_identifier,
  real_T c25_y[3]);
static void c25_d_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[3]);
static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_c_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static void c25_e_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_P_home, const char_T *c25_identifier,
  real_T c25_y[3]);
static void c25_f_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[3]);
static void c25_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_d_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static real_T c25_g_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_i, const char_T *c25_identifier);
static real_T c25_h_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_e_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static real_T c25_i_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_j, const char_T *c25_identifier);
static real_T c25_j_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_f_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static real_T c25_k_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_k, const char_T *c25_identifier);
static real_T c25_l_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_g_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static void c25_m_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_y, const char_T *c25_identifier, real_T
  c25_b_y[3]);
static void c25_n_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[3]);
static void c25_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_h_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static const mxArray *c25_i_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static real_T c25_o_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_j_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static void c25_p_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[30]);
static void c25_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static void c25_info_helper(const mxArray **c25_info);
static const mxArray *c25_emlrt_marshallOut(const char * c25_u);
static const mxArray *c25_b_emlrt_marshallOut(const uint32_T c25_u);
static void c25_eml_scalar_eg(SFc25_juecefinishiInstanceStruct *chartInstance);
static real_T c25_eml_xnrm2(SFc25_juecefinishiInstanceStruct *chartInstance,
  real_T c25_x[3]);
static const mxArray *c25_k_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static int32_T c25_q_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static uint8_T c25_r_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_is_active_c25_juecefinishi, const char_T *
  c25_identifier);
static uint8_T c25_s_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void init_dsm_address_info(SFc25_juecefinishiInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance)
{
  chartInstance->c25_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c25_k_not_empty = false;
  chartInstance->c25_j_not_empty = false;
  chartInstance->c25_i_not_empty = false;
  chartInstance->c25_P_home_not_empty = false;
  chartInstance->c25_P_wp_cur_not_empty = false;
  chartInstance->c25_t_home_not_empty = false;
  chartInstance->c25_is_active_c25_juecefinishi = 0U;
}

static void initialize_params_c25_juecefinishi(SFc25_juecefinishiInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c25_update_debugger_state_c25_juecefinishi
  (SFc25_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c25_juecefinishi
  (SFc25_juecefinishiInstanceStruct *chartInstance)
{
  const mxArray *c25_st;
  const mxArray *c25_y = NULL;
  int32_T c25_i0;
  real_T c25_u[3];
  const mxArray *c25_b_y = NULL;
  int32_T c25_i1;
  real_T c25_b_u[3];
  const mxArray *c25_c_y = NULL;
  int32_T c25_i2;
  real_T c25_c_u[3];
  const mxArray *c25_d_y = NULL;
  real_T c25_hoistedGlobal;
  real_T c25_d_u;
  const mxArray *c25_e_y = NULL;
  real_T c25_b_hoistedGlobal;
  real_T c25_e_u;
  const mxArray *c25_f_y = NULL;
  real_T c25_c_hoistedGlobal;
  real_T c25_f_u;
  const mxArray *c25_g_y = NULL;
  real_T c25_d_hoistedGlobal;
  real_T c25_g_u;
  const mxArray *c25_h_y = NULL;
  uint8_T c25_e_hoistedGlobal;
  uint8_T c25_h_u;
  const mxArray *c25_i_y = NULL;
  real_T (*c25_j_y)[3];
  c25_j_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c25_st = NULL;
  c25_st = NULL;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_createcellmatrix(8, 1), false);
  for (c25_i0 = 0; c25_i0 < 3; c25_i0++) {
    c25_u[c25_i0] = (*c25_j_y)[c25_i0];
  }

  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c25_y, 0, c25_b_y);
  for (c25_i1 = 0; c25_i1 < 3; c25_i1++) {
    c25_b_u[c25_i1] = chartInstance->c25_P_home[c25_i1];
  }

  c25_c_y = NULL;
  if (!chartInstance->c25_P_home_not_empty) {
    sf_mex_assign(&c25_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_c_y, sf_mex_create("y", c25_b_u, 0, 0U, 1U, 0U, 1, 3),
                  false);
  }

  sf_mex_setcell(c25_y, 1, c25_c_y);
  for (c25_i2 = 0; c25_i2 < 3; c25_i2++) {
    c25_c_u[c25_i2] = chartInstance->c25_P_wp_cur[c25_i2];
  }

  c25_d_y = NULL;
  if (!chartInstance->c25_P_wp_cur_not_empty) {
    sf_mex_assign(&c25_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_d_y, sf_mex_create("y", c25_c_u, 0, 0U, 1U, 0U, 1, 3),
                  false);
  }

  sf_mex_setcell(c25_y, 2, c25_d_y);
  c25_hoistedGlobal = chartInstance->c25_i;
  c25_d_u = c25_hoistedGlobal;
  c25_e_y = NULL;
  if (!chartInstance->c25_i_not_empty) {
    sf_mex_assign(&c25_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_e_y, sf_mex_create("y", &c25_d_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c25_y, 3, c25_e_y);
  c25_b_hoistedGlobal = chartInstance->c25_j;
  c25_e_u = c25_b_hoistedGlobal;
  c25_f_y = NULL;
  if (!chartInstance->c25_j_not_empty) {
    sf_mex_assign(&c25_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_f_y, sf_mex_create("y", &c25_e_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c25_y, 4, c25_f_y);
  c25_c_hoistedGlobal = chartInstance->c25_k;
  c25_f_u = c25_c_hoistedGlobal;
  c25_g_y = NULL;
  if (!chartInstance->c25_k_not_empty) {
    sf_mex_assign(&c25_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_g_y, sf_mex_create("y", &c25_f_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c25_y, 5, c25_g_y);
  c25_d_hoistedGlobal = chartInstance->c25_t_home;
  c25_g_u = c25_d_hoistedGlobal;
  c25_h_y = NULL;
  if (!chartInstance->c25_t_home_not_empty) {
    sf_mex_assign(&c25_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_h_y, sf_mex_create("y", &c25_g_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c25_y, 6, c25_h_y);
  c25_e_hoistedGlobal = chartInstance->c25_is_active_c25_juecefinishi;
  c25_h_u = c25_e_hoistedGlobal;
  c25_i_y = NULL;
  sf_mex_assign(&c25_i_y, sf_mex_create("y", &c25_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c25_y, 7, c25_i_y);
  sf_mex_assign(&c25_st, c25_y, false);
  return c25_st;
}

static void set_sim_state_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_st)
{
  const mxArray *c25_u;
  real_T c25_dv0[3];
  int32_T c25_i3;
  real_T c25_dv1[3];
  int32_T c25_i4;
  real_T c25_dv2[3];
  int32_T c25_i5;
  real_T (*c25_y)[3];
  c25_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c25_doneDoubleBufferReInit = true;
  c25_u = sf_mex_dup(c25_st);
  c25_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c25_u, 0)),
    "y", c25_dv0);
  for (c25_i3 = 0; c25_i3 < 3; c25_i3++) {
    (*c25_y)[c25_i3] = c25_dv0[c25_i3];
  }

  c25_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c25_u, 1)),
    "P_home", c25_dv1);
  for (c25_i4 = 0; c25_i4 < 3; c25_i4++) {
    chartInstance->c25_P_home[c25_i4] = c25_dv1[c25_i4];
  }

  c25_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c25_u, 2)),
    "P_wp_cur", c25_dv2);
  for (c25_i5 = 0; c25_i5 < 3; c25_i5++) {
    chartInstance->c25_P_wp_cur[c25_i5] = c25_dv2[c25_i5];
  }

  chartInstance->c25_i = c25_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c25_u, 3)), "i");
  chartInstance->c25_j = c25_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c25_u, 4)), "j");
  chartInstance->c25_k = c25_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c25_u, 5)), "k");
  chartInstance->c25_t_home = c25_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c25_u, 6)), "t_home");
  chartInstance->c25_is_active_c25_juecefinishi = c25_r_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c25_u, 7)),
     "is_active_c25_juecefinishi");
  sf_mex_destroy(&c25_u);
  c25_update_debugger_state_c25_juecefinishi(chartInstance);
  sf_mex_destroy(&c25_st);
}

static void finalize_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance)
{
  int32_T c25_i6;
  int32_T c25_i7;
  real_T *c25_u2;
  real_T (*c25_y)[3];
  real_T (*c25_u1)[12];
  c25_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c25_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c25_u1 = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 20U, chartInstance->c25_sfEvent);
  for (c25_i6 = 0; c25_i6 < 12; c25_i6++) {
    _SFD_DATA_RANGE_CHECK((*c25_u1)[c25_i6], 0U);
  }

  chartInstance->c25_sfEvent = CALL_EVENT;
  c25_chartstep_c25_juecefinishi(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_juecefinishiMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c25_i7 = 0; c25_i7 < 3; c25_i7++) {
    _SFD_DATA_RANGE_CHECK((*c25_y)[c25_i7], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c25_u2, 2U);
}

static void c25_chartstep_c25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance)
{
  real_T c25_hoistedGlobal;
  int32_T c25_i8;
  real_T c25_u1[12];
  real_T c25_u2;
  uint32_T c25_debug_family_var_map[20];
  real_T c25_P[3];
  real_T c25_t;
  real_T c25_P_wp[30];
  real_T c25_ipsilong;
  real_T c25_t_meidianhuijia;
  real_T c25_t_chongdianhuiyuanlu;
  real_T c25_t_chongdian;
  real_T c25_t_wanchengrenwu;
  real_T c25_P_wp_cur_xiao[3];
  real_T c25_nargin = 2.0;
  real_T c25_nargout = 1.0;
  real_T c25_y[3];
  int32_T c25_i9;
  int32_T c25_i10;
  int32_T c25_i11;
  static real_T c25_dv3[30] = { 0.0, 0.0, -1.0, 0.0, 100.0, -1.0, 10.0, 100.0,
    -1.0, 10.0, 0.0, -1.0, 20.0, 0.0, -1.0, 20.0, 100.0, -1.0, 30.0, 100.0, -1.0,
    30.0, 0.0, -1.0, 40.0, 0.0, -1.0, 40.0, 100.0, -1.0 };

  int32_T c25_i12;
  static real_T c25_dv4[3] = { 0.0, 0.0, -1.0 };

  real_T c25_b_hoistedGlobal;
  real_T c25_x;
  real_T c25_xk;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_d_x;
  real_T c25_r;
  real_T c25_u;
  const mxArray *c25_b_y = NULL;
  int32_T c25_i13;
  int32_T c25_i14;
  int32_T c25_i15;
  real_T c25_c_hoistedGlobal[3];
  int32_T c25_i16;
  int32_T c25_i17;
  real_T c25_d_hoistedGlobal[3];
  real_T c25_c_y;
  int32_T c25_i18;
  int32_T c25_i19;
  real_T c25_b_u;
  const mxArray *c25_d_y = NULL;
  int32_T c25_i20;
  real_T c25_c_u;
  const mxArray *c25_e_y = NULL;
  int32_T c25_i21;
  real_T c25_d_u;
  const mxArray *c25_f_y = NULL;
  int32_T c25_i22;
  int32_T c25_i23;
  int32_T c25_i24;
  int32_T c25_i25;
  int32_T c25_i26;
  real_T c25_e_hoistedGlobal[3];
  real_T c25_g_y;
  int32_T c25_i27;
  int32_T c25_i28;
  real_T c25_f_hoistedGlobal[3];
  int32_T c25_i29;
  int32_T c25_i30;
  real_T c25_g_hoistedGlobal[3];
  real_T c25_h_y;
  real_T c25_B;
  real_T c25_i_y;
  real_T c25_j_y;
  real_T c25_k_y;
  real_T c25_l_y;
  int32_T c25_i31;
  int32_T c25_i32;
  int32_T c25_i33;
  int32_T c25_i34;
  real_T *c25_b_u2;
  real_T (*c25_m_y)[3];
  real_T (*c25_b_u1)[12];
  boolean_T guard1 = false;
  c25_b_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c25_m_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c25_b_u1 = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c25_sfEvent);
  c25_hoistedGlobal = *c25_b_u2;
  for (c25_i8 = 0; c25_i8 < 12; c25_i8++) {
    c25_u1[c25_i8] = (*c25_b_u1)[c25_i8];
  }

  c25_u2 = c25_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c25_debug_family_names,
    c25_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_P, 0U, c25_g_sf_marshallOut,
    c25_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_t, 1U, c25_h_sf_marshallOut,
    c25_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_P_wp, 2U, c25_j_sf_marshallOut,
    c25_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_ipsilong, 3U, c25_h_sf_marshallOut,
    c25_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_t_meidianhuijia, 4U,
    c25_h_sf_marshallOut, c25_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_t_chongdianhuiyuanlu, 5U,
    c25_h_sf_marshallOut, c25_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_t_chongdian, 6U,
    c25_h_sf_marshallOut, c25_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_t_wanchengrenwu, 7U,
    c25_h_sf_marshallOut, c25_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_P_wp_cur_xiao, 8U,
    c25_g_sf_marshallOut, c25_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_nargin, 9U, c25_h_sf_marshallOut,
    c25_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_nargout, 10U, c25_h_sf_marshallOut,
    c25_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_u1, 11U, c25_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_u2, 12U, c25_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_y, 13U, c25_g_sf_marshallOut,
    c25_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c25_k, 14U,
    c25_f_sf_marshallOut, c25_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c25_j, 15U,
    c25_e_sf_marshallOut, c25_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c25_i, 16U,
    c25_d_sf_marshallOut, c25_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c25_P_home, 17U,
    c25_c_sf_marshallOut, c25_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c25_P_wp_cur, 18U,
    c25_b_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c25_t_home, 19U,
    c25_sf_marshallOut, c25_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 5);
  for (c25_i9 = 0; c25_i9 < 3; c25_i9++) {
    c25_P[c25_i9] = c25_u1[c25_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 6);
  c25_t = c25_u2;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c25_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 10);
    chartInstance->c25_k = 1.0;
    chartInstance->c25_k_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 14);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c25_j_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 15);
    chartInstance->c25_j = 0.0;
    chartInstance->c25_j_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 18);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 19);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c25_i_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 20);
    chartInstance->c25_i = 0.0;
    chartInstance->c25_i_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 23);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 24);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c25_P_home_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 25);
    for (c25_i10 = 0; c25_i10 < 3; c25_i10++) {
      chartInstance->c25_P_home[c25_i10] = 0.0;
    }

    chartInstance->c25_P_home_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 28);
  for (c25_i11 = 0; c25_i11 < 30; c25_i11++) {
    c25_P_wp[c25_i11] = c25_dv3[c25_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 32);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 33);
  if (CV_EML_IF(0, 1, 4, !chartInstance->c25_P_wp_cur_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 34);
    for (c25_i12 = 0; c25_i12 < 3; c25_i12++) {
      chartInstance->c25_P_wp_cur[c25_i12] = c25_dv4[c25_i12];
    }

    chartInstance->c25_P_wp_cur_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 37);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 38);
  if (CV_EML_IF(0, 1, 5, !chartInstance->c25_t_home_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 39);
    chartInstance->c25_t_home = 0.0;
    chartInstance->c25_t_home_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 42);
  c25_ipsilong = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 44);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, c25_t != 0.0)) {
    c25_b_hoistedGlobal = chartInstance->c25_t_home;
    c25_x = c25_t - c25_b_hoistedGlobal;
    c25_eml_scalar_eg(chartInstance);
    c25_xk = c25_x;
    c25_b_x = c25_xk;
    c25_eml_scalar_eg(chartInstance);
    c25_c_x = c25_b_x / 100.0;
    c25_d_x = c25_c_x;
    c25_d_x = muDoubleScalarFloor(c25_d_x);
    c25_r = c25_b_x - c25_d_x * 100.0;
    if (CV_EML_COND(0, 1, 1, c25_r == 0.0)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 6, true);
      _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 45);
      c25_t_meidianhuijia = c25_t;
      sf_mex_printf("%s =\\n", "t_meidianhuijia");
      c25_u = c25_t_meidianhuijia;
      c25_b_y = NULL;
      sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c25_b_y);
      _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 46);
      chartInstance->c25_i = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 47);
      chartInstance->c25_j = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 48);
      for (c25_i13 = 0; c25_i13 < 3; c25_i13++) {
        chartInstance->c25_P_home[c25_i13] = c25_P[c25_i13];
      }

      _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 49);
      for (c25_i14 = 0; c25_i14 < 3; c25_i14++) {
        chartInstance->c25_P_wp_cur[c25_i14] = c25_dv4[c25_i14];
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 6, false);
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 51);
    for (c25_i15 = 0; c25_i15 < 3; c25_i15++) {
      c25_c_hoistedGlobal[c25_i15] = chartInstance->c25_P_wp_cur[c25_i15];
    }

    for (c25_i16 = 0; c25_i16 < 3; c25_i16++) {
      c25_c_hoistedGlobal[c25_i16] -= c25_P[c25_i16];
    }

    for (c25_i17 = 0; c25_i17 < 3; c25_i17++) {
      c25_d_hoistedGlobal[c25_i17] = c25_c_hoistedGlobal[c25_i17];
    }

    c25_c_y = c25_eml_xnrm2(chartInstance, c25_d_hoistedGlobal);
    if (CV_EML_IF(0, 1, 7, c25_c_y > c25_ipsilong)) {
    } else {
      _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 53);
      if (CV_EML_IF(0, 1, 8, chartInstance->c25_i == 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 54);
        if (CV_EML_IF(0, 1, 9, chartInstance->c25_j == 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 55);
          chartInstance->c25_i = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 56);
          c25_i18 = _SFD_EML_ARRAY_BOUNDS_CHECK("P_wp", (int32_T)
            _SFD_INTEGER_CHECK("k", chartInstance->c25_k), 1, 10, 2, 0) - 1;
          for (c25_i19 = 0; c25_i19 < 3; c25_i19++) {
            chartInstance->c25_P_wp_cur[c25_i19] = c25_P_wp[c25_i19 + 3 *
              c25_i18];
          }

          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 57);
          c25_t_chongdianhuiyuanlu = c25_t;
          sf_mex_printf("%s =\\n", "t_chongdianhuiyuanlu");
          c25_b_u = c25_t_chongdianhuiyuanlu;
          c25_d_y = NULL;
          sf_mex_assign(&c25_d_y, sf_mex_create("y", &c25_b_u, 0, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c25_d_y);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 60);
          for (c25_i20 = 0; c25_i20 < 3; c25_i20++) {
            chartInstance->c25_P_wp_cur[c25_i20] = chartInstance->
              c25_P_home[c25_i20];
          }

          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 61);
          chartInstance->c25_j = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 62);
          chartInstance->c25_t_home = c25_t;
          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 63);
          c25_t_chongdian = c25_t;
          sf_mex_printf("%s =\\n", "t_chongdian");
          c25_c_u = c25_t_chongdian;
          c25_e_y = NULL;
          sf_mex_assign(&c25_e_y, sf_mex_create("y", &c25_c_u, 0, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c25_e_y);
          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 64);
        }
      } else {
        _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 67);
        if (CV_EML_IF(0, 1, 10, chartInstance->c25_k == 10.0)) {
          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 68);
          for (c25_i21 = 0; c25_i21 < 3; c25_i21++) {
            chartInstance->c25_P_wp_cur[c25_i21] = c25_dv4[c25_i21];
          }

          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 69);
          c25_t_wanchengrenwu = c25_t;
          sf_mex_printf("%s =\\n", "t_wanchengrenwu");
          c25_d_u = c25_t_wanchengrenwu;
          c25_f_y = NULL;
          sf_mex_assign(&c25_f_y, sf_mex_create("y", &c25_d_u, 0, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c25_f_y);
          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 71);
          chartInstance->c25_k++;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 74);
          chartInstance->c25_k++;
          _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 75);
          c25_i22 = _SFD_EML_ARRAY_BOUNDS_CHECK("P_wp", (int32_T)
            _SFD_INTEGER_CHECK("k", chartInstance->c25_k), 1, 10, 2, 0) - 1;
          for (c25_i23 = 0; c25_i23 < 3; c25_i23++) {
            chartInstance->c25_P_wp_cur[c25_i23] = c25_P_wp[c25_i23 + 3 *
              c25_i22];
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 82);
  for (c25_i24 = 0; c25_i24 < 3; c25_i24++) {
    c25_c_hoistedGlobal[c25_i24] = chartInstance->c25_P_wp_cur[c25_i24];
  }

  for (c25_i25 = 0; c25_i25 < 3; c25_i25++) {
    c25_c_hoistedGlobal[c25_i25] -= c25_P[c25_i25];
  }

  for (c25_i26 = 0; c25_i26 < 3; c25_i26++) {
    c25_e_hoistedGlobal[c25_i26] = c25_c_hoistedGlobal[c25_i26];
  }

  c25_g_y = c25_eml_xnrm2(chartInstance, c25_e_hoistedGlobal);
  if (CV_EML_IF(0, 1, 11, c25_g_y >= 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 83);
    for (c25_i27 = 0; c25_i27 < 3; c25_i27++) {
      c25_c_hoistedGlobal[c25_i27] = chartInstance->c25_P_wp_cur[c25_i27];
    }

    for (c25_i28 = 0; c25_i28 < 3; c25_i28++) {
      c25_f_hoistedGlobal[c25_i28] = chartInstance->c25_P_wp_cur[c25_i28];
    }

    for (c25_i29 = 0; c25_i29 < 3; c25_i29++) {
      c25_f_hoistedGlobal[c25_i29] -= c25_P[c25_i29];
    }

    for (c25_i30 = 0; c25_i30 < 3; c25_i30++) {
      c25_g_hoistedGlobal[c25_i30] = c25_f_hoistedGlobal[c25_i30];
    }

    c25_h_y = c25_eml_xnrm2(chartInstance, c25_g_hoistedGlobal);
    c25_B = c25_h_y;
    c25_i_y = c25_B;
    c25_j_y = c25_i_y;
    c25_k_y = c25_j_y;
    c25_l_y = 1.0 / c25_k_y;
    for (c25_i31 = 0; c25_i31 < 3; c25_i31++) {
      c25_P_wp_cur_xiao[c25_i31] = (c25_c_hoistedGlobal[c25_i31] - c25_P[c25_i31])
        * c25_l_y + c25_P[c25_i31];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 85);
    for (c25_i32 = 0; c25_i32 < 3; c25_i32++) {
      c25_P_wp_cur_xiao[c25_i32] = chartInstance->c25_P_wp_cur[c25_i32];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 87);
  for (c25_i33 = 0; c25_i33 < 3; c25_i33++) {
    c25_y[c25_i33] = c25_P_wp_cur_xiao[c25_i33];
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -87);
  _SFD_SYMBOL_SCOPE_POP();
  for (c25_i34 = 0; c25_i34 < 3; c25_i34++) {
    (*c25_m_y)[c25_i34] = c25_y[c25_i34];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c25_sfEvent);
}

static void initSimStructsc25_juecefinishi(SFc25_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber, uint32_T c25_instanceNumber)
{
  (void)c25_machineNumber;
  (void)c25_chartNumber;
  (void)c25_instanceNumber;
}

static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  real_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(real_T *)c25_inData;
  c25_y = NULL;
  if (!chartInstance->c25_t_home_not_empty) {
    sf_mex_assign(&c25_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static real_T c25_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_t_home, const char_T *c25_identifier)
{
  real_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_t_home),
    &c25_thisId);
  sf_mex_destroy(&c25_b_t_home);
  return c25_y;
}

static real_T c25_b_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  real_T c25_y;
  real_T c25_d0;
  if (mxIsEmpty(c25_u)) {
    chartInstance->c25_t_home_not_empty = false;
  } else {
    chartInstance->c25_t_home_not_empty = true;
    sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_d0, 1, 0, 0U, 0, 0U, 0);
    c25_y = c25_d0;
  }

  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_t_home;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_b_t_home = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_t_home),
    &c25_thisId);
  sf_mex_destroy(&c25_b_t_home);
  *(real_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i35;
  real_T c25_b_inData[3];
  int32_T c25_i36;
  real_T c25_u[3];
  const mxArray *c25_y = NULL;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  for (c25_i35 = 0; c25_i35 < 3; c25_i35++) {
    c25_b_inData[c25_i35] = (*(real_T (*)[3])c25_inData)[c25_i35];
  }

  for (c25_i36 = 0; c25_i36 < 3; c25_i36++) {
    c25_u[c25_i36] = c25_b_inData[c25_i36];
  }

  c25_y = NULL;
  if (!chartInstance->c25_P_wp_cur_not_empty) {
    sf_mex_assign(&c25_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 1, 3), false);
  }

  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static void c25_c_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_P_wp_cur, const char_T *c25_identifier,
  real_T c25_y[3])
{
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_P_wp_cur), &c25_thisId,
    c25_y);
  sf_mex_destroy(&c25_b_P_wp_cur);
}

static void c25_d_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[3])
{
  real_T c25_dv5[3];
  int32_T c25_i37;
  if (mxIsEmpty(c25_u)) {
    chartInstance->c25_P_wp_cur_not_empty = false;
  } else {
    chartInstance->c25_P_wp_cur_not_empty = true;
    sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_dv5, 1, 0, 0U, 1, 0U, 1,
                  3);
    for (c25_i37 = 0; c25_i37 < 3; c25_i37++) {
      c25_y[c25_i37] = c25_dv5[c25_i37];
    }
  }

  sf_mex_destroy(&c25_u);
}

static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_P_wp_cur;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y[3];
  int32_T c25_i38;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_b_P_wp_cur = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_P_wp_cur), &c25_thisId,
    c25_y);
  sf_mex_destroy(&c25_b_P_wp_cur);
  for (c25_i38 = 0; c25_i38 < 3; c25_i38++) {
    (*(real_T (*)[3])c25_outData)[c25_i38] = c25_y[c25_i38];
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_c_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i39;
  real_T c25_b_inData[3];
  int32_T c25_i40;
  real_T c25_u[3];
  const mxArray *c25_y = NULL;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  for (c25_i39 = 0; c25_i39 < 3; c25_i39++) {
    c25_b_inData[c25_i39] = (*(real_T (*)[3])c25_inData)[c25_i39];
  }

  for (c25_i40 = 0; c25_i40 < 3; c25_i40++) {
    c25_u[c25_i40] = c25_b_inData[c25_i40];
  }

  c25_y = NULL;
  if (!chartInstance->c25_P_home_not_empty) {
    sf_mex_assign(&c25_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 1, 3), false);
  }

  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static void c25_e_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_P_home, const char_T *c25_identifier,
  real_T c25_y[3])
{
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_P_home), &c25_thisId,
    c25_y);
  sf_mex_destroy(&c25_b_P_home);
}

static void c25_f_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[3])
{
  real_T c25_dv6[3];
  int32_T c25_i41;
  if (mxIsEmpty(c25_u)) {
    chartInstance->c25_P_home_not_empty = false;
  } else {
    chartInstance->c25_P_home_not_empty = true;
    sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_dv6, 1, 0, 0U, 1, 0U, 1,
                  3);
    for (c25_i41 = 0; c25_i41 < 3; c25_i41++) {
      c25_y[c25_i41] = c25_dv6[c25_i41];
    }
  }

  sf_mex_destroy(&c25_u);
}

static void c25_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_P_home;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y[3];
  int32_T c25_i42;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_b_P_home = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_P_home), &c25_thisId,
    c25_y);
  sf_mex_destroy(&c25_b_P_home);
  for (c25_i42 = 0; c25_i42 < 3; c25_i42++) {
    (*(real_T (*)[3])c25_outData)[c25_i42] = c25_y[c25_i42];
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_d_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  real_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(real_T *)c25_inData;
  c25_y = NULL;
  if (!chartInstance->c25_i_not_empty) {
    sf_mex_assign(&c25_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static real_T c25_g_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_i, const char_T *c25_identifier)
{
  real_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_i), &c25_thisId);
  sf_mex_destroy(&c25_b_i);
  return c25_y;
}

static real_T c25_h_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  real_T c25_y;
  real_T c25_d1;
  if (mxIsEmpty(c25_u)) {
    chartInstance->c25_i_not_empty = false;
  } else {
    chartInstance->c25_i_not_empty = true;
    sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_d1, 1, 0, 0U, 0, 0U, 0);
    c25_y = c25_d1;
  }

  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_i;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_b_i = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_i), &c25_thisId);
  sf_mex_destroy(&c25_b_i);
  *(real_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_e_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  real_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(real_T *)c25_inData;
  c25_y = NULL;
  if (!chartInstance->c25_j_not_empty) {
    sf_mex_assign(&c25_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static real_T c25_i_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_j, const char_T *c25_identifier)
{
  real_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_j), &c25_thisId);
  sf_mex_destroy(&c25_b_j);
  return c25_y;
}

static real_T c25_j_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  real_T c25_y;
  real_T c25_d2;
  if (mxIsEmpty(c25_u)) {
    chartInstance->c25_j_not_empty = false;
  } else {
    chartInstance->c25_j_not_empty = true;
    sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_d2, 1, 0, 0U, 0, 0U, 0);
    c25_y = c25_d2;
  }

  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_j;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_b_j = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_j), &c25_thisId);
  sf_mex_destroy(&c25_b_j);
  *(real_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_f_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  real_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(real_T *)c25_inData;
  c25_y = NULL;
  if (!chartInstance->c25_k_not_empty) {
    sf_mex_assign(&c25_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static real_T c25_k_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_k, const char_T *c25_identifier)
{
  real_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_k), &c25_thisId);
  sf_mex_destroy(&c25_b_k);
  return c25_y;
}

static real_T c25_l_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  real_T c25_y;
  real_T c25_d3;
  if (mxIsEmpty(c25_u)) {
    chartInstance->c25_k_not_empty = false;
  } else {
    chartInstance->c25_k_not_empty = true;
    sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_d3, 1, 0, 0U, 0, 0U, 0);
    c25_y = c25_d3;
  }

  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_k;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_b_k = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_k), &c25_thisId);
  sf_mex_destroy(&c25_b_k);
  *(real_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_g_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i43;
  real_T c25_b_inData[3];
  int32_T c25_i44;
  real_T c25_u[3];
  const mxArray *c25_y = NULL;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  for (c25_i43 = 0; c25_i43 < 3; c25_i43++) {
    c25_b_inData[c25_i43] = (*(real_T (*)[3])c25_inData)[c25_i43];
  }

  for (c25_i44 = 0; c25_i44 < 3; c25_i44++) {
    c25_u[c25_i44] = c25_b_inData[c25_i44];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static void c25_m_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_y, const char_T *c25_identifier, real_T
  c25_b_y[3])
{
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_y), &c25_thisId, c25_b_y);
  sf_mex_destroy(&c25_y);
}

static void c25_n_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[3])
{
  real_T c25_dv7[3];
  int32_T c25_i45;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_dv7, 1, 0, 0U, 1, 0U, 1, 3);
  for (c25_i45 = 0; c25_i45 < 3; c25_i45++) {
    c25_y[c25_i45] = c25_dv7[c25_i45];
  }

  sf_mex_destroy(&c25_u);
}

static void c25_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_y;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_b_y[3];
  int32_T c25_i46;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_y = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_y), &c25_thisId, c25_b_y);
  sf_mex_destroy(&c25_y);
  for (c25_i46 = 0; c25_i46 < 3; c25_i46++) {
    (*(real_T (*)[3])c25_outData)[c25_i46] = c25_b_y[c25_i46];
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_h_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  real_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(real_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static const mxArray *c25_i_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i47;
  real_T c25_b_inData[12];
  int32_T c25_i48;
  real_T c25_u[12];
  const mxArray *c25_y = NULL;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  for (c25_i47 = 0; c25_i47 < 12; c25_i47++) {
    c25_b_inData[c25_i47] = (*(real_T (*)[12])c25_inData)[c25_i47];
  }

  for (c25_i48 = 0; c25_i48 < 12; c25_i48++) {
    c25_u[c25_i48] = c25_b_inData[c25_i48];
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static real_T c25_o_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  real_T c25_y;
  real_T c25_d4;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_d4, 1, 0, 0U, 0, 0U, 0);
  c25_y = c25_d4;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_nargout;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_nargout = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_nargout),
    &c25_thisId);
  sf_mex_destroy(&c25_nargout);
  *(real_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_j_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i49;
  int32_T c25_i50;
  int32_T c25_i51;
  real_T c25_b_inData[30];
  int32_T c25_i52;
  int32_T c25_i53;
  int32_T c25_i54;
  real_T c25_u[30];
  const mxArray *c25_y = NULL;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_i49 = 0;
  for (c25_i50 = 0; c25_i50 < 10; c25_i50++) {
    for (c25_i51 = 0; c25_i51 < 3; c25_i51++) {
      c25_b_inData[c25_i51 + c25_i49] = (*(real_T (*)[30])c25_inData)[c25_i51 +
        c25_i49];
    }

    c25_i49 += 3;
  }

  c25_i52 = 0;
  for (c25_i53 = 0; c25_i53 < 10; c25_i53++) {
    for (c25_i54 = 0; c25_i54 < 3; c25_i54++) {
      c25_u[c25_i54 + c25_i52] = c25_b_inData[c25_i54 + c25_i52];
    }

    c25_i52 += 3;
  }

  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 0, 0U, 1U, 0U, 2, 3, 10),
                false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static void c25_p_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_y[30])
{
  real_T c25_dv8[30];
  int32_T c25_i55;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), c25_dv8, 1, 0, 0U, 1, 0U, 2, 3,
                10);
  for (c25_i55 = 0; c25_i55 < 30; c25_i55++) {
    c25_y[c25_i55] = c25_dv8[c25_i55];
  }

  sf_mex_destroy(&c25_u);
}

static void c25_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_P_wp;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y[30];
  int32_T c25_i56;
  int32_T c25_i57;
  int32_T c25_i58;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_P_wp = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_P_wp), &c25_thisId, c25_y);
  sf_mex_destroy(&c25_P_wp);
  c25_i56 = 0;
  for (c25_i57 = 0; c25_i57 < 10; c25_i57++) {
    for (c25_i58 = 0; c25_i58 < 3; c25_i58++) {
      (*(real_T (*)[30])c25_outData)[c25_i58 + c25_i56] = c25_y[c25_i58 +
        c25_i56];
    }

    c25_i56 += 3;
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

const mxArray *sf_c25_juecefinishi_get_eml_resolved_functions_info(void)
{
  const mxArray *c25_nameCaptureInfo = NULL;
  c25_nameCaptureInfo = NULL;
  sf_mex_assign(&c25_nameCaptureInfo, sf_mex_createstruct("structure", 2, 43, 1),
                false);
  c25_info_helper(&c25_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c25_nameCaptureInfo);
  return c25_nameCaptureInfo;
}

static void c25_info_helper(const mxArray **c25_info)
{
  const mxArray *c25_rhs0 = NULL;
  const mxArray *c25_lhs0 = NULL;
  const mxArray *c25_rhs1 = NULL;
  const mxArray *c25_lhs1 = NULL;
  const mxArray *c25_rhs2 = NULL;
  const mxArray *c25_lhs2 = NULL;
  const mxArray *c25_rhs3 = NULL;
  const mxArray *c25_lhs3 = NULL;
  const mxArray *c25_rhs4 = NULL;
  const mxArray *c25_lhs4 = NULL;
  const mxArray *c25_rhs5 = NULL;
  const mxArray *c25_lhs5 = NULL;
  const mxArray *c25_rhs6 = NULL;
  const mxArray *c25_lhs6 = NULL;
  const mxArray *c25_rhs7 = NULL;
  const mxArray *c25_lhs7 = NULL;
  const mxArray *c25_rhs8 = NULL;
  const mxArray *c25_lhs8 = NULL;
  const mxArray *c25_rhs9 = NULL;
  const mxArray *c25_lhs9 = NULL;
  const mxArray *c25_rhs10 = NULL;
  const mxArray *c25_lhs10 = NULL;
  const mxArray *c25_rhs11 = NULL;
  const mxArray *c25_lhs11 = NULL;
  const mxArray *c25_rhs12 = NULL;
  const mxArray *c25_lhs12 = NULL;
  const mxArray *c25_rhs13 = NULL;
  const mxArray *c25_lhs13 = NULL;
  const mxArray *c25_rhs14 = NULL;
  const mxArray *c25_lhs14 = NULL;
  const mxArray *c25_rhs15 = NULL;
  const mxArray *c25_lhs15 = NULL;
  const mxArray *c25_rhs16 = NULL;
  const mxArray *c25_lhs16 = NULL;
  const mxArray *c25_rhs17 = NULL;
  const mxArray *c25_lhs17 = NULL;
  const mxArray *c25_rhs18 = NULL;
  const mxArray *c25_lhs18 = NULL;
  const mxArray *c25_rhs19 = NULL;
  const mxArray *c25_lhs19 = NULL;
  const mxArray *c25_rhs20 = NULL;
  const mxArray *c25_lhs20 = NULL;
  const mxArray *c25_rhs21 = NULL;
  const mxArray *c25_lhs21 = NULL;
  const mxArray *c25_rhs22 = NULL;
  const mxArray *c25_lhs22 = NULL;
  const mxArray *c25_rhs23 = NULL;
  const mxArray *c25_lhs23 = NULL;
  const mxArray *c25_rhs24 = NULL;
  const mxArray *c25_lhs24 = NULL;
  const mxArray *c25_rhs25 = NULL;
  const mxArray *c25_lhs25 = NULL;
  const mxArray *c25_rhs26 = NULL;
  const mxArray *c25_lhs26 = NULL;
  const mxArray *c25_rhs27 = NULL;
  const mxArray *c25_lhs27 = NULL;
  const mxArray *c25_rhs28 = NULL;
  const mxArray *c25_lhs28 = NULL;
  const mxArray *c25_rhs29 = NULL;
  const mxArray *c25_lhs29 = NULL;
  const mxArray *c25_rhs30 = NULL;
  const mxArray *c25_lhs30 = NULL;
  const mxArray *c25_rhs31 = NULL;
  const mxArray *c25_lhs31 = NULL;
  const mxArray *c25_rhs32 = NULL;
  const mxArray *c25_lhs32 = NULL;
  const mxArray *c25_rhs33 = NULL;
  const mxArray *c25_lhs33 = NULL;
  const mxArray *c25_rhs34 = NULL;
  const mxArray *c25_lhs34 = NULL;
  const mxArray *c25_rhs35 = NULL;
  const mxArray *c25_lhs35 = NULL;
  const mxArray *c25_rhs36 = NULL;
  const mxArray *c25_lhs36 = NULL;
  const mxArray *c25_rhs37 = NULL;
  const mxArray *c25_lhs37 = NULL;
  const mxArray *c25_rhs38 = NULL;
  const mxArray *c25_lhs38 = NULL;
  const mxArray *c25_rhs39 = NULL;
  const mxArray *c25_lhs39 = NULL;
  const mxArray *c25_rhs40 = NULL;
  const mxArray *c25_lhs40 = NULL;
  const mxArray *c25_rhs41 = NULL;
  const mxArray *c25_lhs41 = NULL;
  const mxArray *c25_rhs42 = NULL;
  const mxArray *c25_lhs42 = NULL;
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mod"), "name", "name", 0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363717454U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c25_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c25_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c25_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c25_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c25_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c25_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 6);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 6);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c25_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 7);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 7);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286825926U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c25_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 8);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 8);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307658438U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c25_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 9);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 9);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286825912U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c25_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 10);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eps"), "name", "name", 10);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c25_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 11);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286825982U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c25_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_eps"), "name", "name",
                  12);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c25_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 13);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c25_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context", 14);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("norm"), "name", "name", 14);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363717468U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c25_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 15);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 15);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c25_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 16);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c25_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 17);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  17);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375987892U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c25_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 18);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c25_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 19);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c25_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 20);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 20);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c25_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 21);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 21);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c25_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 22);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 22);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c25_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 23);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.refblas.xnrm2"), "name", "name", 23);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c25_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 24);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("realmin"), "name", "name",
                  24);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307658442U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c25_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 25);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1307658444U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c25_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 26);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c25_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 27);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 27);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c25_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 28);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 28);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 28);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c25_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 29);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 29);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 29);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c25_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 30);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 30);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c25_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 31);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("intmax"), "name", "name", 31);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c25_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 32);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c25_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 33);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("abs"), "name", "name", 33);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363717452U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c25_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c25_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 35);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286825912U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c25_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context", 36);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mrdivide"), "name", "name",
                  36);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1388463696U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1370017086U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c25_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 37);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 37);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c25_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 38);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("rdivide"), "name", "name",
                  38);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c25_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 39);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c25_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 40);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286825996U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c25_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_div"), "name", "name",
                  41);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c25_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 42);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c25_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs42), "lhs", "lhs",
                  42);
  sf_mex_destroy(&c25_rhs0);
  sf_mex_destroy(&c25_lhs0);
  sf_mex_destroy(&c25_rhs1);
  sf_mex_destroy(&c25_lhs1);
  sf_mex_destroy(&c25_rhs2);
  sf_mex_destroy(&c25_lhs2);
  sf_mex_destroy(&c25_rhs3);
  sf_mex_destroy(&c25_lhs3);
  sf_mex_destroy(&c25_rhs4);
  sf_mex_destroy(&c25_lhs4);
  sf_mex_destroy(&c25_rhs5);
  sf_mex_destroy(&c25_lhs5);
  sf_mex_destroy(&c25_rhs6);
  sf_mex_destroy(&c25_lhs6);
  sf_mex_destroy(&c25_rhs7);
  sf_mex_destroy(&c25_lhs7);
  sf_mex_destroy(&c25_rhs8);
  sf_mex_destroy(&c25_lhs8);
  sf_mex_destroy(&c25_rhs9);
  sf_mex_destroy(&c25_lhs9);
  sf_mex_destroy(&c25_rhs10);
  sf_mex_destroy(&c25_lhs10);
  sf_mex_destroy(&c25_rhs11);
  sf_mex_destroy(&c25_lhs11);
  sf_mex_destroy(&c25_rhs12);
  sf_mex_destroy(&c25_lhs12);
  sf_mex_destroy(&c25_rhs13);
  sf_mex_destroy(&c25_lhs13);
  sf_mex_destroy(&c25_rhs14);
  sf_mex_destroy(&c25_lhs14);
  sf_mex_destroy(&c25_rhs15);
  sf_mex_destroy(&c25_lhs15);
  sf_mex_destroy(&c25_rhs16);
  sf_mex_destroy(&c25_lhs16);
  sf_mex_destroy(&c25_rhs17);
  sf_mex_destroy(&c25_lhs17);
  sf_mex_destroy(&c25_rhs18);
  sf_mex_destroy(&c25_lhs18);
  sf_mex_destroy(&c25_rhs19);
  sf_mex_destroy(&c25_lhs19);
  sf_mex_destroy(&c25_rhs20);
  sf_mex_destroy(&c25_lhs20);
  sf_mex_destroy(&c25_rhs21);
  sf_mex_destroy(&c25_lhs21);
  sf_mex_destroy(&c25_rhs22);
  sf_mex_destroy(&c25_lhs22);
  sf_mex_destroy(&c25_rhs23);
  sf_mex_destroy(&c25_lhs23);
  sf_mex_destroy(&c25_rhs24);
  sf_mex_destroy(&c25_lhs24);
  sf_mex_destroy(&c25_rhs25);
  sf_mex_destroy(&c25_lhs25);
  sf_mex_destroy(&c25_rhs26);
  sf_mex_destroy(&c25_lhs26);
  sf_mex_destroy(&c25_rhs27);
  sf_mex_destroy(&c25_lhs27);
  sf_mex_destroy(&c25_rhs28);
  sf_mex_destroy(&c25_lhs28);
  sf_mex_destroy(&c25_rhs29);
  sf_mex_destroy(&c25_lhs29);
  sf_mex_destroy(&c25_rhs30);
  sf_mex_destroy(&c25_lhs30);
  sf_mex_destroy(&c25_rhs31);
  sf_mex_destroy(&c25_lhs31);
  sf_mex_destroy(&c25_rhs32);
  sf_mex_destroy(&c25_lhs32);
  sf_mex_destroy(&c25_rhs33);
  sf_mex_destroy(&c25_lhs33);
  sf_mex_destroy(&c25_rhs34);
  sf_mex_destroy(&c25_lhs34);
  sf_mex_destroy(&c25_rhs35);
  sf_mex_destroy(&c25_lhs35);
  sf_mex_destroy(&c25_rhs36);
  sf_mex_destroy(&c25_lhs36);
  sf_mex_destroy(&c25_rhs37);
  sf_mex_destroy(&c25_lhs37);
  sf_mex_destroy(&c25_rhs38);
  sf_mex_destroy(&c25_lhs38);
  sf_mex_destroy(&c25_rhs39);
  sf_mex_destroy(&c25_lhs39);
  sf_mex_destroy(&c25_rhs40);
  sf_mex_destroy(&c25_lhs40);
  sf_mex_destroy(&c25_rhs41);
  sf_mex_destroy(&c25_lhs41);
  sf_mex_destroy(&c25_rhs42);
  sf_mex_destroy(&c25_lhs42);
}

static const mxArray *c25_emlrt_marshallOut(const char * c25_u)
{
  const mxArray *c25_y = NULL;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", c25_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c25_u)), false);
  return c25_y;
}

static const mxArray *c25_b_emlrt_marshallOut(const uint32_T c25_u)
{
  const mxArray *c25_y = NULL;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 7, 0U, 0U, 0U, 0), false);
  return c25_y;
}

static void c25_eml_scalar_eg(SFc25_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c25_eml_xnrm2(SFc25_juecefinishiInstanceStruct *chartInstance,
  real_T c25_x[3])
{
  real_T c25_y;
  real_T c25_scale;
  int32_T c25_b_k;
  int32_T c25_c_k;
  real_T c25_b_x;
  real_T c25_c_x;
  real_T c25_absxk;
  real_T c25_t;
  (void)chartInstance;
  c25_y = 0.0;
  c25_scale = 2.2250738585072014E-308;
  for (c25_b_k = 1; c25_b_k < 4; c25_b_k++) {
    c25_c_k = c25_b_k;
    c25_b_x = c25_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c25_c_k), 1, 3, 1, 0) - 1];
    c25_c_x = c25_b_x;
    c25_absxk = muDoubleScalarAbs(c25_c_x);
    if (c25_absxk > c25_scale) {
      c25_t = c25_scale / c25_absxk;
      c25_y = 1.0 + c25_y * c25_t * c25_t;
      c25_scale = c25_absxk;
    } else {
      c25_t = c25_absxk / c25_scale;
      c25_y += c25_t * c25_t;
    }
  }

  return c25_scale * muDoubleScalarSqrt(c25_y);
}

static const mxArray *c25_k_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(int32_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, false);
  return c25_mxArrayOutData;
}

static int32_T c25_q_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  int32_T c25_y;
  int32_T c25_i59;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_i59, 1, 6, 0U, 0, 0U, 0);
  c25_y = c25_i59;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_sfEvent;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  int32_T c25_y;
  SFc25_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc25_juecefinishiInstanceStruct *)chartInstanceVoid;
  c25_b_sfEvent = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_sfEvent),
    &c25_thisId);
  sf_mex_destroy(&c25_b_sfEvent);
  *(int32_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static uint8_T c25_r_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_b_is_active_c25_juecefinishi, const char_T *
  c25_identifier)
{
  uint8_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c25_b_is_active_c25_juecefinishi), &c25_thisId);
  sf_mex_destroy(&c25_b_is_active_c25_juecefinishi);
  return c25_y;
}

static uint8_T c25_s_emlrt_marshallIn(SFc25_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  uint8_T c25_y;
  uint8_T c25_u0;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_u0, 1, 3, 0U, 0, 0U, 0);
  c25_y = c25_u0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void init_dsm_address_info(SFc25_juecefinishiInstanceStruct
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

void sf_c25_juecefinishi_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(973449671U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2968617657U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1314166447U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2795986703U);
}

mxArray *sf_c25_juecefinishi_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6ZtrKNVYVtpMy6GaOOdN7B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
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

mxArray *sf_c25_juecefinishi_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c25_juecefinishi_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c25_juecefinishi(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[4],M[0],T\"P_home\",S'l','i','p'{{M1x2[215 221],M[0],}}},{M[4],M[0],T\"P_wp_cur\",S'l','i','p'{{M1x2[397 405],M[0],}}},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[173 174],M[0],}}},{M[4],M[0],T\"j\",S'l','i','p'{{M1x2[131 132],M[0],}}},{M[4],M[0],T\"k\",S'l','i','p'{{M1x2[89 90],M[0],}}},{M[4],M[0],T\"t_home\",S'l','i','p'{{M1x2[469 475],M[0],}}},{M[8],M[0],T\"is_active_c25_juecefinishi\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c25_juecefinishi_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc25_juecefinishiInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc25_juecefinishiInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _juecefinishiMachineNumber_,
           25,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
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
        _SFD_CV_INIT_EML(0,1,1,12,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1675);
        _SFD_CV_INIT_EML_IF(0,1,0,92,105,-1,118);
        _SFD_CV_INIT_EML_IF(0,1,1,134,147,-1,160);
        _SFD_CV_INIT_EML_IF(0,1,2,176,189,-1,202);
        _SFD_CV_INIT_EML_IF(0,1,3,223,241,-1,265);
        _SFD_CV_INIT_EML_IF(0,1,4,407,427,-1,454);
        _SFD_CV_INIT_EML_IF(0,1,5,477,495,-1,513);
        _SFD_CV_INIT_EML_IF(0,1,6,535,568,683,1531);
        _SFD_CV_INIT_EML_IF(0,1,7,720,748,788,1525);
        _SFD_CV_INIT_EML_IF(0,1,8,830,837,1211,1515);
        _SFD_CV_INIT_EML_IF(0,1,9,872,879,1028,1200);
        _SFD_CV_INIT_EML_IF(0,1,10,1253,1261,1387,1501);
        _SFD_CV_INIT_EML_IF(0,1,11,1535,1557,1616,1652);

        {
          static int condStart[] = { 538, 546 };

          static int condEnd[] = { 542, 568 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,538,568,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_g_sf_marshallOut,(MexInFcnForType)
            c25_g_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_h_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c25_u2;
          real_T (*c25_u1)[12];
          real_T (*c25_y)[3];
          c25_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c25_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c25_u1 = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c25_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c25_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c25_u2);
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
  return "G3SHjicokPj7Yo9Hbiy79F";
}

static void sf_opaque_initialize_c25_juecefinishi(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc25_juecefinishiInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c25_juecefinishi((SFc25_juecefinishiInstanceStruct*)
    chartInstanceVar);
  initialize_c25_juecefinishi((SFc25_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c25_juecefinishi(void *chartInstanceVar)
{
  enable_c25_juecefinishi((SFc25_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c25_juecefinishi(void *chartInstanceVar)
{
  disable_c25_juecefinishi((SFc25_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c25_juecefinishi(void *chartInstanceVar)
{
  sf_gateway_c25_juecefinishi((SFc25_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c25_juecefinishi(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c25_juecefinishi
    ((SFc25_juecefinishiInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c25_juecefinishi();/* state var info */
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

extern void sf_internal_set_sim_state_c25_juecefinishi(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c25_juecefinishi();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c25_juecefinishi((SFc25_juecefinishiInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c25_juecefinishi(SimStruct* S)
{
  return sf_internal_get_sim_state_c25_juecefinishi(S);
}

static void sf_opaque_set_sim_state_c25_juecefinishi(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c25_juecefinishi(S, st);
}

static void sf_opaque_terminate_c25_juecefinishi(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc25_juecefinishiInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_juecefinishi_optimization_info();
    }

    finalize_c25_juecefinishi((SFc25_juecefinishiInstanceStruct*)
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
  initSimStructsc25_juecefinishi((SFc25_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c25_juecefinishi(SimStruct *S)
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
    initialize_params_c25_juecefinishi((SFc25_juecefinishiInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c25_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_juecefinishi_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      25);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,25,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,25,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,25);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,25,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,25,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,25);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1664448785U));
  ssSetChecksum1(S,(2524275357U));
  ssSetChecksum2(S,(802735108U));
  ssSetChecksum3(S,(1702260168U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c25_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c25_juecefinishi(SimStruct *S)
{
  SFc25_juecefinishiInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc25_juecefinishiInstanceStruct *)utMalloc(sizeof
    (SFc25_juecefinishiInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc25_juecefinishiInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c25_juecefinishi;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c25_juecefinishi;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c25_juecefinishi;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c25_juecefinishi;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c25_juecefinishi;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c25_juecefinishi;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c25_juecefinishi;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c25_juecefinishi;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c25_juecefinishi;
  chartInstance->chartInfo.mdlStart = mdlStart_c25_juecefinishi;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c25_juecefinishi;
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

void c25_juecefinishi_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c25_juecefinishi(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c25_juecefinishi(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c25_juecefinishi(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c25_juecefinishi_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
