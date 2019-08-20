/*
 * engineclosed_types.h
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

#ifndef RTW_HEADER_engineclosed_types_h_
#define RTW_HEADER_engineclosed_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Custom Type definition for MATLAB Function: '<S4>/MATLAB Function' */
#include <stdio.h>
#ifndef struct_tag_su2dYx4D5wygFoF57GWu6uG
#define struct_tag_su2dYx4D5wygFoF57GWu6uG

struct tag_su2dYx4D5wygFoF57GWu6uG
{
  int32_T charSize;
  int32_T shortSize;
  int32_T intSize;
  int32_T longSize;
  int32_T longlongSize;
};

#endif                                 /*struct_tag_su2dYx4D5wygFoF57GWu6uG*/

#ifndef typedef_su2dYx4D5wygFoF57GWu6uG_engin_T
#define typedef_su2dYx4D5wygFoF57GWu6uG_engin_T

typedef struct tag_su2dYx4D5wygFoF57GWu6uG su2dYx4D5wygFoF57GWu6uG_engin_T;

#endif                                 /*typedef_su2dYx4D5wygFoF57GWu6uG_engin_T*/

#include <stddef.h>
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T_engineclosed_T
#define typedef_emxArray_real_T_engineclosed_T

typedef struct emxArray_real_T emxArray_real_T_engineclosed_T;

#endif                                 /*typedef_emxArray_real_T_engineclosed_T*/

/* Parameters (default storage) */
typedef struct P_engineclosed_T_ P_engineclosed_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_engineclosed_T RT_MODEL_engineclosed_T;

#endif                                 /* RTW_HEADER_engineclosed_types_h_ */
