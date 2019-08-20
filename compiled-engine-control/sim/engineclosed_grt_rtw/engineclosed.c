/*
 * engineclosed.c
 *
 * Code generation for model "engineclosed".
 *
 * Model version              : 1.132
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Thu Jun  6 13:30:26 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "engineclosed.h"
#include "engineclosed_private.h"

/* Block signals (default storage) */
B_engineclosed_T engineclosed_B;

/* Continuous states */
X_engineclosed_T engineclosed_X;

/* Block states (default storage) */
DW_engineclosed_T engineclosed_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_engineclosed_T engineclosed_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_engineclosed_T engineclosed_Y;

/* Real-time model */
RT_MODEL_engineclosed_T engineclosed_M_;
RT_MODEL_engineclosed_T *const engineclosed_M = &engineclosed_M_;

/* Forward declaration for local functions */
static void engineclosed_emxInit_real_T(emxArray_real_T_engineclosed_T
  **pEmxArray, int32_T numDimensions);
static int8_T engineclosed_filedata(void);
static int8_T engineclosed_cfopen(const char * cfilename, const char
  * cpermission);
static FILE * engineclosed_getFileStar(real_T fileID);
static void engine_emxEnsureCapacity_real_T(emxArray_real_T_engineclosed_T
  *emxArray, int32_T oldNumel);
static void engineclosed_emxFree_real_T(emxArray_real_T_engineclosed_T
  **pEmxArray);
static void engineclosed_fread(real_T fileID, emxArray_real_T_engineclosed_T *A);
static void engineclosed_fclose(real_T fileID);
static int8_T engineclosed_filedata_d(void);
static int8_T engineclosed_cfopen_c(const char * cfilename, const char
  * cpermission);
static FILE * engineclosed_getFileStar_h(real_T fileID);
static void engineclosed_fread_l(real_T fileID, emxArray_real_T_engineclosed_T
  *A);
static void engineclosed_fclose_a(real_T fileID);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  engineclosed_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

static void engineclosed_emxInit_real_T(emxArray_real_T_engineclosed_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_engineclosed_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_engineclosed_T *)malloc(sizeof
    (emxArray_real_T_engineclosed_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/* Function for MATLAB Function: '<S3>/MATLAB Function' */
static int8_T engineclosed_filedata(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (engineclosed_DW.eml_openfiles[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S3>/MATLAB Function' */
static int8_T engineclosed_cfopen(const char * cfilename, const char
  * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = engineclosed_filedata();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      engineclosed_DW.eml_openfiles[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<S3>/MATLAB Function' */
static FILE * engineclosed_getFileStar(real_T fileID)
{
  FILE * filestar;
  int8_T fileid;
  boolean_T p;
  fileid = (int8_T)rt_roundd_snf(fileID);
  if ((fileid < 0) || (fileID != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    filestar = engineclosed_DW.eml_openfiles[fileid - 3];
  } else if (fileid == 0) {
    filestar = stdin;
  } else if (fileid == 1) {
    filestar = stdout;
  } else if (fileid == 2) {
    filestar = stderr;
  } else {
    filestar = NULL;
  }

  p = ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0));
  if (!p) {
    filestar = NULL;
  }

  return filestar;
}

static void engine_emxEnsureCapacity_real_T(emxArray_real_T_engineclosed_T
  *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void engineclosed_emxFree_real_T(emxArray_real_T_engineclosed_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_engineclosed_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_engineclosed_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S3>/MATLAB Function' */
static void engineclosed_fread(real_T fileID, emxArray_real_T_engineclosed_T *A)
{
  size_t nBytes;
  FILE * filestar;
  emxArray_real_T_engineclosed_T *b_A;
  int32_T bytesOut;
  int32_T numRead;
  size_t numReadSizeT;
  nBytes = sizeof(real_T);
  filestar = engineclosed_getFileStar(fileID);
  if (filestar == NULL) {
    A->size[0] = 0;
  } else {
    engineclosed_emxInit_real_T(&b_A, 1);
    numRead = b_A->size[0];
    b_A->size[0] = 10000;
    engine_emxEnsureCapacity_real_T(b_A, numRead);
    bytesOut = 0;
    numRead = 1;
    while ((bytesOut < 10000) && (numRead > 0)) {
      numReadSizeT = fread(&b_A->data[bytesOut], nBytes, 10000 - bytesOut,
                           filestar);
      numRead = (int32_T)numReadSizeT;
      bytesOut += (int32_T)numReadSizeT;
    }

    for (numRead = bytesOut; numRead + 1 < 10001; numRead++) {
      b_A->data[numRead] = 0.0;
    }

    numRead = A->size[0];
    A->size[0] = 10000;
    engine_emxEnsureCapacity_real_T(A, numRead);
    for (numRead = 0; numRead < 10000; numRead++) {
      A->data[numRead] = b_A->data[numRead];
    }

    if (bytesOut < 10000) {
      if (1 > bytesOut) {
        bytesOut = 0;
      }

      numRead = A->size[0];
      A->size[0] = bytesOut;
      engine_emxEnsureCapacity_real_T(A, numRead);
      for (numRead = 0; numRead < bytesOut; numRead++) {
        A->data[numRead] = b_A->data[numRead];
      }
    }

    engineclosed_emxFree_real_T(&b_A);
  }
}

/* Function for MATLAB Function: '<S3>/MATLAB Function' */
static void engineclosed_fclose(real_T fileID)
{
  int8_T fileid;
  int32_T cst;
  boolean_T condition;
  FILE * f;
  int8_T b_fileid;
  fileid = (int8_T)rt_roundd_snf(fileID);
  if ((fileid < 0) || (fileID != fileid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = engineclosed_DW.eml_openfiles[b_fileid - 3];
  } else if (b_fileid == 0) {
    f = stdin;
  } else if (b_fileid == 1) {
    f = stdout;
  } else if (b_fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  condition = ((f != NULL) && (fileid >= 3));
  if (condition) {
    cst = fclose(f);
    if (cst == 0) {
      engineclosed_DW.eml_openfiles[fileid - 3] = NULL;
    }
  }
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static int8_T engineclosed_filedata_d(void)
{
  int8_T f;
  int32_T k;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (engineclosed_DW.eml_openfiles_a[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static int8_T engineclosed_cfopen_c(const char * cfilename, const char
  * cpermission)
{
  int8_T fileid;
  FILE * filestar;
  int8_T j;
  int32_T tmp;
  fileid = -1;
  j = engineclosed_filedata_d();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      engineclosed_DW.eml_openfiles_a[j - 1] = filestar;
      tmp = j + 2;
      if (tmp > 127) {
        tmp = 127;
      }

      fileid = (int8_T)tmp;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static FILE * engineclosed_getFileStar_h(real_T fileID)
{
  FILE * filestar;
  int8_T fileid;
  boolean_T p;
  fileid = (int8_T)rt_roundd_snf(fileID);
  if ((fileid < 0) || (fileID != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    filestar = engineclosed_DW.eml_openfiles_a[fileid - 3];
  } else if (fileid == 0) {
    filestar = stdin;
  } else if (fileid == 1) {
    filestar = stdout;
  } else if (fileid == 2) {
    filestar = stderr;
  } else {
    filestar = NULL;
  }

  p = ((fileID != 0.0) && (fileID != 1.0) && (fileID != 2.0));
  if (!p) {
    filestar = NULL;
  }

  return filestar;
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static void engineclosed_fread_l(real_T fileID, emxArray_real_T_engineclosed_T
  *A)
{
  size_t nBytes;
  FILE * filestar;
  emxArray_real_T_engineclosed_T *b_A;
  int32_T bytesOut;
  int32_T numRead;
  size_t numReadSizeT;
  nBytes = sizeof(real_T);
  filestar = engineclosed_getFileStar_h(fileID);
  if (filestar == NULL) {
    A->size[0] = 0;
  } else {
    engineclosed_emxInit_real_T(&b_A, 1);
    numRead = b_A->size[0];
    b_A->size[0] = 10000;
    engine_emxEnsureCapacity_real_T(b_A, numRead);
    bytesOut = 0;
    numRead = 1;
    while ((bytesOut < 10000) && (numRead > 0)) {
      numReadSizeT = fread(&b_A->data[bytesOut], nBytes, 10000 - bytesOut,
                           filestar);
      numRead = (int32_T)numReadSizeT;
      bytesOut += (int32_T)numReadSizeT;
    }

    for (numRead = bytesOut; numRead + 1 < 10001; numRead++) {
      b_A->data[numRead] = 0.0;
    }

    numRead = A->size[0];
    A->size[0] = 10000;
    engine_emxEnsureCapacity_real_T(A, numRead);
    for (numRead = 0; numRead < 10000; numRead++) {
      A->data[numRead] = b_A->data[numRead];
    }

    if (bytesOut < 10000) {
      if (1 > bytesOut) {
        bytesOut = 0;
      }

      numRead = A->size[0];
      A->size[0] = bytesOut;
      engine_emxEnsureCapacity_real_T(A, numRead);
      for (numRead = 0; numRead < bytesOut; numRead++) {
        A->data[numRead] = b_A->data[numRead];
      }
    }

    engineclosed_emxFree_real_T(&b_A);
  }
}

/* Function for MATLAB Function: '<S4>/MATLAB Function' */
static void engineclosed_fclose_a(real_T fileID)
{
  int8_T fileid;
  int32_T cst;
  boolean_T condition;
  FILE * f;
  int8_T b_fileid;
  fileid = (int8_T)rt_roundd_snf(fileID);
  if ((fileid < 0) || (fileID != fileid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = engineclosed_DW.eml_openfiles_a[b_fileid - 3];
  } else if (b_fileid == 0) {
    f = stdin;
  } else if (b_fileid == 1) {
    f = stdout;
  } else if (b_fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  condition = ((f != NULL) && (fileid >= 3));
  if (condition) {
    cst = fclose(f);
    if (cst == 0) {
      engineclosed_DW.eml_openfiles_a[fileid - 3] = NULL;
    }
  }
}

/* Model output function */
void engineclosed_output(void)
{
  boolean_T resetSolver;
  boolean_T stateChanged;
  emxArray_real_T_engineclosed_T *yv;
  int8_T fileid;
  boolean_T zcEvent;
  ZCEventType zcEvent_0;
  uint32_T elapseT_H;
  uint32_T prevT_idx_0;
  uint32_T elapseTime_idx_0;
  uint32_T prevT_idx_1;
  real_T u1;
  real_T u2;
  real_T u;
  if (rtmIsMajorTimeStep(engineclosed_M)) {
    /* set solver stop time */
    if (!(engineclosed_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&engineclosed_M->solverInfo,
                            ((engineclosed_M->Timing.clockTickH0 + 1) *
        engineclosed_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&engineclosed_M->solverInfo,
                            ((engineclosed_M->Timing.clockTick0 + 1) *
        engineclosed_M->Timing.stepSize0 + engineclosed_M->Timing.clockTickH0 *
        engineclosed_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(engineclosed_M)) {
    engineclosed_M->Timing.t[0] = rtsiGetT(&engineclosed_M->solverInfo);
  }

  /* Integrator: '<S4>/w = T//J w0 = 209 rad//s' */
  engineclosed_B.wTJw0209rads = engineclosed_X.wTJw0209rads_CSTATE;

  /* Outport: '<Root>/crank speed (rad//sec)' */
  engineclosed_Y.crankspeedradsec = engineclosed_B.wTJw0209rads;

  /* Gain: '<Root>/rad//s to rpm' */
  engineclosed_B.EngineSpeed = engineclosed_P.radstorpm_Gain *
    engineclosed_B.wTJw0209rads;
  if (rtmIsMajorTimeStep(engineclosed_M)) {
  }

  /* Step: '<S6>/Step' */
  u1 = engineclosed_M->Timing.t[0];
  if (u1 < engineclosed_P.Step_Time) {
    engineclosed_B.Step = engineclosed_P.Step_Y0;
  } else {
    engineclosed_B.Step = engineclosed_P.Step_YFinal;
  }

  /* End of Step: '<S6>/Step' */

  /* Step: '<S6>/Step1' */
  u1 = engineclosed_M->Timing.t[0];
  if (u1 < engineclosed_P.Step1_Time) {
    engineclosed_B.Step1 = engineclosed_P.Step1_Y0;
  } else {
    engineclosed_B.Step1 = engineclosed_P.Step1_YFinal;
  }

  /* End of Step: '<S6>/Step1' */

  /* Sum: '<S6>/Sum1' */
  engineclosed_B.LoadTorque = engineclosed_B.Step + engineclosed_B.Step1;

  /* Step: '<Root>/Speed Setpoint' */
  u1 = engineclosed_M->Timing.t[0];
  if (u1 < engineclosed_P.SpeedSetpoint_Time) {
    engineclosed_B.SpeedSetpoint = engineclosed_P.SpeedSetpoint_Y0;
  } else {
    engineclosed_B.SpeedSetpoint = engineclosed_P.SpeedSetpoint_YFinal;
  }

  /* End of Step: '<Root>/Speed Setpoint' */

  /* RelationalOperator: '<S109>/Relational Operator' incorporates:
   *  Constant: '<S109>/Constant'
   */
  engineclosed_B.RelationalOperator = (engineclosed_X.GetCrankAngleIC0_CSTATE >=
    engineclosed_P.Constant_Value_g);
  engineclosed_emxInit_real_T(&yv, 1);
  if (rtmIsMajorTimeStep(engineclosed_M)) {
    /* Outputs for Triggered SubSystem: '<Root>/Controller' incorporates:
     *  TriggerPort: '<S3>/Trigger'
     */
    /* Outputs for Triggered SubSystem: '<S7>/positive edge to dual edge conversion' incorporates:
     *  TriggerPort: '<S110>/Trigger'
     */
    if (rtmIsMajorTimeStep(engineclosed_M)) {
      zcEvent = (engineclosed_B.RelationalOperator &&
                 (engineclosed_PrevZCX.positiveedgetodualedgeconversio !=
                  POS_ZCSIG));
      if (zcEvent) {
        /* UnitDelay: '<S110>/Unit Delay' */
        engineclosed_B.UnitDelay = engineclosed_DW.UnitDelay_DSTATE;

        /* Gain: '<S110>/Gain' */
        engineclosed_B.Gain = engineclosed_P.Gain_Gain *
          engineclosed_B.UnitDelay;

        /* Update for UnitDelay: '<S110>/Unit Delay' */
        engineclosed_DW.UnitDelay_DSTATE = engineclosed_B.Gain;
      }

      engineclosed_PrevZCX.positiveedgetodualedgeconversio =
        engineclosed_B.RelationalOperator;
      zcEvent_0 = rt_ZCFcn(ANY_ZERO_CROSSING,
                           &engineclosed_PrevZCX.Controller_Trig_ZCE,
                           (engineclosed_B.UnitDelay));
      if (zcEvent_0 != NO_ZCEVENT) {
        prevT_idx_0 = engineclosed_DW.Controller_PREV_T[0];
        prevT_idx_1 = engineclosed_DW.Controller_PREV_T[1];
        elapseTime_idx_0 = engineclosed_M->Timing.clockTick1 - prevT_idx_0;
        elapseT_H = engineclosed_M->Timing.clockTickH1 - prevT_idx_1;
        if (prevT_idx_0 > engineclosed_M->Timing.clockTick1) {
          elapseT_H--;
        }

        prevT_idx_0 = engineclosed_M->Timing.clockTick1;
        prevT_idx_1 = engineclosed_M->Timing.clockTickH1;
        engineclosed_DW.Controller_ELAPS_T[0] = elapseTime_idx_0;
        engineclosed_DW.Controller_PREV_T[0] = prevT_idx_0;
        engineclosed_DW.Controller_ELAPS_T[1] = elapseT_H;
        engineclosed_DW.Controller_PREV_T[1] = prevT_idx_1;

        /* MATLAB Function: '<S3>/MATLAB Function' */
        /* MATLAB Function 'Controller/MATLAB Function': '<S8>:1' */
        /* '<S8>:1:2' */
        fileid = engineclosed_cfopen("binn.bin", "rb");

        /* '<S8>:1:3' */
        engineclosed_fread((real_T)fileid, yv);

        /* '<S8>:1:4' */
        /* '<S8>:1:5' */
        /* '<S8>:1:6' */
        engineclosed_fclose((real_T)fileid);
        engineclosed_B.kp = yv->data[0];
        engineclosed_B.ki = yv->data[1];

        /* ToFile: '<S3>/To File1' */
        {
          if (!(++engineclosed_DW.ToFile1_IWORK_m.Decimation % 1) &&
              (engineclosed_DW.ToFile1_IWORK_m.Count * (1 + 1)) + 1 < 100000000 )
          {
            FILE *fp = (FILE *) engineclosed_DW.ToFile1_PWORK_f.FilePtr;
            if (fp != (NULL)) {
              real_T u[1 + 1];
              engineclosed_DW.ToFile1_IWORK_m.Decimation = 0;
              u[0] = engineclosed_M->Timing.t[1];
              u[1] = engineclosed_B.kp;
              if (fwrite(u, sizeof(real_T), 1 + 1, fp) != 1 + 1) {
                rtmSetErrorStatus(engineclosed_M,
                                  "Error writing to MAT-file pout.mat");
                return;
              }

              if (((++engineclosed_DW.ToFile1_IWORK_m.Count) * (1 + 1))+1 >=
                  100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file pout.mat.\n");
              }
            }
          }
        }

        /* Gain: '<S3>/rpm to rad//s' */
        engineclosed_B.rpmtorads = engineclosed_P.rpmtorads_Gain *
          engineclosed_B.SpeedSetpoint;

        /* Sum: '<S3>/Sum' */
        engineclosed_B.Sum_n = engineclosed_B.rpmtorads -
          engineclosed_B.wTJw0209rads;

        /* Product: '<S80>/PProd Out' */
        engineclosed_B.PProdOut = engineclosed_B.Sum_n * engineclosed_B.kp;

        /* DiscreteIntegrator: '<S64>/Integrator' */
        engineclosed_B.Integrator = engineclosed_DW.Integrator_DSTATE;

        /* Sum: '<S93>/Sum' */
        engineclosed_B.Sum_f = engineclosed_B.PProdOut +
          engineclosed_B.Integrator;

        /* Gain: '<S37>/ZeroGain' */
        engineclosed_B.ZeroGain = engineclosed_P.ZeroGain_Gain *
          engineclosed_B.Sum_f;

        /* DeadZone: '<S37>/DeadZone' */
        if (engineclosed_B.Sum_f >
            engineclosed_P.PIDController_UpperSaturationLi) {
          engineclosed_B.DeadZone = engineclosed_B.Sum_f -
            engineclosed_P.PIDController_UpperSaturationLi;
        } else if (engineclosed_B.Sum_f >=
                   engineclosed_P.PIDController_LowerSaturationLi) {
          engineclosed_B.DeadZone = 0.0;
        } else {
          engineclosed_B.DeadZone = engineclosed_B.Sum_f -
            engineclosed_P.PIDController_LowerSaturationLi;
        }

        /* End of DeadZone: '<S37>/DeadZone' */

        /* RelationalOperator: '<S37>/NotEqual' */
        engineclosed_B.NotEqual = (engineclosed_B.ZeroGain !=
          engineclosed_B.DeadZone);

        /* Signum: '<S37>/SignPreSat' */
        u = engineclosed_B.DeadZone;
        if (u < 0.0) {
          engineclosed_B.SignPreSat = -1.0;
        } else if (u > 0.0) {
          engineclosed_B.SignPreSat = 1.0;
        } else if (u == 0.0) {
          engineclosed_B.SignPreSat = 0.0;
        } else {
          engineclosed_B.SignPreSat = (rtNaN);
        }

        /* End of Signum: '<S37>/SignPreSat' */

        /* DataTypeConversion: '<S37>/DataTypeConv1' */
        u1 = floor(engineclosed_B.SignPreSat);
        if (rtIsNaN(u1) || rtIsInf(u1)) {
          u1 = 0.0;
        } else {
          u1 = fmod(u1, 256.0);
        }

        engineclosed_B.DataTypeConv1 = (int8_T)(u1 < 0.0 ? (int32_T)(int8_T)
          -(int8_T)(uint8_T)-u1 : (int32_T)(int8_T)(uint8_T)u1);

        /* End of DataTypeConversion: '<S37>/DataTypeConv1' */

        /* Product: '<S53>/IProd Out' */
        engineclosed_B.IProdOut = engineclosed_B.Sum_n * engineclosed_B.ki;

        /* Signum: '<S37>/SignPreIntegrator' */
        u = engineclosed_B.IProdOut;
        if (u < 0.0) {
          engineclosed_B.SignPreIntegrator = -1.0;
        } else if (u > 0.0) {
          engineclosed_B.SignPreIntegrator = 1.0;
        } else if (u == 0.0) {
          engineclosed_B.SignPreIntegrator = 0.0;
        } else {
          engineclosed_B.SignPreIntegrator = (rtNaN);
        }

        /* End of Signum: '<S37>/SignPreIntegrator' */

        /* DataTypeConversion: '<S37>/DataTypeConv2' */
        u1 = floor(engineclosed_B.SignPreIntegrator);
        if (rtIsNaN(u1) || rtIsInf(u1)) {
          u1 = 0.0;
        } else {
          u1 = fmod(u1, 256.0);
        }

        engineclosed_B.DataTypeConv2 = (int8_T)(u1 < 0.0 ? (int32_T)(int8_T)
          -(int8_T)(uint8_T)-u1 : (int32_T)(int8_T)(uint8_T)u1);

        /* End of DataTypeConversion: '<S37>/DataTypeConv2' */

        /* RelationalOperator: '<S37>/Equal1' */
        engineclosed_B.Equal1 = (engineclosed_B.DataTypeConv1 ==
          engineclosed_B.DataTypeConv2);

        /* Logic: '<S37>/AND3' */
        engineclosed_B.AND3 = (engineclosed_B.NotEqual && engineclosed_B.Equal1);

        /* Switch: '<S37>/Switch' incorporates:
         *  Constant: '<S37>/Constant1'
         */
        if (engineclosed_B.AND3) {
          engineclosed_B.Switch_k = engineclosed_P.Constant1_Value;
        } else {
          engineclosed_B.Switch_k = engineclosed_B.IProdOut;
        }

        /* End of Switch: '<S37>/Switch' */

        /* Saturate: '<S85>/Saturation' */
        u = engineclosed_B.Sum_f;
        u1 = engineclosed_P.PIDController_LowerSaturationLi;
        u2 = engineclosed_P.PIDController_UpperSaturationLi;
        if (u > u2) {
          engineclosed_B.ThrottleAngle = u2;
        } else if (u < u1) {
          engineclosed_B.ThrottleAngle = u1;
        } else {
          engineclosed_B.ThrottleAngle = u;
        }

        /* End of Saturate: '<S85>/Saturation' */

        /* Update for DiscreteIntegrator: '<S64>/Integrator' */
        engineclosed_DW.Integrator_DSTATE += engineclosed_P.Integrator_gainval *
          (real_T)engineclosed_DW.Controller_ELAPS_T[0] *
          engineclosed_B.Switch_k;
      }
    }

    /* End of Outputs for SubSystem: '<S7>/positive edge to dual edge conversion' */
    /* End of Outputs for SubSystem: '<Root>/Controller' */
    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo File1Inport1' */
    engineclosed_B.SimulationInputs[0] = engineclosed_B.EngineSpeed;
    engineclosed_B.SimulationInputs[1] = engineclosed_B.SpeedSetpoint;

    /* ToFile: '<Root>/To File1' */
    {
      if (!(++engineclosed_DW.ToFile1_IWORK.Decimation % 1) &&
          (engineclosed_DW.ToFile1_IWORK.Count * (2 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) engineclosed_DW.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2 + 1];
          engineclosed_DW.ToFile1_IWORK.Decimation = 0;
          u[0] = engineclosed_M->Timing.t[1];
          u[1] = engineclosed_B.SimulationInputs[0];
          u[2] = engineclosed_B.SimulationInputs[1];
          if (fwrite(u, sizeof(real_T), 2 + 1, fp) != 2 + 1) {
            rtmSetErrorStatus(engineclosed_M,
                              "Error writing to MAT-file rpms.mat");
            return;
          }

          if (((++engineclosed_DW.ToFile1_IWORK.Count) * (2 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file rpms.mat.\n");
          }
        }
      }
    }

    /* Outputs for Triggered SubSystem: '<Root>/Compression' incorporates:
     *  TriggerPort: '<S2>/Trigger'
     */
    if (rtmIsMajorTimeStep(engineclosed_M)) {
      zcEvent_0 = rt_ZCFcn(ANY_ZERO_CROSSING,
                           &engineclosed_PrevZCX.Compression_Trig_ZCE,
                           (engineclosed_B.UnitDelay));
      if (zcEvent_0 != NO_ZCEVENT) {
        engineclosed_B.Trigger = (real_T)zcEvent_0;

        /* InitialCondition: '<S2>/Init' */
        if (engineclosed_DW.Init_FirstOutputTime) {
          engineclosed_DW.Init_FirstOutputTime = false;
          engineclosed_B.Init = engineclosed_P.Init_Value;
        } else {
          engineclosed_B.Init = engineclosed_X.Intake_CSTATE;
        }

        /* End of InitialCondition: '<S2>/Init' */

        /* UnitDelay: '<S2>/Unit Delay' */
        engineclosed_B.UnitDelay_e = engineclosed_DW.UnitDelay_DSTATE_g;

        /* Update for UnitDelay: '<S2>/Unit Delay' */
        engineclosed_DW.UnitDelay_DSTATE_g = engineclosed_B.Init;
      }
    }

    /* End of Outputs for SubSystem: '<Root>/Compression' */

    /* Gain: '<S1>/Stoichiometric Fuel' */
    engineclosed_B.StoichiometricFuel = engineclosed_P.StoichiometricFuel_Gain *
      engineclosed_B.UnitDelay_e;
  }

  /* Fcn: '<S1>/Torque Gen' incorporates:
   *  Constant: '<S1>/Spark Advance (degrees BTDC)'
   */
  engineclosed_B.TorqueGen = ((((379.36 * engineclosed_B.UnitDelay_e + -181.3) +
    21.91 * engineclosed_B.UnitDelay_e / engineclosed_B.StoichiometricFuel) -
    0.85 * engineclosed_B.UnitDelay_e * engineclosed_B.UnitDelay_e /
    (engineclosed_B.StoichiometricFuel * engineclosed_B.StoichiometricFuel)) +
    0.26 * engineclosed_P.SparkAdvancedegreesBTDC_Value) - 0.0028 *
    engineclosed_P.SparkAdvancedegreesBTDC_Value *
    engineclosed_P.SparkAdvancedegreesBTDC_Value;

  /* Fcn: '<S1>/Torque Gen2' incorporates:
   *  Constant: '<S1>/Spark Advance (degrees BTDC)'
   */
  engineclosed_B.TorqueGen2 = (((0.027 * engineclosed_B.wTJw0209rads - 0.000107 *
    engineclosed_B.wTJw0209rads * engineclosed_B.wTJw0209rads) + 0.00048 *
    engineclosed_B.wTJw0209rads * engineclosed_P.SparkAdvancedegreesBTDC_Value)
    + 2.55 * engineclosed_P.SparkAdvancedegreesBTDC_Value *
    engineclosed_B.UnitDelay_e) - 0.05 *
    engineclosed_P.SparkAdvancedegreesBTDC_Value *
    engineclosed_P.SparkAdvancedegreesBTDC_Value * engineclosed_B.UnitDelay_e;

  /* Sum: '<S1>/Sum' */
  engineclosed_B.Sum = engineclosed_B.TorqueGen + engineclosed_B.TorqueGen2;
  if (rtmIsMajorTimeStep(engineclosed_M)) {
    /* MATLAB Function: '<S4>/MATLAB Function' */
    /* MATLAB Function 'Engine Dynamics/MATLAB Function': '<S106>:1' */
    /* '<S106>:1:2' */
    fileid = engineclosed_cfopen_c("binn.bin", "rb");

    /* '<S106>:1:3' */
    engineclosed_fread_l((real_T)fileid, yv);

    /* '<S106>:1:4' */
    /* '<S106>:1:5' */
    engineclosed_fclose_a((real_T)fileid);
    engineclosed_B.dJ = yv->data[2];
  }

  engineclosed_emxFree_real_T(&yv);

  /* Sum: '<S4>/Sum' */
  engineclosed_B.Sum_k = engineclosed_B.Sum - engineclosed_B.LoadTorque;

  /* Gain: '<S4>/Inverse Inertia, 1//J' */
  engineclosed_B.InverseInertia1J = engineclosed_P.InverseInertia1J_Gain *
    engineclosed_B.Sum_k;

  /* Product: '<S4>/Product' */
  engineclosed_B.Product = engineclosed_B.dJ * engineclosed_B.InverseInertia1J;

  /* Sum: '<S4>/Add' */
  engineclosed_B.Add = engineclosed_B.Product + engineclosed_B.InverseInertia1J;
  if (rtmIsMajorTimeStep(engineclosed_M)) {
    /* Saturate: '<S5>/0 <= theta <= 90' */
    u = engineclosed_B.ThrottleAngle;
    u1 = engineclosed_P.utheta90_LowerSat;
    u2 = engineclosed_P.utheta90_UpperSat;
    if (u > u2) {
      engineclosed_B.utheta90 = u2;
    } else if (u < u1) {
      engineclosed_B.utheta90 = u1;
    } else {
      engineclosed_B.utheta90 = u;
    }

    /* End of Saturate: '<S5>/0 <= theta <= 90' */
  }

  /* Integrator: '<S5>/Intake' */
  if (rtmIsMajorTimeStep(engineclosed_M)) {
    resetSolver = false;
    stateChanged = false;
    zcEvent_0 = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &engineclosed_PrevZCX.Intake_Reset_ZCE,
                         (engineclosed_B.Trigger));
    zcEvent = (zcEvent_0 != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent) {
      resetSolver = true;
      engineclosed_X.Intake_CSTATE = engineclosed_P.Intake_IC;
      stateChanged = true;
    }

    if (resetSolver) {
      rtsiSetBlockStateForSolverChangedAtMajorStep(&engineclosed_M->solverInfo,
        true);
      if (stateChanged) {
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&engineclosed_M->solverInfo, true);
      }
    }
  }

  engineclosed_B.Intake = engineclosed_X.Intake_CSTATE;

  /* End of Integrator: '<S5>/Intake' */

  /* Integrator: '<S107>/p0 = 0.543 bar' */
  engineclosed_B.p00543bar = engineclosed_X.p00543bar_CSTATE;

  /* Fcn: '<S107>/Pumping' */
  engineclosed_B.Pumping = ((0.08979 * engineclosed_B.p00543bar *
    engineclosed_B.wTJw0209rads + -0.366) - 0.0337 * engineclosed_B.wTJw0209rads
    * engineclosed_B.p00543bar * engineclosed_B.p00543bar) + 0.0001 *
    engineclosed_B.p00543bar * engineclosed_B.wTJw0209rads *
    engineclosed_B.wTJw0209rads;
  if (rtmIsMajorTimeStep(engineclosed_M)) {
    /* Fcn: '<S108>/f(theta)' */
    engineclosed_B.ftheta = ((2.821 - 0.05231 * engineclosed_B.utheta90) +
      0.10299 * engineclosed_B.utheta90 * engineclosed_B.utheta90) - 0.00063 *
      engineclosed_B.utheta90 * engineclosed_B.utheta90 *
      engineclosed_B.utheta90;
  }

  /* Product: '<S108>/Product1' incorporates:
   *  Constant: '<S5>/Atmospheric Pressure, Pa (bar)'
   */
  engineclosed_B.Product1 = engineclosed_B.p00543bar /
    engineclosed_P.AtmosphericPressurePabar_Value;

  /* Product: '<S108>/Product2' incorporates:
   *  Constant: '<S5>/Atmospheric Pressure, Pa (bar)'
   */
  engineclosed_B.Product2 = 1.0 / engineclosed_B.p00543bar *
    engineclosed_P.AtmosphericPressurePabar_Value;

  /* MinMax: '<S108>/MinMax' */
  u = engineclosed_B.Product1;
  u1 = engineclosed_B.Product2;
  if ((u < u1) || rtIsNaN(u1)) {
    u1 = u;
  }

  engineclosed_B.pratio = u1;

  /* End of MinMax: '<S108>/MinMax' */

  /* Switch: '<S108>/Switch' incorporates:
   *  Constant: '<S108>/Sonic Flow '
   */
  if (engineclosed_B.pratio >= engineclosed_P.Switch_Threshold) {
    /* Fcn: '<S108>/g(pratio)' */
    u1 = engineclosed_B.pratio - engineclosed_B.pratio * engineclosed_B.pratio;
    if (u1 < 0.0) {
      u1 = -sqrt(-u1);
    } else {
      u1 = sqrt(u1);
    }

    engineclosed_B.gpratio = 2.0 * u1;

    /* End of Fcn: '<S108>/g(pratio)' */
    engineclosed_B.Switch = engineclosed_B.gpratio;
  } else {
    engineclosed_B.Switch = engineclosed_P.SonicFlow_Value;
  }

  /* End of Switch: '<S108>/Switch' */

  /* Sum: '<S108>/Sum' incorporates:
   *  Constant: '<S5>/Atmospheric Pressure, Pa (bar)'
   */
  engineclosed_B.Sum_a = engineclosed_P.AtmosphericPressurePabar_Value -
    engineclosed_B.p00543bar;

  /* Signum: '<S108>/flow direction' */
  u = engineclosed_B.Sum_a;
  if (u < 0.0) {
    engineclosed_B.flowdirection = -1.0;
  } else if (u > 0.0) {
    engineclosed_B.flowdirection = 1.0;
  } else if (u == 0.0) {
    engineclosed_B.flowdirection = 0.0;
  } else {
    engineclosed_B.flowdirection = (rtNaN);
  }

  /* End of Signum: '<S108>/flow direction' */

  /* Product: '<S108>/Product' */
  engineclosed_B.Product_c = engineclosed_B.ftheta * engineclosed_B.Switch *
    engineclosed_B.flowdirection;

  /* Sum: '<S107>/Sum' */
  engineclosed_B.Sum_h = engineclosed_B.Product_c - engineclosed_B.Pumping;

  /* Gain: '<S107>/RT//Vm' */
  engineclosed_B.RTVm = engineclosed_P.RTVm_Gain * engineclosed_B.Sum_h;

  /* Integrator: '<S109>/Get Crank Angle IC 0' */
  if (rtmIsMajorTimeStep(engineclosed_M)) {
    resetSolver = false;
    stateChanged = false;
    zcEvent = (engineclosed_B.RelationalOperator &&
               (engineclosed_PrevZCX.GetCrankAngleIC0_Reset_ZCE != POS_ZCSIG));
    engineclosed_PrevZCX.GetCrankAngleIC0_Reset_ZCE =
      engineclosed_B.RelationalOperator;

    /* evaluate zero-crossings */
    if (zcEvent) {
      resetSolver = true;
      engineclosed_X.GetCrankAngleIC0_CSTATE =
        engineclosed_P.GetCrankAngleIC0_IC;
      stateChanged = true;
    }

    if (resetSolver) {
      rtsiSetBlockStateForSolverChangedAtMajorStep(&engineclosed_M->solverInfo,
        true);
      if (stateChanged) {
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&engineclosed_M->solverInfo, true);
      }
    }
  }

  engineclosed_B.GetCrankAngleIC0 = engineclosed_X.GetCrankAngleIC0_CSTATE;

  /* End of Integrator: '<S109>/Get Crank Angle IC 0' */

  /* Clock: '<Root>/Clock' */
  engineclosed_B.Clock = engineclosed_M->Timing.t[0];
  if (rtmIsMajorTimeStep(engineclosed_M)) {
    /* ToWorkspace: '<Root>/To Workspace2' */
    if (rtmIsMajorTimeStep(engineclosed_M)) {
      rt_UpdateLogVar((LogVar *)(LogVar*)
                      (engineclosed_DW.ToWorkspace2_PWORK.LoggedData),
                      &engineclosed_B.Clock, 0);
    }
  }
}

/* Model update function */
void engineclosed_update(void)
{
  /* ContTimeOutputInconsistentWithStateAtMajorOutputFlag is set, need to run a minor output */
  if (rtmIsMajorTimeStep(engineclosed_M)) {
    if (rtsiGetContTimeOutputInconsistentWithStateAtMajorStep
        (&engineclosed_M->solverInfo)) {
      rtsiSetSimTimeStep(&engineclosed_M->solverInfo,MINOR_TIME_STEP);
      rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
        (&engineclosed_M->solverInfo, false);
      engineclosed_output();
      rtsiSetSimTimeStep(&engineclosed_M->solverInfo, MAJOR_TIME_STEP);
    }
  }

  if (rtmIsMajorTimeStep(engineclosed_M)) {
    rt_ertODEUpdateContinuousStates(&engineclosed_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++engineclosed_M->Timing.clockTick0)) {
    ++engineclosed_M->Timing.clockTickH0;
  }

  engineclosed_M->Timing.t[0] = rtsiGetSolverStopTime
    (&engineclosed_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++engineclosed_M->Timing.clockTick1)) {
      ++engineclosed_M->Timing.clockTickH1;
    }

    engineclosed_M->Timing.t[1] = engineclosed_M->Timing.clockTick1 *
      engineclosed_M->Timing.stepSize1 + engineclosed_M->Timing.clockTickH1 *
      engineclosed_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void engineclosed_derivatives(void)
{
  XDot_engineclosed_T *_rtXdot;
  _rtXdot = ((XDot_engineclosed_T *) engineclosed_M->derivs);

  /* Derivatives for Integrator: '<S4>/w = T//J w0 = 209 rad//s' */
  _rtXdot->wTJw0209rads_CSTATE = engineclosed_B.Add;

  /* Derivatives for Integrator: '<S5>/Intake' */
  _rtXdot->Intake_CSTATE = engineclosed_B.Pumping;

  /* Derivatives for Integrator: '<S107>/p0 = 0.543 bar' */
  _rtXdot->p00543bar_CSTATE = engineclosed_B.RTVm;

  /* Derivatives for Integrator: '<S109>/Get Crank Angle IC 0' */
  _rtXdot->GetCrankAngleIC0_CSTATE = engineclosed_B.wTJw0209rads;
}

/* Model initialize function */
void engineclosed_initialize(void)
{
  /* Start for Triggered SubSystem: '<Root>/Controller' */

  /* Start for ToFile: '<S3>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "pout.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(engineclosed_M, "Error creating .mat file pout.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 1 + 1, 0, "pout")) {
      rtmSetErrorStatus(engineclosed_M,
                        "Error writing mat file header to file pout.mat");
      return;
    }

    engineclosed_DW.ToFile1_IWORK_m.Count = 0;
    engineclosed_DW.ToFile1_IWORK_m.Decimation = -1;
    engineclosed_DW.ToFile1_PWORK_f.FilePtr = fp;
  }

  /* End of Start for SubSystem: '<Root>/Controller' */

  /* Start for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "rpms.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(engineclosed_M, "Error creating .mat file rpms.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 2 + 1, 0, "rpms")) {
      rtmSetErrorStatus(engineclosed_M,
                        "Error writing mat file header to file rpms.mat");
      return;
    }

    engineclosed_DW.ToFile1_IWORK.Count = 0;
    engineclosed_DW.ToFile1_IWORK.Decimation = -1;
    engineclosed_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for Triggered SubSystem: '<Root>/Compression' */
  /* Start for InitialCondition: '<S2>/Init' */
  engineclosed_DW.Init_FirstOutputTime = true;

  /* End of Start for SubSystem: '<Root>/Compression' */

  /* Start for ToWorkspace: '<Root>/To Workspace2' */
  {
    int_T dimensions[1] = { 1 };

    engineclosed_DW.ToWorkspace2_PWORK.LoggedData = rt_CreateLogVar(
      engineclosed_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(engineclosed_M),
      engineclosed_M->Timing.stepSize0,
      (&rtmGetErrorStatus(engineclosed_M)),
      "time",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.001,
      1);
    if (engineclosed_DW.ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  engineclosed_PrevZCX.Intake_Reset_ZCE = UNINITIALIZED_ZCSIG;
  engineclosed_PrevZCX.GetCrankAngleIC0_Reset_ZCE = UNINITIALIZED_ZCSIG;
  engineclosed_PrevZCX.Compression_Trig_ZCE = UNINITIALIZED_ZCSIG;
  engineclosed_PrevZCX.Controller_Trig_ZCE = UNINITIALIZED_ZCSIG;
  engineclosed_PrevZCX.positiveedgetodualedgeconversio = POS_ZCSIG;

  {
    FILE * a;
    int32_T i;
    uint32_T prevT_idx_0;
    uint32_T prevT_idx_1;

    /* InitializeConditions for Integrator: '<S4>/w = T//J w0 = 209 rad//s' */
    engineclosed_X.wTJw0209rads_CSTATE = engineclosed_P.wTJw0209rads_IC;

    /* InitializeConditions for Integrator: '<S5>/Intake' */
    engineclosed_X.Intake_CSTATE = engineclosed_P.Intake_IC;
    if (!rtmIsFirstInitCond(engineclosed_M)) {
      rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
        (&engineclosed_M->solverInfo, true);
    }

    /* End of InitializeConditions for Integrator: '<S5>/Intake' */

    /* InitializeConditions for Integrator: '<S107>/p0 = 0.543 bar' */
    engineclosed_X.p00543bar_CSTATE = engineclosed_P.p00543bar_IC;

    /* InitializeConditions for Integrator: '<S109>/Get Crank Angle IC 0' */
    engineclosed_X.GetCrankAngleIC0_CSTATE = engineclosed_P.GetCrankAngleIC0_IC;
    if (!rtmIsFirstInitCond(engineclosed_M)) {
      rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
        (&engineclosed_M->solverInfo, true);
    }

    /* End of InitializeConditions for Integrator: '<S109>/Get Crank Angle IC 0' */

    /* SystemInitialize for Triggered SubSystem: '<S7>/positive edge to dual edge conversion' */
    /* InitializeConditions for UnitDelay: '<S110>/Unit Delay' */
    engineclosed_DW.UnitDelay_DSTATE =
      engineclosed_P.UnitDelay_InitialCondition_n;

    /* SystemInitialize for Outport: '<S110>/trigger' */
    engineclosed_B.UnitDelay = engineclosed_P.trigger_Y0_k;

    /* End of SystemInitialize for SubSystem: '<S7>/positive edge to dual edge conversion' */

    /* SystemInitialize for Triggered SubSystem: '<Root>/Controller' */
    prevT_idx_0 = engineclosed_M->Timing.clockTick1;
    prevT_idx_1 = engineclosed_M->Timing.clockTickH1;
    engineclosed_DW.Controller_PREV_T[0] = prevT_idx_0;
    engineclosed_DW.Controller_PREV_T[1] = prevT_idx_1;

    /* InitializeConditions for DiscreteIntegrator: '<S64>/Integrator' */
    engineclosed_DW.Integrator_DSTATE =
      engineclosed_P.PIDController_InitialConditionF;

    /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      engineclosed_DW.eml_openfiles[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<S3>/MATLAB Function' */

    /* SystemInitialize for Outport: '<S3>/Throttle Ang.' */
    engineclosed_B.ThrottleAngle = engineclosed_P.ThrottleAng_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Controller' */

    /* SystemInitialize for Triggered SubSystem: '<Root>/Compression' */
    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
    engineclosed_DW.UnitDelay_DSTATE_g =
      engineclosed_P.UnitDelay_InitialCondition;

    /* SystemInitialize for Outport: '<S2>/mass(k)' */
    engineclosed_B.UnitDelay_e = engineclosed_P.massk_Y0;

    /* SystemInitialize for Outport: '<S2>/trigger' */
    engineclosed_B.Trigger = engineclosed_P.trigger_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Compression' */

    /* SystemInitialize for MATLAB Function: '<S4>/MATLAB Function' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      engineclosed_DW.eml_openfiles_a[i] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<S4>/MATLAB Function' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(engineclosed_M)) {
      rtmSetFirstInitCond(engineclosed_M, 0);
    }
  }
}

/* Model terminate function */
void engineclosed_terminate(void)
{
  /* Terminate for Triggered SubSystem: '<Root>/Controller' */

  /* Terminate for ToFile: '<S3>/To File1' */
  {
    FILE *fp = (FILE *) engineclosed_DW.ToFile1_PWORK_f.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "pout.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(engineclosed_M, "Error closing MAT-file pout.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(engineclosed_M, "Error reopening MAT-file pout.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 1 + 1,
           engineclosed_DW.ToFile1_IWORK_m.Count, "pout")) {
        rtmSetErrorStatus(engineclosed_M,
                          "Error writing header for pout to MAT-file pout.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(engineclosed_M, "Error closing MAT-file pout.mat");
        return;
      }

      engineclosed_DW.ToFile1_PWORK_f.FilePtr = (NULL);
    }
  }

  /* End of Terminate for SubSystem: '<Root>/Controller' */

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) engineclosed_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "rpms.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(engineclosed_M, "Error closing MAT-file rpms.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(engineclosed_M, "Error reopening MAT-file rpms.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2 + 1, engineclosed_DW.ToFile1_IWORK.Count,
           "rpms")) {
        rtmSetErrorStatus(engineclosed_M,
                          "Error writing header for rpms to MAT-file rpms.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(engineclosed_M, "Error closing MAT-file rpms.mat");
        return;
      }

      engineclosed_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  engineclosed_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  engineclosed_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  engineclosed_initialize();
}

void MdlTerminate(void)
{
  engineclosed_terminate();
}

/* Registration function */
RT_MODEL_engineclosed_T *engineclosed(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)engineclosed_M, 0,
                sizeof(RT_MODEL_engineclosed_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&engineclosed_M->solverInfo,
                          &engineclosed_M->Timing.simTimeStep);
    rtsiSetTPtr(&engineclosed_M->solverInfo, &rtmGetTPtr(engineclosed_M));
    rtsiSetStepSizePtr(&engineclosed_M->solverInfo,
                       &engineclosed_M->Timing.stepSize0);
    rtsiSetdXPtr(&engineclosed_M->solverInfo, &engineclosed_M->derivs);
    rtsiSetContStatesPtr(&engineclosed_M->solverInfo, (real_T **)
                         &engineclosed_M->contStates);
    rtsiSetNumContStatesPtr(&engineclosed_M->solverInfo,
      &engineclosed_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&engineclosed_M->solverInfo,
      &engineclosed_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&engineclosed_M->solverInfo,
      &engineclosed_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&engineclosed_M->solverInfo,
      &engineclosed_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&engineclosed_M->solverInfo, (&rtmGetErrorStatus
      (engineclosed_M)));
    rtsiSetRTModelPtr(&engineclosed_M->solverInfo, engineclosed_M);
  }

  rtsiSetSimTimeStep(&engineclosed_M->solverInfo, MAJOR_TIME_STEP);
  engineclosed_M->intgData.f[0] = engineclosed_M->odeF[0];
  engineclosed_M->contStates = ((real_T *) &engineclosed_X);
  rtsiSetSolverData(&engineclosed_M->solverInfo, (void *)
                    &engineclosed_M->intgData);
  rtsiSetSolverName(&engineclosed_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = engineclosed_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    engineclosed_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    engineclosed_M->Timing.sampleTimes =
      (&engineclosed_M->Timing.sampleTimesArray[0]);
    engineclosed_M->Timing.offsetTimes =
      (&engineclosed_M->Timing.offsetTimesArray[0]);

    /* task periods */
    engineclosed_M->Timing.sampleTimes[0] = (0.0);
    engineclosed_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    engineclosed_M->Timing.offsetTimes[0] = (0.0);
    engineclosed_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(engineclosed_M, &engineclosed_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = engineclosed_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    engineclosed_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(engineclosed_M, 10.0);
  engineclosed_M->Timing.stepSize0 = 0.001;
  engineclosed_M->Timing.stepSize1 = 0.001;
  rtmSetFirstInitCond(engineclosed_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    engineclosed_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    /*
     * Set pointers to the data and signal info each state
     */
    {
      static int_T rt_LoggedStateWidths[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedStateNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedStateDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedStateIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static BuiltInDTypeId rt_LoggedStateDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedStateComplexSignals[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static const char_T *rt_LoggedStateLabels[] = {
        "CSTATE",
        "CSTATE",
        "CSTATE",
        "CSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE"
      };

      static const char_T *rt_LoggedStateBlockNames[] = {
        "engineclosed/Engine\nDynamics/w = T//J\nw0 = 209 rad//s",
        "engineclosed/Throttle & Manifold/Intake",
        "engineclosed/Throttle & Manifold/Intake Manifold/p0 = 0.543 bar",
        "engineclosed/valve timing/TDC and BDC detection/Get Crank\nAngle\nIC 0",
        "engineclosed/valve timing/positive edge to\ndual edge conversion/Unit Delay",
        "engineclosed/Controller/PID Controller/Integrator/Discrete/Integrator",
        "engineclosed/Compression/Unit Delay"
      };

      static const char_T *rt_LoggedStateNames[] = {
        "",
        "",
        "",
        "",
        "",
        "",
        ""
      };

      static boolean_T rt_LoggedStateCrossMdlRef[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
        7,
        rt_LoggedStateWidths,
        rt_LoggedStateNumDimensions,
        rt_LoggedStateDimensions,
        rt_LoggedStateIsVarDims,
        (NULL),
        (NULL),
        rt_LoggedStateDataTypeIds,
        rt_LoggedStateComplexSignals,
        (NULL),
        rt_LoggingStatePreprocessingFcnPtrs,

        { rt_LoggedStateLabels },
        (NULL),
        (NULL),
        (NULL),

        { rt_LoggedStateBlockNames },

        { rt_LoggedStateNames },
        rt_LoggedStateCrossMdlRef,
        rt_RTWLogDataTypeConvert
      };

      static void * rt_LoggedStateSignalPtrs[7];
      rtliSetLogXSignalPtrs(engineclosed_M->rtwLogInfo, (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
      rtliSetLogXSignalInfo(engineclosed_M->rtwLogInfo,
                            &rt_LoggedStateSignalInfo);
      rt_LoggedStateSignalPtrs[0] = (void*)&engineclosed_X.wTJw0209rads_CSTATE;
      rt_LoggedStateSignalPtrs[1] = (void*)&engineclosed_X.Intake_CSTATE;
      rt_LoggedStateSignalPtrs[2] = (void*)&engineclosed_X.p00543bar_CSTATE;
      rt_LoggedStateSignalPtrs[3] = (void*)
        &engineclosed_X.GetCrankAngleIC0_CSTATE;
      rt_LoggedStateSignalPtrs[4] = (void*)&engineclosed_DW.UnitDelay_DSTATE;
      rt_LoggedStateSignalPtrs[5] = (void*)&engineclosed_DW.Integrator_DSTATE;
      rt_LoggedStateSignalPtrs[6] = (void*)&engineclosed_DW.UnitDelay_DSTATE_g;
    }

    rtliSetLogT(engineclosed_M->rtwLogInfo, "t");
    rtliSetLogX(engineclosed_M->rtwLogInfo, "x");
    rtliSetLogXFinal(engineclosed_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(engineclosed_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(engineclosed_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(engineclosed_M->rtwLogInfo, 0);
    rtliSetLogDecimation(engineclosed_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &engineclosed_Y.crankspeedradsec
      };

      rtliSetLogYSignalPtrs(engineclosed_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "engineclosed/crank speed\n(rad//sec)" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(engineclosed_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(engineclosed_M->rtwLogInfo, "y");
  }

  engineclosed_M->solverInfoPtr = (&engineclosed_M->solverInfo);
  engineclosed_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&engineclosed_M->solverInfo, 0.001);
  rtsiSetSolverMode(&engineclosed_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  engineclosed_M->blockIO = ((void *) &engineclosed_B);
  (void) memset(((void *) &engineclosed_B), 0,
                sizeof(B_engineclosed_T));

  {
    engineclosed_B.wTJw0209rads = 0.0;
    engineclosed_B.EngineSpeed = 0.0;
    engineclosed_B.Step = 0.0;
    engineclosed_B.Step1 = 0.0;
    engineclosed_B.LoadTorque = 0.0;
    engineclosed_B.SpeedSetpoint = 0.0;
    engineclosed_B.SimulationInputs[0] = 0.0;
    engineclosed_B.SimulationInputs[1] = 0.0;
    engineclosed_B.StoichiometricFuel = 0.0;
    engineclosed_B.TorqueGen = 0.0;
    engineclosed_B.TorqueGen2 = 0.0;
    engineclosed_B.Sum = 0.0;
    engineclosed_B.Sum_k = 0.0;
    engineclosed_B.InverseInertia1J = 0.0;
    engineclosed_B.Product = 0.0;
    engineclosed_B.Add = 0.0;
    engineclosed_B.utheta90 = 0.0;
    engineclosed_B.Intake = 0.0;
    engineclosed_B.p00543bar = 0.0;
    engineclosed_B.Pumping = 0.0;
    engineclosed_B.ftheta = 0.0;
    engineclosed_B.Product1 = 0.0;
    engineclosed_B.Product2 = 0.0;
    engineclosed_B.pratio = 0.0;
    engineclosed_B.Switch = 0.0;
    engineclosed_B.Sum_a = 0.0;
    engineclosed_B.flowdirection = 0.0;
    engineclosed_B.Product_c = 0.0;
    engineclosed_B.Sum_h = 0.0;
    engineclosed_B.RTVm = 0.0;
    engineclosed_B.GetCrankAngleIC0 = 0.0;
    engineclosed_B.Clock = 0.0;
    engineclosed_B.UnitDelay = 0.0;
    engineclosed_B.Gain = 0.0;
    engineclosed_B.gpratio = 0.0;
    engineclosed_B.dJ = 0.0;
    engineclosed_B.rpmtorads = 0.0;
    engineclosed_B.Sum_n = 0.0;
    engineclosed_B.PProdOut = 0.0;
    engineclosed_B.Integrator = 0.0;
    engineclosed_B.Sum_f = 0.0;
    engineclosed_B.ZeroGain = 0.0;
    engineclosed_B.DeadZone = 0.0;
    engineclosed_B.SignPreSat = 0.0;
    engineclosed_B.IProdOut = 0.0;
    engineclosed_B.SignPreIntegrator = 0.0;
    engineclosed_B.Switch_k = 0.0;
    engineclosed_B.ThrottleAngle = 0.0;
    engineclosed_B.kp = 0.0;
    engineclosed_B.ki = 0.0;
    engineclosed_B.Init = 0.0;
    engineclosed_B.UnitDelay_e = 0.0;
    engineclosed_B.Trigger = 0.0;
  }

  /* parameters */
  engineclosed_M->defaultParam = ((real_T *)&engineclosed_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &engineclosed_X;
    engineclosed_M->contStates = (x);
    (void) memset((void *)&engineclosed_X, 0,
                  sizeof(X_engineclosed_T));
  }

  /* states (dwork) */
  engineclosed_M->dwork = ((void *) &engineclosed_DW);
  (void) memset((void *)&engineclosed_DW, 0,
                sizeof(DW_engineclosed_T));
  engineclosed_DW.UnitDelay_DSTATE = 0.0;
  engineclosed_DW.Integrator_DSTATE = 0.0;
  engineclosed_DW.UnitDelay_DSTATE_g = 0.0;

  /* external outputs */
  engineclosed_M->outputs = (&engineclosed_Y);
  engineclosed_Y.crankspeedradsec = 0.0;

  /* Initialize Sizes */
  engineclosed_M->Sizes.numContStates = (4);/* Number of continuous states */
  engineclosed_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  engineclosed_M->Sizes.numY = (1);    /* Number of model outputs */
  engineclosed_M->Sizes.numU = (0);    /* Number of model inputs */
  engineclosed_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  engineclosed_M->Sizes.numSampTimes = (2);/* Number of sample times */
  engineclosed_M->Sizes.numBlocks = (76);/* Number of blocks */
  engineclosed_M->Sizes.numBlockIO = (58);/* Number of block outputs */
  engineclosed_M->Sizes.numBlockPrms = (41);/* Sum of parameter "widths" */
  return engineclosed_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
