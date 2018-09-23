/* Include files */

#include <stddef.h>
#include "blas.h"
#include "juecefinishi_sfun.h"
#include "c33_juecefinishi.h"
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
static const char * c33_debug_family_names[33] = { "I", "O", "dt", "Gt", "Ht",
  "Ra", "Rv", "Rx", "Rt", "Qp", "Qt", "X_t", "V_t", "M_t", "Kt", "Zp", "Zv",
  "Zt", "hp", "hv", "ht", "Ut", "nargin", "nargout", "p", "a", "R", "P", "V",
  "Xt", "Vt", "Mt", "a_last" };

/* Function Declarations */
static void initialize_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance);
static void initialize_params_c33_juecefinishi(SFc33_juecefinishiInstanceStruct *
  chartInstance);
static void enable_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance);
static void disable_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance);
static void c33_update_debugger_state_c33_juecefinishi
  (SFc33_juecefinishiInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c33_juecefinishi
  (SFc33_juecefinishiInstanceStruct *chartInstance);
static void set_sim_state_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_st);
static void finalize_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance);
static void sf_gateway_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance);
static void c33_chartstep_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance);
static void initSimStructsc33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber, uint32_T c33_instanceNumber);
static const mxArray *c33_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static void c33_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c33_b_a_last, const char_T *c33_identifier, real_T c33_y[3]);
static void c33_b_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[3]);
static void c33_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_b_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static void c33_c_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_b_Mt, const char_T *c33_identifier, real_T
  c33_y[36]);
static void c33_d_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[36]);
static void c33_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_c_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static void c33_e_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_b_Vt, const char_T *c33_identifier, real_T
  c33_y[3]);
static void c33_f_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[3]);
static void c33_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_d_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static void c33_g_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_b_Xt, const char_T *c33_identifier, real_T
  c33_y[3]);
static void c33_h_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[3]);
static void c33_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_e_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static void c33_i_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_V, const char_T *c33_identifier, real_T
  c33_y[3]);
static void c33_j_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[3]);
static void c33_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_f_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static const mxArray *c33_g_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static real_T c33_k_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_h_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static void c33_l_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[6]);
static void c33_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_i_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static void c33_m_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[36]);
static void c33_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static void c33_n_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[9]);
static void c33_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static void c33_info_helper(const mxArray **c33_info);
static const mxArray *c33_emlrt_marshallOut(const char * c33_u);
static const mxArray *c33_b_emlrt_marshallOut(const uint32_T c33_u);
static void c33_b_info_helper(const mxArray **c33_info);
static void c33_c_info_helper(const mxArray **c33_info);
static void c33_eml_scalar_eg(SFc33_juecefinishiInstanceStruct *chartInstance);
static void c33_threshold(SFc33_juecefinishiInstanceStruct *chartInstance);
static void c33_eml_switch_helper(SFc33_juecefinishiInstanceStruct
  *chartInstance);
static void c33_b_eml_switch_helper(SFc33_juecefinishiInstanceStruct
  *chartInstance);
static void c33_b_eml_scalar_eg(SFc33_juecefinishiInstanceStruct *chartInstance);
static void c33_c_eml_scalar_eg(SFc33_juecefinishiInstanceStruct *chartInstance);
static void c33_inv(SFc33_juecefinishiInstanceStruct *chartInstance, real_T
                    c33_x[36], real_T c33_y[36]);
static void c33_eps(SFc33_juecefinishiInstanceStruct *chartInstance);
static void c33_eml_matlab_zgetrf(SFc33_juecefinishiInstanceStruct
  *chartInstance, real_T c33_A[36], real_T c33_b_A[36], int32_T c33_ipiv[6],
  int32_T *c33_info);
static int32_T c33_eml_ixamax(SFc33_juecefinishiInstanceStruct *chartInstance,
  int32_T c33_n, real_T c33_x[36], int32_T c33_ix0);
static void c33_check_forloop_overflow_error(SFc33_juecefinishiInstanceStruct
  *chartInstance, boolean_T c33_overflow);
static void c33_b_threshold(SFc33_juecefinishiInstanceStruct *chartInstance);
static void c33_eml_xgeru(SFc33_juecefinishiInstanceStruct *chartInstance,
  int32_T c33_m, int32_T c33_n, real_T c33_alpha1, int32_T c33_ix0, int32_T
  c33_iy0, real_T c33_A[36], int32_T c33_ia0, real_T c33_b_A[36]);
static void c33_eml_ipiv2perm(SFc33_juecefinishiInstanceStruct *chartInstance,
  int32_T c33_ipiv[6], int32_T c33_perm[6]);
static void c33_eml_xtrsm(SFc33_juecefinishiInstanceStruct *chartInstance,
  real_T c33_A[36], real_T c33_B[36], real_T c33_b_B[36]);
static void c33_c_threshold(SFc33_juecefinishiInstanceStruct *chartInstance);
static real_T c33_norm(SFc33_juecefinishiInstanceStruct *chartInstance, real_T
  c33_x[36]);
static void c33_eml_warning(SFc33_juecefinishiInstanceStruct *chartInstance);
static void c33_b_eml_warning(SFc33_juecefinishiInstanceStruct *chartInstance,
  char_T c33_varargin_2[14]);
static void c33_d_eml_scalar_eg(SFc33_juecefinishiInstanceStruct *chartInstance);
static void c33_eye(SFc33_juecefinishiInstanceStruct *chartInstance, real_T
                    c33_I[36]);
static void c33_o_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_sprintf, const char_T *c33_identifier,
  char_T c33_y[14]);
static void c33_p_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  char_T c33_y[14]);
static const mxArray *c33_j_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static int32_T c33_q_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static uint8_T c33_r_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_b_is_active_c33_juecefinishi, const char_T *
  c33_identifier);
static uint8_T c33_s_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_b_eml_matlab_zgetrf(SFc33_juecefinishiInstanceStruct
  *chartInstance, real_T c33_A[36], int32_T c33_ipiv[6], int32_T *c33_info);
static void c33_b_eml_xgeru(SFc33_juecefinishiInstanceStruct *chartInstance,
  int32_T c33_m, int32_T c33_n, real_T c33_alpha1, int32_T c33_ix0, int32_T
  c33_iy0, real_T c33_A[36], int32_T c33_ia0);
static void c33_b_eml_xtrsm(SFc33_juecefinishiInstanceStruct *chartInstance,
  real_T c33_A[36], real_T c33_B[36]);
static void init_dsm_address_info(SFc33_juecefinishiInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance)
{
  chartInstance->c33_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c33_Xt_not_empty = false;
  chartInstance->c33_Vt_not_empty = false;
  chartInstance->c33_Mt_not_empty = false;
  chartInstance->c33_a_last_not_empty = false;
  chartInstance->c33_is_active_c33_juecefinishi = 0U;
}

static void initialize_params_c33_juecefinishi(SFc33_juecefinishiInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c33_update_debugger_state_c33_juecefinishi
  (SFc33_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c33_juecefinishi
  (SFc33_juecefinishiInstanceStruct *chartInstance)
{
  const mxArray *c33_st;
  const mxArray *c33_y = NULL;
  int32_T c33_i0;
  real_T c33_u[3];
  const mxArray *c33_b_y = NULL;
  int32_T c33_i1;
  real_T c33_b_u[3];
  const mxArray *c33_c_y = NULL;
  int32_T c33_i2;
  real_T c33_c_u[36];
  const mxArray *c33_d_y = NULL;
  int32_T c33_i3;
  real_T c33_d_u[3];
  const mxArray *c33_e_y = NULL;
  int32_T c33_i4;
  real_T c33_e_u[3];
  const mxArray *c33_f_y = NULL;
  int32_T c33_i5;
  real_T c33_f_u[3];
  const mxArray *c33_g_y = NULL;
  uint8_T c33_hoistedGlobal;
  uint8_T c33_g_u;
  const mxArray *c33_h_y = NULL;
  real_T (*c33_V)[3];
  real_T (*c33_P)[3];
  c33_V = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c33_P = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c33_st = NULL;
  c33_st = NULL;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_createcellmatrix(7, 1), false);
  for (c33_i0 = 0; c33_i0 < 3; c33_i0++) {
    c33_u[c33_i0] = (*c33_P)[c33_i0];
  }

  c33_b_y = NULL;
  sf_mex_assign(&c33_b_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c33_y, 0, c33_b_y);
  for (c33_i1 = 0; c33_i1 < 3; c33_i1++) {
    c33_b_u[c33_i1] = (*c33_V)[c33_i1];
  }

  c33_c_y = NULL;
  sf_mex_assign(&c33_c_y, sf_mex_create("y", c33_b_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c33_y, 1, c33_c_y);
  for (c33_i2 = 0; c33_i2 < 36; c33_i2++) {
    c33_c_u[c33_i2] = chartInstance->c33_Mt[c33_i2];
  }

  c33_d_y = NULL;
  if (!chartInstance->c33_Mt_not_empty) {
    sf_mex_assign(&c33_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c33_d_y, sf_mex_create("y", c33_c_u, 0, 0U, 1U, 0U, 2, 6, 6),
                  false);
  }

  sf_mex_setcell(c33_y, 2, c33_d_y);
  for (c33_i3 = 0; c33_i3 < 3; c33_i3++) {
    c33_d_u[c33_i3] = chartInstance->c33_Vt[c33_i3];
  }

  c33_e_y = NULL;
  if (!chartInstance->c33_Vt_not_empty) {
    sf_mex_assign(&c33_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c33_e_y, sf_mex_create("y", c33_d_u, 0, 0U, 1U, 0U, 1, 3),
                  false);
  }

  sf_mex_setcell(c33_y, 3, c33_e_y);
  for (c33_i4 = 0; c33_i4 < 3; c33_i4++) {
    c33_e_u[c33_i4] = chartInstance->c33_Xt[c33_i4];
  }

  c33_f_y = NULL;
  if (!chartInstance->c33_Xt_not_empty) {
    sf_mex_assign(&c33_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c33_f_y, sf_mex_create("y", c33_e_u, 0, 0U, 1U, 0U, 1, 3),
                  false);
  }

  sf_mex_setcell(c33_y, 4, c33_f_y);
  for (c33_i5 = 0; c33_i5 < 3; c33_i5++) {
    c33_f_u[c33_i5] = chartInstance->c33_a_last[c33_i5];
  }

  c33_g_y = NULL;
  if (!chartInstance->c33_a_last_not_empty) {
    sf_mex_assign(&c33_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c33_g_y, sf_mex_create("y", c33_f_u, 0, 0U, 1U, 0U, 1, 3),
                  false);
  }

  sf_mex_setcell(c33_y, 5, c33_g_y);
  c33_hoistedGlobal = chartInstance->c33_is_active_c33_juecefinishi;
  c33_g_u = c33_hoistedGlobal;
  c33_h_y = NULL;
  sf_mex_assign(&c33_h_y, sf_mex_create("y", &c33_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c33_y, 6, c33_h_y);
  sf_mex_assign(&c33_st, c33_y, false);
  return c33_st;
}

static void set_sim_state_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_st)
{
  const mxArray *c33_u;
  real_T c33_dv0[3];
  int32_T c33_i6;
  real_T c33_dv1[3];
  int32_T c33_i7;
  real_T c33_dv2[36];
  int32_T c33_i8;
  real_T c33_dv3[3];
  int32_T c33_i9;
  real_T c33_dv4[3];
  int32_T c33_i10;
  real_T c33_dv5[3];
  int32_T c33_i11;
  real_T (*c33_P)[3];
  real_T (*c33_V)[3];
  c33_V = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c33_P = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c33_doneDoubleBufferReInit = true;
  c33_u = sf_mex_dup(c33_st);
  c33_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 0)),
    "P", c33_dv0);
  for (c33_i6 = 0; c33_i6 < 3; c33_i6++) {
    (*c33_P)[c33_i6] = c33_dv0[c33_i6];
  }

  c33_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 1)),
    "V", c33_dv1);
  for (c33_i7 = 0; c33_i7 < 3; c33_i7++) {
    (*c33_V)[c33_i7] = c33_dv1[c33_i7];
  }

  c33_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 2)),
    "Mt", c33_dv2);
  for (c33_i8 = 0; c33_i8 < 36; c33_i8++) {
    chartInstance->c33_Mt[c33_i8] = c33_dv2[c33_i8];
  }

  c33_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 3)),
    "Vt", c33_dv3);
  for (c33_i9 = 0; c33_i9 < 3; c33_i9++) {
    chartInstance->c33_Vt[c33_i9] = c33_dv3[c33_i9];
  }

  c33_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 4)),
    "Xt", c33_dv4);
  for (c33_i10 = 0; c33_i10 < 3; c33_i10++) {
    chartInstance->c33_Xt[c33_i10] = c33_dv4[c33_i10];
  }

  c33_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 5)),
                       "a_last", c33_dv5);
  for (c33_i11 = 0; c33_i11 < 3; c33_i11++) {
    chartInstance->c33_a_last[c33_i11] = c33_dv5[c33_i11];
  }

  chartInstance->c33_is_active_c33_juecefinishi = c33_r_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 6)),
     "is_active_c33_juecefinishi");
  sf_mex_destroy(&c33_u);
  c33_update_debugger_state_c33_juecefinishi(chartInstance);
  sf_mex_destroy(&c33_st);
}

static void finalize_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance)
{
  int32_T c33_i12;
  int32_T c33_i13;
  int32_T c33_i14;
  int32_T c33_i15;
  int32_T c33_i16;
  real_T (*c33_V)[3];
  real_T (*c33_R)[9];
  real_T (*c33_a)[3];
  real_T (*c33_P)[3];
  real_T (*c33_p)[3];
  c33_V = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c33_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
  c33_a = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c33_P = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c33_p = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 28U, chartInstance->c33_sfEvent);
  for (c33_i12 = 0; c33_i12 < 3; c33_i12++) {
    _SFD_DATA_RANGE_CHECK((*c33_p)[c33_i12], 0U);
  }

  chartInstance->c33_sfEvent = CALL_EVENT;
  c33_chartstep_c33_juecefinishi(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_juecefinishiMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c33_i13 = 0; c33_i13 < 3; c33_i13++) {
    _SFD_DATA_RANGE_CHECK((*c33_P)[c33_i13], 1U);
  }

  for (c33_i14 = 0; c33_i14 < 3; c33_i14++) {
    _SFD_DATA_RANGE_CHECK((*c33_a)[c33_i14], 2U);
  }

  for (c33_i15 = 0; c33_i15 < 9; c33_i15++) {
    _SFD_DATA_RANGE_CHECK((*c33_R)[c33_i15], 3U);
  }

  for (c33_i16 = 0; c33_i16 < 3; c33_i16++) {
    _SFD_DATA_RANGE_CHECK((*c33_V)[c33_i16], 4U);
  }
}

static void c33_chartstep_c33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance)
{
  int32_T c33_i17;
  real_T c33_p[3];
  int32_T c33_i18;
  real_T c33_a[3];
  int32_T c33_i19;
  real_T c33_R[9];
  uint32_T c33_debug_family_var_map[33];
  real_T c33_I[9];
  real_T c33_O[9];
  real_T c33_dt;
  real_T c33_Gt[36];
  real_T c33_Ht[36];
  real_T c33_Ra[9];
  real_T c33_Rv[9];
  real_T c33_Rx[9];
  real_T c33_Rt[36];
  real_T c33_Qp[9];
  real_T c33_Qt[36];
  real_T c33_X_t[3];
  real_T c33_V_t[3];
  real_T c33_M_t[36];
  real_T c33_Kt[36];
  real_T c33_Zp[3];
  real_T c33_Zv[3];
  real_T c33_Zt[6];
  real_T c33_hp[3];
  real_T c33_hv[3];
  real_T c33_ht[6];
  real_T c33_Ut[6];
  real_T c33_nargin = 3.0;
  real_T c33_nargout = 2.0;
  real_T c33_P[3];
  real_T c33_V[3];
  int32_T c33_i20;
  static real_T c33_dv6[3] = { 1.0, 1.0, -1.0 };

  int32_T c33_i21;
  real_T c33_b_a[9];
  int32_T c33_i22;
  real_T c33_b[3];
  int32_T c33_i23;
  real_T c33_y[3];
  int32_T c33_i24;
  int32_T c33_i25;
  int32_T c33_i26;
  static real_T c33_dv7[3] = { 0.0, 0.0, 9.8 };

  int32_T c33_i27;
  int32_T c33_i28;
  static real_T c33_b_b[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c33_i29;
  int32_T c33_i30;
  int32_T c33_i31;
  int32_T c33_i32;
  int32_T c33_i33;
  int32_T c33_i34;
  int32_T c33_i35;
  static real_T c33_b_y[9] = { 2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 2.0 };

  int32_T c33_i36;
  int32_T c33_i37;
  int32_T c33_i38;
  int32_T c33_i39;
  int32_T c33_i40;
  int32_T c33_i41;
  int32_T c33_i42;
  int32_T c33_i43;
  int32_T c33_i44;
  int32_T c33_i45;
  int32_T c33_i46;
  int32_T c33_i47;
  int32_T c33_i48;
  static real_T c33_c_a[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.01, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 1.0 };

  int32_T c33_i49;
  static real_T c33_d_a[36] = { 1.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 100.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c33_i50;
  static real_T c33_c_b[9] = { 0.01, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.01 };

  int32_T c33_i51;
  int32_T c33_i52;
  int32_T c33_i53;
  int32_T c33_i54;
  int32_T c33_i55;
  real_T c33_C[9];
  int32_T c33_i56;
  int32_T c33_i57;
  int32_T c33_i58;
  int32_T c33_i59;
  int32_T c33_i60;
  int32_T c33_i61;
  int32_T c33_i62;
  int32_T c33_i63;
  int32_T c33_i64;
  int32_T c33_i65;
  int32_T c33_i66;
  int32_T c33_i67;
  int32_T c33_i68;
  int32_T c33_i69;
  int32_T c33_i70;
  int32_T c33_i71;
  int32_T c33_i72;
  int32_T c33_i73;
  int32_T c33_i74;
  int32_T c33_i75;
  int32_T c33_i76;
  int32_T c33_i77;
  int32_T c33_i78;
  int32_T c33_i79;
  int32_T c33_i80;
  int32_T c33_i81;
  int32_T c33_i82;
  int32_T c33_i83;
  int32_T c33_i84;
  int32_T c33_i85;
  int32_T c33_i86;
  int32_T c33_i87;
  int32_T c33_i88;
  int32_T c33_i89;
  int32_T c33_i90;
  int32_T c33_i91;
  int32_T c33_i92;
  int32_T c33_i93;
  int32_T c33_i94;
  int32_T c33_i95;
  int32_T c33_i96;
  int32_T c33_i97;
  int32_T c33_i98;
  int32_T c33_i99;
  int32_T c33_i100;
  int32_T c33_i101;
  real_T c33_hoistedGlobal[36];
  int32_T c33_i102;
  int32_T c33_i103;
  int32_T c33_i104;
  real_T c33_c_y[36];
  int32_T c33_i105;
  int32_T c33_i106;
  int32_T c33_i107;
  int32_T c33_i108;
  int32_T c33_i109;
  real_T c33_d_y[36];
  int32_T c33_i110;
  int32_T c33_i111;
  static real_T c33_d_b[36] = { 1.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.01, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c33_i112;
  int32_T c33_i113;
  int32_T c33_i114;
  int32_T c33_i115;
  int32_T c33_i116;
  int32_T c33_i117;
  int32_T c33_i118;
  static real_T c33_e_b[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0 };

  int32_T c33_i119;
  real_T c33_f_b[36];
  int32_T c33_i120;
  int32_T c33_i121;
  int32_T c33_i122;
  int32_T c33_i123;
  int32_T c33_i124;
  int32_T c33_i125;
  int32_T c33_i126;
  int32_T c33_i127;
  int32_T c33_i128;
  int32_T c33_i129;
  int32_T c33_i130;
  real_T c33_b_hoistedGlobal[36];
  int32_T c33_i131;
  int32_T c33_i132;
  int32_T c33_i133;
  int32_T c33_i134;
  int32_T c33_i135;
  int32_T c33_i136;
  int32_T c33_i137;
  int32_T c33_i138;
  int32_T c33_i139;
  int32_T c33_i140;
  int32_T c33_i141;
  int32_T c33_i142;
  int32_T c33_i143;
  int32_T c33_i144;
  int32_T c33_i145;
  int32_T c33_i146;
  int32_T c33_i147;
  int32_T c33_i148;
  int32_T c33_i149;
  int32_T c33_i150;
  int32_T c33_i151;
  real_T c33_g_b[6];
  int32_T c33_i152;
  real_T c33_e_y[6];
  int32_T c33_i153;
  int32_T c33_i154;
  int32_T c33_i155;
  real_T c33_b_X_t[6];
  int32_T c33_i156;
  int32_T c33_i157;
  int32_T c33_i158;
  int32_T c33_i159;
  int32_T c33_i160;
  int32_T c33_i161;
  int32_T c33_i162;
  int32_T c33_i163;
  int32_T c33_i164;
  int32_T c33_i165;
  int32_T c33_i166;
  int32_T c33_i167;
  int32_T c33_i168;
  int32_T c33_i169;
  int32_T c33_i170;
  int32_T c33_i171;
  int32_T c33_i172;
  int32_T c33_i173;
  int32_T c33_i174;
  int32_T c33_i175;
  int32_T c33_i176;
  real_T (*c33_b_P)[3];
  real_T (*c33_b_V)[3];
  real_T (*c33_b_R)[9];
  real_T (*c33_e_a)[3];
  real_T (*c33_b_p)[3];
  c33_b_V = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c33_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
  c33_e_a = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c33_b_P = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c33_b_p = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 28U, chartInstance->c33_sfEvent);
  for (c33_i17 = 0; c33_i17 < 3; c33_i17++) {
    c33_p[c33_i17] = (*c33_b_p)[c33_i17];
  }

  for (c33_i18 = 0; c33_i18 < 3; c33_i18++) {
    c33_a[c33_i18] = (*c33_e_a)[c33_i18];
  }

  for (c33_i19 = 0; c33_i19 < 9; c33_i19++) {
    c33_R[c33_i19] = (*c33_b_R)[c33_i19];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 33U, 33U, c33_debug_family_names,
    c33_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c33_I, 0U, c33_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c33_O, 1U, c33_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c33_dt, 2U, c33_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c33_Gt, 3U, c33_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c33_Ht, 4U, c33_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c33_Ra, 5U, c33_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_Rv, 6U, c33_f_sf_marshallOut,
    c33_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_Rx, 7U, c33_f_sf_marshallOut,
    c33_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_Rt, 8U, c33_i_sf_marshallOut,
    c33_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_Qp, 9U, c33_f_sf_marshallOut,
    c33_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_Qt, 10U, c33_i_sf_marshallOut,
    c33_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_X_t, 11U, c33_e_sf_marshallOut,
    c33_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_V_t, 12U, c33_e_sf_marshallOut,
    c33_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_M_t, 13U, c33_i_sf_marshallOut,
    c33_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_Kt, 14U, c33_i_sf_marshallOut,
    c33_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_Zp, 15U, c33_e_sf_marshallOut,
    c33_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_Zv, 16U, c33_e_sf_marshallOut,
    c33_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_Zt, 17U, c33_h_sf_marshallOut,
    c33_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_hp, 18U, c33_e_sf_marshallOut,
    c33_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_hv, 19U, c33_e_sf_marshallOut,
    c33_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_ht, 20U, c33_h_sf_marshallOut,
    c33_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_Ut, 21U, c33_h_sf_marshallOut,
    c33_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c33_nargin, 22U, c33_g_sf_marshallOut,
    c33_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c33_nargout, 23U, c33_g_sf_marshallOut,
    c33_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c33_p, 24U, c33_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c33_a, 25U, c33_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c33_R, 26U, c33_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_P, 27U, c33_e_sf_marshallOut,
    c33_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c33_V, 28U, c33_e_sf_marshallOut,
    c33_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c33_Xt, 29U,
    c33_d_sf_marshallOut, c33_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c33_Vt, 30U,
    c33_c_sf_marshallOut, c33_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c33_Mt, 31U,
    c33_b_sf_marshallOut, c33_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c33_a_last, 32U,
    c33_sf_marshallOut, c33_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 3);
  for (c33_i20 = 0; c33_i20 < 3; c33_i20++) {
    c33_p[c33_i20] *= c33_dv6[c33_i20];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 4);
  for (c33_i21 = 0; c33_i21 < 9; c33_i21++) {
    c33_b_a[c33_i21] = c33_R[c33_i21];
  }

  for (c33_i22 = 0; c33_i22 < 3; c33_i22++) {
    c33_b[c33_i22] = c33_a[c33_i22];
  }

  c33_eml_scalar_eg(chartInstance);
  c33_eml_scalar_eg(chartInstance);
  c33_threshold(chartInstance);
  for (c33_i23 = 0; c33_i23 < 3; c33_i23++) {
    c33_y[c33_i23] = 0.0;
    c33_i24 = 0;
    for (c33_i25 = 0; c33_i25 < 3; c33_i25++) {
      c33_y[c33_i23] += c33_b_a[c33_i24 + c33_i23] * c33_b[c33_i25];
      c33_i24 += 3;
    }
  }

  for (c33_i26 = 0; c33_i26 < 3; c33_i26++) {
    c33_a[c33_i26] = c33_y[c33_i26] - c33_dv7[c33_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c33_a_last_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 10);
    for (c33_i27 = 0; c33_i27 < 3; c33_i27++) {
      chartInstance->c33_a_last[c33_i27] = 0.0;
    }

    chartInstance->c33_a_last_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 12);
  for (c33_i28 = 0; c33_i28 < 9; c33_i28++) {
    c33_I[c33_i28] = c33_b_b[c33_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 13);
  for (c33_i29 = 0; c33_i29 < 9; c33_i29++) {
    c33_O[c33_i29] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 14);
  c33_dt = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 15);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c33_Xt_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 16);
    for (c33_i30 = 0; c33_i30 < 3; c33_i30++) {
      chartInstance->c33_Xt[c33_i30] = 0.0;
    }

    chartInstance->c33_Xt_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 18);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c33_Vt_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 19);
    for (c33_i31 = 0; c33_i31 < 3; c33_i31++) {
      chartInstance->c33_Vt[c33_i31] = 0.0;
    }

    chartInstance->c33_Vt_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 21);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c33_Mt_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 22);
    c33_i32 = 0;
    c33_i33 = 0;
    for (c33_i34 = 0; c33_i34 < 3; c33_i34++) {
      for (c33_i35 = 0; c33_i35 < 3; c33_i35++) {
        chartInstance->c33_Mt[c33_i35 + c33_i32] = c33_b_y[c33_i35 + c33_i33];
      }

      c33_i32 += 6;
      c33_i33 += 3;
    }

    c33_i36 = 0;
    c33_i37 = 0;
    for (c33_i38 = 0; c33_i38 < 3; c33_i38++) {
      for (c33_i39 = 0; c33_i39 < 3; c33_i39++) {
        chartInstance->c33_Mt[(c33_i39 + c33_i36) + 18] = c33_O[c33_i39 +
          c33_i37];
      }

      c33_i36 += 6;
      c33_i37 += 3;
    }

    c33_i40 = 0;
    c33_i41 = 0;
    for (c33_i42 = 0; c33_i42 < 3; c33_i42++) {
      for (c33_i43 = 0; c33_i43 < 3; c33_i43++) {
        chartInstance->c33_Mt[(c33_i43 + c33_i40) + 3] = c33_O[c33_i43 + c33_i41];
      }

      c33_i40 += 6;
      c33_i41 += 3;
    }

    c33_i44 = 0;
    c33_i45 = 0;
    for (c33_i46 = 0; c33_i46 < 3; c33_i46++) {
      for (c33_i47 = 0; c33_i47 < 3; c33_i47++) {
        chartInstance->c33_Mt[(c33_i47 + c33_i44) + 21] = c33_I[c33_i47 +
          c33_i45];
      }

      c33_i44 += 6;
      c33_i45 += 3;
    }

    chartInstance->c33_Mt_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 25);
  for (c33_i48 = 0; c33_i48 < 36; c33_i48++) {
    c33_Gt[c33_i48] = c33_c_a[c33_i48];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 27);
  for (c33_i49 = 0; c33_i49 < 36; c33_i49++) {
    c33_Ht[c33_i49] = c33_d_a[c33_i49];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 29);
  for (c33_i50 = 0; c33_i50 < 9; c33_i50++) {
    c33_Ra[c33_i50] = c33_c_b[c33_i50];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 32);
  for (c33_i51 = 0; c33_i51 < 9; c33_i51++) {
    c33_b_a[c33_i51] = c33_R[c33_i51];
  }

  for (c33_i52 = 0; c33_i52 < 9; c33_i52++) {
    c33_b_a[c33_i52] *= 0.01;
  }

  c33_b_eml_scalar_eg(chartInstance);
  c33_b_eml_scalar_eg(chartInstance);
  for (c33_i53 = 0; c33_i53 < 9; c33_i53++) {
    c33_Rv[c33_i53] = 0.0;
  }

  for (c33_i54 = 0; c33_i54 < 9; c33_i54++) {
    c33_Rv[c33_i54] = 0.0;
  }

  for (c33_i55 = 0; c33_i55 < 9; c33_i55++) {
    c33_C[c33_i55] = c33_Rv[c33_i55];
  }

  for (c33_i56 = 0; c33_i56 < 9; c33_i56++) {
    c33_Rv[c33_i56] = c33_C[c33_i56];
  }

  c33_threshold(chartInstance);
  for (c33_i57 = 0; c33_i57 < 9; c33_i57++) {
    c33_C[c33_i57] = c33_Rv[c33_i57];
  }

  for (c33_i58 = 0; c33_i58 < 9; c33_i58++) {
    c33_Rv[c33_i58] = c33_C[c33_i58];
  }

  for (c33_i59 = 0; c33_i59 < 3; c33_i59++) {
    c33_i60 = 0;
    for (c33_i61 = 0; c33_i61 < 3; c33_i61++) {
      c33_Rv[c33_i60 + c33_i59] = 0.0;
      c33_i62 = 0;
      for (c33_i63 = 0; c33_i63 < 3; c33_i63++) {
        c33_Rv[c33_i60 + c33_i59] += c33_b_a[c33_i62 + c33_i59] *
          c33_c_b[c33_i63 + c33_i60];
        c33_i62 += 3;
      }

      c33_i60 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 33);
  for (c33_i64 = 0; c33_i64 < 9; c33_i64++) {
    c33_b_a[c33_i64] = c33_Rv[c33_i64];
  }

  for (c33_i65 = 0; c33_i65 < 9; c33_i65++) {
    c33_Rx[c33_i65] = 0.01 * c33_b_a[c33_i65];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 34);
  c33_i66 = 0;
  c33_i67 = 0;
  for (c33_i68 = 0; c33_i68 < 3; c33_i68++) {
    for (c33_i69 = 0; c33_i69 < 3; c33_i69++) {
      c33_Rt[c33_i69 + c33_i66] = c33_Rx[c33_i69 + c33_i67];
    }

    c33_i66 += 6;
    c33_i67 += 3;
  }

  c33_i70 = 0;
  c33_i71 = 0;
  for (c33_i72 = 0; c33_i72 < 3; c33_i72++) {
    for (c33_i73 = 0; c33_i73 < 3; c33_i73++) {
      c33_Rt[(c33_i73 + c33_i70) + 18] = c33_O[c33_i73 + c33_i71];
    }

    c33_i70 += 6;
    c33_i71 += 3;
  }

  c33_i74 = 0;
  c33_i75 = 0;
  for (c33_i76 = 0; c33_i76 < 3; c33_i76++) {
    for (c33_i77 = 0; c33_i77 < 3; c33_i77++) {
      c33_Rt[(c33_i77 + c33_i74) + 3] = c33_O[c33_i77 + c33_i75];
    }

    c33_i74 += 6;
    c33_i75 += 3;
  }

  c33_i78 = 0;
  c33_i79 = 0;
  for (c33_i80 = 0; c33_i80 < 3; c33_i80++) {
    for (c33_i81 = 0; c33_i81 < 3; c33_i81++) {
      c33_Rt[(c33_i81 + c33_i78) + 21] = c33_Rv[c33_i81 + c33_i79];
    }

    c33_i78 += 6;
    c33_i79 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 36);
  for (c33_i82 = 0; c33_i82 < 9; c33_i82++) {
    c33_Qp[c33_i82] = c33_b_b[c33_i82];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 39);
  c33_i83 = 0;
  c33_i84 = 0;
  for (c33_i85 = 0; c33_i85 < 3; c33_i85++) {
    for (c33_i86 = 0; c33_i86 < 3; c33_i86++) {
      c33_Qt[c33_i86 + c33_i83] = c33_Qp[c33_i86 + c33_i84];
    }

    c33_i83 += 6;
    c33_i84 += 3;
  }

  c33_i87 = 0;
  c33_i88 = 0;
  for (c33_i89 = 0; c33_i89 < 3; c33_i89++) {
    for (c33_i90 = 0; c33_i90 < 3; c33_i90++) {
      c33_Qt[(c33_i90 + c33_i87) + 18] = c33_O[c33_i90 + c33_i88];
    }

    c33_i87 += 6;
    c33_i88 += 3;
  }

  c33_i91 = 0;
  c33_i92 = 0;
  for (c33_i93 = 0; c33_i93 < 3; c33_i93++) {
    for (c33_i94 = 0; c33_i94 < 3; c33_i94++) {
      c33_Qt[(c33_i94 + c33_i91) + 3] = c33_O[c33_i94 + c33_i92];
    }

    c33_i91 += 6;
    c33_i92 += 3;
  }

  c33_i95 = 0;
  c33_i96 = 0;
  for (c33_i97 = 0; c33_i97 < 3; c33_i97++) {
    for (c33_i98 = 0; c33_i98 < 3; c33_i98++) {
      c33_Qt[(c33_i98 + c33_i95) + 21] = c33_O[c33_i98 + c33_i96];
    }

    c33_i95 += 6;
    c33_i96 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 41);
  for (c33_i99 = 0; c33_i99 < 3; c33_i99++) {
    c33_X_t[c33_i99] = chartInstance->c33_Xt[c33_i99] + chartInstance->
      c33_Vt[c33_i99] * c33_dt;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 42);
  for (c33_i100 = 0; c33_i100 < 3; c33_i100++) {
    c33_V_t[c33_i100] = chartInstance->c33_Vt[c33_i100] +
      chartInstance->c33_a_last[c33_i100] * c33_dt;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 43);
  for (c33_i101 = 0; c33_i101 < 36; c33_i101++) {
    c33_hoistedGlobal[c33_i101] = chartInstance->c33_Mt[c33_i101];
  }

  c33_c_eml_scalar_eg(chartInstance);
  c33_c_eml_scalar_eg(chartInstance);
  c33_threshold(chartInstance);
  for (c33_i102 = 0; c33_i102 < 6; c33_i102++) {
    c33_i103 = 0;
    for (c33_i104 = 0; c33_i104 < 6; c33_i104++) {
      c33_c_y[c33_i103 + c33_i102] = 0.0;
      c33_i105 = 0;
      for (c33_i106 = 0; c33_i106 < 6; c33_i106++) {
        c33_c_y[c33_i103 + c33_i102] += c33_c_a[c33_i105 + c33_i102] *
          c33_hoistedGlobal[c33_i106 + c33_i103];
        c33_i105 += 6;
      }

      c33_i103 += 6;
    }
  }

  c33_c_eml_scalar_eg(chartInstance);
  c33_c_eml_scalar_eg(chartInstance);
  c33_threshold(chartInstance);
  for (c33_i107 = 0; c33_i107 < 6; c33_i107++) {
    c33_i108 = 0;
    for (c33_i109 = 0; c33_i109 < 6; c33_i109++) {
      c33_d_y[c33_i108 + c33_i107] = 0.0;
      c33_i110 = 0;
      for (c33_i111 = 0; c33_i111 < 6; c33_i111++) {
        c33_d_y[c33_i108 + c33_i107] += c33_c_y[c33_i110 + c33_i107] *
          c33_d_b[c33_i111 + c33_i108];
        c33_i110 += 6;
      }

      c33_i108 += 6;
    }
  }

  for (c33_i112 = 0; c33_i112 < 36; c33_i112++) {
    c33_M_t[c33_i112] = c33_d_y[c33_i112] + c33_Rt[c33_i112];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 44);
  for (c33_i113 = 0; c33_i113 < 36; c33_i113++) {
    c33_hoistedGlobal[c33_i113] = c33_M_t[c33_i113];
  }

  c33_c_eml_scalar_eg(chartInstance);
  c33_c_eml_scalar_eg(chartInstance);
  c33_threshold(chartInstance);
  for (c33_i114 = 0; c33_i114 < 6; c33_i114++) {
    c33_i115 = 0;
    for (c33_i116 = 0; c33_i116 < 6; c33_i116++) {
      c33_c_y[c33_i115 + c33_i114] = 0.0;
      c33_i117 = 0;
      for (c33_i118 = 0; c33_i118 < 6; c33_i118++) {
        c33_c_y[c33_i115 + c33_i114] += c33_hoistedGlobal[c33_i117 + c33_i114] *
          c33_e_b[c33_i118 + c33_i115];
        c33_i117 += 6;
      }

      c33_i115 += 6;
    }
  }

  for (c33_i119 = 0; c33_i119 < 36; c33_i119++) {
    c33_f_b[c33_i119] = c33_M_t[c33_i119];
  }

  c33_c_eml_scalar_eg(chartInstance);
  c33_c_eml_scalar_eg(chartInstance);
  c33_threshold(chartInstance);
  for (c33_i120 = 0; c33_i120 < 6; c33_i120++) {
    c33_i121 = 0;
    for (c33_i122 = 0; c33_i122 < 6; c33_i122++) {
      c33_d_y[c33_i121 + c33_i120] = 0.0;
      c33_i123 = 0;
      for (c33_i124 = 0; c33_i124 < 6; c33_i124++) {
        c33_d_y[c33_i121 + c33_i120] += c33_d_a[c33_i123 + c33_i120] *
          c33_f_b[c33_i124 + c33_i121];
        c33_i123 += 6;
      }

      c33_i121 += 6;
    }
  }

  c33_c_eml_scalar_eg(chartInstance);
  c33_c_eml_scalar_eg(chartInstance);
  c33_threshold(chartInstance);
  for (c33_i125 = 0; c33_i125 < 6; c33_i125++) {
    c33_i126 = 0;
    for (c33_i127 = 0; c33_i127 < 6; c33_i127++) {
      c33_hoistedGlobal[c33_i126 + c33_i125] = 0.0;
      c33_i128 = 0;
      for (c33_i129 = 0; c33_i129 < 6; c33_i129++) {
        c33_hoistedGlobal[c33_i126 + c33_i125] += c33_d_y[c33_i128 + c33_i125] *
          c33_e_b[c33_i129 + c33_i126];
        c33_i128 += 6;
      }

      c33_i126 += 6;
    }
  }

  for (c33_i130 = 0; c33_i130 < 36; c33_i130++) {
    c33_b_hoistedGlobal[c33_i130] = c33_hoistedGlobal[c33_i130] +
      c33_Qt[c33_i130];
  }

  c33_inv(chartInstance, c33_b_hoistedGlobal, c33_f_b);
  c33_c_eml_scalar_eg(chartInstance);
  c33_c_eml_scalar_eg(chartInstance);
  for (c33_i131 = 0; c33_i131 < 36; c33_i131++) {
    c33_Kt[c33_i131] = 0.0;
  }

  for (c33_i132 = 0; c33_i132 < 36; c33_i132++) {
    c33_Kt[c33_i132] = 0.0;
  }

  for (c33_i133 = 0; c33_i133 < 36; c33_i133++) {
    c33_hoistedGlobal[c33_i133] = c33_Kt[c33_i133];
  }

  for (c33_i134 = 0; c33_i134 < 36; c33_i134++) {
    c33_Kt[c33_i134] = c33_hoistedGlobal[c33_i134];
  }

  c33_threshold(chartInstance);
  for (c33_i135 = 0; c33_i135 < 36; c33_i135++) {
    c33_hoistedGlobal[c33_i135] = c33_Kt[c33_i135];
  }

  for (c33_i136 = 0; c33_i136 < 36; c33_i136++) {
    c33_Kt[c33_i136] = c33_hoistedGlobal[c33_i136];
  }

  for (c33_i137 = 0; c33_i137 < 6; c33_i137++) {
    c33_i138 = 0;
    for (c33_i139 = 0; c33_i139 < 6; c33_i139++) {
      c33_Kt[c33_i138 + c33_i137] = 0.0;
      c33_i140 = 0;
      for (c33_i141 = 0; c33_i141 < 6; c33_i141++) {
        c33_Kt[c33_i138 + c33_i137] += c33_c_y[c33_i140 + c33_i137] *
          c33_f_b[c33_i141 + c33_i138];
        c33_i140 += 6;
      }

      c33_i138 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 45);
  for (c33_i142 = 0; c33_i142 < 3; c33_i142++) {
    c33_Zp[c33_i142] = c33_p[c33_i142];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 46);
  for (c33_i143 = 0; c33_i143 < 3; c33_i143++) {
    c33_Zv[c33_i143] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 47);
  for (c33_i144 = 0; c33_i144 < 3; c33_i144++) {
    c33_Zt[c33_i144] = c33_Zp[c33_i144];
  }

  for (c33_i145 = 0; c33_i145 < 3; c33_i145++) {
    c33_Zt[c33_i145 + 3] = c33_Zv[c33_i145];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 48);
  for (c33_i146 = 0; c33_i146 < 3; c33_i146++) {
    c33_hp[c33_i146] = c33_X_t[c33_i146];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 49);
  for (c33_i147 = 0; c33_i147 < 3; c33_i147++) {
    c33_hv[c33_i147] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 50);
  for (c33_i148 = 0; c33_i148 < 3; c33_i148++) {
    c33_ht[c33_i148] = c33_hp[c33_i148];
  }

  for (c33_i149 = 0; c33_i149 < 3; c33_i149++) {
    c33_ht[c33_i149 + 3] = c33_hv[c33_i149];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 51);
  for (c33_i150 = 0; c33_i150 < 36; c33_i150++) {
    c33_hoistedGlobal[c33_i150] = c33_Kt[c33_i150];
  }

  for (c33_i151 = 0; c33_i151 < 6; c33_i151++) {
    c33_g_b[c33_i151] = c33_Zt[c33_i151] - c33_ht[c33_i151];
  }

  c33_d_eml_scalar_eg(chartInstance);
  c33_d_eml_scalar_eg(chartInstance);
  c33_threshold(chartInstance);
  for (c33_i152 = 0; c33_i152 < 6; c33_i152++) {
    c33_e_y[c33_i152] = 0.0;
    c33_i153 = 0;
    for (c33_i154 = 0; c33_i154 < 6; c33_i154++) {
      c33_e_y[c33_i152] += c33_hoistedGlobal[c33_i153 + c33_i152] *
        c33_g_b[c33_i154];
      c33_i153 += 6;
    }
  }

  for (c33_i155 = 0; c33_i155 < 3; c33_i155++) {
    c33_b_X_t[c33_i155] = c33_X_t[c33_i155];
  }

  for (c33_i156 = 0; c33_i156 < 3; c33_i156++) {
    c33_b_X_t[c33_i156 + 3] = c33_V_t[c33_i156];
  }

  for (c33_i157 = 0; c33_i157 < 6; c33_i157++) {
    c33_Ut[c33_i157] = c33_b_X_t[c33_i157] + c33_e_y[c33_i157];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 52);
  for (c33_i158 = 0; c33_i158 < 36; c33_i158++) {
    c33_hoistedGlobal[c33_i158] = c33_Kt[c33_i158];
  }

  c33_c_eml_scalar_eg(chartInstance);
  c33_c_eml_scalar_eg(chartInstance);
  c33_threshold(chartInstance);
  for (c33_i159 = 0; c33_i159 < 6; c33_i159++) {
    c33_i160 = 0;
    for (c33_i161 = 0; c33_i161 < 6; c33_i161++) {
      c33_c_y[c33_i160 + c33_i159] = 0.0;
      c33_i162 = 0;
      for (c33_i163 = 0; c33_i163 < 6; c33_i163++) {
        c33_c_y[c33_i160 + c33_i159] += c33_hoistedGlobal[c33_i162 + c33_i159] *
          c33_d_a[c33_i163 + c33_i160];
        c33_i162 += 6;
      }

      c33_i160 += 6;
    }
  }

  c33_eye(chartInstance, c33_hoistedGlobal);
  for (c33_i164 = 0; c33_i164 < 36; c33_i164++) {
    c33_hoistedGlobal[c33_i164] -= c33_c_y[c33_i164];
  }

  for (c33_i165 = 0; c33_i165 < 36; c33_i165++) {
    c33_f_b[c33_i165] = c33_M_t[c33_i165];
  }

  c33_c_eml_scalar_eg(chartInstance);
  c33_c_eml_scalar_eg(chartInstance);
  c33_threshold(chartInstance);
  for (c33_i166 = 0; c33_i166 < 6; c33_i166++) {
    c33_i167 = 0;
    for (c33_i168 = 0; c33_i168 < 6; c33_i168++) {
      c33_c_y[c33_i167 + c33_i166] = 0.0;
      c33_i169 = 0;
      for (c33_i170 = 0; c33_i170 < 6; c33_i170++) {
        c33_c_y[c33_i167 + c33_i166] += c33_hoistedGlobal[c33_i169 + c33_i166] *
          c33_f_b[c33_i170 + c33_i167];
        c33_i169 += 6;
      }

      c33_i167 += 6;
    }
  }

  for (c33_i171 = 0; c33_i171 < 36; c33_i171++) {
    chartInstance->c33_Mt[c33_i171] = c33_c_y[c33_i171];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 53);
  chartInstance->c33_Xt[0] = c33_Ut[0];
  chartInstance->c33_Xt[1] = c33_Ut[1];
  chartInstance->c33_Xt[2] = c33_Ut[2];
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 54);
  chartInstance->c33_Vt[0] = c33_Ut[3];
  chartInstance->c33_Vt[1] = c33_Ut[4];
  chartInstance->c33_Vt[2] = c33_Ut[5];
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 55);
  for (c33_i172 = 0; c33_i172 < 3; c33_i172++) {
    chartInstance->c33_a_last[c33_i172] = c33_a[c33_i172];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 56);
  for (c33_i173 = 0; c33_i173 < 3; c33_i173++) {
    c33_P[c33_i173] = chartInstance->c33_Xt[c33_i173];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 57);
  for (c33_i174 = 0; c33_i174 < 3; c33_i174++) {
    c33_V[c33_i174] = chartInstance->c33_Vt[c33_i174];
  }

  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, -57);
  _SFD_SYMBOL_SCOPE_POP();
  for (c33_i175 = 0; c33_i175 < 3; c33_i175++) {
    (*c33_b_P)[c33_i175] = c33_P[c33_i175];
  }

  for (c33_i176 = 0; c33_i176 < 3; c33_i176++) {
    (*c33_b_V)[c33_i176] = c33_V[c33_i176];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c33_sfEvent);
}

static void initSimStructsc33_juecefinishi(SFc33_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber, uint32_T c33_instanceNumber)
{
  (void)c33_machineNumber;
  (void)c33_chartNumber;
  (void)c33_instanceNumber;
}

static const mxArray *c33_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i177;
  real_T c33_b_inData[3];
  int32_T c33_i178;
  real_T c33_u[3];
  const mxArray *c33_y = NULL;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  for (c33_i177 = 0; c33_i177 < 3; c33_i177++) {
    c33_b_inData[c33_i177] = (*(real_T (*)[3])c33_inData)[c33_i177];
  }

  for (c33_i178 = 0; c33_i178 < 3; c33_i178++) {
    c33_u[c33_i178] = c33_b_inData[c33_i178];
  }

  c33_y = NULL;
  if (!chartInstance->c33_a_last_not_empty) {
    sf_mex_assign(&c33_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 1, 3), false);
  }

  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static void c33_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct *chartInstance,
  const mxArray *c33_b_a_last, const char_T *c33_identifier, real_T c33_y[3])
{
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_a_last), &c33_thisId,
    c33_y);
  sf_mex_destroy(&c33_b_a_last);
}

static void c33_b_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[3])
{
  real_T c33_dv8[3];
  int32_T c33_i179;
  if (mxIsEmpty(c33_u)) {
    chartInstance->c33_a_last_not_empty = false;
  } else {
    chartInstance->c33_a_last_not_empty = true;
    sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv8, 1, 0, 0U, 1, 0U, 1,
                  3);
    for (c33_i179 = 0; c33_i179 < 3; c33_i179++) {
      c33_y[c33_i179] = c33_dv8[c33_i179];
    }
  }

  sf_mex_destroy(&c33_u);
}

static void c33_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_a_last;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[3];
  int32_T c33_i180;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_b_a_last = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_a_last), &c33_thisId,
    c33_y);
  sf_mex_destroy(&c33_b_a_last);
  for (c33_i180 = 0; c33_i180 < 3; c33_i180++) {
    (*(real_T (*)[3])c33_outData)[c33_i180] = c33_y[c33_i180];
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_b_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i181;
  int32_T c33_i182;
  int32_T c33_i183;
  real_T c33_b_inData[36];
  int32_T c33_i184;
  int32_T c33_i185;
  int32_T c33_i186;
  real_T c33_u[36];
  const mxArray *c33_y = NULL;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_i181 = 0;
  for (c33_i182 = 0; c33_i182 < 6; c33_i182++) {
    for (c33_i183 = 0; c33_i183 < 6; c33_i183++) {
      c33_b_inData[c33_i183 + c33_i181] = (*(real_T (*)[36])c33_inData)[c33_i183
        + c33_i181];
    }

    c33_i181 += 6;
  }

  c33_i184 = 0;
  for (c33_i185 = 0; c33_i185 < 6; c33_i185++) {
    for (c33_i186 = 0; c33_i186 < 6; c33_i186++) {
      c33_u[c33_i186 + c33_i184] = c33_b_inData[c33_i186 + c33_i184];
    }

    c33_i184 += 6;
  }

  c33_y = NULL;
  if (!chartInstance->c33_Mt_not_empty) {
    sf_mex_assign(&c33_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 2, 6, 6),
                  false);
  }

  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static void c33_c_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_b_Mt, const char_T *c33_identifier, real_T
  c33_y[36])
{
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_Mt), &c33_thisId, c33_y);
  sf_mex_destroy(&c33_b_Mt);
}

static void c33_d_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[36])
{
  real_T c33_dv9[36];
  int32_T c33_i187;
  if (mxIsEmpty(c33_u)) {
    chartInstance->c33_Mt_not_empty = false;
  } else {
    chartInstance->c33_Mt_not_empty = true;
    sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv9, 1, 0, 0U, 1, 0U, 2,
                  6, 6);
    for (c33_i187 = 0; c33_i187 < 36; c33_i187++) {
      c33_y[c33_i187] = c33_dv9[c33_i187];
    }
  }

  sf_mex_destroy(&c33_u);
}

static void c33_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_Mt;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[36];
  int32_T c33_i188;
  int32_T c33_i189;
  int32_T c33_i190;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_b_Mt = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_Mt), &c33_thisId, c33_y);
  sf_mex_destroy(&c33_b_Mt);
  c33_i188 = 0;
  for (c33_i189 = 0; c33_i189 < 6; c33_i189++) {
    for (c33_i190 = 0; c33_i190 < 6; c33_i190++) {
      (*(real_T (*)[36])c33_outData)[c33_i190 + c33_i188] = c33_y[c33_i190 +
        c33_i188];
    }

    c33_i188 += 6;
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_c_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i191;
  real_T c33_b_inData[3];
  int32_T c33_i192;
  real_T c33_u[3];
  const mxArray *c33_y = NULL;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  for (c33_i191 = 0; c33_i191 < 3; c33_i191++) {
    c33_b_inData[c33_i191] = (*(real_T (*)[3])c33_inData)[c33_i191];
  }

  for (c33_i192 = 0; c33_i192 < 3; c33_i192++) {
    c33_u[c33_i192] = c33_b_inData[c33_i192];
  }

  c33_y = NULL;
  if (!chartInstance->c33_Vt_not_empty) {
    sf_mex_assign(&c33_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 1, 3), false);
  }

  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static void c33_e_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_b_Vt, const char_T *c33_identifier, real_T
  c33_y[3])
{
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_Vt), &c33_thisId, c33_y);
  sf_mex_destroy(&c33_b_Vt);
}

static void c33_f_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[3])
{
  real_T c33_dv10[3];
  int32_T c33_i193;
  if (mxIsEmpty(c33_u)) {
    chartInstance->c33_Vt_not_empty = false;
  } else {
    chartInstance->c33_Vt_not_empty = true;
    sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv10, 1, 0, 0U, 1, 0U, 1,
                  3);
    for (c33_i193 = 0; c33_i193 < 3; c33_i193++) {
      c33_y[c33_i193] = c33_dv10[c33_i193];
    }
  }

  sf_mex_destroy(&c33_u);
}

static void c33_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_Vt;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[3];
  int32_T c33_i194;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_b_Vt = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_Vt), &c33_thisId, c33_y);
  sf_mex_destroy(&c33_b_Vt);
  for (c33_i194 = 0; c33_i194 < 3; c33_i194++) {
    (*(real_T (*)[3])c33_outData)[c33_i194] = c33_y[c33_i194];
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_d_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i195;
  real_T c33_b_inData[3];
  int32_T c33_i196;
  real_T c33_u[3];
  const mxArray *c33_y = NULL;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  for (c33_i195 = 0; c33_i195 < 3; c33_i195++) {
    c33_b_inData[c33_i195] = (*(real_T (*)[3])c33_inData)[c33_i195];
  }

  for (c33_i196 = 0; c33_i196 < 3; c33_i196++) {
    c33_u[c33_i196] = c33_b_inData[c33_i196];
  }

  c33_y = NULL;
  if (!chartInstance->c33_Xt_not_empty) {
    sf_mex_assign(&c33_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 1, 3), false);
  }

  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static void c33_g_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_b_Xt, const char_T *c33_identifier, real_T
  c33_y[3])
{
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_Xt), &c33_thisId, c33_y);
  sf_mex_destroy(&c33_b_Xt);
}

static void c33_h_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[3])
{
  real_T c33_dv11[3];
  int32_T c33_i197;
  if (mxIsEmpty(c33_u)) {
    chartInstance->c33_Xt_not_empty = false;
  } else {
    chartInstance->c33_Xt_not_empty = true;
    sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv11, 1, 0, 0U, 1, 0U, 1,
                  3);
    for (c33_i197 = 0; c33_i197 < 3; c33_i197++) {
      c33_y[c33_i197] = c33_dv11[c33_i197];
    }
  }

  sf_mex_destroy(&c33_u);
}

static void c33_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_Xt;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[3];
  int32_T c33_i198;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_b_Xt = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_Xt), &c33_thisId, c33_y);
  sf_mex_destroy(&c33_b_Xt);
  for (c33_i198 = 0; c33_i198 < 3; c33_i198++) {
    (*(real_T (*)[3])c33_outData)[c33_i198] = c33_y[c33_i198];
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_e_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i199;
  real_T c33_b_inData[3];
  int32_T c33_i200;
  real_T c33_u[3];
  const mxArray *c33_y = NULL;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  for (c33_i199 = 0; c33_i199 < 3; c33_i199++) {
    c33_b_inData[c33_i199] = (*(real_T (*)[3])c33_inData)[c33_i199];
  }

  for (c33_i200 = 0; c33_i200 < 3; c33_i200++) {
    c33_u[c33_i200] = c33_b_inData[c33_i200];
  }

  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static void c33_i_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_V, const char_T *c33_identifier, real_T
  c33_y[3])
{
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_V), &c33_thisId, c33_y);
  sf_mex_destroy(&c33_V);
}

static void c33_j_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[3])
{
  real_T c33_dv12[3];
  int32_T c33_i201;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv12, 1, 0, 0U, 1, 0U, 1, 3);
  for (c33_i201 = 0; c33_i201 < 3; c33_i201++) {
    c33_y[c33_i201] = c33_dv12[c33_i201];
  }

  sf_mex_destroy(&c33_u);
}

static void c33_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_V;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[3];
  int32_T c33_i202;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_V = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_V), &c33_thisId, c33_y);
  sf_mex_destroy(&c33_V);
  for (c33_i202 = 0; c33_i202 < 3; c33_i202++) {
    (*(real_T (*)[3])c33_outData)[c33_i202] = c33_y[c33_i202];
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_f_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i203;
  int32_T c33_i204;
  int32_T c33_i205;
  real_T c33_b_inData[9];
  int32_T c33_i206;
  int32_T c33_i207;
  int32_T c33_i208;
  real_T c33_u[9];
  const mxArray *c33_y = NULL;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_i203 = 0;
  for (c33_i204 = 0; c33_i204 < 3; c33_i204++) {
    for (c33_i205 = 0; c33_i205 < 3; c33_i205++) {
      c33_b_inData[c33_i205 + c33_i203] = (*(real_T (*)[9])c33_inData)[c33_i205
        + c33_i203];
    }

    c33_i203 += 3;
  }

  c33_i206 = 0;
  for (c33_i207 = 0; c33_i207 < 3; c33_i207++) {
    for (c33_i208 = 0; c33_i208 < 3; c33_i208++) {
      c33_u[c33_i208 + c33_i206] = c33_b_inData[c33_i208 + c33_i206];
    }

    c33_i206 += 3;
  }

  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static const mxArray *c33_g_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  real_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(real_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static real_T c33_k_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  real_T c33_y;
  real_T c33_d0;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_d0, 1, 0, 0U, 0, 0U, 0);
  c33_y = c33_d0;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_nargout;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_nargout = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_nargout),
    &c33_thisId);
  sf_mex_destroy(&c33_nargout);
  *(real_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_h_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i209;
  real_T c33_b_inData[6];
  int32_T c33_i210;
  real_T c33_u[6];
  const mxArray *c33_y = NULL;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  for (c33_i209 = 0; c33_i209 < 6; c33_i209++) {
    c33_b_inData[c33_i209] = (*(real_T (*)[6])c33_inData)[c33_i209];
  }

  for (c33_i210 = 0; c33_i210 < 6; c33_i210++) {
    c33_u[c33_i210] = c33_b_inData[c33_i210];
  }

  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static void c33_l_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[6])
{
  real_T c33_dv13[6];
  int32_T c33_i211;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv13, 1, 0, 0U, 1, 0U, 1, 6);
  for (c33_i211 = 0; c33_i211 < 6; c33_i211++) {
    c33_y[c33_i211] = c33_dv13[c33_i211];
  }

  sf_mex_destroy(&c33_u);
}

static void c33_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_Ut;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[6];
  int32_T c33_i212;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_Ut = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_Ut), &c33_thisId, c33_y);
  sf_mex_destroy(&c33_Ut);
  for (c33_i212 = 0; c33_i212 < 6; c33_i212++) {
    (*(real_T (*)[6])c33_outData)[c33_i212] = c33_y[c33_i212];
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_i_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i213;
  int32_T c33_i214;
  int32_T c33_i215;
  real_T c33_b_inData[36];
  int32_T c33_i216;
  int32_T c33_i217;
  int32_T c33_i218;
  real_T c33_u[36];
  const mxArray *c33_y = NULL;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_i213 = 0;
  for (c33_i214 = 0; c33_i214 < 6; c33_i214++) {
    for (c33_i215 = 0; c33_i215 < 6; c33_i215++) {
      c33_b_inData[c33_i215 + c33_i213] = (*(real_T (*)[36])c33_inData)[c33_i215
        + c33_i213];
    }

    c33_i213 += 6;
  }

  c33_i216 = 0;
  for (c33_i217 = 0; c33_i217 < 6; c33_i217++) {
    for (c33_i218 = 0; c33_i218 < 6; c33_i218++) {
      c33_u[c33_i218 + c33_i216] = c33_b_inData[c33_i218 + c33_i216];
    }

    c33_i216 += 6;
  }

  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 2, 6, 6), false);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static void c33_m_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[36])
{
  real_T c33_dv14[36];
  int32_T c33_i219;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv14, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c33_i219 = 0; c33_i219 < 36; c33_i219++) {
    c33_y[c33_i219] = c33_dv14[c33_i219];
  }

  sf_mex_destroy(&c33_u);
}

static void c33_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_Kt;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[36];
  int32_T c33_i220;
  int32_T c33_i221;
  int32_T c33_i222;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_Kt = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_Kt), &c33_thisId, c33_y);
  sf_mex_destroy(&c33_Kt);
  c33_i220 = 0;
  for (c33_i221 = 0; c33_i221 < 6; c33_i221++) {
    for (c33_i222 = 0; c33_i222 < 6; c33_i222++) {
      (*(real_T (*)[36])c33_outData)[c33_i222 + c33_i220] = c33_y[c33_i222 +
        c33_i220];
    }

    c33_i220 += 6;
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

static void c33_n_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[9])
{
  real_T c33_dv15[9];
  int32_T c33_i223;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv15, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c33_i223 = 0; c33_i223 < 9; c33_i223++) {
    c33_y[c33_i223] = c33_dv15[c33_i223];
  }

  sf_mex_destroy(&c33_u);
}

static void c33_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_Qp;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[9];
  int32_T c33_i224;
  int32_T c33_i225;
  int32_T c33_i226;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_Qp = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_Qp), &c33_thisId, c33_y);
  sf_mex_destroy(&c33_Qp);
  c33_i224 = 0;
  for (c33_i225 = 0; c33_i225 < 3; c33_i225++) {
    for (c33_i226 = 0; c33_i226 < 3; c33_i226++) {
      (*(real_T (*)[9])c33_outData)[c33_i226 + c33_i224] = c33_y[c33_i226 +
        c33_i224];
    }

    c33_i224 += 3;
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

const mxArray *sf_c33_juecefinishi_get_eml_resolved_functions_info(void)
{
  const mxArray *c33_nameCaptureInfo = NULL;
  c33_nameCaptureInfo = NULL;
  sf_mex_assign(&c33_nameCaptureInfo, sf_mex_createstruct("structure", 2, 169, 1),
                false);
  c33_info_helper(&c33_nameCaptureInfo);
  c33_b_info_helper(&c33_nameCaptureInfo);
  c33_c_info_helper(&c33_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c33_nameCaptureInfo);
  return c33_nameCaptureInfo;
}

static void c33_info_helper(const mxArray **c33_info)
{
  const mxArray *c33_rhs0 = NULL;
  const mxArray *c33_lhs0 = NULL;
  const mxArray *c33_rhs1 = NULL;
  const mxArray *c33_lhs1 = NULL;
  const mxArray *c33_rhs2 = NULL;
  const mxArray *c33_lhs2 = NULL;
  const mxArray *c33_rhs3 = NULL;
  const mxArray *c33_lhs3 = NULL;
  const mxArray *c33_rhs4 = NULL;
  const mxArray *c33_lhs4 = NULL;
  const mxArray *c33_rhs5 = NULL;
  const mxArray *c33_lhs5 = NULL;
  const mxArray *c33_rhs6 = NULL;
  const mxArray *c33_lhs6 = NULL;
  const mxArray *c33_rhs7 = NULL;
  const mxArray *c33_lhs7 = NULL;
  const mxArray *c33_rhs8 = NULL;
  const mxArray *c33_lhs8 = NULL;
  const mxArray *c33_rhs9 = NULL;
  const mxArray *c33_lhs9 = NULL;
  const mxArray *c33_rhs10 = NULL;
  const mxArray *c33_lhs10 = NULL;
  const mxArray *c33_rhs11 = NULL;
  const mxArray *c33_lhs11 = NULL;
  const mxArray *c33_rhs12 = NULL;
  const mxArray *c33_lhs12 = NULL;
  const mxArray *c33_rhs13 = NULL;
  const mxArray *c33_lhs13 = NULL;
  const mxArray *c33_rhs14 = NULL;
  const mxArray *c33_lhs14 = NULL;
  const mxArray *c33_rhs15 = NULL;
  const mxArray *c33_lhs15 = NULL;
  const mxArray *c33_rhs16 = NULL;
  const mxArray *c33_lhs16 = NULL;
  const mxArray *c33_rhs17 = NULL;
  const mxArray *c33_lhs17 = NULL;
  const mxArray *c33_rhs18 = NULL;
  const mxArray *c33_lhs18 = NULL;
  const mxArray *c33_rhs19 = NULL;
  const mxArray *c33_lhs19 = NULL;
  const mxArray *c33_rhs20 = NULL;
  const mxArray *c33_lhs20 = NULL;
  const mxArray *c33_rhs21 = NULL;
  const mxArray *c33_lhs21 = NULL;
  const mxArray *c33_rhs22 = NULL;
  const mxArray *c33_lhs22 = NULL;
  const mxArray *c33_rhs23 = NULL;
  const mxArray *c33_lhs23 = NULL;
  const mxArray *c33_rhs24 = NULL;
  const mxArray *c33_lhs24 = NULL;
  const mxArray *c33_rhs25 = NULL;
  const mxArray *c33_lhs25 = NULL;
  const mxArray *c33_rhs26 = NULL;
  const mxArray *c33_lhs26 = NULL;
  const mxArray *c33_rhs27 = NULL;
  const mxArray *c33_lhs27 = NULL;
  const mxArray *c33_rhs28 = NULL;
  const mxArray *c33_lhs28 = NULL;
  const mxArray *c33_rhs29 = NULL;
  const mxArray *c33_lhs29 = NULL;
  const mxArray *c33_rhs30 = NULL;
  const mxArray *c33_lhs30 = NULL;
  const mxArray *c33_rhs31 = NULL;
  const mxArray *c33_lhs31 = NULL;
  const mxArray *c33_rhs32 = NULL;
  const mxArray *c33_lhs32 = NULL;
  const mxArray *c33_rhs33 = NULL;
  const mxArray *c33_lhs33 = NULL;
  const mxArray *c33_rhs34 = NULL;
  const mxArray *c33_lhs34 = NULL;
  const mxArray *c33_rhs35 = NULL;
  const mxArray *c33_lhs35 = NULL;
  const mxArray *c33_rhs36 = NULL;
  const mxArray *c33_lhs36 = NULL;
  const mxArray *c33_rhs37 = NULL;
  const mxArray *c33_lhs37 = NULL;
  const mxArray *c33_rhs38 = NULL;
  const mxArray *c33_lhs38 = NULL;
  const mxArray *c33_rhs39 = NULL;
  const mxArray *c33_lhs39 = NULL;
  const mxArray *c33_rhs40 = NULL;
  const mxArray *c33_lhs40 = NULL;
  const mxArray *c33_rhs41 = NULL;
  const mxArray *c33_lhs41 = NULL;
  const mxArray *c33_rhs42 = NULL;
  const mxArray *c33_lhs42 = NULL;
  const mxArray *c33_rhs43 = NULL;
  const mxArray *c33_lhs43 = NULL;
  const mxArray *c33_rhs44 = NULL;
  const mxArray *c33_lhs44 = NULL;
  const mxArray *c33_rhs45 = NULL;
  const mxArray *c33_lhs45 = NULL;
  const mxArray *c33_rhs46 = NULL;
  const mxArray *c33_lhs46 = NULL;
  const mxArray *c33_rhs47 = NULL;
  const mxArray *c33_lhs47 = NULL;
  const mxArray *c33_rhs48 = NULL;
  const mxArray *c33_lhs48 = NULL;
  const mxArray *c33_rhs49 = NULL;
  const mxArray *c33_lhs49 = NULL;
  const mxArray *c33_rhs50 = NULL;
  const mxArray *c33_lhs50 = NULL;
  const mxArray *c33_rhs51 = NULL;
  const mxArray *c33_lhs51 = NULL;
  const mxArray *c33_rhs52 = NULL;
  const mxArray *c33_lhs52 = NULL;
  const mxArray *c33_rhs53 = NULL;
  const mxArray *c33_lhs53 = NULL;
  const mxArray *c33_rhs54 = NULL;
  const mxArray *c33_lhs54 = NULL;
  const mxArray *c33_rhs55 = NULL;
  const mxArray *c33_lhs55 = NULL;
  const mxArray *c33_rhs56 = NULL;
  const mxArray *c33_lhs56 = NULL;
  const mxArray *c33_rhs57 = NULL;
  const mxArray *c33_lhs57 = NULL;
  const mxArray *c33_rhs58 = NULL;
  const mxArray *c33_lhs58 = NULL;
  const mxArray *c33_rhs59 = NULL;
  const mxArray *c33_lhs59 = NULL;
  const mxArray *c33_rhs60 = NULL;
  const mxArray *c33_lhs60 = NULL;
  const mxArray *c33_rhs61 = NULL;
  const mxArray *c33_lhs61 = NULL;
  const mxArray *c33_rhs62 = NULL;
  const mxArray *c33_lhs62 = NULL;
  const mxArray *c33_rhs63 = NULL;
  const mxArray *c33_lhs63 = NULL;
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1383880894U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c33_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c33_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c33_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c33_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c33_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  5);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987890U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c33_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 6);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c33_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 7);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c33_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 8);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 8);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c33_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 9);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 9);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c33_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 10);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c33_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c33_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 12);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c33_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eye"), "name", "name", 13);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1381857498U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c33_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 14);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1368190230U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c33_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c33_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 16);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("isinf"), "name", "name", 16);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363717456U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c33_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c33_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 18);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 18);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286825982U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c33_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 19);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmax"), "name", "name", 19);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c33_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 20);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c33_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 21);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmin"), "name", "name", 21);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c33_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 22);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c33_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 23);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 23);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1326731922U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c33_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 24);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 24);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c33_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 25);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 25);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c33_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 26);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmin"), "name", "name", 26);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c33_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 27);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 27);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c33_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmax"), "name", "name", 28);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c33_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 29);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c33_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 30);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmax"), "name", "name", 30);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c33_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "context", "context", 31);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("rdivide"), "name", "name",
                  31);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c33_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 32);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c33_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 33);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286825996U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c33_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_div"), "name", "name",
                  34);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c33_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 35);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c33_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "context", "context", 36);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("inv"), "name", "name", 36);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1305325200U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c33_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN"), "context",
                  "context", 37);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 37);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c33_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN"), "context",
                  "context", 38);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_xgetrf"), "name", "name",
                  38);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286826006U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c33_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_lapack_xgetrf"), "name",
                  "name", 39);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286826010U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c33_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_matlab_zgetrf"), "name",
                  "name", 40);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1302696194U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c33_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("realmin"), "name", "name",
                  41);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1307658442U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c33_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 42);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1307658444U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c33_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 43);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c33_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eps"), "name", "name", 44);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c33_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 45);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286825982U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c33_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_eps"), "name", "name",
                  46);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c33_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 47);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c33_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 48);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("min"), "name", "name", 48);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 48);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1311262518U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c33_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 49);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1378303184U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c33_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 50);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 50);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 50);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c33_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 51);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 51);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c33_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 52);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 52);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 52);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c33_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 53);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 53);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 53);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c33_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 54);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 54);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c33_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 55);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 55);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 55);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c33_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 56);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 56);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 56);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c33_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 57);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("colon"), "name", "name", 57);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1378303188U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c33_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("colon"), "name", "name", 58);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1378303188U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c33_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 59);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c33_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 60);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 60);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 60);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c33_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 61);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("floor"), "name", "name", 61);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 61);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363717454U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c33_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 62);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 62);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c33_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 63);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 63);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286825926U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c33_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c33_rhs0);
  sf_mex_destroy(&c33_lhs0);
  sf_mex_destroy(&c33_rhs1);
  sf_mex_destroy(&c33_lhs1);
  sf_mex_destroy(&c33_rhs2);
  sf_mex_destroy(&c33_lhs2);
  sf_mex_destroy(&c33_rhs3);
  sf_mex_destroy(&c33_lhs3);
  sf_mex_destroy(&c33_rhs4);
  sf_mex_destroy(&c33_lhs4);
  sf_mex_destroy(&c33_rhs5);
  sf_mex_destroy(&c33_lhs5);
  sf_mex_destroy(&c33_rhs6);
  sf_mex_destroy(&c33_lhs6);
  sf_mex_destroy(&c33_rhs7);
  sf_mex_destroy(&c33_lhs7);
  sf_mex_destroy(&c33_rhs8);
  sf_mex_destroy(&c33_lhs8);
  sf_mex_destroy(&c33_rhs9);
  sf_mex_destroy(&c33_lhs9);
  sf_mex_destroy(&c33_rhs10);
  sf_mex_destroy(&c33_lhs10);
  sf_mex_destroy(&c33_rhs11);
  sf_mex_destroy(&c33_lhs11);
  sf_mex_destroy(&c33_rhs12);
  sf_mex_destroy(&c33_lhs12);
  sf_mex_destroy(&c33_rhs13);
  sf_mex_destroy(&c33_lhs13);
  sf_mex_destroy(&c33_rhs14);
  sf_mex_destroy(&c33_lhs14);
  sf_mex_destroy(&c33_rhs15);
  sf_mex_destroy(&c33_lhs15);
  sf_mex_destroy(&c33_rhs16);
  sf_mex_destroy(&c33_lhs16);
  sf_mex_destroy(&c33_rhs17);
  sf_mex_destroy(&c33_lhs17);
  sf_mex_destroy(&c33_rhs18);
  sf_mex_destroy(&c33_lhs18);
  sf_mex_destroy(&c33_rhs19);
  sf_mex_destroy(&c33_lhs19);
  sf_mex_destroy(&c33_rhs20);
  sf_mex_destroy(&c33_lhs20);
  sf_mex_destroy(&c33_rhs21);
  sf_mex_destroy(&c33_lhs21);
  sf_mex_destroy(&c33_rhs22);
  sf_mex_destroy(&c33_lhs22);
  sf_mex_destroy(&c33_rhs23);
  sf_mex_destroy(&c33_lhs23);
  sf_mex_destroy(&c33_rhs24);
  sf_mex_destroy(&c33_lhs24);
  sf_mex_destroy(&c33_rhs25);
  sf_mex_destroy(&c33_lhs25);
  sf_mex_destroy(&c33_rhs26);
  sf_mex_destroy(&c33_lhs26);
  sf_mex_destroy(&c33_rhs27);
  sf_mex_destroy(&c33_lhs27);
  sf_mex_destroy(&c33_rhs28);
  sf_mex_destroy(&c33_lhs28);
  sf_mex_destroy(&c33_rhs29);
  sf_mex_destroy(&c33_lhs29);
  sf_mex_destroy(&c33_rhs30);
  sf_mex_destroy(&c33_lhs30);
  sf_mex_destroy(&c33_rhs31);
  sf_mex_destroy(&c33_lhs31);
  sf_mex_destroy(&c33_rhs32);
  sf_mex_destroy(&c33_lhs32);
  sf_mex_destroy(&c33_rhs33);
  sf_mex_destroy(&c33_lhs33);
  sf_mex_destroy(&c33_rhs34);
  sf_mex_destroy(&c33_lhs34);
  sf_mex_destroy(&c33_rhs35);
  sf_mex_destroy(&c33_lhs35);
  sf_mex_destroy(&c33_rhs36);
  sf_mex_destroy(&c33_lhs36);
  sf_mex_destroy(&c33_rhs37);
  sf_mex_destroy(&c33_lhs37);
  sf_mex_destroy(&c33_rhs38);
  sf_mex_destroy(&c33_lhs38);
  sf_mex_destroy(&c33_rhs39);
  sf_mex_destroy(&c33_lhs39);
  sf_mex_destroy(&c33_rhs40);
  sf_mex_destroy(&c33_lhs40);
  sf_mex_destroy(&c33_rhs41);
  sf_mex_destroy(&c33_lhs41);
  sf_mex_destroy(&c33_rhs42);
  sf_mex_destroy(&c33_lhs42);
  sf_mex_destroy(&c33_rhs43);
  sf_mex_destroy(&c33_lhs43);
  sf_mex_destroy(&c33_rhs44);
  sf_mex_destroy(&c33_lhs44);
  sf_mex_destroy(&c33_rhs45);
  sf_mex_destroy(&c33_lhs45);
  sf_mex_destroy(&c33_rhs46);
  sf_mex_destroy(&c33_lhs46);
  sf_mex_destroy(&c33_rhs47);
  sf_mex_destroy(&c33_lhs47);
  sf_mex_destroy(&c33_rhs48);
  sf_mex_destroy(&c33_lhs48);
  sf_mex_destroy(&c33_rhs49);
  sf_mex_destroy(&c33_lhs49);
  sf_mex_destroy(&c33_rhs50);
  sf_mex_destroy(&c33_lhs50);
  sf_mex_destroy(&c33_rhs51);
  sf_mex_destroy(&c33_lhs51);
  sf_mex_destroy(&c33_rhs52);
  sf_mex_destroy(&c33_lhs52);
  sf_mex_destroy(&c33_rhs53);
  sf_mex_destroy(&c33_lhs53);
  sf_mex_destroy(&c33_rhs54);
  sf_mex_destroy(&c33_lhs54);
  sf_mex_destroy(&c33_rhs55);
  sf_mex_destroy(&c33_lhs55);
  sf_mex_destroy(&c33_rhs56);
  sf_mex_destroy(&c33_lhs56);
  sf_mex_destroy(&c33_rhs57);
  sf_mex_destroy(&c33_lhs57);
  sf_mex_destroy(&c33_rhs58);
  sf_mex_destroy(&c33_lhs58);
  sf_mex_destroy(&c33_rhs59);
  sf_mex_destroy(&c33_lhs59);
  sf_mex_destroy(&c33_rhs60);
  sf_mex_destroy(&c33_lhs60);
  sf_mex_destroy(&c33_rhs61);
  sf_mex_destroy(&c33_lhs61);
  sf_mex_destroy(&c33_rhs62);
  sf_mex_destroy(&c33_lhs62);
  sf_mex_destroy(&c33_rhs63);
  sf_mex_destroy(&c33_lhs63);
}

static const mxArray *c33_emlrt_marshallOut(const char * c33_u)
{
  const mxArray *c33_y = NULL;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c33_u)), false);
  return c33_y;
}

static const mxArray *c33_b_emlrt_marshallOut(const uint32_T c33_u)
{
  const mxArray *c33_y = NULL;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 7, 0U, 0U, 0U, 0), false);
  return c33_y;
}

static void c33_b_info_helper(const mxArray **c33_info)
{
  const mxArray *c33_rhs64 = NULL;
  const mxArray *c33_lhs64 = NULL;
  const mxArray *c33_rhs65 = NULL;
  const mxArray *c33_lhs65 = NULL;
  const mxArray *c33_rhs66 = NULL;
  const mxArray *c33_lhs66 = NULL;
  const mxArray *c33_rhs67 = NULL;
  const mxArray *c33_lhs67 = NULL;
  const mxArray *c33_rhs68 = NULL;
  const mxArray *c33_lhs68 = NULL;
  const mxArray *c33_rhs69 = NULL;
  const mxArray *c33_lhs69 = NULL;
  const mxArray *c33_rhs70 = NULL;
  const mxArray *c33_lhs70 = NULL;
  const mxArray *c33_rhs71 = NULL;
  const mxArray *c33_lhs71 = NULL;
  const mxArray *c33_rhs72 = NULL;
  const mxArray *c33_lhs72 = NULL;
  const mxArray *c33_rhs73 = NULL;
  const mxArray *c33_lhs73 = NULL;
  const mxArray *c33_rhs74 = NULL;
  const mxArray *c33_lhs74 = NULL;
  const mxArray *c33_rhs75 = NULL;
  const mxArray *c33_lhs75 = NULL;
  const mxArray *c33_rhs76 = NULL;
  const mxArray *c33_lhs76 = NULL;
  const mxArray *c33_rhs77 = NULL;
  const mxArray *c33_lhs77 = NULL;
  const mxArray *c33_rhs78 = NULL;
  const mxArray *c33_lhs78 = NULL;
  const mxArray *c33_rhs79 = NULL;
  const mxArray *c33_lhs79 = NULL;
  const mxArray *c33_rhs80 = NULL;
  const mxArray *c33_lhs80 = NULL;
  const mxArray *c33_rhs81 = NULL;
  const mxArray *c33_lhs81 = NULL;
  const mxArray *c33_rhs82 = NULL;
  const mxArray *c33_lhs82 = NULL;
  const mxArray *c33_rhs83 = NULL;
  const mxArray *c33_lhs83 = NULL;
  const mxArray *c33_rhs84 = NULL;
  const mxArray *c33_lhs84 = NULL;
  const mxArray *c33_rhs85 = NULL;
  const mxArray *c33_lhs85 = NULL;
  const mxArray *c33_rhs86 = NULL;
  const mxArray *c33_lhs86 = NULL;
  const mxArray *c33_rhs87 = NULL;
  const mxArray *c33_lhs87 = NULL;
  const mxArray *c33_rhs88 = NULL;
  const mxArray *c33_lhs88 = NULL;
  const mxArray *c33_rhs89 = NULL;
  const mxArray *c33_lhs89 = NULL;
  const mxArray *c33_rhs90 = NULL;
  const mxArray *c33_lhs90 = NULL;
  const mxArray *c33_rhs91 = NULL;
  const mxArray *c33_lhs91 = NULL;
  const mxArray *c33_rhs92 = NULL;
  const mxArray *c33_lhs92 = NULL;
  const mxArray *c33_rhs93 = NULL;
  const mxArray *c33_lhs93 = NULL;
  const mxArray *c33_rhs94 = NULL;
  const mxArray *c33_lhs94 = NULL;
  const mxArray *c33_rhs95 = NULL;
  const mxArray *c33_lhs95 = NULL;
  const mxArray *c33_rhs96 = NULL;
  const mxArray *c33_lhs96 = NULL;
  const mxArray *c33_rhs97 = NULL;
  const mxArray *c33_lhs97 = NULL;
  const mxArray *c33_rhs98 = NULL;
  const mxArray *c33_lhs98 = NULL;
  const mxArray *c33_rhs99 = NULL;
  const mxArray *c33_lhs99 = NULL;
  const mxArray *c33_rhs100 = NULL;
  const mxArray *c33_lhs100 = NULL;
  const mxArray *c33_rhs101 = NULL;
  const mxArray *c33_lhs101 = NULL;
  const mxArray *c33_rhs102 = NULL;
  const mxArray *c33_lhs102 = NULL;
  const mxArray *c33_rhs103 = NULL;
  const mxArray *c33_lhs103 = NULL;
  const mxArray *c33_rhs104 = NULL;
  const mxArray *c33_lhs104 = NULL;
  const mxArray *c33_rhs105 = NULL;
  const mxArray *c33_lhs105 = NULL;
  const mxArray *c33_rhs106 = NULL;
  const mxArray *c33_lhs106 = NULL;
  const mxArray *c33_rhs107 = NULL;
  const mxArray *c33_lhs107 = NULL;
  const mxArray *c33_rhs108 = NULL;
  const mxArray *c33_lhs108 = NULL;
  const mxArray *c33_rhs109 = NULL;
  const mxArray *c33_lhs109 = NULL;
  const mxArray *c33_rhs110 = NULL;
  const mxArray *c33_lhs110 = NULL;
  const mxArray *c33_rhs111 = NULL;
  const mxArray *c33_lhs111 = NULL;
  const mxArray *c33_rhs112 = NULL;
  const mxArray *c33_lhs112 = NULL;
  const mxArray *c33_rhs113 = NULL;
  const mxArray *c33_lhs113 = NULL;
  const mxArray *c33_rhs114 = NULL;
  const mxArray *c33_lhs114 = NULL;
  const mxArray *c33_rhs115 = NULL;
  const mxArray *c33_lhs115 = NULL;
  const mxArray *c33_rhs116 = NULL;
  const mxArray *c33_lhs116 = NULL;
  const mxArray *c33_rhs117 = NULL;
  const mxArray *c33_lhs117 = NULL;
  const mxArray *c33_rhs118 = NULL;
  const mxArray *c33_lhs118 = NULL;
  const mxArray *c33_rhs119 = NULL;
  const mxArray *c33_lhs119 = NULL;
  const mxArray *c33_rhs120 = NULL;
  const mxArray *c33_lhs120 = NULL;
  const mxArray *c33_rhs121 = NULL;
  const mxArray *c33_lhs121 = NULL;
  const mxArray *c33_rhs122 = NULL;
  const mxArray *c33_lhs122 = NULL;
  const mxArray *c33_rhs123 = NULL;
  const mxArray *c33_lhs123 = NULL;
  const mxArray *c33_rhs124 = NULL;
  const mxArray *c33_lhs124 = NULL;
  const mxArray *c33_rhs125 = NULL;
  const mxArray *c33_lhs125 = NULL;
  const mxArray *c33_rhs126 = NULL;
  const mxArray *c33_lhs126 = NULL;
  const mxArray *c33_rhs127 = NULL;
  const mxArray *c33_lhs127 = NULL;
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 64);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmin"), "name", "name", 64);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c33_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 65);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmax"), "name", "name", 65);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 65);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c33_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 66);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmin"), "name", "name", 66);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 66);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c33_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 67);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmax"), "name", "name", 67);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 67);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c33_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 68);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 68);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 68);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 68);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c33_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 69);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 69);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 69);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c33_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 70);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 70);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c33_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 71);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 71);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c33_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 72);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 72);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c33_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 73);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 73);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c33_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 74);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 74);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c33_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 75);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmax"), "name", "name", 75);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 75);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c33_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 76);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 76);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 76);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 76);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c33_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 77);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 77);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372589616U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c33_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 78);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 78);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c33_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 79);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 79);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c33_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 80);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 80);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c33_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 81);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 81);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372589616U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c33_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 82);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 82);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c33_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 83);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 83);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 83);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372589616U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c33_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 84);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 84);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c33_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 85);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 85);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 85);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 85);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372589616U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c33_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 86);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 86);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 86);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c33_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 87);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 87);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 87);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 87);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372589616U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c33_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 88);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 88);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 88);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 88);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c33_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 89);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 89);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 89);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372589616U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c33_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 90);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 90);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 90);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 90);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c33_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 91);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_ixamax"), "name", "name",
                  91);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "resolved", "resolved", 91);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c33_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 92);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 92);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c33_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 93);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.ixamax"),
                  "name", "name", 93);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c33_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 94);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 94);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 94);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c33_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 95);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 95);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 95);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c33_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 96);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("length"), "name", "name", 96);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 96);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1303153406U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c33_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 97);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 97);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c33_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 98);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.refblas.ixamax"), "name", "name", 98);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c33_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 99);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.refblas.xcabs1"), "name", "name", 99);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 99);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c33_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 100);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("abs"), "name", "name", 100);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 100);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363717452U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c33_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 101);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 101);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 101);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c33_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 102);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 102);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286825912U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c33_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 103);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 103);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c33_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 104);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 104);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 104);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c33_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 105);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_xswap"), "name", "name",
                  105);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"),
                  "resolved", "resolved", 105);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987892U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c33_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 106);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 106);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c33_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 107);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.xswap"),
                  "name", "name", 107);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c33_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 108);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 108);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 108);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c33_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p!below_threshold"),
                  "context", "context", 109);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 109);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 109);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c33_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 110);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.refblas.xswap"), "name", "name", 110);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c33_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 111);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("abs"), "name", "name", 111);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 111);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 111);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363717452U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c33_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 112);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 112);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 112);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 112);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c33_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 113);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 113);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 113);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286825912U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c33_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 114);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 114);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c33_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs114), "rhs",
                  "rhs", 114);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs114), "lhs",
                  "lhs", 114);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 115);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 115);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 115);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c33_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs115), "rhs",
                  "rhs", 115);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs115), "lhs",
                  "lhs", 115);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 116);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_div"), "name", "name",
                  116);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 116);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c33_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs116), "rhs",
                  "rhs", 116);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs116), "lhs",
                  "lhs", 116);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 117);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_xgeru"), "name", "name",
                  117);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987890U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c33_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs117), "rhs",
                  "rhs", 117);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs117), "lhs",
                  "lhs", 117);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 118);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 118);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 118);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c33_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs118), "rhs",
                  "rhs", 118);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs118), "lhs",
                  "lhs", 118);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 119);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.xgeru"),
                  "name", "name", 119);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "resolved", "resolved", 119);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c33_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs119), "rhs",
                  "rhs", 119);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs119), "lhs",
                  "lhs", 119);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "context", "context", 120);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.xger"),
                  "name", "name", 120);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 120);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "resolved", "resolved", 120);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c33_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs120), "rhs",
                  "rhs", 120);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs120), "lhs",
                  "lhs", 120);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 121);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 121);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c33_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs121), "rhs",
                  "rhs", 121);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs121), "lhs",
                  "lhs", 121);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 122);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 122);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 122);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c33_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs122), "rhs",
                  "rhs", 122);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs122), "lhs",
                  "lhs", 122);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 123);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.int"),
                  "name", "name", 123);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/int.p"),
                  "resolved", "resolved", 123);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c33_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs123), "rhs",
                  "rhs", 123);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs123), "lhs",
                  "lhs", 123);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 124);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmax"), "name", "name",
                  124);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 124);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c33_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs124), "rhs",
                  "rhs", 124);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs124), "lhs",
                  "lhs", 124);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 125);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("min"), "name", "name", 125);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 125);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1311262518U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c33_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs125), "rhs",
                  "rhs", 125);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs125), "lhs",
                  "lhs", 125);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 126);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 126);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 126);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c33_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs126), "rhs",
                  "rhs", 126);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs126), "lhs",
                  "lhs", 126);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 127);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 127);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 127);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c33_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs127), "rhs",
                  "rhs", 127);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs127), "lhs",
                  "lhs", 127);
  sf_mex_destroy(&c33_rhs64);
  sf_mex_destroy(&c33_lhs64);
  sf_mex_destroy(&c33_rhs65);
  sf_mex_destroy(&c33_lhs65);
  sf_mex_destroy(&c33_rhs66);
  sf_mex_destroy(&c33_lhs66);
  sf_mex_destroy(&c33_rhs67);
  sf_mex_destroy(&c33_lhs67);
  sf_mex_destroy(&c33_rhs68);
  sf_mex_destroy(&c33_lhs68);
  sf_mex_destroy(&c33_rhs69);
  sf_mex_destroy(&c33_lhs69);
  sf_mex_destroy(&c33_rhs70);
  sf_mex_destroy(&c33_lhs70);
  sf_mex_destroy(&c33_rhs71);
  sf_mex_destroy(&c33_lhs71);
  sf_mex_destroy(&c33_rhs72);
  sf_mex_destroy(&c33_lhs72);
  sf_mex_destroy(&c33_rhs73);
  sf_mex_destroy(&c33_lhs73);
  sf_mex_destroy(&c33_rhs74);
  sf_mex_destroy(&c33_lhs74);
  sf_mex_destroy(&c33_rhs75);
  sf_mex_destroy(&c33_lhs75);
  sf_mex_destroy(&c33_rhs76);
  sf_mex_destroy(&c33_lhs76);
  sf_mex_destroy(&c33_rhs77);
  sf_mex_destroy(&c33_lhs77);
  sf_mex_destroy(&c33_rhs78);
  sf_mex_destroy(&c33_lhs78);
  sf_mex_destroy(&c33_rhs79);
  sf_mex_destroy(&c33_lhs79);
  sf_mex_destroy(&c33_rhs80);
  sf_mex_destroy(&c33_lhs80);
  sf_mex_destroy(&c33_rhs81);
  sf_mex_destroy(&c33_lhs81);
  sf_mex_destroy(&c33_rhs82);
  sf_mex_destroy(&c33_lhs82);
  sf_mex_destroy(&c33_rhs83);
  sf_mex_destroy(&c33_lhs83);
  sf_mex_destroy(&c33_rhs84);
  sf_mex_destroy(&c33_lhs84);
  sf_mex_destroy(&c33_rhs85);
  sf_mex_destroy(&c33_lhs85);
  sf_mex_destroy(&c33_rhs86);
  sf_mex_destroy(&c33_lhs86);
  sf_mex_destroy(&c33_rhs87);
  sf_mex_destroy(&c33_lhs87);
  sf_mex_destroy(&c33_rhs88);
  sf_mex_destroy(&c33_lhs88);
  sf_mex_destroy(&c33_rhs89);
  sf_mex_destroy(&c33_lhs89);
  sf_mex_destroy(&c33_rhs90);
  sf_mex_destroy(&c33_lhs90);
  sf_mex_destroy(&c33_rhs91);
  sf_mex_destroy(&c33_lhs91);
  sf_mex_destroy(&c33_rhs92);
  sf_mex_destroy(&c33_lhs92);
  sf_mex_destroy(&c33_rhs93);
  sf_mex_destroy(&c33_lhs93);
  sf_mex_destroy(&c33_rhs94);
  sf_mex_destroy(&c33_lhs94);
  sf_mex_destroy(&c33_rhs95);
  sf_mex_destroy(&c33_lhs95);
  sf_mex_destroy(&c33_rhs96);
  sf_mex_destroy(&c33_lhs96);
  sf_mex_destroy(&c33_rhs97);
  sf_mex_destroy(&c33_lhs97);
  sf_mex_destroy(&c33_rhs98);
  sf_mex_destroy(&c33_lhs98);
  sf_mex_destroy(&c33_rhs99);
  sf_mex_destroy(&c33_lhs99);
  sf_mex_destroy(&c33_rhs100);
  sf_mex_destroy(&c33_lhs100);
  sf_mex_destroy(&c33_rhs101);
  sf_mex_destroy(&c33_lhs101);
  sf_mex_destroy(&c33_rhs102);
  sf_mex_destroy(&c33_lhs102);
  sf_mex_destroy(&c33_rhs103);
  sf_mex_destroy(&c33_lhs103);
  sf_mex_destroy(&c33_rhs104);
  sf_mex_destroy(&c33_lhs104);
  sf_mex_destroy(&c33_rhs105);
  sf_mex_destroy(&c33_lhs105);
  sf_mex_destroy(&c33_rhs106);
  sf_mex_destroy(&c33_lhs106);
  sf_mex_destroy(&c33_rhs107);
  sf_mex_destroy(&c33_lhs107);
  sf_mex_destroy(&c33_rhs108);
  sf_mex_destroy(&c33_lhs108);
  sf_mex_destroy(&c33_rhs109);
  sf_mex_destroy(&c33_lhs109);
  sf_mex_destroy(&c33_rhs110);
  sf_mex_destroy(&c33_lhs110);
  sf_mex_destroy(&c33_rhs111);
  sf_mex_destroy(&c33_lhs111);
  sf_mex_destroy(&c33_rhs112);
  sf_mex_destroy(&c33_lhs112);
  sf_mex_destroy(&c33_rhs113);
  sf_mex_destroy(&c33_lhs113);
  sf_mex_destroy(&c33_rhs114);
  sf_mex_destroy(&c33_lhs114);
  sf_mex_destroy(&c33_rhs115);
  sf_mex_destroy(&c33_lhs115);
  sf_mex_destroy(&c33_rhs116);
  sf_mex_destroy(&c33_lhs116);
  sf_mex_destroy(&c33_rhs117);
  sf_mex_destroy(&c33_lhs117);
  sf_mex_destroy(&c33_rhs118);
  sf_mex_destroy(&c33_lhs118);
  sf_mex_destroy(&c33_rhs119);
  sf_mex_destroy(&c33_lhs119);
  sf_mex_destroy(&c33_rhs120);
  sf_mex_destroy(&c33_lhs120);
  sf_mex_destroy(&c33_rhs121);
  sf_mex_destroy(&c33_lhs121);
  sf_mex_destroy(&c33_rhs122);
  sf_mex_destroy(&c33_lhs122);
  sf_mex_destroy(&c33_rhs123);
  sf_mex_destroy(&c33_lhs123);
  sf_mex_destroy(&c33_rhs124);
  sf_mex_destroy(&c33_lhs124);
  sf_mex_destroy(&c33_rhs125);
  sf_mex_destroy(&c33_lhs125);
  sf_mex_destroy(&c33_rhs126);
  sf_mex_destroy(&c33_lhs126);
  sf_mex_destroy(&c33_rhs127);
  sf_mex_destroy(&c33_lhs127);
}

static void c33_c_info_helper(const mxArray **c33_info)
{
  const mxArray *c33_rhs128 = NULL;
  const mxArray *c33_lhs128 = NULL;
  const mxArray *c33_rhs129 = NULL;
  const mxArray *c33_lhs129 = NULL;
  const mxArray *c33_rhs130 = NULL;
  const mxArray *c33_lhs130 = NULL;
  const mxArray *c33_rhs131 = NULL;
  const mxArray *c33_lhs131 = NULL;
  const mxArray *c33_rhs132 = NULL;
  const mxArray *c33_lhs132 = NULL;
  const mxArray *c33_rhs133 = NULL;
  const mxArray *c33_lhs133 = NULL;
  const mxArray *c33_rhs134 = NULL;
  const mxArray *c33_lhs134 = NULL;
  const mxArray *c33_rhs135 = NULL;
  const mxArray *c33_lhs135 = NULL;
  const mxArray *c33_rhs136 = NULL;
  const mxArray *c33_lhs136 = NULL;
  const mxArray *c33_rhs137 = NULL;
  const mxArray *c33_lhs137 = NULL;
  const mxArray *c33_rhs138 = NULL;
  const mxArray *c33_lhs138 = NULL;
  const mxArray *c33_rhs139 = NULL;
  const mxArray *c33_lhs139 = NULL;
  const mxArray *c33_rhs140 = NULL;
  const mxArray *c33_lhs140 = NULL;
  const mxArray *c33_rhs141 = NULL;
  const mxArray *c33_lhs141 = NULL;
  const mxArray *c33_rhs142 = NULL;
  const mxArray *c33_lhs142 = NULL;
  const mxArray *c33_rhs143 = NULL;
  const mxArray *c33_lhs143 = NULL;
  const mxArray *c33_rhs144 = NULL;
  const mxArray *c33_lhs144 = NULL;
  const mxArray *c33_rhs145 = NULL;
  const mxArray *c33_lhs145 = NULL;
  const mxArray *c33_rhs146 = NULL;
  const mxArray *c33_lhs146 = NULL;
  const mxArray *c33_rhs147 = NULL;
  const mxArray *c33_lhs147 = NULL;
  const mxArray *c33_rhs148 = NULL;
  const mxArray *c33_lhs148 = NULL;
  const mxArray *c33_rhs149 = NULL;
  const mxArray *c33_lhs149 = NULL;
  const mxArray *c33_rhs150 = NULL;
  const mxArray *c33_lhs150 = NULL;
  const mxArray *c33_rhs151 = NULL;
  const mxArray *c33_lhs151 = NULL;
  const mxArray *c33_rhs152 = NULL;
  const mxArray *c33_lhs152 = NULL;
  const mxArray *c33_rhs153 = NULL;
  const mxArray *c33_lhs153 = NULL;
  const mxArray *c33_rhs154 = NULL;
  const mxArray *c33_lhs154 = NULL;
  const mxArray *c33_rhs155 = NULL;
  const mxArray *c33_lhs155 = NULL;
  const mxArray *c33_rhs156 = NULL;
  const mxArray *c33_lhs156 = NULL;
  const mxArray *c33_rhs157 = NULL;
  const mxArray *c33_lhs157 = NULL;
  const mxArray *c33_rhs158 = NULL;
  const mxArray *c33_lhs158 = NULL;
  const mxArray *c33_rhs159 = NULL;
  const mxArray *c33_lhs159 = NULL;
  const mxArray *c33_rhs160 = NULL;
  const mxArray *c33_lhs160 = NULL;
  const mxArray *c33_rhs161 = NULL;
  const mxArray *c33_lhs161 = NULL;
  const mxArray *c33_rhs162 = NULL;
  const mxArray *c33_lhs162 = NULL;
  const mxArray *c33_rhs163 = NULL;
  const mxArray *c33_lhs163 = NULL;
  const mxArray *c33_rhs164 = NULL;
  const mxArray *c33_lhs164 = NULL;
  const mxArray *c33_rhs165 = NULL;
  const mxArray *c33_lhs165 = NULL;
  const mxArray *c33_rhs166 = NULL;
  const mxArray *c33_lhs166 = NULL;
  const mxArray *c33_rhs167 = NULL;
  const mxArray *c33_lhs167 = NULL;
  const mxArray *c33_rhs168 = NULL;
  const mxArray *c33_lhs168 = NULL;
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 128);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 128);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c33_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs128), "rhs",
                  "rhs", 128);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs128), "lhs",
                  "lhs", 128);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 129);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 129);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 129);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 129);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c33_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs129), "rhs",
                  "rhs", 129);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs129), "lhs",
                  "lhs", 129);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 130);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 130);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 130);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 130);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c33_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs130), "rhs",
                  "rhs", 130);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs130), "lhs",
                  "lhs", 130);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 131);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.refblas.xger"),
                  "name", "name", 131);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 131);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "resolved", "resolved", 131);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c33_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs131), "rhs",
                  "rhs", 131);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs131), "lhs",
                  "lhs", 131);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "context", "context", 132);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.refblas.xgerx"), "name", "name", 132);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 132);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "resolved", "resolved", 132);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c33_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs132), "rhs",
                  "rhs", 132);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs132), "lhs",
                  "lhs", 132);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 133);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("abs"), "name", "name", 133);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 133);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 133);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363717452U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c33_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs133), "rhs",
                  "rhs", 133);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs133), "lhs",
                  "lhs", 133);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 134);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 134);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 134);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c33_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs134), "rhs",
                  "rhs", 134);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs134), "lhs",
                  "lhs", 134);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 135);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 135);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 135);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c33_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs135), "rhs",
                  "rhs", 135);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs135), "lhs",
                  "lhs", 135);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 136);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 136);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c33_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs136), "rhs",
                  "rhs", 136);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs136), "lhs",
                  "lhs", 136);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 137);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 137);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 137);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 137);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372590360U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c33_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs137), "rhs",
                  "rhs", 137);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs137), "lhs",
                  "lhs", 137);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN"), "context",
                  "context", 138);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_ipiv2perm"), "name",
                  "name", 138);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 138);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m"), "resolved",
                  "resolved", 138);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286825982U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c33_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs138), "rhs",
                  "rhs", 138);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs138), "lhs",
                  "lhs", 138);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m"), "context",
                  "context", 139);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("colon"), "name", "name", 139);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 139);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1378303188U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c33_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs139), "rhs",
                  "rhs", 139);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs139), "lhs",
                  "lhs", 139);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m"), "context",
                  "context", 140);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 140);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 140);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c33_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs140), "rhs",
                  "rhs", 140);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs140), "lhs",
                  "lhs", 140);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m"), "context",
                  "context", 141);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 141);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 141);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1326731922U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c33_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs141), "rhs",
                  "rhs", 141);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs141), "lhs",
                  "lhs", 141);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN"), "context",
                  "context", 142);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 142);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 142);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 142);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c33_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs142), "rhs",
                  "rhs", 142);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs142), "lhs",
                  "lhs", 142);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN"), "context",
                  "context", 143);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 143);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 143);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1372589616U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c33_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs143), "rhs",
                  "rhs", 143);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs143), "lhs",
                  "lhs", 143);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN"), "context",
                  "context", 144);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 144);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 144);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 144);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 144);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 144);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 144);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 144);
  sf_mex_assign(&c33_rhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs144), "rhs",
                  "rhs", 144);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs144), "lhs",
                  "lhs", 144);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN"), "context",
                  "context", 145);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_xtrsm"), "name", "name",
                  145);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 145);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"),
                  "resolved", "resolved", 145);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987892U), "fileTimeLo",
                  "fileTimeLo", 145);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 145);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 145);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 145);
  sf_mex_assign(&c33_rhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs145), "rhs",
                  "rhs", 145);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs145), "lhs",
                  "lhs", 145);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 146);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 146);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 146);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 146);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 146);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 146);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 146);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 146);
  sf_mex_assign(&c33_rhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs146), "rhs",
                  "rhs", 146);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs146), "lhs",
                  "lhs", 146);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 147);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.blas.xtrsm"),
                  "name", "name", 147);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 147);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "resolved", "resolved", 147);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 147);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 147);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 147);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 147);
  sf_mex_assign(&c33_rhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs147), "rhs",
                  "rhs", 147);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs147), "lhs",
                  "lhs", 147);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 148);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 148);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 148);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 148);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 148);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 148);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 148);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 148);
  sf_mex_assign(&c33_rhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs148), "rhs",
                  "rhs", 148);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs148), "lhs",
                  "lhs", 148);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p!below_threshold"),
                  "context", "context", 149);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 149);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 149);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 149);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 149);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 149);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 149);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 149);
  sf_mex_assign(&c33_rhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs149), "rhs",
                  "rhs", 149);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs149), "lhs",
                  "lhs", 149);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 150);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 150);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 150);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 150);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 150);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 150);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 150);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 150);
  sf_mex_assign(&c33_rhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs150), "rhs",
                  "rhs", 150);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs150), "lhs",
                  "lhs", 150);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 151);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.refblas.xtrsm"), "name", "name", 151);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 151);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "resolved", "resolved", 151);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 151);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 151);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 151);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 151);
  sf_mex_assign(&c33_rhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs151), "rhs",
                  "rhs", 151);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs151), "lhs",
                  "lhs", 151);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 152);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 152);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 152);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 152);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 152);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 152);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 152);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 152);
  sf_mex_assign(&c33_rhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs152), "rhs",
                  "rhs", 152);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs152), "lhs",
                  "lhs", 152);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 153);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 153);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 153);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 153);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 153);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 153);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 153);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 153);
  sf_mex_assign(&c33_rhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs153), "rhs",
                  "rhs", 153);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs153), "lhs",
                  "lhs", 153);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 154);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 154);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 154);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 154);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 154);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 154);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 154);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 154);
  sf_mex_assign(&c33_rhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs154), "rhs",
                  "rhs", 154);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs154), "lhs",
                  "lhs", 154);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 155);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("intmin"), "name", "name",
                  155);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 155);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 155);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 155);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 155);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 155);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 155);
  sf_mex_assign(&c33_rhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs155), "rhs",
                  "rhs", 155);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs155), "lhs",
                  "lhs", 155);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 156);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("rdivide"), "name", "name",
                  156);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 156);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 156);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 156);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 156);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 156);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 156);
  sf_mex_assign(&c33_rhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs156), "rhs",
                  "rhs", 156);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs156), "lhs",
                  "lhs", 156);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 157);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("norm"), "name", "name", 157);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 157);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 157);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363717468U), "fileTimeLo",
                  "fileTimeLo", 157);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 157);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 157);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 157);
  sf_mex_assign(&c33_rhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs157), "rhs",
                  "rhs", 157);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs157), "lhs",
                  "lhs", 157);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 158);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 158);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 158);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 158);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 158);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 158);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 158);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 158);
  sf_mex_assign(&c33_rhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs158), "rhs",
                  "rhs", 158);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs158), "lhs",
                  "lhs", 158);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 159);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("abs"), "name", "name", 159);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 159);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 159);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363717452U), "fileTimeLo",
                  "fileTimeLo", 159);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 159);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 159);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 159);
  sf_mex_assign(&c33_rhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs159), "rhs",
                  "rhs", 159);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs159), "lhs",
                  "lhs", 159);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 160);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("isnan"), "name", "name", 160);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 160);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 160);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363717458U), "fileTimeLo",
                  "fileTimeLo", 160);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 160);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 160);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 160);
  sf_mex_assign(&c33_rhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs160), "rhs",
                  "rhs", 160);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs160), "lhs",
                  "lhs", 160);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 161);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 161);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 161);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 161);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 161);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 161);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 161);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 161);
  sf_mex_assign(&c33_rhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs161), "rhs",
                  "rhs", 161);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs161), "lhs",
                  "lhs", 161);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 162);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 162);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 162);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 162);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286825976U), "fileTimeLo",
                  "fileTimeLo", 162);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 162);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 162);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 162);
  sf_mex_assign(&c33_rhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs162), "rhs",
                  "rhs", 162);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs162), "lhs",
                  "lhs", 162);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 163);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 163);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 163);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 163);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286825982U), "fileTimeLo",
                  "fileTimeLo", 163);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 163);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 163);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 163);
  sf_mex_assign(&c33_rhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs163), "rhs",
                  "rhs", 163);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs163), "lhs",
                  "lhs", 163);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 164);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_warning"), "name",
                  "name", 164);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 164);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 164);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1286826002U), "fileTimeLo",
                  "fileTimeLo", 164);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 164);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 164);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 164);
  sf_mex_assign(&c33_rhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs164), "rhs",
                  "rhs", 164);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs164), "lhs",
                  "lhs", 164);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 165);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("isnan"), "name", "name", 165);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 165);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 165);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1363717458U), "fileTimeLo",
                  "fileTimeLo", 165);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 165);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 165);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 165);
  sf_mex_assign(&c33_rhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs165), "rhs",
                  "rhs", 165);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs165), "lhs",
                  "lhs", 165);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 166);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eps"), "name", "name", 166);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 166);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 166);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1326731596U), "fileTimeLo",
                  "fileTimeLo", 166);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 166);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 166);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 166);
  sf_mex_assign(&c33_rhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs166), "rhs",
                  "rhs", 166);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs166), "lhs",
                  "lhs", 166);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond"),
                  "context", "context", 167);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("eml_flt2str"), "name",
                  "name", 167);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 167);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "resolved",
                  "resolved", 167);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1360285950U), "fileTimeLo",
                  "fileTimeLo", 167);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 167);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 167);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 167);
  sf_mex_assign(&c33_rhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs167), "rhs",
                  "rhs", 167);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs167), "lhs",
                  "lhs", 167);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m"), "context",
                  "context", 168);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("char"), "name", "name", 168);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 168);
  sf_mex_addfield(*c33_info, c33_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 168);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(1319737168U), "fileTimeLo",
                  "fileTimeLo", 168);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 168);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 168);
  sf_mex_addfield(*c33_info, c33_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 168);
  sf_mex_assign(&c33_rhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c33_lhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_rhs168), "rhs",
                  "rhs", 168);
  sf_mex_addfield(*c33_info, sf_mex_duplicatearraysafe(&c33_lhs168), "lhs",
                  "lhs", 168);
  sf_mex_destroy(&c33_rhs128);
  sf_mex_destroy(&c33_lhs128);
  sf_mex_destroy(&c33_rhs129);
  sf_mex_destroy(&c33_lhs129);
  sf_mex_destroy(&c33_rhs130);
  sf_mex_destroy(&c33_lhs130);
  sf_mex_destroy(&c33_rhs131);
  sf_mex_destroy(&c33_lhs131);
  sf_mex_destroy(&c33_rhs132);
  sf_mex_destroy(&c33_lhs132);
  sf_mex_destroy(&c33_rhs133);
  sf_mex_destroy(&c33_lhs133);
  sf_mex_destroy(&c33_rhs134);
  sf_mex_destroy(&c33_lhs134);
  sf_mex_destroy(&c33_rhs135);
  sf_mex_destroy(&c33_lhs135);
  sf_mex_destroy(&c33_rhs136);
  sf_mex_destroy(&c33_lhs136);
  sf_mex_destroy(&c33_rhs137);
  sf_mex_destroy(&c33_lhs137);
  sf_mex_destroy(&c33_rhs138);
  sf_mex_destroy(&c33_lhs138);
  sf_mex_destroy(&c33_rhs139);
  sf_mex_destroy(&c33_lhs139);
  sf_mex_destroy(&c33_rhs140);
  sf_mex_destroy(&c33_lhs140);
  sf_mex_destroy(&c33_rhs141);
  sf_mex_destroy(&c33_lhs141);
  sf_mex_destroy(&c33_rhs142);
  sf_mex_destroy(&c33_lhs142);
  sf_mex_destroy(&c33_rhs143);
  sf_mex_destroy(&c33_lhs143);
  sf_mex_destroy(&c33_rhs144);
  sf_mex_destroy(&c33_lhs144);
  sf_mex_destroy(&c33_rhs145);
  sf_mex_destroy(&c33_lhs145);
  sf_mex_destroy(&c33_rhs146);
  sf_mex_destroy(&c33_lhs146);
  sf_mex_destroy(&c33_rhs147);
  sf_mex_destroy(&c33_lhs147);
  sf_mex_destroy(&c33_rhs148);
  sf_mex_destroy(&c33_lhs148);
  sf_mex_destroy(&c33_rhs149);
  sf_mex_destroy(&c33_lhs149);
  sf_mex_destroy(&c33_rhs150);
  sf_mex_destroy(&c33_lhs150);
  sf_mex_destroy(&c33_rhs151);
  sf_mex_destroy(&c33_lhs151);
  sf_mex_destroy(&c33_rhs152);
  sf_mex_destroy(&c33_lhs152);
  sf_mex_destroy(&c33_rhs153);
  sf_mex_destroy(&c33_lhs153);
  sf_mex_destroy(&c33_rhs154);
  sf_mex_destroy(&c33_lhs154);
  sf_mex_destroy(&c33_rhs155);
  sf_mex_destroy(&c33_lhs155);
  sf_mex_destroy(&c33_rhs156);
  sf_mex_destroy(&c33_lhs156);
  sf_mex_destroy(&c33_rhs157);
  sf_mex_destroy(&c33_lhs157);
  sf_mex_destroy(&c33_rhs158);
  sf_mex_destroy(&c33_lhs158);
  sf_mex_destroy(&c33_rhs159);
  sf_mex_destroy(&c33_lhs159);
  sf_mex_destroy(&c33_rhs160);
  sf_mex_destroy(&c33_lhs160);
  sf_mex_destroy(&c33_rhs161);
  sf_mex_destroy(&c33_lhs161);
  sf_mex_destroy(&c33_rhs162);
  sf_mex_destroy(&c33_lhs162);
  sf_mex_destroy(&c33_rhs163);
  sf_mex_destroy(&c33_lhs163);
  sf_mex_destroy(&c33_rhs164);
  sf_mex_destroy(&c33_lhs164);
  sf_mex_destroy(&c33_rhs165);
  sf_mex_destroy(&c33_lhs165);
  sf_mex_destroy(&c33_rhs166);
  sf_mex_destroy(&c33_lhs166);
  sf_mex_destroy(&c33_rhs167);
  sf_mex_destroy(&c33_lhs167);
  sf_mex_destroy(&c33_rhs168);
  sf_mex_destroy(&c33_lhs168);
}

static void c33_eml_scalar_eg(SFc33_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c33_threshold(SFc33_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c33_eml_switch_helper(SFc33_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c33_b_eml_switch_helper(SFc33_juecefinishiInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c33_b_eml_scalar_eg(SFc33_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c33_c_eml_scalar_eg(SFc33_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c33_inv(SFc33_juecefinishiInstanceStruct *chartInstance, real_T
                    c33_x[36], real_T c33_y[36])
{
  int32_T c33_i227;
  real_T c33_b_x[36];
  int32_T c33_i228;
  int32_T c33_info;
  int32_T c33_ipiv[6];
  int32_T c33_i229;
  int32_T c33_b_ipiv[6];
  int32_T c33_k;
  int32_T c33_b_k;
  int32_T c33_c;
  int32_T c33_c_k;
  int32_T c33_a;
  int32_T c33_b_a;
  boolean_T c33_overflow;
  int32_T c33_j;
  int32_T c33_b_j;
  int32_T c33_c_a;
  int32_T c33_d_a;
  int32_T c33_i230;
  int32_T c33_e_a;
  int32_T c33_f_a;
  boolean_T c33_b_overflow;
  int32_T c33_i;
  int32_T c33_b_i;
  int32_T c33_i231;
  real_T c33_c_x[36];
  int32_T c33_i232;
  real_T c33_d_x[36];
  real_T c33_n1x;
  int32_T c33_i233;
  real_T c33_b_y[36];
  real_T c33_n1xinv;
  real_T c33_rc;
  real_T c33_e_x;
  boolean_T c33_b;
  real_T c33_f_x;
  int32_T c33_i234;
  static char_T c33_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c33_u[8];
  const mxArray *c33_c_y = NULL;
  real_T c33_b_u;
  const mxArray *c33_d_y = NULL;
  real_T c33_c_u;
  const mxArray *c33_e_y = NULL;
  real_T c33_d_u;
  const mxArray *c33_f_y = NULL;
  char_T c33_str[14];
  int32_T c33_i235;
  char_T c33_b_str[14];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  for (c33_i227 = 0; c33_i227 < 36; c33_i227++) {
    c33_b_x[c33_i227] = c33_x[c33_i227];
  }

  for (c33_i228 = 0; c33_i228 < 36; c33_i228++) {
    c33_y[c33_i228] = 0.0;
  }

  c33_b_eml_matlab_zgetrf(chartInstance, c33_b_x, c33_ipiv, &c33_info);
  for (c33_i229 = 0; c33_i229 < 6; c33_i229++) {
    c33_b_ipiv[c33_i229] = c33_ipiv[c33_i229];
  }

  c33_eml_ipiv2perm(chartInstance, c33_b_ipiv, c33_ipiv);
  for (c33_k = 1; c33_k < 7; c33_k++) {
    c33_b_k = c33_k;
    c33_c = c33_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c33_b_k), 1, 6, 1, 0) - 1];
    c33_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c33_b_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c33_c), 1, 6, 2, 0) - 1)) -
      1] = 1.0;
    c33_c_k = c33_b_k;
    c33_a = c33_c_k;
    c33_b_a = c33_a;
    if (c33_b_a > 6) {
      c33_overflow = false;
    } else {
      c33_eml_switch_helper(chartInstance);
      c33_overflow = false;
    }

    if (c33_overflow) {
      c33_check_forloop_overflow_error(chartInstance, c33_overflow);
    }

    for (c33_j = c33_c_k; c33_j < 7; c33_j++) {
      c33_b_j = c33_j;
      if (c33_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c33_b_j), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c33_c), 1, 6, 2, 0) - 1)) -
          1] != 0.0) {
        c33_c_a = c33_b_j;
        c33_d_a = c33_c_a + 1;
        c33_i230 = c33_d_a;
        c33_e_a = c33_i230;
        c33_f_a = c33_e_a;
        if (c33_f_a > 6) {
          c33_b_overflow = false;
        } else {
          c33_eml_switch_helper(chartInstance);
          c33_b_overflow = false;
        }

        if (c33_b_overflow) {
          c33_check_forloop_overflow_error(chartInstance, c33_b_overflow);
        }

        for (c33_i = c33_i230; c33_i < 7; c33_i++) {
          c33_b_i = c33_i;
          c33_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c33_b_i), 1, 6, 1, 0) + 6 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c33_c), 1, 6, 2, 0) - 1)) - 1] = c33_y
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c33_b_i), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c33_c), 1, 6, 2, 0)
               - 1)) - 1] - c33_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c33_b_j), 1, 6, 1, 0) + 6 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c33_c), 1, 6, 2, 0) - 1)) - 1] * c33_b_x
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c33_b_i), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c33_b_j), 1, 6, 2, 0)
               - 1)) - 1];
        }
      }
    }
  }

  for (c33_i231 = 0; c33_i231 < 36; c33_i231++) {
    c33_c_x[c33_i231] = c33_b_x[c33_i231];
  }

  c33_b_eml_xtrsm(chartInstance, c33_c_x, c33_y);
  for (c33_i232 = 0; c33_i232 < 36; c33_i232++) {
    c33_d_x[c33_i232] = c33_x[c33_i232];
  }

  c33_n1x = c33_norm(chartInstance, c33_d_x);
  for (c33_i233 = 0; c33_i233 < 36; c33_i233++) {
    c33_b_y[c33_i233] = c33_y[c33_i233];
  }

  c33_n1xinv = c33_norm(chartInstance, c33_b_y);
  c33_rc = 1.0 / (c33_n1x * c33_n1xinv);
  guard1 = false;
  guard2 = false;
  if (c33_n1x == 0.0) {
    guard2 = true;
  } else if (c33_n1xinv == 0.0) {
    guard2 = true;
  } else if (c33_rc == 0.0) {
    guard1 = true;
  } else {
    c33_e_x = c33_rc;
    c33_b = muDoubleScalarIsNaN(c33_e_x);
    guard3 = false;
    if (c33_b) {
      guard3 = true;
    } else {
      c33_eps(chartInstance);
      if (c33_rc < 2.2204460492503131E-16) {
        guard3 = true;
      }
    }

    if (guard3 == true) {
      c33_f_x = c33_rc;
      for (c33_i234 = 0; c33_i234 < 8; c33_i234++) {
        c33_u[c33_i234] = c33_cv0[c33_i234];
      }

      c33_c_y = NULL;
      sf_mex_assign(&c33_c_y, sf_mex_create("y", c33_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    false);
      c33_b_u = 14.0;
      c33_d_y = NULL;
      sf_mex_assign(&c33_d_y, sf_mex_create("y", &c33_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      c33_c_u = 6.0;
      c33_e_y = NULL;
      sf_mex_assign(&c33_e_y, sf_mex_create("y", &c33_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      c33_d_u = c33_f_x;
      c33_f_y = NULL;
      sf_mex_assign(&c33_f_y, sf_mex_create("y", &c33_d_u, 0, 0U, 0U, 0U, 0),
                    false);
      c33_o_emlrt_marshallIn(chartInstance, sf_mex_call_debug
        (sfGlobalDebugInstanceStruct, "sprintf", 1U, 2U, 14, sf_mex_call_debug
         (sfGlobalDebugInstanceStruct, "sprintf", 1U, 3U, 14, c33_c_y, 14,
          c33_d_y, 14, c33_e_y), 14, c33_f_y), "sprintf", c33_str);
      for (c33_i235 = 0; c33_i235 < 14; c33_i235++) {
        c33_b_str[c33_i235] = c33_str[c33_i235];
      }

      c33_b_eml_warning(chartInstance, c33_b_str);
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c33_eml_warning(chartInstance);
  }
}

static void c33_eps(SFc33_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c33_eml_matlab_zgetrf(SFc33_juecefinishiInstanceStruct
  *chartInstance, real_T c33_A[36], real_T c33_b_A[36], int32_T c33_ipiv[6],
  int32_T *c33_info)
{
  int32_T c33_i236;
  for (c33_i236 = 0; c33_i236 < 36; c33_i236++) {
    c33_b_A[c33_i236] = c33_A[c33_i236];
  }

  c33_b_eml_matlab_zgetrf(chartInstance, c33_b_A, c33_ipiv, c33_info);
}

static int32_T c33_eml_ixamax(SFc33_juecefinishiInstanceStruct *chartInstance,
  int32_T c33_n, real_T c33_x[36], int32_T c33_ix0)
{
  int32_T c33_idxmax;
  int32_T c33_b_n;
  int32_T c33_b_ix0;
  int32_T c33_c_n;
  int32_T c33_c_ix0;
  int32_T c33_ix;
  real_T c33_b_x;
  real_T c33_c_x;
  real_T c33_d_x;
  real_T c33_y;
  real_T c33_e_x;
  real_T c33_f_x;
  real_T c33_b_y;
  real_T c33_smax;
  int32_T c33_d_n;
  int32_T c33_b;
  int32_T c33_b_b;
  boolean_T c33_overflow;
  int32_T c33_k;
  int32_T c33_b_k;
  int32_T c33_a;
  real_T c33_g_x;
  real_T c33_h_x;
  real_T c33_i_x;
  real_T c33_c_y;
  real_T c33_j_x;
  real_T c33_k_x;
  real_T c33_d_y;
  real_T c33_s;
  c33_b_n = c33_n;
  c33_b_ix0 = c33_ix0;
  c33_c_n = c33_b_n;
  c33_c_ix0 = c33_b_ix0;
  if (c33_c_n < 1) {
    c33_idxmax = 0;
  } else {
    c33_idxmax = 1;
    if (c33_c_n > 1) {
      c33_ix = c33_c_ix0;
      c33_b_x = c33_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c33_ix), 1, 36, 1, 0) - 1];
      c33_c_x = c33_b_x;
      c33_d_x = c33_c_x;
      c33_y = muDoubleScalarAbs(c33_d_x);
      c33_e_x = 0.0;
      c33_f_x = c33_e_x;
      c33_b_y = muDoubleScalarAbs(c33_f_x);
      c33_smax = c33_y + c33_b_y;
      c33_d_n = c33_c_n;
      c33_b = c33_d_n;
      c33_b_b = c33_b;
      if (2 > c33_b_b) {
        c33_overflow = false;
      } else {
        c33_eml_switch_helper(chartInstance);
        c33_overflow = (c33_b_b > 2147483646);
      }

      if (c33_overflow) {
        c33_check_forloop_overflow_error(chartInstance, c33_overflow);
      }

      for (c33_k = 2; c33_k <= c33_d_n; c33_k++) {
        c33_b_k = c33_k;
        c33_a = c33_ix + 1;
        c33_ix = c33_a;
        c33_g_x = c33_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c33_ix), 1, 36, 1, 0) - 1];
        c33_h_x = c33_g_x;
        c33_i_x = c33_h_x;
        c33_c_y = muDoubleScalarAbs(c33_i_x);
        c33_j_x = 0.0;
        c33_k_x = c33_j_x;
        c33_d_y = muDoubleScalarAbs(c33_k_x);
        c33_s = c33_c_y + c33_d_y;
        if (c33_s > c33_smax) {
          c33_idxmax = c33_b_k;
          c33_smax = c33_s;
        }
      }
    }
  }

  return c33_idxmax;
}

static void c33_check_forloop_overflow_error(SFc33_juecefinishiInstanceStruct
  *chartInstance, boolean_T c33_overflow)
{
  int32_T c33_i237;
  static char_T c33_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c33_u[34];
  const mxArray *c33_y = NULL;
  int32_T c33_i238;
  static char_T c33_cv2[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c33_b_u[23];
  const mxArray *c33_b_y = NULL;
  (void)chartInstance;
  if (!c33_overflow) {
  } else {
    for (c33_i237 = 0; c33_i237 < 34; c33_i237++) {
      c33_u[c33_i237] = c33_cv1[c33_i237];
    }

    c33_y = NULL;
    sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c33_i238 = 0; c33_i238 < 23; c33_i238++) {
      c33_b_u[c33_i238] = c33_cv2[c33_i238];
    }

    c33_b_y = NULL;
    sf_mex_assign(&c33_b_y, sf_mex_create("y", c33_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c33_y, 14, c33_b_y));
  }
}

static void c33_b_threshold(SFc33_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c33_eml_xgeru(SFc33_juecefinishiInstanceStruct *chartInstance,
  int32_T c33_m, int32_T c33_n, real_T c33_alpha1, int32_T c33_ix0, int32_T
  c33_iy0, real_T c33_A[36], int32_T c33_ia0, real_T c33_b_A[36])
{
  int32_T c33_i239;
  for (c33_i239 = 0; c33_i239 < 36; c33_i239++) {
    c33_b_A[c33_i239] = c33_A[c33_i239];
  }

  c33_b_eml_xgeru(chartInstance, c33_m, c33_n, c33_alpha1, c33_ix0, c33_iy0,
                  c33_b_A, c33_ia0);
}

static void c33_eml_ipiv2perm(SFc33_juecefinishiInstanceStruct *chartInstance,
  int32_T c33_ipiv[6], int32_T c33_perm[6])
{
  int32_T c33_i240;
  int32_T c33_k;
  real_T c33_b_k;
  int32_T c33_ipk;
  int32_T c33_a;
  real_T c33_b;
  int32_T c33_b_a;
  real_T c33_b_b;
  int32_T c33_idx;
  real_T c33_flt;
  boolean_T c33_p;
  int32_T c33_pipk;
  for (c33_i240 = 0; c33_i240 < 6; c33_i240++) {
    c33_perm[c33_i240] = 1 + c33_i240;
  }

  for (c33_k = 0; c33_k < 5; c33_k++) {
    c33_b_k = 1.0 + (real_T)c33_k;
    c33_ipk = c33_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c33_b_k), 1, 6, 1, 0) - 1];
    c33_a = c33_ipk;
    c33_b = c33_b_k;
    c33_b_a = c33_a;
    c33_b_b = c33_b;
    c33_b_eml_switch_helper(chartInstance);
    c33_idx = c33_b_a;
    c33_flt = c33_b_b;
    c33_p = ((real_T)c33_idx > c33_flt);
    if (c33_p) {
      c33_pipk = c33_perm[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c33_ipk), 1, 6, 1, 0) - 1];
      c33_perm[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c33_ipk), 1, 6, 1, 0) - 1] =
        c33_perm[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c33_b_k), 1, 6, 1, 0) - 1];
      c33_perm[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c33_b_k), 1, 6, 1, 0) - 1] = c33_pipk;
    }
  }
}

static void c33_eml_xtrsm(SFc33_juecefinishiInstanceStruct *chartInstance,
  real_T c33_A[36], real_T c33_B[36], real_T c33_b_B[36])
{
  int32_T c33_i241;
  int32_T c33_i242;
  real_T c33_b_A[36];
  for (c33_i241 = 0; c33_i241 < 36; c33_i241++) {
    c33_b_B[c33_i241] = c33_B[c33_i241];
  }

  for (c33_i242 = 0; c33_i242 < 36; c33_i242++) {
    c33_b_A[c33_i242] = c33_A[c33_i242];
  }

  c33_b_eml_xtrsm(chartInstance, c33_b_A, c33_b_B);
}

static void c33_c_threshold(SFc33_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c33_norm(SFc33_juecefinishiInstanceStruct *chartInstance, real_T
  c33_x[36])
{
  real_T c33_y;
  int32_T c33_j;
  real_T c33_b_j;
  real_T c33_s;
  int32_T c33_i;
  real_T c33_b_i;
  real_T c33_b_x;
  real_T c33_c_x;
  real_T c33_b_y;
  real_T c33_d_x;
  boolean_T c33_b;
  boolean_T exitg1;
  (void)chartInstance;
  c33_y = 0.0;
  c33_j = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c33_j < 6)) {
    c33_b_j = 1.0 + (real_T)c33_j;
    c33_s = 0.0;
    for (c33_i = 0; c33_i < 6; c33_i++) {
      c33_b_i = 1.0 + (real_T)c33_i;
      c33_b_x = c33_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c33_b_i), 1, 6, 1, 0) + 6 *
                       (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c33_b_j), 1, 6, 2, 0) - 1)) - 1];
      c33_c_x = c33_b_x;
      c33_b_y = muDoubleScalarAbs(c33_c_x);
      c33_s += c33_b_y;
    }

    c33_d_x = c33_s;
    c33_b = muDoubleScalarIsNaN(c33_d_x);
    if (c33_b) {
      c33_y = rtNaN;
      exitg1 = true;
    } else {
      if (c33_s > c33_y) {
        c33_y = c33_s;
      }

      c33_j++;
    }
  }

  return c33_y;
}

static void c33_eml_warning(SFc33_juecefinishiInstanceStruct *chartInstance)
{
  int32_T c33_i243;
  static char_T c33_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c33_u[27];
  const mxArray *c33_y = NULL;
  (void)chartInstance;
  for (c33_i243 = 0; c33_i243 < 27; c33_i243++) {
    c33_u[c33_i243] = c33_varargin_1[c33_i243];
  }

  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c33_y));
}

static void c33_b_eml_warning(SFc33_juecefinishiInstanceStruct *chartInstance,
  char_T c33_varargin_2[14])
{
  int32_T c33_i244;
  static char_T c33_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c33_u[33];
  const mxArray *c33_y = NULL;
  int32_T c33_i245;
  char_T c33_b_u[14];
  const mxArray *c33_b_y = NULL;
  (void)chartInstance;
  for (c33_i244 = 0; c33_i244 < 33; c33_i244++) {
    c33_u[c33_i244] = c33_varargin_1[c33_i244];
  }

  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  for (c33_i245 = 0; c33_i245 < 14; c33_i245++) {
    c33_b_u[c33_i245] = c33_varargin_2[c33_i245];
  }

  c33_b_y = NULL;
  sf_mex_assign(&c33_b_y, sf_mex_create("y", c33_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c33_y, 14, c33_b_y));
}

static void c33_d_eml_scalar_eg(SFc33_juecefinishiInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c33_eye(SFc33_juecefinishiInstanceStruct *chartInstance, real_T
                    c33_I[36])
{
  int32_T c33_i246;
  int32_T c33_k;
  int32_T c33_b_k;
  (void)chartInstance;
  for (c33_i246 = 0; c33_i246 < 36; c33_i246++) {
    c33_I[c33_i246] = 0.0;
  }

  for (c33_k = 1; c33_k < 7; c33_k++) {
    c33_b_k = c33_k;
    c33_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c33_b_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c33_b_k), 1, 6, 2, 0) - 1))
      - 1] = 1.0;
  }
}

static void c33_o_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_sprintf, const char_T *c33_identifier,
  char_T c33_y[14])
{
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_sprintf), &c33_thisId,
    c33_y);
  sf_mex_destroy(&c33_sprintf);
}

static void c33_p_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  char_T c33_y[14])
{
  char_T c33_cv3[14];
  int32_T c33_i247;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_cv3, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c33_i247 = 0; c33_i247 < 14; c33_i247++) {
    c33_y[c33_i247] = c33_cv3[c33_i247];
  }

  sf_mex_destroy(&c33_u);
}

static const mxArray *c33_j_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(int32_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, false);
  return c33_mxArrayOutData;
}

static int32_T c33_q_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  int32_T c33_y;
  int32_T c33_i248;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_i248, 1, 6, 0U, 0, 0U, 0);
  c33_y = c33_i248;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_sfEvent;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  int32_T c33_y;
  SFc33_juecefinishiInstanceStruct *chartInstance;
  chartInstance = (SFc33_juecefinishiInstanceStruct *)chartInstanceVoid;
  c33_b_sfEvent = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_sfEvent),
    &c33_thisId);
  sf_mex_destroy(&c33_b_sfEvent);
  *(int32_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static uint8_T c33_r_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_b_is_active_c33_juecefinishi, const char_T *
  c33_identifier)
{
  uint8_T c33_y;
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c33_b_is_active_c33_juecefinishi), &c33_thisId);
  sf_mex_destroy(&c33_b_is_active_c33_juecefinishi);
  return c33_y;
}

static uint8_T c33_s_emlrt_marshallIn(SFc33_juecefinishiInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  uint8_T c33_y;
  uint8_T c33_u0;
  (void)chartInstance;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_u0, 1, 3, 0U, 0, 0U, 0);
  c33_y = c33_u0;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_b_eml_matlab_zgetrf(SFc33_juecefinishiInstanceStruct
  *chartInstance, real_T c33_A[36], int32_T c33_ipiv[6], int32_T *c33_info)
{
  int32_T c33_i249;
  int32_T c33_j;
  int32_T c33_b_j;
  int32_T c33_a;
  int32_T c33_b_a;
  int32_T c33_jm1;
  int32_T c33_b;
  int32_T c33_b_b;
  int32_T c33_mmj;
  int32_T c33_c_a;
  int32_T c33_d_a;
  int32_T c33_c;
  int32_T c33_c_b;
  int32_T c33_d_b;
  int32_T c33_jj;
  int32_T c33_e_a;
  int32_T c33_f_a;
  int32_T c33_jp1j;
  int32_T c33_g_a;
  int32_T c33_h_a;
  int32_T c33_b_c;
  int32_T c33_i250;
  int32_T c33_i251;
  int32_T c33_i252;
  real_T c33_b_A[36];
  int32_T c33_i_a;
  int32_T c33_j_a;
  int32_T c33_jpiv_offset;
  int32_T c33_k_a;
  int32_T c33_e_b;
  int32_T c33_l_a;
  int32_T c33_f_b;
  int32_T c33_jpiv;
  int32_T c33_m_a;
  int32_T c33_g_b;
  int32_T c33_n_a;
  int32_T c33_h_b;
  int32_T c33_c_c;
  int32_T c33_i_b;
  int32_T c33_j_b;
  int32_T c33_jrow;
  int32_T c33_o_a;
  int32_T c33_k_b;
  int32_T c33_p_a;
  int32_T c33_l_b;
  int32_T c33_jprow;
  int32_T c33_ix0;
  int32_T c33_iy0;
  int32_T c33_b_ix0;
  int32_T c33_b_iy0;
  int32_T c33_c_ix0;
  int32_T c33_c_iy0;
  int32_T c33_ix;
  int32_T c33_iy;
  int32_T c33_k;
  real_T c33_temp;
  int32_T c33_q_a;
  int32_T c33_r_a;
  int32_T c33_b_jp1j;
  int32_T c33_s_a;
  int32_T c33_t_a;
  int32_T c33_d_c;
  int32_T c33_u_a;
  int32_T c33_m_b;
  int32_T c33_v_a;
  int32_T c33_n_b;
  int32_T c33_i253;
  int32_T c33_w_a;
  int32_T c33_o_b;
  int32_T c33_x_a;
  int32_T c33_p_b;
  boolean_T c33_overflow;
  int32_T c33_i;
  int32_T c33_b_i;
  real_T c33_x;
  real_T c33_y;
  real_T c33_b_x;
  real_T c33_b_y;
  real_T c33_z;
  int32_T c33_q_b;
  int32_T c33_r_b;
  int32_T c33_e_c;
  int32_T c33_y_a;
  int32_T c33_ab_a;
  int32_T c33_f_c;
  int32_T c33_bb_a;
  int32_T c33_cb_a;
  int32_T c33_g_c;
  real_T c33_d1;
  c33_eps(chartInstance);
  for (c33_i249 = 0; c33_i249 < 6; c33_i249++) {
    c33_ipiv[c33_i249] = 1 + c33_i249;
  }

  *c33_info = 0;
  for (c33_j = 1; c33_j < 6; c33_j++) {
    c33_b_j = c33_j;
    c33_a = c33_b_j;
    c33_b_a = c33_a - 1;
    c33_jm1 = c33_b_a;
    c33_b = c33_b_j;
    c33_b_b = c33_b;
    c33_mmj = 6 - c33_b_b;
    c33_c_a = c33_jm1;
    c33_d_a = c33_c_a;
    c33_c = c33_d_a * 7;
    c33_c_b = c33_c;
    c33_d_b = c33_c_b + 1;
    c33_jj = c33_d_b;
    c33_e_a = c33_jj;
    c33_f_a = c33_e_a + 1;
    c33_jp1j = c33_f_a;
    c33_g_a = c33_mmj;
    c33_h_a = c33_g_a;
    c33_b_c = c33_h_a;
    c33_i250 = 0;
    for (c33_i251 = 0; c33_i251 < 6; c33_i251++) {
      for (c33_i252 = 0; c33_i252 < 6; c33_i252++) {
        c33_b_A[c33_i252 + c33_i250] = c33_A[c33_i252 + c33_i250];
      }

      c33_i250 += 6;
    }

    c33_i_a = c33_eml_ixamax(chartInstance, c33_b_c + 1, c33_b_A, c33_jj);
    c33_j_a = c33_i_a - 1;
    c33_jpiv_offset = c33_j_a;
    c33_k_a = c33_jj;
    c33_e_b = c33_jpiv_offset;
    c33_l_a = c33_k_a;
    c33_f_b = c33_e_b;
    c33_jpiv = c33_l_a + c33_f_b;
    if (c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c33_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if (c33_jpiv_offset != 0) {
        c33_m_a = c33_b_j;
        c33_g_b = c33_jpiv_offset;
        c33_n_a = c33_m_a;
        c33_h_b = c33_g_b;
        c33_c_c = c33_n_a + c33_h_b;
        c33_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c33_b_j), 1, 6, 1, 0) - 1] = c33_c_c;
        c33_i_b = c33_jm1;
        c33_j_b = c33_i_b + 1;
        c33_jrow = c33_j_b;
        c33_o_a = c33_jrow;
        c33_k_b = c33_jpiv_offset;
        c33_p_a = c33_o_a;
        c33_l_b = c33_k_b;
        c33_jprow = c33_p_a + c33_l_b;
        c33_ix0 = c33_jrow;
        c33_iy0 = c33_jprow;
        c33_b_ix0 = c33_ix0;
        c33_b_iy0 = c33_iy0;
        c33_b_threshold(chartInstance);
        c33_c_ix0 = c33_b_ix0;
        c33_c_iy0 = c33_b_iy0;
        c33_ix = c33_c_ix0;
        c33_iy = c33_c_iy0;
        for (c33_k = 1; c33_k < 7; c33_k++) {
          c33_temp = c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c33_ix), 1, 36, 1, 0) - 1];
          c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c33_ix), 1, 36, 1, 0) - 1] =
            c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c33_iy), 1, 36, 1, 0) - 1];
          c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c33_iy), 1, 36, 1, 0) - 1] = c33_temp;
          c33_q_a = c33_ix + 6;
          c33_ix = c33_q_a;
          c33_r_a = c33_iy + 6;
          c33_iy = c33_r_a;
        }
      }

      c33_b_jp1j = c33_jp1j;
      c33_s_a = c33_mmj;
      c33_t_a = c33_s_a;
      c33_d_c = c33_t_a;
      c33_u_a = c33_jp1j;
      c33_m_b = c33_d_c - 1;
      c33_v_a = c33_u_a;
      c33_n_b = c33_m_b;
      c33_i253 = c33_v_a + c33_n_b;
      c33_w_a = c33_b_jp1j;
      c33_o_b = c33_i253;
      c33_x_a = c33_w_a;
      c33_p_b = c33_o_b;
      if (c33_x_a > c33_p_b) {
        c33_overflow = false;
      } else {
        c33_eml_switch_helper(chartInstance);
        c33_overflow = (c33_p_b > 2147483646);
      }

      if (c33_overflow) {
        c33_check_forloop_overflow_error(chartInstance, c33_overflow);
      }

      for (c33_i = c33_b_jp1j; c33_i <= c33_i253; c33_i++) {
        c33_b_i = c33_i;
        c33_x = c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c33_b_i), 1, 36, 1, 0) - 1];
        c33_y = c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c33_jj), 1, 36, 1, 0) - 1];
        c33_b_x = c33_x;
        c33_b_y = c33_y;
        c33_z = c33_b_x / c33_b_y;
        c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c33_b_i), 1, 36, 1, 0) - 1] = c33_z;
      }
    } else {
      *c33_info = c33_b_j;
    }

    c33_q_b = c33_b_j;
    c33_r_b = c33_q_b;
    c33_e_c = 6 - c33_r_b;
    c33_y_a = c33_jj;
    c33_ab_a = c33_y_a;
    c33_f_c = c33_ab_a;
    c33_bb_a = c33_jj;
    c33_cb_a = c33_bb_a;
    c33_g_c = c33_cb_a;
    c33_d1 = -1.0;
    c33_b_eml_xgeru(chartInstance, c33_mmj, c33_e_c, c33_d1, c33_jp1j, c33_f_c +
                    6, c33_A, c33_g_c + 7);
  }

  if (*c33_info == 0) {
    if (!(c33_A[35] != 0.0)) {
      *c33_info = 6;
    }
  }
}

static void c33_b_eml_xgeru(SFc33_juecefinishiInstanceStruct *chartInstance,
  int32_T c33_m, int32_T c33_n, real_T c33_alpha1, int32_T c33_ix0, int32_T
  c33_iy0, real_T c33_A[36], int32_T c33_ia0)
{
  int32_T c33_b_m;
  int32_T c33_b_n;
  real_T c33_b_alpha1;
  int32_T c33_b_ix0;
  int32_T c33_b_iy0;
  int32_T c33_b_ia0;
  int32_T c33_c_m;
  int32_T c33_c_n;
  real_T c33_c_alpha1;
  int32_T c33_c_ix0;
  int32_T c33_c_iy0;
  int32_T c33_c_ia0;
  int32_T c33_d_m;
  int32_T c33_d_n;
  real_T c33_d_alpha1;
  int32_T c33_d_ix0;
  int32_T c33_d_iy0;
  int32_T c33_d_ia0;
  int32_T c33_e_m;
  int32_T c33_e_n;
  real_T c33_e_alpha1;
  int32_T c33_e_ix0;
  int32_T c33_e_iy0;
  int32_T c33_e_ia0;
  int32_T c33_ixstart;
  int32_T c33_a;
  int32_T c33_jA;
  int32_T c33_jy;
  int32_T c33_f_n;
  int32_T c33_b;
  int32_T c33_b_b;
  boolean_T c33_overflow;
  int32_T c33_j;
  real_T c33_yjy;
  real_T c33_temp;
  int32_T c33_ix;
  int32_T c33_c_b;
  int32_T c33_i254;
  int32_T c33_b_a;
  int32_T c33_d_b;
  int32_T c33_i255;
  int32_T c33_c_a;
  int32_T c33_e_b;
  int32_T c33_d_a;
  int32_T c33_f_b;
  boolean_T c33_b_overflow;
  int32_T c33_ijA;
  int32_T c33_b_ijA;
  int32_T c33_e_a;
  int32_T c33_f_a;
  int32_T c33_g_a;
  c33_b_m = c33_m;
  c33_b_n = c33_n;
  c33_b_alpha1 = c33_alpha1;
  c33_b_ix0 = c33_ix0;
  c33_b_iy0 = c33_iy0;
  c33_b_ia0 = c33_ia0;
  c33_c_m = c33_b_m;
  c33_c_n = c33_b_n;
  c33_c_alpha1 = c33_b_alpha1;
  c33_c_ix0 = c33_b_ix0;
  c33_c_iy0 = c33_b_iy0;
  c33_c_ia0 = c33_b_ia0;
  c33_d_m = c33_c_m;
  c33_d_n = c33_c_n;
  c33_d_alpha1 = c33_c_alpha1;
  c33_d_ix0 = c33_c_ix0;
  c33_d_iy0 = c33_c_iy0;
  c33_d_ia0 = c33_c_ia0;
  c33_e_m = c33_d_m;
  c33_e_n = c33_d_n;
  c33_e_alpha1 = c33_d_alpha1;
  c33_e_ix0 = c33_d_ix0;
  c33_e_iy0 = c33_d_iy0;
  c33_e_ia0 = c33_d_ia0;
  if (c33_e_alpha1 == 0.0) {
  } else {
    c33_ixstart = c33_e_ix0;
    c33_a = c33_e_ia0 - 1;
    c33_jA = c33_a;
    c33_jy = c33_e_iy0;
    c33_f_n = c33_e_n;
    c33_b = c33_f_n;
    c33_b_b = c33_b;
    if (1 > c33_b_b) {
      c33_overflow = false;
    } else {
      c33_eml_switch_helper(chartInstance);
      c33_overflow = (c33_b_b > 2147483646);
    }

    if (c33_overflow) {
      c33_check_forloop_overflow_error(chartInstance, c33_overflow);
    }

    for (c33_j = 1; c33_j <= c33_f_n; c33_j++) {
      c33_yjy = c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c33_jy), 1, 36, 1, 0) - 1];
      if (c33_yjy != 0.0) {
        c33_temp = c33_yjy * c33_e_alpha1;
        c33_ix = c33_ixstart;
        c33_c_b = c33_jA + 1;
        c33_i254 = c33_c_b;
        c33_b_a = c33_e_m;
        c33_d_b = c33_jA;
        c33_i255 = c33_b_a + c33_d_b;
        c33_c_a = c33_i254;
        c33_e_b = c33_i255;
        c33_d_a = c33_c_a;
        c33_f_b = c33_e_b;
        if (c33_d_a > c33_f_b) {
          c33_b_overflow = false;
        } else {
          c33_eml_switch_helper(chartInstance);
          c33_b_overflow = (c33_f_b > 2147483646);
        }

        if (c33_b_overflow) {
          c33_check_forloop_overflow_error(chartInstance, c33_b_overflow);
        }

        for (c33_ijA = c33_i254; c33_ijA <= c33_i255; c33_ijA++) {
          c33_b_ijA = c33_ijA;
          c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c33_b_ijA), 1, 36, 1, 0) - 1] =
            c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c33_b_ijA), 1, 36, 1, 0) - 1] +
            c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c33_ix), 1, 36, 1, 0) - 1] * c33_temp;
          c33_e_a = c33_ix + 1;
          c33_ix = c33_e_a;
        }
      }

      c33_f_a = c33_jy + 6;
      c33_jy = c33_f_a;
      c33_g_a = c33_jA + 6;
      c33_jA = c33_g_a;
    }
  }
}

static void c33_b_eml_xtrsm(SFc33_juecefinishiInstanceStruct *chartInstance,
  real_T c33_A[36], real_T c33_B[36])
{
  int32_T c33_j;
  int32_T c33_b_j;
  int32_T c33_jBcol;
  int32_T c33_k;
  int32_T c33_b_k;
  int32_T c33_kAcol;
  real_T c33_x;
  real_T c33_y;
  real_T c33_b_x;
  real_T c33_b_y;
  real_T c33_c_x;
  real_T c33_c_y;
  real_T c33_z;
  int32_T c33_i256;
  int32_T c33_b;
  int32_T c33_b_b;
  boolean_T c33_overflow;
  int32_T c33_i;
  int32_T c33_b_i;
  c33_c_threshold(chartInstance);
  for (c33_j = 1; c33_j < 7; c33_j++) {
    c33_b_j = c33_j - 1;
    c33_jBcol = 6 * c33_b_j;
    for (c33_k = 6; c33_k > 0; c33_k--) {
      c33_b_k = c33_k;
      c33_kAcol = 6 * (c33_b_k - 1);
      if (c33_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c33_b_k + c33_jBcol)), 1, 36, 1, 0) - 1] != 0.0) {
        c33_x = c33_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c33_b_k + c33_jBcol)), 1, 36, 1, 0) -
          1];
        c33_y = c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c33_b_k + c33_kAcol)), 1, 36, 1, 0) -
          1];
        c33_b_x = c33_x;
        c33_b_y = c33_y;
        c33_c_x = c33_b_x;
        c33_c_y = c33_b_y;
        c33_z = c33_c_x / c33_c_y;
        c33_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c33_b_k + c33_jBcol)), 1, 36, 1, 0) - 1] = c33_z;
        c33_i256 = c33_b_k - 1;
        c33_b = c33_i256;
        c33_b_b = c33_b;
        if (1 > c33_b_b) {
          c33_overflow = false;
        } else {
          c33_eml_switch_helper(chartInstance);
          c33_overflow = (c33_b_b > 2147483646);
        }

        if (c33_overflow) {
          c33_check_forloop_overflow_error(chartInstance, c33_overflow);
        }

        for (c33_i = 1; c33_i <= c33_i256; c33_i++) {
          c33_b_i = c33_i;
          c33_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c33_b_i + c33_jBcol)), 1, 36, 1, 0) - 1] =
            c33_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c33_b_i + c33_jBcol)), 1, 36, 1, 0) - 1] -
            c33_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c33_b_k + c33_jBcol)), 1, 36, 1, 0) - 1] *
            c33_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c33_b_i + c33_kAcol)), 1, 36, 1, 0) - 1];
        }
      }
    }
  }
}

static void init_dsm_address_info(SFc33_juecefinishiInstanceStruct
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

void sf_c33_juecefinishi_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1364116878U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2257886204U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1579359359U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1364857348U);
}

mxArray *sf_c33_juecefinishi_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("IavqyeNs1Rw4LHBQ2gb9UF");
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c33_juecefinishi_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c33_juecefinishi_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c33_juecefinishi(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"P\",},{M[1],M[8],T\"V\",},{M[4],M[0],T\"Mt\",S'l','i','p'{{M1x2[102 104],M[0],}}},{M[4],M[0],T\"Vt\",S'l','i','p'{{M1x2[87 89],M[0],}}},{M[4],M[0],T\"Xt\",S'l','i','p'{{M1x2[72 74],M[0],}}},{M[4],M[0],T\"a_last\",S'l','i','p'{{M1x2[117 123],M[0],}}},{M[8],M[0],T\"is_active_c33_juecefinishi\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c33_juecefinishi_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc33_juecefinishiInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc33_juecefinishiInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _juecefinishiMachineNumber_,
           33,
           1,
           1,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"p");
          _SFD_SET_DATA_PROPS(1,2,0,1,"P");
          _SFD_SET_DATA_PROPS(2,1,1,0,"a");
          _SFD_SET_DATA_PROPS(3,1,1,0,"R");
          _SFD_SET_DATA_PROPS(4,2,0,1,"V");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,816);
        _SFD_CV_INIT_EML_IF(0,1,0,125,143,-1,170);
        _SFD_CV_INIT_EML_IF(0,1,1,202,216,-1,239);
        _SFD_CV_INIT_EML_IF(0,1,2,240,254,-1,277);
        _SFD_CV_INIT_EML_IF(0,1,3,278,292,-1,333);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_e_sf_marshallOut,(MexInFcnForType)
            c33_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_e_sf_marshallOut,(MexInFcnForType)
            c33_e_sf_marshallIn);
        }

        {
          real_T (*c33_p)[3];
          real_T (*c33_P)[3];
          real_T (*c33_a)[3];
          real_T (*c33_R)[9];
          real_T (*c33_V)[3];
          c33_V = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c33_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 2);
          c33_a = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c33_P = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c33_p = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c33_p);
          _SFD_SET_DATA_VALUE_PTR(1U, *c33_P);
          _SFD_SET_DATA_VALUE_PTR(2U, *c33_a);
          _SFD_SET_DATA_VALUE_PTR(3U, *c33_R);
          _SFD_SET_DATA_VALUE_PTR(4U, *c33_V);
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
  return "D4djfdqoZDInbYlxR78t1B";
}

static void sf_opaque_initialize_c33_juecefinishi(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc33_juecefinishiInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c33_juecefinishi((SFc33_juecefinishiInstanceStruct*)
    chartInstanceVar);
  initialize_c33_juecefinishi((SFc33_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c33_juecefinishi(void *chartInstanceVar)
{
  enable_c33_juecefinishi((SFc33_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c33_juecefinishi(void *chartInstanceVar)
{
  disable_c33_juecefinishi((SFc33_juecefinishiInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c33_juecefinishi(void *chartInstanceVar)
{
  sf_gateway_c33_juecefinishi((SFc33_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c33_juecefinishi(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c33_juecefinishi
    ((SFc33_juecefinishiInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c33_juecefinishi();/* state var info */
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

extern void sf_internal_set_sim_state_c33_juecefinishi(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c33_juecefinishi();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c33_juecefinishi((SFc33_juecefinishiInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c33_juecefinishi(SimStruct* S)
{
  return sf_internal_get_sim_state_c33_juecefinishi(S);
}

static void sf_opaque_set_sim_state_c33_juecefinishi(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c33_juecefinishi(S, st);
}

static void sf_opaque_terminate_c33_juecefinishi(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc33_juecefinishiInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_juecefinishi_optimization_info();
    }

    finalize_c33_juecefinishi((SFc33_juecefinishiInstanceStruct*)
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
  initSimStructsc33_juecefinishi((SFc33_juecefinishiInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c33_juecefinishi(SimStruct *S)
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
    initialize_params_c33_juecefinishi((SFc33_juecefinishiInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c33_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_juecefinishi_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      33);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,33,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,33,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,33);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,33,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,33,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,33);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(177767177U));
  ssSetChecksum1(S,(3701302723U));
  ssSetChecksum2(S,(210082593U));
  ssSetChecksum3(S,(2783505238U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c33_juecefinishi(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c33_juecefinishi(SimStruct *S)
{
  SFc33_juecefinishiInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc33_juecefinishiInstanceStruct *)utMalloc(sizeof
    (SFc33_juecefinishiInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc33_juecefinishiInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c33_juecefinishi;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c33_juecefinishi;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c33_juecefinishi;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c33_juecefinishi;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c33_juecefinishi;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c33_juecefinishi;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c33_juecefinishi;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c33_juecefinishi;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c33_juecefinishi;
  chartInstance->chartInfo.mdlStart = mdlStart_c33_juecefinishi;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c33_juecefinishi;
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

void c33_juecefinishi_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c33_juecefinishi(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c33_juecefinishi(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c33_juecefinishi(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c33_juecefinishi_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
