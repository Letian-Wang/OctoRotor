/* Include files */

#include "juecefinishi_sfun.h"
#include "juecefinishi_sfun_debug_macros.h"
#include "c1_juecefinishi.h"
#include "c2_juecefinishi.h"
#include "c3_juecefinishi.h"
#include "c4_juecefinishi.h"
#include "c5_juecefinishi.h"
#include "c6_juecefinishi.h"
#include "c7_juecefinishi.h"
#include "c8_juecefinishi.h"
#include "c9_juecefinishi.h"
#include "c10_juecefinishi.h"
#include "c11_juecefinishi.h"
#include "c12_juecefinishi.h"
#include "c13_juecefinishi.h"
#include "c14_juecefinishi.h"
#include "c15_juecefinishi.h"
#include "c16_juecefinishi.h"
#include "c17_juecefinishi.h"
#include "c18_juecefinishi.h"
#include "c19_juecefinishi.h"
#include "c20_juecefinishi.h"
#include "c25_juecefinishi.h"
#include "c26_juecefinishi.h"
#include "c27_juecefinishi.h"
#include "c28_juecefinishi.h"
#include "c29_juecefinishi.h"
#include "c30_juecefinishi.h"
#include "c31_juecefinishi.h"
#include "c32_juecefinishi.h"
#include "c33_juecefinishi.h"
#include "c34_juecefinishi.h"
#include "c35_juecefinishi.h"
#include "c36_juecefinishi.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _juecefinishiMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void juecefinishi_initializer(void)
{
}

void juecefinishi_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_juecefinishi_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==25) {
    c25_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==27) {
    c27_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==28) {
    c28_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==29) {
    c29_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==30) {
    c30_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==32) {
    c32_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==33) {
    c33_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==34) {
    c34_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==35) {
    c35_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_juecefinishi_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_juecefinishi_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1636649331U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2058073475U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3809641280U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3863329338U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4182095140U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2127878199U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2872290947U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1190373633U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c1_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c2_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c3_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c4_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c5_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c6_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c7_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c8_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c9_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c10_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c11_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c12_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c13_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c14_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c15_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c16_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c17_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c18_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c19_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c20_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 25:
        {
          extern void sf_c25_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c25_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 26:
        {
          extern void sf_c26_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c26_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 27:
        {
          extern void sf_c27_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c27_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 28:
        {
          extern void sf_c28_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c28_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 29:
        {
          extern void sf_c29_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c29_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 30:
        {
          extern void sf_c30_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c30_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c31_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 32:
        {
          extern void sf_c32_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c32_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 33:
        {
          extern void sf_c33_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c33_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 34:
        {
          extern void sf_c34_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c34_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 35:
        {
          extern void sf_c35_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c35_juecefinishi_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_juecefinishi_get_check_sum(mxArray *plhs[]);
          sf_c36_juecefinishi_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3209800707U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(415435611U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(324213402U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(930168944U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_juecefinishi_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "dnjcux2HtDkcXj2GNNYmR") == 0) {
          extern mxArray *sf_c1_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c1_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "X3o7K04ps0UTrhYQV4213G") == 0) {
          extern mxArray *sf_c2_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c2_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "yPhoOvbzmzylB8UU4qaPdC") == 0) {
          extern mxArray *sf_c3_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c3_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "9c5lpDNKZfXuAOa9X3CMLC") == 0) {
          extern mxArray *sf_c4_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c4_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "D8e6dc8JE3SMrx3pC3f1xE") == 0) {
          extern mxArray *sf_c5_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c5_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "jYNQoJBhJ3v59prTwggRTE") == 0) {
          extern mxArray *sf_c6_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c6_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "jrTiZgNvpYFzjTQqwEYeTB") == 0) {
          extern mxArray *sf_c7_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c7_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "efrGqanKbEGZIvjyJeqJSD") == 0) {
          extern mxArray *sf_c8_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c8_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "lP9ho1wZAOTpfzdP2VUVpC") == 0) {
          extern mxArray *sf_c9_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c9_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "2WHliWTV3J2sF7rOmOUrKC") == 0) {
          extern mxArray *sf_c10_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c10_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "78ihLEWLwlwuyGsKYYWbPH") == 0) {
          extern mxArray *sf_c11_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c11_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "XqiSPAhrcfxp7Mc0QBBEIG") == 0) {
          extern mxArray *sf_c12_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c12_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "dNnAvhKcUuHkrF2nvwfVsB") == 0) {
          extern mxArray *sf_c13_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c13_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "R5gfedjztjMX5njitysMfG") == 0) {
          extern mxArray *sf_c14_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c14_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "h1LMKeHpGsLAR3lf8qbkhF") == 0) {
          extern mxArray *sf_c15_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c15_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "AYXjCjEETRuuLKaSyMl9sD") == 0) {
          extern mxArray *sf_c16_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c16_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "jZCFsUgmyO7mPNZvRNNX7F") == 0) {
          extern mxArray *sf_c17_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c17_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "DF1Tg8JxNa96Gb8Ozj86SH") == 0) {
          extern mxArray *sf_c18_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c18_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "LHuk9MuT7alnF2sIOz8oiG") == 0) {
          extern mxArray *sf_c19_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c19_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "PHXqvSusJ5GSFDXAwqq6KG") == 0) {
          extern mxArray *sf_c20_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c20_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 25:
      {
        if (strcmp(aiChksum, "6ZtrKNVYVtpMy6GaOOdN7B") == 0) {
          extern mxArray *sf_c25_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c25_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 26:
      {
        if (strcmp(aiChksum, "F8hlEwSBtMRMeCrjXES8sG") == 0) {
          extern mxArray *sf_c26_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c26_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 27:
      {
        if (strcmp(aiChksum, "PgxtuFYwzt7dD6aiwigmDF") == 0) {
          extern mxArray *sf_c27_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c27_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 28:
      {
        if (strcmp(aiChksum, "jYNQoJBhJ3v59prTwggRTE") == 0) {
          extern mxArray *sf_c28_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c28_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 29:
      {
        if (strcmp(aiChksum, "jrTiZgNvpYFzjTQqwEYeTB") == 0) {
          extern mxArray *sf_c29_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c29_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 30:
      {
        if (strcmp(aiChksum, "efrGqanKbEGZIvjyJeqJSD") == 0) {
          extern mxArray *sf_c30_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c30_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 31:
      {
        if (strcmp(aiChksum, "QHmQwa6n8FPPNFh7BWEwFB") == 0) {
          extern mxArray *sf_c31_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c31_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 32:
      {
        if (strcmp(aiChksum, "bffJZHDIxUTRA2fGfnhrDD") == 0) {
          extern mxArray *sf_c32_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c32_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 33:
      {
        if (strcmp(aiChksum, "IavqyeNs1Rw4LHBQ2gb9UF") == 0) {
          extern mxArray *sf_c33_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c33_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 34:
      {
        if (strcmp(aiChksum, "P07AAVHalmsrSFxwTlGR6D") == 0) {
          extern mxArray *sf_c34_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c34_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 35:
      {
        if (strcmp(aiChksum, "kFNn8RCEBIrg1lJRxnn1lH") == 0) {
          extern mxArray *sf_c35_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c35_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 36:
      {
        if (strcmp(aiChksum, "BXw64zdS5phERUIOUdu6bE") == 0) {
          extern mxArray *sf_c36_juecefinishi_get_autoinheritance_info(void);
          plhs[0] = sf_c36_juecefinishi_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_juecefinishi_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_juecefinishi_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_juecefinishi_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_juecefinishi_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_juecefinishi_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_juecefinishi_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_juecefinishi_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_juecefinishi_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_juecefinishi_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_juecefinishi_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 25:
      {
        extern const mxArray
          *sf_c25_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c25_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray
          *sf_c26_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 27:
      {
        extern const mxArray
          *sf_c27_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c27_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 28:
      {
        extern const mxArray
          *sf_c28_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c28_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 29:
      {
        extern const mxArray
          *sf_c29_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c29_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 30:
      {
        extern const mxArray
          *sf_c30_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c30_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray
          *sf_c31_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 32:
      {
        extern const mxArray
          *sf_c32_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c32_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 33:
      {
        extern const mxArray
          *sf_c33_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c33_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 34:
      {
        extern const mxArray
          *sf_c34_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c34_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 35:
      {
        extern const mxArray
          *sf_c35_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c35_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray
          *sf_c36_juecefinishi_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_juecefinishi_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_juecefinishi_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "ehPuPaJUcArLefOWNyPVcF") == 0) {
          extern mxArray *sf_c1_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c1_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "dCnvrAF3pL9Y05ThSzFos") == 0) {
          extern mxArray *sf_c2_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c2_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "1jvycT4OR5mbZBKx26296F") == 0) {
          extern mxArray *sf_c3_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c3_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "6TZ3yCnaCmpi6Flj5ofILC") == 0) {
          extern mxArray *sf_c4_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c4_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "w18x3erIQvCgw7naKQ2Mr") == 0) {
          extern mxArray *sf_c5_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c5_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "Y1mfSptqILTFQlF8wESgNF") == 0) {
          extern mxArray *sf_c6_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c6_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "qYThxaDHh0koSRi268873B") == 0) {
          extern mxArray *sf_c7_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c7_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "83y7zNqcVWVEZgPnFuvcQH") == 0) {
          extern mxArray *sf_c8_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c8_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "kOJO4rbc4ldGkFfRmjwFZB") == 0) {
          extern mxArray *sf_c9_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c9_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "ZGRBvfAYhE6IJpxbYZjOGB") == 0) {
          extern mxArray *sf_c10_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c10_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Ww101FZDXzvmkBlIdW6hvF") == 0) {
          extern mxArray *sf_c11_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c11_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "qh6uUVWKVp7SB2adxZMCyC") == 0) {
          extern mxArray *sf_c12_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c12_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "EXr4ZTrVvMtxeGSgNSAV7F") == 0) {
          extern mxArray *sf_c13_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c13_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "5z4xHI7ENZaKwcTayJghTE") == 0) {
          extern mxArray *sf_c14_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c14_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "8kclrmTsWS2Wxp5t7CXHAB") == 0) {
          extern mxArray *sf_c15_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c15_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "OrA0losDDo6chpAJ1rtHLE") == 0) {
          extern mxArray *sf_c16_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c16_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "4slKUJnAiFGNC70qa4eUrH") == 0) {
          extern mxArray *sf_c17_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c17_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "TMBcwITZDmEyW5l3A97h0F") == 0) {
          extern mxArray *sf_c18_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c18_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "SGiUJpZMjrJqYLRN0EYNJC") == 0) {
          extern mxArray *sf_c19_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c19_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "zh5OEiLthX4KRmuhK1N2C") == 0) {
          extern mxArray *sf_c20_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c20_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "G3SHjicokPj7Yo9Hbiy79F") == 0) {
          extern mxArray *sf_c25_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c25_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "PevAcoCPoQY0Nt9PUEw32F") == 0) {
          extern mxArray *sf_c26_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c26_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "eE59b0rPs252phaYrP9K8") == 0) {
          extern mxArray *sf_c27_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c27_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "Y1mfSptqILTFQlF8wESgNF") == 0) {
          extern mxArray *sf_c28_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c28_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "qYThxaDHh0koSRi268873B") == 0) {
          extern mxArray *sf_c29_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c29_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "83y7zNqcVWVEZgPnFuvcQH") == 0) {
          extern mxArray *sf_c30_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c30_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "tnPaw0NQn2HNMG9yJ7CkFH") == 0) {
          extern mxArray *sf_c31_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c31_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "gedevDeQUlOd3SQL010MNC") == 0) {
          extern mxArray *sf_c32_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c32_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 33:
      {
        if (strcmp(tpChksum, "D4djfdqoZDInbYlxR78t1B") == 0) {
          extern mxArray *sf_c33_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c33_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 34:
      {
        if (strcmp(tpChksum, "3VZwEK3OLgpDOcuW9okD1B") == 0) {
          extern mxArray *sf_c34_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c34_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "defwvx6BZYJMMTLEslQiAB") == 0) {
          extern mxArray *sf_c35_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c35_juecefinishi_third_party_uses_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "UFBp6O7GFKMca2bqk8S07C") == 0) {
          extern mxArray *sf_c36_juecefinishi_third_party_uses_info(void);
          plhs[0] = sf_c36_juecefinishi_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_juecefinishi_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "ehPuPaJUcArLefOWNyPVcF") == 0) {
          extern mxArray *sf_c1_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "dCnvrAF3pL9Y05ThSzFos") == 0) {
          extern mxArray *sf_c2_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "1jvycT4OR5mbZBKx26296F") == 0) {
          extern mxArray *sf_c3_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "6TZ3yCnaCmpi6Flj5ofILC") == 0) {
          extern mxArray *sf_c4_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "w18x3erIQvCgw7naKQ2Mr") == 0) {
          extern mxArray *sf_c5_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "Y1mfSptqILTFQlF8wESgNF") == 0) {
          extern mxArray *sf_c6_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "qYThxaDHh0koSRi268873B") == 0) {
          extern mxArray *sf_c7_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "83y7zNqcVWVEZgPnFuvcQH") == 0) {
          extern mxArray *sf_c8_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "kOJO4rbc4ldGkFfRmjwFZB") == 0) {
          extern mxArray *sf_c9_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "ZGRBvfAYhE6IJpxbYZjOGB") == 0) {
          extern mxArray *sf_c10_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "Ww101FZDXzvmkBlIdW6hvF") == 0) {
          extern mxArray *sf_c11_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "qh6uUVWKVp7SB2adxZMCyC") == 0) {
          extern mxArray *sf_c12_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "EXr4ZTrVvMtxeGSgNSAV7F") == 0) {
          extern mxArray *sf_c13_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "5z4xHI7ENZaKwcTayJghTE") == 0) {
          extern mxArray *sf_c14_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "8kclrmTsWS2Wxp5t7CXHAB") == 0) {
          extern mxArray *sf_c15_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "OrA0losDDo6chpAJ1rtHLE") == 0) {
          extern mxArray *sf_c16_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "4slKUJnAiFGNC70qa4eUrH") == 0) {
          extern mxArray *sf_c17_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "TMBcwITZDmEyW5l3A97h0F") == 0) {
          extern mxArray *sf_c18_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c18_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "SGiUJpZMjrJqYLRN0EYNJC") == 0) {
          extern mxArray *sf_c19_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c19_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "zh5OEiLthX4KRmuhK1N2C") == 0) {
          extern mxArray *sf_c20_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "G3SHjicokPj7Yo9Hbiy79F") == 0) {
          extern mxArray *sf_c25_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c25_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "PevAcoCPoQY0Nt9PUEw32F") == 0) {
          extern mxArray *sf_c26_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c26_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "eE59b0rPs252phaYrP9K8") == 0) {
          extern mxArray *sf_c27_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c27_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 28:
      {
        if (strcmp(tpChksum, "Y1mfSptqILTFQlF8wESgNF") == 0) {
          extern mxArray *sf_c28_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c28_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 29:
      {
        if (strcmp(tpChksum, "qYThxaDHh0koSRi268873B") == 0) {
          extern mxArray *sf_c29_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c29_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 30:
      {
        if (strcmp(tpChksum, "83y7zNqcVWVEZgPnFuvcQH") == 0) {
          extern mxArray *sf_c30_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c30_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "tnPaw0NQn2HNMG9yJ7CkFH") == 0) {
          extern mxArray *sf_c31_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "gedevDeQUlOd3SQL010MNC") == 0) {
          extern mxArray *sf_c32_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c32_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 33:
      {
        if (strcmp(tpChksum, "D4djfdqoZDInbYlxR78t1B") == 0) {
          extern mxArray *sf_c33_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c33_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 34:
      {
        if (strcmp(tpChksum, "3VZwEK3OLgpDOcuW9okD1B") == 0) {
          extern mxArray *sf_c34_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c34_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "defwvx6BZYJMMTLEslQiAB") == 0) {
          extern mxArray *sf_c35_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c35_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "UFBp6O7GFKMca2bqk8S07C") == 0) {
          extern mxArray *sf_c36_juecefinishi_updateBuildInfo_args_info(void);
          plhs[0] = sf_c36_juecefinishi_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void juecefinishi_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _juecefinishiMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "juecefinishi","sfun",0,32,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _juecefinishiMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_juecefinishiMachineNumber_,
    0);
}

void juecefinishi_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_juecefinishi_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("juecefinishi",
      "juecefinishi");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_juecefinishi_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
